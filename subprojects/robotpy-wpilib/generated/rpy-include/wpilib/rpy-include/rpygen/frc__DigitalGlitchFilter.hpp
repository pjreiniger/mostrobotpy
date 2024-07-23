

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/DigitalGlitchFilter.h>


#include <wpi/sendable/SendableBuilder.h>

#include <frc/Counter.h>

#include <frc/Encoder.h>









#include <rpygen/wpi__Sendable.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__DigitalGlitchFilter :


    PyTrampolineCfg_wpi__Sendable<

CfgBase
>

{
    using Base = frc::DigitalGlitchFilter;

    
    
    using override_base_InitSendable_RTSendableBuilder = frc::DigitalGlitchFilter;
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__DigitalGlitchFilter =

    PyTrampoline_wpi__Sendable<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__DigitalGlitchFilter : PyTrampolineBase_frc__DigitalGlitchFilter<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__DigitalGlitchFilter<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__DigitalGlitchFilter;











    
    
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


