load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")
load("@rules_semiwrap//:defs.bzl", "create_native_library")
load("//bazel_scripts:file_resolver_utils.bzl", "local_pc_file_util")

def define_library(name, headers, headers_external_repositories, shared_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-wpihal",
        entry_points = {"pkg_config": ["wpihal = native.wpihal"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "wpihal",
        local_pc_file_info =
            local_pc_file_util("//subprojects/robotpy-native-wpiutil", ["native/wpiutil/robotpy-native-wpiutil.pc"]),
        package_requires = ["robotpy-native-wpiutil==2025.3.2"],
        package_summary = "WPILib HAL implementation",
        strip_pkg_prefix = ["subprojects/robotpy-native-wpihal"],
        version = version,
    )

    whl_filegroup(
        name = "header_files",
        pattern = "native/wpihal/include",
        whl = ":robotpy-native-wpihal-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpihal",
        srcs = [shared_library],
        hdrs = [":header_files"],
        includes = ["header_files/native/wpihal/include"],
        visibility = ["//visibility:public"],
        deps = [
            "//subprojects/robotpy-native-wpiutil:wpiutil",
        ],
        tags = ["manual"],
    )
