import os
import json
import argparse
import dataclasses
from typing import Optional

@dataclasses.dataclass
class CopybaraConfig:
    # Settings for migrating to a local repository
    mostrobotpy_local_repo_path: Optional[str] = None
    allwpilib_local_repo_path: Optional[str] = None

    # Settings for migrating to a fork that you own
    mostrobotpy_fork_repo: Optional[str] = None
    allwpilib_fork_repo: Optional[str] = None

    # Settings for truth repositories
    mostrobotpy_truth_repo: str = "https://github.com/robotpy/mostrobotpy.git"
    mostrobotpy_truth_branch: str = 2027

    allwpilib_truth_repo: str = "https://github.com/wpilibsuite/allwpilib.git"
    allwpilib_truth_branch: str = "2027"



    @staticmethod
    def populate_argparse(parser: argparse.ArgumentParser):
        
        user_config_file = ".copybara.json"
        if os.path.exists(user_config_file):
            print(f"Loading user config from '{user_config_file}'")
            with open(user_config_file, 'r') as f:
                json_config = json.load(f)
        else:
            print(f"No user config present at '{user_config_file}', no defaults will be loaded")
            json_config = {}

        user_config = CopybaraConfig(**json_config)
        
        group = parser.add_argument_group('Local Repo Settings')
        group.add_argument("--mostrobotpy_local_repo_path", default=user_config.mostrobotpy_local_repo_path, help="Path on your local computer to a mostrobotpy clone")
        group.add_argument("--allwpilib_local_repo_path", default=user_config.allwpilib_local_repo_path, help="Path on your local computer to a allwpilib clone")
        
        group = parser.add_argument_group('Fork Repo Settings')
        group.add_argument("--mostrobotpy_fork_repo", default=user_config.mostrobotpy_fork_repo, help="URL to your github fork of mostrobotpy that you have write permissions for")
        group.add_argument("--allwpilib_fork_repo", default=user_config.allwpilib_fork_repo, help="URL to your github fork of allwpilib that you have write permissions for")

        group = parser.add_argument_group('Source Of Truth Settings')
        group.add_argument("--mostrobotpy_truth_repo", default=user_config.allwpilib_fork_repo, help="URL to the 'source of truth' for mostrobotpy migrations. Typically this should be the mostrobotpy upstream repository")
        group.add_argument("--mostrobotpy_truth_branch", default=user_config.allwpilib_fork_repo, help="Branch name for the source of truth for mostrobotpy")

        group.add_argument("--allwpilib_truth_repo", default=user_config.allwpilib_fork_repo, help="URL to the 'source of truth' for allwpilib migrations. Typically this should be the allwpilib upstream repository")
        group.add_argument("--allwpilib_truth_branch", default=user_config.allwpilib_fork_repo, help="Branch name for the source of truth for allwpilib")

