import re
import os
import shutil

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

# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpiutil/BUILD.bazel")
# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpiutil/wpiutil/BUILD.bazel")

# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpinet/BUILD.bazel")
# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpinet/wpinet/BUILD.bazel")

# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/pyntcore/BUILD.bazel")
# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/pyntcore/ntcore/BUILD.bazel")

# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-hal/BUILD.bazel")
# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-hal/hal/BUILD.bazel")
# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-hal/hal/simulation/BUILD.bazel")

# import os
# for root, _, files in os.walk("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpimath"):
#     for f in files:
#         if f == "BUILD.bazel":
#             run_replacement(os.path.join(root, f))
# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-hal/hal/BUILD.bazel")
# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-hal/hal/simulation/BUILD.bazel")


# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-apriltag/BUILD.bazel")
# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-apriltag/robotpy_apriltag/BUILD.bazel")

# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-cscore/BUILD.bazel")
# run_replacement("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-cscore/cscore/BUILD.bazel")


# for root, _, files in os.walk("/home/pjreiniger/git/robotpy/mostrobotpy/subprojects/robotpy-wpilib"):
#     for f in files:
#         if f == "BUILD.bazel":
#             run_replacement(os.path.join(root, f))


files_to_delete = []



for root, dirs, files in os.walk("."):
    # for d in dirs:
    #     if d == ".pytest_cache" or d == "dist" or d == "__pycache__" or d == "wpiutil_test.egg-info" or d == "wpimath_test.egg-info":
    #         print("Removing ", root, d)
    #         shutil.rmtree(os.path.join(root, d))
    #     if  d == "rpy-include" and "generated" not in root:
    #         print("Removing ", root, d)
    #         shutil.rmtree(os.path.join(root, d))
    #     if d == "include" and "rules_robotpy_utils" not in root:
    #         print("Removing ", root, d)
    #         shutil.rmtree(os.path.join(root, d))


    for f in files:
        # if f == ".gitignore":
        #     os.remove(os.path.join(root, f))
        # if f.endswith(".so"):
        #     os.remove(os.path.join(root, f))

        if f.startswith("_init"):
            files_to_delete.append(os.path.join(root, f))
        if f == "pkgcfg.py":
            files_to_delete.append(os.path.join(root, f))
        if f == "version.py":
            files_to_delete.append(os.path.join(root, f))

for f in files_to_delete:
    print("Removing ", f)
    os.remove(f)