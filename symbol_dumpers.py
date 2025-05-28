import pathlib
import pefile
import os


def dump_dll(output_dir, dll_file):
    output_dir.mkdir(parents=True, exist_ok=True)
    print(output_dir, dll_file)
    pe = pefile.PE(dll_file)

    # print(pe.dump_info())
    with open(output_dir / "exports.txt", 'w') as f:
        for exp in pe.DIRECTORY_ENTRY_EXPORT.symbols:
            print(type(hex(pe.OPTIONAL_HEADER.ImageBase + exp.address)))
            print(type(exp.name))
            print(type(exp.ordinal))
            f.write(exp.name.decode("utf-8") + " " + str(exp.ordinal))
            f.write('\n')

    pe.parse_data_directories()
    with open(output_dir / "imports.txt", 'w') as import_f:
        with open(output_dir / "dependents.txt", 'w') as dep_f:

            for entry in sorted(pe.DIRECTORY_ENTRY_IMPORT, key=lambda x: x.dll):
                import_f.write(entry.dll.decode("utf-8") + "\n")
                dep_f.write(entry.dll.decode("utf-8") + "\n")
                for imp in sorted(entry.imports, key=lambda x: x.name):
                    import_f.write('\t' + imp.name.decode("utf-8") + "\n")
    


def main():
    output_dir = pathlib.Path("./symbol_exports")


    venv_dir = pathlib.Path(r"C:\Users\PJ\git\robotpy\mostrobotpy\.venv\Lib\site-packages")
    bzl_dir = pathlib.Path("bazel-bin/subprojects")

    do_bazel = True
    if do_bazel:
        venv_dir = None
    else:
        bzl_dir = None

    projects = [
        ("hal", "_wpiHal"),
        ("hal", "simulation/_simulation"),
        # ("wpilib", "_wpilib"),
        # ("wpilib", "counter/_counter"),
        # ("wpilib", "drive/_drive"),
        # ("wpilib", "event/_event"),
        # ("wpilib", "interfaces/_interfaces"),
        # ("wpilib", "shuffleboard/_shuffleboard"),
        # ("wpilib", "simulation/_simulation"),
        # ("wpimath", "_wpimath"),
        # ("wpimath", "_controls/_controls"),
        # ("wpimath", "filter/_filter"),
        # ("wpimath", "geometry/_geometry"),
        # ("wpimath", "interpolation/_interpolation"),
        # ("wpimath", "kinematics/_kinematics"),
        # ("wpimath", "spline/_spline"),
        ("wpinet", "_wpinet"),
        ("wpiutil", "_wpiutil"),
    ]

    for project, lib_info in projects:
        if venv_dir:
            dll_file = venv_dir / project / (lib_info + ".cp310-win_amd64.pyd")
        elif bzl_dir:
            dll_file = bzl_dir / f"robotpy-{project}" / project / (lib_info + ".pyd")
        # print(dll_file, os.path.exists(dll_file))
        dump_dll(output_dir / project / lib_info, dll_file)


if __name__ == "__main__":
    main()