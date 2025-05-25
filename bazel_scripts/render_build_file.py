import pathlib
import dataclasses
from semiwrap.makeplan import (
    TypeCasterConfig,
    BuildTarget,
    Entrypoint,
    LocalDependency,
    ExtensionModule,
    CppMacroValue,
    InputFile,
    OutputFile,
    BuildTargetOutput,
    ExtensionModule,
    ExtensionModuleConfig,
    PlanError,
    Depfile,
)
from semiwrap.autowrap.buffer import RenderBuffer
import typing as T
from semiwrap.pyproject import PyProject
from semiwrap.pkgconf_cache import PkgconfCache
from semiwrap.casters import PKGCONF_CASTER_EXT
from semiwrap.config.autowrap_yml import AutowrapConfigYaml
import collections
import sysconfig
import os

import toposort



@dataclasses.dataclass(frozen=True)
class Dat2HeaderConfig:
    class_name: str
    yml_file: InputFile
    header_input: str
    header_root: str
    all_type_casters: BuildTarget
    output_file: OutputFile
    dep_file: Depfile


def _split_ns(name: str) -> T.Tuple[str, str]:
    ns = ""
    idx = name.rfind("::")
    if idx != -1:
        ns = name[:idx]
        name = name[idx + 2 :]
    return ns, name


class _BuildPlanner:
    def __init__(self, project_root: pathlib.Path, missing_yaml_ok: bool = False):

        self.project_root = project_root
        self.missing_yaml_ok = missing_yaml_ok

        self.pyproject = PyProject(project_root / "pyproject.toml")
        self.pkgcache = PkgconfCache()
        self.pyproject_input = InputFile(project_root / "pyproject.toml")

        self.pyi_targets: T.List[BuildTarget] = []
        self.pyi_args = []

        self.local_caster_targets: T.Dict[str, BuildTargetOutput] = {}
        self.local_dependencies: T.Dict[str, LocalDependency] = {}

        sw_path = self.pkgcache.get("semiwrap").type_casters_path
        assert sw_path is not None
        self.semiwrap_type_caster_path = sw_path

    def generate(self):

        projectcfg = self.pyproject.project

        #
        # Export type casters
        # .. this probably should be its own hatchling plugin?
        #

        for name, caster_cfg in projectcfg.export_type_casters.items():
            yield from self._process_export_type_caster(name, caster_cfg)

        # This is needed elsewhere
        self._cpp_macro = CppMacroValue("__cplusplus")
        yield self._cpp_macro

        #
        # Generate extension modules
        #

        for package_name, extension in self._sorted_extension_modules():
            try:
                yield from self._process_extension_module(package_name, extension)
            except Exception as e:
                raise PlanError(f"{package_name} failed") from e

        # TODO: this conditional probably should be done in the build system instead
        # cannot build pyi files when cross-compiling
        if not (
            "_PYTHON_HOST_PLATFORM" in os.environ
            or "PYTHON_CROSSENV" in os.environ
            or os.environ.get("SEMIWRAP_SKIP_PYI") == "1"
        ):
            # Make a pyi for every module
            # - they depend on every module because it needs a working environment
            #   and the user might import something
            # - if there's a subpkg this fails, need to think about it
            for pyi_target in self.pyi_targets:
                yield BuildTarget(
                    command="make-pyi",
                    args=pyi_target.args + tuple(self.pyi_args),
                    install_path=pyi_target.install_path,
                )

    def _resolve_dep(self, dname: str):
        return self.local_dependencies.get(dname, dname)

    def _process_export_type_caster(self, name: str, caster_cfg: TypeCasterConfig):
        # print("!!!!!!!!!", caster_cfg)

        # Need to generate the data file and the .pc file
        caster_target = BuildTarget(
            command="publish-casters",
            args=(
                self.pyproject_input,
                name,
                OutputFile(f"{name}{PKGCONF_CASTER_EXT}"),
                OutputFile(f"{name}.pc"),
            ),
            install_path=pathlib.Path(*caster_cfg.pypackage.split(".")),
        )
        yield caster_target

        # Need an entrypoint to point at the .pc file
        yield Entrypoint(group="pkg_config", name=name, package=caster_cfg.pypackage)

        dep = self.pkgcache.add_local(
            name=name,
            includes=[self.project_root / inc for inc in caster_cfg.includedir],
            requires=caster_cfg.requires,
        )
        caster_dep = LocalDependency(
            name=dep.name,
            include_paths=tuple(dep.include_path),
            depends=tuple([self._resolve_dep(cd) for cd in caster_cfg.requires]),
        )
        self.local_dependencies[dep.name] = caster_dep
        yield caster_dep

        # The .pc file cannot be used in the build, but the data file must be, so
        # store it so it can be used elsewhere
        self.local_caster_targets[name] = BuildTargetOutput(caster_target, 0)

    def _sorted_extension_modules(
        self,
    ) -> T.Generator[T.Tuple[str, ExtensionModuleConfig], None, None]:
        # sort extension modules by dependencies, that way modules can depend on other modules
        # also declared in pyproject.toml without needing to worry about ordering in the file
        by_name = {}
        to_sort: T.Dict[str, T.Set[str]] = {}

        for package_name, extension in self.pyproject.project.extension_modules.items():
            if extension.ignore:
                continue

            name = extension.name or package_name.replace(".", "_")
            by_name[name] = (package_name, extension)

            deps = to_sort.setdefault(name, set())
            for dep in extension.wraps:
                deps.add(dep)
            for dep in extension.depends:
                deps.add(dep)

        for name in toposort.toposort_flatten(to_sort, sort=True):
            data = by_name.get(name)
            if data:
                yield data

    def _process_extension_module(
        self, package_name: str, extension: ExtensionModuleConfig
    ):
        package_path_elems = package_name.split(".")
        parent_package = ".".join(package_path_elems[:-1])
        module_name = package_path_elems[-1]
        package_path = pathlib.Path(*package_path_elems[:-1])
        varname = extension.name or package_name.replace(".", "_")

        # Detect the location of the package in the source tree
        package_init_py = self.pyproject.package_root / package_path / "__init__.py"
        self.pyi_args += [parent_package, package_init_py.as_posix()]

        depends = self.pyproject.get_extension_deps(extension)
        depends.append("semiwrap")

        # Search path for wrapping is dictated by package_path and wraps
        search_path, include_directories_uniq, caster_json_file, libinit_modules = (
            self._prepare_dependency_paths(depends, extension)
        )

        includes = [
            self.project_root / pathlib.PurePosixPath(inc) for inc in extension.includes
        ]
        search_path.extend(includes)

        # Search the package path last
        search_path.append(self.pyproject.package_root / package_path)

        all_type_casters = BuildTarget(
            command="resolve-casters",
            args=(
                OutputFile(f"{varname}.casters.pkl"),
                Depfile(f"{varname}.casters.d"),
                *caster_json_file,
            ),
            install_path=None,
        )
        yield all_type_casters

        #
        # Generate init.py for loading dependencies
        #

        libinit_module = None
        if libinit_modules:
            libinit_py = extension.libinit or f"_init_{module_name}.py"
            libinit_tgt = BuildTarget(
                command="gen-libinit-py",
                args=(OutputFile(libinit_py), *libinit_modules),
                install_path=package_path,
            )

            libinit_module = f"{parent_package}.{libinit_py}"[:-3]
            self.pyi_args += [libinit_module, libinit_tgt]

            yield libinit_tgt

        #
        # Publish a .pc file for this module
        #

        pc_args = [
            package_name,
            varname,
            self.pyproject_input,
            OutputFile(f"{varname}.pc"),
        ]
        if libinit_module:
            pc_args += ["--libinit-py", libinit_module]

        yield BuildTarget(
            command="gen-pkgconf",
            args=tuple(pc_args),
            install_path=package_path,
        )

        yield Entrypoint(group="pkg_config", name=varname, package=parent_package)

        #
        # Process the headers
        #

        # Find and load the yaml
        if extension.yaml_path is None:
            yaml_path = pathlib.Path("semiwrap")
        else:
            yaml_path = pathlib.Path(pathlib.PurePosixPath(extension.yaml_path))

        datfiles, module_sources, subpackages = yield from self._process_headers(
            extension,
            package_path,
            yaml_path,
            include_directories_uniq.keys(),
            search_path,
            all_type_casters,
        )

        modinit = BuildTarget(
            command="gen-modinit-hpp",
            args=(
                module_name,
                OutputFile(f"semiwrap_init.{package_name}.hpp"),
                *datfiles,
            ),
            install_path=None,
        )
        module_sources.append(modinit)
        yield modinit

        #
        # Emit the module
        #

        # Use a local dependency to store everything so it can be referenced elsewhere
        cached_dep = self.pkgcache.add_local(
            name=varname,
            includes=[*includes, self.pyproject.package_root / package_path],
            requires=depends,
            libinit_py=libinit_module,
        )
        local_dep = LocalDependency(
            name=cached_dep.name,
            include_paths=tuple(cached_dep.include_path),
            depends=tuple(self._resolve_dep(dep) for dep in depends),
        )
        yield local_dep
        self.local_dependencies[local_dep.name] = local_dep

        modobj = ExtensionModule(
            name=varname,
            package_name=package_name,
            sources=tuple(module_sources),
            depends=(local_dep,),
            include_directories=tuple(),
            install_path=package_path,
        )
        yield modobj

        self.pyi_args += [package_name, modobj]

        # This is not yielded here because pyi targets need to depend on all modules
        # via self.pyi_args.
        # - The output .pyi files vary based on whether there are subpackages or not. If no
        #   subpackage, it's {module_name}.pyi. If there are subpackages, it becomes
        #   {module_name}/__init__.pyi and {module_name}/{subpackage}.pyi
        # - As long as a user doesn't manually bind a subpackage our detection works here
        #   but if we need to allow that then will need to declare subpackages in pyproject.toml
        # .. this breaks if there are sub-sub packages, don't do that please

        base_pyi_elems = package_name.split(".")

        if subpackages:
            pyi_elems = base_pyi_elems + ["__init__.pyi"]
            pyi_args = [
                pathlib.PurePath(*pyi_elems).as_posix(),
                OutputFile("__init__.pyi"),
            ]
            for subpackage in subpackages:
                pyi_elems = base_pyi_elems + [f"{subpackage}.pyi"]
                pyi_args += [
                    pathlib.PurePath(*pyi_elems).as_posix(),
                    OutputFile(f"{subpackage}.pyi"),
                ]

            self.pyi_targets.append(
                BuildTarget(
                    command="make-pyi",
                    args=(package_name, *pyi_args, "--"),
                    install_path=package_path / module_name,
                )
            )

        else:
            base_pyi_elems[-1] = f"{base_pyi_elems[-1]}.pyi"

            self.pyi_targets.append(
                BuildTarget(
                    command="make-pyi",
                    args=(
                        package_name,
                        pathlib.PurePath(*base_pyi_elems).as_posix(),
                        OutputFile(f"{module_name}.pyi"),
                        "--",
                    ),
                    install_path=package_path,
                )
            )

    def _locate_type_caster_json(
        self,
        depname: str,
        caster_json_file: T.List[T.Union[BuildTargetOutput, pathlib.Path]],
    ):
        checked = set()
        to_check = collections.deque([depname])
        while to_check:
            name = to_check.popleft()
            checked.add(name)

            entry = self.pkgcache.get(name)

            if name in self.local_caster_targets:
                caster_json_file.append(self.local_caster_targets[name])
            else:
                tc = entry.type_casters_path
                if tc and tc not in caster_json_file:
                    caster_json_file.append(tc)

            for req in entry.requires:
                if req not in checked:
                    to_check.append(req)

    def _prepare_dependency_paths(
        self, depends: T.List[str], extension: ExtensionModuleConfig
    ):
        search_path: T.List[pathlib.Path] = []
        include_directories_uniq: T.Dict[pathlib.Path, bool] = {}
        caster_json_file: T.List[T.Union[BuildTargetOutput, pathlib.Path]] = []
        libinit_modules: T.List[str] = []

        # Add semiwrap default type casters
        caster_json_file.append(self.semiwrap_type_caster_path)

        for dep in depends:
            entry = self.pkgcache.get(dep)
            include_directories_uniq.update(
                dict.fromkeys(entry.full_include_path, True)
            )

            # extend the search path if the dependency is in 'wraps'
            if dep in extension.wraps:
                search_path.extend(entry.include_path)

            self._locate_type_caster_json(dep, caster_json_file)

            if entry.libinit_py:
                libinit_modules.append(entry.libinit_py)

        return search_path, include_directories_uniq, caster_json_file, libinit_modules

    def _process_headers(
        self,
        extension: ExtensionModuleConfig,
        package_path: pathlib.Path,
        yaml_path: pathlib.Path,
        include_directories_uniq: T.Iterable[pathlib.Path],
        search_path: T.List[pathlib.Path],
        all_type_casters: BuildTarget,
    ):
        datfiles: T.List[BuildTarget] = []
        module_sources: T.List[BuildTarget] = []
        subpackages: T.Set[str] = set()

        for yml, hdr in self.pyproject.get_extension_headers(extension):
            yml_input = InputFile(yaml_path / f"{yml}.yml")

            try:
                ayml = AutowrapConfigYaml.from_file(self.project_root / yml_input.path)
            except FileNotFoundError:
                if not self.missing_yaml_ok:
                    msg = f"{self.project_root / yml_input.path}: use `python3 -m semiwrap create-yaml --write` to generate"
                    raise FileNotFoundError(msg) from None
                ayml = AutowrapConfigYaml()

            # find the source header
            h_input, h_root = self._locate_header(hdr, search_path)

            header2dat_args = []

            header2dat_config = Dat2HeaderConfig(
                class_name = yml,
                yml_file = yml_input,
                header_input = h_input,
                header_root = h_root,
                all_type_casters = all_type_casters,
                output_file = OutputFile(f"{yml}.dat"),
                dep_file = Depfile(f"{yml}.d")
            )

            datfile = BuildTarget(
                command="header2dat", args=[header2dat_config], install_path=None
            )
            yield datfile
            datfiles.append(datfile)

            # Every header has a .cpp file for binding
            cppfile = BuildTarget(
                command="dat2cpp",
                args=(datfile, OutputFile(f"{yml}.cpp")),
                install_path=None,
            )
            module_sources.append(cppfile)
            yield cppfile

            # Detect subpackages
            for f in ayml.functions.values():
                if f.ignore:
                    continue
                if f.subpackage:
                    subpackages.add(f.subpackage)
                for f in f.overloads.values():
                    if f.subpackage:
                        subpackages.add(f.subpackage)

            for e in ayml.enums.values():
                if e.ignore:
                    continue
                if e.subpackage:
                    subpackages.add(e.subpackage)

            # Every class gets a trampoline file, but some just have #error in them
            for name, ctx in ayml.classes.items():
                if ctx.ignore:
                    continue

                if ctx.subpackage:
                    subpackages.add(ctx.subpackage)

                cls_ns, cls_name = _split_ns(name)
                cls_ns = cls_ns.replace(":", "_")
                trampoline = BuildTarget(
                    command="dat2trampoline",
                    args=(datfile, name, OutputFile(f"{cls_ns}__{cls_name}.hpp")),
                    install_path=package_path / "trampolines",
                )
                module_sources.append(trampoline)
                yield trampoline

            # Even more files if there are templates
            if ayml.templates:

                # Every template instantiation gets a cpp file to lessen compiler
                # memory requirements
                for i, (name, tctx) in enumerate(ayml.templates.items(), start=1):
                    if tctx.subpackage:
                        subpackages.add(tctx.subpackage)

                    tmpl_cpp = BuildTarget(
                        command="dat2tmplcpp",
                        args=(datfile, name, OutputFile(f"{yml}_tmpl{i}.cpp")),
                        install_path=None,
                    )
                    module_sources.append(tmpl_cpp)
                    yield tmpl_cpp

                # All of which use this hpp file
                tmpl_hpp = BuildTarget(
                    command="dat2tmplhpp",
                    args=(datfile, OutputFile(f"{yml}_tmpl.hpp")),
                    install_path=None,
                )
                module_sources.append(tmpl_hpp)
                yield tmpl_hpp

        return datfiles, module_sources, subpackages

    def _locate_header(self, hdr: str, search_path: T.List[pathlib.Path]):
        phdr = pathlib.PurePosixPath(hdr)
        for p in search_path:
            h_path = p / phdr
            if h_path.exists():
                # We should return this as an InputFile, but inputs must be relative to the
                # project root, which may not be the case on windows. Incremental build should
                # still work, because the header is included in a depfile
                return h_path, p
        raise FileNotFoundError(
            f"cannot locate {phdr} in {', '.join(map(str, search_path))}"
        )



def makeplan(project_root: pathlib.Path, missing_yaml_ok: bool = False):
    """
    Given the pyproject.toml configuration for a semiwrap project, reads the
    configuration and generates a series of commands that can be used to parse
    the input headers and generate the needed source code from them.
    """
    planner = _BuildPlanner(project_root, missing_yaml_ok)
    yield from planner.generate()



@dataclasses.dataclass(frozen=True)
class HeaderGenInfo:
    class_name: str
    yml_file: InputFile
    header_input: str
    hdr_tmpls: T.List[T.Tuple[str, str]] = dataclasses.field(default_factory=list)
    trampolines: T.List[T.Tuple[str, str]] = dataclasses.field(default_factory=list)


def write_library(generated_info_buffer, build_file_buffer, lib_name, publish_casters, resolve_casters_item, gen_libinit, gen_pkgconf, gen_modinit_hpp, casters_pickle_file, header2dats, dat2cpps, dat2tmplcpps, dat2tmplhpps, dat2trampolines):

    build_file_buffer.write_trim(f"""   
{lib_name}_extension()
""")

    configs = {}

    for header2dat in header2dats:
        assert len(header2dat.args) == 1
        config = header2dat.args[0]
        configs[config.class_name] = HeaderGenInfo(class_name = config.class_name, yml_file = config.yml_file, header_input = config.header_input)

    for dat2tmplcpp in dat2tmplcpps:
        class_name = dat2tmplcpp.args[0].args[0].class_name
        specialization_name = dat2tmplcpp.args[-2]
        output_file = dat2tmplcpp.args[-1].name[:-4]
        configs[class_name].hdr_tmpls.append((output_file, specialization_name))

    for dat2trampoline in dat2trampolines:
        class_name = dat2trampoline.args[0].args[0].class_name
        configs[class_name].trampolines.append((dat2trampoline.args[-2], dat2trampoline.args[-1].name))




    generated_info_buffer.writeln(f"""def {lib_name}_extension(entry_point, other_deps, DEFAULT_INCLUDE_ROOT, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):""")

    with generated_info_buffer.indent(4):
    
        generated_info_buffer.writeln(f"{lib_name.upper()}_HEADER_GEN = [")
        with generated_info_buffer.indent(4):
            for class_name, config in configs.items():
                newline_indent = "\n                    "
                trimed_header = str(config.header_input)
                trimed_header = trimed_header[trimed_header.find("include") + 7:]
                # print()
                header_templates = newline_indent + newline_indent.join(f'("{x[0]}", "{x[1]}"),' for x in config.hdr_tmpls) + newline_indent if config.hdr_tmpls else ""
                trampolines = newline_indent + newline_indent.join(f'("{x[0]}", "{x[1]}"),' for x in config.trampolines) + newline_indent[:-4] if config.trampolines else ""
                generated_info_buffer.write_trim(f"""struct(
                class_name = "{config.class_name}",
                yml_file = "{config.yml_file.path}",
                header_file = DEFAULT_INCLUDE_ROOT + "{trimed_header}",
                tmpl_class_names = [{header_templates}],
                trampolines = [{trampolines}],
            ),""")
        generated_info_buffer.writeln(f"]")

        write_resolve_casters(generated_info_buffer, lib_name, resolve_casters_item)

        # print(publish_casters)
        # print(resolve_casters_item)
        # print(gen_libinit)
        # print(gen_pkgconf)
        # print(gen_modinit_hpp)
        gen_lib_init_files = f','.join(f'"{x}"' for x in gen_libinit.args[1:])
        generated_info_buffer.write_trim(f"""
            gen_libinit(
                name = "{lib_name}.gen_lib_init",
                output_file = "{gen_libinit.args[0].name}",
                modules = [{gen_lib_init_files}],
            )

            gen_pkgconf(
                name = "{lib_name}.gen_pkgconf",
                libinit_py = "{gen_pkgconf.args[-1]}",
                module_pkg_name = "{gen_pkgconf.args[0]}",
                output_file = "{gen_pkgconf.args[3].name}",
                pkg_name = "{gen_pkgconf.args[1]}",
                project_file = "pyproject.toml",
            )

            gen_modinit_hpp(
                name = "{lib_name}.gen_modinit_hpp",
                input_dats = [x.class_name for x in {lib_name.upper()}_HEADER_GEN],
                libname = "{gen_modinit_hpp.args[0]}",
                output_file = "{gen_modinit_hpp.args[1].name}",
            )
            
            run_header_gen(
                name = "{lib_name}",
                casters_pickle = "{lib_name}.casters.pkl",
                header_gen_config = {lib_name.upper()}_HEADER_GEN,
                include_root = DEFAULT_INCLUDE_ROOT,
                deps = header_to_dat_deps,
            )
            
            native.filegroup(
                name = "{lib_name}.generated_files",
                srcs = [
                    "{lib_name}.gen_modinit_hpp.gen",
                    "{lib_name}.header_gen_files",
                    "{lib_name}.gen_pkgconf",
                    "{lib_name}.gen_lib_init",
                ],
            )
            """
                )




def write_resolve_casters(generated_file_buffer, lib_name, item):
    casters_pickle_file = item.args[0].name
    dep_file = item.args[1].name
    maybe_caster_file = None
    last_arg = item.args[-1]

    caster_files = []
    for cf in item.args[3:]:
        # print(cf)
        if isinstance(cf, pathlib.Path):
            cf = str(cf)
            if cf == "/home/pjreiniger/git/robotpy/mostrobotpy/.venv/lib/python3.10/site-packages/wpiutil/wpiutil-casters.pybind11.json":
                cf = "//subprojects/robotpy-wpiutil:generated/publish_casters/wpiutil-casters.pybind11.json"
            elif cf == "/home/pjreiniger/git/robotpy/mostrobotpy/.venv/lib/python3.10/site-packages/wpimath/wpimath-casters.pybind11.json":
                cf = "//subprojects/robotpy-wpimath:generated/publish_casters/wpimath-casters.pybind11.json"
        elif isinstance(cf, BuildTargetOutput):
            cf = cf.target.args[-2].name
            # cf = 
        else:
            print("UNKNOWN CASTER FILE", type(cf))
                
        caster_files.append(cf)
        
    generated_file_buffer.write_trim(f"""
        resolve_casters(
            name = "{lib_name}.resolve_casters",
            caster_files = {caster_files},
            casters_pkl_file = "{casters_pickle_file}",
            dep_file = "{dep_file}",
        )
    """
    )
    generated_file_buffer.writeln()


def write_extension_module(buffer, item, write_deps):

    depends = []
    def calculate_deps(dependency):
        for d in dependency:
            if isinstance(d, LocalDependency):
                calculate_deps(d.depends)
            elif isinstance(d, str):
                if d == "wpiutil":
                    depends.append("//subprojects/robotpy-wpiutil:wpiutil_pybind_library")
                elif d == "wpinet":
                    depends.append("//subprojects/robotpy-wpinet:wpinet_pybind_library")
                elif d == "wpimath":
                    depends.append("//subprojects/robotpy-wpimath:wpimath_pybind_library")
                elif d == "wpihal":
                    depends.append("//subprojects/robotpy-hal:hal_pybind_library")
                elif d == "ntcore":
                    depends.append("//subprojects/pyntcore:ntcore_pybind_library")
                elif d == "wpilib":
                    depends.append("//subprojects/robotpy-wpilib:wpilib_pybind_library")
                elif d == "wpimath_geometry" or d == "wpimath_filter" or d == "wpimath_controls":
                    depends.append("//subprojects/robotpy-wpimath:wpimath_pybind_library")
                elif "wpimath" in d:
                    depends.append("//subprojects/robotpy-wpimath:wpimath_pybind_library")
                elif d.startswith("robotpy-native-"):
                    lib = d[15:]
                    depends.append(f"@bzlmodrio-allwpilib//libraries/cpp/{lib}:shared",)
                elif d == "semiwrap":
                    continue
                else:
                    print(d)
                    raise
            else:
                print(d)
                raise


    # print(item.depends)
    calculate_deps(item.depends)
    # print("----", depends)

    if write_deps:
        buffer.write_trim(f'''
        create_pybind_library(
            name = "{item.name}",
            generated_srcs = [":{item.name}.generated_srcs"],
            deps = [
                ":{item.name}.tmpl_hdrs",
                ":{item.name}.trampoline_hdrs",
                
            ] + {depends},
            semiwrap_header = [
                ":gen_modinit_hpp0",
            ],
        )
        ''')
    else:
        buffer.write_trim(f'''
        create_pybind_library(
            name = "{item.name}",
            entry_point = entry_point,
            extension_name = extension_name,
            generated_srcs = [":{item.name}.generated_srcs"],
            semiwrap_header = [":{item.name}.gen_modinit_hpp"],
            deps = [
                ":{item.name}.tmpl_hdrs",
                ":{item.name}.trampoline_hdrs",
                
            ] + other_deps,
            extra_hdrs = extra_hdrs,
            extra_srcs = extra_srcs,
            includes = includes,
        )
        ''')

def render_build_file(project_dir):
    plans = makeplan(project_dir)
    # project = PyProject(project_dir / "pyproject.toml")
    # print(project.project)

    dat2trampolines = []
    header2dats = []
    dat2cpps = []
    dat2tmplhpps = []
    dat2tmplcpps = []
    publish_casters = None
    resolve_casters = None
    gen_libinit = None
    gen_pkgconf = None
    gen_modinit_hpp = None

    lib_counter = 0

    extension_modules = []

    build_file_buffer = RenderBuffer()
    build_file_buffer.write_trim('''load("//bazel_scripts:copy_native_file.bzl", "copy_extension_library", "copy_native_file")
load("//bazel_scripts:semiwrap_helpers.bzl", "dat_to_cc", "dat_to_tmpl_hpp", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "make_pyi", "dat_to_trampoline", "gen_pkgconf", "header_to_dat", "publish_casters", "publish_casters",  "resolve_casters", "dat_to_tmpl_cpp", "run_header_gen")
load("//bazel_scripts:pybind_rules.bzl", "create_pybind_library", "pybind_python_library")

load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")

DEFAULT_INCLUDE_ROOT = "/home/pjreiniger/git/robotpy/mostrobotpy/.venv/lib/python3.10/site-packages/native/wpiutil/include"
''')

    generated_info_buffer = RenderBuffer()
    generated_info_buffer.write_trim("""load("//bazel_scripts:pybind_rules.bzl", "create_pybind_library")
load("//bazel_scripts:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "publish_casters", "resolve_casters", "run_header_gen")
""")

    print("----")

    for item in plans:
        if isinstance(item, BuildTarget):
            print(item.command)
        else:
            print(type(item))
        
        if isinstance(item, BuildTarget):
            if item.command == "dat2trampoline":
                dat2trampolines.append(item)
            elif item.command == "header2dat":
                header2dats.append(item)
                pass
            elif item.command == "dat2cpp":
                dat2cpps.append(item)
                pass
            elif item.command == "dat2tmplcpp":
                dat2tmplcpps.append(item)
                pass
            elif item.command == "dat2tmplhpp":
                dat2tmplhpps.append(item)
            elif item.command == "publish-casters":
                build_file_buffer.write_trim("""
                    publish_library_casters(
                        typecasters_srcs = glob([
                            "wpiutil/src/type_casters/**",
                            "wpiutil/src/wpistruct/**",
                        ]),
                    )""")
                if publish_casters is not None:
                    raise
                publish_casters = item
            elif item.command == "resolve-casters":
                if resolve_casters is not None:
                    raise
                resolve_casters = item
            elif item.command == "gen-libinit-py":
                if gen_libinit is not None:
                    raise
                gen_libinit = item
            elif item.command == "gen-pkgconf":
                if gen_pkgconf is not None:
                    raise
                gen_pkgconf = item
            elif item.command == "gen-modinit-hpp":
                if gen_modinit_hpp is not None:
                    raise
                gen_modinit_hpp = item
            elif item.command == "make-pyi":
                build_file_buffer.write_trim(f"""
                    make_pyi(
                        name = "make_pyi{lib_counter}",
                    )
                """
                )
            else:
                print(f"Unknown command {item.command}")
        elif isinstance(item, CppMacroValue):
            print("Ignoring macro thing")
        elif isinstance(item, LocalDependency):
            pass
        elif isinstance(item, ExtensionModule):
            extension_modules.append(item.name)
            write_library(generated_info_buffer, build_file_buffer, item.name, publish_casters, resolve_casters, gen_libinit, gen_pkgconf, gen_modinit_hpp, None, header2dats, dat2cpps, dat2tmplcpps, dat2tmplhpps, dat2trampolines)
            
            with generated_info_buffer.indent(4):
                write_extension_module(generated_info_buffer, item, write_deps = False)
                
            write_extension_module(build_file_buffer, item, write_deps = True)

            casters_pickle_file = None
            header2dats = []
            dat2cpps = []
            dat2tmplcpps = []
            dat2tmplhpps = []
            dat2trampolines = []
            resolve_casters = None
            gen_libinit = None
            gen_pkgconf = None
            gen_modinit_hpp = None
            lib_counter += 1
            pass
        else:
            print(type(item))

    for em in extension_modules:
        build_file_buffer.write_trim(f"""
    copy_extension_library(
        name = "copy_{em}",
        extension = "_{em}",
        output_directory = "wpiutil/",
    )""")

    build_file_buffer.write_trim("""
pybind_python_library(
    name = "wpiutil",
    srcs = glob(["wpiutil/**/*.py"]),
    data = [
        ":copy_wpiutil",
    ],
    imports = ["."],
    visibility = ["//visibility:public"],
)
""")

    if publish_casters:
        generated_info_buffer.write_trim(f"""
            def publish_library_casters(typecasters_srcs):
                publish_casters(
                    name = "publish_casters",
                    caster_name = "{publish_casters.args[1]}",
                    output_json = "{publish_casters.args[2].name}",
                    output_pc = "{publish_casters.args[3].name}",
                    project_config = "pyproject.toml",
                    typecasters_srcs = typecasters_srcs,
                )

        """
        )
        generated_info_buffer.writeln()


    build_file_buffer.write_trim(f"""
        filegroup(
            name = "generated_files",
            srcs = [
        """)
    for em in extension_modules:
        build_file_buffer.writeln(f'"{em}.generated_files",')
        
    build_file_buffer.write_trim(f"""
        ],
        visibility = ["//visibility:public"],
    )
    """)
        

    # with open(project_dir / "BUILD.bazel", 'w') as f:
    #     f.write(build_file_buffer.getvalue())

    print(project_dir)
    with open(project_dir / "generated_build_info.bzl", 'w') as f:
        f.write(generated_info_buffer.getvalue())


def main():
    project_files = [
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/pyntcore/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-apriltag/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-cscore/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-hal/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-halsim-ds-socket/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-halsim-gui/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-halsim-ws/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-romi/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpilib/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpimath/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpimath/tests/cpp/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpinet/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpiutil/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpiutil/tests/cpp/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-xrp/pyproject.toml"),
        
    ]

    for project_file in project_files:
        print(f"Running for {project_file}")
        render_build_file(project_file.parent)

if __name__ == "__main__":
    main()
