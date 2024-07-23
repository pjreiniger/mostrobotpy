

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/simulation/FlywheelSim.h>










#include <rpygen/frc__sim__LinearSystemSim.hpp>



namespace rpygen {


using namespace frc::sim;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__sim__FlywheelSim :


    PyTrampolineCfg_frc__sim__LinearSystemSim<1, 1, 1, 

CfgBase
>

{
    using Base = frc::sim::FlywheelSim;

    
    
    using override_base_KGetCurrentDraw_v = frc::sim::FlywheelSim;
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__sim__FlywheelSim =

    PyTrampoline_frc__sim__LinearSystemSim<

        PyTrampolineBase

        , 1, 1, 1
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__sim__FlywheelSim : PyTrampolineBase_frc__sim__FlywheelSim<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__sim__FlywheelSim<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__sim__FlywheelSim;





    using DCMotor = frc::DCMotor;

    template <int S, int I, int O> using LinearSystem = frc::LinearSystem<S, I, O>;







    
    
#ifndef RPYGEN_DISABLE_KGetCurrentDraw_v
    units::ampere_t GetCurrentDraw() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetCurrentDraw_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(units::ampere_t), LookupBase,
            "getCurrentDraw", );
        return CxxCallBase::GetCurrentDraw();
    
    
    
    }
#endif

    

    
    

    

    
};

}; // namespace rpygen


