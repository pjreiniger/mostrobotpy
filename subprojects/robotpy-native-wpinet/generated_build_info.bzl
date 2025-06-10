load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")
load("@rules_semiwrap//:defs.bzl", "create_native_library")
load("//bazel_scripts:file_resolver_utils.bzl", "local_pc_file_util")

def define_library(name, headers, headers_external_repositories, shared_library, windows_interface_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-wpinet",
        entry_points = {"pkg_config": ["wpinet = native.wpinet"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "wpinet",
        local_pc_file_info =
            local_pc_file_util("//subprojects/robotpy-native-wpiutil", ["native/wpiutil/robotpy-native-wpiutil.pc"]),
        package_requires = ["robotpy-native-wpiutil==2025.3.2"],
        package_summary = "WPILib Networking Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-wpinet"],
        version = version,
    )

    whl_filegroup(
        name = "header_files",
        pattern = "native/wpinet/include",
        whl = ":robotpy-native-wpinet-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpinet",
        srcs = [shared_library],
        hdrs = [":header_files"],
        includes = ["header_files/native/wpinet/include"],
        visibility = ["//visibility:public"],
        deps = [
            "//subprojects/robotpy-native-wpiutil:wpiutil",
        ] + select({
            "@bazel_tools//src/conditions:windows": [windows_interface_library],
            "//conditions:default": [],
        }),
        tags = ["manual"],
    )
