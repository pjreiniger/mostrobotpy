import os
import pathlib
import shutil
import tempfile
import time

# DUMP_DIR = "/home/pjreiniger/git/robotpy/temp_gen_results"
DUMP_DIR = "__genresults"


def copy_directory_stuff(magic_dir, overwrite_existing=True):

    ignored_files = set(
        [
            ".gitignore",
            "BUILD.bazel",
            "build.ninja",
            "build.ninja~",
            # "generated_build_info.bzl",
            "README.md",
            # "compile_commands.json",
            "PKG-INFO",
            "pyproject.toml",
            "hatch-meson-native-file.ini",
            "meson.lock",
            # ".ninja_deps",
            # ".ninja_logs",
        ]
    )

    for root, dirs, files in os.walk(magic_dir):
        for file in files:
            source_file = os.path.join(root, file)
            if (
                file.endswith(".o")
                or file.endswith(".obj")
                or file.endswith(".pdb")
                or file.endswith(".a")
                or file.endswith(".so")
                or file.endswith(".dylib")
                or file.endswith(".pyd")
                or file.endswith(".exe")
                or file.endswith(".dat")
                or file.endswith(".d")
                or file.endswith(".pkl")
                or file.endswith(".yml")
                or file.endswith(".exe")
                or file.endswith(".whl")
                or file.endswith(".pyc")
                or file.endswith("Zone.Identifier")
                # or "meson-info" in root
                # or "meson-logs" in root
                # or "meson-private" in root
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


class StupidThread:
    def __init__(self):
        self.running_build = True

    def loop_copy_files(self):
        return
        search_base = tempfile.gettempdir()

        print("-" * 80)
        print(f"Running search on {search_base}")
        print("-" * 80)
        magic_dir = None
        while self.running_build and not magic_dir:
            for ddd in os.listdir(search_base):
                if "build-via-sdist" in ddd:
                    magic_dir = search_base + "/" + ddd
                    break

            time.sleep(0.01)

        print("-" * 80)
        print("Got the magic dir", magic_dir)
        print("-" * 80)
        
        while self.running_build:
            debug_print = "-" * 80
            debug_print += "ran loop"
            time.sleep(0.1)

            copy_directory_stuff(magic_dir, False)


def search_copy_delete():
    ttttddddd = tempfile.gettempdir()
    
    for x in os.listdir(ttttddddd):
        if "build-via-sdist" in x:
            magic_directory = os.path.join(ttttddddd, x)
            print(f"--Found one... {magic_directory}")
            copy_directory_stuff(magic_directory)
            shutil.rmtree(magic_directory)