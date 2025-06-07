load("@rules_semiwrap//:defs.bzl", "create_native_library")

def define_library(name, headers, headers_external_repositories, shared_library, version):

    create_native_library(
        name = name,
        package_name = "robotpy-native-romi",
        entry_points = {"pkg_config": ["romi = native.romi"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "romi",
        package_requires = ["robotpy-native-wpilib==2025.3.2"],
        package_summary = "WPILib Romi support library",
        strip_pkg_prefix = ["subprojects/robotpy-native-romi"],
        version = version,
        pc_dep_deps = [
            "//subprojects/robotpy-native-wpilib:import",
        ],
        pc_dep_files = [
            "$(location //subprojects/robotpy-native-wpilib:import)/site-packages/native/wpilib/robotpy-native-wpilib.pc",
        ],
    )
