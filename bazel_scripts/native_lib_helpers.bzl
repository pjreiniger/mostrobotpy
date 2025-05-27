
load("@rules_python//python:packaging.bzl", "py_package", "py_wheel")
load("//bazel_scripts:copy_native_file.bzl", "copy_native_file")
load("//bazel_scripts:hatch_nativelib_helpers.bzl", "gen_libinit")
load("//bazel_scripts:pybind_rules.bzl", "pybind_python_library")


def create_native_library(
    name,
    lib_name,
    package_name,
    shared_library,
    module_dependencies,
    strip_pkg_prefix,
    visibility = ["//visibility:public"],
):
    gen_libinit(
        name = "{}.gen_lib_init".format(name),
        lib_name = lib_name,
        modules = module_dependencies,
        output_file = "native/{}/_init_{}.py".format(lib_name, package_name.replace("-", "_")),
    )
    print("native/{}/_init_{}.py".format(lib_name, package_name))

    copy_native_file(
        name = lib_name,
        base_path = "native/{}/".format(lib_name),
        library = shared_library,
    )

    native.py_library(
        name = package_name,
        srcs = ["{}.gen_lib_init".format(name)],
        data = [":{}.copy_lib".format(lib_name)],
        imports = ["."],
        visibility = visibility,
    )
    
    py_package(
        name = "{}-pkg".format(package_name),
        # packages = ["examples.wheel"],
        deps = [":{}".format(package_name)],
    )
    
    py_wheel(
        name = "{}-wheel".format(package_name),
        distribution = package_name,
        platform = select({
            
            "@bazel_tools//src/conditions:darwin": "win_amd64",
            "@bazel_tools//src/conditions:windows": "macosx_11_0_x86_64",
            "//conditions:default": "manylinux_2_35_x86_64",
        }),
        python_tag = "py3",
        stamp = 1,
        version = "0.0.0",
        deps = [":{}-pkg".format(package_name)],
        strip_path_prefixes = strip_pkg_prefix,
    )
