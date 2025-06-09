load("@aspect_bazel_lib//lib:write_source_files.bzl", "write_source_files")

def generate_build_info(name, yaml_files, pyproject_toml, local_pkgcfgs = [], header_packages = [], additional_srcs = []):
    cmd = "$(location @rules_semiwrap//rules_semiwrap/tools:generate_build_file) --project_file=$(location " + pyproject_toml + ") --output_file=$(OUTS)"

    local_deps = []

    if local_pkgcfgs:
        cmd += " --pkgcfgs "

        for subproject_label, pc_files in local_pkgcfgs:
            local_deps.append(subproject_label)
            for pc_file in pc_files:
                cmd += " " + pc_file

    native.genrule(
        name = "{}.gen_build_info".format(name),
        tools = ["@rules_semiwrap//rules_semiwrap/tools:generate_build_file"],
        srcs = local_deps + [pyproject_toml] + yaml_files + header_packages + additional_srcs,
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
