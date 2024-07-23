

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/ADXL345_SPI.h>


#include <networktables/NTSendableBuilder.h>

#include <frc/DigitalSource.h>









#include <rpygen/nt__NTSendable.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__ADXL345_SPI :


    PyTrampolineCfg_nt__NTSendable<

CfgBase
>

{
    using Base = frc::ADXL345_SPI;

    
    
    using override_base_GetAcceleration_TAxes = frc::ADXL345_SPI;
    
    using override_base_GetAccelerations_v = frc::ADXL345_SPI;
    
    using override_base_InitSendable_RTNTSendableBuilder = frc::ADXL345_SPI;
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__ADXL345_SPI =

    PyTrampoline_nt__NTSendable<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__ADXL345_SPI : PyTrampolineBase_frc__ADXL345_SPI<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__ADXL345_SPI<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__ADXL345_SPI;



  using AllAxes [[maybe_unused]] = typename frc::ADXL345_SPI::AllAxes;


  using Range [[maybe_unused]] = typename frc::ADXL345_SPI::Range;

  using Axes [[maybe_unused]] = typename frc::ADXL345_SPI::Axes;




    static constexpr auto kRange_2G = frc::ADXL345_SPI::Range::kRange_2G;





    
    
#ifndef RPYGEN_DISABLE_GetAcceleration_TAxes
    double GetAcceleration(Axes axis) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_GetAcceleration_TAxes;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(double), LookupBase,
            "getAcceleration", axis);
        return CxxCallBase::GetAcceleration(std::move(axis));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_GetAccelerations_v
    AllAxes GetAccelerations() override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_GetAccelerations_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(AllAxes), LookupBase,
            "getAccelerations", );
        return CxxCallBase::GetAccelerations();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_InitSendable_RTNTSendableBuilder
    void InitSendable(nt::NTSendableBuilder& builder) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_InitSendable_RTNTSendableBuilder;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "initSendable", builder);
        return CxxCallBase::InitSendable(std::forward<decltype(builder)>(builder));
    
    
    
    }
#endif

    

    
    

    

    
};

}; // namespace rpygen


