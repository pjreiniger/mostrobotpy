load("@rules_semiwrap//:defs.bzl", "copy_extension_library", "create_pybind_library", "make_pyi", "robotpy_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")
load("//bazel_scripts:file_resolver_utils.bzl", "local_native_libraries_helper", "resolve_caster_file", "resolve_include_root")

def wpilog_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps=[]):
    WPILOG_HEADER_GEN = [
        struct(
            class_name = "DataLog",
            yml_file = "semiwrap/DataLog.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-datalog", "datalog"),
            header_file = resolve_include_root("//subprojects/robotpy-native-datalog", "datalog") + "/wpi/datalog/DataLog.h",
            tmpl_class_names = [
                ("DataLog_tmpl1", "StructLogEntry"),
                ("DataLog_tmpl2", "StructArrayLogEntry"),
                ("DataLog_tmpl3", "_RawLogEntryImpl"),
                ("DataLog_tmpl4", "_BooleanLogEntryImpl"),
                ("DataLog_tmpl5", "_IntegerLogEntryImpl"),
                ("DataLog_tmpl6", "_FloatLogEntryImpl"),
                ("DataLog_tmpl7", "_DoubleLogEntryImpl"),
                ("DataLog_tmpl8", "_StringLogEntryImpl"),
                ("DataLog_tmpl9", "_BooleanArrayLogEntryImpl"),
                ("DataLog_tmpl10", "_IntegerArrayLogEntryImpl"),
                ("DataLog_tmpl11", "_FloatArrayLogEntryImpl"),
                ("DataLog_tmpl12", "_DoubleArrayLogEntryImpl"),
                ("DataLog_tmpl13", "_StringArrayLogEntryImpl"),
            ],
            trampolines = [
                ("wpi::log::DataLog", "wpi__log__DataLog.hpp"),
                ("wpi::log::DataLogEntry", "wpi__log__DataLogEntry.hpp"),
                ("wpi::log::DataLogValueEntryImpl", "wpi__log__DataLogValueEntryImpl.hpp"),
                ("wpi::log::RawLogEntry", "wpi__log__RawLogEntry.hpp"),
                ("wpi::log::BooleanLogEntry", "wpi__log__BooleanLogEntry.hpp"),
                ("wpi::log::IntegerLogEntry", "wpi__log__IntegerLogEntry.hpp"),
                ("wpi::log::FloatLogEntry", "wpi__log__FloatLogEntry.hpp"),
                ("wpi::log::DoubleLogEntry", "wpi__log__DoubleLogEntry.hpp"),
                ("wpi::log::StringLogEntry", "wpi__log__StringLogEntry.hpp"),
                ("wpi::log::BooleanArrayLogEntry", "wpi__log__BooleanArrayLogEntry.hpp"),
                ("wpi::log::IntegerArrayLogEntry", "wpi__log__IntegerArrayLogEntry.hpp"),
                ("wpi::log::FloatArrayLogEntry", "wpi__log__FloatArrayLogEntry.hpp"),
                ("wpi::log::DoubleArrayLogEntry", "wpi__log__DoubleArrayLogEntry.hpp"),
                ("wpi::log::StringArrayLogEntry", "wpi__log__StringArrayLogEntry.hpp"),
                ("wpi::log::StructLogEntry", "wpi__log__StructLogEntry.hpp"),
                ("wpi::log::StructArrayLogEntry", "wpi__log__StructArrayLogEntry.hpp"),
            ],
        ),
        struct(
            class_name = "DataLogBackgroundWriter",
            yml_file = "semiwrap/DataLogBackgroundWriter.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-datalog", "datalog"),
            header_file = resolve_include_root("//subprojects/robotpy-native-datalog", "datalog") + "/wpi/datalog/DataLogBackgroundWriter.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::log::DataLogBackgroundWriter", "wpi__log__DataLogBackgroundWriter.hpp"),
            ],
        ),
        struct(
            class_name = "DataLogReader",
            yml_file = "semiwrap/DataLogReader.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-datalog", "datalog"),
            header_file = resolve_include_root("//subprojects/robotpy-native-datalog", "datalog") + "/wpi/datalog/DataLogReader.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::log::StartRecordData", "wpi__log__StartRecordData.hpp"),
                ("wpi::log::MetadataRecordData", "wpi__log__MetadataRecordData.hpp"),
                ("wpi::log::DataLogRecord", "wpi__log__DataLogRecord.hpp"),
                ("wpi::log::DataLogReader", "wpi__log__DataLogReader.hpp"),
            ],
        ),
        struct(
            class_name = "DataLogWriter",
            yml_file = "semiwrap/DataLogWriter.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-datalog", "datalog"),
            header_file = resolve_include_root("//subprojects/robotpy-native-datalog", "datalog") + "/wpi/datalog/DataLogWriter.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::log::DataLogWriter", "wpi__log__DataLogWriter.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpilog.resolve_casters",
        caster_deps = [resolve_caster_file("wpiutil-casters")],
        casters_pkl_file = "wpilog.casters.pkl",
        dep_file = "wpilog.casters.d",
    )

    gen_libinit(
        name = "wpilog.gen_lib_init",
        output_file = "wpilog/_init__wpilog.py",
        modules = ["native.datalog._init_robotpy_native_datalog", "wpiutil._init__wpiutil"],
    )

    gen_pkgconf(
        name = "wpilog.gen_pkgconf",
        libinit_py = "wpilog._init__wpilog",
        module_pkg_name = "wpilog._wpilog",
        output_file = "wpilog.pc",
        pkg_name = "wpilog",
        install_path = "wpilog",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpilog.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPILOG_HEADER_GEN],
        libname = "_wpilog",
        output_file = "semiwrap_init.wpilog._wpilog.hpp",
    )

    run_header_gen(
        name = "wpilog",
        casters_pickle = "wpilog.casters.pkl",
        header_gen_config = WPILOG_HEADER_GEN,
        trampoline_subpath = "wpilog",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("datalog"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpilog.generated_files",
        srcs = [
            "wpilog.gen_modinit_hpp.gen",
            "wpilog.header_gen_files",
            "wpilog.gen_pkgconf",
            "wpilog.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpilog",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpilog.generated_srcs"],
        semiwrap_header = [":wpilog.gen_modinit_hpp"],
        deps = deps + [
            ":wpilog.tmpl_hdrs",
            ":wpilog.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )


    # make_pyi(
    #     name = "wpilog.make_pyi",
    #     extension_package = "wpilog._wpilog",
    #     extension_library = "copy_wpilog",
    #     interface_files = [
    #         "_wpilog.pyi",
    #     ],
    #     init_pkgcfgs = ["wpilog/_init__wpilog.py"],
    #     init_packages = ["wpilog"],
    #     install_path = "wpilog",
    #     python_deps = [
    #         "//subprojects/robotpy-native-datalog:import",
    #         "//subprojects/robotpy-native-wpiutil:import",
    #         "//subprojects/robotpy-wpiutil:import",
    #     ] + extra_pyi_deps,
    # )

def get_generated_data_files():
    copy_extension_library(
        name = "copy_wpilog",
        extension = "_wpilog",
        output_directory = "wpilog/",
    )

    native.filegroup(
        name = "wpilog.generated_data_files",
        srcs = [
            "wpilog/wpilog.pc",
        ],
    )

    return [
        ":wpilog.generated_data_files",
        ":copy_wpilog",
        ":wpilog.trampoline_hdr_files",
    ]

def libinit_files():
    return [
        "wpilog/_init__wpilog.py",
    ]

def define_pybind_library(name, version, extra_entry_points = {}):
    native.filegroup(
        name = "wpilog.extra_pkg_files",
        srcs = native.glob(["wpilog/**"], exclude = ["wpilog/**/*.py"], allow_empty=True),
        tags = ["manual"],
    )

    # native.filegroup(
    #     name = "pyi_files",
    #     srcs = [
    #         ":wpilog.make_pyi",
    #     ],
    # )

    robotpy_library(
        name = name,
        srcs = native.glob(["wpilog/**/*.py"]) + libinit_files(),
        data = get_generated_data_files() + ["wpilog.extra_pkg_files"],
        imports = ["."],
        robotpy_wheel_deps = [
            "//subprojects/robotpy-native-datalog:import",
            "//subprojects/robotpy-native-wpiutil:import",
            "//subprojects/robotpy-wpiutil:import",
        ],
        strip_path_prefixes = ["subprojects/robotpy-wpilog"],
        version = version,
        visibility = ["//visibility:public"],
        entry_points = {
            "pkg_config": [
                "wpilog = wpilog",
            ],
        }.update(extra_entry_points),
        package_name = "robotpy-wpilog",
        package_summary = "Binary wrapper for FRC wpilog library",
        package_project_urls = {"Source code": "https://github.com/robotpy/mostrobotpy"},
        package_author_email = "RobotPy Development Team <robotpy@googlegroups.com>",
        package_requires = ["robotpy-native-datalog==2027.0.0a1.dev0", "robotpy-wpiutil==2027.0.0a1.dev0"],
    )
