load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_python//python:pip.bzl", "whl_filegroup")
load("@rules_semiwrap//:defs.bzl", "copy_extension_library", "create_pybind_library", "make_pyi", "robotpy_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "publish_casters", "resolve_casters", "run_header_gen")
load("//bazel_scripts:file_resolver_utils.bzl", "local_native_libraries_helper", "local_pybind_library", "resolve_caster_file", "resolve_include_root")

def wpimath_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps = []):
    WPIMATH_HEADER_GEN = [
        struct(
            class_name = "ComputerVisionUtil",
            yml_file = "semiwrap/ComputerVisionUtil.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/ComputerVisionUtil.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "MathUtil",
            yml_file = "semiwrap/MathUtil.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/MathUtil.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
    ]

    resolve_casters(
        name = "wpimath.resolve_casters",
        caster_files = [":wpimath/wpimath-casters.pybind11.json"],
        caster_deps = [resolve_caster_file("wpiutil-casters")],
        casters_pkl_file = "wpimath.casters.pkl",
        dep_file = "wpimath.casters.d",
    )

    gen_libinit(
        name = "wpimath.gen_lib_init",
        output_file = "wpimath/_init__wpimath.py",
        modules = ["native.wpimath._init_robotpy_native_wpimath", "wpiutil._init__wpiutil"],
    )

    gen_pkgconf(
        name = "wpimath.gen_pkgconf",
        libinit_py = "wpimath._init__wpimath",
        module_pkg_name = "wpimath._wpimath",
        output_file = "wpimath.pc",
        pkg_name = "wpimath",
        install_path = "wpimath",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpimath.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPIMATH_HEADER_GEN],
        libname = "_wpimath",
        output_file = "semiwrap_init.wpimath._wpimath.hpp",
    )

    run_header_gen(
        name = "wpimath",
        casters_pickle = "wpimath.casters.pkl",
        header_gen_config = WPIMATH_HEADER_GEN,
        trampoline_subpath = "wpimath",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpimath.generated_files",
        srcs = [
            "wpimath.gen_modinit_hpp.gen",
            "wpimath.header_gen_files",
            "wpimath.gen_pkgconf",
            "wpimath.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpimath",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpimath.generated_srcs"],
        semiwrap_header = [":wpimath.gen_modinit_hpp"],
        deps = deps + [
            ":wpimath.tmpl_hdrs",
            ":wpimath.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    whl_filegroup(
        name = "wpimath.wheel.trampoline_files",
        pattern = "wpimath/trampolines",
        whl = ":wpimath-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath.wheel.trampoline_hdrs",
        hdrs = [":wpimath.wheel.trampoline_files"],
        includes = ["wpimath.wheel.trampoline_files/wpimath"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath.wheel.headers",
        deps = [
            ":wpimath.wheel.trampoline_hdrs",
            ":wpimath-casters.wheel.headers",
            "//subprojects/robotpy-native-wpimath:wpimath",
            "//subprojects/robotpy-native-wpiutil:wpiutil",
            "//subprojects/robotpy-wpiutil:wpiutil.wheel.headers",
        ],
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    make_pyi(
        name = "wpimath.make_pyi",
        extension_package = "wpimath._wpimath",
        extension_library = "copy_wpimath",
        interface_files = [
            "_wpimath.pyi",
        ],
        init_pkgcfgs = [
            "wpimath/_init__wpimath.py",
            "wpimath/filter/_init__filter.py",
            "wpimath/geometry/_init__geometry.py",
            "wpimath/interpolation/_init__interpolation.py",
            "wpimath/kinematics/_init__kinematics.py",
            "wpimath/spline/_init__spline.py",
            "wpimath/_controls/_init__controls.py",
        ],
        init_packages = [
            "wpimath",
            "wpimath/filter",
            "wpimath/geometry",
            "wpimath/interpolation",
            "wpimath/kinematics",
            "wpimath/spline",
            "wpimath/_controls",
        ],
        install_path = "wpimath",
        python_deps = [
            local_pybind_library("//subprojects/robotpy-native-wpimath", "robotpy-native-wpimath"),
            local_pybind_library("//subprojects/robotpy-native-wpiutil", "robotpy-native-wpiutil"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ] + extra_pyi_deps,
        target_compatible_with = select({
            "//conditions:default": ["@platforms//:incompatible"],
        }),
        local_extension_deps = [
            ("wpimath/filter/_filter", "copy_wpimath_filter"),
            ("wpimath/geometry/_geometry", "copy_wpimath_geometry"),
            ("wpimath/interpolation/_interpolation", "copy_wpimath_interpolation"),
            ("wpimath/kinematics/_kinematics", "copy_wpimath_kinematics"),
            ("wpimath/spline/_spline", "copy_wpimath_spline"),
            ("wpimath/_controls/_controls", "copy_wpimath_controls"),
        ],
    )

def wpimath_filter_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps = []):
    WPIMATH_FILTER_HEADER_GEN = [
        struct(
            class_name = "Debouncer",
            yml_file = "semiwrap/filter/Debouncer.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/filter/Debouncer.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Debouncer", "frc__Debouncer.hpp"),
            ],
        ),
        struct(
            class_name = "LinearFilter",
            yml_file = "semiwrap/filter/LinearFilter.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/filter/LinearFilter.h",
            tmpl_class_names = [
                ("LinearFilter_tmpl1", "LinearFilter"),
            ],
            trampolines = [
                ("frc::LinearFilter", "frc__LinearFilter.hpp"),
            ],
        ),
        struct(
            class_name = "MedianFilter",
            yml_file = "semiwrap/filter/MedianFilter.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/filter/MedianFilter.h",
            tmpl_class_names = [
                ("MedianFilter_tmpl1", "MedianFilter"),
            ],
            trampolines = [
                ("frc::MedianFilter", "frc__MedianFilter.hpp"),
            ],
        ),
        struct(
            class_name = "SlewRateLimiter",
            yml_file = "semiwrap/filter/SlewRateLimiter.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/filter/SlewRateLimiter.h",
            tmpl_class_names = [
                ("SlewRateLimiter_tmpl1", "SlewRateLimiter"),
            ],
            trampolines = [
                ("frc::SlewRateLimiter", "frc__SlewRateLimiter.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpimath_filter.resolve_casters",
        caster_files = [":wpimath/wpimath-casters.pybind11.json"],
        caster_deps = [resolve_caster_file("wpiutil-casters")],
        casters_pkl_file = "wpimath_filter.casters.pkl",
        dep_file = "wpimath_filter.casters.d",
    )

    gen_libinit(
        name = "wpimath_filter.gen_lib_init",
        output_file = "wpimath/filter/_init__filter.py",
        modules = ["native.wpimath._init_robotpy_native_wpimath", "wpimath._init__wpimath"],
    )

    gen_pkgconf(
        name = "wpimath_filter.gen_pkgconf",
        libinit_py = "wpimath.filter._init__filter",
        module_pkg_name = "wpimath.filter._filter",
        output_file = "wpimath_filter.pc",
        pkg_name = "wpimath_filter",
        install_path = "wpimath/filter",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpimath_filter.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPIMATH_FILTER_HEADER_GEN],
        libname = "_filter",
        output_file = "semiwrap_init.wpimath.filter._filter.hpp",
    )

    run_header_gen(
        name = "wpimath_filter",
        casters_pickle = "wpimath_filter.casters.pkl",
        header_gen_config = WPIMATH_FILTER_HEADER_GEN,
        trampoline_subpath = "wpimath/filter",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpimath_filter.generated_files",
        srcs = [
            "wpimath_filter.gen_modinit_hpp.gen",
            "wpimath_filter.header_gen_files",
            "wpimath_filter.gen_pkgconf",
            "wpimath_filter.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpimath_filter",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpimath_filter.generated_srcs"],
        semiwrap_header = [":wpimath_filter.gen_modinit_hpp"],
        deps = deps + [
            ":wpimath_filter.tmpl_hdrs",
            ":wpimath_filter.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    whl_filegroup(
        name = "wpimath_filter.wheel.trampoline_files",
        pattern = "wpimath/filter/trampolines",
        whl = ":wpimath-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_filter.wheel.trampoline_hdrs",
        hdrs = [":wpimath_filter.wheel.trampoline_files"],
        includes = ["wpimath_filter.wheel.trampoline_files/wpimath/filter"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_filter.wheel.headers",
        deps = [
            ":wpimath_filter.wheel.trampoline_hdrs",
            ":wpimath-casters.wheel.headers",
            "//subprojects/robotpy-native-wpimath:wpimath",
            "//subprojects/robotpy-native-wpiutil:wpiutil",
            "//subprojects/robotpy-wpimath:wpimath.wheel.headers",
            "//subprojects/robotpy-wpiutil:wpiutil.wheel.headers",
        ],
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    make_pyi(
        name = "wpimath_filter.make_pyi",
        extension_package = "wpimath.filter._filter",
        extension_library = "copy_wpimath_filter",
        interface_files = [
            "_filter.pyi",
        ],
        init_pkgcfgs = [
            "wpimath/_init__wpimath.py",
            "wpimath/filter/_init__filter.py",
            "wpimath/geometry/_init__geometry.py",
            "wpimath/interpolation/_init__interpolation.py",
            "wpimath/kinematics/_init__kinematics.py",
            "wpimath/spline/_init__spline.py",
            "wpimath/_controls/_init__controls.py",
        ],
        init_packages = [
            "wpimath",
            "wpimath/filter",
            "wpimath/geometry",
            "wpimath/interpolation",
            "wpimath/kinematics",
            "wpimath/spline",
            "wpimath/_controls",
        ],
        install_path = "wpimath/filter",
        python_deps = [
            local_pybind_library("//subprojects/robotpy-native-wpimath", "robotpy-native-wpimath"),
            local_pybind_library("//subprojects/robotpy-native-wpiutil", "robotpy-native-wpiutil"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ] + extra_pyi_deps,
        target_compatible_with = select({
            "//conditions:default": ["@platforms//:incompatible"],
        }),
        local_extension_deps = [
            ("wpimath/_wpimath", "copy_wpimath"),
            ("wpimath/geometry/_geometry", "copy_wpimath_geometry"),
            ("wpimath/interpolation/_interpolation", "copy_wpimath_interpolation"),
            ("wpimath/kinematics/_kinematics", "copy_wpimath_kinematics"),
            ("wpimath/spline/_spline", "copy_wpimath_spline"),
            ("wpimath/_controls/_controls", "copy_wpimath_controls"),
        ],
    )

def wpimath_geometry_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps = []):
    WPIMATH_GEOMETRY_HEADER_GEN = [
        struct(
            class_name = "CoordinateAxis",
            yml_file = "semiwrap/geometry/CoordinateAxis.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/CoordinateAxis.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::CoordinateAxis", "frc__CoordinateAxis.hpp"),
            ],
        ),
        struct(
            class_name = "CoordinateSystem",
            yml_file = "semiwrap/geometry/CoordinateSystem.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/CoordinateSystem.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::CoordinateSystem", "frc__CoordinateSystem.hpp"),
            ],
        ),
        struct(
            class_name = "Ellipse2d",
            yml_file = "semiwrap/geometry/Ellipse2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Ellipse2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Ellipse2d", "frc__Ellipse2d.hpp"),
            ],
        ),
        struct(
            class_name = "Pose2d",
            yml_file = "semiwrap/geometry/Pose2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Pose2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Pose2d", "frc__Pose2d.hpp"),
            ],
        ),
        struct(
            class_name = "Pose3d",
            yml_file = "semiwrap/geometry/Pose3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Pose3d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Pose3d", "frc__Pose3d.hpp"),
            ],
        ),
        struct(
            class_name = "Quaternion",
            yml_file = "semiwrap/geometry/Quaternion.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Quaternion.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Quaternion", "frc__Quaternion.hpp"),
            ],
        ),
        struct(
            class_name = "Rectangle2d",
            yml_file = "semiwrap/geometry/Rectangle2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Rectangle2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Rectangle2d", "frc__Rectangle2d.hpp"),
            ],
        ),
        struct(
            class_name = "Rotation2d",
            yml_file = "semiwrap/geometry/Rotation2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Rotation2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Rotation2d", "frc__Rotation2d.hpp"),
            ],
        ),
        struct(
            class_name = "Rotation3d",
            yml_file = "semiwrap/geometry/Rotation3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Rotation3d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Rotation3d", "frc__Rotation3d.hpp"),
            ],
        ),
        struct(
            class_name = "Transform2d",
            yml_file = "semiwrap/geometry/Transform2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Transform2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Transform2d", "frc__Transform2d.hpp"),
            ],
        ),
        struct(
            class_name = "Transform3d",
            yml_file = "semiwrap/geometry/Transform3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Transform3d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Transform3d", "frc__Transform3d.hpp"),
            ],
        ),
        struct(
            class_name = "Translation2d",
            yml_file = "semiwrap/geometry/Translation2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Translation2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Translation2d", "frc__Translation2d.hpp"),
            ],
        ),
        struct(
            class_name = "Translation3d",
            yml_file = "semiwrap/geometry/Translation3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Translation3d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Translation3d", "frc__Translation3d.hpp"),
            ],
        ),
        struct(
            class_name = "Twist2d",
            yml_file = "semiwrap/geometry/Twist2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Twist2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Twist2d", "frc__Twist2d.hpp"),
            ],
        ),
        struct(
            class_name = "Twist3d",
            yml_file = "semiwrap/geometry/Twist3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/geometry/Twist3d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Twist3d", "frc__Twist3d.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpimath_geometry.resolve_casters",
        caster_files = [":wpimath/wpimath-casters.pybind11.json"],
        caster_deps = [resolve_caster_file("wpiutil-casters")],
        casters_pkl_file = "wpimath_geometry.casters.pkl",
        dep_file = "wpimath_geometry.casters.d",
    )

    gen_libinit(
        name = "wpimath_geometry.gen_lib_init",
        output_file = "wpimath/geometry/_init__geometry.py",
        modules = ["native.wpimath._init_robotpy_native_wpimath", "wpimath._init__wpimath"],
    )

    gen_pkgconf(
        name = "wpimath_geometry.gen_pkgconf",
        libinit_py = "wpimath.geometry._init__geometry",
        module_pkg_name = "wpimath.geometry._geometry",
        output_file = "wpimath_geometry.pc",
        pkg_name = "wpimath_geometry",
        install_path = "wpimath/geometry",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpimath_geometry.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPIMATH_GEOMETRY_HEADER_GEN],
        libname = "_geometry",
        output_file = "semiwrap_init.wpimath.geometry._geometry.hpp",
    )

    run_header_gen(
        name = "wpimath_geometry",
        casters_pickle = "wpimath_geometry.casters.pkl",
        header_gen_config = WPIMATH_GEOMETRY_HEADER_GEN,
        trampoline_subpath = "wpimath/geometry",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpimath_geometry.generated_files",
        srcs = [
            "wpimath_geometry.gen_modinit_hpp.gen",
            "wpimath_geometry.header_gen_files",
            "wpimath_geometry.gen_pkgconf",
            "wpimath_geometry.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpimath_geometry",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpimath_geometry.generated_srcs"],
        semiwrap_header = [":wpimath_geometry.gen_modinit_hpp"],
        deps = deps + [
            ":wpimath_geometry.tmpl_hdrs",
            ":wpimath_geometry.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    whl_filegroup(
        name = "wpimath_geometry.wheel.trampoline_files",
        pattern = "wpimath/geometry/trampolines",
        whl = ":wpimath-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_geometry.wheel.trampoline_hdrs",
        hdrs = [":wpimath_geometry.wheel.trampoline_files"],
        includes = ["wpimath_geometry.wheel.trampoline_files/wpimath/geometry"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_geometry.wheel.headers",
        deps = [
            ":wpimath_geometry.wheel.trampoline_hdrs",
            ":wpimath-casters.wheel.headers",
            "//subprojects/robotpy-native-wpimath:wpimath",
            "//subprojects/robotpy-native-wpiutil:wpiutil",
            "//subprojects/robotpy-wpimath:wpimath.wheel.headers",
            "//subprojects/robotpy-wpiutil:wpiutil.wheel.headers",
        ],
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    make_pyi(
        name = "wpimath_geometry.make_pyi",
        extension_package = "wpimath.geometry._geometry",
        extension_library = "copy_wpimath_geometry",
        interface_files = [
            "_geometry.pyi",
        ],
        init_pkgcfgs = [
            "wpimath/_init__wpimath.py",
            "wpimath/filter/_init__filter.py",
            "wpimath/geometry/_init__geometry.py",
            "wpimath/interpolation/_init__interpolation.py",
            "wpimath/kinematics/_init__kinematics.py",
            "wpimath/spline/_init__spline.py",
            "wpimath/_controls/_init__controls.py",
        ],
        init_packages = [
            "wpimath",
            "wpimath/filter",
            "wpimath/geometry",
            "wpimath/interpolation",
            "wpimath/kinematics",
            "wpimath/spline",
            "wpimath/_controls",
        ],
        install_path = "wpimath/geometry",
        python_deps = [
            local_pybind_library("//subprojects/robotpy-native-wpimath", "robotpy-native-wpimath"),
            local_pybind_library("//subprojects/robotpy-native-wpiutil", "robotpy-native-wpiutil"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ] + extra_pyi_deps,
        target_compatible_with = select({
            "//conditions:default": ["@platforms//:incompatible"],
        }),
        local_extension_deps = [
            ("wpimath/_wpimath", "copy_wpimath"),
            ("wpimath/filter/_filter", "copy_wpimath_filter"),
            ("wpimath/interpolation/_interpolation", "copy_wpimath_interpolation"),
            ("wpimath/kinematics/_kinematics", "copy_wpimath_kinematics"),
            ("wpimath/spline/_spline", "copy_wpimath_spline"),
            ("wpimath/_controls/_controls", "copy_wpimath_controls"),
        ],
    )

def wpimath_interpolation_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps = []):
    WPIMATH_INTERPOLATION_HEADER_GEN = [
        struct(
            class_name = "TimeInterpolatableBuffer",
            yml_file = "semiwrap/interpolation/TimeInterpolatableBuffer.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/interpolation/TimeInterpolatableBuffer.h",
            tmpl_class_names = [
                ("TimeInterpolatableBuffer_tmpl1", "TimeInterpolatablePose2dBuffer"),
                ("TimeInterpolatableBuffer_tmpl2", "TimeInterpolatablePose3dBuffer"),
                ("TimeInterpolatableBuffer_tmpl3", "TimeInterpolatableRotation2dBuffer"),
                ("TimeInterpolatableBuffer_tmpl4", "TimeInterpolatableRotation3dBuffer"),
                ("TimeInterpolatableBuffer_tmpl5", "TimeInterpolatableTranslation2dBuffer"),
                ("TimeInterpolatableBuffer_tmpl6", "TimeInterpolatableTranslation3dBuffer"),
                ("TimeInterpolatableBuffer_tmpl7", "TimeInterpolatableFloatBuffer"),
            ],
            trampolines = [
                ("frc::TimeInterpolatableBuffer", "frc__TimeInterpolatableBuffer.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpimath_interpolation.resolve_casters",
        caster_files = [":wpimath/wpimath-casters.pybind11.json"],
        caster_deps = [resolve_caster_file("wpiutil-casters")],
        casters_pkl_file = "wpimath_interpolation.casters.pkl",
        dep_file = "wpimath_interpolation.casters.d",
    )

    gen_libinit(
        name = "wpimath_interpolation.gen_lib_init",
        output_file = "wpimath/interpolation/_init__interpolation.py",
        modules = ["native.wpimath._init_robotpy_native_wpimath", "wpimath.geometry._init__geometry"],
    )

    gen_pkgconf(
        name = "wpimath_interpolation.gen_pkgconf",
        libinit_py = "wpimath.interpolation._init__interpolation",
        module_pkg_name = "wpimath.interpolation._interpolation",
        output_file = "wpimath_interpolation.pc",
        pkg_name = "wpimath_interpolation",
        install_path = "wpimath/interpolation",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpimath_interpolation.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPIMATH_INTERPOLATION_HEADER_GEN],
        libname = "_interpolation",
        output_file = "semiwrap_init.wpimath.interpolation._interpolation.hpp",
    )

    run_header_gen(
        name = "wpimath_interpolation",
        casters_pickle = "wpimath_interpolation.casters.pkl",
        header_gen_config = WPIMATH_INTERPOLATION_HEADER_GEN,
        trampoline_subpath = "wpimath/interpolation",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpimath_interpolation.generated_files",
        srcs = [
            "wpimath_interpolation.gen_modinit_hpp.gen",
            "wpimath_interpolation.header_gen_files",
            "wpimath_interpolation.gen_pkgconf",
            "wpimath_interpolation.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpimath_interpolation",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpimath_interpolation.generated_srcs"],
        semiwrap_header = [":wpimath_interpolation.gen_modinit_hpp"],
        deps = deps + [
            ":wpimath_interpolation.tmpl_hdrs",
            ":wpimath_interpolation.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    whl_filegroup(
        name = "wpimath_interpolation.wheel.trampoline_files",
        pattern = "wpimath/interpolation/trampolines",
        whl = ":wpimath-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_interpolation.wheel.trampoline_hdrs",
        hdrs = [":wpimath_interpolation.wheel.trampoline_files"],
        includes = ["wpimath_interpolation.wheel.trampoline_files/wpimath/interpolation"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_interpolation.wheel.headers",
        deps = [
            ":wpimath_interpolation.wheel.trampoline_hdrs",
            ":wpimath-casters.wheel.headers",
            "//subprojects/robotpy-native-wpimath:wpimath",
            "//subprojects/robotpy-native-wpiutil:wpiutil",
            "//subprojects/robotpy-wpimath:wpimath.wheel.headers",
            "//subprojects/robotpy-wpimath:wpimath_geometry.wheel.headers",
        ],
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    make_pyi(
        name = "wpimath_interpolation.make_pyi",
        extension_package = "wpimath.interpolation._interpolation",
        extension_library = "copy_wpimath_interpolation",
        interface_files = [
            "_interpolation.pyi",
        ],
        init_pkgcfgs = [
            "wpimath/_init__wpimath.py",
            "wpimath/filter/_init__filter.py",
            "wpimath/geometry/_init__geometry.py",
            "wpimath/interpolation/_init__interpolation.py",
            "wpimath/kinematics/_init__kinematics.py",
            "wpimath/spline/_init__spline.py",
            "wpimath/_controls/_init__controls.py",
        ],
        init_packages = [
            "wpimath",
            "wpimath/filter",
            "wpimath/geometry",
            "wpimath/interpolation",
            "wpimath/kinematics",
            "wpimath/spline",
            "wpimath/_controls",
        ],
        install_path = "wpimath/interpolation",
        python_deps = [
            local_pybind_library("//subprojects/robotpy-native-wpimath", "robotpy-native-wpimath"),
            local_pybind_library("//subprojects/robotpy-native-wpiutil", "robotpy-native-wpiutil"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ] + extra_pyi_deps,
        target_compatible_with = select({
            "//conditions:default": ["@platforms//:incompatible"],
        }),
        local_extension_deps = [
            ("wpimath/_wpimath", "copy_wpimath"),
            ("wpimath/filter/_filter", "copy_wpimath_filter"),
            ("wpimath/geometry/_geometry", "copy_wpimath_geometry"),
            ("wpimath/kinematics/_kinematics", "copy_wpimath_kinematics"),
            ("wpimath/spline/_spline", "copy_wpimath_spline"),
            ("wpimath/_controls/_controls", "copy_wpimath_controls"),
        ],
    )

def wpimath_kinematics_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps = []):
    WPIMATH_KINEMATICS_HEADER_GEN = [
        struct(
            class_name = "ChassisSpeeds",
            yml_file = "semiwrap/kinematics/ChassisSpeeds.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/ChassisSpeeds.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::ChassisSpeeds", "frc__ChassisSpeeds.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDriveKinematics",
            yml_file = "semiwrap/kinematics/DifferentialDriveKinematics.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/DifferentialDriveKinematics.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDriveKinematics", "frc__DifferentialDriveKinematics.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDriveOdometry3d",
            yml_file = "semiwrap/kinematics/DifferentialDriveOdometry3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/DifferentialDriveOdometry3d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDriveOdometry3d", "frc__DifferentialDriveOdometry3d.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDriveOdometry",
            yml_file = "semiwrap/kinematics/DifferentialDriveOdometry.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/DifferentialDriveOdometry.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDriveOdometry", "frc__DifferentialDriveOdometry.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDriveWheelPositions",
            yml_file = "semiwrap/kinematics/DifferentialDriveWheelPositions.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/DifferentialDriveWheelPositions.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDriveWheelPositions", "frc__DifferentialDriveWheelPositions.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDriveWheelSpeeds",
            yml_file = "semiwrap/kinematics/DifferentialDriveWheelSpeeds.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/DifferentialDriveWheelSpeeds.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDriveWheelSpeeds", "frc__DifferentialDriveWheelSpeeds.hpp"),
            ],
        ),
        struct(
            class_name = "Kinematics",
            yml_file = "semiwrap/kinematics/Kinematics.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/Kinematics.h",
            tmpl_class_names = [
                ("Kinematics_tmpl1", "DifferentialDriveKinematicsBase"),
                ("Kinematics_tmpl2", "MecanumDriveKinematicsBase"),
                ("Kinematics_tmpl3", "SwerveDrive2KinematicsBase"),
                ("Kinematics_tmpl4", "SwerveDrive3KinematicsBase"),
                ("Kinematics_tmpl5", "SwerveDrive4KinematicsBase"),
                ("Kinematics_tmpl6", "SwerveDrive6KinematicsBase"),
            ],
            trampolines = [
                ("frc::Kinematics", "frc__Kinematics.hpp"),
            ],
        ),
        struct(
            class_name = "MecanumDriveKinematics",
            yml_file = "semiwrap/kinematics/MecanumDriveKinematics.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/MecanumDriveKinematics.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MecanumDriveKinematics", "frc__MecanumDriveKinematics.hpp"),
            ],
        ),
        struct(
            class_name = "MecanumDriveOdometry",
            yml_file = "semiwrap/kinematics/MecanumDriveOdometry.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/MecanumDriveOdometry.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MecanumDriveOdometry", "frc__MecanumDriveOdometry.hpp"),
            ],
        ),
        struct(
            class_name = "MecanumDriveOdometry3d",
            yml_file = "semiwrap/kinematics/MecanumDriveOdometry3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/MecanumDriveOdometry3d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MecanumDriveOdometry3d", "frc__MecanumDriveOdometry3d.hpp"),
            ],
        ),
        struct(
            class_name = "MecanumDriveWheelPositions",
            yml_file = "semiwrap/kinematics/MecanumDriveWheelPositions.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/MecanumDriveWheelPositions.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MecanumDriveWheelPositions", "frc__MecanumDriveWheelPositions.hpp"),
            ],
        ),
        struct(
            class_name = "MecanumDriveWheelSpeeds",
            yml_file = "semiwrap/kinematics/MecanumDriveWheelSpeeds.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/MecanumDriveWheelSpeeds.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MecanumDriveWheelSpeeds", "frc__MecanumDriveWheelSpeeds.hpp"),
            ],
        ),
        struct(
            class_name = "Odometry",
            yml_file = "semiwrap/kinematics/Odometry.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/Odometry.h",
            tmpl_class_names = [
                ("Odometry_tmpl1", "DifferentialDriveOdometryBase"),
                ("Odometry_tmpl2", "MecanumDriveOdometryBase"),
                ("Odometry_tmpl3", "SwerveDrive2OdometryBase"),
                ("Odometry_tmpl4", "SwerveDrive3OdometryBase"),
                ("Odometry_tmpl5", "SwerveDrive4OdometryBase"),
                ("Odometry_tmpl6", "SwerveDrive6OdometryBase"),
            ],
            trampolines = [
                ("frc::Odometry", "frc__Odometry.hpp"),
            ],
        ),
        struct(
            class_name = "Odometry3d",
            yml_file = "semiwrap/kinematics/Odometry3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/Odometry3d.h",
            tmpl_class_names = [
                ("Odometry3d_tmpl1", "DifferentialDriveOdometry3dBase"),
                ("Odometry3d_tmpl2", "MecanumDriveOdometry3dBase"),
                ("Odometry3d_tmpl3", "SwerveDrive2Odometry3dBase"),
                ("Odometry3d_tmpl4", "SwerveDrive3Odometry3dBase"),
                ("Odometry3d_tmpl5", "SwerveDrive4Odometry3dBase"),
                ("Odometry3d_tmpl6", "SwerveDrive6Odometry3dBase"),
            ],
            trampolines = [
                ("frc::Odometry3d", "frc__Odometry3d.hpp"),
            ],
        ),
        struct(
            class_name = "SwerveDriveKinematics",
            yml_file = "semiwrap/kinematics/SwerveDriveKinematics.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/SwerveDriveKinematics.h",
            tmpl_class_names = [
                ("SwerveDriveKinematics_tmpl1", "SwerveDrive2Kinematics"),
                ("SwerveDriveKinematics_tmpl2", "SwerveDrive3Kinematics"),
                ("SwerveDriveKinematics_tmpl3", "SwerveDrive4Kinematics"),
                ("SwerveDriveKinematics_tmpl4", "SwerveDrive6Kinematics"),
            ],
            trampolines = [
                ("frc::SwerveDriveKinematics", "frc__SwerveDriveKinematics.hpp"),
            ],
        ),
        struct(
            class_name = "SwerveDriveOdometry",
            yml_file = "semiwrap/kinematics/SwerveDriveOdometry.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/SwerveDriveOdometry.h",
            tmpl_class_names = [
                ("SwerveDriveOdometry_tmpl1", "SwerveDrive2Odometry"),
                ("SwerveDriveOdometry_tmpl2", "SwerveDrive3Odometry"),
                ("SwerveDriveOdometry_tmpl3", "SwerveDrive4Odometry"),
                ("SwerveDriveOdometry_tmpl4", "SwerveDrive6Odometry"),
            ],
            trampolines = [
                ("frc::SwerveDriveOdometry", "frc__SwerveDriveOdometry.hpp"),
            ],
        ),
        struct(
            class_name = "SwerveDriveOdometry3d",
            yml_file = "semiwrap/kinematics/SwerveDriveOdometry3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/SwerveDriveOdometry3d.h",
            tmpl_class_names = [
                ("SwerveDriveOdometry3d_tmpl1", "SwerveDrive2Odometry3d"),
                ("SwerveDriveOdometry3d_tmpl2", "SwerveDrive3Odometry3d"),
                ("SwerveDriveOdometry3d_tmpl3", "SwerveDrive4Odometry3d"),
                ("SwerveDriveOdometry3d_tmpl4", "SwerveDrive6Odometry3d"),
            ],
            trampolines = [
                ("frc::SwerveDriveOdometry3d", "frc__SwerveDriveOdometry3d.hpp"),
            ],
        ),
        struct(
            class_name = "SwerveModulePosition",
            yml_file = "semiwrap/kinematics/SwerveModulePosition.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/SwerveModulePosition.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SwerveModulePosition", "frc__SwerveModulePosition.hpp"),
            ],
        ),
        struct(
            class_name = "SwerveModuleState",
            yml_file = "semiwrap/kinematics/SwerveModuleState.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/kinematics/SwerveModuleState.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SwerveModuleState", "frc__SwerveModuleState.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpimath_kinematics.resolve_casters",
        caster_files = [":wpimath/wpimath-casters.pybind11.json"],
        caster_deps = [resolve_caster_file("wpiutil-casters")],
        casters_pkl_file = "wpimath_kinematics.casters.pkl",
        dep_file = "wpimath_kinematics.casters.d",
    )

    gen_libinit(
        name = "wpimath_kinematics.gen_lib_init",
        output_file = "wpimath/kinematics/_init__kinematics.py",
        modules = ["native.wpimath._init_robotpy_native_wpimath", "wpimath.geometry._init__geometry"],
    )

    gen_pkgconf(
        name = "wpimath_kinematics.gen_pkgconf",
        libinit_py = "wpimath.kinematics._init__kinematics",
        module_pkg_name = "wpimath.kinematics._kinematics",
        output_file = "wpimath_kinematics.pc",
        pkg_name = "wpimath_kinematics",
        install_path = "wpimath/kinematics",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpimath_kinematics.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPIMATH_KINEMATICS_HEADER_GEN],
        libname = "_kinematics",
        output_file = "semiwrap_init.wpimath.kinematics._kinematics.hpp",
    )

    run_header_gen(
        name = "wpimath_kinematics",
        casters_pickle = "wpimath_kinematics.casters.pkl",
        header_gen_config = WPIMATH_KINEMATICS_HEADER_GEN,
        trampoline_subpath = "wpimath/kinematics",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpimath_kinematics.generated_files",
        srcs = [
            "wpimath_kinematics.gen_modinit_hpp.gen",
            "wpimath_kinematics.header_gen_files",
            "wpimath_kinematics.gen_pkgconf",
            "wpimath_kinematics.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpimath_kinematics",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpimath_kinematics.generated_srcs"],
        semiwrap_header = [":wpimath_kinematics.gen_modinit_hpp"],
        deps = deps + [
            ":wpimath_kinematics.tmpl_hdrs",
            ":wpimath_kinematics.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    whl_filegroup(
        name = "wpimath_kinematics.wheel.trampoline_files",
        pattern = "wpimath/kinematics/trampolines",
        whl = ":wpimath-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_kinematics.wheel.trampoline_hdrs",
        hdrs = [":wpimath_kinematics.wheel.trampoline_files"],
        includes = ["wpimath_kinematics.wheel.trampoline_files/wpimath/kinematics"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_kinematics.wheel.headers",
        deps = [
            ":wpimath_kinematics.wheel.trampoline_hdrs",
            ":wpimath-casters.wheel.headers",
            "//subprojects/robotpy-native-wpimath:wpimath",
            "//subprojects/robotpy-native-wpiutil:wpiutil",
            "//subprojects/robotpy-wpimath:wpimath.wheel.headers",
            "//subprojects/robotpy-wpimath:wpimath_geometry.wheel.headers",
        ],
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    make_pyi(
        name = "wpimath_kinematics.make_pyi",
        extension_package = "wpimath.kinematics._kinematics",
        extension_library = "copy_wpimath_kinematics",
        interface_files = [
            "_kinematics.pyi",
        ],
        init_pkgcfgs = [
            "wpimath/_init__wpimath.py",
            "wpimath/filter/_init__filter.py",
            "wpimath/geometry/_init__geometry.py",
            "wpimath/interpolation/_init__interpolation.py",
            "wpimath/kinematics/_init__kinematics.py",
            "wpimath/spline/_init__spline.py",
            "wpimath/_controls/_init__controls.py",
        ],
        init_packages = [
            "wpimath",
            "wpimath/filter",
            "wpimath/geometry",
            "wpimath/interpolation",
            "wpimath/kinematics",
            "wpimath/spline",
            "wpimath/_controls",
        ],
        install_path = "wpimath/kinematics",
        python_deps = [
            local_pybind_library("//subprojects/robotpy-native-wpimath", "robotpy-native-wpimath"),
            local_pybind_library("//subprojects/robotpy-native-wpiutil", "robotpy-native-wpiutil"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ] + extra_pyi_deps,
        target_compatible_with = select({
            "//conditions:default": ["@platforms//:incompatible"],
        }),
        local_extension_deps = [
            ("wpimath/_wpimath", "copy_wpimath"),
            ("wpimath/filter/_filter", "copy_wpimath_filter"),
            ("wpimath/geometry/_geometry", "copy_wpimath_geometry"),
            ("wpimath/interpolation/_interpolation", "copy_wpimath_interpolation"),
            ("wpimath/spline/_spline", "copy_wpimath_spline"),
            ("wpimath/_controls/_controls", "copy_wpimath_controls"),
        ],
    )

def wpimath_spline_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps = []):
    WPIMATH_SPLINE_HEADER_GEN = [
        struct(
            class_name = "CubicHermiteSpline",
            yml_file = "semiwrap/spline/CubicHermiteSpline.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/spline/CubicHermiteSpline.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::CubicHermiteSpline", "frc__CubicHermiteSpline.hpp"),
            ],
        ),
        struct(
            class_name = "QuinticHermiteSpline",
            yml_file = "semiwrap/spline/QuinticHermiteSpline.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/spline/QuinticHermiteSpline.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::QuinticHermiteSpline", "frc__QuinticHermiteSpline.hpp"),
            ],
        ),
        struct(
            class_name = "Spline",
            yml_file = "semiwrap/spline/Spline.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/spline/Spline.h",
            tmpl_class_names = [
                ("Spline_tmpl1", "Spline3"),
                ("Spline_tmpl2", "Spline5"),
            ],
            trampolines = [
                ("frc::Spline", "frc__Spline.hpp"),
                ("frc::Spline::ControlVector", "frc__Spline__ControlVector.hpp"),
            ],
        ),
        struct(
            class_name = "SplineHelper",
            yml_file = "semiwrap/spline/SplineHelper.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/spline/SplineHelper.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SplineHelper", "frc__SplineHelper.hpp"),
            ],
        ),
        struct(
            class_name = "SplineParameterizer",
            yml_file = "semiwrap/spline/SplineParameterizer.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/spline/SplineParameterizer.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SplineParameterizer", "frc__SplineParameterizer.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpimath_spline.resolve_casters",
        caster_files = [":wpimath/wpimath-casters.pybind11.json"],
        caster_deps = [resolve_caster_file("wpiutil-casters")],
        casters_pkl_file = "wpimath_spline.casters.pkl",
        dep_file = "wpimath_spline.casters.d",
    )

    gen_libinit(
        name = "wpimath_spline.gen_lib_init",
        output_file = "wpimath/spline/_init__spline.py",
        modules = ["native.wpimath._init_robotpy_native_wpimath", "wpimath.geometry._init__geometry"],
    )

    gen_pkgconf(
        name = "wpimath_spline.gen_pkgconf",
        libinit_py = "wpimath.spline._init__spline",
        module_pkg_name = "wpimath.spline._spline",
        output_file = "wpimath_spline.pc",
        pkg_name = "wpimath_spline",
        install_path = "wpimath/spline",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpimath_spline.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPIMATH_SPLINE_HEADER_GEN],
        libname = "_spline",
        output_file = "semiwrap_init.wpimath.spline._spline.hpp",
    )

    run_header_gen(
        name = "wpimath_spline",
        casters_pickle = "wpimath_spline.casters.pkl",
        header_gen_config = WPIMATH_SPLINE_HEADER_GEN,
        trampoline_subpath = "wpimath/spline",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpimath_spline.generated_files",
        srcs = [
            "wpimath_spline.gen_modinit_hpp.gen",
            "wpimath_spline.header_gen_files",
            "wpimath_spline.gen_pkgconf",
            "wpimath_spline.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpimath_spline",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpimath_spline.generated_srcs"],
        semiwrap_header = [":wpimath_spline.gen_modinit_hpp"],
        deps = deps + [
            ":wpimath_spline.tmpl_hdrs",
            ":wpimath_spline.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    whl_filegroup(
        name = "wpimath_spline.wheel.trampoline_files",
        pattern = "wpimath/spline/trampolines",
        whl = ":wpimath-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_spline.wheel.trampoline_hdrs",
        hdrs = [":wpimath_spline.wheel.trampoline_files"],
        includes = ["wpimath_spline.wheel.trampoline_files/wpimath/spline"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_spline.wheel.headers",
        deps = [
            ":wpimath_spline.wheel.trampoline_hdrs",
            ":wpimath-casters.wheel.headers",
            "//subprojects/robotpy-native-wpimath:wpimath",
            "//subprojects/robotpy-native-wpiutil:wpiutil",
            "//subprojects/robotpy-wpimath:wpimath.wheel.headers",
            "//subprojects/robotpy-wpimath:wpimath_geometry.wheel.headers",
        ],
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    make_pyi(
        name = "wpimath_spline.make_pyi",
        extension_package = "wpimath.spline._spline",
        extension_library = "copy_wpimath_spline",
        interface_files = [
            "_spline.pyi",
        ],
        init_pkgcfgs = [
            "wpimath/_init__wpimath.py",
            "wpimath/filter/_init__filter.py",
            "wpimath/geometry/_init__geometry.py",
            "wpimath/interpolation/_init__interpolation.py",
            "wpimath/kinematics/_init__kinematics.py",
            "wpimath/spline/_init__spline.py",
            "wpimath/_controls/_init__controls.py",
        ],
        init_packages = [
            "wpimath",
            "wpimath/filter",
            "wpimath/geometry",
            "wpimath/interpolation",
            "wpimath/kinematics",
            "wpimath/spline",
            "wpimath/_controls",
        ],
        install_path = "wpimath/spline",
        python_deps = [
            local_pybind_library("//subprojects/robotpy-native-wpimath", "robotpy-native-wpimath"),
            local_pybind_library("//subprojects/robotpy-native-wpiutil", "robotpy-native-wpiutil"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ] + extra_pyi_deps,
        target_compatible_with = select({
            "//conditions:default": ["@platforms//:incompatible"],
        }),
        local_extension_deps = [
            ("wpimath/_wpimath", "copy_wpimath"),
            ("wpimath/filter/_filter", "copy_wpimath_filter"),
            ("wpimath/geometry/_geometry", "copy_wpimath_geometry"),
            ("wpimath/interpolation/_interpolation", "copy_wpimath_interpolation"),
            ("wpimath/kinematics/_kinematics", "copy_wpimath_kinematics"),
            ("wpimath/_controls/_controls", "copy_wpimath_controls"),
        ],
    )

def wpimath_controls_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps = []):
    WPIMATH_CONTROLS_HEADER_GEN = [
        struct(
            class_name = "ArmFeedforward",
            yml_file = "semiwrap/controls/ArmFeedforward.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/ArmFeedforward.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::ArmFeedforward", "frc__ArmFeedforward.hpp"),
            ],
        ),
        struct(
            class_name = "BangBangController",
            yml_file = "semiwrap/controls/BangBangController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/BangBangController.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::BangBangController", "frc__BangBangController.hpp"),
            ],
        ),
        struct(
            class_name = "ControlAffinePlantInversionFeedforward",
            yml_file = "semiwrap/controls/ControlAffinePlantInversionFeedforward.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/ControlAffinePlantInversionFeedforward.h",
            tmpl_class_names = [
                ("ControlAffinePlantInversionFeedforward_tmpl1", "ControlAffinePlantInversionFeedforward_1_1"),
                ("ControlAffinePlantInversionFeedforward_tmpl2", "ControlAffinePlantInversionFeedforward_2_1"),
                ("ControlAffinePlantInversionFeedforward_tmpl3", "ControlAffinePlantInversionFeedforward_2_2"),
            ],
            trampolines = [
                ("frc::ControlAffinePlantInversionFeedforward", "frc__ControlAffinePlantInversionFeedforward.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDriveAccelerationLimiter",
            yml_file = "semiwrap/controls/DifferentialDriveAccelerationLimiter.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/DifferentialDriveAccelerationLimiter.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDriveAccelerationLimiter", "frc__DifferentialDriveAccelerationLimiter.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDriveFeedforward",
            yml_file = "semiwrap/controls/DifferentialDriveFeedforward.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/DifferentialDriveFeedforward.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDriveFeedforward", "frc__DifferentialDriveFeedforward.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDriveWheelVoltages",
            yml_file = "semiwrap/controls/DifferentialDriveWheelVoltages.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/DifferentialDriveWheelVoltages.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDriveWheelVoltages", "frc__DifferentialDriveWheelVoltages.hpp"),
            ],
        ),
        struct(
            class_name = "ElevatorFeedforward",
            yml_file = "semiwrap/controls/ElevatorFeedforward.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/ElevatorFeedforward.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::ElevatorFeedforward", "frc__ElevatorFeedforward.hpp"),
            ],
        ),
        struct(
            class_name = "HolonomicDriveController",
            yml_file = "semiwrap/controls/HolonomicDriveController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/HolonomicDriveController.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::HolonomicDriveController", "frc__HolonomicDriveController.hpp"),
            ],
        ),
        struct(
            class_name = "ImplicitModelFollower",
            yml_file = "semiwrap/controls/ImplicitModelFollower.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/ImplicitModelFollower.h",
            tmpl_class_names = [
                ("ImplicitModelFollower_tmpl1", "ImplicitModelFollower_1_1"),
                ("ImplicitModelFollower_tmpl2", "ImplicitModelFollower_2_1"),
                ("ImplicitModelFollower_tmpl3", "ImplicitModelFollower_2_2"),
            ],
            trampolines = [
                ("frc::ImplicitModelFollower", "frc__ImplicitModelFollower.hpp"),
            ],
        ),
        struct(
            class_name = "LTVDifferentialDriveController",
            yml_file = "semiwrap/controls/LTVDifferentialDriveController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/LTVDifferentialDriveController.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::LTVDifferentialDriveController", "frc__LTVDifferentialDriveController.hpp"),
            ],
        ),
        struct(
            class_name = "LTVUnicycleController",
            yml_file = "semiwrap/controls/LTVUnicycleController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/LTVUnicycleController.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::LTVUnicycleController", "frc__LTVUnicycleController.hpp"),
            ],
        ),
        struct(
            class_name = "LinearPlantInversionFeedforward",
            yml_file = "semiwrap/controls/LinearPlantInversionFeedforward.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/LinearPlantInversionFeedforward.h",
            tmpl_class_names = [
                ("LinearPlantInversionFeedforward_tmpl1", "LinearPlantInversionFeedforward_1_1"),
                ("LinearPlantInversionFeedforward_tmpl2", "LinearPlantInversionFeedforward_2_1"),
                ("LinearPlantInversionFeedforward_tmpl3", "LinearPlantInversionFeedforward_2_2"),
                ("LinearPlantInversionFeedforward_tmpl4", "LinearPlantInversionFeedforward_3_2"),
            ],
            trampolines = [
                ("frc::LinearPlantInversionFeedforward", "frc__LinearPlantInversionFeedforward.hpp"),
            ],
        ),
        struct(
            class_name = "LinearQuadraticRegulator",
            yml_file = "semiwrap/controls/LinearQuadraticRegulator.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/LinearQuadraticRegulator.h",
            tmpl_class_names = [
                ("LinearQuadraticRegulator_tmpl1", "LinearQuadraticRegulator_1_1"),
                ("LinearQuadraticRegulator_tmpl2", "LinearQuadraticRegulator_2_1"),
                ("LinearQuadraticRegulator_tmpl3", "LinearQuadraticRegulator_2_2"),
                ("LinearQuadraticRegulator_tmpl4", "LinearQuadraticRegulator_3_2"),
            ],
            trampolines = [
                ("frc::LinearQuadraticRegulator", "frc__LinearQuadraticRegulator.hpp"),
            ],
        ),
        struct(
            class_name = "PIDController",
            yml_file = "semiwrap/controls/PIDController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/PIDController.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PIDController", "frc__PIDController.hpp"),
            ],
        ),
        struct(
            class_name = "ProfiledPIDController",
            yml_file = "semiwrap/controls/ProfiledPIDController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/ProfiledPIDController.h",
            tmpl_class_names = [
                ("ProfiledPIDController_tmpl1", "ProfiledPIDController"),
                ("ProfiledPIDController_tmpl2", "ProfiledPIDControllerRadians"),
            ],
            trampolines = [
                ("frc::ProfiledPIDController", "frc__ProfiledPIDController.hpp"),
            ],
        ),
        struct(
            class_name = "RamseteController",
            yml_file = "semiwrap/controls/RamseteController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/RamseteController.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::RamseteController", "frc__RamseteController.hpp"),
            ],
        ),
        struct(
            class_name = "SimpleMotorFeedforward",
            yml_file = "semiwrap/controls/SimpleMotorFeedforward.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/controller/SimpleMotorFeedforward.h",
            tmpl_class_names = [
                ("SimpleMotorFeedforward_tmpl1", "SimpleMotorFeedforwardMeters"),
                ("SimpleMotorFeedforward_tmpl2", "SimpleMotorFeedforwardRadians"),
            ],
            trampolines = [
                ("frc::SimpleMotorFeedforward", "frc__SimpleMotorFeedforward.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDrivePoseEstimator",
            yml_file = "semiwrap/controls/DifferentialDrivePoseEstimator.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/estimator/DifferentialDrivePoseEstimator.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDrivePoseEstimator", "frc__DifferentialDrivePoseEstimator.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDrivePoseEstimator3d",
            yml_file = "semiwrap/controls/DifferentialDrivePoseEstimator3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/estimator/DifferentialDrivePoseEstimator3d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDrivePoseEstimator3d", "frc__DifferentialDrivePoseEstimator3d.hpp"),
            ],
        ),
        struct(
            class_name = "ExtendedKalmanFilter",
            yml_file = "semiwrap/controls/ExtendedKalmanFilter.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/estimator/ExtendedKalmanFilter.h",
            tmpl_class_names = [
                ("ExtendedKalmanFilter_tmpl1", "ExtendedKalmanFilter_1_1_1"),
                ("ExtendedKalmanFilter_tmpl2", "ExtendedKalmanFilter_2_1_1"),
                ("ExtendedKalmanFilter_tmpl3", "ExtendedKalmanFilter_2_1_2"),
                ("ExtendedKalmanFilter_tmpl4", "ExtendedKalmanFilter_2_2_2"),
            ],
            trampolines = [
                ("frc::ExtendedKalmanFilter", "frc__ExtendedKalmanFilter.hpp"),
            ],
        ),
        struct(
            class_name = "KalmanFilter",
            yml_file = "semiwrap/controls/KalmanFilter.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/estimator/KalmanFilter.h",
            tmpl_class_names = [
                ("KalmanFilter_tmpl1", "KalmanFilter_1_1_1"),
                ("KalmanFilter_tmpl2", "KalmanFilter_2_1_1"),
                ("KalmanFilter_tmpl3", "KalmanFilter_2_1_2"),
                ("KalmanFilter_tmpl4", "KalmanFilter_2_2_2"),
                ("KalmanFilter_tmpl5", "KalmanFilter_3_2_3"),
            ],
            trampolines = [
                ("frc::KalmanFilter", "frc__KalmanFilter.hpp"),
            ],
        ),
        struct(
            class_name = "MecanumDrivePoseEstimator",
            yml_file = "semiwrap/controls/MecanumDrivePoseEstimator.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/estimator/MecanumDrivePoseEstimator.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MecanumDrivePoseEstimator", "frc__MecanumDrivePoseEstimator.hpp"),
            ],
        ),
        struct(
            class_name = "MecanumDrivePoseEstimator3d",
            yml_file = "semiwrap/controls/MecanumDrivePoseEstimator3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/estimator/MecanumDrivePoseEstimator3d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MecanumDrivePoseEstimator3d", "frc__MecanumDrivePoseEstimator3d.hpp"),
            ],
        ),
        struct(
            class_name = "PoseEstimator",
            yml_file = "semiwrap/controls/PoseEstimator.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/estimator/PoseEstimator.h",
            tmpl_class_names = [
                ("PoseEstimator_tmpl1", "DifferentialDrivePoseEstimatorBase"),
                ("PoseEstimator_tmpl2", "MecanumDrivePoseEstimatorBase"),
                ("PoseEstimator_tmpl3", "SwerveDrive2PoseEstimatorBase"),
                ("PoseEstimator_tmpl4", "SwerveDrive3PoseEstimatorBase"),
                ("PoseEstimator_tmpl5", "SwerveDrive4PoseEstimatorBase"),
                ("PoseEstimator_tmpl6", "SwerveDrive6PoseEstimatorBase"),
            ],
            trampolines = [
                ("frc::PoseEstimator", "frc__PoseEstimator.hpp"),
            ],
        ),
        struct(
            class_name = "PoseEstimator3d",
            yml_file = "semiwrap/controls/PoseEstimator3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/estimator/PoseEstimator3d.h",
            tmpl_class_names = [
                ("PoseEstimator3d_tmpl1", "DifferentialDrivePoseEstimator3dBase"),
                ("PoseEstimator3d_tmpl2", "MecanumDrivePoseEstimator3dBase"),
                ("PoseEstimator3d_tmpl3", "SwerveDrive2PoseEstimator3dBase"),
                ("PoseEstimator3d_tmpl4", "SwerveDrive3PoseEstimator3dBase"),
                ("PoseEstimator3d_tmpl5", "SwerveDrive4PoseEstimator3dBase"),
                ("PoseEstimator3d_tmpl6", "SwerveDrive6PoseEstimator3dBase"),
            ],
            trampolines = [
                ("frc::PoseEstimator3d", "frc__PoseEstimator3d.hpp"),
            ],
        ),
        struct(
            class_name = "SwerveDrivePoseEstimator",
            yml_file = "semiwrap/controls/SwerveDrivePoseEstimator.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/estimator/SwerveDrivePoseEstimator.h",
            tmpl_class_names = [
                ("SwerveDrivePoseEstimator_tmpl1", "SwerveDrive2PoseEstimator"),
                ("SwerveDrivePoseEstimator_tmpl2", "SwerveDrive3PoseEstimator"),
                ("SwerveDrivePoseEstimator_tmpl3", "SwerveDrive4PoseEstimator"),
                ("SwerveDrivePoseEstimator_tmpl4", "SwerveDrive6PoseEstimator"),
            ],
            trampolines = [
                ("frc::SwerveDrivePoseEstimator", "frc__SwerveDrivePoseEstimator.hpp"),
            ],
        ),
        struct(
            class_name = "SwerveDrivePoseEstimator3d",
            yml_file = "semiwrap/controls/SwerveDrivePoseEstimator3d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/estimator/SwerveDrivePoseEstimator3d.h",
            tmpl_class_names = [
                ("SwerveDrivePoseEstimator3d_tmpl1", "SwerveDrive2PoseEstimator3d"),
                ("SwerveDrivePoseEstimator3d_tmpl2", "SwerveDrive3PoseEstimator3d"),
                ("SwerveDrivePoseEstimator3d_tmpl3", "SwerveDrive4PoseEstimator3d"),
                ("SwerveDrivePoseEstimator3d_tmpl4", "SwerveDrive6PoseEstimator3d"),
            ],
            trampolines = [
                ("frc::SwerveDrivePoseEstimator3d", "frc__SwerveDrivePoseEstimator3d.hpp"),
            ],
        ),
        struct(
            class_name = "SimulatedAnnealing",
            yml_file = "semiwrap/controls/SimulatedAnnealing.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/optimization/SimulatedAnnealing.h",
            tmpl_class_names = [
                ("SimulatedAnnealing_tmpl1", "SimulatedAnnealing"),
            ],
            trampolines = [
                ("frc::SimulatedAnnealing", "frc__SimulatedAnnealing.hpp"),
            ],
        ),
        struct(
            class_name = "TravelingSalesman",
            yml_file = "semiwrap/controls/TravelingSalesman.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/path/TravelingSalesman.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::TravelingSalesman", "frc__TravelingSalesman.hpp"),
            ],
        ),
        struct(
            class_name = "LinearSystem",
            yml_file = "semiwrap/controls/LinearSystem.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/system/LinearSystem.h",
            tmpl_class_names = [
                ("LinearSystem_tmpl1", "LinearSystem_1_1_1"),
                ("LinearSystem_tmpl2", "LinearSystem_1_1_2"),
                ("LinearSystem_tmpl3", "LinearSystem_1_1_3"),
                ("LinearSystem_tmpl4", "LinearSystem_2_1_1"),
                ("LinearSystem_tmpl5", "LinearSystem_2_1_2"),
                ("LinearSystem_tmpl6", "LinearSystem_2_1_3"),
                ("LinearSystem_tmpl7", "LinearSystem_2_2_1"),
                ("LinearSystem_tmpl8", "LinearSystem_2_2_2"),
                ("LinearSystem_tmpl9", "LinearSystem_2_2_3"),
                ("LinearSystem_tmpl10", "LinearSystem_3_2_1"),
                ("LinearSystem_tmpl11", "LinearSystem_3_2_2"),
                ("LinearSystem_tmpl12", "LinearSystem_3_2_3"),
            ],
            trampolines = [
                ("frc::LinearSystem", "frc__LinearSystem.hpp"),
            ],
        ),
        struct(
            class_name = "LinearSystemLoop",
            yml_file = "semiwrap/controls/LinearSystemLoop.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/system/LinearSystemLoop.h",
            tmpl_class_names = [
                ("LinearSystemLoop_tmpl1", "LinearSystemLoop_1_1_1"),
                ("LinearSystemLoop_tmpl2", "LinearSystemLoop_2_1_1"),
                ("LinearSystemLoop_tmpl3", "LinearSystemLoop_2_1_2"),
                ("LinearSystemLoop_tmpl4", "LinearSystemLoop_2_2_2"),
                ("LinearSystemLoop_tmpl5", "LinearSystemLoop_3_2_3"),
            ],
            trampolines = [
                ("frc::LinearSystemLoop", "frc__LinearSystemLoop.hpp"),
            ],
        ),
        struct(
            class_name = "DCMotor",
            yml_file = "semiwrap/controls/DCMotor.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/system/plant/DCMotor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DCMotor", "frc__DCMotor.hpp"),
            ],
        ),
        struct(
            class_name = "LinearSystemId",
            yml_file = "semiwrap/controls/LinearSystemId.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/system/plant/LinearSystemId.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::LinearSystemId", "frc__LinearSystemId.hpp"),
            ],
        ),
        struct(
            class_name = "ExponentialProfile",
            yml_file = "semiwrap/controls/ExponentialProfile.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/ExponentialProfile.h",
            tmpl_class_names = [
                ("ExponentialProfile_tmpl1", "ExponentialProfileMeterVolts"),
            ],
            trampolines = [
                ("frc::ExponentialProfile", "frc__ExponentialProfile.hpp"),
                ("frc::ExponentialProfile::Constraints", "frc__ExponentialProfile__Constraints.hpp"),
                ("frc::ExponentialProfile::State", "frc__ExponentialProfile__State.hpp"),
                ("frc::ExponentialProfile::ProfileTiming", "frc__ExponentialProfile__ProfileTiming.hpp"),
            ],
        ),
        struct(
            class_name = "Trajectory",
            yml_file = "semiwrap/controls/Trajectory.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/Trajectory.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Trajectory", "frc__Trajectory.hpp"),
                ("frc::Trajectory::State", "frc__Trajectory__State.hpp"),
            ],
        ),
        struct(
            class_name = "TrajectoryConfig",
            yml_file = "semiwrap/controls/TrajectoryConfig.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/TrajectoryConfig.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::TrajectoryConfig", "frc__TrajectoryConfig.hpp"),
            ],
        ),
        struct(
            class_name = "TrajectoryGenerator",
            yml_file = "semiwrap/controls/TrajectoryGenerator.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/TrajectoryGenerator.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::TrajectoryGenerator", "frc__TrajectoryGenerator.hpp"),
            ],
        ),
        struct(
            class_name = "TrajectoryParameterizer",
            yml_file = "semiwrap/controls/TrajectoryParameterizer.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/TrajectoryParameterizer.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::TrajectoryParameterizer", "frc__TrajectoryParameterizer.hpp"),
            ],
        ),
        struct(
            class_name = "TrajectoryUtil",
            yml_file = "semiwrap/controls/TrajectoryUtil.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/TrajectoryUtil.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::TrajectoryUtil", "frc__TrajectoryUtil.hpp"),
            ],
        ),
        struct(
            class_name = "TrapezoidProfile",
            yml_file = "semiwrap/controls/TrapezoidProfile.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/TrapezoidProfile.h",
            tmpl_class_names = [
                ("TrapezoidProfile_tmpl1", "TrapezoidProfile"),
                ("TrapezoidProfile_tmpl2", "TrapezoidProfileRadians"),
            ],
            trampolines = [
                ("frc::TrapezoidProfile", "frc__TrapezoidProfile.hpp"),
                ("frc::TrapezoidProfile::Constraints", "frc__TrapezoidProfile__Constraints.hpp"),
                ("frc::TrapezoidProfile::State", "frc__TrapezoidProfile__State.hpp"),
            ],
        ),
        struct(
            class_name = "CentripetalAccelerationConstraint",
            yml_file = "semiwrap/controls/CentripetalAccelerationConstraint.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/constraint/CentripetalAccelerationConstraint.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::CentripetalAccelerationConstraint", "frc__CentripetalAccelerationConstraint.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDriveKinematicsConstraint",
            yml_file = "semiwrap/controls/DifferentialDriveKinematicsConstraint.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDriveKinematicsConstraint", "frc__DifferentialDriveKinematicsConstraint.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDriveVoltageConstraint",
            yml_file = "semiwrap/controls/DifferentialDriveVoltageConstraint.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDriveVoltageConstraint", "frc__DifferentialDriveVoltageConstraint.hpp"),
            ],
        ),
        struct(
            class_name = "EllipticalRegionConstraint",
            yml_file = "semiwrap/controls/EllipticalRegionConstraint.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/constraint/EllipticalRegionConstraint.h",
            tmpl_class_names = [
                ("EllipticalRegionConstraint_tmpl1", "EllipticalRegionConstraint"),
            ],
            trampolines = [
                ("frc::EllipticalRegionConstraint", "frc__EllipticalRegionConstraint.hpp"),
            ],
        ),
        struct(
            class_name = "MaxVelocityConstraint",
            yml_file = "semiwrap/controls/MaxVelocityConstraint.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/constraint/MaxVelocityConstraint.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MaxVelocityConstraint", "frc__MaxVelocityConstraint.hpp"),
            ],
        ),
        struct(
            class_name = "MecanumDriveKinematicsConstraint",
            yml_file = "semiwrap/controls/MecanumDriveKinematicsConstraint.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/constraint/MecanumDriveKinematicsConstraint.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MecanumDriveKinematicsConstraint", "frc__MecanumDriveKinematicsConstraint.hpp"),
            ],
        ),
        struct(
            class_name = "RectangularRegionConstraint",
            yml_file = "semiwrap/controls/RectangularRegionConstraint.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/constraint/RectangularRegionConstraint.h",
            tmpl_class_names = [
                ("RectangularRegionConstraint_tmpl1", "RectangularRegionConstraint"),
            ],
            trampolines = [
                ("frc::RectangularRegionConstraint", "frc__RectangularRegionConstraint.hpp"),
            ],
        ),
        struct(
            class_name = "SwerveDriveKinematicsConstraint",
            yml_file = "semiwrap/controls/SwerveDriveKinematicsConstraint.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/constraint/SwerveDriveKinematicsConstraint.h",
            tmpl_class_names = [
                ("SwerveDriveKinematicsConstraint_tmpl1", "SwerveDrive2KinematicsConstraint"),
                ("SwerveDriveKinematicsConstraint_tmpl2", "SwerveDrive3KinematicsConstraint"),
                ("SwerveDriveKinematicsConstraint_tmpl3", "SwerveDrive4KinematicsConstraint"),
                ("SwerveDriveKinematicsConstraint_tmpl4", "SwerveDrive6KinematicsConstraint"),
            ],
            trampolines = [
                ("frc::SwerveDriveKinematicsConstraint", "frc__SwerveDriveKinematicsConstraint.hpp"),
            ],
        ),
        struct(
            class_name = "TrajectoryConstraint",
            yml_file = "semiwrap/controls/TrajectoryConstraint.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpimath", "wpimath") + "/frc/trajectory/constraint/TrajectoryConstraint.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::TrajectoryConstraint", "frc__TrajectoryConstraint.hpp"),
                ("frc::TrajectoryConstraint::MinMax", "frc__TrajectoryConstraint__MinMax.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpimath_controls.resolve_casters",
        caster_files = [":wpimath/wpimath-casters.pybind11.json"],
        caster_deps = [resolve_caster_file("wpiutil-casters")],
        casters_pkl_file = "wpimath_controls.casters.pkl",
        dep_file = "wpimath_controls.casters.d",
    )

    gen_libinit(
        name = "wpimath_controls.gen_lib_init",
        output_file = "wpimath/_controls/_init__controls.py",
        modules = ["native.wpimath._init_robotpy_native_wpimath", "wpimath._init__wpimath", "wpimath.geometry._init__geometry", "wpimath.kinematics._init__kinematics", "wpimath.spline._init__spline"],
    )

    gen_pkgconf(
        name = "wpimath_controls.gen_pkgconf",
        libinit_py = "wpimath._controls._init__controls",
        module_pkg_name = "wpimath._controls._controls",
        output_file = "wpimath_controls.pc",
        pkg_name = "wpimath_controls",
        install_path = "wpimath/_controls",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpimath_controls.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPIMATH_CONTROLS_HEADER_GEN],
        libname = "_controls",
        output_file = "semiwrap_init.wpimath._controls._controls.hpp",
    )

    run_header_gen(
        name = "wpimath_controls",
        casters_pickle = "wpimath_controls.casters.pkl",
        header_gen_config = WPIMATH_CONTROLS_HEADER_GEN,
        trampoline_subpath = "wpimath/_controls",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpimath_controls.generated_files",
        srcs = [
            "wpimath_controls.gen_modinit_hpp.gen",
            "wpimath_controls.header_gen_files",
            "wpimath_controls.gen_pkgconf",
            "wpimath_controls.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpimath_controls",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpimath_controls.generated_srcs"],
        semiwrap_header = [":wpimath_controls.gen_modinit_hpp"],
        deps = deps + [
            ":wpimath_controls.tmpl_hdrs",
            ":wpimath_controls.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    whl_filegroup(
        name = "wpimath_controls.wheel.trampoline_files",
        pattern = "wpimath/_controls/trampolines",
        whl = ":wpimath-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_controls.wheel.trampoline_hdrs",
        hdrs = [":wpimath_controls.wheel.trampoline_files"],
        includes = ["wpimath_controls.wheel.trampoline_files/wpimath/_controls"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath_controls.wheel.headers",
        deps = [
            ":wpimath_controls.wheel.trampoline_hdrs",
            ":wpimath-casters.wheel.headers",
            "//subprojects/robotpy-native-wpimath:wpimath",
            "//subprojects/robotpy-native-wpiutil:wpiutil",
            "//subprojects/robotpy-wpimath:wpimath.wheel.headers",
            "//subprojects/robotpy-wpimath:wpimath_geometry.wheel.headers",
            "//subprojects/robotpy-wpimath:wpimath_kinematics.wheel.headers",
            "//subprojects/robotpy-wpimath:wpimath_spline.wheel.headers",
            "//subprojects/robotpy-wpiutil:wpiutil.wheel.headers",
        ],
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    make_pyi(
        name = "wpimath_controls.make_pyi",
        extension_package = "wpimath._controls._controls",
        extension_library = "copy_wpimath_controls",
        interface_files = [
            "__init__.pyi",
            "constraint.pyi",
            "controller.pyi",
            "estimator.pyi",
            "optimization.pyi",
            "path.pyi",
            "plant.pyi",
            "system.pyi",
            "trajectory.pyi",
        ],
        init_pkgcfgs = [
            "wpimath/_init__wpimath.py",
            "wpimath/filter/_init__filter.py",
            "wpimath/geometry/_init__geometry.py",
            "wpimath/interpolation/_init__interpolation.py",
            "wpimath/kinematics/_init__kinematics.py",
            "wpimath/spline/_init__spline.py",
            "wpimath/_controls/_init__controls.py",
        ],
        init_packages = [
            "wpimath",
            "wpimath/filter",
            "wpimath/geometry",
            "wpimath/interpolation",
            "wpimath/kinematics",
            "wpimath/spline",
            "wpimath/_controls",
        ],
        install_path = "wpimath/_controls/_controls",
        python_deps = [
            local_pybind_library("//subprojects/robotpy-native-wpimath", "robotpy-native-wpimath"),
            local_pybind_library("//subprojects/robotpy-native-wpiutil", "robotpy-native-wpiutil"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ] + extra_pyi_deps,
        target_compatible_with = select({
            "//conditions:default": ["@platforms//:incompatible"],
        }),
        local_extension_deps = [
            ("wpimath/_wpimath", "copy_wpimath"),
            ("wpimath/filter/_filter", "copy_wpimath_filter"),
            ("wpimath/geometry/_geometry", "copy_wpimath_geometry"),
            ("wpimath/interpolation/_interpolation", "copy_wpimath_interpolation"),
            ("wpimath/kinematics/_kinematics", "copy_wpimath_kinematics"),
            ("wpimath/spline/_spline", "copy_wpimath_spline"),
        ],
    )

def publish_library_casters(typecasters_srcs):
    publish_casters(
        name = "publish_casters",
        caster_name = "wpimath-casters",
        output_json = "wpimath/wpimath-casters.pybind11.json",
        output_pc = "wpimath/wpimath-casters.pc",
        project_config = "pyproject.toml",
        typecasters_srcs = typecasters_srcs,
    )

    whl_filegroup(
        name = "wpimath-casters.wheel.header_files",
        pattern = "wpimath/_impl/src/.*.h$",
        whl = ":wpimath-wheel",
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

    cc_library(
        name = "wpimath-casters.wheel.headers",
        hdrs = [":wpimath-casters.wheel.header_files"],
        includes = ["wpimath-casters.wheel.header_files/wpimath/_impl/src", "wpimath-casters.wheel.header_files/wpimath/_impl/src/type_casters"],
        visibility = ["//visibility:public"],
        tags = ["manual"],
    )

def get_generated_data_files():
    copy_extension_library(
        name = "copy_wpimath",
        extension = "_wpimath",
        output_directory = "wpimath/",
    )
    copy_extension_library(
        name = "copy_wpimath_filter",
        extension = "_filter",
        output_directory = "wpimath/filter/",
    )
    copy_extension_library(
        name = "copy_wpimath_geometry",
        extension = "_geometry",
        output_directory = "wpimath/geometry/",
    )
    copy_extension_library(
        name = "copy_wpimath_interpolation",
        extension = "_interpolation",
        output_directory = "wpimath/interpolation/",
    )
    copy_extension_library(
        name = "copy_wpimath_kinematics",
        extension = "_kinematics",
        output_directory = "wpimath/kinematics/",
    )
    copy_extension_library(
        name = "copy_wpimath_spline",
        extension = "_spline",
        output_directory = "wpimath/spline/",
    )
    copy_extension_library(
        name = "copy_wpimath_controls",
        extension = "_controls",
        output_directory = "wpimath/_controls/",
    )

    native.filegroup(
        name = "wpimath.generated_data_files",
        srcs = [
            "wpimath/wpimath.pc",
            "wpimath/filter/wpimath_filter.pc",
            "wpimath/geometry/wpimath_geometry.pc",
            "wpimath/interpolation/wpimath_interpolation.pc",
            "wpimath/kinematics/wpimath_kinematics.pc",
            "wpimath/spline/wpimath_spline.pc",
            "wpimath/_controls/wpimath_controls.pc",
            "wpimath/wpimath-casters.pc",
            "wpimath/wpimath-casters.pybind11.json",
        ],
        tags = ["manual"],
    )

    return [
        ":wpimath.generated_data_files",
        ":copy_wpimath",
        ":copy_wpimath_filter",
        ":copy_wpimath_geometry",
        ":copy_wpimath_interpolation",
        ":copy_wpimath_kinematics",
        ":copy_wpimath_spline",
        ":copy_wpimath_controls",
        ":wpimath.trampoline_hdr_files",
        ":wpimath_filter.trampoline_hdr_files",
        ":wpimath_geometry.trampoline_hdr_files",
        ":wpimath_interpolation.trampoline_hdr_files",
        ":wpimath_kinematics.trampoline_hdr_files",
        ":wpimath_spline.trampoline_hdr_files",
        ":wpimath_controls.trampoline_hdr_files",
    ]

def libinit_files():
    return [
        "wpimath/_init__wpimath.py",
        "wpimath/filter/_init__filter.py",
        "wpimath/geometry/_init__geometry.py",
        "wpimath/interpolation/_init__interpolation.py",
        "wpimath/kinematics/_init__kinematics.py",
        "wpimath/spline/_init__spline.py",
        "wpimath/_controls/_init__controls.py",
    ]

def define_pybind_library(name, version, extra_entry_points = {}):
    native.filegroup(
        name = "wpimath.extra_pkg_files",
        srcs = native.glob(["wpimath/**"], exclude = ["wpimath/**/*.py"], allow_empty = True),
        tags = ["manual"],
    )

    native.filegroup(
        name = "pyi_files",
        srcs = select({
            "//conditions:default": [],
            # "//conditions:default": [
            #     ":wpimath.make_pyi",
            #     ":wpimath_filter.make_pyi",
            #     ":wpimath_geometry.make_pyi",
            #     ":wpimath_interpolation.make_pyi",
            #     ":wpimath_kinematics.make_pyi",
            #     ":wpimath_spline.make_pyi",
            #     ":wpimath_controls.make_pyi",
            # ],
        }),
        tags = ["manual"],
    )

    native.filegroup(
        name = "generated_files",
        srcs = [
            "wpimath.generated_files",
            "wpimath_filter.generated_files",
            "wpimath_geometry.generated_files",
            "wpimath_interpolation.generated_files",
            "wpimath_kinematics.generated_files",
            "wpimath_spline.generated_files",
            "wpimath_controls.generated_files",
        ],
        tags = ["manual"],
        visibility = ["//visibility:public"],
    )

    robotpy_library(
        name = name,
        srcs = native.glob(["wpimath/**/*.py"]) + libinit_files(),
        data = get_generated_data_files() + ["wpimath.extra_pkg_files", ":pyi_files"],
        imports = ["."],
        robotpy_wheel_deps = [
            local_pybind_library("//subprojects/robotpy-native-wpimath", "robotpy-native-wpimath"),
            local_pybind_library("//subprojects/robotpy-native-wpiutil", "robotpy-native-wpiutil"),
            local_pybind_library("//subprojects/robotpy-wpiutil", "wpiutil"),
        ],
        strip_path_prefixes = ["subprojects/robotpy-wpimath"],
        version = version,
        visibility = ["//visibility:public"],
        entry_points = {
            "pkg_config": [
                "wpimath-casters = wpimath",
                "wpimath = wpimath",
                "wpimath_filter = wpimath.filter",
                "wpimath_geometry = wpimath.geometry",
                "wpimath_interpolation = wpimath.interpolation",
                "wpimath_kinematics = wpimath.kinematics",
                "wpimath_spline = wpimath.spline",
                "wpimath_controls = wpimath._controls",
            ],
        }.update(extra_entry_points),
        package_name = "robotpy-wpimath",
        package_summary = "Binary wrapper for FRC WPIMath library",
        package_project_urls = {"Source code": "https://github.com/robotpy/mostrobotpy"},
        package_author_email = "RobotPy Development Team <robotpy@googlegroups.com>",
        package_requires = ["robotpy-native-wpimath==2025.3.2", "robotpy-wpiutil==2025.3.2.2"],
    )
