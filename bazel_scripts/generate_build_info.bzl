load("@aspect_bazel_lib//lib:write_source_files.bzl", "write_source_files")

def generate_build_info(name, pkgcfgs, local_libraries, yaml_files, pyproject_toml, header_packages = [], additional_srcs = []):
    cmd = "$(location @rules_semiwrap//rules_semiwrap/tools:generate_build_file) --project_file=$(location " + pyproject_toml + ") --output_file=$(OUTS)"
    if pkgcfgs:
        cmd += " --pkgcfgs "
        for x in pkgcfgs:
            cmd += " " + x

    native.genrule(
        name = "{}.gen_build_info".format(name),
        tools = ["@rules_semiwrap//rules_semiwrap/tools:generate_build_file"],
        srcs = local_libraries + [pyproject_toml] + yaml_files + header_packages + additional_srcs,
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
