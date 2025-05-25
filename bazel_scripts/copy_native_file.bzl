load("@aspect_bazel_lib//lib:copy_file.bzl", "copy_file")

def copy_native_file(name, library, base_path):
    copy_file(
        name = name + ".win_copy_lib",
        src = library,
        out = "lib/{}.dll".format(name),
        tags = ["manual"],
        visibility = ["//visibility:public"],
    )

    copy_file(
        name = name + ".osx_copy_lib",
        src = library,
        out = "lib/lib{}.dylib".format(name),
        tags = ["manual"],
        visibility = ["//visibility:public"],
    )

    copy_file(
        name = name + ".linux_copy_lib",
        src = library,
        out = "{}/lib/lib{}.so".format(base_path, name),
        tags = ["manual"],
        visibility = ["//visibility:public"],
    )

    native.alias(
        name = "{}.copy_lib".format(name),
        actual = select({
            "@bazel_tools//src/conditions:darwin": name + ".osx_copy_lib",
            # "@rules_bazelrio//conditions:windows": name + ".win_copy_lib",
            "//conditions:default": name + ".linux_copy_lib",
        }),
        visibility = ["//visibility:public"],
    )

def copy_extension_library(
        name,
        extension,
        output_directory):
    copy_file(
        name = name,
        src = extension,
        out = output_directory + extension + ".so",
        visibility = ["//visibility:public"],
    )
