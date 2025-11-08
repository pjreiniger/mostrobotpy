# Copybara Syncronization
This directory contains helper scripts to run the syncronization between `mostrobotpy` and the mirror that lives in `allwpilib` using [copybara](https://github.com/google/copybara). Two main scripts exist; one for [pushing](copybara_push_to_mirror.py) to the mirror (`mostrobotpy` -> `allwpilib`), and another more complicated script  for pulling changes from the mirror (`allwpilib` -> `mostrobotpy`). These scripts can run with two different settings that are outlined below: one that pushes to a local repository on your computer, one to push the changes to your fork on github.

## User Configuration
All parameters for the locations of the forks or local repositories on your computer can be overridden on the command line, but to save some typing you can also specify using settings in a `.copybara.json` file. The scripts will read this file before executing the syncronization and use the values in there if nothing is specified on the command line.

Example config:
```
{
    "mostrobotpy_truth_repo": "https://github.com/robotpy/mostrobotpy.git",
    "mostrobotpy_truth_branch": "2027",

    "allwpilib_truth_repo": "https://github.com/wpilibsuite/allwpilib.git",
    "allwpilib_truth_branch": "2027",

    "mostrobotpy_fork_repo": "https://github.com/<your_username>/mostrobotpy.git",
    "allwpilib_fork_repo": "https://github.com/<your_username>/allwpilib.git",

    "mostrobotpy_local_repo_path": "/home/<your_username>/git/mostrobotpy",
    "allwpilib_local_repo_path": "/home/<your_username>/git/allwpilib"
}
```

## Pushing to `allwpilib`
Moving changes in this direction is easy under the hood, and if you have set up a `.copybara.json` config file the command can be as simple as:
`python3 copybara_push_to_mirror.py --method=push_fork`

If the changes look good on your fork, you can open a pull request to merge them into `mostrobotpy`

## Pulling from `allwpilib`
Since the semiwrap tooling needs to download external archives from the `wpilibsuite` maven repository, additional steps are required by the script to update the versions in addition to running `copybara`. The process is as follows:
1. Run copybara
2. Fetch the changes that were pushed to your fork and checkout that branch
3. Update the `rdev.toml` script with the approriate version updates
4. Push these additional changes to your fork
