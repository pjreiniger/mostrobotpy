
import os
from robotbuild_generation.pybind_gen_utils import Setup
from robotpy_build.wrapper import Wrapper
from pathlib import Path



def write_toplevel(setup, project_root):
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
    headers = ["@bazelrio_edu_wpi_first_{setup.project.base_package}_{setup.project.base_package}-cpp_headers//:header_files"],
)

pybind_python_library(
    name = "{setup.project.base_package}",
    srcs = ["//subprojects/{setup.pypi_package}/{setup.project.base_package}:python_files"],
    data = [
        "//subprojects/{setup.pypi_package}/{setup.project.base_package}:copy_lib",
        "//subprojects/{setup.pypi_package}/{setup.project.base_package}:{setup.project.base_package}.pyso",
    ],
    imports = ["."],
    visibility = ["//visibility:public"],
)

py_library(
    name = "pkgcfg",
    srcs = [
        "//subprojects/{setup.pypi_package}/{setup.project.base_package}:pkgcfg",
    ],
    imports = ["."],
    visibility = ["//visibility:public"],
)

"""
    
    with open(project_root / "BUILD.bazel", 'w') as f:
        f.write(contents)


def generate_subproject(setup, project_root, wrapper):

    gen_deps = ""
    pybind_deps = ""
    if wrapper.depends:
        pybind_deps += "\n"
        pybind_deps += '        "//subprojects/robotpy-wpiutil/wpiutil:wpiutil_pybind_library",'

        gen_deps += '    internal_project_dependencies = ["wpiutil"],\n'
        gen_deps += '    python_deps = [\n'
        gen_deps += '        "//subprojects/robotpy-wpiutil:pkgcfg",\n'
        gen_deps += '    ],\n'

    contents = f"""load("@rules_cc//cc:defs.bzl", "cc_library")
load("//rules_robotpy_utils:copy_native_file.bzl", "copy_native_file")
load("//rules_robotpy_utils:generate_robotpy_project_files.bzl", "generate_robotpy_project_files")
load("//rules_robotpy_utils:pybind_rules.bzl", "create_pybind_library")

generate_robotpy_project_files(
    name = "{wrapper.package_name}",
    config_file = "//subprojects/{setup.pypi_package}:config_file",
{gen_deps}    visibility = ["//subprojects/{setup.pypi_package}:__subpackages__"],
)


create_pybind_library(
    "{wrapper.package_name}",
    entry_point = ["src/main.cpp"],
    extension_visibility = ["//subprojects/{setup.pypi_package}:__subpackages__"],
    generation_helper_prefix = "//subprojects/{setup.pypi_package}:{wrapper.package_name}",
    deps = [{pybind_deps}
        "@bzlmodrio-allwpilib//libraries/cpp/{wrapper.package_name}",
    ],
)


alias(
    name = "TEMP_shared_library",
    actual = select({{
        "@bazel_tools//src/conditions:darwin": "@bazelrio_edu_wpi_first_{wrapper.package_name}_{wrapper.package_name}-cpp_osxuniversal//:shared_libs",
        "@rules_bazelrio//conditions:windows": "@bazelrio_edu_wpi_first_{wrapper.package_name}_{wrapper.package_name}-cpp_windowsx86-64//:shared_libs",
        "//conditions:default":                "@bazelrio_edu_wpi_first_{wrapper.package_name}_{wrapper.package_name}-cpp_linuxx86-64//:shared",
    }}),
)

copy_native_file(
    name = "{wrapper.package_name}",
    library = ":TEMP_shared_library",
)

filegroup(
    name = "python_files",
    srcs = glob(["*.py"]),
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

    write_toplevel(setup, project_root)
    
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

