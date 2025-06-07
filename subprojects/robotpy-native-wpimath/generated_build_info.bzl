load("@rules_semiwrap//:defs.bzl", "create_native_library")

def define_library(name, headers, headers_external_repositories, shared_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-wpimath",
        entry_points = {"pkg_config": ["wpimath = native.wpimath"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "wpimath",
        pc_dep_deps = [
            "//subprojects/robotpy-native-wpiutil:import",
        ],
        pc_dep_files = [
            "$(location //subprojects/robotpy-native-wpiutil:import)/site-packages/native/wpiutil/robotpy-native-wpiutil.pc",
        ],
        package_requires = ["robotpy-native-wpiutil==2027.0.0a1.dev0"],
        package_summary = "WPILib Math Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-wpimath"],
        version = version,
    )
