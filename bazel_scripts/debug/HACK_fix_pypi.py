with open(
    "bazel-mostrobotpy/external/rules_python~~pip~allwpilib_pip_deps_310_semiwrap/site-packages/semiwrap/pyproject.py",
    "r",
) as f:
    contents = f.read()

print(contents)

contents = contents.replace(
    "def package_root(self) -> pathlib.Path:",
    "def package_root(self) -> pathlib.Path:\n        self._package_root = self.root",
)

with open(
    "bazel-mostrobotpy/external/rules_python~~pip~allwpilib_pip_deps_310_semiwrap/site-packages/semiwrap/pyproject.py",
    "w",
) as f:
    f.write(contents)

with open("subprojects/robotpy-hal/hal/version.py", 'w') as f:
    f.write('version = __version__ = "2025.3.2.2"')