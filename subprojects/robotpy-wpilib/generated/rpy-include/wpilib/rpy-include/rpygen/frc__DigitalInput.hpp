

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/DigitalInput.h>


#include <wpi/sendable/SendableBuilder.h>

#include <frc/DigitalGlitchFilter.h>









#include <rpygen/frc__DigitalSource.hpp>

#include <rpygen/wpi__Sendable.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__DigitalInput :


    PyTrampolineCfg_frc__DigitalSource<

    PyTrampolineCfg_wpi__Sendable<

CfgBase
>>

{
    using Base = frc::DigitalInput;

    
    
    using override_base_KGetPortHandleForRouting_v = frc::DigitalInput;
    
    using override_base_KGetAnalogTriggerTypeForRouting_v = frc::DigitalInput;
    
    using override_base_KIsAnalogTrigger_v = frc::DigitalInput;
    
    using override_base_KGetChannel_v = frc::DigitalInput;
    
    using override_base_InitSendable_RTSendableBuilder = frc::DigitalInput;
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__DigitalInput =

    PyTrampoline_frc__DigitalSource<

    PyTrampoline_wpi__Sendable<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__DigitalInput : PyTrampolineBase_frc__DigitalInput<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__DigitalInput<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__DigitalInput;











    
    
#ifndef RPYGEN_DISABLE_KGetPortHandleForRouting_v
    HAL_Handle GetPortHandleForRouting() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetPortHandleForRouting_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(HAL_Handle), LookupBase,
            "getPortHandleForRouting", );
        return CxxCallBase::GetPortHandleForRouting();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetAnalogTriggerTypeForRouting_v
    AnalogTriggerType GetAnalogTriggerTypeForRouting() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetAnalogTriggerTypeForRouting_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(AnalogTriggerType), LookupBase,
            "getAnalogTriggerTypeForRouting", );
        return CxxCallBase::GetAnalogTriggerTypeForRouting();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KIsAnalogTrigger_v
    bool IsAnalogTrigger() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KIsAnalogTrigger_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(bool), LookupBase,
            "isAnalogTrigger", );
        return CxxCallBase::IsAnalogTrigger();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetChannel_v
    int GetChannel() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetChannel_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(int), LookupBase,
            "getChannel", );
        return CxxCallBase::GetChannel();
    
    
    
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

