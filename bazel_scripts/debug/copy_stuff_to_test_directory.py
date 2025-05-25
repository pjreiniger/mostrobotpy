import os
import pathlib
import shutil


def main():
    projects = [
        "pyntcore",
        "robotpy-apriltag",
        "robotpy-cscore",
        "robotpy-hal",
        "robotpy-romi",
        "robotpy-wpilib",
        "robotpy-wpimath",
        "robotpy-wpinet",
        "robotpy-wpiutil",
        "robotpy-xrp",
        "robotpy-halsim-gui",
    ]

    for project in projects:
        for root, _, files in os.walk(f"bazel-bin/subprojects/{project}/generated"):
            for f in files:
                if f.endswith(".dat") or f.endswith(".d") or f.endswith(".pkl"):
                    continue

                full_file = pathlib.Path(os.path.join(root, f))
                print(full_file)

                resolved_project_name = project
                if project == "robotpy-wpilib":
                    resolved_project_name = "wpilib"

                if "dat_to_trampoline_hdr" in root:
                    dst_file = pathlib.Path(
                        f"/home/pjreiniger/git/robotpy/temp_gen_results/{resolved_project_name.replace('-', '_')}-2025.3.2.2/build/cp310/semiwrap/trampolines/{f}"
                    )
                else:
                    dst_file = pathlib.Path(
                        f"/home/pjreiniger/git/robotpy/temp_gen_results/{resolved_project_name.replace('-', '_')}-2025.3.2.2/build/cp310/semiwrap/{f}"
                    )
                dst_file.parent.mkdir(parents=True, exist_ok=True)
                # os.chmod(dst_file, 0o777)
                shutil.copy(full_file, dst_file)
                os.chmod(dst_file, 0o644)


if __name__ == "__main__":
    main()
