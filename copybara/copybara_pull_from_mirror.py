
import argparse
import re
import os
import subprocess
import json
from config import CopybaraConfig


def update_rdev(wpilib_bin_version: str, is_development_build: bool):
    with open("rdev.toml") as f:
        contents = f.read()

    artifactory_path = "https://frcmaven.wpi.edu/artifactory/"
    if is_development_build:
        artifactory_path += "development-2027"
    else:
        artifactory_path += "release-2027"

    contents = re.sub('wpilib_bin_version = ".*"', f'wpilib_bin_version = "{wpilib_bin_version}"', contents)
    contents = re.sub('wpilib_bin_url = ".*"', f'wpilib_bin_url = "{artifactory_path}"', contents)
    
    
    with open("rdev.toml", 'w') as f:
        f.write(contents)

    subprocess.check_call(["./rdev.sh", "update-pyproject", "--commit"])


def run_copybara(git_repo_path, method, mostrobotpy_truth_repo, mostrobotpy_fork_repo, mostrobotpy_local_repo_path):

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
            mostrobotpy_truth_repo,
        ])
    elif method == "push_fork":
        destination_args.extend([
            "--git-destination-url",
            mostrobotpy_fork_repo,
        ])
        destination_args.append("--git-destination-non-fast-forward")
    elif method == "local":
        destination_args.extend([
            "--git-destination-url",
            mostrobotpy_local_repo_path,
        ])


    
    args.extend(destination_args)
    print(" ".join(args))
    subprocess.check_call(args)
    

def checkout_branch(auto_delete_branch):
    ret = subprocess.call(["git", "rev-parse", "--verify", "copybara_allwpilib_to_mostrobotpy"])
    branch_exists = ret == 0
    if branch_exists:
        if not auto_delete_branch:
            ans = input("Delete local branch copybara_allwpilib_to_mostrobotpy?")
            if ans.lower() != "y":
                raise Execption("You must delete your local copy of copybara_allwpilib_to_mostrobotpy before the script can finish")

        subprocess.check_call(["git", "branch", "-D", "copybara_allwpilib_to_mostrobotpy"])

    subprocess.check_call(["git", "fetch", "--all"])
    subprocess.check_call(["git", "checkout", "copybara_allwpilib_to_mostrobotpy"])
    


def main():
    this_dir = "/home/pjreiniger/git/robotpy/robotpy_monorepo/mostrobotpy"

    parser = argparse.ArgumentParser()
    parser.add_argument("--wpilib_bin_version", required=True, help="The wpilib release version as hosted on artifactory")
    parser.add_argument("--development_build", action="store_true", help="True if you are upgrading to a development build instead of a release build. Affects where artifacts will be downloaded from.")
    parser.add_argument(
        "--method",
        required=True,
        choices=["local", "push_fork", "pr_upstream"],
        help="""Destination for the copybara script. 
        - 'local' will create a new commit in your local repository
        - 'fork' will push a commit to your fork
        """
    )
    parser.add_argument("-y", "--auto_delete_branch", action="store_true", help="If present, will automatically delete the local version of the copybara branch if it exists. Otherwise you will be prompted if it is ok to delete")
    CopybaraConfig.populate_argparse(parser)

    args = parser.parse_args()


    os.chdir(this_dir)


    run_copybara(this_dir, args.method, args.mostrobotpy_truth_repo, args.mostrobotpy_fork_repo, args.mostrobotpy_local_repo_path)
    checkout_branch(args.auto_delete_branch)
    update_rdev(args.wpilib_bin_version, args.development_build)
    subprocess.check_call(["git", "push", "-f"])


if __name__ == "__main__":
    main()
