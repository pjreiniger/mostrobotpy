load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")
load("@rules_semiwrap//:defs.bzl", "create_native_library")
load("//bazel_scripts:file_resolver_utils.bzl", "local_pc_file_util")

def define_library(name, headers, headers_external_repositories, shared_library, windows_interface_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-wpiutil",
        entry_points = {"pkg_config": ["wpiutil = native.wpiutil"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "wpiutil",
        local_pc_file_info = [],
        package_requires = ["msvc-runtime>=14.42.34433; platform_system == 'Windows'"],
        package_summary = "WPILib Utility Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-wpiutil"],
        version = version,
    )

    whl_filegroup(
        name = "header_files",
        pattern = "native/wpiutil/include",
        whl = ":robotpy-native-wpiutil-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpiutil",
        srcs = [shared_library],
        hdrs = [":header_files"],
        includes = ["header_files/native/wpiutil/include"],
        visibility = ["//visibility:public"],
        deps = [
        ] + select({
            "@bazel_tools//src/conditions:windows": [windows_interface_library],
            "//conditions:default": [],
        }),
        tags = ["manual"],
    )
