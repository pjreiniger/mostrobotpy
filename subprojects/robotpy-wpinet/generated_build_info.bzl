load("@rules_semiwrap//:defs.bzl", "create_pybind_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "publish_casters", "resolve_casters", "run_header_gen")

def _local_include_root(project_import, include_subpackage):
    return "$(location " + project_import + ")/site-packages/native/" + include_subpackage + "/include"


def wpinet_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    WPINET_HEADER_GEN = [
        struct(
            class_name = "PortForwarder",
            yml_file = "semiwrap/PortForwarder.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpinet:import", "wpinet"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpinet:import", "wpinet") + "/wpinet/PortForwarder.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::PortForwarder", "wpi__PortForwarder.hpp"),
            ],
        ),
        struct(
            class_name = "WebServer",
            yml_file = "semiwrap/WebServer.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpinet:import", "wpinet"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpinet:import", "wpinet") + "/wpinet/WebServer.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::WebServer", "wpi__WebServer.hpp"),
            ],
        ),
    ]
    resolve_casters(
        name = "wpinet.resolve_casters",
        caster_files = ["//subprojects/robotpy-wpiutil:generated/publish_casters/wpiutil-casters.pybind11.json"],
        casters_pkl_file = "wpinet.casters.pkl",
        dep_file = "wpinet.casters.d",
    )

    gen_libinit(
        name = "wpinet.gen_lib_init",
        output_file = "wpinet/_init__wpinet.py",
        modules = ["native.wpinet._init_robotpy_native_wpinet", "wpiutil._init__wpiutil"],
    )

    gen_pkgconf(
        name = "wpinet.gen_pkgconf",
        libinit_py = "wpinet._init__wpinet",
        module_pkg_name = "wpinet._wpinet",
        output_file = "wpinet.pc",
        pkg_name = "wpinet",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpinet.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPINET_HEADER_GEN],
        libname = "_wpinet",
        output_file = "semiwrap_init.wpinet._wpinet.hpp",
    )

    run_header_gen(
        name = "wpinet",
        casters_pickle = "wpinet.casters.pkl",
        header_gen_config = WPINET_HEADER_GEN,
        deps = header_to_dat_deps,
        header_to_dat_deps = ["//subprojects/robotpy-native-wpinet:import"],
        generation_includes = [
            _local_include_root("//subprojects/robotpy-native-wpinet:import", "wpinet"),
        ],
    )

    native.filegroup(
        name = "wpinet.generated_files",
        srcs = [
            "wpinet.gen_modinit_hpp.gen",
            "wpinet.header_gen_files",
            "wpinet.gen_pkgconf",
            "wpinet.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpinet",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpinet.generated_srcs"],
        semiwrap_header = [":wpinet.gen_modinit_hpp"],
        deps = deps + [
            ":wpinet.tmpl_hdrs",
            ":wpinet.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )
