
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/trajectory/constraint/TrajectoryConstraint.h>


#include <units_acceleration_type_caster.h>

#include <units_compound_type_caster.h>

#include <units_velocity_type_caster.h>







#define RPYGEN_ENABLE_frc__TrajectoryConstraint_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__TrajectoryConstraint.hpp>









#include <type_traits>


  using namespace frc;





struct rpybuild_TrajectoryConstraint_initializer {


  

  




  py::module pkg_constraint;









  
  using TrajectoryConstraint_Trampoline = rpygen::PyTrampoline_frc__TrajectoryConstraint<typename frc::TrajectoryConstraint, typename rpygen::PyTrampolineCfg_frc__TrajectoryConstraint<>>;
    static_assert(std::is_abstract<TrajectoryConstraint_Trampoline>::value == false, "frc::TrajectoryConstraint " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::TrajectoryConstraint, TrajectoryConstraint_Trampoline> cls_TrajectoryConstraint;

    

    
    
    py::class_<typename frc::TrajectoryConstraint::MinMax> cls_MinMax;

    

    
    
    

  py::module &m;

  
  rpybuild_TrajectoryConstraint_initializer(py::module &m) :

  
    pkg_constraint(m.def_submodule("constraint")),
  

  

  

  
    cls_TrajectoryConstraint(pkg_constraint, "TrajectoryConstraint"),

  

  
  
    cls_MinMax(cls_TrajectoryConstraint, "MinMax"),

  

  
  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  

    
    
  }

void finish() {





  {
  
  using MinMax [[maybe_unused]] = typename frc::TrajectoryConstraint::MinMax;
  
  
  


  

  cls_TrajectoryConstraint.doc() =
    "An interface for defining user-defined velocity and acceleration constraints\n"
"while generating trajectories.";

  cls_TrajectoryConstraint
  
    
  .def(py::init<>(), release_gil()
  )
  
  
  
    
  .
def
("maxVelocity", &frc::TrajectoryConstraint::MaxVelocity,
      py::arg("pose"), py::arg("curvature"), py::arg("velocity"), release_gil(), py::doc(
    "Returns the max velocity given the current pose and curvature.\n"
"\n"
":param pose:      The pose at the current point in the trajectory.\n"
":param curvature: The curvature at the current point in the trajectory.\n"
":param velocity:  The velocity at the current point in the trajectory before\n"
"                  constraints are applied.\n"
"\n"
":returns: The absolute maximum velocity.")
  )
  
  
  
    
  .
def
("minMaxAcceleration", &frc::TrajectoryConstraint::MinMaxAcceleration,
      py::arg("pose"), py::arg("curvature"), py::arg("speed"), release_gil(), py::doc(
    "Returns the minimum and maximum allowable acceleration for the trajectory\n"
"given pose, curvature, and speed.\n"
"\n"
":param pose:      The pose at the current point in the trajectory.\n"
":param curvature: The curvature at the current point in the trajectory.\n"
":param speed:     The speed at the current point in the trajectory.\n"
"\n"
":returns: The min and max acceleration bounds.")
  )
  
  
  ;

  


  

  cls_MinMax.doc() =
    "Represents a minimum and maximum acceleration.";

  cls_MinMax
  
    .def(py::init<>(), release_gil())
  
    .def_readwrite("minAcceleration", &frc::TrajectoryConstraint::MinMax::minAcceleration, py::doc(
    "The minimum acceleration."))
  
    .def_readwrite("maxAcceleration", &frc::TrajectoryConstraint::MinMax::maxAcceleration, py::doc(
    "The maximum acceleration."))
  ;

  


  
  }






}

}; // struct rpybuild_TrajectoryConstraint_initializer

static std::unique_ptr<rpybuild_TrajectoryConstraint_initializer> cls;

void begin_init_TrajectoryConstraint(py::module &m) {
  cls = std::make_unique<rpybuild_TrajectoryConstraint_initializer>(m);
}

void finish_init_TrajectoryConstraint() {
  cls->finish();
  cls.reset();
}