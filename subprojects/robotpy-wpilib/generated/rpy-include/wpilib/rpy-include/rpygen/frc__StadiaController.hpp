

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/StadiaController.h>










#include <rpygen/frc__GenericHID.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__StadiaController :


    PyTrampolineCfg_frc__GenericHID<

CfgBase
>

{
    using Base = frc::StadiaController;

    
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__StadiaController =

    PyTrampoline_frc__GenericHID<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__StadiaController : PyTrampolineBase_frc__StadiaController<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__StadiaController<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__StadiaController;



  using Button [[maybe_unused]] = typename frc::StadiaController::Button;

  using Axis [[maybe_unused]] = typename frc::StadiaController::Axis;









    
    

    
    

    

    
};

}; // namespace rpygen


