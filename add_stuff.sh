git add \
    subprojects/robotpy-wpinet/generated/ \
    subprojects/robotpy-wpiutil/generated/ \
    subprojects/robotpy-wpimath/generated/ \
    subprojects/robotpy-wpimath/tests/cpp/generated/ \
    subprojects/pyntcore/generated/ \
    subprojects/robotpy-apriltag/generated/ \
    subprojects/robotpy-cscore/generated/ \
    subprojects/robotpy-hal/generated/ \
    subprojects/robotpy-wpilib/generated/ \
    subprojects/robotpy-wpimath/tests/cpp/generated/

git add **conftest.py

find -name BUILD.bazel | xargs git add
git add rules_robotpy_utils
git add robotbuild_generation

git add .bazel*
git add MODULE*
git add requirements*