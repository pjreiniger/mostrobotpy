load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")
load("@rules_semiwrap//:defs.bzl", "create_native_library")
load("//bazel_scripts:file_resolver_utils.bzl", "local_pc_file_util")

def define_library(name, headers, headers_external_repositories, shared_library, windows_interface_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-ntcore",
        entry_points = {"pkg_config": ["ntcore = native.ntcore"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "ntcore",
        local_pc_file_info =
            local_pc_file_util("//subprojects/robotpy-native-wpinet", ["native/wpinet/robotpy-native-wpinet.pc"]) +
            local_pc_file_util("//subprojects/robotpy-native-wpiutil", ["native/wpiutil/robotpy-native-wpiutil.pc"]),
        package_requires = ["robotpy-native-wpiutil==2025.3.2", "robotpy-native-wpinet==2025.3.2"],
        package_summary = "WPILib NetworkTables Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-ntcore"],
        version = version,
    )

    whl_filegroup(
        name = "header_files",
        pattern = "native/ntcore/include",
        whl = ":robotpy-native-ntcore-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "ntcore",
        srcs = [shared_library],
        hdrs = [":header_files"],
        includes = ["header_files/native/ntcore/include"],
        visibility = ["//visibility:public"],
        deps = [
            "//subprojects/robotpy-native-wpinet:wpinet",
            "//subprojects/robotpy-native-wpiutil:wpiutil",
        ] + select({
            "@bazel_tools//src/conditions:windows": [windows_interface_library],
            "//conditions:default": [],
        }),
        tags = ["manual"],
    )
