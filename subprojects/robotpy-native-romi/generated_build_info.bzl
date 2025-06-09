load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")
load("@rules_semiwrap//:defs.bzl", "create_native_library")
load("//bazel_scripts:file_resolver_utils.bzl", "local_pc_file_util")

def define_library(name, headers, headers_external_repositories, shared_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-romi",
        entry_points = {"pkg_config": ["romi = native.romi"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "romi",
        local_pc_file_info =
            local_pc_file_util("//subprojects/robotpy-native-wpilib", ["native/wpilib/robotpy-native-wpilib.pc"]),
        package_requires = ["robotpy-native-wpilib==2025.3.2"],
        package_summary = "WPILib Romi support library",
        strip_pkg_prefix = ["subprojects/robotpy-native-romi"],
        version = version,
    )

    whl_filegroup(
        name = "header_files",
        pattern = "native/romi/include",
        whl = ":robotpy-native-romi-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "romi",
        srcs = [shared_library],
        hdrs = [":header_files"],
        includes = ["header_files/native/romi/include"],
        visibility = ["//visibility:public"],
        deps = [
            "//subprojects/robotpy-native-wpilib:wpilib",
        ],
        tags = ["manual"],
    )
