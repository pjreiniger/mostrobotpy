
import argparse
import re
import os
import subprocess
import json


def update_rdev(wpilib_bin_version: str, artifactory_subfolder: str):
    with open("rdev.toml") as f:
        contents = f.read()

    contents = re.sub('wpilib_bin_version = ".*"', f'wpilib_bin_version = "{wpilib_bin_version}"', contents)
    contents = re.sub('wpilib_bin_url = ".*"', f'wpilib_bin_url = "https://frcmaven.wpi.edu/artifactory/{artifactory_subfolder}"', contents)
    
    
    with open("rdev.toml", 'w') as f:
        f.write(contents)

    subprocess.check_call(["./rdev.sh", "update-pyproject", "--commit"])


def run_copybara(git_repo_path, method, copybara_config):

    args = [
        "bazel",
        "run",
        "//:copybara",
        "--",
        "migrate",
        os.path.join(git_repo_path, "copy.bara.sky"),
        "allwpilib_to_mostrobotpy_" + method,
        "--force",
    ]

    destination_args = []
    
    if method == "pr_upstream":
        destination_args.extend([
            "--git-destination-url",
            copybara_config['mostrobotpy_truth_repo'],
        ])
    elif method == "push_fork":
        destination_args.extend([
            "--git-destination-url",
            copybara_config['mostrobotpy_fork_repo'],
        ])
    elif method == "local":
        destination_args.extend([
            "--git-destination-url",
            copybara_config["mostrobotpy_local_repo_path"],
        ])


    
    args.extend(destination_args)
    print(" ".join(args))
    subprocess.check_call(args)
    

def main():
    user_config_file = ".copybara.json"
    if os.path.exists(user_config_file):
        print(f"Loading user config from '{user_config_file}'")
        with open(user_config_file, 'r') as f:
            copybara_config = json.load(f)
    else:
        print(f"No user config present at '{user_config_file}', no defaults will be loaded")

    this_dir = "/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy"

    parser = argparse.ArgumentParser()
    # parser.add_argument("--download_copybara", action="store_true", help="If set, will download a version of the copybara binary")
    parser.add_argument("--wpilib_bin_version", required=True, help="The wpilib release version as hosted on artifactory")
    parser.add_argument("--development_build", action="store_true", help="True if you are upgrading to a development build instead of a release build. Affects where artifacts will be downloaded from.")
    parser.add_argument(
        "--method",
        required=True,
        choices=["local", "pr_upstream"],
        help="""Destination for the copybara script. 
        - 'local' will create a new commit in your local repository
        - 'fork' will push a commit to your fork
        """
    )
    args = parser.parse_args()


    # update_rdev(args.wpilib_bin_version, args.artifactory_subfolder)
    run_copybara(this_dir, args.method, copybara_config)


if __name__ == "__main__":
    main()
