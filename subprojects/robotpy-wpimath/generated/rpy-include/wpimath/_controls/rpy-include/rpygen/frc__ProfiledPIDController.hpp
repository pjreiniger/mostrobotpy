

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/controller/ProfiledPIDController.h>










#include <rpygen/wpi__Sendable.hpp>



namespace rpygen {


using namespace frc;





template <typename Distance, typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__ProfiledPIDController :


    PyTrampolineCfg_wpi__Sendable<

CfgBase
>

{
    using Base = frc::ProfiledPIDController<Distance>;

    
    
    using override_base_InitSendable_RTSendableBuilder = frc::ProfiledPIDController<Distance>;
    
};




template <typename PyTrampolineBase, typename Distance, typename PyTrampolineCfg>
using PyTrampolineBase_frc__ProfiledPIDController =

    PyTrampoline_wpi__Sendable<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename Distance, typename PyTrampolineCfg>
struct PyTrampoline_frc__ProfiledPIDController : PyTrampolineBase_frc__ProfiledPIDController<PyTrampolineBase, Distance, PyTrampolineCfg> {
    using PyTrampolineBase_frc__ProfiledPIDController<PyTrampolineBase, Distance, PyTrampolineCfg>::PyTrampolineBase_frc__ProfiledPIDController;





    using Velocity = typename frc::ProfiledPIDController<Distance>::Velocity;

    using Velocity_t = typename frc::ProfiledPIDController<Distance>::Velocity_t;


    using Distance_t [[maybe_unused]] = typename frc::ProfiledPIDController<Distance>::Distance_t;

    using Acceleration [[maybe_unused]] = typename frc::ProfiledPIDController<Distance>::Acceleration;

    using Acceleration_t [[maybe_unused]] = typename frc::ProfiledPIDController<Distance>::Acceleration_t;

    using State [[maybe_unused]] = typename frc::ProfiledPIDController<Distance>::State;

    using Constraints [[maybe_unused]] = typename frc::ProfiledPIDController<Distance>::Constraints;






    
    
#ifndef RPYGEN_DISABLE_InitSendable_RTSendableBuilder
    void InitSendable(wpi::SendableBuilder& builder) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_InitSendable_RTSendableBuilder;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "initSendable", builder);
        return CxxCallBase::InitSendable(std::forward<decltype(builder)>(builder));
    
    
    
    }
#endif

    

    
    

    

    
};

}; // namespace rpygen







#include <units_angle_type_caster.h>

#include <units_angular_velocity_type_caster.h>

#include <units_compound_type_caster.h>

#include <units_misc_type_caster.h>

#include <units_time_type_caster.h>


namespace rpygen {


using namespace frc;




template <typename Distance>
struct bind_frc__ProfiledPIDController {

    
    using Velocity = typename frc::ProfiledPIDController<Distance>::Velocity;
  
    using Velocity_t = typename frc::ProfiledPIDController<Distance>::Velocity_t;
  

    
  
  
    using Distance_t [[maybe_unused]] = typename frc::ProfiledPIDController<Distance>::Distance_t;
  
    using Acceleration [[maybe_unused]] = typename frc::ProfiledPIDController<Distance>::Acceleration;
  
    using Acceleration_t [[maybe_unused]] = typename frc::ProfiledPIDController<Distance>::Acceleration_t;
  
    using State [[maybe_unused]] = typename frc::ProfiledPIDController<Distance>::State;
  
    using Constraints [[maybe_unused]] = typename frc::ProfiledPIDController<Distance>::Constraints;
  

    

    
  using ProfiledPIDController_Trampoline = rpygen::PyTrampoline_frc__ProfiledPIDController<typename frc::ProfiledPIDController<Distance>, Distance, typename rpygen::PyTrampolineCfg_frc__ProfiledPIDController<Distance>>;
    static_assert(std::is_abstract<ProfiledPIDController_Trampoline>::value == false, "frc::ProfiledPIDController<Distance> " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::ProfiledPIDController<Distance>, ProfiledPIDController_Trampoline, wpi::Sendable> cls_ProfiledPIDController;

    

    
    

    py::module &m;
    std::string clsName;

bind_frc__ProfiledPIDController(py::module &m, const char * clsName) :
    
    cls_ProfiledPIDController(m, clsName),

  

  
  
    m(m),
    clsName(clsName)
{
    
  

}

void finish(const char * set_doc = NULL, const char * add_doc = NULL) {

    

  cls_ProfiledPIDController.doc() =
    "Implements a PID control loop whose setpoint is constrained by a trapezoid\n"
"profile.";

  cls_ProfiledPIDController
  
    
  .def(py::init<double, double, double, typename TrapezoidProfile<Distance>::Constraints, units::second_t>(),
      py::arg("Kp"), py::arg("Ki"), py::arg("Kd"), py::arg("constraints"), py::arg("period") = (units::second_t)0.020_s, release_gil(), py::doc(
    "Allocates a ProfiledPIDController with the given constants for Kp, Ki, and\n"
"Kd. Users should call reset() when they first start running the controller\n"
"to avoid unwanted behavior.\n"
"\n"
":param Kp:          The proportional coefficient. Must be >= 0.\n"
":param Ki:          The integral coefficient. Must be >= 0.\n"
":param Kd:          The derivative coefficient. Must be >= 0.\n"
":param constraints: Velocity and acceleration constraints for goal.\n"
":param period:      The period between controller updates in seconds. The\n"
"                    default is 20 milliseconds. Must be positive.")
  )
  
  
  
    
  .
def
("setPID", &frc::ProfiledPIDController<Distance>::SetPID,
      py::arg("Kp"), py::arg("Ki"), py::arg("Kd"), release_gil(), py::doc(
    "Sets the PID Controller gain parameters.\n"
"\n"
"Sets the proportional, integral, and differential coefficients.\n"
"\n"
":param Kp: The proportional coefficient. Must be >= 0.\n"
":param Ki: The integral coefficient. Must be >= 0.\n"
":param Kd: The differential coefficient. Must be >= 0.")
  )
  
  
  
    
  .
def
("setP", &frc::ProfiledPIDController<Distance>::SetP,
      py::arg("Kp"), release_gil(), py::doc(
    "Sets the proportional coefficient of the PID controller gain.\n"
"\n"
":param Kp: The proportional coefficient. Must be >= 0.")
  )
  
  
  
    
  .
def
("setI", &frc::ProfiledPIDController<Distance>::SetI,
      py::arg("Ki"), release_gil(), py::doc(
    "Sets the integral coefficient of the PID controller gain.\n"
"\n"
":param Ki: The integral coefficient. Must be >= 0.")
  )
  
  
  
    
  .
def
("setD", &frc::ProfiledPIDController<Distance>::SetD,
      py::arg("Kd"), release_gil(), py::doc(
    "Sets the differential coefficient of the PID controller gain.\n"
"\n"
":param Kd: The differential coefficient. Must be >= 0.")
  )
  
  
  
    
  .
def
("setIZone", &frc::ProfiledPIDController<Distance>::SetIZone,
      py::arg("iZone"), release_gil(), py::doc(
    "Sets the IZone range. When the absolute value of the position error is\n"
"greater than IZone, the total accumulated error will reset to zero,\n"
"disabling integral gain until the absolute value of the position error is\n"
"less than IZone. This is used to prevent integral windup. Must be\n"
"non-negative. Passing a value of zero will effectively disable integral\n"
"gain. Passing a value of infinity disables IZone functionality.\n"
"\n"
":param iZone: Maximum magnitude of error to allow integral control. Must be\n"
"              >= 0.")
  )
  
  
  
    
  .
def
("getP", &frc::ProfiledPIDController<Distance>::GetP, release_gil(), py::doc(
    "Gets the proportional coefficient.\n"
"\n"
":returns: proportional coefficient")
  )
  
  
  
    
  .
def
("getI", &frc::ProfiledPIDController<Distance>::GetI, release_gil(), py::doc(
    "Gets the integral coefficient.\n"
"\n"
":returns: integral coefficient")
  )
  
  
  
    
  .
def
("getD", &frc::ProfiledPIDController<Distance>::GetD, release_gil(), py::doc(
    "Gets the differential coefficient.\n"
"\n"
":returns: differential coefficient")
  )
  
  
  
    
  .
def
("getIZone", &frc::ProfiledPIDController<Distance>::GetIZone, release_gil(), py::doc(
    "Get the IZone range.\n"
"\n"
":returns: Maximum magnitude of error to allow integral control.")
  )
  
  
  
    
  .
def
("getPeriod", &frc::ProfiledPIDController<Distance>::GetPeriod, release_gil(), py::doc(
    "Gets the period of this controller.\n"
"\n"
":returns: The period of the controller.")
  )
  
  
  
    
  .
def
("getPositionTolerance", &frc::ProfiledPIDController<Distance>::GetPositionTolerance, release_gil(), py::doc(
    "Gets the position tolerance of this controller.\n"
"\n"
":returns: The position tolerance of the controller.")
  )
  
  
  
    
  .
def
("getVelocityTolerance", &frc::ProfiledPIDController<Distance>::GetVelocityTolerance, release_gil(), py::doc(
    "Gets the velocity tolerance of this controller.\n"
"\n"
":returns: The velocity tolerance of the controller.")
  )
  
  
  
    
  .
def
("setGoal", static_cast<void(frc::ProfiledPIDController<Distance>::*)(State)>(
        &frc::ProfiledPIDController<Distance>::SetGoal),
      py::arg("goal"), release_gil(), py::doc(
    "Sets the goal for the ProfiledPIDController.\n"
"\n"
":param goal: The desired unprofiled setpoint.")
  )
  
  
  
    
  .
def
("setGoal", static_cast<void(frc::ProfiledPIDController<Distance>::*)(Distance_t)>(
        &frc::ProfiledPIDController<Distance>::SetGoal),
      py::arg("goal"), release_gil(), py::doc(
    "Sets the goal for the ProfiledPIDController.\n"
"\n"
":param goal: The desired unprofiled setpoint.")
  )
  
  
  
    
  .
def
("getGoal", &frc::ProfiledPIDController<Distance>::GetGoal, release_gil(), py::doc(
    "Gets the goal for the ProfiledPIDController.")
  )
  
  
  
    
  .
def
("atGoal", &frc::ProfiledPIDController<Distance>::AtGoal, release_gil(), py::doc(
    "Returns true if the error is within the tolerance of the error.\n"
"\n"
"This will return false until at least one input value has been computed.")
  )
  
  
  
    
  .
def
("setConstraints", &frc::ProfiledPIDController<Distance>::SetConstraints,
      py::arg("constraints"), release_gil(), py::doc(
    "Set velocity and acceleration constraints for goal.\n"
"\n"
":param constraints: Velocity and acceleration constraints for goal.")
  )
  
  
  
    
  .
def
("getConstraints", &frc::ProfiledPIDController<Distance>::GetConstraints, release_gil(), py::doc(
    "Get the velocity and acceleration constraints for this controller.\n"
"\n"
":returns: Velocity and acceleration constraints.")
  )
  
  
  
    
  .
def
("getSetpoint", &frc::ProfiledPIDController<Distance>::GetSetpoint, release_gil(), py::doc(
    "Returns the current setpoint of the ProfiledPIDController.\n"
"\n"
":returns: The current setpoint.")
  )
  
  
  
    
  .
def
("atSetpoint", &frc::ProfiledPIDController<Distance>::AtSetpoint, release_gil(), py::doc(
    "Returns true if the error is within the tolerance of the error.\n"
"\n"
"Currently this just reports on target as the actual value passes through\n"
"the setpoint. Ideally it should be based on being within the tolerance for\n"
"some period of time.\n"
"\n"
"This will return false until at least one input value has been computed.")
  )
  
  
  
    
  .
def
("enableContinuousInput", &frc::ProfiledPIDController<Distance>::EnableContinuousInput,
      py::arg("minimumInput"), py::arg("maximumInput"), release_gil(), py::doc(
    "Enables continuous input.\n"
"\n"
"Rather then using the max and min input range as constraints, it considers\n"
"them to be the same point and automatically calculates the shortest route\n"
"to the setpoint.\n"
"\n"
":param minimumInput: The minimum value expected from the input.\n"
":param maximumInput: The maximum value expected from the input.")
  )
  
  
  
    
  .
def
("disableContinuousInput", &frc::ProfiledPIDController<Distance>::DisableContinuousInput, release_gil(), py::doc(
    "Disables continuous input.")
  )
  
  
  
    
  .
def
("setIntegratorRange", &frc::ProfiledPIDController<Distance>::SetIntegratorRange,
      py::arg("minimumIntegral"), py::arg("maximumIntegral"), release_gil(), py::doc(
    "Sets the minimum and maximum values for the integrator.\n"
"\n"
"When the cap is reached, the integrator value is added to the controller\n"
"output rather than the integrator value times the integral gain.\n"
"\n"
":param minimumIntegral: The minimum value of the integrator.\n"
":param maximumIntegral: The maximum value of the integrator.")
  )
  
  
  
    
  .
def
("setTolerance", &frc::ProfiledPIDController<Distance>::SetTolerance,
      py::arg("positionTolerance"), py::arg("velocityTolerance") = Velocity_t{std::numeric_limits<double>::infinity ()}, release_gil(), py::doc(
    "Sets the error which is considered tolerable for use with\n"
"AtSetpoint().\n"
"\n"
":param positionTolerance: Position error which is tolerable.\n"
":param velocityTolerance: Velocity error which is tolerable.")
  )
  
  
  
    
  .
def
("getPositionError", &frc::ProfiledPIDController<Distance>::GetPositionError, release_gil(), py::doc(
    "Returns the difference between the setpoint and the measurement.\n"
"\n"
":returns: The error.")
  )
  
  
  
    
  .
def
("getVelocityError", &frc::ProfiledPIDController<Distance>::GetVelocityError, release_gil(), py::doc(
    "Returns the change in error per second.")
  )
  
  
  
    
  .
def
("calculate", static_cast<double(frc::ProfiledPIDController<Distance>::*)(Distance_t)>(
        &frc::ProfiledPIDController<Distance>::Calculate),
      py::arg("measurement"), release_gil(), py::doc(
    "Returns the next output of the PID controller.\n"
"\n"
":param measurement: The current measurement of the process variable.")
  )
  
  
  
    
  .
def
("calculate", static_cast<double(frc::ProfiledPIDController<Distance>::*)(Distance_t, State)>(
        &frc::ProfiledPIDController<Distance>::Calculate),
      py::arg("measurement"), py::arg("goal"), release_gil(), py::doc(
    "Returns the next output of the PID controller.\n"
"\n"
":param measurement: The current measurement of the process variable.\n"
":param goal:        The new goal of the controller.")
  )
  
  
  
    
  .
def
("calculate", static_cast<double(frc::ProfiledPIDController<Distance>::*)(Distance_t, Distance_t)>(
        &frc::ProfiledPIDController<Distance>::Calculate),
      py::arg("measurement"), py::arg("goal"), release_gil(), py::doc(
    "Returns the next output of the PID controller.\n"
"\n"
":param measurement: The current measurement of the process variable.\n"
":param goal:        The new goal of the controller.")
  )
  
  
  
    
  .
def
("calculate", static_cast<double(frc::ProfiledPIDController<Distance>::*)(Distance_t, Distance_t, typename TrapezoidProfile<Distance>::Constraints)>(
        &frc::ProfiledPIDController<Distance>::Calculate),
      py::arg("measurement"), py::arg("goal"), py::arg("constraints"), release_gil(), py::doc(
    "Returns the next output of the PID controller.\n"
"\n"
":param measurement: The current measurement of the process variable.\n"
":param goal:        The new goal of the controller.\n"
":param constraints: Velocity and acceleration constraints for goal.")
  )
  
  
  
    
  .
def
("reset", static_cast<void(frc::ProfiledPIDController<Distance>::*)(const State&)>(
        &frc::ProfiledPIDController<Distance>::Reset),
      py::arg("measurement"), release_gil(), py::doc(
    "Reset the previous error and the integral term.\n"
"\n"
":param measurement: The current measured State of the system.")
  )
  
  
  
    
  .
def
("reset", static_cast<void(frc::ProfiledPIDController<Distance>::*)(Distance_t, Velocity_t)>(
        &frc::ProfiledPIDController<Distance>::Reset),
      py::arg("measuredPosition"), py::arg("measuredVelocity"), release_gil(), py::doc(
    "Reset the previous error and the integral term.\n"
"\n"
":param measuredPosition: The current measured position of the system.\n"
":param measuredVelocity: The current measured velocity of the system.")
  )
  
  
  
    
  .
def
("reset", static_cast<void(frc::ProfiledPIDController<Distance>::*)(Distance_t)>(
        &frc::ProfiledPIDController<Distance>::Reset),
      py::arg("measuredPosition"), release_gil(), py::doc(
    "Reset the previous error and the integral term.\n"
"\n"
":param measuredPosition: The current measured position of the system. The\n"
"                         velocity is assumed to be zero.")
  )
  
  
  
    
  .
def
("initSendable", &frc::ProfiledPIDController<Distance>::InitSendable,
      py::arg("builder"), release_gil()
  )
  
  
  ;

  



    if (set_doc) {
        cls_ProfiledPIDController.doc() = set_doc;
    }
    if (add_doc) {
        cls_ProfiledPIDController.doc() = py::cast<std::string>(cls_ProfiledPIDController.doc()) + add_doc;
    }

    
}

}; // struct bind_frc__ProfiledPIDController

}; // namespace rpygen