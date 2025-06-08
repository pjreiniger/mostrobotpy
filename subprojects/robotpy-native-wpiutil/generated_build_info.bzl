load("@rules_semiwrap//:defs.bzl", "create_native_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")

def define_library(name, headers, headers_external_repositories, shared_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-wpiutil",
        entry_points = {"pkg_config": ["wpiutil = native.wpiutil"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "wpiutil",
        pc_dep_deps = [
        ],
        pc_dep_files = [
        ],
        package_requires = ["msvc-runtime>=14.42.34433; platform_system == 'Windows'"],
        package_summary = "WPILib Utility Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-wpiutil"],
        version = version,
    )

    whl_filegroup(
        name = "header_files",
        pattern = "native/wpiutil/include",
        whl = ":robotpy-native-wpiutil-wheel",
    )

    native.cc_library(
        name = "wpiutil",
        srcs = [shared_library],
        hdrs = [":header_files"],
        includes = ["header_files/native/wpiutil/include"],
        visibility = ["//visibility:public"],
        deps = [
        ],
    )
