load("@rules_semiwrap//:defs.bzl", "create_pybind_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "publish_casters", "resolve_casters", "run_header_gen")

def cscore_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    CSCORE_HEADER_GEN = [
        struct(
            class_name = "CameraServer",
            yml_file = "semiwrap/CameraServer.yml",
            header_root = "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cameraserver_cameraserver-cpp_headers",
            header_file = "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cameraserver_cameraserver-cpp_headers/cameraserver/CameraServer.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::CameraServer", "frc__CameraServer.hpp"),
            ],
        ),
        struct(
            class_name = "cscore_cpp",
            yml_file = "semiwrap/cscore_cpp.yml",
            header_root = "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cscore_cscore-cpp_headers",
            header_file = "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cscore_cscore-cpp_headers/cscore_cpp.h",
            tmpl_class_names = [],
            trampolines = [
                ("cs::UsbCameraInfo", "cs__UsbCameraInfo.hpp"),
                ("cs::VideoMode", "cs__VideoMode.hpp"),
                ("cs::RawEvent", "cs__RawEvent.hpp"),
            ],
        ),
        struct(
            class_name = "cscore_oo",
            yml_file = "semiwrap/cscore_oo.yml",
            header_root = "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cscore_cscore-cpp_headers",
            header_file = "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cscore_cscore-cpp_headers/cscore_oo.h",
            tmpl_class_names = [],
            trampolines = [
                ("cs::VideoProperty", "cs__VideoProperty.hpp"),
                ("cs::VideoSource", "cs__VideoSource.hpp"),
                ("cs::VideoCamera", "cs__VideoCamera.hpp"),
                ("cs::UsbCamera", "cs__UsbCamera.hpp"),
                ("cs::HttpCamera", "cs__HttpCamera.hpp"),
                ("cs::AxisCamera", "cs__AxisCamera.hpp"),
                ("cs::ImageSource", "cs__ImageSource.hpp"),
                ("cs::VideoSink", "cs__VideoSink.hpp"),
                ("cs::MjpegServer", "cs__MjpegServer.hpp"),
                ("cs::ImageSink", "cs__ImageSink.hpp"),
                ("cs::VideoEvent", "cs__VideoEvent.hpp"),
                ("cs::VideoListener", "cs__VideoListener.hpp"),
            ],
        ),
        struct(
            class_name = "cscore_cv",
            yml_file = "semiwrap/cscore_cv.yml",
            header_root = "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cscore_cscore-cpp_headers",
            header_file = "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cscore_cscore-cpp_headers/cscore_cv.h",
            tmpl_class_names = [],
            trampolines = [
                ("cs::CvSource", "cs__CvSource.hpp"),
                ("cs::CvSink", "cs__CvSink.hpp"),
            ],
        ),
        struct(
            class_name = "cscore_runloop",
            yml_file = "semiwrap/cscore_runloop.yml",
            header_root = "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cscore_cscore-cpp_headers",
            header_file = "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cscore_cscore-cpp_headers/cscore_runloop.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
    ]
    resolve_casters(
        name = "cscore.resolve_casters",
        caster_files = [
            "$(location //subprojects/robotpy-wpiutil:import)" + "/site-packages/wpiutil/wpiutil-casters.pybind11.json",
            ":cscore/cscore-casters.pybind11.json",
        ],
        caster_deps = ["//subprojects/robotpy-wpiutil:import"],
        casters_pkl_file = "cscore.casters.pkl",
        dep_file = "cscore.casters.d",
    )

    gen_libinit(
        name = "cscore.gen_lib_init",
        output_file = "cscore/_init__cscore.py",
        modules = ["wpiutil._init__wpiutil", "wpinet._init__wpinet", "ntcore._init__ntcore"],
    )

    gen_pkgconf(
        name = "cscore.gen_pkgconf",
        libinit_py = "cscore._init__cscore",
        module_pkg_name = "cscore._cscore",
        output_file = "cscore.pc",
        pkg_name = "cscore",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "cscore.gen_modinit_hpp",
        input_dats = [x.class_name for x in CSCORE_HEADER_GEN],
        libname = "_cscore",
        output_file = "semiwrap_init.cscore._cscore.hpp",
    )

    run_header_gen(
        name = "cscore",
        casters_pickle = "cscore.casters.pkl",
        header_gen_config = CSCORE_HEADER_GEN,
        deps = header_to_dat_deps,
        generation_includes = [
            "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cscore_cscore-cpp_headers",
            "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_cameraserver_cameraserver-cpp_headers",
            "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_ntcore_ntcore-cpp_headers",
            "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpinet_wpinet-cpp_headers",
            "external/bzlmodrio-allwpilib~~setup_bzlmodrio_allwpilib_cpp_dependencies~bazelrio_edu_wpi_first_wpiutil_wpiutil-cpp_headers",
            "external/bzlmodrio-opencv~~setup_bzlmodrio_opencv_cpp_dependencies~bazelrio_edu_wpi_first_thirdparty_frc_opencv_opencv-cpp_headers",
        ],
    )

    native.filegroup(
        name = "cscore.generated_files",
        srcs = [
            "cscore.gen_modinit_hpp.gen",
            "cscore.header_gen_files",
            "cscore.gen_pkgconf",
            "cscore.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "cscore",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":cscore.generated_srcs"],
        semiwrap_header = [":cscore.gen_modinit_hpp"],
        deps = deps + [
            ":cscore.tmpl_hdrs",
            ":cscore.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

def publish_library_casters(typecasters_srcs):
    publish_casters(
        name = "publish_casters",
        caster_name = "cscore-casters",
        output_json = "cscore/cscore-casters.pybind11.json",
        output_pc = "cscore/cscore-casters.pc",
        project_config = "pyproject.toml",
        typecasters_srcs = typecasters_srcs,
    )
