load("@rules_semiwrap//:defs.bzl", "copy_extension_library", "create_pybind_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")
load("//bazel_scripts:file_resolver_utils.bzl", "local_native_libraries_helper", "resolve_include_root", "resolve_caster_file")

def xrp_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    XRP_HEADER_GEN = [
        struct(
            class_name = "XRPGyro",
            yml_file = "semiwrap/XRPGyro.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp"),
            header_file = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp") + "/frc/xrp/XRPGyro.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPGyro", "frc__XRPGyro.hpp"),
            ],
        ),
        struct(
            class_name = "XRPMotor",
            yml_file = "semiwrap/XRPMotor.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp"),
            header_file = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp") + "/frc/xrp/XRPMotor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPMotor", "frc__XRPMotor.hpp"),
            ],
        ),
        struct(
            class_name = "XRPOnBoardIO",
            yml_file = "semiwrap/XRPOnBoardIO.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp"),
            header_file = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp") + "/frc/xrp/XRPOnBoardIO.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPOnBoardIO", "frc__XRPOnBoardIO.hpp"),
            ],
        ),
        struct(
            class_name = "XRPRangefinder",
            yml_file = "semiwrap/XRPRangefinder.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp"),
            header_file = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp") + "/frc/xrp/XRPRangefinder.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPRangefinder", "frc__XRPRangefinder.hpp"),
            ],
        ),
        struct(
            class_name = "XRPReflectanceSensor",
            yml_file = "semiwrap/XRPReflectanceSensor.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp"),
            header_file = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp") + "/frc/xrp/XRPReflectanceSensor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPReflectanceSensor", "frc__XRPReflectanceSensor.hpp"),
            ],
        ),
        struct(
            class_name = "XRPServo",
            yml_file = "semiwrap/XRPServo.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp"),
            header_file = resolve_include_root("//subprojects/robotpy-native-xrp", "xrp") + "/frc/xrp/XRPServo.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPServo", "frc__XRPServo.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "xrp.resolve_casters",
        caster_deps = [resolve_caster_file("wpiutil-casters"), resolve_caster_file("wpimath-casters")],
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
        trampoline_subpath = "xrp",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("ntcore"),
            local_native_libraries_helper("wpilib"),
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpinet"),
            local_native_libraries_helper("wpiutil"),
            local_native_libraries_helper("xrp"),
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

def get_generated_data_files():
    copy_extension_library(
        name = "copy_xrp",
        extension = "_xrp",
        output_directory = "xrp/",
    )

    native.filegroup(
        name = "xrp.generated_data_files",
        srcs = [
            "xrp/xrp.pc",
        ],
    )

    return [
        ":xrp.generated_data_files",
        ":copy_xrp",
        ":xrp.trampoline_hdr_files",
    ]

def libinit_files():
    return [
        "xrp/_init__xrp.py",
    ]
