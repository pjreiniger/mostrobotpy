load("@rules_semiwrap//:defs.bzl", "create_pybind_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "publish_casters", "resolve_casters", "run_header_gen")

def wpiutil_extension(entry_point, deps, DEFAULT_INCLUDE_ROOT, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    WPIUTIL_HEADER_GEN = [
        struct(
            class_name = "DataLog",
            yml_file = "semiwrap/DataLog.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/wpi/DataLog.h",
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
            class_name = "DataLogReader",
            yml_file = "semiwrap/DataLogReader.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/wpi/DataLogReader.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::log::StartRecordData", "wpi__log__StartRecordData.hpp"),
                ("wpi::log::MetadataRecordData", "wpi__log__MetadataRecordData.hpp"),
                ("wpi::log::DataLogRecord", "wpi__log__DataLogRecord.hpp"),
                ("wpi::log::DataLogReader", "wpi__log__DataLogReader.hpp"),
            ],
        ),
        struct(
            class_name = "DataLogBackgroundWriter",
            yml_file = "semiwrap/DataLogBackgroundWriter.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/wpi/DataLogBackgroundWriter.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::log::DataLogBackgroundWriter", "wpi__log__DataLogBackgroundWriter.hpp"),
            ],
        ),
        struct(
            class_name = "DataLogWriter",
            yml_file = "semiwrap/DataLogWriter.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/wpi/DataLogWriter.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::log::DataLogWriter", "wpi__log__DataLogWriter.hpp"),
            ],
        ),
        struct(
            class_name = "StackTrace",
            yml_file = "semiwrap/StackTrace.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/wpi/StackTrace.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Synchronization",
            yml_file = "semiwrap/Synchronization.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/wpi/Synchronization.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "RawFrame",
            yml_file = "semiwrap/RawFrame.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/wpi/RawFrame.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Sendable",
            yml_file = "semiwrap/Sendable.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/wpi/sendable/Sendable.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::Sendable", "wpi__Sendable.hpp"),
            ],
        ),
        struct(
            class_name = "SendableBuilder",
            yml_file = "semiwrap/SendableBuilder.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/wpi/sendable/SendableBuilder.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::SendableBuilder", "wpi__SendableBuilder.hpp"),
            ],
        ),
        struct(
            class_name = "SendableRegistry",
            yml_file = "semiwrap/SendableRegistry.yml",
            header_file = DEFAULT_INCLUDE_ROOT + "/wpi/sendable/SendableRegistry.h",
            tmpl_class_names = [],
            trampolines = [
                ("wpi::SendableRegistry", "wpi__SendableRegistry.hpp"),
            ],
        ),
        struct(
            class_name = "WPyStruct",
            yml_file = "semiwrap/WPyStruct.yml",
            header_file = "subprojects/robotpy-wpiutil/wpiutil/src/wpistruct/wpystruct_fns.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
    ]
    resolve_casters(
        name = "wpiutil.resolve_casters",
        caster_files = ["wpiutil-casters.pybind11.json"],
        casters_pkl_file = "wpiutil.casters.pkl",
        dep_file = "wpiutil.casters.d",
    )

    gen_libinit(
        name = "wpiutil.gen_lib_init",
        output_file = "wpiutil/_init__wpiutil.py",
        modules = ["native.wpiutil._init_robotpy_native_wpiutil"],
    )

    gen_pkgconf(
        name = "wpiutil.gen_pkgconf",
        libinit_py = "wpiutil._init__wpiutil",
        module_pkg_name = "wpiutil._wpiutil",
        output_file = "wpiutil.pc",
        pkg_name = "wpiutil",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpiutil.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPIUTIL_HEADER_GEN],
        libname = "_wpiutil",
        output_file = "semiwrap_init.wpiutil._wpiutil.hpp",
    )

    run_header_gen(
        name = "wpiutil",
        casters_pickle = "wpiutil.casters.pkl",
        header_gen_config = WPIUTIL_HEADER_GEN,
        include_root = DEFAULT_INCLUDE_ROOT,
        deps = header_to_dat_deps + ["wpiutil/src/wpistruct/wpystruct_fns.h"],
    )

    native.filegroup(
        name = "wpiutil.generated_files",
        srcs = [
            "wpiutil.gen_modinit_hpp.gen",
            "wpiutil.header_gen_files",
            "wpiutil.gen_pkgconf",
            "wpiutil.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpiutil",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpiutil.generated_srcs"],
        semiwrap_header = [":wpiutil.gen_modinit_hpp"],
        deps = deps + [
            ":wpiutil.tmpl_hdrs",
            ":wpiutil.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

def publish_library_casters(typecasters_srcs):
    publish_casters(
        name = "publish_casters",
        caster_name = "wpiutil-casters",
        output_json = "wpiutil-casters.pybind11.json",
        output_pc = "wpiutil-casters.pc",
        project_config = "pyproject.toml",
        typecasters_srcs = typecasters_srcs,
    )
