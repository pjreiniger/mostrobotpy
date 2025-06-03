load("@rules_semiwrap//:defs.bzl", "copy_extension_library", "create_pybind_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")

def _local_include_root(project_import, include_subpackage):
    return "$(location " + project_import + ")/site-packages/native/" + include_subpackage + "/include"

def apriltag_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    APRILTAG_HEADER_GEN = [
        struct(
            class_name = "AprilTag",
            yml_file = "semiwrap/AprilTag.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag"),
            header_file = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag") + "/frc/apriltag/AprilTag.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AprilTag", "frc__AprilTag.hpp"),
            ],
        ),
        struct(
            class_name = "AprilTagDetection",
            yml_file = "semiwrap/AprilTagDetection.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag"),
            header_file = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag") + "/frc/apriltag/AprilTagDetection.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AprilTagDetection", "frc__AprilTagDetection.hpp"),
                ("frc::AprilTagDetection::Point", "frc__AprilTagDetection__Point.hpp"),
            ],
        ),
        struct(
            class_name = "AprilTagDetector",
            yml_file = "semiwrap/AprilTagDetector.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag"),
            header_file = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag") + "/frc/apriltag/AprilTagDetector.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AprilTagDetector", "frc__AprilTagDetector.hpp"),
                ("frc::AprilTagDetector::Config", "frc__AprilTagDetector__Config.hpp"),
                ("frc::AprilTagDetector::QuadThresholdParameters", "frc__AprilTagDetector__QuadThresholdParameters.hpp"),
                ("frc::AprilTagDetector::Results", "frc__AprilTagDetector__Results.hpp"),
            ],
        ),
        struct(
            class_name = "AprilTagFieldLayout",
            yml_file = "semiwrap/AprilTagFieldLayout.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag"),
            header_file = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag") + "/frc/apriltag/AprilTagFieldLayout.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AprilTagFieldLayout", "frc__AprilTagFieldLayout.hpp"),
            ],
        ),
        struct(
            class_name = "AprilTagFields",
            yml_file = "semiwrap/AprilTagFields.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag"),
            header_file = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag") + "/frc/apriltag/AprilTagFields.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AprilTagPoseEstimate",
            yml_file = "semiwrap/AprilTagPoseEstimate.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag"),
            header_file = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag") + "/frc/apriltag/AprilTagPoseEstimate.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AprilTagPoseEstimate", "frc__AprilTagPoseEstimate.hpp"),
            ],
        ),
        struct(
            class_name = "AprilTagPoseEstimator",
            yml_file = "semiwrap/AprilTagPoseEstimator.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag"),
            header_file = _local_include_root("//subprojects/robotpy-native-apriltag:import", "apriltag") + "/frc/apriltag/AprilTagPoseEstimator.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AprilTagPoseEstimator", "frc__AprilTagPoseEstimator.hpp"),
                ("frc::AprilTagPoseEstimator::Config", "frc__AprilTagPoseEstimator__Config.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "apriltag.resolve_casters",
        caster_files = [
            "$(location //subprojects/robotpy-wpiutil:import)" + "/site-packages/wpiutil/wpiutil-casters.pybind11.json",
            "$(location //subprojects/robotpy-wpimath:import)" + "/site-packages/wpimath/wpimath-casters.pybind11.json",
        ],
        caster_deps = ["//subprojects/robotpy-wpiutil:import", "//subprojects/robotpy-wpimath:import"],
        # caster_files = ["//subprojects/robotpy-wpimath:generated/publish_casters/wpimath-casters.pybind11.json", "//subprojects/robotpy-wpiutil:generated/publish_casters/wpiutil-casters.pybind11.json"],
        casters_pkl_file = "apriltag.casters.pkl",
        dep_file = "apriltag.casters.d",
    )

    gen_libinit(
        name = "apriltag.gen_lib_init",
        output_file = "robotpy_apriltag/_init__apriltag.py",
        modules = ["native.apriltag._init_robotpy_native_apriltag", "wpiutil._init__wpiutil", "wpimath._init__wpimath"],
    )

    gen_pkgconf(
        name = "apriltag.gen_pkgconf",
        libinit_py = "robotpy_apriltag._init__apriltag",
        module_pkg_name = "robotpy_apriltag._apriltag",
        output_file = "apriltag.pc",
        pkg_name = "apriltag",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "apriltag.gen_modinit_hpp",
        input_dats = [x.class_name for x in APRILTAG_HEADER_GEN],
        libname = "_apriltag",
        output_file = "semiwrap_init.robotpy_apriltag._apriltag.hpp",
    )

    run_header_gen(
        name = "apriltag",
        casters_pickle = "apriltag.casters.pkl",
        header_gen_config = APRILTAG_HEADER_GEN,
        deps = header_to_dat_deps,
        local_native_libraries = [
            ("//subprojects/robotpy-native-apriltag:import", "apriltag"),
            ("//subprojects/robotpy-native-wpimath:import", "wpimath"),
            ("//subprojects/robotpy-native-wpiutil:import", "wpiutil"),
        ],
    )

    native.filegroup(
        name = "apriltag.generated_files",
        srcs = [
            "apriltag.gen_modinit_hpp.gen",
            "apriltag.header_gen_files",
            "apriltag.gen_pkgconf",
            "apriltag.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "apriltag",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":apriltag.generated_srcs"],
        semiwrap_header = [":apriltag.gen_modinit_hpp"],
        deps = deps + [
            ":apriltag.tmpl_hdrs",
            ":apriltag.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

def get_generated_data_files():
    copy_extension_library(
        name = "copy_apriltag",
        extension = "_apriltag",
        output_directory = "robotpy_apriltag/",
    )

    native.filegroup(
        name = "apriltag.generated_data_files",
        srcs = [
            "apriltag/apriltag.pc",
        ],
    )

    return [
        ":apriltag.generated_data_files",
        ":copy_apriltag",
    ]

def libinit_files():
    return [
        "robotpy_apriltag/_init__apriltag.py",
    ]
