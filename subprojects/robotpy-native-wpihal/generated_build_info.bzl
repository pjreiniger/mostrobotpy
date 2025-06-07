load("@rules_semiwrap//:defs.bzl", "create_native_library")

def define_library(name, headers, headers_external_repositories, shared_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-wpihal",
        entry_points = {"pkg_config": ["wpihal = native.wpihal"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "wpihal",
        pc_dep_deps = [
            "//subprojects/robotpy-native-ntcore:import",
            "//subprojects/robotpy-native-wpiutil:import",
        ],
        pc_dep_files = [
            "$(location //subprojects/robotpy-native-ntcore:import)/site-packages/native/ntcore/robotpy-native-ntcore.pc",
            "$(location //subprojects/robotpy-native-wpiutil:import)/site-packages/native/wpiutil/robotpy-native-wpiutil.pc",
        ],
        package_requires = ["robotpy-native-wpiutil==2027.0.0a1.dev0", "robotpy-native-ntcore==2027.0.0a1.dev0"],
        package_summary = "WPILib HAL implementation",
        strip_pkg_prefix = ["subprojects/robotpy-native-wpihal"],
        version = version,
    )
