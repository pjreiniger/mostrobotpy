

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/motorcontrol/Jaguar.h>


#include <wpi/sendable/SendableBuilder.h>









#include <rpygen/frc__PWMMotorController.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__Jaguar :


    PyTrampolineCfg_frc__PWMMotorController<

CfgBase
>

{
    using Base = frc::Jaguar;

    
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__Jaguar =

    PyTrampoline_frc__PWMMotorController<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__Jaguar : PyTrampolineBase_frc__Jaguar<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__Jaguar<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__Jaguar;











    
    

    
    

    

    
};

}; // namespace rpygen

