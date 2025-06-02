load("@aspect_bazel_lib//lib:write_source_files.bzl", "write_source_files")


def generate_build_info(name, local_libraries, yaml_files, pyproject_toml):
    native.genrule(
        name = "{}.gen_build_info".format(name),
        tools = ["@rules_semiwrap//rules_semiwrap/tools:generate_build_file"],
        srcs = local_libraries + [pyproject_toml] + yaml_files,
        outs = ["_generated_build_info.bzl"],
        cmd = "$(location @rules_semiwrap//rules_semiwrap/tools:generate_build_file) --project_file=$(location " + pyproject_toml + ") --output_file=$(OUTS)",
    )

    write_source_files(
        name = "{}.generate_build_info".format(name),
        files = {
            "generated_build_info.bzl": "{}.gen_build_info".format(name),
        },
        visibility = ["//visibility:public"],
    )