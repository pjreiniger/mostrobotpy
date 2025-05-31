
from semiwrap.autowrap.buffer import RenderBuffer
from semiwrap.pyproject import PyProject
import pathlib

def generate_build_info(project_file: pathlib.Path, output_file: pathlib.Path):
    py_project = PyProject(project_file)



def main():
    project_files = [
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/pyntcore/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-apriltag/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-cscore/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-hal/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-halsim-ds-socket/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-halsim-gui/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-halsim-ws/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-romi/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpilib/pyproject.toml"),
        pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpimath/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpimath/tests/cpp/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpinet/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpiutil/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpiutil/tests/cpp/pyproject.toml"),
        # pathlib.Path("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-xrp/pyproject.toml"),
    ]

    for project_file in project_files:
        print(f"Running for {project_file}")
        generate_build_info(project_file, project_file.parent / "generated_build_info.bzl")



if __name__ == "__main__":
    main()