load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")
load("@rules_semiwrap//:defs.bzl", "copy_extension_library", "create_pybind_library", "make_pyi", "robotpy_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")
load("//bazel_scripts:file_resolver_utils.bzl", "local_native_libraries_helper", "local_pybind_library", "resolve_caster_file", "resolve_include_root")

def xrp_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps = []):
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
        install_path = "xrp",
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
            local_native_libraries_helper("wpihal"),
            local_native_libraries_helper("wpilib"),
            local_native_libraries_helper("wpimath"),
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

    whl_filegroup(
        name = "xrp.wheel.trampoline_files",
        pattern = "xrp/trampolines",
        whl = ":xrp-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "xrp.wheel.trampoline_hdrs",
        hdrs = [":xrp.wheel.trampoline_files"],
        includes = ["xrp.wheel.trampoline_files/xrp"],
        tags = ["manual"],
    )

    cc_library(
        name = "xrp.wheel.headers",
        deps = [
            ":xrp.wheel.trampoline_hdrs",
            "//subprojects/robotpy-wpilib:wpilib.wheel.headers",
            "//subprojects/robotpy-wpilib:wpilib_event.wheel.headers",
            "//subprojects/robotpy-wpilib:wpilib_interfaces.wheel.headers",
            "//subprojects/robotpy-wpimath:wpimath.wheel.headers",
            "//subprojects/robotpy-wpimath:wpimath_controls.wheel.headers",
            "//subprojects/robotpy-wpimath:wpimath_geometry.wheel.headers",
            "//subprojects/robotpy-wpiutil:wpiutil.wheel.headers",
            "//subprojects/robotpy-native-xrp:xrp",
        ],
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    make_pyi(
        name = "xrp.make_pyi",
        extension_package = "xrp._xrp",
        extension_library = "copy_xrp",
        interface_files = [
            "_xrp.pyi",
        ],
        init_pkgcfgs = ["xrp/_init__xrp.py"],
        init_packages = ["xrp"],
        install_path = "xrp",
        python_deps = [
            local_pybind_library("//subprojects/pyntcore", "ntcore"),
            local_pybind_library("//subprojects/robotpy-hal", "hal"),
            local_pybind_library("//subprojects/robotpy-native-wpilib", "robotpy-native-wpilib"),
            local_pybind_library("//subprojects/robotpy-native-wpimath", "robotpy-native-wpimath"),
            local_pybind_library("//subprojects/robotpy-native-xrp", "robotpy-native-xrp"),
            local_pybind_library("//subprojects/robotpy-wpilib", "wpilib"),
            local_pybind_library("//subprojects/robotpy-wpimath", "wpimath"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ] + extra_pyi_deps,
        target_compatible_with = select({
            "//conditions:default": ["@platforms//:incompatible"],
        }),
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
        tags = ["manual"],
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

def define_pybind_library(name, version, extra_entry_points = {}):
    native.filegroup(
        name = "xrp.extra_pkg_files",
        srcs = native.glob(["xrp/**"], exclude = ["xrp/**/*.py"], allow_empty = True),
        tags = ["manual"],
    )

    native.filegroup(
        name = "pyi_files",
        srcs = select({
            "//conditions:default": [],
            # "//conditions:default": [
            #     ":xrp.make_pyi",
            # ],
        }),
        tags = ["manual"],
    )

    native.filegroup(
        name = "generated_files",
        srcs = [
            "xrp.generated_files",
        ],
        tags = ["manual"],
        visibility = ["//visibility:public"],
    )

    robotpy_library(
        name = name,
        srcs = native.glob(["xrp/**/*.py"]) + libinit_files(),
        data = get_generated_data_files() + ["xrp.extra_pkg_files", ":pyi_files"],
        imports = ["."],
        robotpy_wheel_deps = [
            local_pybind_library("//subprojects/pyntcore", "ntcore"),
            local_pybind_library("//subprojects/robotpy-hal", "hal"),
            local_pybind_library("//subprojects/robotpy-native-wpilib", "robotpy-native-wpilib"),
            local_pybind_library("//subprojects/robotpy-native-wpimath", "robotpy-native-wpimath"),
            local_pybind_library("//subprojects/robotpy-native-xrp", "robotpy-native-xrp"),
            local_pybind_library("//subprojects/robotpy-wpilib", "wpilib"),
            local_pybind_library("//subprojects/robotpy-wpimath", "wpimath"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ],
        strip_path_prefixes = ["subprojects/robotpy-xrp"],
        version = version,
        visibility = ["//visibility:public"],
        entry_points = {
            "pkg_config": [
                "xrp = xrp",
            ],
        }.update(extra_entry_points),
        package_name = "robotpy-xrp",
        package_summary = "Binary wrapper for WPILib XRP Vendor library",
        package_project_urls = None,
        package_author_email = "RobotPy Development Team <robotpy@googlegroups.com>",
        package_requires = ["wpilib==2025.3.2.2"],
    )
