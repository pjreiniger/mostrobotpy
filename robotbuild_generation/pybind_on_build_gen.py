import argparse

from robotbuild_generation.load_project_config import (
    load_project_config,
)
from robotbuild_generation.pybind_gen_utils import Setup
from robotpy_build.wrapper import Wrapper
import os
import re
import shutil
import logging


def main(argv):
    parser = argparse.ArgumentParser()
    parser.add_argument("--config", required=True)
    parser.add_argument("--output_directory", required=True)
    parser.add_argument("--project_name", required=True)
    parser.add_argument("--keep_json_files", action="store_true")
    parser.add_argument("--internal_project_dependencies", nargs="+")
    args = parser.parse_args()
    args.keep_json_files = True

    intermediate_directory = args.output_directory + ".intermediate"

    setup = Setup(args.config, intermediate_directory, args.internal_project_dependencies)

    for wrapper in setup.wrappers:
        wrapper.on_build_gen(os.path.join(intermediate_directory, "pybind_gen"))

    project_name = args.project_name

    shutil.copytree(
        os.path.join(intermediate_directory, "pybind_gen"),
        os.path.join(args.output_directory, "gensrc"),
    )

    rpy_include_output_dir = os.path.join(
        args.output_directory, f"rpy-include/{project_name}"
    )

    if "apriltag" in project_name:
        shutil.copytree(
            os.path.join(intermediate_directory, f"robotpy_apriltag"),
            rpy_include_output_dir,
        )
    else:
        shutil.copytree(
            os.path.join(intermediate_directory, f"{project_name}"),
            rpy_include_output_dir,
        )

    logging.info("Copying CPP files to src directory")
    for root, _, files in os.walk(rpy_include_output_dir):
        for f in files:
            if f.endswith(".cpp"):
                re_pattern = f"rpy-include/{project_name}(/.*)/rpy-include"
                xxxx = re.search(re_pattern, root)
                logging.info(root, f)
                if xxxx:
                    subfolder = xxxx[1]
                    actual_directory = os.path.join(
                        args.output_directory,
                        "gensrc",
                        project_name + "_" + subfolder[1:].replace("_", ""),
                    )
                    if project_name == "wpilib" and subfolder == "/shuffleboard":
                        actual_directory = os.path.join(
                            args.output_directory,
                            "gensrc",
                            project_name + "c_" + subfolder[1:].replace("_", ""),
                        )
                    if project_name == "wpilib" and subfolder == "/simulation":
                        actual_directory = os.path.join(
                            args.output_directory,
                            "gensrc",
                            project_name + "c_" + subfolder[1:].replace("_", ""),
                        )

                    if not os.path.exists(actual_directory):
                        os.makedirs(actual_directory)
                    logging.info("Got a match...", subfolder)
                    logging.info("  Putting in ", actual_directory)
                    shutil.move(os.path.join(root, f), actual_directory)
                elif project_name == "wpilib":
                    shutil.move(
                        os.path.join(root, f),
                        os.path.join(
                            args.output_directory, "gensrc", project_name + "_core"
                        ),
                    )
                else:
                    logging.info("  No regex, doing normal copy")

                    shutil.move(
                        os.path.join(root, f),
                        os.path.join(args.output_directory, "gensrc", project_name),
                    )

    if not args.keep_json_files:
        for root, _, files in os.walk(os.path.join(args.output_directory, "gensrc")):
            for f in files:
                if f.endswith(".json"):
                    os.remove(os.path.join(root, f))


if __name__ == "__main__":
    main(sys.argv[1:])
