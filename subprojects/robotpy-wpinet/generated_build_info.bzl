load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")
load("@rules_semiwrap//:defs.bzl", "copy_extension_library", "create_pybind_library", "make_pyi", "robotpy_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")
load("//bazel_scripts:file_resolver_utils.bzl", "local_native_libraries_helper", "local_pybind_library", "resolve_caster_file", "resolve_include_root")

def wpinet_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps = []):
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

    whl_filegroup(
        name = "wpinet.wheel.trampoline_files",
        pattern = "wpinet/trampolines",
        whl = ":wpinet-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpinet.wheel.trampoline_hdrs",
        hdrs = [":wpinet.wheel.trampoline_files"],
        includes = ["wpinet.wheel.trampoline_files/wpinet"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpinet.wheel.headers",
        deps = [
            ":wpinet.wheel.trampoline_hdrs",
            "//subprojects/robotpy-native-wpinet:wpinet",
            "//subprojects/robotpy-native-wpiutil:wpiutil",
            "//subprojects/robotpy-wpiutil:wpiutil.wheel.headers",
        ],
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    make_pyi(
        name = "wpinet.make_pyi",
        extension_package = "wpinet._wpinet",
        extension_library = "copy_wpinet",
        interface_files = [
            "_wpinet.pyi",
        ],
        init_pkgcfgs = ["wpinet/_init__wpinet.py"],
        init_packages = ["wpinet"],
        install_path = "wpinet",
        python_deps = [
            local_pybind_library("//subprojects/robotpy-native-wpinet", "robotpy-native-wpinet"),
            local_pybind_library("//subprojects/robotpy-native-wpiutil", "robotpy-native-wpiutil"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ] + extra_pyi_deps,
        target_compatible_with = select({
            "//conditions:default": ["@platforms//:incompatible"],
        }),
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
        tags = ["manual"],
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

def define_pybind_library(name, version, extra_entry_points = {}):
    native.filegroup(
        name = "wpinet.extra_pkg_files",
        srcs = native.glob(["wpinet/**"], exclude = ["wpinet/**/*.py"], allow_empty = True),
        tags = ["manual"],
    )

    native.filegroup(
        name = "pyi_files",
        srcs = select({
            "//conditions:default": [],
            # "//conditions:default": [
            #     ":wpinet.make_pyi",
            # ],
        }),
        tags = ["manual"],
    )

    native.filegroup(
        name = "generated_files",
        srcs = [
            "wpinet.generated_files",
        ],
        tags = ["manual"],
        visibility = ["//visibility:public"],
    )

    robotpy_library(
        name = name,
        srcs = native.glob(["wpinet/**/*.py"]) + libinit_files(),
        data = get_generated_data_files() + ["wpinet.extra_pkg_files", ":pyi_files"],
        imports = ["."],
        robotpy_wheel_deps = [
            local_pybind_library("//subprojects/robotpy-native-wpinet", "robotpy-native-wpinet"),
            local_pybind_library("//subprojects/robotpy-native-wpiutil", "robotpy-native-wpiutil"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ],
        strip_path_prefixes = ["subprojects/robotpy-wpinet"],
        version = version,
        visibility = ["//visibility:public"],
        entry_points = {
            "pkg_config": [
                "wpinet = wpinet",
            ],
        }.update(extra_entry_points),
        package_name = "robotpy-wpinet",
        package_summary = "Binary wrapper for FRC wpinet library",
        package_project_urls = {"Source code": "https://github.com/robotpy/mostrobotpy"},
        package_author_email = "RobotPy Development Team <robotpy@googlegroups.com>",
        package_requires = ["robotpy-native-wpinet==2025.3.2", "robotpy-wpiutil==2025.3.2.2"],
    )
