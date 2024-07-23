

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/trajectory/constraint/TrajectoryConstraint.h>










namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__TrajectoryConstraint :

    CfgBase

{
    using Base = frc::TrajectoryConstraint;

    
    
    using override_base_KMaxVelocity_KRTPose2d_Tcurvature_t_Tmeters_per_second_t = frc::TrajectoryConstraint;
    
    using override_base_KMinMaxAcceleration_KRTPose2d_Tcurvature_t_Tmeters_per_second_t = frc::TrajectoryConstraint;
    
};



template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__TrajectoryConstraint : PyTrampolineBase, virtual py::trampoline_self_life_support {
    using PyTrampolineBase::PyTrampolineBase;



  using MinMax [[maybe_unused]] = typename frc::TrajectoryConstraint::MinMax;









    
    
#ifndef RPYGEN_DISABLE_KMaxVelocity_KRTPose2d_Tcurvature_t_Tmeters_per_second_t
    units::meters_per_second_t MaxVelocity(const Pose2d& pose, units::curvature_t curvature, units::meters_per_second_t velocity) const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(TrajectoryConstraint, PYBIND11_TYPE(units::meters_per_second_t), LookupBase,
            "maxVelocity", MaxVelocity, pose, curvature, velocity);
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KMinMaxAcceleration_KRTPose2d_Tcurvature_t_Tmeters_per_second_t
    MinMax MinMaxAcceleration(const Pose2d& pose, units::curvature_t curvature, units::meters_per_second_t speed) const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(TrajectoryConstraint, PYBIND11_TYPE(MinMax), LookupBase,
            "minMaxAcceleration", MinMaxAcceleration, pose, curvature, speed);
    
    
    
    }
#endif

    

    
    

    

    
};

}; // namespace rpygen


