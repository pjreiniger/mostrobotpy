
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/trajectory/constraint/MecanumDriveKinematicsConstraint.h>


#include <units_compound_type_caster.h>

#include <units_velocity_type_caster.h>







#define RPYGEN_ENABLE_frc__MecanumDriveKinematicsConstraint_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__MecanumDriveKinematicsConstraint.hpp>









#include <type_traits>


  using namespace frc;





struct rpybuild_MecanumDriveKinematicsConstraint_initializer {


  
    using MinMax = frc::TrajectoryConstraint::MinMax;
  

  




  py::module pkg_constraint;









  
  using MecanumDriveKinematicsConstraint_Trampoline = rpygen::PyTrampoline_frc__MecanumDriveKinematicsConstraint<typename frc::MecanumDriveKinematicsConstraint, typename rpygen::PyTrampolineCfg_frc__MecanumDriveKinematicsConstraint<>>;
    static_assert(std::is_abstract<MecanumDriveKinematicsConstraint_Trampoline>::value == false, "frc::MecanumDriveKinematicsConstraint " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::MecanumDriveKinematicsConstraint, MecanumDriveKinematicsConstraint_Trampoline, frc::TrajectoryConstraint> cls_MecanumDriveKinematicsConstraint;

    

    
    

  py::module &m;

  
  rpybuild_MecanumDriveKinematicsConstraint_initializer(py::module &m) :

  
    pkg_constraint(m.def_submodule("constraint")),
  

  

  

  
    cls_MecanumDriveKinematicsConstraint(pkg_constraint, "MecanumDriveKinematicsConstraint"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_MecanumDriveKinematicsConstraint.doc() =
    "A class that enforces constraints on the mecanum drive kinematics.\n"
"This can be used to ensure that the trajectory is constructed so that the\n"
"commanded velocities for wheels of the drivetrain stay below a certain\n"
"limit.";

  cls_MecanumDriveKinematicsConstraint
  
    
  .def(py::init<const MecanumDriveKinematics&, units::meters_per_second_t>(),
      py::arg("kinematics"), py::arg("maxSpeed"), release_gil()
    , py::keep_alive<1, 2>()
  )
  
  
  
    
  .
def
("maxVelocity", &frc::MecanumDriveKinematicsConstraint::MaxVelocity,
      py::arg("pose"), py::arg("curvature"), py::arg("velocity"), release_gil()
  )
  
  
  
    
  .
def
("minMaxAcceleration", &frc::MecanumDriveKinematicsConstraint::MinMaxAcceleration,
      py::arg("pose"), py::arg("curvature"), py::arg("speed"), release_gil()
  )
  
  
  ;

  


  }







  cls_MecanumDriveKinematicsConstraint
  .def_static("fromFps", [](const frc::MecanumDriveKinematics& kinematics,
                            units::feet_per_second_t maxSpeed) {
    return std::make_shared<frc::MecanumDriveKinematicsConstraint>(kinematics, maxSpeed);
  }, py::arg("kinematics"), py::arg("maxSpeed"))
;

}

}; // struct rpybuild_MecanumDriveKinematicsConstraint_initializer

static std::unique_ptr<rpybuild_MecanumDriveKinematicsConstraint_initializer> cls;

void begin_init_MecanumDriveKinematicsConstraint(py::module &m) {
  cls = std::make_unique<rpybuild_MecanumDriveKinematicsConstraint_initializer>(m);
}

void finish_init_MecanumDriveKinematicsConstraint() {
  cls->finish();
  cls.reset();
}