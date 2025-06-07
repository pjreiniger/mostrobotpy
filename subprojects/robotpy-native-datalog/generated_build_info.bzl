load("@rules_semiwrap//:defs.bzl", "create_native_library")

def define_library(name, headers, headers_external_repositories, shared_library, version):
    create_native_library(
        name = "datalog",
        package_name = "robotpy-native-datalog",
        entry_points = {"pkg_config": ["datalog = native.datalog"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "datalog",
        package_requires = [
            "robotpy-native-wpiutil==2025.3.2",
        ],
        pc_dep_deps = [
            # "//subprojects/robotpy-native-ntcore:import",
            "//subprojects/robotpy-native-wpiutil:import",
            # "//subprojects/robotpy-native-wpinet:import",
        ],
        pc_dep_files = [
            # "$(location //subprojects/robotpy-native-ntcore:import)/site-packages/native/ntcore/robotpy-native-ntcore.pc",
            # "$(location //subprojects/robotpy-native-wpinet:import)/site-packages/native/wpinet/robotpy-native-wpinet.pc",
            "$(location //subprojects/robotpy-native-wpiutil:import)/site-packages/native/wpiutil/robotpy-native-wpiutil.pc",
        ],
        package_summary = "WPILib NetworkTables Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-datalog"],
        version = version,
    )
