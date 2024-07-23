# This file is automatically generated, DO NOT EDIT
# fmt: off

from os.path import abspath, join, dirname, exists
_root = abspath(dirname(__file__))

# runtime dependencies
import wpiutil._init_wpiutil
import wpinet._init_wpinet
from ctypes import cdll

try:
    _lib = cdll.LoadLibrary(join(_root, "lib", "libntcore.so"))
except FileNotFoundError:
    if not exists(join(_root, "lib", "libntcore.so")):
        raise FileNotFoundError("libntcore.so was not found on your system. Is this package correctly installed?")
    raise FileNotFoundError("libntcore.so could not be loaded. There is a missing dependency.")

