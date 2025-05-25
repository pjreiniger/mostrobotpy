load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")
load("@rules_python//python:defs.bzl", "py_library")

def create_pybind_library(
        name,
        extension_name = None,
        generated_srcs = [],
        extra_hdrs = [],
        extra_srcs = [],
        entry_point = [],
        deps = [],
        semiwrap_header = [],
        copts = [],
        includes = []):
    # srcs = [DAT_TO_CC_DIR + src + ".cpp" for src in dat_to_cc_srcs]
    pybind_library(
        name = "{}_pybind_library".format(name),
        srcs = generated_srcs + extra_srcs,
        hdrs = extra_hdrs,
        copts = copts + select({
            "@bazel_tools//src/conditions:darwin": [
                "-Wno-deprecated-declarations",
            ],
            "@bazel_tools//src/conditions:linux_x86_64": [
                "-Wno-attributes",
                "-Wno-unused-value",
                "-Wno-deprecated",
                "-Wno-deprecated-declarations",
                "-Wno-unused-parameter",
                "-Wno-redundant-move",
                "-Wno-unused-but-set-variable",
                "-Wno-unused-variable",
                "-Wno-pessimizing-move",
            ],
        }),
        deps = deps + [
            "//bazel_scripts/semiwrap_headers",
        ],
        includes = includes,
        visibility = ["//visibility:public"],
    )

    extension_name = extension_name or "_{}".format(name)
    pybind_extension(
        name = extension_name,
        srcs = entry_point,
        deps = [":{}_pybind_library".format(name)] + semiwrap_header,
        defines = ["RPYBUILD_MODULE_NAME={}".format(extension_name)],
        visibility = ["//visibility:private"],
        target_compatible_with = select({
            "//conditions:default": [],
        }),
        copts = copts + select({
            "@bazel_tools//src/conditions:darwin": [
            ],
            "@bazel_tools//src/conditions:linux_x86_64": [
                "-Wno-unused-parameter",
            ],
        }),
    )

def pybind_python_library(
        name,
        **kwargs):
    py_library(
        name = name,
        **kwargs
    )
