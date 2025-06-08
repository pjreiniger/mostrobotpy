load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")
load("@rules_semiwrap//:defs.bzl", "create_native_library")

def define_library(name, headers, headers_external_repositories, shared_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-apriltag",
        entry_points = {"pkg_config": ["apriltag = native.apriltag"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "apriltag",
        pc_dep_deps = [
            "//subprojects/robotpy-native-wpimath:import",
            "//subprojects/robotpy-native-wpiutil:import",
        ],
        pc_dep_files = [
            "$(location //subprojects/robotpy-native-wpimath:import)/site-packages/native/wpimath/robotpy-native-wpimath.pc",
            "$(location //subprojects/robotpy-native-wpiutil:import)/site-packages/native/wpiutil/robotpy-native-wpiutil.pc",
        ],
        package_requires = ["robotpy-native-wpiutil==2025.3.2", "robotpy-native-wpimath==2025.3.2"],
        package_summary = "WPILib AprilTag Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-apriltag"],
        version = version,
    )

    whl_filegroup(
        name = "header_files",
        pattern = "native/apriltag/include",
        whl = ":robotpy-native-apriltag-wheel",
    )
    cc_library(
        name = "apriltag",
        srcs = [shared_library],
        hdrs = [":header_files"],
        includes = ["header_files/native/apriltag/include"],
        visibility = ["//visibility:public"],
        deps = [
            "//subprojects/robotpy-native-wpimath:wpimath",
            "//subprojects/robotpy-native-wpiutil:wpiutil",
        ],
    )
