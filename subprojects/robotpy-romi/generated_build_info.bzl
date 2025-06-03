load("@rules_semiwrap//:defs.bzl", "copy_extension_library", "create_pybind_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")

def _local_include_root(project_import, include_subpackage):
    return "$(location " + project_import + ")/site-packages/native/" + include_subpackage + "/include"

def romi_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    ROMI_HEADER_GEN = [
        struct(
            class_name = "OnBoardIO",
            yml_file = "semiwrap/OnBoardIO.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-romi:import", "romi"),
            header_file = _local_include_root("//subprojects/robotpy-native-romi:import", "romi") + "/frc/romi/OnBoardIO.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::OnBoardIO", "frc__OnBoardIO.hpp"),
            ],
        ),
        struct(
            class_name = "RomiGyro",
            yml_file = "semiwrap/RomiGyro.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-romi:import", "romi"),
            header_file = _local_include_root("//subprojects/robotpy-native-romi:import", "romi") + "/frc/romi/RomiGyro.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::RomiGyro", "frc__RomiGyro.hpp"),
            ],
        ),
        struct(
            class_name = "RomiMotor",
            yml_file = "semiwrap/RomiMotor.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-romi:import", "romi"),
            header_file = _local_include_root("//subprojects/robotpy-native-romi:import", "romi") + "/frc/romi/RomiMotor.h",
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
        local_native_libraries = [
            ("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            ("//subprojects/robotpy-native-romi:import", "romi"),
            ("//subprojects/robotpy-native-wpilib:import", "wpilib"),
            ("//subprojects/robotpy-native-wpimath:import", "wpimath"),
            ("//subprojects/robotpy-native-wpinet:import", "wpinet"),
            ("//subprojects/robotpy-native-wpiutil:import", "wpiutil"),
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

def get_generated_data_files():
    copy_extension_library(
        name = "copy_romi",
        extension = "_romi",
        output_directory = "romi/",
    )

    native.filegroup(
        name = "romi.generated_data_files",
        srcs = [
            "romi/romi.pc",
        ],
    )

    return [
        ":romi.generated_data_files",
        ":copy_romi",
    ]

def libinit_files():
    return [
        "romi/_init__romi.py",
    ]
