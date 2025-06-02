load("@rules_semiwrap//:defs.bzl", "create_pybind_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")

def _local_include_root(project_import, include_subpackage):
    return "$(location " + project_import + ")/site-packages/native/" + include_subpackage + "/include"

def ntcore_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    NTCORE_HEADER_GEN = [
        struct(
            class_name = "BooleanArrayTopic",
            yml_file = "semiwrap/BooleanArrayTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/BooleanArrayTopic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::BooleanArraySubscriber", "nt__BooleanArraySubscriber.hpp"),
                ("nt::BooleanArrayPublisher", "nt__BooleanArrayPublisher.hpp"),
                ("nt::BooleanArrayEntry", "nt__BooleanArrayEntry.hpp"),
                ("nt::BooleanArrayTopic", "nt__BooleanArrayTopic.hpp"),
            ],
        ),
        struct(
            class_name = "BooleanTopic",
            yml_file = "semiwrap/BooleanTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/BooleanTopic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::BooleanSubscriber", "nt__BooleanSubscriber.hpp"),
                ("nt::BooleanPublisher", "nt__BooleanPublisher.hpp"),
                ("nt::BooleanEntry", "nt__BooleanEntry.hpp"),
                ("nt::BooleanTopic", "nt__BooleanTopic.hpp"),
            ],
        ),
        struct(
            class_name = "DoubleArrayTopic",
            yml_file = "semiwrap/DoubleArrayTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/DoubleArrayTopic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::DoubleArraySubscriber", "nt__DoubleArraySubscriber.hpp"),
                ("nt::DoubleArrayPublisher", "nt__DoubleArrayPublisher.hpp"),
                ("nt::DoubleArrayEntry", "nt__DoubleArrayEntry.hpp"),
                ("nt::DoubleArrayTopic", "nt__DoubleArrayTopic.hpp"),
            ],
        ),
        struct(
            class_name = "DoubleTopic",
            yml_file = "semiwrap/DoubleTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/DoubleTopic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::DoubleSubscriber", "nt__DoubleSubscriber.hpp"),
                ("nt::DoublePublisher", "nt__DoublePublisher.hpp"),
                ("nt::DoubleEntry", "nt__DoubleEntry.hpp"),
                ("nt::DoubleTopic", "nt__DoubleTopic.hpp"),
            ],
        ),
        struct(
            class_name = "FloatArrayTopic",
            yml_file = "semiwrap/FloatArrayTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/FloatArrayTopic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::FloatArraySubscriber", "nt__FloatArraySubscriber.hpp"),
                ("nt::FloatArrayPublisher", "nt__FloatArrayPublisher.hpp"),
                ("nt::FloatArrayEntry", "nt__FloatArrayEntry.hpp"),
                ("nt::FloatArrayTopic", "nt__FloatArrayTopic.hpp"),
            ],
        ),
        struct(
            class_name = "FloatTopic",
            yml_file = "semiwrap/FloatTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/FloatTopic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::FloatSubscriber", "nt__FloatSubscriber.hpp"),
                ("nt::FloatPublisher", "nt__FloatPublisher.hpp"),
                ("nt::FloatEntry", "nt__FloatEntry.hpp"),
                ("nt::FloatTopic", "nt__FloatTopic.hpp"),
            ],
        ),
        struct(
            class_name = "GenericEntry",
            yml_file = "semiwrap/GenericEntry.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/GenericEntry.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::GenericSubscriber", "nt__GenericSubscriber.hpp"),
                ("nt::GenericPublisher", "nt__GenericPublisher.hpp"),
                ("nt::GenericEntry", "nt__GenericEntry.hpp"),
            ],
        ),
        struct(
            class_name = "IntegerArrayTopic",
            yml_file = "semiwrap/IntegerArrayTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/IntegerArrayTopic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::IntegerArraySubscriber", "nt__IntegerArraySubscriber.hpp"),
                ("nt::IntegerArrayPublisher", "nt__IntegerArrayPublisher.hpp"),
                ("nt::IntegerArrayEntry", "nt__IntegerArrayEntry.hpp"),
                ("nt::IntegerArrayTopic", "nt__IntegerArrayTopic.hpp"),
            ],
        ),
        struct(
            class_name = "IntegerTopic",
            yml_file = "semiwrap/IntegerTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/IntegerTopic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::IntegerSubscriber", "nt__IntegerSubscriber.hpp"),
                ("nt::IntegerPublisher", "nt__IntegerPublisher.hpp"),
                ("nt::IntegerEntry", "nt__IntegerEntry.hpp"),
                ("nt::IntegerTopic", "nt__IntegerTopic.hpp"),
            ],
        ),
        struct(
            class_name = "MultiSubscriber",
            yml_file = "semiwrap/MultiSubscriber.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/MultiSubscriber.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::MultiSubscriber", "nt__MultiSubscriber.hpp"),
            ],
        ),
        struct(
            class_name = "NTSendable",
            yml_file = "semiwrap/NTSendable.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/NTSendable.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::NTSendable", "nt__NTSendable.hpp"),
            ],
        ),
        struct(
            class_name = "NTSendableBuilder",
            yml_file = "semiwrap/NTSendableBuilder.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/NTSendableBuilder.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::NTSendableBuilder", "nt__NTSendableBuilder.hpp"),
            ],
        ),
        struct(
            class_name = "NetworkTable",
            yml_file = "semiwrap/NetworkTable.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/NetworkTable.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::NetworkTable", "nt__NetworkTable.hpp"),
            ],
        ),
        struct(
            class_name = "NetworkTableEntry",
            yml_file = "semiwrap/NetworkTableEntry.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/NetworkTableEntry.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::NetworkTableEntry", "nt__NetworkTableEntry.hpp"),
            ],
        ),
        struct(
            class_name = "NetworkTableInstance",
            yml_file = "semiwrap/NetworkTableInstance.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/NetworkTableInstance.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::NetworkTableInstance", "nt__NetworkTableInstance.hpp"),
            ],
        ),
        struct(
            class_name = "NetworkTableListener",
            yml_file = "semiwrap/NetworkTableListener.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/NetworkTableListener.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::NetworkTableListener", "nt__NetworkTableListener.hpp"),
                ("nt::NetworkTableListenerPoller", "nt__NetworkTableListenerPoller.hpp"),
            ],
        ),
        struct(
            class_name = "NetworkTableType",
            yml_file = "semiwrap/NetworkTableType.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/NetworkTableType.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "NetworkTableValue",
            yml_file = "semiwrap/NetworkTableValue.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/NetworkTableValue.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::Value", "nt__Value.hpp"),
            ],
        ),
        struct(
            class_name = "RawTopic",
            yml_file = "semiwrap/RawTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/RawTopic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::RawSubscriber", "nt__RawSubscriber.hpp"),
                ("nt::RawPublisher", "nt__RawPublisher.hpp"),
                ("nt::RawEntry", "nt__RawEntry.hpp"),
                ("nt::RawTopic", "nt__RawTopic.hpp"),
            ],
        ),
        struct(
            class_name = "StructTopic",
            yml_file = "semiwrap/StructTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/StructTopic.h",
            tmpl_class_names = [
                ("StructTopic_tmpl1", "StructSubscriber"),
                ("StructTopic_tmpl2", "StructPublisher"),
                ("StructTopic_tmpl3", "StructEntry"),
                ("StructTopic_tmpl4", "StructTopic"),
            ],
            trampolines = [
                ("nt::StructSubscriber", "nt__StructSubscriber.hpp"),
                ("nt::StructPublisher", "nt__StructPublisher.hpp"),
                ("nt::StructEntry", "nt__StructEntry.hpp"),
                ("nt::StructTopic", "nt__StructTopic.hpp"),
            ],
        ),
        struct(
            class_name = "StructArrayTopic",
            yml_file = "semiwrap/StructArrayTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/StructArrayTopic.h",
            tmpl_class_names = [
                ("StructArrayTopic_tmpl1", "StructArraySubscriber"),
                ("StructArrayTopic_tmpl2", "StructArrayPublisher"),
                ("StructArrayTopic_tmpl3", "StructArrayEntry"),
                ("StructArrayTopic_tmpl4", "StructArrayTopic"),
            ],
            trampolines = [
                ("nt::StructArraySubscriber", "nt__StructArraySubscriber.hpp"),
                ("nt::StructArrayPublisher", "nt__StructArrayPublisher.hpp"),
                ("nt::StructArrayEntry", "nt__StructArrayEntry.hpp"),
                ("nt::StructArrayTopic", "nt__StructArrayTopic.hpp"),
            ],
        ),
        struct(
            class_name = "StringArrayTopic",
            yml_file = "semiwrap/StringArrayTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/StringArrayTopic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::StringArraySubscriber", "nt__StringArraySubscriber.hpp"),
                ("nt::StringArrayPublisher", "nt__StringArrayPublisher.hpp"),
                ("nt::StringArrayEntry", "nt__StringArrayEntry.hpp"),
                ("nt::StringArrayTopic", "nt__StringArrayTopic.hpp"),
            ],
        ),
        struct(
            class_name = "StringTopic",
            yml_file = "semiwrap/StringTopic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/StringTopic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::StringSubscriber", "nt__StringSubscriber.hpp"),
                ("nt::StringPublisher", "nt__StringPublisher.hpp"),
                ("nt::StringEntry", "nt__StringEntry.hpp"),
                ("nt::StringTopic", "nt__StringTopic.hpp"),
            ],
        ),
        struct(
            class_name = "Topic",
            yml_file = "semiwrap/Topic.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/networktables/Topic.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::Topic", "nt__Topic.hpp"),
                ("nt::Subscriber", "nt__Subscriber.hpp"),
                ("nt::Publisher", "nt__Publisher.hpp"),
            ],
        ),
        struct(
            class_name = "ntcore_cpp",
            yml_file = "semiwrap/ntcore_cpp.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/ntcore_cpp.h",
            tmpl_class_names = [],
            trampolines = [
                ("nt::EventFlags", "nt__EventFlags.hpp"),
                ("nt::TopicInfo", "nt__TopicInfo.hpp"),
                ("nt::ConnectionInfo", "nt__ConnectionInfo.hpp"),
                ("nt::ValueEventData", "nt__ValueEventData.hpp"),
                ("nt::LogMessage", "nt__LogMessage.hpp"),
                ("nt::TimeSyncEventData", "nt__TimeSyncEventData.hpp"),
                ("nt::Event", "nt__Event.hpp"),
                ("nt::PubSubOptions", "nt__PubSubOptions.hpp"),
                ("nt::meta::SubscriberOptions", "nt__meta__SubscriberOptions.hpp"),
                ("nt::meta::TopicPublisher", "nt__meta__TopicPublisher.hpp"),
                ("nt::meta::TopicSubscriber", "nt__meta__TopicSubscriber.hpp"),
                ("nt::meta::ClientPublisher", "nt__meta__ClientPublisher.hpp"),
                ("nt::meta::ClientSubscriber", "nt__meta__ClientSubscriber.hpp"),
                ("nt::meta::Client", "nt__meta__Client.hpp"),
            ],
        ),
        struct(
            class_name = "ntcore_cpp_types",
            yml_file = "semiwrap/ntcore_cpp_types.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            header_file = _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore") + "/ntcore_cpp_types.h",
            tmpl_class_names = [
                ("ntcore_cpp_types_tmpl1", "TimestampedBoolean"),
                ("ntcore_cpp_types_tmpl2", "TimestampedInteger"),
                ("ntcore_cpp_types_tmpl3", "TimestampedFloat"),
                ("ntcore_cpp_types_tmpl4", "TimestampedDouble"),
                ("ntcore_cpp_types_tmpl5", "TimestampedString"),
                ("ntcore_cpp_types_tmpl6", "TimestampedRaw"),
                ("ntcore_cpp_types_tmpl7", "TimestampedBooleanArray"),
                ("ntcore_cpp_types_tmpl8", "TimestampedIntegerArray"),
                ("ntcore_cpp_types_tmpl9", "TimestampedFloatArray"),
                ("ntcore_cpp_types_tmpl10", "TimestampedDoubleArray"),
                ("ntcore_cpp_types_tmpl11", "TimestampedStringArray"),
                ("ntcore_cpp_types_tmpl12", "TimestampedStruct"),
                ("ntcore_cpp_types_tmpl13", "TimestampedStructArray"),
            ],
            trampolines = [
                ("nt::Timestamped", "nt__Timestamped.hpp"),
            ],
        ),
    ]
    resolve_casters(
        name = "ntcore.resolve_casters",
        caster_files = ["//subprojects/robotpy-wpiutil:generated/publish_casters/wpiutil-casters.pybind11.json"],
        casters_pkl_file = "ntcore.casters.pkl",
        dep_file = "ntcore.casters.d",
    )

    gen_libinit(
        name = "ntcore.gen_lib_init",
        output_file = "ntcore/_init__ntcore.py",
        modules = ["native.ntcore._init_robotpy_native_ntcore", "wpiutil._init__wpiutil", "wpinet._init__wpinet"],
    )

    gen_pkgconf(
        name = "ntcore.gen_pkgconf",
        libinit_py = "ntcore._init__ntcore",
        module_pkg_name = "ntcore._ntcore",
        output_file = "ntcore.pc",
        pkg_name = "ntcore",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "ntcore.gen_modinit_hpp",
        input_dats = [x.class_name for x in NTCORE_HEADER_GEN],
        libname = "_ntcore",
        output_file = "semiwrap_init.ntcore._ntcore.hpp",
    )

    run_header_gen(
        name = "ntcore",
        casters_pickle = "ntcore.casters.pkl",
        header_gen_config = NTCORE_HEADER_GEN,
        deps = header_to_dat_deps,
        local_native_libraries = [
            ("//subprojects/robotpy-native-ntcore:import", "ntcore"),
            ("//subprojects/robotpy-native-wpinet:import", "wpinet"),
            ("//subprojects/robotpy-native-wpiutil:import", "wpiutil"),
        ],
        # header_to_dat_deps = ["//subprojects/robotpy-native-ntcore:import", "//subprojects/robotpy-native-wpiutil:import", "//subprojects/robotpy-native-wpinet:import"],
        # generation_includes = [
        #     _local_include_root("//subprojects/robotpy-native-ntcore:import", "ntcore"),
        #     _local_include_root("//subprojects/robotpy-native-wpinet:import", "wpinet"),
        #     _local_include_root("//subprojects/robotpy-native-wpiutil:import", "wpiutil"),
        # ],
    )

    native.filegroup(
        name = "ntcore.generated_files",
        srcs = [
            "ntcore.gen_modinit_hpp.gen",
            "ntcore.header_gen_files",
            "ntcore.gen_pkgconf",
            "ntcore.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "ntcore",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":ntcore.generated_srcs"],
        semiwrap_header = [":ntcore.gen_modinit_hpp"],
        deps = deps + [
            ":ntcore.tmpl_hdrs",
            ":ntcore.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )
