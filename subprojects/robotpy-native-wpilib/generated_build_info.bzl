load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")
load("@rules_semiwrap//:defs.bzl", "create_native_library")

def define_library(name, headers, headers_external_repositories, shared_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-wpilib",
        entry_points = {"pkg_config": ["wpilib = native.wpilib"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "wpilib",
        pc_dep_deps = [
            "//subprojects/robotpy-native-ntcore:import",
            "//subprojects/robotpy-native-wpihal:import",
            "//subprojects/robotpy-native-wpimath:import",
            "//subprojects/robotpy-native-wpinet:import",
            "//subprojects/robotpy-native-wpiutil:import",
        ],
        pc_dep_files = [
            "$(location //subprojects/robotpy-native-ntcore:import)/site-packages/native/ntcore/robotpy-native-ntcore.pc",
            "$(location //subprojects/robotpy-native-wpihal:import)/site-packages/native/wpihal/robotpy-native-wpihal.pc",
            "$(location //subprojects/robotpy-native-wpimath:import)/site-packages/native/wpimath/robotpy-native-wpimath.pc",
            "$(location //subprojects/robotpy-native-wpinet:import)/site-packages/native/wpinet/robotpy-native-wpinet.pc",
            "$(location //subprojects/robotpy-native-wpiutil:import)/site-packages/native/wpiutil/robotpy-native-wpiutil.pc",
        ],
        package_requires = ["robotpy-native-wpiutil==2025.3.2", "robotpy-native-wpinet==2025.3.2", "robotpy-native-ntcore==2025.3.2", "robotpy-native-wpimath==2025.3.2", "robotpy-native-wpihal==2025.3.2"],
        package_summary = "WPILib Robotics Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-wpilib"],
        version = version,
    )

    whl_filegroup(
        name = "header_files",
        pattern = "native/wpilib/include",
        whl = ":robotpy-native-wpilib-wheel",
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
        ],
    )
