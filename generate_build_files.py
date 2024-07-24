
import os
from robotbuild_generation.pybind_gen_utils import Setup
from robotpy_build.wrapper import Wrapper
from pathlib import Path



def write_toplevel(setup, project_root, wrappers):
    print("Writing top level...")

    gen_internal_proj_deps = ""
    gen_python_deps = ""
    pybind_deps = None
    pkgcfg_deps = ""


    seen_deps = set()

    for wrapper in wrappers:
        print("--Wrapper", wrapper.package_name)

        if wrapper.depends:
            if pybind_deps is None:
                pybind_deps = "deps = [\n"
                gen_internal_proj_deps += 'internal_project_dependencies = ['
                gen_python_deps = "python_deps = ["
                pkgcfg_deps += "deps = ["

            for dep in wrapper.depends:
                if dep in seen_deps:
                    continue
                gen_internal_proj_deps += f'"{dep}",'
                pybind_deps += f'        "//subprojects/robotpy-{dep}:{dep}",'
                gen_python_deps += f'"//subprojects/robotpy-{dep}:pkgcfg",\n'
                pkgcfg_deps += f'"//subprojects/robotpy-{dep}:pkgcfg",\n'
                seen_deps.add(dep)

    if pybind_deps:
        pybind_deps += "]"
        gen_internal_proj_deps += '],\n'
        gen_python_deps += '],\n'
        pkgcfg_deps += '],\n'
    else:
        pybind_deps = ""


    contents = f"""load("@rules_python//python:defs.bzl", "py_library")
load("//rules_robotpy_utils:generate_robotpy_source_files.bzl", "generate_robotpy_source_files")
load("//rules_robotpy_utils:pybind_rules.bzl", "generated_files_helper", "pybind_python_library")

generated_files_helper(
    name = "{setup.project.base_package}",
    visibility = ["//subprojects/{setup.pypi_package}:__subpackages__"],
)

filegroup(
    name = "config_file",
    srcs = ["pyproject.toml"],
    visibility = ["//subprojects/{setup.pypi_package}:__subpackages__"],
)

generate_robotpy_source_files(
    name = "{setup.project.base_package}",
    config_file = ":config_file",
    headers = ["@bzlmodrio-allwpilib//libraries/cpp/{wrapper.package_name}:header_files"],
{gen_internal_proj_deps}{gen_python_deps})

pybind_python_library(
    name = "{setup.project.base_package}",
    srcs = ["//subprojects/{setup.pypi_package}/{setup.project.base_package}:python_files"],
    data = [
        "//subprojects/{setup.pypi_package}/{setup.project.base_package}:copy_lib",
        "//subprojects/{setup.pypi_package}/{setup.project.base_package}:{setup.project.base_package}.pyso",
    ],
    imports = ["."],
    visibility = ["//visibility:public"],
{pybind_deps})

py_library(
    name = "pkgcfg",
    srcs = [
        "//subprojects/{setup.pypi_package}/{setup.project.base_package}:pkgcfg",
    ],
    imports = ["."],
    visibility = ["//visibility:public"],
{pkgcfg_deps})
"""
    
    with open(project_root / "BUILD.bazel", 'w') as f:
        f.write(contents)


def generate_subproject(setup, project_root, wrapper):

    gen_internal_proj_deps = ""
    gen_python_deps = ""
    pybind_deps = ""
    if wrapper.depends:
        pybind_deps += "deps = [\n"
        gen_internal_proj_deps += 'internal_project_dependencies = ['
        gen_python_deps = "python_deps = ["
        # pkgcfg_deps += "deps = ["

        for dep in wrapper.depends:
            print(dep, type(dep))
            gen_internal_proj_deps += f'"{dep}",'
        #     pybind_deps += f'        "//subprojects/robotpy-{dep}:{dep}",'
            gen_python_deps += f'"//subprojects/robotpy-{dep}:pkgcfg",\n'
        #     # pkgcfg_deps += f'"//subprojects/robotpy-{dep}:pkgcfg",\n'

        pybind_deps += "]"
        gen_internal_proj_deps += '],\n'
        gen_python_deps += '],\n'
        # pkgcfg_deps += '],\n'
        # pybind_deps += "\n"
        # pybind_deps += '        "//subprojects/robotpy-wpiutil/wpiutil:wpiutil_pybind_library",'

        # gen_deps += '    internal_project_dependencies = ["wpiutil"],\n'
        # gen_deps += '    python_deps = [\n'
        # gen_deps += '        "//subprojects/robotpy-wpiutil:pkgcfg",\n'
        # gen_deps += '    ],\n'


    entry_point = None
    extra_srcs = ""
    for src in wrapper.cfg.sources:
        print(wrapper.package_name)
        stripped_src = src.removeprefix(f"{wrapper.package_name}/")
        if src.endswith("main.cpp") or src.endswith(f"{wrapper.package_name}.cpp"):
            entry_point = stripped_src
        else:
            extra_srcs += "        \"" + stripped_src + "\",\n"
        print(src, " -> ", stripped_src)

    if extra_srcs:
        extra_srcs = "    extra_srcs = [\n" + extra_srcs + "\n    ],\n"

    contents = f"""load("@rules_cc//cc:defs.bzl", "cc_library")
load("//rules_robotpy_utils:copy_native_file.bzl", "copy_native_file")
load("//rules_robotpy_utils:generate_robotpy_project_files.bzl", "generate_robotpy_project_files")
load("//rules_robotpy_utils:pybind_rules.bzl", "create_pybind_library")

generate_robotpy_project_files(
    name = "{wrapper.package_name}",
    config_file = "//subprojects/{setup.pypi_package}:config_file",
{gen_internal_proj_deps}{gen_python_deps}    visibility = ["//subprojects/{setup.pypi_package}:__subpackages__"],
)


create_pybind_library(
    "{wrapper.package_name}",
    entry_point = ["{entry_point}"],
    extension_visibility = ["//subprojects/{setup.pypi_package}:__subpackages__"],
{extra_srcs}    generation_helper_prefix = "//subprojects/{setup.pypi_package}:{wrapper.package_name}",
    deps = [
        "@bzlmodrio-allwpilib//libraries/cpp/{wrapper.package_name}",
    ],
)

copy_native_file(
    name = "{wrapper.package_name}",
    library = "@bzlmodrio-allwpilib//libraries/cpp/{wrapper.package_name}:shared_raw",
)

filegroup(
    name = "python_files",
    srcs = glob(["**/*.py"]),
    visibility = ["//subprojects/{setup.pypi_package}:__subpackages__"],
)
"""

    output_file = project_root / wrapper.package_name.replace(".", "/") / "BUILD.bazel"
    print("Trying to write to ", output_file)
    with open(output_file, 'w') as f:
        f.write(contents)


def generate_project_build_files(project_root):
    config = project_root / "pyproject.toml"
    
    setup = Setup(config, ".", [])
    # print(setup.project.base_package)

    write_toplevel(setup, project_root, setup.wrappers)
    
    for wrapper in setup.wrappers:
        print(wrapper.package_name)
        try:
            generate_subproject(setup, project_root, wrapper)
        except:
            raise
        # print(wrapper.package_name)


def main():
    SUBPROJECTS = [
        "pyntcore",
        "robotpy-apriltag",
        "robotpy-cscore",
        "robotpy-hal",
        "robotpy-halsim-ds-socket",
        "robotpy-halsim-gui",
        "robotpy-halsim-ws",
        "robotpy-wpimath",
        "robotpy-wpinet",
        "robotpy-wpiutil",
    ]

    for p in SUBPROJECTS:
        project_root = Path(f"/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/{p}")
        generate_project_build_files(project_root)



if __name__ == "__main__":
    main()

