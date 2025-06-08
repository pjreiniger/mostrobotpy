load("@rules_semiwrap//:defs.bzl", "copy_extension_library", "create_pybind_library", "make_pyi", "robotpy_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")
load("//bazel_scripts:file_resolver_utils.bzl", "local_native_libraries_helper", "resolve_caster_file", "resolve_include_root")

def wpilib_event_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps=[]):
    WPILIB_EVENT_HEADER_GEN = [
        struct(
            class_name = "BooleanEvent",
            yml_file = "semiwrap/event/BooleanEvent.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/event/BooleanEvent.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::BooleanEvent", "frc__BooleanEvent.hpp"),
            ],
        ),
        struct(
            class_name = "EventLoop",
            yml_file = "semiwrap/event/EventLoop.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/event/EventLoop.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::EventLoop", "frc__EventLoop.hpp"),
            ],
        ),
        struct(
            class_name = "NetworkBooleanEvent",
            yml_file = "semiwrap/event/NetworkBooleanEvent.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/event/NetworkBooleanEvent.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::NetworkBooleanEvent", "frc__NetworkBooleanEvent.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpilib_event.resolve_casters",
        caster_deps = [resolve_caster_file("wpimath-casters"), resolve_caster_file("wpiutil-casters")],
        casters_pkl_file = "wpilib_event.casters.pkl",
        dep_file = "wpilib_event.casters.d",
    )

    gen_libinit(
        name = "wpilib_event.gen_lib_init",
        output_file = "wpilib/event/_init__event.py",
        modules = ["native.wpilib._init_robotpy_native_wpilib", "wpimath.filter._init__filter"],
    )

    gen_pkgconf(
        name = "wpilib_event.gen_pkgconf",
        libinit_py = "wpilib.event._init__event",
        module_pkg_name = "wpilib.event._event",
        output_file = "wpilib_event.pc",
        pkg_name = "wpilib_event",
        install_path = "wpilib/event",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpilib_event.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPILIB_EVENT_HEADER_GEN],
        libname = "_event",
        output_file = "semiwrap_init.wpilib.event._event.hpp",
    )

    run_header_gen(
        name = "wpilib_event",
        casters_pickle = "wpilib_event.casters.pkl",
        header_gen_config = WPILIB_EVENT_HEADER_GEN,
        trampoline_subpath = "wpilib/event",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("ntcore"),
            local_native_libraries_helper("wpihal"),
            local_native_libraries_helper("wpilib"),
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpinet"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpilib_event.generated_files",
        srcs = [
            "wpilib_event.gen_modinit_hpp.gen",
            "wpilib_event.header_gen_files",
            "wpilib_event.gen_pkgconf",
            "wpilib_event.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpilib_event",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpilib_event.generated_srcs"],
        semiwrap_header = [":wpilib_event.gen_modinit_hpp"],
        deps = deps + [
            ":wpilib_event.tmpl_hdrs",
            ":wpilib_event.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    make_pyi(
        name = "wpilib_event.make_pyi",
        extension_package = "wpilib.event._event",
        extension_library = "copy_wpilib_event",
        interface_files = [
            "_event.pyi",
        ],
        init_pkgcfgs = [
            "wpilib/event/_init__event.py",
            "wpilib/interfaces/_init__interfaces.py",
            "wpilib/_init__wpilib.py",
            "wpilib/counter/_init__counter.py",
            "wpilib/drive/_init__drive.py",
            "wpilib/simulation/_init__simulation.py",
        ],
        init_packages = [
            "wpilib/event",
            "wpilib/interfaces",
            "wpilib",
            "wpilib/counter",
            "wpilib/drive",
            "wpilib/simulation",
        ],
        install_path = "wpilib/event",
        python_deps = [
            "//subprojects/pyntcore:import",
            "//subprojects/robotpy-hal:import",
            "//subprojects/robotpy-native-ntcore:import",
            "//subprojects/robotpy-native-wpihal:import",
            "//subprojects/robotpy-native-wpilib:import",
            "//subprojects/robotpy-native-wpimath:import",
            "//subprojects/robotpy-native-wpinet:import",
            "//subprojects/robotpy-native-wpiutil:import",
            "//subprojects/robotpy-wpilog:import",
            "//subprojects/robotpy-wpimath:import",
            "//subprojects/robotpy-wpinet:import",
            "//subprojects/robotpy-wpiutil:import",
        ] + extra_pyi_deps,
        local_extension_deps = [
            ("wpilib/interfaces/_interfaces", "copy_wpilib_interfaces"),
            ("wpilib/_wpilib", "copy_wpilib"),
            ("wpilib/counter/_counter", "copy_wpilib_counter"),
            ("wpilib/drive/_drive", "copy_wpilib_drive"),
            ("wpilib/simulation/_simulation", "copy_wpilib_simulation"),
        ],
    )

def wpilib_interfaces_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps=[]):
    WPILIB_INTERFACES_HEADER_GEN = [
        struct(
            class_name = "CounterBase",
            yml_file = "semiwrap/interfaces/CounterBase.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/CounterBase.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::CounterBase", "frc__CounterBase.hpp"),
            ],
        ),
        struct(
            class_name = "GenericHID",
            yml_file = "semiwrap/interfaces/GenericHID.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/GenericHID.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::GenericHID", "frc__GenericHID.hpp"),
            ],
        ),
        struct(
            class_name = "MotorController",
            yml_file = "semiwrap/interfaces/MotorController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/MotorController.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MotorController", "frc__MotorController.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpilib_interfaces.resolve_casters",
        caster_deps = [resolve_caster_file("wpimath-casters"), resolve_caster_file("wpiutil-casters")],
        casters_pkl_file = "wpilib_interfaces.casters.pkl",
        dep_file = "wpilib_interfaces.casters.d",
    )

    gen_libinit(
        name = "wpilib_interfaces.gen_lib_init",
        output_file = "wpilib/interfaces/_init__interfaces.py",
        modules = ["native.wpilib._init_robotpy_native_wpilib", "wpilib.event._init__event", "wpimath.geometry._init__geometry"],
    )

    gen_pkgconf(
        name = "wpilib_interfaces.gen_pkgconf",
        libinit_py = "wpilib.interfaces._init__interfaces",
        module_pkg_name = "wpilib.interfaces._interfaces",
        output_file = "wpilib_interfaces.pc",
        pkg_name = "wpilib_interfaces",
        install_path = "wpilib/interfaces",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpilib_interfaces.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPILIB_INTERFACES_HEADER_GEN],
        libname = "_interfaces",
        output_file = "semiwrap_init.wpilib.interfaces._interfaces.hpp",
    )

    run_header_gen(
        name = "wpilib_interfaces",
        casters_pickle = "wpilib_interfaces.casters.pkl",
        header_gen_config = WPILIB_INTERFACES_HEADER_GEN,
        trampoline_subpath = "wpilib/interfaces",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("ntcore"),
            local_native_libraries_helper("wpihal"),
            local_native_libraries_helper("wpilib"),
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpinet"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpilib_interfaces.generated_files",
        srcs = [
            "wpilib_interfaces.gen_modinit_hpp.gen",
            "wpilib_interfaces.header_gen_files",
            "wpilib_interfaces.gen_pkgconf",
            "wpilib_interfaces.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpilib_interfaces",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpilib_interfaces.generated_srcs"],
        semiwrap_header = [":wpilib_interfaces.gen_modinit_hpp"],
        deps = deps + [
            ":wpilib_interfaces.tmpl_hdrs",
            ":wpilib_interfaces.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    make_pyi(
        name = "wpilib_interfaces.make_pyi",
        extension_package = "wpilib.interfaces._interfaces",
        extension_library = "copy_wpilib_interfaces",
        interface_files = [
            "_interfaces.pyi",
        ],
        init_pkgcfgs = [
            "wpilib/event/_init__event.py",
            "wpilib/interfaces/_init__interfaces.py",
            "wpilib/_init__wpilib.py",
            "wpilib/counter/_init__counter.py",
            "wpilib/drive/_init__drive.py",
            "wpilib/simulation/_init__simulation.py",
        ],
        init_packages = [
            "wpilib/event",
            "wpilib/interfaces",
            "wpilib",
            "wpilib/counter",
            "wpilib/drive",
            "wpilib/simulation",
        ],
        install_path = "wpilib/interfaces",
        python_deps = [
            "//subprojects/pyntcore:import",
            "//subprojects/robotpy-hal:import",
            "//subprojects/robotpy-native-ntcore:import",
            "//subprojects/robotpy-native-wpihal:import",
            "//subprojects/robotpy-native-wpilib:import",
            "//subprojects/robotpy-native-wpimath:import",
            "//subprojects/robotpy-native-wpinet:import",
            "//subprojects/robotpy-native-wpiutil:import",
            "//subprojects/robotpy-wpilog:import",
            "//subprojects/robotpy-wpimath:import",
            "//subprojects/robotpy-wpinet:import",
            "//subprojects/robotpy-wpiutil:import",
        ] + extra_pyi_deps,
        local_extension_deps = [
            ("wpilib/event/_event", "copy_wpilib_event"),
            ("wpilib/_wpilib", "copy_wpilib"),
            ("wpilib/counter/_counter", "copy_wpilib_counter"),
            ("wpilib/drive/_drive", "copy_wpilib_drive"),
            ("wpilib/simulation/_simulation", "copy_wpilib_simulation"),
        ],
    )

def wpilib_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps=[]):
    WPILIB_HEADER_GEN = [
        struct(
            class_name = "ADXL345_I2C",
            yml_file = "semiwrap/ADXL345_I2C.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/ADXL345_I2C.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::ADXL345_I2C", "frc__ADXL345_I2C.hpp"),
                ("frc::ADXL345_I2C::AllAxes", "frc__ADXL345_I2C__AllAxes.hpp"),
            ],
        ),
        struct(
            class_name = "AddressableLED",
            yml_file = "semiwrap/AddressableLED.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/AddressableLED.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AddressableLED", "frc__AddressableLED.hpp"),
                ("frc::AddressableLED::LEDData", "frc__AddressableLED__LEDData.hpp"),
            ],
        ),
        struct(
            class_name = "Alert",
            yml_file = "semiwrap/Alert.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Alert.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Alert", "frc__Alert.hpp"),
            ],
        ),
        struct(
            class_name = "AnalogAccelerometer",
            yml_file = "semiwrap/AnalogAccelerometer.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/AnalogAccelerometer.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AnalogAccelerometer", "frc__AnalogAccelerometer.hpp"),
            ],
        ),
        struct(
            class_name = "AnalogEncoder",
            yml_file = "semiwrap/AnalogEncoder.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/AnalogEncoder.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AnalogEncoder", "frc__AnalogEncoder.hpp"),
            ],
        ),
        struct(
            class_name = "AnalogGyro",
            yml_file = "semiwrap/AnalogGyro.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/AnalogGyro.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AnalogGyro", "frc__AnalogGyro.hpp"),
            ],
        ),
        struct(
            class_name = "AnalogInput",
            yml_file = "semiwrap/AnalogInput.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/AnalogInput.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AnalogInput", "frc__AnalogInput.hpp"),
            ],
        ),
        struct(
            class_name = "AnalogPotentiometer",
            yml_file = "semiwrap/AnalogPotentiometer.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/AnalogPotentiometer.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::AnalogPotentiometer", "frc__AnalogPotentiometer.hpp"),
            ],
        ),
        struct(
            class_name = "CAN",
            yml_file = "semiwrap/CAN.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/CAN.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::CAN", "frc__CAN.hpp"),
            ],
        ),
        struct(
            class_name = "Compressor",
            yml_file = "semiwrap/Compressor.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Compressor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Compressor", "frc__Compressor.hpp"),
            ],
        ),
        struct(
            class_name = "CompressorConfigType",
            yml_file = "semiwrap/CompressorConfigType.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/CompressorConfigType.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "DataLogManager",
            yml_file = "semiwrap/DataLogManager.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/DataLogManager.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DataLogManager", "frc__DataLogManager.hpp"),
            ],
        ),
        struct(
            class_name = "DSControlWord",
            yml_file = "semiwrap/DSControlWord.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/DSControlWord.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DSControlWord", "frc__DSControlWord.hpp"),
            ],
        ),
        struct(
            class_name = "DigitalInput",
            yml_file = "semiwrap/DigitalInput.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/DigitalInput.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DigitalInput", "frc__DigitalInput.hpp"),
            ],
        ),
        struct(
            class_name = "DigitalOutput",
            yml_file = "semiwrap/DigitalOutput.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/DigitalOutput.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DigitalOutput", "frc__DigitalOutput.hpp"),
            ],
        ),
        struct(
            class_name = "DoubleSolenoid",
            yml_file = "semiwrap/DoubleSolenoid.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/DoubleSolenoid.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DoubleSolenoid", "frc__DoubleSolenoid.hpp"),
            ],
        ),
        struct(
            class_name = "DriverStation",
            yml_file = "semiwrap/DriverStation.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/DriverStation.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DriverStation", "frc__DriverStation.hpp"),
            ],
        ),
        struct(
            class_name = "DutyCycle",
            yml_file = "semiwrap/DutyCycle.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/DutyCycle.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DutyCycle", "frc__DutyCycle.hpp"),
            ],
        ),
        struct(
            class_name = "DutyCycleEncoder",
            yml_file = "semiwrap/DutyCycleEncoder.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/DutyCycleEncoder.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DutyCycleEncoder", "frc__DutyCycleEncoder.hpp"),
            ],
        ),
        struct(
            class_name = "Encoder",
            yml_file = "semiwrap/Encoder.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Encoder.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Encoder", "frc__Encoder.hpp"),
            ],
        ),
        struct(
            class_name = "Errors",
            yml_file = "semiwrap/Errors.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Errors.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Filesystem",
            yml_file = "semiwrap/Filesystem.yml",
            header_root = "subprojects/robotpy-wpilib/wpilib/src",
            header_file = "subprojects/robotpy-wpilib/wpilib/src" + "/rpy/Filesystem.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "I2C",
            yml_file = "semiwrap/I2C.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/I2C.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::I2C", "frc__I2C.hpp"),
            ],
        ),
        struct(
            class_name = "IterativeRobotBase",
            yml_file = "semiwrap/IterativeRobotBase.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/IterativeRobotBase.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::IterativeRobotBase", "frc__IterativeRobotBase.hpp"),
            ],
        ),
        struct(
            class_name = "Joystick",
            yml_file = "semiwrap/Joystick.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Joystick.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Joystick", "frc__Joystick.hpp"),
            ],
        ),
        struct(
            class_name = "LEDPattern",
            yml_file = "semiwrap/LEDPattern.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/LEDPattern.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::LEDPattern", "frc__LEDPattern.hpp"),
                ("frc::LEDPattern::LEDReader", "frc__LEDPattern__LEDReader.hpp"),
            ],
        ),
        struct(
            class_name = "MotorSafety",
            yml_file = "semiwrap/MotorSafety.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/MotorSafety.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MotorSafety", "frc__MotorSafety.hpp"),
            ],
        ),
        struct(
            class_name = "Notifier",
            yml_file = "semiwrap/Notifier.yml",
            header_root = "subprojects/robotpy-wpilib/wpilib/src",
            header_file = "subprojects/robotpy-wpilib/wpilib/src" + "/rpy/Notifier.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PyNotifier", "frc__PyNotifier.hpp"),
            ],
        ),
        struct(
            class_name = "PS4Controller",
            yml_file = "semiwrap/PS4Controller.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/PS4Controller.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PS4Controller", "frc__PS4Controller.hpp"),
                ("frc::PS4Controller::Button", "frc__PS4Controller__Button.hpp"),
                ("frc::PS4Controller::Axis", "frc__PS4Controller__Axis.hpp"),
            ],
        ),
        struct(
            class_name = "PS5Controller",
            yml_file = "semiwrap/PS5Controller.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/PS5Controller.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PS5Controller", "frc__PS5Controller.hpp"),
                ("frc::PS5Controller::Button", "frc__PS5Controller__Button.hpp"),
                ("frc::PS5Controller::Axis", "frc__PS5Controller__Axis.hpp"),
            ],
        ),
        struct(
            class_name = "PWM",
            yml_file = "semiwrap/PWM.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/PWM.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PWM", "frc__PWM.hpp"),
            ],
        ),
        struct(
            class_name = "PneumaticHub",
            yml_file = "semiwrap/PneumaticHub.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/PneumaticHub.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PneumaticHub", "frc__PneumaticHub.hpp"),
                ("frc::PneumaticHub::Version", "frc__PneumaticHub__Version.hpp"),
                ("frc::PneumaticHub::Faults", "frc__PneumaticHub__Faults.hpp"),
                ("frc::PneumaticHub::StickyFaults", "frc__PneumaticHub__StickyFaults.hpp"),
            ],
        ),
        struct(
            class_name = "PneumaticsBase",
            yml_file = "semiwrap/PneumaticsBase.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/PneumaticsBase.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PneumaticsBase", "frc__PneumaticsBase.hpp"),
            ],
        ),
        struct(
            class_name = "PneumaticsControlModule",
            yml_file = "semiwrap/PneumaticsControlModule.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/PneumaticsControlModule.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PneumaticsControlModule", "frc__PneumaticsControlModule.hpp"),
            ],
        ),
        struct(
            class_name = "PneumaticsModuleType",
            yml_file = "semiwrap/PneumaticsModuleType.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/PneumaticsModuleType.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "PowerDistribution",
            yml_file = "semiwrap/PowerDistribution.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/PowerDistribution.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PowerDistribution", "frc__PowerDistribution.hpp"),
                ("frc::PowerDistribution::Version", "frc__PowerDistribution__Version.hpp"),
                ("frc::PowerDistribution::Faults", "frc__PowerDistribution__Faults.hpp"),
                ("frc::PowerDistribution::StickyFaults", "frc__PowerDistribution__StickyFaults.hpp"),
            ],
        ),
        struct(
            class_name = "Preferences",
            yml_file = "semiwrap/Preferences.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Preferences.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Preferences", "frc__Preferences.hpp"),
            ],
        ),
        struct(
            class_name = "RobotBase",
            yml_file = "semiwrap/RobotBase.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/RobotBase.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::RobotBase", "frc__RobotBase.hpp"),
            ],
        ),
        struct(
            class_name = "RobotController",
            yml_file = "semiwrap/RobotController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/RobotController.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::CANStatus", "frc__CANStatus.hpp"),
                ("frc::RobotController", "frc__RobotController.hpp"),
            ],
        ),
        struct(
            class_name = "RobotState",
            yml_file = "semiwrap/RobotState.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/RobotState.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::RobotState", "frc__RobotState.hpp"),
            ],
        ),
        struct(
            class_name = "RuntimeType",
            yml_file = "semiwrap/RuntimeType.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/RuntimeType.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "SensorUtil",
            yml_file = "semiwrap/SensorUtil.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/SensorUtil.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SensorUtil", "frc__SensorUtil.hpp"),
            ],
        ),
        struct(
            class_name = "SerialPort",
            yml_file = "semiwrap/SerialPort.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/SerialPort.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SerialPort", "frc__SerialPort.hpp"),
            ],
        ),
        struct(
            class_name = "Servo",
            yml_file = "semiwrap/Servo.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Servo.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Servo", "frc__Servo.hpp"),
            ],
        ),
        struct(
            class_name = "SharpIR",
            yml_file = "semiwrap/SharpIR.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/SharpIR.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SharpIR", "frc__SharpIR.hpp"),
            ],
        ),
        struct(
            class_name = "Solenoid",
            yml_file = "semiwrap/Solenoid.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Solenoid.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Solenoid", "frc__Solenoid.hpp"),
            ],
        ),
        struct(
            class_name = "StadiaController",
            yml_file = "semiwrap/StadiaController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/StadiaController.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::StadiaController", "frc__StadiaController.hpp"),
                ("frc::StadiaController::Button", "frc__StadiaController__Button.hpp"),
                ("frc::StadiaController::Axis", "frc__StadiaController__Axis.hpp"),
            ],
        ),
        struct(
            class_name = "SystemServer",
            yml_file = "semiwrap/SystemServer.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/SystemServer.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SystemServer", "frc__SystemServer.hpp"),
            ],
        ),
        struct(
            class_name = "Threads",
            yml_file = "semiwrap/Threads.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Threads.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "TimedRobot",
            yml_file = "semiwrap/TimedRobot.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/TimedRobot.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::TimedRobot", "frc__TimedRobot.hpp"),
            ],
        ),
        struct(
            class_name = "Timer",
            yml_file = "semiwrap/Timer.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Timer.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Timer", "frc__Timer.hpp"),
            ],
        ),
        struct(
            class_name = "TimesliceRobot",
            yml_file = "semiwrap/TimesliceRobot.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/TimesliceRobot.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::TimesliceRobot", "frc__TimesliceRobot.hpp"),
            ],
        ),
        struct(
            class_name = "Tracer",
            yml_file = "semiwrap/Tracer.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Tracer.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Tracer", "frc__Tracer.hpp"),
            ],
        ),
        struct(
            class_name = "Watchdog",
            yml_file = "semiwrap/Watchdog.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/Watchdog.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Watchdog", "frc__Watchdog.hpp"),
            ],
        ),
        struct(
            class_name = "XboxController",
            yml_file = "semiwrap/XboxController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/XboxController.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::XboxController", "frc__XboxController.hpp"),
                ("frc::XboxController::Button", "frc__XboxController__Button.hpp"),
                ("frc::XboxController::Axis", "frc__XboxController__Axis.hpp"),
            ],
        ),
        struct(
            class_name = "DriverStationModeThread",
            yml_file = "semiwrap/DriverStationModeThread.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/internal/DriverStationModeThread.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::internal::DriverStationModeThread", "frc__internal__DriverStationModeThread.hpp"),
            ],
        ),
        struct(
            class_name = "DMC60",
            yml_file = "semiwrap/DMC60.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/DMC60.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DMC60", "frc__DMC60.hpp"),
            ],
        ),
        struct(
            class_name = "Jaguar",
            yml_file = "semiwrap/Jaguar.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/Jaguar.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Jaguar", "frc__Jaguar.hpp"),
            ],
        ),
        struct(
            class_name = "Koors40",
            yml_file = "semiwrap/Koors40.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/Koors40.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Koors40", "frc__Koors40.hpp"),
            ],
        ),
        struct(
            class_name = "MotorControllerGroup",
            yml_file = "semiwrap/MotorControllerGroup.yml",
            header_root = "subprojects/robotpy-wpilib/wpilib/src",
            header_file = "subprojects/robotpy-wpilib/wpilib/src" + "/rpy/MotorControllerGroup.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PyMotorControllerGroup", "frc__PyMotorControllerGroup.hpp"),
            ],
        ),
        struct(
            class_name = "PWMMotorController",
            yml_file = "semiwrap/PWMMotorController.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/PWMMotorController.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PWMMotorController", "frc__PWMMotorController.hpp"),
            ],
        ),
        struct(
            class_name = "PWMSparkFlex",
            yml_file = "semiwrap/PWMSparkFlex.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/PWMSparkFlex.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PWMSparkFlex", "frc__PWMSparkFlex.hpp"),
            ],
        ),
        struct(
            class_name = "PWMSparkMax",
            yml_file = "semiwrap/PWMSparkMax.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/PWMSparkMax.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PWMSparkMax", "frc__PWMSparkMax.hpp"),
            ],
        ),
        struct(
            class_name = "PWMTalonFX",
            yml_file = "semiwrap/PWMTalonFX.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/PWMTalonFX.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PWMTalonFX", "frc__PWMTalonFX.hpp"),
            ],
        ),
        struct(
            class_name = "PWMTalonSRX",
            yml_file = "semiwrap/PWMTalonSRX.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/PWMTalonSRX.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PWMTalonSRX", "frc__PWMTalonSRX.hpp"),
            ],
        ),
        struct(
            class_name = "PWMVenom",
            yml_file = "semiwrap/PWMVenom.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/PWMVenom.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PWMVenom", "frc__PWMVenom.hpp"),
            ],
        ),
        struct(
            class_name = "PWMVictorSPX",
            yml_file = "semiwrap/PWMVictorSPX.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/PWMVictorSPX.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::PWMVictorSPX", "frc__PWMVictorSPX.hpp"),
            ],
        ),
        struct(
            class_name = "SD540",
            yml_file = "semiwrap/SD540.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/SD540.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SD540", "frc__SD540.hpp"),
            ],
        ),
        struct(
            class_name = "Spark",
            yml_file = "semiwrap/Spark.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/Spark.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Spark", "frc__Spark.hpp"),
            ],
        ),
        struct(
            class_name = "SparkMini",
            yml_file = "semiwrap/SparkMini.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/SparkMini.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SparkMini", "frc__SparkMini.hpp"),
            ],
        ),
        struct(
            class_name = "Talon",
            yml_file = "semiwrap/Talon.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/Talon.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Talon", "frc__Talon.hpp"),
            ],
        ),
        struct(
            class_name = "Victor",
            yml_file = "semiwrap/Victor.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/Victor.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Victor", "frc__Victor.hpp"),
            ],
        ),
        struct(
            class_name = "VictorSP",
            yml_file = "semiwrap/VictorSP.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/motorcontrol/VictorSP.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::VictorSP", "frc__VictorSP.hpp"),
            ],
        ),
        struct(
            class_name = "Field2d",
            yml_file = "semiwrap/Field2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/smartdashboard/Field2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Field2d", "frc__Field2d.hpp"),
            ],
        ),
        struct(
            class_name = "FieldObject2d",
            yml_file = "semiwrap/FieldObject2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/smartdashboard/FieldObject2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::FieldObject2d", "frc__FieldObject2d.hpp"),
            ],
        ),
        struct(
            class_name = "Mechanism2d",
            yml_file = "semiwrap/Mechanism2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/smartdashboard/Mechanism2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Mechanism2d", "frc__Mechanism2d.hpp"),
            ],
        ),
        struct(
            class_name = "MechanismLigament2d",
            yml_file = "semiwrap/MechanismLigament2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/smartdashboard/MechanismLigament2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MechanismLigament2d", "frc__MechanismLigament2d.hpp"),
            ],
        ),
        struct(
            class_name = "MechanismObject2d",
            yml_file = "semiwrap/MechanismObject2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/smartdashboard/MechanismObject2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MechanismObject2d", "frc__MechanismObject2d.hpp"),
            ],
        ),
        struct(
            class_name = "MechanismRoot2d",
            yml_file = "semiwrap/MechanismRoot2d.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/smartdashboard/MechanismRoot2d.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MechanismRoot2d", "frc__MechanismRoot2d.hpp"),
            ],
        ),
        struct(
            class_name = "SendableBuilderImpl",
            yml_file = "semiwrap/SendableBuilderImpl.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/smartdashboard/SendableBuilderImpl.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SendableBuilderImpl", "frc__SendableBuilderImpl.hpp"),
            ],
        ),
        struct(
            class_name = "SendableChooser",
            yml_file = "semiwrap/SendableChooser.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/smartdashboard/SendableChooser.h",
            tmpl_class_names = [
                ("SendableChooser_tmpl1", "SendableChooser"),
            ],
            trampolines = [
                ("frc::SendableChooser", "frc__SendableChooser.hpp"),
            ],
        ),
        struct(
            class_name = "SendableChooserBase",
            yml_file = "semiwrap/SendableChooserBase.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/smartdashboard/SendableChooserBase.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SendableChooserBase", "frc__SendableChooserBase.hpp"),
            ],
        ),
        struct(
            class_name = "SmartDashboard",
            yml_file = "semiwrap/SmartDashboard.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/smartdashboard/SmartDashboard.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SmartDashboard", "frc__SmartDashboard.hpp"),
            ],
        ),
        struct(
            class_name = "SysIdRoutineLog",
            yml_file = "semiwrap/SysIdRoutineLog.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/sysid/SysIdRoutineLog.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sysid::SysIdRoutineLog", "frc__sysid__SysIdRoutineLog.hpp"),
                ("frc::sysid::SysIdRoutineLog::MotorLog", "frc__sysid__SysIdRoutineLog__MotorLog.hpp"),
            ],
        ),
        struct(
            class_name = "Color",
            yml_file = "semiwrap/Color.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/util/Color.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Color", "frc__Color.hpp"),
            ],
        ),
        struct(
            class_name = "Color8Bit",
            yml_file = "semiwrap/Color8Bit.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/util/Color8Bit.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Color8Bit", "frc__Color8Bit.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpilib.resolve_casters",
        caster_deps = [resolve_caster_file("wpiutil-casters"), resolve_caster_file("wpimath-casters")],
        casters_pkl_file = "wpilib.casters.pkl",
        dep_file = "wpilib.casters.d",
    )

    gen_libinit(
        name = "wpilib.gen_lib_init",
        output_file = "wpilib/_init__wpilib.py",
        modules = ["native.wpilib._init_robotpy_native_wpilib", "hal._init__wpiHal", "wpiutil._init__wpiutil", "ntcore._init__ntcore", "wpimath._init__wpimath", "wpimath.geometry._init__geometry", "wpimath._controls._init__controls", "wpilib.interfaces._init__interfaces", "wpilib.event._init__event"],
    )

    gen_pkgconf(
        name = "wpilib.gen_pkgconf",
        libinit_py = "wpilib._init__wpilib",
        module_pkg_name = "wpilib._wpilib",
        output_file = "wpilib.pc",
        pkg_name = "wpilib",
        install_path = "wpilib",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpilib.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPILIB_HEADER_GEN],
        libname = "_wpilib",
        output_file = "semiwrap_init.wpilib._wpilib.hpp",
    )

    run_header_gen(
        name = "wpilib",
        casters_pickle = "wpilib.casters.pkl",
        header_gen_config = WPILIB_HEADER_GEN,
        trampoline_subpath = "wpilib",
        deps = header_to_dat_deps + ["wpilib/src/rpy/Filesystem.h", "wpilib/src/rpy/Notifier.h", "wpilib/src/rpy/MotorControllerGroup.h"],
        local_native_libraries = [
            local_native_libraries_helper("datalog"),
            local_native_libraries_helper("ntcore"),
            local_native_libraries_helper("wpihal"),
            local_native_libraries_helper("wpilib"),
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpinet"),
            local_native_libraries_helper("wpiutil"),
        ],
        generation_defines = ["DYNAMIC_CAMERA_SERVER 1"],
    )

    native.filegroup(
        name = "wpilib.generated_files",
        srcs = [
            "wpilib.gen_modinit_hpp.gen",
            "wpilib.header_gen_files",
            "wpilib.gen_pkgconf",
            "wpilib.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpilib",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpilib.generated_srcs"],
        semiwrap_header = [":wpilib.gen_modinit_hpp"],
        deps = deps + [
            ":wpilib.tmpl_hdrs",
            ":wpilib.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
        local_defines = ["DYNAMIC_CAMERA_SERVER=1"],
    )

    make_pyi(
        name = "wpilib.make_pyi",
        extension_package = "wpilib._wpilib",
        extension_library = "copy_wpilib",
        interface_files = [
            "__init__.pyi",
            "sysid.pyi",
        ],
        init_pkgcfgs = [
            "wpilib/event/_init__event.py",
            "wpilib/interfaces/_init__interfaces.py",
            "wpilib/_init__wpilib.py",
            "wpilib/counter/_init__counter.py",
            "wpilib/drive/_init__drive.py",
            "wpilib/simulation/_init__simulation.py",
        ],
        init_packages = [
            "wpilib/event",
            "wpilib/interfaces",
            "wpilib",
            "wpilib/counter",
            "wpilib/drive",
            "wpilib/simulation",
        ],
        install_path = "wpilib/_wpilib",
        python_deps = [
            "//subprojects/pyntcore:import",
            "//subprojects/robotpy-hal:import",
            "//subprojects/robotpy-native-ntcore:import",
            "//subprojects/robotpy-native-wpihal:import",
            "//subprojects/robotpy-native-wpilib:import",
            "//subprojects/robotpy-native-wpimath:import",
            "//subprojects/robotpy-native-wpinet:import",
            "//subprojects/robotpy-native-wpiutil:import",
            "//subprojects/robotpy-wpilog:import",
            "//subprojects/robotpy-wpimath:import",
            "//subprojects/robotpy-wpinet:import",
            "//subprojects/robotpy-wpiutil:import",
        ] + extra_pyi_deps,
        local_extension_deps = [
            ("wpilib/event/_event", "copy_wpilib_event"),
            ("wpilib/interfaces/_interfaces", "copy_wpilib_interfaces"),
            ("wpilib/counter/_counter", "copy_wpilib_counter"),
            ("wpilib/drive/_drive", "copy_wpilib_drive"),
            ("wpilib/simulation/_simulation", "copy_wpilib_simulation"),
        ],
    )

def wpilib_counter_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps=[]):
    WPILIB_COUNTER_HEADER_GEN = [
        struct(
            class_name = "EdgeConfiguration",
            yml_file = "semiwrap/counter/EdgeConfiguration.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/counter/EdgeConfiguration.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Tachometer",
            yml_file = "semiwrap/counter/Tachometer.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/counter/Tachometer.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::Tachometer", "frc__Tachometer.hpp"),
            ],
        ),
        struct(
            class_name = "UpDownCounter",
            yml_file = "semiwrap/counter/UpDownCounter.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/counter/UpDownCounter.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::UpDownCounter", "frc__UpDownCounter.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpilib_counter.resolve_casters",
        caster_deps = [resolve_caster_file("wpiutil-casters"), resolve_caster_file("wpimath-casters")],
        casters_pkl_file = "wpilib_counter.casters.pkl",
        dep_file = "wpilib_counter.casters.d",
    )

    gen_libinit(
        name = "wpilib_counter.gen_lib_init",
        output_file = "wpilib/counter/_init__counter.py",
        modules = ["native.wpilib._init_robotpy_native_wpilib", "wpilib._init__wpilib"],
    )

    gen_pkgconf(
        name = "wpilib_counter.gen_pkgconf",
        libinit_py = "wpilib.counter._init__counter",
        module_pkg_name = "wpilib.counter._counter",
        output_file = "wpilib_counter.pc",
        pkg_name = "wpilib_counter",
        install_path = "wpilib/counter",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpilib_counter.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPILIB_COUNTER_HEADER_GEN],
        libname = "_counter",
        output_file = "semiwrap_init.wpilib.counter._counter.hpp",
    )

    run_header_gen(
        name = "wpilib_counter",
        casters_pickle = "wpilib_counter.casters.pkl",
        header_gen_config = WPILIB_COUNTER_HEADER_GEN,
        trampoline_subpath = "wpilib/counter",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("ntcore"),
            local_native_libraries_helper("wpihal"),
            local_native_libraries_helper("wpilib"),
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpinet"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpilib_counter.generated_files",
        srcs = [
            "wpilib_counter.gen_modinit_hpp.gen",
            "wpilib_counter.header_gen_files",
            "wpilib_counter.gen_pkgconf",
            "wpilib_counter.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpilib_counter",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpilib_counter.generated_srcs"],
        semiwrap_header = [":wpilib_counter.gen_modinit_hpp"],
        deps = deps + [
            ":wpilib_counter.tmpl_hdrs",
            ":wpilib_counter.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    make_pyi(
        name = "wpilib_counter.make_pyi",
        extension_package = "wpilib.counter._counter",
        extension_library = "copy_wpilib_counter",
        interface_files = [
            "_counter.pyi",
        ],
        init_pkgcfgs = [
            "wpilib/event/_init__event.py",
            "wpilib/interfaces/_init__interfaces.py",
            "wpilib/_init__wpilib.py",
            "wpilib/counter/_init__counter.py",
            "wpilib/drive/_init__drive.py",
            "wpilib/simulation/_init__simulation.py",
        ],
        init_packages = [
            "wpilib/event",
            "wpilib/interfaces",
            "wpilib",
            "wpilib/counter",
            "wpilib/drive",
            "wpilib/simulation",
        ],
        install_path = "wpilib/counter",
        python_deps = [
            "//subprojects/pyntcore:import",
            "//subprojects/robotpy-hal:import",
            "//subprojects/robotpy-native-ntcore:import",
            "//subprojects/robotpy-native-wpihal:import",
            "//subprojects/robotpy-native-wpilib:import",
            "//subprojects/robotpy-native-wpimath:import",
            "//subprojects/robotpy-native-wpinet:import",
            "//subprojects/robotpy-native-wpiutil:import",
            "//subprojects/robotpy-wpilog:import",
            "//subprojects/robotpy-wpimath:import",
            "//subprojects/robotpy-wpinet:import",
            "//subprojects/robotpy-wpiutil:import",
        ] + extra_pyi_deps,
        local_extension_deps = [
            ("wpilib/event/_event", "copy_wpilib_event"),
            ("wpilib/interfaces/_interfaces", "copy_wpilib_interfaces"),
            ("wpilib/_wpilib", "copy_wpilib"),
            ("wpilib/drive/_drive", "copy_wpilib_drive"),
            ("wpilib/simulation/_simulation", "copy_wpilib_simulation"),
        ],
    )

def wpilib_drive_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps=[]):
    WPILIB_DRIVE_HEADER_GEN = [
        struct(
            class_name = "DifferentialDrive",
            yml_file = "semiwrap/drive/DifferentialDrive.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/drive/DifferentialDrive.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::DifferentialDrive", "frc__DifferentialDrive.hpp"),
                ("frc::DifferentialDrive::WheelSpeeds", "frc__DifferentialDrive__WheelSpeeds.hpp"),
            ],
        ),
        struct(
            class_name = "MecanumDrive",
            yml_file = "semiwrap/drive/MecanumDrive.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/drive/MecanumDrive.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::MecanumDrive", "frc__MecanumDrive.hpp"),
                ("frc::MecanumDrive::WheelSpeeds", "frc__MecanumDrive__WheelSpeeds.hpp"),
            ],
        ),
        struct(
            class_name = "RobotDriveBase",
            yml_file = "semiwrap/drive/RobotDriveBase.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/drive/RobotDriveBase.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::RobotDriveBase", "frc__RobotDriveBase.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpilib_drive.resolve_casters",
        caster_deps = [resolve_caster_file("wpiutil-casters"), resolve_caster_file("wpimath-casters")],
        casters_pkl_file = "wpilib_drive.casters.pkl",
        dep_file = "wpilib_drive.casters.d",
    )

    gen_libinit(
        name = "wpilib_drive.gen_lib_init",
        output_file = "wpilib/drive/_init__drive.py",
        modules = ["native.wpilib._init_robotpy_native_wpilib", "wpilib._init__wpilib"],
    )

    gen_pkgconf(
        name = "wpilib_drive.gen_pkgconf",
        libinit_py = "wpilib.drive._init__drive",
        module_pkg_name = "wpilib.drive._drive",
        output_file = "wpilib_drive.pc",
        pkg_name = "wpilib_drive",
        install_path = "wpilib/drive",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpilib_drive.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPILIB_DRIVE_HEADER_GEN],
        libname = "_drive",
        output_file = "semiwrap_init.wpilib.drive._drive.hpp",
    )

    run_header_gen(
        name = "wpilib_drive",
        casters_pickle = "wpilib_drive.casters.pkl",
        header_gen_config = WPILIB_DRIVE_HEADER_GEN,
        trampoline_subpath = "wpilib/drive",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("ntcore"),
            local_native_libraries_helper("wpihal"),
            local_native_libraries_helper("wpilib"),
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpinet"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpilib_drive.generated_files",
        srcs = [
            "wpilib_drive.gen_modinit_hpp.gen",
            "wpilib_drive.header_gen_files",
            "wpilib_drive.gen_pkgconf",
            "wpilib_drive.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpilib_drive",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpilib_drive.generated_srcs"],
        semiwrap_header = [":wpilib_drive.gen_modinit_hpp"],
        deps = deps + [
            ":wpilib_drive.tmpl_hdrs",
            ":wpilib_drive.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    make_pyi(
        name = "wpilib_drive.make_pyi",
        extension_package = "wpilib.drive._drive",
        extension_library = "copy_wpilib_drive",
        interface_files = [
            "_drive.pyi",
        ],
        init_pkgcfgs = [
            "wpilib/event/_init__event.py",
            "wpilib/interfaces/_init__interfaces.py",
            "wpilib/_init__wpilib.py",
            "wpilib/counter/_init__counter.py",
            "wpilib/drive/_init__drive.py",
            "wpilib/simulation/_init__simulation.py",
        ],
        init_packages = [
            "wpilib/event",
            "wpilib/interfaces",
            "wpilib",
            "wpilib/counter",
            "wpilib/drive",
            "wpilib/simulation",
        ],
        install_path = "wpilib/drive",
        python_deps = [
            "//subprojects/pyntcore:import",
            "//subprojects/robotpy-hal:import",
            "//subprojects/robotpy-native-ntcore:import",
            "//subprojects/robotpy-native-wpihal:import",
            "//subprojects/robotpy-native-wpilib:import",
            "//subprojects/robotpy-native-wpimath:import",
            "//subprojects/robotpy-native-wpinet:import",
            "//subprojects/robotpy-native-wpiutil:import",
            "//subprojects/robotpy-wpilog:import",
            "//subprojects/robotpy-wpimath:import",
            "//subprojects/robotpy-wpinet:import",
            "//subprojects/robotpy-wpiutil:import",
        ] + extra_pyi_deps,
        local_extension_deps = [
            ("wpilib/event/_event", "copy_wpilib_event"),
            ("wpilib/interfaces/_interfaces", "copy_wpilib_interfaces"),
            ("wpilib/_wpilib", "copy_wpilib"),
            ("wpilib/counter/_counter", "copy_wpilib_counter"),
            ("wpilib/simulation/_simulation", "copy_wpilib_simulation"),
        ],
    )

def wpilib_simulation_extension(entry_point, deps, header_to_dat_deps = [], extension_name = None, extra_hdrs = [], extra_srcs = [], includes = [], extra_pyi_deps=[]):
    WPILIB_SIMULATION_HEADER_GEN = [
        struct(
            class_name = "ADXL345Sim",
            yml_file = "semiwrap/simulation/ADXL345Sim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/ADXL345Sim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::ADXL345Sim", "frc__sim__ADXL345Sim.hpp"),
            ],
        ),
        struct(
            class_name = "AddressableLEDSim",
            yml_file = "semiwrap/simulation/AddressableLEDSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/AddressableLEDSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::AddressableLEDSim", "frc__sim__AddressableLEDSim.hpp"),
            ],
        ),
        struct(
            class_name = "AnalogEncoderSim",
            yml_file = "semiwrap/simulation/AnalogEncoderSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/AnalogEncoderSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::AnalogEncoderSim", "frc__sim__AnalogEncoderSim.hpp"),
            ],
        ),
        struct(
            class_name = "AnalogInputSim",
            yml_file = "semiwrap/simulation/AnalogInputSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/AnalogInputSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::AnalogInputSim", "frc__sim__AnalogInputSim.hpp"),
            ],
        ),
        struct(
            class_name = "BatterySim",
            yml_file = "semiwrap/simulation/BatterySim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/BatterySim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::BatterySim", "frc__sim__BatterySim.hpp"),
            ],
        ),
        struct(
            class_name = "CTREPCMSim",
            yml_file = "semiwrap/simulation/CTREPCMSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/CTREPCMSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::CTREPCMSim", "frc__sim__CTREPCMSim.hpp"),
            ],
        ),
        struct(
            class_name = "CallbackStore",
            yml_file = "semiwrap/simulation/CallbackStore.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/CallbackStore.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::CallbackStore", "frc__sim__CallbackStore.hpp"),
            ],
        ),
        struct(
            class_name = "DCMotorSim",
            yml_file = "semiwrap/simulation/DCMotorSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/DCMotorSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::DCMotorSim", "frc__sim__DCMotorSim.hpp"),
            ],
        ),
        struct(
            class_name = "DIOSim",
            yml_file = "semiwrap/simulation/DIOSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/DIOSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::DIOSim", "frc__sim__DIOSim.hpp"),
            ],
        ),
        struct(
            class_name = "DifferentialDrivetrainSim",
            yml_file = "semiwrap/simulation/DifferentialDrivetrainSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/DifferentialDrivetrainSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::DifferentialDrivetrainSim", "frc__sim__DifferentialDrivetrainSim.hpp"),
                ("frc::sim::DifferentialDrivetrainSim::State", "frc__sim__DifferentialDrivetrainSim__State.hpp"),
                ("frc::sim::DifferentialDrivetrainSim::KitbotGearing", "frc__sim__DifferentialDrivetrainSim__KitbotGearing.hpp"),
                ("frc::sim::DifferentialDrivetrainSim::KitbotMotor", "frc__sim__DifferentialDrivetrainSim__KitbotMotor.hpp"),
                ("frc::sim::DifferentialDrivetrainSim::KitbotWheelSize", "frc__sim__DifferentialDrivetrainSim__KitbotWheelSize.hpp"),
            ],
        ),
        struct(
            class_name = "DigitalPWMSim",
            yml_file = "semiwrap/simulation/DigitalPWMSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/DigitalPWMSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::DigitalPWMSim", "frc__sim__DigitalPWMSim.hpp"),
            ],
        ),
        struct(
            class_name = "DoubleSolenoidSim",
            yml_file = "semiwrap/simulation/DoubleSolenoidSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/DoubleSolenoidSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::DoubleSolenoidSim", "frc__sim__DoubleSolenoidSim.hpp"),
            ],
        ),
        struct(
            class_name = "DriverStationSim",
            yml_file = "semiwrap/simulation/DriverStationSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/DriverStationSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::DriverStationSim", "frc__sim__DriverStationSim.hpp"),
            ],
        ),
        struct(
            class_name = "DutyCycleEncoderSim",
            yml_file = "semiwrap/simulation/DutyCycleEncoderSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/DutyCycleEncoderSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::DutyCycleEncoderSim", "frc__sim__DutyCycleEncoderSim.hpp"),
            ],
        ),
        struct(
            class_name = "DutyCycleSim",
            yml_file = "semiwrap/simulation/DutyCycleSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/DutyCycleSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::DutyCycleSim", "frc__sim__DutyCycleSim.hpp"),
            ],
        ),
        struct(
            class_name = "ElevatorSim",
            yml_file = "semiwrap/simulation/ElevatorSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/ElevatorSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::ElevatorSim", "frc__sim__ElevatorSim.hpp"),
            ],
        ),
        struct(
            class_name = "EncoderSim",
            yml_file = "semiwrap/simulation/EncoderSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/EncoderSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::EncoderSim", "frc__sim__EncoderSim.hpp"),
            ],
        ),
        struct(
            class_name = "FlywheelSim",
            yml_file = "semiwrap/simulation/FlywheelSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/FlywheelSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::FlywheelSim", "frc__sim__FlywheelSim.hpp"),
            ],
        ),
        struct(
            class_name = "GenericHIDSim",
            yml_file = "semiwrap/simulation/GenericHIDSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/GenericHIDSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::GenericHIDSim", "frc__sim__GenericHIDSim.hpp"),
            ],
        ),
        struct(
            class_name = "JoystickSim",
            yml_file = "semiwrap/simulation/JoystickSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/JoystickSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::JoystickSim", "frc__sim__JoystickSim.hpp"),
            ],
        ),
        struct(
            class_name = "LinearSystemSim",
            yml_file = "semiwrap/simulation/LinearSystemSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/LinearSystemSim.h",
            tmpl_class_names = [
                ("LinearSystemSim_tmpl1", "LinearSystemSim_1_1_1"),
                ("LinearSystemSim_tmpl2", "LinearSystemSim_1_1_2"),
                ("LinearSystemSim_tmpl3", "LinearSystemSim_2_1_1"),
                ("LinearSystemSim_tmpl4", "LinearSystemSim_2_1_2"),
                ("LinearSystemSim_tmpl5", "LinearSystemSim_2_2_1"),
                ("LinearSystemSim_tmpl6", "LinearSystemSim_2_2_2"),
            ],
            trampolines = [
                ("frc::sim::LinearSystemSim", "frc__sim__LinearSystemSim.hpp"),
            ],
        ),
        struct(
            class_name = "PS4ControllerSim",
            yml_file = "semiwrap/simulation/PS4ControllerSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/PS4ControllerSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::PS4ControllerSim", "frc__sim__PS4ControllerSim.hpp"),
            ],
        ),
        struct(
            class_name = "PS5ControllerSim",
            yml_file = "semiwrap/simulation/PS5ControllerSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/PS5ControllerSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::PS5ControllerSim", "frc__sim__PS5ControllerSim.hpp"),
            ],
        ),
        struct(
            class_name = "PWMSim",
            yml_file = "semiwrap/simulation/PWMSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/PWMSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::PWMSim", "frc__sim__PWMSim.hpp"),
            ],
        ),
        struct(
            class_name = "PneumaticsBaseSim",
            yml_file = "semiwrap/simulation/PneumaticsBaseSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/PneumaticsBaseSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::PneumaticsBaseSim", "frc__sim__PneumaticsBaseSim.hpp"),
            ],
        ),
        struct(
            class_name = "PowerDistributionSim",
            yml_file = "semiwrap/simulation/PowerDistributionSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/PowerDistributionSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::PowerDistributionSim", "frc__sim__PowerDistributionSim.hpp"),
            ],
        ),
        struct(
            class_name = "PWMMotorControllerSim",
            yml_file = "semiwrap/simulation/PWMMotorControllerSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/PWMMotorControllerSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::PWMMotorControllerSim", "frc__sim__PWMMotorControllerSim.hpp"),
            ],
        ),
        struct(
            class_name = "REVPHSim",
            yml_file = "semiwrap/simulation/REVPHSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/REVPHSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::REVPHSim", "frc__sim__REVPHSim.hpp"),
            ],
        ),
        struct(
            class_name = "RoboRioSim",
            yml_file = "semiwrap/simulation/RoboRioSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/RoboRioSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::RoboRioSim", "frc__sim__RoboRioSim.hpp"),
            ],
        ),
        struct(
            class_name = "SendableChooserSim",
            yml_file = "semiwrap/simulation/SendableChooserSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/SendableChooserSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::SendableChooserSim", "frc__sim__SendableChooserSim.hpp"),
            ],
        ),
        struct(
            class_name = "ServoSim",
            yml_file = "semiwrap/simulation/ServoSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/ServoSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::ServoSim", "frc__sim__ServoSim.hpp"),
            ],
        ),
        struct(
            class_name = "SharpIRSim",
            yml_file = "semiwrap/simulation/SharpIRSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/SharpIRSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::SharpIRSim", "frc__SharpIRSim.hpp"),
            ],
        ),
        struct(
            class_name = "SimDeviceSim",
            yml_file = "semiwrap/simulation/SimDeviceSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/SimDeviceSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::SimDeviceSim", "frc__sim__SimDeviceSim.hpp"),
            ],
        ),
        struct(
            class_name = "SimHooks",
            yml_file = "semiwrap/simulation/SimHooks.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/SimHooks.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "SingleJointedArmSim",
            yml_file = "semiwrap/simulation/SingleJointedArmSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/SingleJointedArmSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::SingleJointedArmSim", "frc__sim__SingleJointedArmSim.hpp"),
            ],
        ),
        struct(
            class_name = "SolenoidSim",
            yml_file = "semiwrap/simulation/SolenoidSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/SolenoidSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::SolenoidSim", "frc__sim__SolenoidSim.hpp"),
            ],
        ),
        struct(
            class_name = "StadiaControllerSim",
            yml_file = "semiwrap/simulation/StadiaControllerSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/StadiaControllerSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::StadiaControllerSim", "frc__sim__StadiaControllerSim.hpp"),
            ],
        ),
        struct(
            class_name = "XboxControllerSim",
            yml_file = "semiwrap/simulation/XboxControllerSim.yml",
            header_root = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib"),
            header_file = resolve_include_root("//subprojects/robotpy-native-wpilib", "wpilib") + "/frc/simulation/XboxControllerSim.h",
            tmpl_class_names = [],
            trampolines = [
                ("frc::sim::XboxControllerSim", "frc__sim__XboxControllerSim.hpp"),
            ],
        ),
    ]

    resolve_casters(
        name = "wpilib_simulation.resolve_casters",
        caster_deps = [resolve_caster_file("wpiutil-casters"), resolve_caster_file("wpimath-casters")],
        casters_pkl_file = "wpilib_simulation.casters.pkl",
        dep_file = "wpilib_simulation.casters.d",
    )

    gen_libinit(
        name = "wpilib_simulation.gen_lib_init",
        output_file = "wpilib/simulation/_init__simulation.py",
        modules = ["native.wpilib._init_robotpy_native_wpilib", "wpilib._init__wpilib", "wpimath._controls._init__controls", "wpimath.geometry._init__geometry", "wpimath.kinematics._init__kinematics"],
    )

    gen_pkgconf(
        name = "wpilib_simulation.gen_pkgconf",
        libinit_py = "wpilib.simulation._init__simulation",
        module_pkg_name = "wpilib.simulation._simulation",
        output_file = "wpilib_simulation.pc",
        pkg_name = "wpilib_simulation",
        install_path = "wpilib/simulation",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpilib_simulation.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPILIB_SIMULATION_HEADER_GEN],
        libname = "_simulation",
        output_file = "semiwrap_init.wpilib.simulation._simulation.hpp",
    )

    run_header_gen(
        name = "wpilib_simulation",
        casters_pickle = "wpilib_simulation.casters.pkl",
        header_gen_config = WPILIB_SIMULATION_HEADER_GEN,
        trampoline_subpath = "wpilib/simulation",
        deps = header_to_dat_deps,
        local_native_libraries = [
            local_native_libraries_helper("ntcore"),
            local_native_libraries_helper("wpihal"),
            local_native_libraries_helper("wpilib"),
            local_native_libraries_helper("wpimath"),
            local_native_libraries_helper("wpinet"),
            local_native_libraries_helper("wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpilib_simulation.generated_files",
        srcs = [
            "wpilib_simulation.gen_modinit_hpp.gen",
            "wpilib_simulation.header_gen_files",
            "wpilib_simulation.gen_pkgconf",
            "wpilib_simulation.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpilib_simulation",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpilib_simulation.generated_srcs"],
        semiwrap_header = [":wpilib_simulation.gen_modinit_hpp"],
        deps = deps + [
            ":wpilib_simulation.tmpl_hdrs",
            ":wpilib_simulation.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

    make_pyi(
        name = "wpilib_simulation.make_pyi",
        extension_package = "wpilib.simulation._simulation",
        extension_library = "copy_wpilib_simulation",
        interface_files = [
            "_simulation.pyi",
        ],
        init_pkgcfgs = [
            "wpilib/event/_init__event.py",
            "wpilib/interfaces/_init__interfaces.py",
            "wpilib/_init__wpilib.py",
            "wpilib/counter/_init__counter.py",
            "wpilib/drive/_init__drive.py",
            "wpilib/simulation/_init__simulation.py",
        ],
        init_packages = [
            "wpilib/event",
            "wpilib/interfaces",
            "wpilib",
            "wpilib/counter",
            "wpilib/drive",
            "wpilib/simulation",
        ],
        install_path = "wpilib/simulation",
        python_deps = [
            "//subprojects/pyntcore:import",
            "//subprojects/robotpy-hal:import",
            "//subprojects/robotpy-native-ntcore:import",
            "//subprojects/robotpy-native-wpihal:import",
            "//subprojects/robotpy-native-wpilib:import",
            "//subprojects/robotpy-native-wpimath:import",
            "//subprojects/robotpy-native-wpinet:import",
            "//subprojects/robotpy-native-wpiutil:import",
            "//subprojects/robotpy-wpilog:import",
            "//subprojects/robotpy-wpimath:import",
            "//subprojects/robotpy-wpinet:import",
            "//subprojects/robotpy-wpiutil:import",
        ] + extra_pyi_deps,
        local_extension_deps = [
            ("wpilib/event/_event", "copy_wpilib_event"),
            ("wpilib/interfaces/_interfaces", "copy_wpilib_interfaces"),
            ("wpilib/_wpilib", "copy_wpilib"),
            ("wpilib/counter/_counter", "copy_wpilib_counter"),
            ("wpilib/drive/_drive", "copy_wpilib_drive"),
        ],
    )

def get_generated_data_files():
    copy_extension_library(
        name = "copy_wpilib_event",
        extension = "_event",
        output_directory = "wpilib/event/",
    )
    copy_extension_library(
        name = "copy_wpilib_interfaces",
        extension = "_interfaces",
        output_directory = "wpilib/interfaces/",
    )
    copy_extension_library(
        name = "copy_wpilib",
        extension = "_wpilib",
        output_directory = "wpilib/",
    )
    copy_extension_library(
        name = "copy_wpilib_counter",
        extension = "_counter",
        output_directory = "wpilib/counter/",
    )
    copy_extension_library(
        name = "copy_wpilib_drive",
        extension = "_drive",
        output_directory = "wpilib/drive/",
    )
    copy_extension_library(
        name = "copy_wpilib_simulation",
        extension = "_simulation",
        output_directory = "wpilib/simulation/",
    )

    native.filegroup(
        name = "wpilib.generated_data_files",
        srcs = [
            "wpilib/event/wpilib_event.pc",
            "wpilib/interfaces/wpilib_interfaces.pc",
            "wpilib/wpilib.pc",
            "wpilib/counter/wpilib_counter.pc",
            "wpilib/drive/wpilib_drive.pc",
            "wpilib/simulation/wpilib_simulation.pc",
        ],
    )

    return [
        ":wpilib.generated_data_files",
        ":copy_wpilib_event",
        ":copy_wpilib_interfaces",
        ":copy_wpilib",
        ":copy_wpilib_counter",
        ":copy_wpilib_drive",
        ":copy_wpilib_simulation",
        ":wpilib_event.trampoline_hdr_files",
        ":wpilib_interfaces.trampoline_hdr_files",
        ":wpilib.trampoline_hdr_files",
        ":wpilib_counter.trampoline_hdr_files",
        ":wpilib_drive.trampoline_hdr_files",
        ":wpilib_simulation.trampoline_hdr_files",
    ]

def libinit_files():
    return [
        "wpilib/event/_init__event.py",
        "wpilib/interfaces/_init__interfaces.py",
        "wpilib/_init__wpilib.py",
        "wpilib/counter/_init__counter.py",
        "wpilib/drive/_init__drive.py",
        "wpilib/simulation/_init__simulation.py",
    ]

def define_pybind_library(name, version, extra_entry_points = {}):
    native.filegroup(
        name = "wpilib.extra_pkg_files",
        srcs = native.glob(["wpilib/**"], exclude = ["wpilib/**/*.py"], allow_empty=True),
        tags = ["manual"],
    )

    native.filegroup(
        name = "pyi_files",
        srcs = [
            ":wpilib_event.make_pyi",
            ":wpilib_interfaces.make_pyi",
            ":wpilib.make_pyi",
            ":wpilib_counter.make_pyi",
            ":wpilib_drive.make_pyi",
            ":wpilib_simulation.make_pyi",
        ],
    )

    robotpy_library(
        name = name,
        srcs = native.glob(["wpilib/**/*.py"]) + libinit_files(),
        data = get_generated_data_files() + ["wpilib.extra_pkg_files", ":pyi_files"],
        imports = ["."],
        robotpy_wheel_deps = [
            "//subprojects/pyntcore:import",
            "//subprojects/robotpy-hal:import",
            "//subprojects/robotpy-native-ntcore:import",
            "//subprojects/robotpy-native-wpihal:import",
            "//subprojects/robotpy-native-wpilib:import",
            "//subprojects/robotpy-native-wpimath:import",
            "//subprojects/robotpy-native-wpinet:import",
            "//subprojects/robotpy-native-wpiutil:import",
            "//subprojects/robotpy-wpilog:import",
            "//subprojects/robotpy-wpimath:import",
            "//subprojects/robotpy-wpinet:import",
            "//subprojects/robotpy-wpiutil:import",
        ],
        strip_path_prefixes = ["subprojects/robotpy-wpilib"],
        version = version,
        visibility = ["//visibility:public"],
        entry_points = {
            "pkg_config": [
                "wpilib_event = wpilib.event",
                "wpilib_interfaces = wpilib.interfaces",
                "wpilib = wpilib",
                "wpilib_counter = wpilib.counter",
                "wpilib_drive = wpilib.drive",
                "wpilib_simulation = wpilib.simulation",
            ],
        }.update(extra_entry_points),
        package_name = "wpilib",
        package_summary = "Binary wrapper for FRC WPILib",
        package_project_urls = {"Source code": "https://github.com/robotpy/mostrobotpy"},
        package_author_email = "RobotPy Development Team <robotpy@googlegroups.com>",
        package_requires = ["robotpy-native-wpilib==2027.0.0a1.dev0", "robotpy-wpiutil==2027.0.0a1.dev0", "robotpy-wpimath==2027.0.0a1.dev0", "robotpy-hal==2027.0.0a1.dev0", "pyntcore==2027.0.0a1.dev0", "robotpy-cli~=2024.0b"],
    )
