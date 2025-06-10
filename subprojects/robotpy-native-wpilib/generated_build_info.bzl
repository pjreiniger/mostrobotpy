load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")
load("@rules_semiwrap//:defs.bzl", "create_native_library")
load("//bazel_scripts:file_resolver_utils.bzl", "local_pc_file_util")

def define_library(name, headers, headers_external_repositories, shared_library, windows_interface_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-wpilib",
        entry_points = {"pkg_config": ["wpilib = native.wpilib"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "wpilib",
        local_pc_file_info =
            local_pc_file_util("//subprojects/robotpy-native-ntcore", ["native/ntcore/robotpy-native-ntcore.pc"]) +
            local_pc_file_util("//subprojects/robotpy-native-wpihal", ["native/wpihal/robotpy-native-wpihal.pc"]) +
            local_pc_file_util("//subprojects/robotpy-native-wpimath", ["native/wpimath/robotpy-native-wpimath.pc"]) +
            local_pc_file_util("//subprojects/robotpy-native-wpinet", ["native/wpinet/robotpy-native-wpinet.pc"]) +
            local_pc_file_util("//subprojects/robotpy-native-wpiutil", ["native/wpiutil/robotpy-native-wpiutil.pc"]),
        package_requires = ["robotpy-native-wpiutil==2025.3.2", "robotpy-native-wpinet==2025.3.2", "robotpy-native-ntcore==2025.3.2", "robotpy-native-wpimath==2025.3.2", "robotpy-native-wpihal==2025.3.2"],
        package_summary = "WPILib Robotics Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-wpilib"],
        version = version,
    )

    whl_filegroup(
        name = "header_files",
        pattern = "native/wpilib/include",
        whl = ":robotpy-native-wpilib-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpilib",
        srcs = [shared_library],
        hdrs = [":header_files"],
        includes = ["header_files/native/wpilib/include"],
        visibility = ["//visibility:public"],
        deps = [
            "//subprojects/robotpy-native-ntcore:ntcore",
            "//subprojects/robotpy-native-wpihal:wpihal",
            "//subprojects/robotpy-native-wpimath:wpimath",
            "//subprojects/robotpy-native-wpinet:wpinet",
            "//subprojects/robotpy-native-wpiutil:wpiutil",
        ] + select({
            "@bazel_tools//src/conditions:windows": [windows_interface_library],
            "//conditions:default": [],
        }),
        tags = ["manual"],
    )
