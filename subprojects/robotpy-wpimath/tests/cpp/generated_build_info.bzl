load("//bazel_scripts:pybind_rules.bzl", "create_pybind_library")
load("//bazel_scripts:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")

def wpimath_test_extension(entry_point, other_deps, DEFAULT_INCLUDE_ROOT, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    WPIMATH_TEST_HEADER_GEN = [
        struct(
            class_name = "module",
            yml_file = "semiwrap/module.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/module.h",
            tmpl_class_names = [],
            trampolines = [
                ("SomeClass", "__SomeClass.hpp"),
            ],
        ),
    ]
    resolve_casters(
        name = "wpimath_test.resolve_casters",
        caster_files = ["//subprojects/robotpy-wpimath:generated/publish_casters/wpimath-casters.pybind11.json", "//subprojects/robotpy-wpiutil:generated/publish_casters/wpiutil-casters.pybind11.json"],
        casters_pkl_file = "wpimath_test.casters.pkl",
        dep_file = "wpimath_test.casters.d",
    )

    gen_libinit(
        name = "wpimath_test.gen_lib_init",
        output_file = "_init__wpimath_test.py",
        modules = ["wpimath._init__wpimath"],
    )

    gen_pkgconf(
        name = "wpimath_test.gen_pkgconf",
        libinit_py = "wpimath_test._init__wpimath_test",
        module_pkg_name = "wpimath_test._wpimath_test",
        output_file = "wpimath_test.pc",
        pkg_name = "wpimath_test",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpimath_test.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPIMATH_TEST_HEADER_GEN],
        libname = "_wpimath_test",
        output_file = "semiwrap_init.wpimath_test._wpimath_test.hpp",
    )

    run_header_gen(
        name = "wpimath_test",
        casters_pickle = "wpimath_test.casters.pkl",
        header_gen_config = WPIMATH_TEST_HEADER_GEN,
        include_root = DEFAULT_INCLUDE_ROOT,
        deps = header_to_dat_deps,
    )

    native.filegroup(
        name = "wpimath_test.generated_files",
        srcs = [
            "wpimath_test.gen_modinit_hpp.gen",
            "wpimath_test.header_gen_files",
            "wpimath_test.gen_pkgconf",
            "wpimath_test.gen_lib_init",
        ],
    )
    create_pybind_library(
        name = "wpimath_test",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpimath_test.generated_srcs"],
        semiwrap_header = [":wpimath_test.gen_modinit_hpp"],
        deps = [
            ":wpimath_test.tmpl_hdrs",
            ":wpimath_test.trampoline_hdrs",
        ] + other_deps,
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )
