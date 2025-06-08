load("@rules_semiwrap//:defs.bzl", "create_native_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")

def define_library(name, headers, headers_external_repositories, shared_library, version):
    create_native_library(
        name = name,
        package_name = "robotpy-native-wpinet",
        entry_points = {"pkg_config": ["wpinet = native.wpinet"]},
        headers = headers,
        headers_external_repositories = headers_external_repositories,
        shared_library = shared_library,
        lib_name = "wpinet",
        pc_dep_deps = [
            "//subprojects/robotpy-native-wpiutil:import",
        ],
        pc_dep_files = [
            "$(location //subprojects/robotpy-native-wpiutil:import)/site-packages/native/wpiutil/robotpy-native-wpiutil.pc",
        ],
        package_requires = ["robotpy-native-wpiutil==2027.0.0a1.dev0"],
        package_summary = "WPILib Networking Library",
        strip_pkg_prefix = ["subprojects/robotpy-native-wpinet"],
        version = version,
    )

    whl_filegroup(
        name = "header_files",
        pattern = "native/wpinet/include",
        whl = ":robotpy-native-wpinet-wheel",
    )

    native.cc_library(
        name = "wpinet",
        srcs = [shared_library],
        hdrs = [":header_files"],
        includes = ["header_files/native/wpinet/include"],
        visibility = ["//visibility:public"],
    )
