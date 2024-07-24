

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/motorcontrol/VictorSP.h>


#include <wpi/sendable/SendableBuilder.h>









#include <rpygen/frc__PWMMotorController.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__VictorSP :


    PyTrampolineCfg_frc__PWMMotorController<

CfgBase
>

{
    using Base = frc::VictorSP;

    
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__VictorSP =

    PyTrampoline_frc__PWMMotorController<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__VictorSP : PyTrampolineBase_frc__VictorSP<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__VictorSP<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__VictorSP;











    
    

    
    

    

    
};

}; // namespace rpygen

