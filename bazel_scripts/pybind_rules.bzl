load("@pybind11_bazel//:build_defs.bzl", "pybind_extension", "pybind_library")
load("@rules_pycross//pycross/private:wheel_library.bzl", "pycross_wheel_library")
load("@rules_python//python:defs.bzl", "py_library")
load("@rules_python//python:packaging.bzl", "py_wheel")
load("//bazel_scripts:version.bzl", "VERSION")

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
        includes = [],
        local_defines = []):
    # srcs = [DAT_TO_CC_DIR + src + ".cpp" for src in dat_to_cc_srcs]
    pybind_library(
        name = "{}_pybind_library".format(name),
        srcs = generated_srcs + extra_srcs,
        hdrs = extra_hdrs,
        copts = copts + select({
            "@bazel_tools//src/conditions:darwin": [
                "-Wno-deprecated-declarations",
                "-Wno-overloaded-virtual",
                "-Wno-pessimizing-move",
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
            "@bazel_tools//src/conditions:windows": [
            ],
        }),
        deps = deps + [
            "//bazel_scripts/semiwrap_headers",
        ],
        includes = includes,
        visibility = ["//visibility:public"],
        local_defines = local_defines,
    )

    extension_name = extension_name or "_{}".format(name)
    pybind_extension(
        name = extension_name,
        srcs = entry_point,
        deps = [":{}_pybind_library".format(name)] + semiwrap_header,
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
            "@bazel_tools//src/conditions:windows": [
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

def robotpy_library(
        name,
        package_name,
        strip_path_prefixes,
        data = [],
        robotpy_wheel_deps = [],
        visibility = None,
        **kwargs):
    py_library(
        name = name,
        visibility = None,
        data = data,
        **kwargs
    )

    py_wheel(
        name = "{}-wheel".format(name),
        distribution = package_name,
        platform = select({
            "@bazel_tools//src/conditions:darwin": "win_amd64",
            "@bazel_tools//src/conditions:windows": "macosx_11_0_x86_64",
            "//conditions:default": "manylinux_2_35_x86_64",
        }),
        python_tag = "py3",
        stamp = 1,
        version = VERSION,
        deps = data + [":{}".format(name)],
        strip_path_prefixes = strip_path_prefixes,
    )

    pycross_wheel_library(
        name = "import",
        wheel = "{}-wheel".format(name),
        deps = robotpy_wheel_deps,
        visibility = visibility,
    )
