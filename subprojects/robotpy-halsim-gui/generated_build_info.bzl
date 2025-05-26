load("//bazel_scripts:pybind_rules.bzl", "create_pybind_library")
load("//bazel_scripts:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")

def halsim_gui_ext_extension(entry_point, deps, DEFAULT_INCLUDE_ROOT, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    HALSIM_GUI_EXT_HEADER_GEN = [
    ]
    resolve_casters(
        name = "halsim_gui_ext.resolve_casters",
        caster_files = ["//subprojects/robotpy-wpiutil:generated/publish_casters/wpiutil-casters.pybind11.json", "//subprojects/robotpy-wpimath:generated/publish_casters/wpimath-casters.pybind11.json"],
        casters_pkl_file = "halsim_gui_ext.casters.pkl",
        dep_file = "halsim_gui_ext.casters.d",
    )

    gen_libinit(
        name = "halsim_gui_ext.gen_lib_init",
        output_file = "halsim_gui/_ext/_init__halsim_gui_ext.py",
        modules = ["hal._init__wpiHal", "wpimath._init__wpimath", "ntcore._init__ntcore"],
    )

    gen_pkgconf(
        name = "halsim_gui_ext.gen_pkgconf",
        libinit_py = "halsim_gui._ext._init__halsim_gui_ext",
        module_pkg_name = "halsim_gui._ext._halsim_gui_ext",
        output_file = "halsim_gui_ext.pc",
        pkg_name = "halsim_gui_ext",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "halsim_gui_ext.gen_modinit_hpp",
        input_dats = [x.class_name for x in HALSIM_GUI_EXT_HEADER_GEN],
        libname = "_halsim_gui_ext",
        output_file = "semiwrap_init.halsim_gui._ext._halsim_gui_ext.hpp",
    )

    run_header_gen(
        name = "halsim_gui_ext",
        casters_pickle = "halsim_gui_ext.casters.pkl",
        header_gen_config = HALSIM_GUI_EXT_HEADER_GEN,
        include_root = DEFAULT_INCLUDE_ROOT,
        deps = header_to_dat_deps,
        generation_includes = [
        ],
    )

    native.filegroup(
        name = "halsim_gui_ext.generated_files",
        srcs = [
            "halsim_gui_ext.gen_modinit_hpp.gen",
            "halsim_gui_ext.header_gen_files",
            "halsim_gui_ext.gen_pkgconf",
            "halsim_gui_ext.gen_lib_init",
        ],
    )
    create_pybind_library(
        name = "halsim_gui_ext",
        entry_point = entry_point,
        extension_name = extension_name,
        # generated_srcs = [":halsim_gui_ext.generated_srcs"],
        semiwrap_header = [":halsim_gui_ext.gen_modinit_hpp"],
        deps = deps + [
            ":halsim_gui_ext.tmpl_hdrs",
            ":halsim_gui_ext.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )
