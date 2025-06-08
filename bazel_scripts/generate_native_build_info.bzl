load("@aspect_bazel_lib//lib:write_source_files.bzl", "write_source_files")

def generate_native_build_info(name, pyproject_toml = "pyproject.toml"):
    cmd = "$(location @rules_semiwrap//rules_semiwrap/tools:generate_nativelib_build_file) --pyproject=$(location " + pyproject_toml + ") --output_file=$(OUTS)"

    native.genrule(
        name = "{}.gen_build_info".format(name),
        tools = ["@rules_semiwrap//rules_semiwrap/tools:generate_nativelib_build_file"],
        srcs = [pyproject_toml],
        outs = ["_generated_build_info.bzl"],
        cmd = cmd,
    )

    write_source_files(
        name = "{}.generate_build_info".format(name),
        files = {
            "generated_build_info.bzl": "{}.gen_build_info".format(name),
        },
        visibility = ["//visibility:public"],
    )
