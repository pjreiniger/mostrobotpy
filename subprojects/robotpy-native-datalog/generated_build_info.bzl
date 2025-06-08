load("@rules_semiwrap//:defs.bzl", "create_native_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")

def define_library(name, headers, headers_external_repositories, shared_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-datalog",
        entry_points = {"pkg_config": ["datalog = native.datalog"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "datalog",
        pc_dep_deps = [
            "//subprojects/robotpy-native-wpiutil:import",
        ],
        pc_dep_files = [
            "$(location //subprojects/robotpy-native-wpiutil:import)/site-packages/native/wpiutil/robotpy-native-wpiutil.pc",
        ],
        package_requires = ["robotpy-native-wpiutil==2027.0.0a1.dev0"],
        package_summary = "WPILib Utility Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-datalog"],
        version = version,
    )

    whl_filegroup(
        name = "header_files",
        pattern = "native/datalog/include",
        whl = ":robotpy-native-datalog-wheel",
    )

    native.cc_library(
        name = "datalog",
        srcs = [shared_library],
        hdrs = [":header_files"],
        includes = ["header_files/native/datalog/include"],
        visibility = ["//visibility:public"],
    )
