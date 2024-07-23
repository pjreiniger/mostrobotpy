import re
import os
import shutil
import subprocess

SUBPROJECTS = [
    "pyntcore",
    "robotpy-apriltag",
    "robotpy-build",
    "robotpy-cscore",
    "robotpy-hal",
    "robotpy-halsim-ds-socket",
    "robotpy-halsim-gui",
    "robotpy-halsim-ws",
    "robotpy-wpimath",
    "robotpy-wpinet",
    "robotpy-wpiutil",
    
    "wpimath-test",
]

def run_replacement(filename):
    with open(filename, 'r') as f:
        contents = f.read()

    contents = contents.replace("//shared/bazel/rules/python/pybind_generator", "//rules_robotpy_utils")
    contents = contents.replace("//shared/bazel/rules/python/pybind_generator", "//rules_robotpy_utils")
    contents = contents.replace('load("@rules_robotpy_utils//', 'load("//')
    
    contents = re.sub("//(.*)/src/main/python/(.*):", "//subprojects/robotpy-\\1/\\2:", contents)
    contents = re.sub("//(.*)/src/main/python:", "//subprojects/robotpy-\\1:", contents)
    contents = re.sub("//(.*)/src/main/native:(.*).shared", "@bzlmodrio-allwpilib//libraries/cpp/\\1", contents)
    contents = re.sub("//(.*)/src/main/native:(.*)\"", "@bazelrio_edu_wpi_first_xx-cpp_linuxx86-64//:shared_libs\"", contents)
    
    with open(filename, 'w') as f:
        f.write(contents)


def fixup_build_files():
    for subproject in SUBPROJECTS:
        for root, _, files in os.walk(os.path.join("subprojects", subproject)):
            for f in files:
                if f == "BUILD.bazel":
                    run_replacement(os.path.join(root, f))


def delete_gitignored_files():
    for root, dirs, files in os.walk("."):
        for d in dirs:
            if d == ".pytest_cache" or d == "dist" or d == "__pycache__" or d == "wpiutil_test.egg-info" or d == "wpimath_test.egg-info" or d == "wpilib.egg-info" or d == "build" or d == "lib":
                print("Removing ", root, d)
                shutil.rmtree(os.path.join(root, d))
            if  d == "rpy-include" and "generated" not in root:
                print("Removing ", root, d)
                shutil.rmtree(os.path.join(root, d))
            if d == "include" and "rules_robotpy_utils" not in root:
                print("Removing ", root, d)
                shutil.rmtree(os.path.join(root, d))

        for f in files:
            if f == ".gitignore":
                print("Removing ", root, f)
                os.remove(os.path.join(root, f))


def find_generated_files():
    generated_files = []

    for root, dirs, files in os.walk("."):
        for f in files:
            if f.startswith("_init"):
                generated_files.append(os.path.join(root, f))
            if f == "pkgcfg.py":
                generated_files.append(os.path.join(root, f))
            if f == "version.py":
                generated_files.append(os.path.join(root, f))

    return generated_files


def delete_generated_files():
    files_to_delete = find_generated_files()
    for f in files_to_delete:
        print("Removing ", f)
        os.remove(f)
        
        
def add_generated_files():
    files_to_delete = find_generated_files()
    
    args = ["git", "add", "-f"] + files_to_delete
    subprocess.check_call(args)


def uninstall_dev_versions():
    for project in SUBPROJECTS:
        print(project)
        subprocess.check_call(["pip3", "uninstall", project, "-y"])


# fixup_build_files()
delete_generated_files()

# add_generated_files()


# delete_gitignored_files()
# delete_generated_files()

# uninstall_dev_versions()




