load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_bzlmodrio_toolchains",
    sha256 = "2ef1cafce7f4fd4e909bb5de8b0dc771a934646afd55d5f100ff31f6b500df98",
    url = "https://github.com/wpilibsuite/rules_bzlmodRio_toolchains/releases/download/2024-1.bcr1/rules_bzlmodRio_toolchains-2024-1.bcr1.tar.gz",
)

http_archive(
    name = "bzlmodrio-allwpilib",
    sha256 = "986e7ba1cdb7cacadb22256185843ba12bd1c5e2b6da10019829f18bedafa3ee",
    url = "https://github.com/bzlmodRio/bzlmodRio-allwpilib/releases/download/{}/bzlmodRio-allwpilib-{}.tar.gz".format("2025.1.1-beta-1", "2025.1.1-beta-1"),
)

# Rules Python
http_archive(
    name = "rules_python",
    sha256 = "778aaeab3e6cfd56d681c89f5c10d7ad6bf8d2f1a72de9de55b23081b2d31618",
    strip_prefix = "rules_python-0.34.0",
    url = "https://github.com/bazelbuild/rules_python/releases/download/0.34.0/rules_python-0.34.0.tar.gz",
)

load("@rules_python//python:repositories.bzl", "py_repositories", "python_register_toolchains")

py_repositories()

http_archive(
    name = "aspect_bazel_lib",
    integrity = "sha256-qKkmRecpi79TiqiAExxq20z2I5u9JyMPB3oAQU1Y5M4=",
    strip_prefix = "bazel-lib-2.7.2",
    url = "https://github.com/aspect-build/bazel-lib/releases/download/v2.7.2/bazel-lib-v2.7.2.tar.gz",
)

load("@aspect_bazel_lib//lib:repositories.bzl", "aspect_bazel_lib_dependencies", "aspect_bazel_lib_register_toolchains")

# Required bazel-lib dependencies

aspect_bazel_lib_dependencies()

# Register bazel-lib toolchains

aspect_bazel_lib_register_toolchains()

http_archive(
    name = "pybind11_bazel",
    integrity = "sha256-3BSpYGcrq/baLygweaW1wT5ASpQOp824KXtx+PMWQ6U=",
    strip_prefix = "pybind11_bazel-2.12.0",
    urls = ["https://github.com/pybind/pybind11_bazel/releases/download/v2.12.0/pybind11_bazel-2.12.0.tar.gz"],
)

http_archive(
    name = "rules_python_pytest",
    sha256 = "8b82935e16f7b28e3711a68ae5f88f44d8685ccd906b869f7721fdd4c32f2369",
    strip_prefix = "rules_python_pytest-1.1.0",
    url = "https://github.com/caseyduquettesc/rules_python_pytest/releases/download/v1.1.0/rules_python_pytest-v1.1.0.tar.gz",
)

load("@rules_python_pytest//python_pytest:repositories.bzl", "rules_python_pytest_dependencies")

rules_python_pytest_dependencies()

http_archive(
    name = "pybind11",
    build_file = "@pybind11_bazel//:pybind11-BUILD.bazel",
    integrity = "sha256-bGzo9w9pc/TBKLk/GRHRQXjMHqnnVY8ByK7G5WegAWM=",
    strip_prefix = "pybind11-d8b1541168e58444597f25e85e78356de9b67d34",
    urls = ["https://github.com/pybind/pybind11/archive/d8b1541168e58444597f25e85e78356de9b67d34.zip"],
)

PYTHON_VERSION = "3.10"

PYTHON_UNDERSCORE_VERSION = PYTHON_VERSION.replace(".", "_")

python_register_toolchains(
    name = "python_" + PYTHON_UNDERSCORE_VERSION,
    ignore_root_user_error = True,
    python_version = PYTHON_VERSION,
)

# http_archive(
#     name = "rules_bazelrio",
#     sha256 = "0c5a98476ac5b606689863b7b9ef3f7d685c47ce2681e448ca977e8e95de31c1",
#     url = "https://github.com/bzlmodRio/rules_bazelrio/releases/download/0.0.14/rules_bazelrio-0.0.14.tar.gz",
# )

# bzlmodrio-opencv
http_archive(
    name = "bzlmodrio-opencv",
    sha256 = "5314cce05b49451a46bf3e3140fc401342e53d5f3357612ed4473e59bb616cba",
    url = "https://github.com/bzlmodRio/bzlmodRio-opencv/releases/download/2024.4.8.0-4.bcr1/bzlmodRio-opencv-2024.4.8.0-4.bcr1.tar.gz",
)

# bzlmodrio-ni
http_archive(
    name = "bzlmodrio-ni",
    sha256 = "197fceac88bf44fb8427d5e000b0083118d3346172dd2ad31eccf83a5e61b3ce",
    url = "https://github.com/bzlmodRio/bzlmodRio-ni/releases/download/2025.0.0/bzlmodRio-ni-2025.0.0.tar.gz",
)

load("@bzlmodrio-allwpilib//:maven_cpp_deps.bzl", "setup_legacy_bzlmodrio_allwpilib_cpp_dependencies")
load("@bzlmodrio-ni//:maven_cpp_deps.bzl", "setup_legacy_bzlmodrio_ni_cpp_dependencies")
load("@bzlmodrio-opencv//:maven_cpp_deps.bzl", "setup_legacy_bzlmodrio_opencv_cpp_dependencies")

setup_legacy_bzlmodrio_allwpilib_cpp_dependencies()

setup_legacy_bzlmodrio_ni_cpp_dependencies()

setup_legacy_bzlmodrio_opencv_cpp_dependencies()

load("@rules_python//python:pip.bzl", "pip_parse")

pip_parse(
    name = "rules_robotpy_utils_pip_deps",
    # requirements_by_platform = {
    #     "@//:requirements_linux.txt": "linux_*",
    #     "@//:requirements_osx.txt": "osx_*,darwin_*",
    #     "@//:requirements_windows.txt": "windows_*",
    # },
    
    requirements_windows = "@//bazel_utils/requirements/" + PYTHON_VERSION + ":requirements_windows_" + PYTHON_VERSION + ".txt",
    requirements_darwin = "@//bazel_utils/requirements/" + PYTHON_VERSION + ":requirements_osx_" + PYTHON_VERSION + ".txt",
    requirements_lock = "@//bazel_utils/requirements/" + PYTHON_VERSION + ":requirements_linux_" + PYTHON_VERSION + ".txt",
    python_interpreter_target = "@python_" + PYTHON_UNDERSCORE_VERSION + "_host//:python",
)

load("@rules_robotpy_utils_pip_deps//:requirements.bzl", "install_deps")

install_deps()
