

def resolve_caster_file(caster_name):
    if caster_name == "wpiutil-casters":
        project = "//subprojects/robotpy-wpiutil"
        caster_path = "wpiutil/wpiutil-casters.pybind11.json"
    if caster_name == "wpimath-casters":
        project = "//subprojects/robotpy-wpimath"
        caster_path = "wpimath/wpimath-casters.pybind11.json"

    caster_deps = project + ":import"
    caster_files = "$(location " + project + ":import)" + "/site-packages/" + caster_path

    return (caster_deps, caster_files)