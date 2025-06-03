load("@rules_semiwrap//:defs.bzl", "copy_extension_library", "create_pybind_library")
load("@rules_semiwrap//rules_semiwrap/private:semiwrap_helpers.bzl", "gen_libinit", "gen_modinit_hpp", "gen_pkgconf", "resolve_casters", "run_header_gen")

def _local_include_root(project_import, include_subpackage):
    return "$(location " + project_import + ")/site-packages/native/" + include_subpackage + "/include"

def hal_simulation_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    HAL_SIMULATION_HEADER_GEN = [
        struct(
            class_name = "AccelerometerData",
            yml_file = "semiwrap/simulation/AccelerometerData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/AccelerometerData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AddressableLEDData",
            yml_file = "semiwrap/simulation/AddressableLEDData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/AddressableLEDData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AnalogGyroData",
            yml_file = "semiwrap/simulation/AnalogGyroData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/AnalogGyroData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AnalogInData",
            yml_file = "semiwrap/simulation/AnalogInData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/AnalogInData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AnalogOutData",
            yml_file = "semiwrap/simulation/AnalogOutData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/AnalogOutData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AnalogTriggerData",
            yml_file = "semiwrap/simulation/AnalogTriggerData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/AnalogTriggerData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "CTREPCMData",
            yml_file = "semiwrap/simulation/CTREPCMData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/CTREPCMData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "DIOData",
            yml_file = "semiwrap/simulation/DIOData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/DIOData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "DigitalPWMData",
            yml_file = "semiwrap/simulation/DigitalPWMData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/DigitalPWMData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "DriverStationData",
            yml_file = "semiwrap/simulation/DriverStationData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/DriverStationData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "DutyCycleData",
            yml_file = "semiwrap/simulation/DutyCycleData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/DutyCycleData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "EncoderData",
            yml_file = "semiwrap/simulation/EncoderData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/EncoderData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "MockHooks",
            yml_file = "semiwrap/simulation/MockHooks.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/MockHooks.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "NotifierData",
            yml_file = "semiwrap/simulation/NotifierData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/NotifierData.h",
            tmpl_class_names = [],
            trampolines = [
                ("HALSIM_NotifierInfo", "__HALSIM_NotifierInfo.hpp"),
            ],
        ),
        struct(
            class_name = "PWMData",
            yml_file = "semiwrap/simulation/PWMData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/PWMData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "PowerDistributionData",
            yml_file = "semiwrap/simulation/PowerDistributionData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/PowerDistributionData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "REVPHData",
            yml_file = "semiwrap/simulation/REVPHData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/REVPHData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "RelayData",
            yml_file = "semiwrap/simulation/RelayData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/RelayData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Reset",
            yml_file = "semiwrap/simulation/Reset.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/Reset.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "RoboRioData",
            yml_file = "semiwrap/simulation/RoboRioData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/RoboRioData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "SPIAccelerometerData",
            yml_file = "semiwrap/simulation/SPIAccelerometerData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/SPIAccelerometerData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "SimDeviceData",
            yml_file = "semiwrap/simulation/SimDeviceData.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/simulation/SimDeviceData.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
    ]
    resolve_casters(
        name = "hal_simulation.resolve_casters",
        caster_files = [
            "$(location //subprojects/robotpy-wpiutil:import)" + "/site-packages/wpiutil/wpiutil-casters.pybind11.json",
        ],
        caster_deps = ["//subprojects/robotpy-wpiutil:import"],
        casters_pkl_file = "hal_simulation.casters.pkl",
        dep_file = "hal_simulation.casters.d",
    )

    gen_libinit(
        name = "hal_simulation.gen_lib_init",
        output_file = "hal/simulation/_init__simulation.py",
        modules = ["native.wpihal._init_robotpy_native_wpihal", "wpiutil._init__wpiutil"],
    )

    gen_pkgconf(
        name = "hal_simulation.gen_pkgconf",
        libinit_py = "hal.simulation._init__simulation",
        module_pkg_name = "hal.simulation._simulation",
        output_file = "hal_simulation.pc",
        pkg_name = "hal_simulation",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "hal_simulation.gen_modinit_hpp",
        input_dats = [x.class_name for x in HAL_SIMULATION_HEADER_GEN],
        libname = "_simulation",
        output_file = "semiwrap_init.hal.simulation._simulation.hpp",
    )

    run_header_gen(
        name = "hal_simulation",
        casters_pickle = "hal_simulation.casters.pkl",
        header_gen_config = HAL_SIMULATION_HEADER_GEN,
        deps = header_to_dat_deps,
        local_native_libraries = [
            ("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            ("//subprojects/robotpy-native-wpiutil:import", "wpiutil"),
        ],
    )

    native.filegroup(
        name = "hal_simulation.generated_files",
        srcs = [
            "hal_simulation.gen_modinit_hpp.gen",
            "hal_simulation.header_gen_files",
            "hal_simulation.gen_pkgconf",
            "hal_simulation.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "hal_simulation",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":hal_simulation.generated_srcs"],
        semiwrap_header = [":hal_simulation.gen_modinit_hpp"],
        deps = deps + [
            ":hal_simulation.tmpl_hdrs",
            ":hal_simulation.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

def wpihal_extension(entry_point, deps, header_to_dat_deps, extension_name = None, extra_hdrs = [], extra_srcs = [], includes = []):
    WPIHAL_HEADER_GEN = [
        struct(
            class_name = "Accelerometer",
            yml_file = "semiwrap/Accelerometer.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Accelerometer.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AddressableLED",
            yml_file = "semiwrap/AddressableLED.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/AddressableLED.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AddressableLEDTypes",
            yml_file = "semiwrap/AddressableLEDTypes.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/AddressableLEDTypes.h",
            tmpl_class_names = [],
            trampolines = [
                ("HAL_AddressableLEDData", "__HAL_AddressableLEDData.hpp"),
            ],
        ),
        struct(
            class_name = "AnalogAccumulator",
            yml_file = "semiwrap/AnalogAccumulator.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/AnalogAccumulator.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AnalogGyro",
            yml_file = "semiwrap/AnalogGyro.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/AnalogGyro.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AnalogInput",
            yml_file = "semiwrap/AnalogInput.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/AnalogInput.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AnalogOutput",
            yml_file = "semiwrap/AnalogOutput.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/AnalogOutput.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "AnalogTrigger",
            yml_file = "semiwrap/AnalogTrigger.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/AnalogTrigger.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "CAN",
            yml_file = "semiwrap/CAN.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/CAN.h",
            tmpl_class_names = [],
            trampolines = [
                ("HAL_CANStreamMessage", "__HAL_CANStreamMessage.hpp"),
            ],
        ),
        struct(
            class_name = "CANAPI",
            yml_file = "semiwrap/CANAPI.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/CANAPI.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "CANAPITypes",
            yml_file = "semiwrap/CANAPITypes.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/CANAPITypes.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "CTREPCM",
            yml_file = "semiwrap/CTREPCM.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/CTREPCM.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Constants",
            yml_file = "semiwrap/Constants.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Constants.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Counter",
            yml_file = "semiwrap/Counter.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Counter.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "DIO",
            yml_file = "semiwrap/DIO.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/DIO.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "DriverStation",
            yml_file = "semiwrap/DriverStation.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/DriverStation.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "DriverStationTypes",
            yml_file = "semiwrap/DriverStationTypes.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/DriverStationTypes.h",
            tmpl_class_names = [],
            trampolines = [
                ("HAL_ControlWord", "__HAL_ControlWord.hpp"),
                ("HAL_JoystickAxes", "__HAL_JoystickAxes.hpp"),
                ("HAL_JoystickPOVs", "__HAL_JoystickPOVs.hpp"),
                ("HAL_JoystickButtons", "__HAL_JoystickButtons.hpp"),
                ("HAL_JoystickDescriptor", "__HAL_JoystickDescriptor.hpp"),
                ("HAL_MatchInfo", "__HAL_MatchInfo.hpp"),
            ],
        ),
        struct(
            class_name = "DutyCycle",
            yml_file = "semiwrap/DutyCycle.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/DutyCycle.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Encoder",
            yml_file = "semiwrap/Encoder.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Encoder.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Extensions",
            yml_file = "semiwrap/Extensions.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Extensions.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "FRCUsageReporting",
            yml_file = "semiwrap/FRCUsageReporting.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/FRCUsageReporting.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "HALBase",
            yml_file = "semiwrap/HALBase.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/HALBase.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "I2C",
            yml_file = "semiwrap/I2C.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/I2C.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "I2CTypes",
            yml_file = "semiwrap/I2CTypes.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/I2CTypes.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Interrupts",
            yml_file = "semiwrap/Interrupts.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Interrupts.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "LEDs",
            yml_file = "semiwrap/LEDs.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/LEDs.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Main",
            yml_file = "semiwrap/Main.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Main.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Notifier",
            yml_file = "semiwrap/Notifier.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Notifier.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "PWM",
            yml_file = "semiwrap/PWM.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/PWM.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Ports",
            yml_file = "semiwrap/Ports.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Ports.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "Power",
            yml_file = "semiwrap/Power.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Power.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "PowerDistribution",
            yml_file = "semiwrap/PowerDistribution.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/PowerDistribution.h",
            tmpl_class_names = [],
            trampolines = [
                ("HAL_PowerDistributionVersion", "__HAL_PowerDistributionVersion.hpp"),
                ("HAL_PowerDistributionFaults", "__HAL_PowerDistributionFaults.hpp"),
                ("HAL_PowerDistributionStickyFaults", "__HAL_PowerDistributionStickyFaults.hpp"),
            ],
        ),
        struct(
            class_name = "REVPH",
            yml_file = "semiwrap/REVPH.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/REVPH.h",
            tmpl_class_names = [],
            trampolines = [
                ("HAL_REVPHVersion", "__HAL_REVPHVersion.hpp"),
                ("HAL_REVPHCompressorConfig", "__HAL_REVPHCompressorConfig.hpp"),
                ("HAL_REVPHFaults", "__HAL_REVPHFaults.hpp"),
                ("HAL_REVPHStickyFaults", "__HAL_REVPHStickyFaults.hpp"),
            ],
        ),
        struct(
            class_name = "Relay",
            yml_file = "semiwrap/Relay.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Relay.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "SPI",
            yml_file = "semiwrap/SPI.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/SPI.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "SPITypes",
            yml_file = "semiwrap/SPITypes.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/SPITypes.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "SerialPort",
            yml_file = "semiwrap/SerialPort.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/SerialPort.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "SimDevice",
            yml_file = "semiwrap/SimDevice.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/SimDevice.h",
            tmpl_class_names = [],
            trampolines = [
                ("hal::SimValue", "hal__SimValue.hpp"),
                ("hal::SimInt", "hal__SimInt.hpp"),
                ("hal::SimLong", "hal__SimLong.hpp"),
                ("hal::SimDouble", "hal__SimDouble.hpp"),
                ("hal::SimEnum", "hal__SimEnum.hpp"),
                ("hal::SimBoolean", "hal__SimBoolean.hpp"),
                ("hal::SimDevice", "hal__SimDevice.hpp"),
            ],
        ),
        struct(
            class_name = "Threads",
            yml_file = "semiwrap/Threads.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/Threads.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
        struct(
            class_name = "HandlesInternal",
            yml_file = "semiwrap/HandlesInternal.yml",
            header_root = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            header_file = _local_include_root("//subprojects/robotpy-native-wpihal:import", "wpihal") + "/hal/handles/HandlesInternal.h",
            tmpl_class_names = [],
            trampolines = [],
        ),
    ]
    resolve_casters(
        name = "wpihal.resolve_casters",
        caster_files = [
            "$(location //subprojects/robotpy-wpiutil:import)" + "/site-packages/wpiutil/wpiutil-casters.pybind11.json",
        ],
        caster_deps = ["//subprojects/robotpy-wpiutil:import"],
        casters_pkl_file = "wpihal.casters.pkl",
        dep_file = "wpihal.casters.d",
    )

    gen_libinit(
        name = "wpihal.gen_lib_init",
        output_file = "hal/_init__wpiHal.py",
        modules = ["native.wpihal._init_robotpy_native_wpihal", "wpiutil._init__wpiutil"],
    )

    gen_pkgconf(
        name = "wpihal.gen_pkgconf",
        libinit_py = "hal._init__wpiHal",
        module_pkg_name = "hal._wpiHal",
        output_file = "wpihal.pc",
        pkg_name = "hal",
        project_file = "pyproject.toml",
    )

    gen_modinit_hpp(
        name = "wpihal.gen_modinit_hpp",
        input_dats = [x.class_name for x in WPIHAL_HEADER_GEN],
        libname = "_wpiHal",
        output_file = "semiwrap_init.hal._wpiHal.hpp",
    )

    run_header_gen(
        name = "wpihal",
        casters_pickle = "wpihal.casters.pkl",
        header_gen_config = WPIHAL_HEADER_GEN,
        deps = header_to_dat_deps,
        local_native_libraries = [
            ("//subprojects/robotpy-native-wpihal:import", "wpihal"),
            ("//subprojects/robotpy-native-wpiutil:import", "wpiutil"),
        ],
    )

    native.filegroup(
        name = "wpihal.generated_files",
        srcs = [
            "wpihal.gen_modinit_hpp.gen",
            "wpihal.header_gen_files",
            "wpihal.gen_pkgconf",
            "wpihal.gen_lib_init",
        ],
        tags = ["manual"],
    )
    create_pybind_library(
        name = "wpiHal",
        entry_point = entry_point,
        extension_name = extension_name,
        generated_srcs = [":wpihal.generated_srcs"],
        semiwrap_header = [":wpihal.gen_modinit_hpp"],
        deps = deps + [
            ":wpihal.tmpl_hdrs",
            ":wpihal.trampoline_hdrs",
        ],
        extra_hdrs = extra_hdrs,
        extra_srcs = extra_srcs,
        includes = includes,
    )

def get_generated_data_files():
    copy_extension_library(
        name = "copy_hal_simulation",
        extension = "_simulation",
        output_directory = "hal/simulation/",
    )

    copy_extension_library(
        name = "copy_wpihal",
        extension = "_wpiHal",
        output_directory = "hal/",
    )

    native.filegroup(
        name = "hal.generated_data_files",
        srcs = [
            "hal/wpihal.pc",
        ],
    )

    return [
        ":hal.generated_data_files",
        ":copy_hal_simulation",
        ":copy_wpihal",
    ]

def libinit_files():
    return [
        "hal/_init__wpiHal.py",
        "hal/simulation/_init__simulation.py",
    ]
