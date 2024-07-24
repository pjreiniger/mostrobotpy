

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/Encoder.h>


#include <wpi/sendable/SendableBuilder.h>

#include <frc/DigitalSource.h>

#include <frc/DigitalGlitchFilter.h>

#include <frc/DMA.h>

#include <frc/DMASample.h>









#include <rpygen/frc__CounterBase.hpp>

#include <rpygen/wpi__Sendable.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__Encoder :


    PyTrampolineCfg_frc__CounterBase<

    PyTrampolineCfg_wpi__Sendable<

CfgBase
>>

{
    using Base = frc::Encoder;

    
    
    using override_base_KGet_v = frc::Encoder;
    
    using override_base_Reset_v = frc::Encoder;
    
    using override_base_KGetPeriod_v = frc::Encoder;
    
    using override_base_SetMaxPeriod_Tsecond_t = frc::Encoder;
    
    using override_base_KGetStopped_v = frc::Encoder;
    
    using override_base_KGetDirection_v = frc::Encoder;
    
    using override_base_InitSendable_RTSendableBuilder = frc::Encoder;
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__Encoder =

    PyTrampoline_frc__CounterBase<

    PyTrampoline_wpi__Sendable<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__Encoder : PyTrampolineBase_frc__Encoder<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__Encoder<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__Encoder;




  using IndexingType [[maybe_unused]] = typename frc::Encoder::IndexingType;


    using EncodingType = frc::Encoder::EncodingType;







    
    
#ifndef RPYGEN_DISABLE_KGet_v
    int Get() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGet_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(int), LookupBase,
            "get", );
        return CxxCallBase::Get();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_Reset_v
    void Reset() override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_Reset_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "reset", );
        return CxxCallBase::Reset();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetPeriod_v
    units::second_t GetPeriod() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetPeriod_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(units::second_t), LookupBase,
            "getPeriod", );
        return CxxCallBase::GetPeriod();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SetMaxPeriod_Tsecond_t
    void SetMaxPeriod(units::second_t maxPeriod) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_SetMaxPeriod_Tsecond_t;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "setMaxPeriod", maxPeriod);
        return CxxCallBase::SetMaxPeriod(std::move(maxPeriod));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetStopped_v
    bool GetStopped() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetStopped_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(bool), LookupBase,
            "getStopped", );
        return CxxCallBase::GetStopped();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetDirection_v
    bool GetDirection() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetDirection_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(bool), LookupBase,
            "getDirection", );
        return CxxCallBase::GetDirection();
    
    
    
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

