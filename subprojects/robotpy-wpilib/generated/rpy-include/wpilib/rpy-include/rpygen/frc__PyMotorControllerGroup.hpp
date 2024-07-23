

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <rpy/MotorControllerGroup.h>


#include <wpi/sendable/SendableBuilder.h>

#include <pybind11/stl.h>









#include <rpygen/wpi__Sendable.hpp>

#include <rpygen/frc__MotorController.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__PyMotorControllerGroup :


    PyTrampolineCfg_wpi__Sendable<

    PyTrampolineCfg_frc__MotorController<

CfgBase
>>

{
    using Base = frc::PyMotorControllerGroup;

    
    
    using override_base_Set_d = frc::PyMotorControllerGroup;
    
    using override_base_SetVoltage_Tvolt_t = frc::PyMotorControllerGroup;
    
    using override_base_KGet_v = frc::PyMotorControllerGroup;
    
    using override_base_SetInverted_b = frc::PyMotorControllerGroup;
    
    using override_base_KGetInverted_v = frc::PyMotorControllerGroup;
    
    using override_base_Disable_v = frc::PyMotorControllerGroup;
    
    using override_base_StopMotor_v = frc::PyMotorControllerGroup;
    
    using override_base_InitSendable_RTSendableBuilder = frc::PyMotorControllerGroup;
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__PyMotorControllerGroup =

    PyTrampoline_wpi__Sendable<

    PyTrampoline_frc__MotorController<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__PyMotorControllerGroup : PyTrampolineBase_frc__PyMotorControllerGroup<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__PyMotorControllerGroup<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__PyMotorControllerGroup;











    
    
#ifndef RPYGEN_DISABLE_Set_d
    void Set(double speed) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_Set_d;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "set", speed);
        return CxxCallBase::Set(std::move(speed));
    
    
    
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
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGet_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(double), LookupBase,
            "get", );
        return CxxCallBase::Get();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SetInverted_b
    void SetInverted(bool isInverted) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_SetInverted_b;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "setInverted", isInverted);
        return CxxCallBase::SetInverted(std::move(isInverted));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetInverted_v
    bool GetInverted() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetInverted_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(bool), LookupBase,
            "getInverted", );
        return CxxCallBase::GetInverted();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_Disable_v
    void Disable() override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_Disable_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "disable", );
        return CxxCallBase::Disable();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_StopMotor_v
    void StopMotor() override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_StopMotor_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "stopMotor", );
        return CxxCallBase::StopMotor();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_InitSendable_RTSendableBuilder
    void InitSendable(wpi::SendableBuilder& builder) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_InitSendable_RTSendableBuilder;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "initSendable", builder);
        return CxxCallBase::InitSendable(std::forward<decltype(builder)>(builder));
    
    
    
    }
#endif

    

    
    

    

    
};

}; // namespace rpygen


