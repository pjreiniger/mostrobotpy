# fmt: off
# This file is automatically generated, DO NOT EDIT

from os.path import abspath, join, dirname
_root = abspath(dirname(__file__))

libinit_import = "halsim_gui._ext._init_halsim_gui_ext"
depends = ['wpiutil', 'wpiHal', 'ntcore', 'wpimath_cpp', 'halsim_gui']
pypi_package = 'robotpy-halsim-gui'

def get_include_dirs():
    return [join(_root, "include"), join(_root, "rpy-include")]

def get_library_dirs():
    return []

def get_library_dirs_rel():
    return []

def get_library_names():
    return []

def get_library_full_names():
    return []