

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/trajectory/constraint/EllipticalRegionConstraint.h>


#include <PyTrajectoryConstraint.h>









#include <rpygen/frc__TrajectoryConstraint.hpp>



namespace rpygen {


using namespace frc;





template <typename Constraint, typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__EllipticalRegionConstraint :


    PyTrampolineCfg_frc__TrajectoryConstraint<

CfgBase
>

{
    using Base = frc::EllipticalRegionConstraint<Constraint>;

    
    
    using override_base_KMaxVelocity_KRTPose2d_Tcurvature_t_Tmeters_per_second_t = frc::EllipticalRegionConstraint<Constraint>;
    
    using override_base_KMinMaxAcceleration_KRTPose2d_Tcurvature_t_Tmeters_per_second_t = frc::EllipticalRegionConstraint<Constraint>;
    
};




template <typename PyTrampolineBase, typename Constraint, typename PyTrampolineCfg>
using PyTrampolineBase_frc__EllipticalRegionConstraint =

    PyTrampoline_frc__TrajectoryConstraint<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename Constraint, typename PyTrampolineCfg>
struct PyTrampoline_frc__EllipticalRegionConstraint : PyTrampolineBase_frc__EllipticalRegionConstraint<PyTrampolineBase, Constraint, PyTrampolineCfg> {
    using PyTrampolineBase_frc__EllipticalRegionConstraint<PyTrampolineBase, Constraint, PyTrampolineCfg>::PyTrampolineBase_frc__EllipticalRegionConstraint;





    using MinMax = frc::TrajectoryConstraint::MinMax;







    
    
#ifndef RPYGEN_DISABLE_KMaxVelocity_KRTPose2d_Tcurvature_t_Tmeters_per_second_t
    units::meters_per_second_t MaxVelocity(const Pose2d& pose, units::curvature_t curvature, units::meters_per_second_t velocity) const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KMaxVelocity_KRTPose2d_Tcurvature_t_Tmeters_per_second_t;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(units::meters_per_second_t), LookupBase,
            "maxVelocity", pose, curvature, velocity);
        return CxxCallBase::MaxVelocity(std::forward<decltype(pose)>(pose), std::move(curvature), std::move(velocity));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KMinMaxAcceleration_KRTPose2d_Tcurvature_t_Tmeters_per_second_t
    MinMax MinMaxAcceleration(const Pose2d& pose, units::curvature_t curvature, units::meters_per_second_t speed) const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KMinMaxAcceleration_KRTPose2d_Tcurvature_t_Tmeters_per_second_t;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(MinMax), LookupBase,
            "minMaxAcceleration", pose, curvature, speed);
        return CxxCallBase::MinMaxAcceleration(std::forward<decltype(pose)>(pose), std::move(curvature), std::move(speed));
    
    
    
    }
#endif

    

    
    

    

    
};

}; // namespace rpygen







#include <units_compound_type_caster.h>

#include <units_length_type_caster.h>

#include <units_velocity_type_caster.h>


namespace rpygen {


using namespace frc;




template <typename Constraint>
struct bind_frc__EllipticalRegionConstraint {

    
    using MinMax = frc::TrajectoryConstraint::MinMax;
  

    
  
  

    

    
  using EllipticalRegionConstraint_Trampoline = rpygen::PyTrampoline_frc__EllipticalRegionConstraint<typename frc::EllipticalRegionConstraint<Constraint>, Constraint, typename rpygen::PyTrampolineCfg_frc__EllipticalRegionConstraint<Constraint>>;
    static_assert(std::is_abstract<EllipticalRegionConstraint_Trampoline>::value == false, "frc::EllipticalRegionConstraint<Constraint> " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::EllipticalRegionConstraint<Constraint>, EllipticalRegionConstraint_Trampoline, frc::TrajectoryConstraint> cls_EllipticalRegionConstraint;

    

    
    

    py::module &m;
    std::string clsName;

bind_frc__EllipticalRegionConstraint(py::module &m, const char * clsName) :
    
    cls_EllipticalRegionConstraint(m, clsName),

  

  
  
    m(m),
    clsName(clsName)
{
    
  

}

void finish(const char * set_doc = NULL, const char * add_doc = NULL) {

    

  cls_EllipticalRegionConstraint.doc() =
    "Enforces a particular constraint only within an elliptical region.";

  cls_EllipticalRegionConstraint
  
    
  .def(py::init<const Translation2d&, units::meter_t, units::meter_t, const Rotation2d&, const Constraint&>(),
      py::arg("center"), py::arg("xWidth"), py::arg("yWidth"), py::arg("rotation"), py::arg("constraint"), release_gil()
    , py::keep_alive<1, 2>()
    , py::keep_alive<1, 5>()
    , py::keep_alive<1, 6>(), py::doc(
    "Constructs a new EllipticalRegionConstraint.\n"
"\n"
":param center:     The center of the ellipse in which to enforce the constraint.\n"
":param xWidth:     The width of the ellipse in which to enforce the constraint.\n"
":param yWidth:     The height of the ellipse in which to enforce the constraint.\n"
":param rotation:   The rotation to apply to all radii around the origin.\n"
":param constraint: The constraint to enforce when the robot is within the\n"
"                   region.")
  )
  
  
  
    
  .
def
("maxVelocity", &frc::EllipticalRegionConstraint<Constraint>::MaxVelocity,
      py::arg("pose"), py::arg("curvature"), py::arg("velocity"), release_gil()
  )
  
  
  
    
  .
def
("minMaxAcceleration", &frc::EllipticalRegionConstraint<Constraint>::MinMaxAcceleration,
      py::arg("pose"), py::arg("curvature"), py::arg("speed"), release_gil()
  )
  
  
  
    
  .
def
("isPoseInRegion", &frc::EllipticalRegionConstraint<Constraint>::IsPoseInRegion,
      py::arg("pose"), release_gil(), py::doc(
    "Returns whether the specified robot pose is within the region that the\n"
"constraint is enforced in.\n"
"\n"
":param pose: The robot pose.\n"
"\n"
":returns: Whether the robot pose is within the constraint region.")
  )
  
  
  ;

  



    if (set_doc) {
        cls_EllipticalRegionConstraint.doc() = set_doc;
    }
    if (add_doc) {
        cls_EllipticalRegionConstraint.doc() = py::cast<std::string>(cls_EllipticalRegionConstraint.doc()) + add_doc;
    }

    cls_EllipticalRegionConstraint
  .def_static("fromFeet", [](const Translation2d& center, units::foot_t xWidth,
                             units::foot_t yWidth, const Rotation2d& rotation,
                             const Constraint& constraint) {
    return std::make_shared<EllipticalRegionConstraint<Constraint>>(center, xWidth, yWidth, rotation, constraint);
  }, py::arg("center"), py::arg("xWidth"), py::arg("yWidth"), py::arg("rotation"), py::arg("constraint"))
;

}

}; // struct bind_frc__EllipticalRegionConstraint

}; // namespace rpygen
