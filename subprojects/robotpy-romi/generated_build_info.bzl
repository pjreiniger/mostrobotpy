load("@rules_semiwrap//:defs.bzl", "create_pybind_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")

def romi_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    ROMI_HEADER_GEN = [
        struct(
            class_name = "OnBoardIO",
            yml_file = "semiwrap/OnBoardIO.yml",
            header_root = "$(location //subprojects/robotpy-native-romi:import)/site-packages/native/romi/include",
            header_file = "$(location //subprojects/robotpy-native-romi:import)/site-packages/native/romi/include/frc/romi/OnBoardIO.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::OnBoardIO", "frc__OnBoardIO.hpp"),
            ],
        ),
        struct(
            class_name = "RomiGyro",
            yml_file = "semiwrap/RomiGyro.yml",
            header_root = "$(location //subprojects/robotpy-native-romi:import)/site-packages/native/romi/include",
            header_file = "$(location //subprojects/robotpy-native-romi:import)/site-packages/native/romi/include/frc/romi/RomiGyro.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::RomiGyro", "frc__RomiGyro.hpp"),
            ],
        ),
        struct(
            class_name = "RomiMotor",
            yml_file = "semiwrap/RomiMotor.yml",
            header_root = "$(location //subprojects/robotpy-native-romi:import)/site-packages/native/romi/include",
            header_file = "$(location //subprojects/robotpy-native-romi:import)/site-packages/native/romi/include/frc/romi/RomiMotor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::RomiMotor", "frc__RomiMotor.hpp"),
            ],
        ),
    ]
    resolve_casters(
        name = "romi.resolve_casters",
        caster_files = [
            "$(location //subprojects/robotpy-wpiutil:import)" + "/site-packages/wpiutil/wpiutil-casters.pybind11.json",
            "$(location //subprojects/robotpy-wpimath:import)" + "/site-packages/wpimath/wpimath-casters.pybind11.json",
        ],
        caster_deps = ["//subprojects/robotpy-wpiutil:import", "//subprojects/robotpy-wpimath:import"],
        casters_pkl_file = "romi.casters.pkl",
        dep_file = "romi.casters.d",
    )

    gen_libinit(
        name = "romi.gen_lib_init",
        output_file = "romi/_init__romi.py",
        modules = ["native.romi._init_robotpy_native_romi", "wpilib._init__wpilib", "wpimath.geometry._init__geometry"],
    )

    gen_pkgconf(
        name = "romi.gen_pkgconf",
        libinit_py = "romi._init__romi",
        module_pkg_name = "romi._romi",
        output_file = "romi.pc",
        pkg_name = "romi",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "romi.gen_modinit_hpp",
        input_dats = [x.class_name for x in ROMI_HEADER_GEN],
        libname = "_romi",
        output_file = "semiwrap_init.romi._romi.hpp",
    )

    run_header_gen(
        name = "romi",
        casters_pickle = "romi.casters.pkl",
        header_gen_config = ROMI_HEADER_GEN,
        deps = header_to_dat_deps,
        header_to_dat_deps = ["//subprojects/robotpy-native-romi:import", "//subprojects/robotpy-native-wpihal:import", "//subprojects/robotpy-native-ntcore:import", "//subprojects/robotpy-native-wpimath:import", "//subprojects/robotpy-native-wpinet:import", "//subprojects/robotpy-native-wpilib:import", "//subprojects/robotpy-native-wpiutil:import"],
        generation_includes = [
            "$(location //subprojects/robotpy-native-ntcore:import)/site-packages/native/ntcore/include",
            "$(location //subprojects/robotpy-native-wpilib:import)/site-packages/native/wpilib/include",
            "$(location //subprojects/robotpy-native-wpimath:import)/site-packages/native/wpimath/include",
            "$(location //subprojects/robotpy-native-wpinet:import)/site-packages/native/wpinet/include",
            "$(location //subprojects/robotpy-native-wpiutil:import)/site-packages/native/wpiutil/include",
            "$(location //subprojects/robotpy-native-romi:import)/site-packages/native/romi/include",
        ],
    )

    native.filegroup(
        name = "romi.generated_files",
        srcs = [
            "romi.gen_modinit_hpp.gen",
            "romi.header_gen_files",
            "romi.gen_pkgconf",
            "romi.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "romi",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":romi.generated_srcs"],
        semiwrap_header = [":romi.gen_modinit_hpp"],
        deps = deps + [
            ":romi.tmpl_hdrs",
            ":romi.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )
