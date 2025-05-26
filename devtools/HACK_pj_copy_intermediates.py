import os
import pathlib
import shutil

# DUMP_DIR = "/home/pjreiniger/git/robotpy/temp_gen_results"
DUMP_DIR = "__genresults"


def copy_directory_stuff(magic_dir, overwrite_existing=True):

    ignored_files = set(
        [
            ".gitignore",
            "BUILD.bazel",
            "build.ninja",
            "build.ninja~",
            "generated_build_info.bzl",
            "README.md",
            "compile_commands.json",
            "PKG-INFO",
            "pyproject.toml",
            "hatch-meson-native-file.ini",
            "meson.lock",
            ".ninja_deps",
            ".ninja_logs",
        ]
    )

    print("----------------------------------------------")
    print(f"Copying files from {magic_dir}")
    print("----------------------------------------------")

    for root, dirs, files in os.walk(magic_dir):
        for file in files:
            source_file = os.path.join(root, file)
            if (
                file.endswith(".o")
                or file.endswith(".so")
                or file.endswith(".a")
                or file.endswith(".dylib")
                or file.endswith(".exe")
                or file.endswith(".dat")
                or file.endswith(".d")
                or file.endswith(".pkl")
                or file.endswith(".yml")
                or file.endswith(".exe")
                or file.endswith(".pyc")
                or file.endswith("Zone.Identifier")
                or "meson-info" in root
                or "meson-logs" in root
                or "meson-private" in root
            ):
                continue
            elif file in ignored_files:
                continue
            # if file.endswith(".hpp") or file.endswith(".cpp") or file.endswith(".h") or file == "meson.build":
            else:
                dst_file = pathlib.Path(f"{DUMP_DIR}/" + source_file[len(magic_dir) :])
                dst_file.parent.mkdir(parents=True, exist_ok=True)

                try:
                    if not dst_file.exists():
                        shutil.copy(source_file, dst_file)
                    elif dst_file.exists() and overwrite_existing:
                        shutil.copy(source_file, dst_file)
                except Exception as e:
                    print(f"Failed to copy {source_file} - {e}")

    print(".... Done")
    print("----------------------------------------------")
