load("@rules_semiwrap//:defs.bzl", "copy_extension_library", "create_pybind_library", "make_pyi", "robotpy_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")
load("//bazel_scripts:file_resolver_utils.bzl", "local_native_libraries_helper", "resolve_caster_file", "resolve_include_root")

def romi_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps=[]):
    ROMI_HEADER_GEN = [
        struct(
            class_name = "OnBoardIO",
            yml_file = "semiwrap/OnBoardIO.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-romi", "romi"),
            header_file = resolve_include_root("//subprojects/robotpy-native-romi", "romi") + "/frc/romi/OnBoardIO.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::OnBoardIO", "frc__OnBoardIO.hpp"),
            ],
        ),
        struct(
            class_name = "RomiGyro",
            yml_file = "semiwrap/RomiGyro.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-romi", "romi"),
            header_file = resolve_include_root("//subprojects/robotpy-native-romi", "romi") + "/frc/romi/RomiGyro.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::RomiGyro", "frc__RomiGyro.hpp"),
            ],
        ),
        struct(
            class_name = "RomiMotor",
            yml_file = "semiwrap/RomiMotor.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-romi", "romi"),
            header_file = resolve_include_root("//subprojects/robotpy-native-romi", "romi") + "/frc/romi/RomiMotor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::RomiMotor", "frc__RomiMotor.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "romi.resolve_casters",
        caster_deps = [resolve_caster_file("wpiutil-casters"), resolve_caster_file("wpimath-casters")],
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
        install_path = "romi",
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
        trampoline_subpath = "romi",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("ntcore"),
            local_native_libraries_helper("romi"),
            local_native_libraries_helper("wpihal"),
            local_native_libraries_helper("wpilib"),
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpiutil"),
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

    make_pyi(
        name = "romi.make_pyi",
        extension_package = "romi._romi",
        extension_library = "copy_romi",
        interface_files = [
            "_romi.pyi",
        ],
        init_pkgcfgs = ["romi/_init__romi.py"],
        init_packages = ["romi"],
        install_path = "romi",
        python_deps = [
            "//subprojects/pyntcore:import",
            "//subprojects/robotpy-hal:import",
            "//subprojects/robotpy-native-romi:import",
            "//subprojects/robotpy-native-wpilib:import",
            "//subprojects/robotpy-native-wpimath:import",
            "//subprojects/robotpy-wpilib:import",
            "//subprojects/robotpy-wpimath:import",
            "//subprojects/robotpy-wpiutil:import",
        ] + extra_pyi_deps,
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
        ":romi.trampoline_hdr_files",
    ]

def libinit_files():
    return [
        "romi/_init__romi.py",
    ]

def define_pybind_library(name, version, extra_entry_points = {}):
    native.filegroup(
        name = "romi.extra_pkg_files",
        srcs = native.glob(["romi/**"], exclude = ["romi/**/*.py"], allow_empty=True),
        tags = ["manual"],
    )

    native.filegroup(
        name = "pyi_files",
        srcs = [
            ":romi.make_pyi",
        ],
    )

    robotpy_library(
        name = name,
        srcs = native.glob(["romi/**/*.py"]) + libinit_files(),
        data = get_generated_data_files() + ["romi.extra_pkg_files", ":pyi_files"],
        imports = ["."],
        robotpy_wheel_deps = [
            "//subprojects/pyntcore:import",
            "//subprojects/robotpy-hal:import",
            "//subprojects/robotpy-native-romi:import",
            "//subprojects/robotpy-native-wpilib:import",
            "//subprojects/robotpy-native-wpimath:import",
            "//subprojects/robotpy-wpilib:import",
            "//subprojects/robotpy-wpimath:import",
            "//subprojects/robotpy-wpiutil:import",
        ],
        strip_path_prefixes = ["subprojects/robotpy-romi"],
        version = version,
        visibility = ["//visibility:public"],
        entry_points = {
            "pkg_config": [
                "romi = romi",
            ],
        }.update(extra_entry_points),
        package_name = "robotpy-romi",
        package_summary = "Binary wrapper for WPILib Romi Vendor library",
        package_project_urls = {"Source code": "https://github.com/robotpy/mostrobotpy"},
        package_author_email = "RobotPy Development Team <robotpy@googlegroups.com>",
        package_requires = ["wpilib==2027.0.0a1.dev0"],
    )
