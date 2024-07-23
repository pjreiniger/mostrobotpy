
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/controller/LTVUnicycleController.h>


#include <units_angular_velocity_type_caster.h>

#include <units_time_type_caster.h>

#include <units_velocity_type_caster.h>

#include <wpi_array_type_caster.h>















#include <type_traits>


  using namespace frc;





struct rpybuild_LTVUnicycleController_initializer {


  

  




  py::module pkg_controller;









  py::class_<typename frc::LTVUnicycleController> cls_LTVUnicycleController;

    

    
    

  py::module &m;

  
  rpybuild_LTVUnicycleController_initializer(py::module &m) :

  
    pkg_controller(m.def_submodule("controller")),
  

  

  

  
    cls_LTVUnicycleController(pkg_controller, "LTVUnicycleController"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_LTVUnicycleController.doc() =
    "The linear time-varying unicycle controller has a similar form to the LQR,\n"
"but the model used to compute the controller gain is the nonlinear unicycle\n"
"model linearized around the drivetrain's current state.\n"
"\n"
"This controller is a roughly drop-in replacement for RamseteController with\n"
"more optimal feedback gains in the \"least-squares error\" sense.\n"
"\n"
"See section 8.9 in Controls Engineering in FRC for a derivation of the\n"
"control law we used shown in theorem 8.9.1.";

  cls_LTVUnicycleController
  
    
  .def(py::init<units::second_t, units::meters_per_second_t>(),
      py::arg("dt"), py::arg("maxVelocity") = (units::meters_per_second_t)9_mps, release_gil(), py::doc(
    "Constructs a linear time-varying unicycle controller with default maximum\n"
"desired error tolerances of (0.0625 m, 0.125 m, 2 rad) and default maximum\n"
"desired control effort of (1 m/s, 2 rad/s).\n"
"\n"
":param dt:          Discretization timestep.\n"
":param maxVelocity: The maximum velocity for the controller gain lookup\n"
"                    table.\n"
"                    @throws std::domain_error if maxVelocity &lt;= 0.")
  )
  
  
  
    
  .def(py::init<const wpi::array<double, 3>&, const wpi::array<double, 2>&, units::second_t, units::meters_per_second_t>(),
      py::arg("Qelems"), py::arg("Relems"), py::arg("dt"), py::arg("maxVelocity") = (units::meters_per_second_t)9_mps, release_gil()
    , py::keep_alive<1, 2>()
    , py::keep_alive<1, 3>(), py::doc(
    "Constructs a linear time-varying unicycle controller.\n"
"\n"
"See\n"
"https://docs.wpilib.org/en/stable/docs/software/advanced-controls/state-space/state-space-intro.html#lqr-tuning\n"
"for how to select the tolerances.\n"
"\n"
":param Qelems:      The maximum desired error tolerance for each state.\n"
":param Relems:      The maximum desired control effort for each input.\n"
":param dt:          Discretization timestep.\n"
":param maxVelocity: The maximum velocity for the controller gain lookup\n"
"                    table.\n"
"                    @throws std::domain_error if maxVelocity <= 0 m/s or >= 15 m/s.")
  )
  
  
  
    
  .
def
("atReference", &frc::LTVUnicycleController::AtReference, release_gil(), py::doc(
    "Returns true if the pose error is within tolerance of the reference.")
  )
  
  
  
    
  .
def
("setTolerance", &frc::LTVUnicycleController::SetTolerance,
      py::arg("poseTolerance"), release_gil(), py::doc(
    "Sets the pose error which is considered tolerable for use with\n"
"AtReference().\n"
"\n"
":param poseTolerance: Pose error which is tolerable.")
  )
  
  
  
    
  .
def
("calculate", static_cast<ChassisSpeeds(frc::LTVUnicycleController::*)(const Pose2d&, const Pose2d&, units::meters_per_second_t, units::radians_per_second_t)>(
        &frc::LTVUnicycleController::Calculate),
      py::arg("currentPose"), py::arg("poseRef"), py::arg("linearVelocityRef"), py::arg("angularVelocityRef"), release_gil(), py::doc(
    "Returns the linear and angular velocity outputs of the LTV controller.\n"
"\n"
"The reference pose, linear velocity, and angular velocity should come from\n"
"a drivetrain trajectory.\n"
"\n"
":param currentPose:        The current pose.\n"
":param poseRef:            The desired pose.\n"
":param linearVelocityRef:  The desired linear velocity.\n"
":param angularVelocityRef: The desired angular velocity.")
  )
  
  
  
    
  .
def
("calculate", static_cast<ChassisSpeeds(frc::LTVUnicycleController::*)(const Pose2d&, const Trajectory::State&)>(
        &frc::LTVUnicycleController::Calculate),
      py::arg("currentPose"), py::arg("desiredState"), release_gil(), py::doc(
    "Returns the linear and angular velocity outputs of the LTV controller.\n"
"\n"
"The reference pose, linear velocity, and angular velocity should come from\n"
"a drivetrain trajectory.\n"
"\n"
":param currentPose:  The current pose.\n"
":param desiredState: The desired pose, linear velocity, and angular velocity\n"
"                     from a trajectory.")
  )
  
  
  
    
  .
def
("setEnabled", &frc::LTVUnicycleController::SetEnabled,
      py::arg("enabled"), release_gil(), py::doc(
    "Enables and disables the controller for troubleshooting purposes.\n"
"\n"
":param enabled: If the controller is enabled or not.")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_LTVUnicycleController_initializer

static std::unique_ptr<rpybuild_LTVUnicycleController_initializer> cls;

void begin_init_LTVUnicycleController(py::module &m) {
  cls = std::make_unique<rpybuild_LTVUnicycleController_initializer>(m);
}

void finish_init_LTVUnicycleController() {
  cls->finish();
  cls.reset();
}