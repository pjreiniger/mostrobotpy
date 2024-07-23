load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_bzlmodrio_toolchains",
    sha256 = "cd3ff046427e9c6dbc0c86a458c8cf081b8045fc3fb4265d08c0ebfc17f9cb30",
    url = "https://github.com/bzlmodRio/rules_bzlmodRio_toolchains/releases/download/2024-1/rules_bzlmodRio_toolchains-2024-1.tar.gz",
)

http_archive(
    name = "bzlmodrio-allwpilib",
    sha256 = "f0d477e7236df5d46980566943a64045f6ed69b498fd7a959c58425a6afcf6db",
    url = "https://github.com/bzlmodRio/bzlmodRio-allwpilib/releases/download/{}/bzlmodRio-allwpilib-{}.tar.gz".format("2024.3.2", "2024.3.2"),
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
    integrity = "sha256-ONA//pxfMap4Hs1OtYk/Yk4UMBZ3B0PmIBsVoYIjdFE=",
    strip_prefix = "pybind11-a5b0cdcb937b2853e012489633d692099dab7078",
    urls = ["https://github.com/pybind/pybind11/archive/a5b0cdcb937b2853e012489633d692099dab7078.zip"],
)

PYTHON_VERSION = "3.10"

PYTHON_UNDERSCORE_VERSION = PYTHON_VERSION.replace(".", "_")

python_register_toolchains(
    name = "python_" + PYTHON_UNDERSCORE_VERSION,
    ignore_root_user_error = True,
    python_version = PYTHON_VERSION,
)

http_archive(
    name = "rules_bazelrio",
    sha256 = "0c5a98476ac5b606689863b7b9ef3f7d685c47ce2681e448ca977e8e95de31c1",
    url = "https://github.com/bzlmodRio/rules_bazelrio/releases/download/0.0.14/rules_bazelrio-0.0.14.tar.gz",
)

# bzlmodrio-ni
http_archive(
    name = "bzlmodrio-ni",
    sha256 = "f4101925d260c385f6a5c0a79451692db35f433cab8b8cc4092dd3ab93424559",
    url = "https://github.com/bzlmodRio/bzlmodRio-ni/releases/download/2024.2.0/bzlmodRio-ni-2024.2.0.tar.gz",
)

# bzlmodrio-opencv
http_archive(
    name = "bzlmodrio-opencv",
    sha256 = "761b152ef922e6bb386b79b06830fdf085b905d132d967c31d3ab4f33b8a8366",
    url = "https://github.com/bzlmodRio/bzlmodRio-opencv/releases/download/2024.4.8.0-1/bzlmodRio-opencv-2024.4.8.0-1.tar.gz",
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
    
    requirements_windows = "@//bazel_utils/requirements/" + PYTHON_VERSION + ":requirements_windows.txt",
    requirements_darwin = "@//bazel_utils/requirements/" + PYTHON_VERSION + ":requirements_osx.txt",
    requirements_lock = "@//bazel_utils/requirements/" + PYTHON_VERSION + ":requirements_linux.txt",
    python_interpreter_target = "@python_" + PYTHON_UNDERSCORE_VERSION + "_host//:python",
)

load("@rules_robotpy_utils_pip_deps//:requirements.bzl", "install_deps")

install_deps()
