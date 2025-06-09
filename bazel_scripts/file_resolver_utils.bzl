INSTALL_WHEELS = True

def resolve_caster_file(caster_name):

    if INSTALL_WHEELS:
        if caster_name == "wpiutil-casters":
            project = "//subprojects/robotpy-wpiutil"
            caster_path = "wpiutil/wpiutil-casters.pybind11.json"
        if caster_name == "wpimath-casters":
            project = "//subprojects/robotpy-wpimath"
            caster_path = "wpimath/wpimath-casters.pybind11.json"

        caster_deps = project + ":import"
        caster_files = "$(location " + project + ":import)" + "/site-packages/" + caster_path

        return (caster_deps, caster_files)
    else:
        if caster_name == "wpiutil-casters":
            return (
                "//subprojects/robotpy-wpiutil:wpiutil/wpiutil-casters.pybind11.json", 
                "$(location //subprojects/robotpy-wpiutil:wpiutil/wpiutil-casters.pybind11.json)"
            )
        elif caster_name == "wpimath-casters":
            return (
                "//subprojects/robotpy-wpimath:wpimath/wpimath-casters.pybind11.json", 
                "$(location //subprojects/robotpy-wpimath:wpimath/wpimath-casters.pybind11.json)"
            )
        else:
            fail()

def resolve_include_root(library_label, include_subpackage):
    return "$(location " + library_label + ":import)/site-packages/native/" + include_subpackage + "/include"

def local_native_libraries_helper(base_library_name):
    return ("//subprojects/robotpy-native-" + base_library_name + ":import", base_library_name)

def local_pc_file_util(library_project, pc_subpaths):
    if INSTALL_WHEELS or "native" in library_project:
        pc_files = []
        for pc in pc_subpaths:
            pc_files.append("$(location " + library_project + ":import)/site-packages/" + pc)
        return [(library_project + ":import", pc_files)]
    else:
        output = []
        for pc in pc_subpaths:
            combo = library_project + ":" + pc
            output.append((combo, ["$(location " + combo + ")"]))

        return output


def local_pybind_library(library_project, lib_name):
    if INSTALL_WHEELS:
        return library_project + ":import"
    else:
        return library_project + ":" + lib_name