

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/kinematics/MecanumDriveKinematics.h>


#include <wpystruct.h>









#include <rpygen/frc__Kinematics.hpp>



namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__MecanumDriveKinematics :


    PyTrampolineCfg_frc__Kinematics<MecanumDriveWheelSpeeds, MecanumDriveWheelPositions, 

CfgBase
>

{
    using Base = frc::MecanumDriveKinematics;

    
    
    using override_base_KToWheelSpeeds_KRTChassisSpeeds = frc::MecanumDriveKinematics;
    
    using override_base_KToChassisSpeeds_KRTMecanumDriveWheelSpeeds = frc::MecanumDriveKinematics;
    
    using override_base_KToTwist2d_KRTMecanumDriveWheelPositions_KRTMecanumDriveWheelPositions = frc::MecanumDriveKinematics;
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__MecanumDriveKinematics =

    PyTrampoline_frc__Kinematics<

        PyTrampolineBase

        , MecanumDriveWheelSpeeds, MecanumDriveWheelPositions
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__MecanumDriveKinematics : PyTrampolineBase_frc__MecanumDriveKinematics<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__MecanumDriveKinematics<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__MecanumDriveKinematics;











    
    
#ifndef RPYGEN_DISABLE_KToWheelSpeeds_KRTChassisSpeeds
    MecanumDriveWheelSpeeds ToWheelSpeeds(const ChassisSpeeds& chassisSpeeds) const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KToWheelSpeeds_KRTChassisSpeeds;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(MecanumDriveWheelSpeeds), LookupBase,
            "toWheelSpeeds", chassisSpeeds);
        return CxxCallBase::ToWheelSpeeds(std::forward<decltype(chassisSpeeds)>(chassisSpeeds));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KToChassisSpeeds_KRTMecanumDriveWheelSpeeds
    ChassisSpeeds ToChassisSpeeds(const MecanumDriveWheelSpeeds& wheelSpeeds) const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KToChassisSpeeds_KRTMecanumDriveWheelSpeeds;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(ChassisSpeeds), LookupBase,
            "toChassisSpeeds", wheelSpeeds);
        return CxxCallBase::ToChassisSpeeds(std::forward<decltype(wheelSpeeds)>(wheelSpeeds));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KToTwist2d_KRTMecanumDriveWheelPositions_KRTMecanumDriveWheelPositions
    Twist2d ToTwist2d(const MecanumDriveWheelPositions& start, const MecanumDriveWheelPositions& end) const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KToTwist2d_KRTMecanumDriveWheelPositions_KRTMecanumDriveWheelPositions;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(Twist2d), LookupBase,
            "toTwist2d", start, end);
        return CxxCallBase::ToTwist2d(std::forward<decltype(start)>(start), std::forward<decltype(end)>(end));
    
    
    
    }
#endif

    

    
    

    

    
};

}; // namespace rpygen


