

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/ADXRS450_Gyro.h>


#include <wpi/sendable/SendableBuilder.h>

#include <frc/DigitalSource.h>









#include <rpygen/wpi__Sendable.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__ADXRS450_Gyro :


    PyTrampolineCfg_wpi__Sendable<

CfgBase
>

{
    using Base = frc::ADXRS450_Gyro;

    
    
    using override_base_InitSendable_RTSendableBuilder = frc::ADXRS450_Gyro;
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__ADXRS450_Gyro =

    PyTrampoline_wpi__Sendable<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__ADXRS450_Gyro : PyTrampolineBase_frc__ADXRS450_Gyro<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__ADXRS450_Gyro<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__ADXRS450_Gyro;











    
    
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


