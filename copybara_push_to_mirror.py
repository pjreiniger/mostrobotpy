
import argparse
import re
import os
import subprocess
import json

def run_copybara(git_repo_path, method, copybara_config):

    destination_args = []
    origin_args = []

    args = [
        "bazel",
        "run",
        "//:copybara",
        "--",
        "migrate",
        os.path.join(git_repo_path, "copy.bara.sky"),
        "mostrobotpy_to_allwpilib_" + method,
        "--force",
    ]

    if method == "pr_upstream":
        destination_args.extend([
            "--git-destination-url",
            copybara_config['allwpilib_mirror_repo'],
        ])
    elif method == "push_fork":
        destination_args.extend([
            "--git-destination-url",
            copybara_config['allwpilib_fork_repo'],
        ])
        destination_args.append("--git-destination-non-fast-forward")
    elif method == "local":
        destination_args.extend([
            "--git-destination-url",
            copybara_config["allwpilib_local_repo_path"],
        ])

    else:
        raise Exception(f"Unknown method: {method}")

    args.extend(destination_args)
    args.extend(origin_args)
    
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
    parser.add_argument(
        "--method",
        required=True,
        choices=["local", "push_fork", "pr_upstream"],
        help="""Destination for the copybara script. 
        - 'local' will create a new commit in your local repository
        - 'push_fork' will push a commit to your fork
        """
    )
    args = parser.parse_args()
    run_copybara(this_dir, args.method, copybara_config)


if __name__ == "__main__":
    main()
