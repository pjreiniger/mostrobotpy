load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")
load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_python//python:defs.bzl", "py_library")

def create_pybind_library(
        name,
        generation_helper_prefix,
        strip_include_prefix = None,
        includes = [],
        extra_srcs = [],
        extra_hdrs = [],
        deps = [],
        static_deps = [],
        entry_point = [],
        local_defines = [],
        extension_visibility = None,
        extension_name = None):
    extension_name = extension_name or "_{}".format(name)

    if generation_helper_prefix:
        rpy_include_libs = [generation_helper_prefix + "_rpy_includes"]
        generated_srcs = [generation_helper_prefix + "_generated_sources"]
        gensrc_headers = [generation_helper_prefix + "_gensrc_headers"]
    else:
        rpy_include_libs = []
        generated_srcs = []
        gensrc_headers = []

    pybind_library(
        name = "{}_pybind_library".format(name),
        srcs = generated_srcs + extra_srcs,
        hdrs = extra_hdrs,
        deps = deps + static_deps + rpy_include_libs + gensrc_headers + [
            "//rules_robotpy_utils/include:robotpy_includes",
        ],
        copts = select({
            "@bazel_tools//src/conditions:darwin": [
                "-Wno-delete-abstract-non-virtual-dtor",
                "-Wno-delete-non-abstract-non-virtual-dtor",
                "-Wno-deprecated-declarations",
                "-Wno-overloaded-virtual",
                "-Wno-pessimizing-move",
                "-Wno-sign-compare",
                "-Wno-unused-value",
                "-Wno-unused-variable",
            ],
            "@bazel_tools//src/conditions:windows": [
                "/wd4407",
                "/wd4101",
            ],
            "@rules_bzlmodrio_toolchains//constraints/combined:is_linux": [
                "-Wno-attributes",
                "-Wno-deprecated",
                "-Wno-deprecated-declarations",
                "-Wno-redundant-move",
                "-Wno-sign-compare",
                "-Wno-unused-but-set-variable",
                "-Wno-unused-value",
                "-Wno-unused-variable",
            ],
        }),
        target_compatible_with = select({
            "@rules_bzlmodrio_toolchains//constraints/is_bullseye32:bullseye32": ["@platforms//:incompatible"],
            "@rules_bzlmodrio_toolchains//constraints/is_bullseye64:bullseye64": ["@platforms//:incompatible"],
            "@rules_bzlmodrio_toolchains//constraints/is_raspi32:raspi32": ["@platforms//:incompatible"],
            "@rules_bzlmodrio_toolchains//constraints/is_roborio:roborio": ["@platforms//:incompatible"],
            "//conditions:default": [],
        }),
        local_defines = local_defines + ["RPYBUILD_MODULE_NAME=_{}".format(name), "PYBIND11_DETAILED_ERROR_MESSAGES=1"],
        defines = ["PYBIND11_USE_SMART_HOLDER_AS_DEFAULT=1"],
        strip_include_prefix = strip_include_prefix,
        includes = includes,
        visibility = ["//visibility:public"],
        tags = [
            "no-bullseye",
            "no-raspi",
            "no-roborio",
        ],
    )

    pybind_extension(
        name = extension_name,
        srcs = entry_point,
        deps = gensrc_headers + [":{}_pybind_library".format(name)] + static_deps,
        defines = ["RPYBUILD_MODULE_NAME={}".format(extension_name)],
        visibility = ["//visibility:private"],
        target_compatible_with = select({
            "@rules_bzlmodrio_toolchains//constraints/is_bullseye32:bullseye32": ["@platforms//:incompatible"],
            "@rules_bzlmodrio_toolchains//constraints/is_bullseye64:bullseye64": ["@platforms//:incompatible"],
            "@rules_bzlmodrio_toolchains//constraints/is_raspi32:raspi32": ["@platforms//:incompatible"],
            "@rules_bzlmodrio_toolchains//constraints/is_roborio:roborio": ["@platforms//:incompatible"],
            "//conditions:default": [],
        }),
        tags = [
            "no-bullseye",
            "no-raspi",
            "no-roborio",
        ],
    )

    # TODO this is now redundant
    native.alias(
        name = name + ".pyso",
        actual = extension_name,
        visibility = extension_visibility,
    )

def generated_files_helper(
        name,
        visibility = None,
        rpy_include_dir = None):
    rpy_include_dir = rpy_include_dir or "generated/rpy-include/{}/rpy-include".format(name)

    cc_library(
        name = "{}_gensrc_headers".format(name),
        srcs = native.glob(["generated/gensrc/{}/**/*.hpp".format(name)]),
        includes = ["generated/gensrc/{}".format(name)],
        visibility = visibility,
    )

    native.filegroup(
        name = "{}_generated_sources".format(name),
        srcs = native.glob(["generated/gensrc/{}/**/*.cpp".format(name)]),
        visibility = visibility,
    )

    cc_library(
        name = "{}_rpy_includes".format(name),
        hdrs = native.glob([rpy_include_dir + "/rpygen/*.hpp".format(name)]),
        strip_include_prefix = rpy_include_dir,
        visibility = visibility,
    )

def pybind_python_library(name, tags = [], **kwargs):
    py_library(
        name = name,
        tags = tags + [
            "no-bullseye",
            "no-raspi",
            "no-roborio",
        ],
        target_compatible_with = select({
            "@rules_bzlmodrio_toolchains//constraints/is_bullseye32:bullseye32": ["@platforms//:incompatible"],
            "@rules_bzlmodrio_toolchains//constraints/is_bullseye64:bullseye64": ["@platforms//:incompatible"],
            "@rules_bzlmodrio_toolchains//constraints/is_raspi32:raspi32": ["@platforms//:incompatible"],
            "@rules_bzlmodrio_toolchains//constraints/is_roborio:roborio": ["@platforms//:incompatible"],
            "//conditions:default": [],
        }),
        **kwargs
    )
