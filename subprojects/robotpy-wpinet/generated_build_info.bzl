load("@rules_semiwrap//:defs.bzl", "copy_extension_library", "create_pybind_library", "robotpy_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")
load("//bazel_scripts:file_resolver_utils.bzl", "local_native_libraries_helper", "resolve_caster_file", "resolve_include_root")

def wpinet_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    WPINET_HEADER_GEN = [
        struct(
            class_name = "PortForwarder",
            yml_file = "semiwrap/PortForwarder.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpinet", "wpinet"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpinet", "wpinet") + "/wpinet/PortForwarder.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::PortForwarder", "wpi__PortForwarder.hpp"),
            ],
        ),
        struct(
            class_name = "WebServer",
            yml_file = "semiwrap/WebServer.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpinet", "wpinet"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpinet", "wpinet") + "/wpinet/WebServer.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::WebServer", "wpi__WebServer.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpinet.resolve_casters",
        caster_deps = [resolve_caster_file("wpiutil-casters")],
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
        install_path = "wpinet",
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
        trampoline_subpath = "wpinet",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("wpinet"),
            local_native_libraries_helper("wpiutil"),
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

def get_generated_data_files():
    copy_extension_library(
        name = "copy_wpinet",
        extension = "_wpinet",
        output_directory = "wpinet/",
    )

    native.filegroup(
        name = "wpinet.generated_data_files",
        srcs = [
            "wpinet/wpinet.pc",
        ],
    )

    return [
        ":wpinet.generated_data_files",
        ":copy_wpinet",
        ":wpinet.trampoline_hdr_files",
    ]

def libinit_files():
    return [
        "wpinet/_init__wpinet.py",
    ]

def define_pybind_library(
        name,
        version):
        
    native.filegroup(
        name = "wpinet.extra_pkg_files",
        srcs = native.glob(["wpinet/**"], exclude=["wpinet/**/*.py"]),
        tags = ["manual"],
    )

    robotpy_library(
        name = name,
        srcs = native.glob(["wpinet/**/*.py"]) + libinit_files(),
        data = get_generated_data_files() + ["wpinet.extra_pkg_files"],
        imports = ["."],
        robotpy_wheel_deps = [
            "//subprojects/robotpy-native-wpinet:import",
            "//subprojects/robotpy-wpiutil:import",
        ],
        strip_path_prefixes = ["subprojects/robotpy-wpinet"],
        version = version,
        entry_points = {"pkg_config": ["wpinet = wpinet"]},
        visibility = ["//visibility:public"],
        package_name = "robotpy-wpinet",
        package_summary = "Binary wrapper for FRC wpinet library",
        package_project_urls = {"Source code": "https://github.com/robotpy/mostrobotpy"},
        package_author_email = "RobotPy Development Team <robotpy@googlegroups.com>",
        package_requires = ["robotpy-native-wpinet==2025.3.2", "robotpy-wpiutil==2025.3.2.2"],
    )
