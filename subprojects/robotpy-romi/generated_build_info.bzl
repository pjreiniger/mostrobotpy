load("//bazel_scripts:pybind_rules.bzl", "create_pybind_library")
load("//bazel_scripts:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")

def romi_extension(entry_point, other_deps, DEFAULT_INCLUDE_ROOT, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    ROMI_HEADER_GEN = [
        struct(
            class_name = "OnBoardIO",
            yml_file = "semiwrap/OnBoardIO.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/frc/romi/OnBoardIO.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::OnBoardIO", "frc__OnBoardIO.hpp"),
            ],
        ),
        struct(
            class_name = "RomiGyro",
            yml_file = "semiwrap/RomiGyro.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/frc/romi/RomiGyro.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::RomiGyro", "frc__RomiGyro.hpp"),
            ],
        ),
        struct(
            class_name = "RomiMotor",
            yml_file = "semiwrap/RomiMotor.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/frc/romi/RomiMotor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::RomiMotor", "frc__RomiMotor.hpp"),
            ],
        ),
    ]
    resolve_casters(
        name = "romi.resolve_casters",
        caster_files = ["//subprojects/robotpy-wpiutil:generated/publish_casters/wpiutil-casters.pybind11.json", "//subprojects/robotpy-wpimath:generated/publish_casters/wpimath-casters.pybind11.json"],
        casters_pkl_file = "romi.casters.pkl",
        dep_file = "romi.casters.d",
    )

    gen_libinit(
        name = "romi.gen_lib_init",
        output_file = "_init__romi.py",
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
        include_root = DEFAULT_INCLUDE_ROOT,
        deps = header_to_dat_deps,
        generation_includes = [
            "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpiutil_wpiutil-cpp_headers",
            "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpilibc_wpilibc-cpp_headers",
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
    )
    create_pybind_library(
        name = "romi",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":romi.generated_srcs"],
        semiwrap_header = [":romi.gen_modinit_hpp"],
        deps = [
            ":romi.tmpl_hdrs",
            ":romi.trampoline_hdrs",
        ] + other_deps,
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )
