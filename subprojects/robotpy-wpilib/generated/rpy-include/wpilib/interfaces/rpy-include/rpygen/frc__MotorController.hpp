

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/motorcontrol/MotorController.h>










namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__MotorController :

    CfgBase

{
    using Base = frc::MotorController;

    
    
    using override_base_Set_d = frc::MotorController;
    
    using override_base_SetVoltage_Tvolt_t = frc::MotorController;
    
    using override_base_KGet_v = frc::MotorController;
    
    using override_base_SetInverted_b = frc::MotorController;
    
    using override_base_KGetInverted_v = frc::MotorController;
    
    using override_base_Disable_v = frc::MotorController;
    
    using override_base_StopMotor_v = frc::MotorController;
    
};



template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__MotorController : PyTrampolineBase, virtual py::trampoline_self_life_support {
    using PyTrampolineBase::PyTrampolineBase;











    
    
#ifndef RPYGEN_DISABLE_Set_d
    void Set(double speed) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(MotorController, PYBIND11_TYPE(void), LookupBase,
            "set", Set, speed);
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SetVoltage_Tvolt_t
    void SetVoltage(units::volt_t output) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_SetVoltage_Tvolt_t;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "setVoltage", output);
        return CxxCallBase::SetVoltage(std::move(output));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGet_v
    double Get() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(MotorController, PYBIND11_TYPE(double), LookupBase,
            "get", Get, );
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SetInverted_b
    void SetInverted(bool isInverted) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(MotorController, PYBIND11_TYPE(void), LookupBase,
            "setInverted", SetInverted, isInverted);
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetInverted_v
    bool GetInverted() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(MotorController, PYBIND11_TYPE(bool), LookupBase,
            "getInverted", GetInverted, );
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_Disable_v
    void Disable() override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(MotorController, PYBIND11_TYPE(void), LookupBase,
            "disable", Disable, );
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_StopMotor_v
    void StopMotor() override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(MotorController, PYBIND11_TYPE(void), LookupBase,
            "stopMotor", StopMotor, );
    
    
    
    }
#endif

    

    
    

    

    
};

}; // namespace rpygen

