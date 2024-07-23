

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/controller/LinearQuadraticRegulator.h>










#include <pybind11/eigen.h>

#include <units_time_type_caster.h>

#include <wpi_array_type_caster.h>


namespace rpygen {


using namespace frc;




template <int States, int Inputs>
struct bind_frc__LinearQuadraticRegulator {

    

    
  
  
    using StateVector [[maybe_unused]] = typename frc::LinearQuadraticRegulator<States, Inputs>::StateVector;
  
    using InputVector [[maybe_unused]] = typename frc::LinearQuadraticRegulator<States, Inputs>::InputVector;
  
    using StateArray [[maybe_unused]] = typename frc::LinearQuadraticRegulator<States, Inputs>::StateArray;
  
    using InputArray [[maybe_unused]] = typename frc::LinearQuadraticRegulator<States, Inputs>::InputArray;
  

    

    py::class_<typename frc::LinearQuadraticRegulator<States, Inputs>> cls_LinearQuadraticRegulator;

    

    
    

    py::module &m;
    std::string clsName;

bind_frc__LinearQuadraticRegulator(py::module &m, const char * clsName) :
    
    cls_LinearQuadraticRegulator(m, clsName),

  

  
  
    m(m),
    clsName(clsName)
{
    
  

}

void finish(const char * set_doc = NULL, const char * add_doc = NULL) {

    

  cls_LinearQuadraticRegulator.doc() =
    "Contains the controller coefficients and logic for a linear-quadratic\n"
"regulator (LQR).\n"
"LQRs use the control law u = K(r - x).\n"
"\n"
"For more on the underlying math, read\n"
"https://file.tavsys.net/control/controls-engineering-in-frc.pdf.\n"
"\n"
"@tparam States Number of states.\n"
"@tparam Inputs Number of inputs.";

  cls_LinearQuadraticRegulator
  
    
  .def(py::init<const Matrixd<States, States>&, const Matrixd<States, Inputs>&, const StateArray&, const InputArray&, units::second_t>(),
      py::arg("A"), py::arg("B"), py::arg("Qelems"), py::arg("Relems"), py::arg("dt"), release_gil()
    , py::keep_alive<1, 2>()
    , py::keep_alive<1, 3>()
    , py::keep_alive<1, 4>()
    , py::keep_alive<1, 5>(), py::doc(
    "Constructs a controller with the given coefficients and plant.\n"
"\n"
"See\n"
"https://docs.wpilib.org/en/stable/docs/software/advanced-controls/state-space/state-space-intro.html#lqr-tuning\n"
"for how to select the tolerances.\n"
"\n"
":param A:      Continuous system matrix of the plant being controlled.\n"
":param B:      Continuous input matrix of the plant being controlled.\n"
":param Qelems: The maximum desired error tolerance for each state.\n"
":param Relems: The maximum desired control effort for each input.\n"
":param dt:     Discretization timestep.\n"
"               @throws std::invalid_argument If the system is uncontrollable.")
  )
  
  
  
    
  .def(py::init<const Matrixd<States, States>&, const Matrixd<States, Inputs>&, const Matrixd<States, States>&, const Matrixd<Inputs, Inputs>&, units::second_t>(),
      py::arg("A"), py::arg("B"), py::arg("Q"), py::arg("R"), py::arg("dt"), release_gil()
    , py::keep_alive<1, 2>()
    , py::keep_alive<1, 3>()
    , py::keep_alive<1, 4>()
    , py::keep_alive<1, 5>(), py::doc(
    "Constructs a controller with the given coefficients and plant.\n"
"\n"
":param A:  Continuous system matrix of the plant being controlled.\n"
":param B:  Continuous input matrix of the plant being controlled.\n"
":param Q:  The state cost matrix.\n"
":param R:  The input cost matrix.\n"
":param dt: Discretization timestep.\n"
"           @throws std::invalid_argument If the system is uncontrollable.")
  )
  
  
  
    
  .def(py::init<const Matrixd<States, States>&, const Matrixd<States, Inputs>&, const Matrixd<States, States>&, const Matrixd<Inputs, Inputs>&, const Matrixd<States, Inputs>&, units::second_t>(),
      py::arg("A"), py::arg("B"), py::arg("Q"), py::arg("R"), py::arg("N"), py::arg("dt"), release_gil()
    , py::keep_alive<1, 2>()
    , py::keep_alive<1, 3>()
    , py::keep_alive<1, 4>()
    , py::keep_alive<1, 5>()
    , py::keep_alive<1, 6>(), py::doc(
    "Constructs a controller with the given coefficients and plant.\n"
"\n"
":param A:  Continuous system matrix of the plant being controlled.\n"
":param B:  Continuous input matrix of the plant being controlled.\n"
":param Q:  The state cost matrix.\n"
":param R:  The input cost matrix.\n"
":param N:  The state-input cross-term cost matrix.\n"
":param dt: Discretization timestep.\n"
"           @throws std::invalid_argument If the system is uncontrollable.")
  )
  
  
  
    
  .
def
("K", static_cast<const Matrixd<Inputs, States>&(frc::LinearQuadraticRegulator<States, Inputs>::*)() const>(
        &frc::LinearQuadraticRegulator<States, Inputs>::K), release_gil(), py::doc(
    "Returns the controller matrix K.")
  )
  
  
  
    
  .
def
("K", static_cast<double(frc::LinearQuadraticRegulator<States, Inputs>::*)(int, int) const>(
        &frc::LinearQuadraticRegulator<States, Inputs>::K),
      py::arg("i"), py::arg("j"), release_gil(), py::doc(
    "Returns an element of the controller matrix K.\n"
"\n"
":param i: Row of K.\n"
":param j: Column of K.")
  )
  
  
  
    
  .
def
("R", static_cast<const StateVector&(frc::LinearQuadraticRegulator<States, Inputs>::*)() const>(
        &frc::LinearQuadraticRegulator<States, Inputs>::R), release_gil(), py::doc(
    "Returns the reference vector r.\n"
"\n"
":returns: The reference vector.")
  )
  
  
  
    
  .
def
("R", static_cast<double(frc::LinearQuadraticRegulator<States, Inputs>::*)(int) const>(
        &frc::LinearQuadraticRegulator<States, Inputs>::R),
      py::arg("i"), release_gil(), py::doc(
    "Returns an element of the reference vector r.\n"
"\n"
":param i: Row of r.\n"
"\n"
":returns: The row of the reference vector.")
  )
  
  
  
    
  .
def
("U", static_cast<const InputVector&(frc::LinearQuadraticRegulator<States, Inputs>::*)() const>(
        &frc::LinearQuadraticRegulator<States, Inputs>::U), release_gil(), py::doc(
    "Returns the control input vector u.\n"
"\n"
":returns: The control input.")
  )
  
  
  
    
  .
def
("U", static_cast<double(frc::LinearQuadraticRegulator<States, Inputs>::*)(int) const>(
        &frc::LinearQuadraticRegulator<States, Inputs>::U),
      py::arg("i"), release_gil(), py::doc(
    "Returns an element of the control input vector u.\n"
"\n"
":param i: Row of u.\n"
"\n"
":returns: The row of the control input vector.")
  )
  
  
  
    
  .
def
("reset", &frc::LinearQuadraticRegulator<States, Inputs>::Reset, release_gil(), py::doc(
    "Resets the controller.")
  )
  
  
  
    
  .
def
("calculate", static_cast<InputVector(frc::LinearQuadraticRegulator<States, Inputs>::*)(const StateVector&)>(
        &frc::LinearQuadraticRegulator<States, Inputs>::Calculate),
      py::arg("x"), release_gil(), py::doc(
    "Returns the next output of the controller.\n"
"\n"
":param x: The current state x.")
  )
  
  
  
    
  .
def
("calculate", static_cast<InputVector(frc::LinearQuadraticRegulator<States, Inputs>::*)(const StateVector&, const StateVector&)>(
        &frc::LinearQuadraticRegulator<States, Inputs>::Calculate),
      py::arg("x"), py::arg("nextR"), release_gil(), py::doc(
    "Returns the next output of the controller.\n"
"\n"
":param x:     The current state x.\n"
":param nextR: The next reference vector r.")
  )
  
  
  
    
  .
def
("latencyCompensate", &frc::LinearQuadraticRegulator<States, Inputs>::template LatencyCompensate<1>,
      py::arg("plant"), py::arg("dt"), py::arg("inputDelay"), release_gil(), py::doc(
    "Adjusts LQR controller gain to compensate for a pure time delay in the\n"
"input.\n"
"\n"
"Linear-Quadratic regulator controller gains tend to be aggressive. If\n"
"sensor measurements are time-delayed too long, the LQR may be unstable.\n"
"However, if we know the amount of delay, we can compute the control based\n"
"on where the system will be after the time delay.\n"
"\n"
"See https://file.tavsys.net/control/controls-engineering-in-frc.pdf\n"
"appendix C.4 for a derivation.\n"
"\n"
":param plant:      The plant being controlled.\n"
":param dt:         Discretization timestep.\n"
":param inputDelay: Input time delay.")
  )
  
  
    
  .
def
("latencyCompensate", &frc::LinearQuadraticRegulator<States, Inputs>::template LatencyCompensate<2>,
      py::arg("plant"), py::arg("dt"), py::arg("inputDelay"), release_gil(), py::doc(
    "Adjusts LQR controller gain to compensate for a pure time delay in the\n"
"input.\n"
"\n"
"Linear-Quadratic regulator controller gains tend to be aggressive. If\n"
"sensor measurements are time-delayed too long, the LQR may be unstable.\n"
"However, if we know the amount of delay, we can compute the control based\n"
"on where the system will be after the time delay.\n"
"\n"
"See https://file.tavsys.net/control/controls-engineering-in-frc.pdf\n"
"appendix C.4 for a derivation.\n"
"\n"
":param plant:      The plant being controlled.\n"
":param dt:         Discretization timestep.\n"
":param inputDelay: Input time delay.")
  )
  
  
    
  ;

  



    if (set_doc) {
        cls_LinearQuadraticRegulator.doc() = set_doc;
    }
    if (add_doc) {
        cls_LinearQuadraticRegulator.doc() = py::cast<std::string>(cls_LinearQuadraticRegulator.doc()) + add_doc;
    }

    cls_LinearQuadraticRegulator
  .def(py::init<const frc::LinearSystem<States, Inputs, 1>&, const wpi::array<double, States>&, const wpi::array<double, Inputs>&, units::second_t>())
  .def(py::init<const frc::LinearSystem<States, Inputs, 2>&, const wpi::array<double, States>&, const wpi::array<double, Inputs>&, units::second_t>())
  .def(py::init<const frc::LinearSystem<States, Inputs, 3>&, const wpi::array<double, States>&, const wpi::array<double, Inputs>&, units::second_t>());

}

}; // struct bind_frc__LinearQuadraticRegulator

}; // namespace rpygen
