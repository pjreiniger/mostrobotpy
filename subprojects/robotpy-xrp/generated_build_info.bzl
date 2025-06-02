load("@rules_semiwrap//:defs.bzl", "create_pybind_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")

def xrp_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    XRP_HEADER_GEN = [
        struct(
            class_name = "XRPGyro",
            yml_file = "semiwrap/XRPGyro.yml",
            header_root = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include",
            header_file = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include/frc/xrp/XRPGyro.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPGyro", "frc__XRPGyro.hpp"),
            ],
        ),
        struct(
            class_name = "XRPMotor",
            yml_file = "semiwrap/XRPMotor.yml",
            header_root = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include",
            header_file = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include/frc/xrp/XRPMotor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPMotor", "frc__XRPMotor.hpp"),
            ],
        ),
        struct(
            class_name = "XRPOnBoardIO",
            yml_file = "semiwrap/XRPOnBoardIO.yml",
            header_root = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include",
            header_file = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include/frc/xrp/XRPOnBoardIO.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPOnBoardIO", "frc__XRPOnBoardIO.hpp"),
            ],
        ),
        struct(
            class_name = "XRPRangefinder",
            yml_file = "semiwrap/XRPRangefinder.yml",
            header_root = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include",
            header_file = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include/frc/xrp/XRPRangefinder.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPRangefinder", "frc__XRPRangefinder.hpp"),
            ],
        ),
        struct(
            class_name = "XRPReflectanceSensor",
            yml_file = "semiwrap/XRPReflectanceSensor.yml",
            header_root = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include",
            header_file = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include/frc/xrp/XRPReflectanceSensor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPReflectanceSensor", "frc__XRPReflectanceSensor.hpp"),
            ],
        ),
        struct(
            class_name = "XRPServo",
            yml_file = "semiwrap/XRPServo.yml",
            header_root = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include",
            header_file = "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include/frc/xrp/XRPServo.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPServo", "frc__XRPServo.hpp"),
            ],
        ),
    ]
    resolve_casters(
        name = "xrp.resolve_casters",
        caster_files = ["//subprojects/robotpy-wpimath:generated/publish_casters/wpimath-casters.pybind11.json", "//subprojects/robotpy-wpiutil:generated/publish_casters/wpiutil-casters.pybind11.json"],
        casters_pkl_file = "xrp.casters.pkl",
        dep_file = "xrp.casters.d",
    )

    gen_libinit(
        name = "xrp.gen_lib_init",
        output_file = "xrp/_init__xrp.py",
        modules = ["native.xrp._init_robotpy_native_xrp", "wpilib._init__wpilib", "wpimath.geometry._init__geometry"],
    )

    gen_pkgconf(
        name = "xrp.gen_pkgconf",
        libinit_py = "xrp._init__xrp",
        module_pkg_name = "xrp._xrp",
        output_file = "xrp.pc",
        pkg_name = "xrp",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "xrp.gen_modinit_hpp",
        input_dats = [x.class_name for x in XRP_HEADER_GEN],
        libname = "_xrp",
        output_file = "semiwrap_init.xrp._xrp.hpp",
    )

    run_header_gen(
        name = "xrp",
        casters_pickle = "xrp.casters.pkl",
        header_gen_config = XRP_HEADER_GEN,
        deps = header_to_dat_deps,
        header_to_dat_deps = ["//subprojects/robotpy-native-xrp:import", "//subprojects/robotpy-native-wpihal:import", "//subprojects/robotpy-native-ntcore:import", "//subprojects/robotpy-native-wpimath:import", "//subprojects/robotpy-native-wpinet:import", "//subprojects/robotpy-native-wpilib:import", "//subprojects/robotpy-native-wpiutil:import"],
        generation_includes = [
            "$(location //subprojects/robotpy-native-ntcore:import)/site-packages/native/ntcore/include",
            "$(location //subprojects/robotpy-native-wpilib:import)/site-packages/native/wpilib/include",
            "$(location //subprojects/robotpy-native-wpimath:import)/site-packages/native/wpimath/include",
            "$(location //subprojects/robotpy-native-wpinet:import)/site-packages/native/wpinet/include",
            "$(location //subprojects/robotpy-native-wpiutil:import)/site-packages/native/wpiutil/include",
            "$(location //subprojects/robotpy-native-xrp:import)/site-packages/native/xrp/include",
        ],
    )

    native.filegroup(
        name = "xrp.generated_files",
        srcs = [
            "xrp.gen_modinit_hpp.gen",
            "xrp.header_gen_files",
            "xrp.gen_pkgconf",
            "xrp.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "xrp",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":xrp.generated_srcs"],
        semiwrap_header = [":xrp.gen_modinit_hpp"],
        deps = deps + [
            ":xrp.tmpl_hdrs",
            ":xrp.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )
