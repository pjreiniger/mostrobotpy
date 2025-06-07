load("@rules_semiwrap//:defs.bzl", "create_native_library")

def define_library(name, headers, headers_external_repositories, shared_library, version):

    create_native_library(
        name = "ntcore",
        package_name = "robotpy-native-ntcore",
        entry_points = {"pkg_config": ["ntcore = native.ntcore"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "ntcore",
        package_requires = [
            "robotpy-native-wpinet==2025.3.2",
            "robotpy-native-wpiutil==2025.3.2",
        ],
        pc_dep_deps = [
            "//subprojects/robotpy-native-datalog:import",
            "//subprojects/robotpy-native-wpiutil:import",
            "//subprojects/robotpy-native-wpinet:import",
        ],
        pc_dep_files = [
            "$(location //subprojects/robotpy-native-datalog:import)/site-packages/native/datalog/robotpy-native-datalog.pc",
            "$(location //subprojects/robotpy-native-wpinet:import)/site-packages/native/wpinet/robotpy-native-wpinet.pc",
            "$(location //subprojects/robotpy-native-wpiutil:import)/site-packages/native/wpiutil/robotpy-native-wpiutil.pc",
        ],
        package_summary = "WPILib NetworkTables Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-ntcore"],
        version = version,
    )
