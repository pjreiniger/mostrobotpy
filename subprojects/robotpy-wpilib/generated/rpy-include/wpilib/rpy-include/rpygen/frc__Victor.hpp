

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/motorcontrol/Victor.h>


#include <wpi/sendable/SendableBuilder.h>









#include <rpygen/frc__PWMMotorController.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__Victor :


    PyTrampolineCfg_frc__PWMMotorController<

CfgBase
>

{
    using Base = frc::Victor;

    
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__Victor =

    PyTrampoline_frc__PWMMotorController<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__Victor : PyTrampolineBase_frc__Victor<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__Victor<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__Victor;











    
    

    
    

    

    
};

}; // namespace rpygen

