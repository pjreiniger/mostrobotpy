
from semiwrap.autowrap.buffer import RenderBuffer
from semiwrap.pyproject import PyProject
from semiwrap.config.autowrap_yml import AutowrapConfigYaml
from semiwrap.config.pyproject_toml import ExtensionModuleConfig, TypeCasterConfig
import pathlib
import typing as T

import toposort

def _split_ns(name: str) -> T.Tuple[str, str]:
    ns = ""
    idx = name.rfind("::")
    if idx != -1:
        ns = name[:idx]
        name = name[idx + 2 :]
    return ns, name

class Generator:
    def __init__(self, project_file):
        self.output_buffer = RenderBuffer()
        self.project_root = project_file.parent
        self.pyproject = PyProject(project_file)

        self.output_buffer.write_trim("""load("@rules_semiwrap//:defs.bzl", "create_pybind_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "publish_casters", "resolve_casters", "run_header_gen")
""")    
        self.output_buffer.writeln()

    def _sorted_extension_modules(self):
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

    
    def _process_trampolines_str(self, ayml: AutowrapConfigYaml) -> str:
        trampolines = []
        
        for name, ctx in ayml.classes.items():
            if ctx.ignore:
                continue

            # if ctx.subpackage:
            #     subpackages.add(ctx.subpackage)

            cls_ns, cls_name = _split_ns(name)
            cls_ns = cls_ns.replace(":", "_")

            trampolines.append((name, f"{cls_ns}__{cls_name}.hpp"))
        
        output = "["
        if trampolines:
            # output += "\n            "
            output += "\n                            "
            output += ",\n                            ".join(f'("{t[0]}", "{t[1]}")' for t in trampolines)
            output += ",\n                        "
            # for trampoline in trampolines:
            #     output += f'("{trampoline[0]}", "{trampoline[1]}"), '


        output += "]"
        return output


    def _process_tmpl_str(self, yml: str, ayml: AutowrapConfigYaml) -> str:
        templates = []
        
        for i, (name, tctx) in enumerate(ayml.templates.items(), start=1):
            templates.append((f"{yml}_tmpl{i}", f"{name}"))
        
        output = "["
        if templates:
            output += "\n                            "
            output += ",\n                            ".join(f'("{t[0]}", "{t[1]}")' for t in templates)
            output += ",\n                        "


        output += "]"
        return output


    def _process_headers(
        self, 
        extension: ExtensionModuleConfig, 
        yaml_path: pathlib.Path):

        # TODO
        search_path = []
        if extension.name == "wpiutil":
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpiutil_wpiutil-cpp_headers"))
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-wpiutil/wpiutil/"))
        elif extension.name == "wpinet":
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpinet_wpinet-cpp_headers"))
        elif extension.name == "ntcore":
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_ntcore_ntcore-cpp_headers"))
        elif "wpimath" in extension.name:
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpimath_wpimath-cpp_headers"))
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-wpimath/wpimath/"))
        elif "hal" in extension.name:
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_hal_hal-cpp_headers"))
        elif "apriltag" in extension.name:
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_apriltag_apriltag-cpp_headers"))
        elif "wpilib" in extension.name:
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpilibc_wpilibc-cpp_headers"))
        elif "cscore" in extension.name:
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cscore_cscore-cpp_headers"))
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cameraserver_cameraserver-cpp_headers"))
        elif "xrp" in extension.name:
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_xrpvendordep_xrpvendordep-cpp_headers"))
        elif "romi" in extension.name:
            search_path.append(pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_romivendordep_romivendordep-cpp_headers"))
        else:
            raise Exception(extension.name)
        # TODO

        with self.output_buffer.indent(4):
            self.output_buffer.writeln(f"{extension.name.upper()}_HEADER_GEN = [")

            with self.output_buffer.indent(4):
                for yml, hdr in self.pyproject.get_extension_headers(extension):
                    yml_input = yaml_path / f"{yml}.yml"

                    ayml = AutowrapConfigYaml.from_file(self.project_root / yml_input)

                    tmpl_class_names = self._process_tmpl_str(yml, ayml)
                    trampolines = self._process_trampolines_str(ayml)
                    # Every class gets a trampoline file, but some just have #error in them
                    for name, ctx in ayml.classes.items():
                        if ctx.ignore:
                            continue
                        cls_ns, cls_name = _split_ns(name)
                        cls_ns = cls_ns.replace(":", "_")

                    h_input, h_root = self._locate_header(hdr, search_path)
                    if str(h_root).startswith("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy"):
                        header_root = str(h_root)[len("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/bazel-mostrobotpy/"):]
                    else:
                        header_root = h_input

                    self.output_buffer.write_trim(f"""
                    struct(
                        class_name = "{yml}",
                        yml_file = "{yml_input}",
                        header_root = "{header_root}",
                        header_file = "{header_root}/{h_input.relative_to(h_root)}",
                        tmpl_class_names = {tmpl_class_names},
                        trampolines = {trampolines},
                    ),""")



            self.output_buffer.writeln("]")
            # self.output_buffer.writeln("\n")

    def _write_extension_data(self, package_name: str, extension: ExtensionModuleConfig):
        with self.output_buffer.indent(4):
            package_path_elems = package_name.split(".")
            parent_package = ".".join(package_path_elems[:-1])
            module_name = package_path_elems[-1]
            package_path = pathlib.Path(*package_path_elems[:-1])
            
            libinit = extension.libinit or f"_init_{module_name}"
            
            package_init_py = package_path / "__init__.py"
            self.output_buffer.write_trim(f"""
    resolve_casters(
        name = "{extension.name}.resolve_casters",
        caster_files = [],
        casters_pkl_file = "{extension.name}.casters.pkl",
        dep_file = "{extension.name}.casters.d",
    )

    gen_libinit(
        name = "{extension.name}.gen_lib_init",
        output_file = "{package_path}/{libinit}.py",
        modules = [],
    )

    gen_pkgconf(
        name = "{extension.name}.gen_pkgconf",
        libinit_py = "{parent_package}.{libinit}",
        module_pkg_name = "{package_name}",
        output_file = "{extension.name}.pc",
        pkg_name = "{extension.name}",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "{extension.name}.gen_modinit_hpp",
        input_dats = [x.class_name for x in {extension.name.upper()}_HEADER_GEN],
        libname = "{module_name}",
        output_file = "semiwrap_init.{package_name}.hpp",
    )

    run_header_gen(
        name = "{extension.name}",
        casters_pickle = "{extension.name}.casters.pkl",
        header_gen_config = {extension.name.upper()}_HEADER_GEN,
        include_root = DEFAULT_INCLUDE_ROOT,
        deps = header_to_dat_deps,
        generation_includes = [
            "subprojects/robotpy-wpimath/wpimath/_impl/src",
            "subprojects/robotpy-wpimath/wpimath/_impl/src/type_casters",
            "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpimath_wpimath-cpp_headers",
            "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpiutil_wpiutil-cpp_headers",
        ],
    )

    native.filegroup(
        name = "{extension.name}.generated_files",
        srcs = [
            "{extension.name}.gen_modinit_hpp.gen",
            "{extension.name}.header_gen_files",
            "{extension.name}.gen_pkgconf",
            "{extension.name}.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "{extension.name}",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":{extension.name}.generated_srcs"],
        semiwrap_header = [":{extension.name}.gen_modinit_hpp"],
        deps = deps + [
            ":{extension.name}.tmpl_hdrs",
            ":{extension.name}.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )""")

    def _process_extension_module(self, extension: ExtensionModuleConfig):


        print(type(extension))
        print(extension.name)

        self.output_buffer.writeln(f"""def {extension.name}_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):""")


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

    def generate(self, output_file: pathlib.Path):
        for package_name, extension in self._sorted_extension_modules():
            self._process_extension_module(extension)
            
            if extension.yaml_path is None:
                yaml_path = pathlib.Path("semiwrap")
            else:
                yaml_path = pathlib.Path(pathlib.PurePosixPath(extension.yaml_path))
            self._process_headers(extension, yaml_path)
            self._write_extension_data(package_name, extension)
        
        with open(output_file, 'w') as f:
            f.write(self.output_buffer.getvalue())

def generate_build_info(project_file: pathlib.Path, output_file: pathlib.Path):
    generator = Generator(project_file)
    generator.generate(output_file)
    



def main():
    project_files = [
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/pyntcore/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-apriltag/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-cscore/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-hal/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-halsim-ds-socket/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-halsim-gui/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-halsim-ws/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-romi/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-wpilib/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-wpimath/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-wpimath/tests/cpp/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-wpinet/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-wpiutil/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-wpiutil/tests/cpp/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy/subprojects/robotpy-xrp/pyproject.toml"),
    ]

    for project_file in project_files:
        print(f"Running for {project_file}")
        generate_build_info(project_file, project_file.parent / "generated_build_info.bzl")



if __name__ == "__main__":
    main()