

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/Joystick.h>


#include <frc/DriverStation.h>









#include <rpygen/frc__GenericHID.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__Joystick :


    PyTrampolineCfg_frc__GenericHID<

CfgBase
>

{
    using Base = frc::Joystick;

    
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__Joystick =

    PyTrampoline_frc__GenericHID<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__Joystick : PyTrampolineBase_frc__Joystick<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__Joystick<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__Joystick;




  using AxisType [[maybe_unused]] = typename frc::Joystick::AxisType;

  using ButtonType [[maybe_unused]] = typename frc::Joystick::ButtonType;



    static constexpr auto kDefaultXChannel [[maybe_unused]] = frc::Joystick::kDefaultXChannel;

    static constexpr auto kDefaultYChannel [[maybe_unused]] = frc::Joystick::kDefaultYChannel;

    static constexpr auto kDefaultZChannel [[maybe_unused]] = frc::Joystick::kDefaultZChannel;

    static constexpr auto kDefaultTwistChannel [[maybe_unused]] = frc::Joystick::kDefaultTwistChannel;

    static constexpr auto kDefaultThrottleChannel [[maybe_unused]] = frc::Joystick::kDefaultThrottleChannel;






    
    

    
    

    

    
};

}; // namespace rpygen


