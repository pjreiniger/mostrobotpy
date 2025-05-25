load("//bazel_scripts:pybind_rules.bzl", "create_pybind_library")
load("//bazel_scripts:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")

def xrp_extension(entry_point, other_deps, DEFAULT_INCLUDE_ROOT, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    XRP_HEADER_GEN = [
        struct(
            class_name = "XRPGyro",
            yml_file = "semiwrap/XRPGyro.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/frc/xrp/XRPGyro.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPGyro", "frc__XRPGyro.hpp"),
            ],
        ),
        struct(
            class_name = "XRPMotor",
            yml_file = "semiwrap/XRPMotor.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/frc/xrp/XRPMotor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPMotor", "frc__XRPMotor.hpp"),
            ],
        ),
        struct(
            class_name = "XRPOnBoardIO",
            yml_file = "semiwrap/XRPOnBoardIO.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/frc/xrp/XRPOnBoardIO.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPOnBoardIO", "frc__XRPOnBoardIO.hpp"),
            ],
        ),
        struct(
            class_name = "XRPRangefinder",
            yml_file = "semiwrap/XRPRangefinder.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/frc/xrp/XRPRangefinder.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPRangefinder", "frc__XRPRangefinder.hpp"),
            ],
        ),
        struct(
            class_name = "XRPReflectanceSensor",
            yml_file = "semiwrap/XRPReflectanceSensor.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/frc/xrp/XRPReflectanceSensor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPReflectanceSensor", "frc__XRPReflectanceSensor.hpp"),
            ],
        ),
        struct(
            class_name = "XRPServo",
            yml_file = "semiwrap/XRPServo.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/frc/xrp/XRPServo.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XRPServo", "frc__XRPServo.hpp"),
            ],
        ),
    ]
    resolve_casters(
        name = "xrp.resolve_casters",
        caster_files = ["//subprojects/robotpy-wpiutil:generated/publish_casters/wpiutil-casters.pybind11.json", "//subprojects/robotpy-wpimath:generated/publish_casters/wpimath-casters.pybind11.json"],
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
        include_root = DEFAULT_INCLUDE_ROOT,
        deps = header_to_dat_deps,
        generation_includes = [
            "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpiutil_wpiutil-cpp_headers",
            "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpilibc_wpilibc-cpp_headers",
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
    )
    create_pybind_library(
        name = "xrp",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":xrp.generated_srcs"],
        semiwrap_header = [":xrp.gen_modinit_hpp"],
        deps = [
            ":xrp.tmpl_hdrs",
            ":xrp.trampoline_hdrs",
        ] + other_deps,
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )
