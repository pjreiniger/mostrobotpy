load("@rules_semiwrap//:defs.bzl", "create_native_library")

def define_library(name, headers, headers_external_repositories, shared_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-ntcore",
        entry_points = {"pkg_config": ["ntcore = native.ntcore"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "ntcore",
        pc_dep_deps = [
            "//subprojects/robotpy-native-datalog:import",
            "//subprojects/robotpy-native-wpinet:import",
            "//subprojects/robotpy-native-wpiutil:import",
        ],
        pc_dep_files = [
            "$(location //subprojects/robotpy-native-datalog:import)/site-packages/native/datalog/robotpy-native-datalog.pc",
            "$(location //subprojects/robotpy-native-wpinet:import)/site-packages/native/wpinet/robotpy-native-wpinet.pc",
            "$(location //subprojects/robotpy-native-wpiutil:import)/site-packages/native/wpiutil/robotpy-native-wpiutil.pc",
        ],
        package_requires = ["robotpy-native-wpiutil==2027.0.0a1.dev0", "robotpy-native-wpinet==2027.0.0a1.dev0", "robotpy-native-datalog==2027.0.0a1.dev0"],
        package_summary = "WPILib NetworkTables Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-ntcore"],
        version = version,
    )
