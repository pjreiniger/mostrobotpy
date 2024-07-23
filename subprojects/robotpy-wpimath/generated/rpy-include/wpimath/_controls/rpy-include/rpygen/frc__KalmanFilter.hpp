

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/estimator/KalmanFilter.h>










#include <pybind11/eigen.h>

#include <units_time_type_caster.h>

#include <wpi_array_type_caster.h>


namespace rpygen {


using namespace frc;




template <int States, int Inputs, int Outputs>
struct bind_frc__KalmanFilter {

    

    
  
  
    using StateVector [[maybe_unused]] = typename frc::KalmanFilter<States, Inputs, Outputs>::StateVector;
  
    using InputVector [[maybe_unused]] = typename frc::KalmanFilter<States, Inputs, Outputs>::InputVector;
  
    using OutputVector [[maybe_unused]] = typename frc::KalmanFilter<States, Inputs, Outputs>::OutputVector;
  
    using StateArray [[maybe_unused]] = typename frc::KalmanFilter<States, Inputs, Outputs>::StateArray;
  
    using OutputArray [[maybe_unused]] = typename frc::KalmanFilter<States, Inputs, Outputs>::OutputArray;
  
    using StateMatrix [[maybe_unused]] = typename frc::KalmanFilter<States, Inputs, Outputs>::StateMatrix;
  

    

    py::class_<typename frc::KalmanFilter<States, Inputs, Outputs>> cls_KalmanFilter;

    

    
    

    py::module &m;
    std::string clsName;

bind_frc__KalmanFilter(py::module &m, const char * clsName) :
    
    cls_KalmanFilter(m, clsName),

  

  
  
    m(m),
    clsName(clsName)
{
    
  

}

void finish(const char * set_doc = NULL, const char * add_doc = NULL) {

    

  cls_KalmanFilter.doc() =
    "A Kalman filter combines predictions from a model and measurements to give an\n"
"estimate of the true system state. This is useful because many states cannot\n"
"be measured directly as a result of sensor noise, or because the state is\n"
"\"hidden\".\n"
"\n"
"Kalman filters use a K gain matrix to determine whether to trust the model or\n"
"measurements more. Kalman filter theory uses statistics to compute an optimal\n"
"K gain which minimizes the sum of squares error in the state estimate. This K\n"
"gain is used to correct the state estimate by some amount of the difference\n"
"between the actual measurements and the measurements predicted by the model.\n"
"\n"
"For more on the underlying math, read\n"
"https://file.tavsys.net/control/controls-engineering-in-frc.pdf chapter 9\n"
"\"Stochastic control theory\".\n"
"\n"
"@tparam States Number of states.\n"
"@tparam Inputs Number of inputs.\n"
"@tparam Outputs Number of outputs.";

  cls_KalmanFilter
  
    
  .def(py::init<LinearSystem<States, Inputs, Outputs>&, const StateArray&, const OutputArray&, units::second_t>(),
      py::arg("plant"), py::arg("stateStdDevs"), py::arg("measurementStdDevs"), py::arg("dt"), release_gil()
    , py::keep_alive<1, 2>()
    , py::keep_alive<1, 3>()
    , py::keep_alive<1, 4>(), py::doc(
    "Constructs a Kalman filter with the given plant.\n"
"\n"
"See\n"
"https://docs.wpilib.org/en/stable/docs/software/advanced-controls/state-space/state-space-observers.html#process-and-measurement-noise-covariance-matrices\n"
"for how to select the standard deviations.\n"
"\n"
":param plant:              The plant used for the prediction step.\n"
":param stateStdDevs:       Standard deviations of model states.\n"
":param measurementStdDevs: Standard deviations of measurements.\n"
":param dt:                 Nominal discretization timestep.\n"
"                           @throws std::invalid_argument If the system is unobservable.")
  )
  
  
  
    
  .
def
("P", static_cast<const StateMatrix&(frc::KalmanFilter<States, Inputs, Outputs>::*)() const>(
        &frc::KalmanFilter<States, Inputs, Outputs>::P), release_gil(), py::doc(
    "Returns the error covariance matrix P.")
  )
  
  
  
    
  .
def
("P", static_cast<double(frc::KalmanFilter<States, Inputs, Outputs>::*)(int, int) const>(
        &frc::KalmanFilter<States, Inputs, Outputs>::P),
      py::arg("i"), py::arg("j"), release_gil(), py::doc(
    "Returns an element of the error covariance matrix P.\n"
"\n"
":param i: Row of P.\n"
":param j: Column of P.")
  )
  
  
  
    
  .
def
("setP", &frc::KalmanFilter<States, Inputs, Outputs>::SetP,
      py::arg("P"), release_gil(), py::doc(
    "Set the current error covariance matrix P.\n"
"\n"
":param P: The error covariance matrix P.")
  )
  
  
  
    
  .
def
("xhat", static_cast<const StateVector&(frc::KalmanFilter<States, Inputs, Outputs>::*)() const>(
        &frc::KalmanFilter<States, Inputs, Outputs>::Xhat), release_gil(), py::doc(
    "Returns the state estimate x-hat.")
  )
  
  
  
    
  .
def
("xhat", static_cast<double(frc::KalmanFilter<States, Inputs, Outputs>::*)(int) const>(
        &frc::KalmanFilter<States, Inputs, Outputs>::Xhat),
      py::arg("i"), release_gil(), py::doc(
    "Returns an element of the state estimate x-hat.\n"
"\n"
":param i: Row of x-hat.")
  )
  
  
  
    
  .
def
("setXhat", static_cast<void(frc::KalmanFilter<States, Inputs, Outputs>::*)(const StateVector&)>(
        &frc::KalmanFilter<States, Inputs, Outputs>::SetXhat),
      py::arg("xHat"), release_gil(), py::doc(
    "Set initial state estimate x-hat.\n"
"\n"
":param xHat: The state estimate x-hat.")
  )
  
  
  
    
  .
def
("setXhat", static_cast<void(frc::KalmanFilter<States, Inputs, Outputs>::*)(int, double)>(
        &frc::KalmanFilter<States, Inputs, Outputs>::SetXhat),
      py::arg("i"), py::arg("value"), release_gil(), py::doc(
    "Set an element of the initial state estimate x-hat.\n"
"\n"
":param i:     Row of x-hat.\n"
":param value: Value for element of x-hat.")
  )
  
  
  
    
  .
def
("reset", &frc::KalmanFilter<States, Inputs, Outputs>::Reset, release_gil(), py::doc(
    "Resets the observer.")
  )
  
  
  
    
  .
def
("predict", &frc::KalmanFilter<States, Inputs, Outputs>::Predict,
      py::arg("u"), py::arg("dt"), release_gil(), py::doc(
    "Project the model into the future with a new control input u.\n"
"\n"
":param u:  New control input from controller.\n"
":param dt: Timestep for prediction.")
  )
  
  
  
    
  .
def
("correct", static_cast<void(frc::KalmanFilter<States, Inputs, Outputs>::*)(const InputVector&, const OutputVector&)>(
        &frc::KalmanFilter<States, Inputs, Outputs>::Correct),
      py::arg("u"), py::arg("y"), release_gil(), py::doc(
    "Correct the state estimate x-hat using the measurements in y.\n"
"\n"
":param u: Same control input used in the predict step.\n"
":param y: Measurement vector.")
  )
  
  
  
    
  .
def
("correct", static_cast<void(frc::KalmanFilter<States, Inputs, Outputs>::*)(const InputVector&, const OutputVector&, const Matrixd<Outputs, Outputs>&)>(
        &frc::KalmanFilter<States, Inputs, Outputs>::Correct),
      py::arg("u"), py::arg("y"), py::arg("R"), release_gil(), py::doc(
    "Correct the state estimate x-hat using the measurements in y.\n"
"\n"
"This is useful for when the measurement noise covariances vary.\n"
"\n"
":param u: Same control input used in the predict step.\n"
":param y: Measurement vector.\n"
":param R: Continuous measurement noise covariance matrix.")
  )
  
  
  ;

  



    if (set_doc) {
        cls_KalmanFilter.doc() = set_doc;
    }
    if (add_doc) {
        cls_KalmanFilter.doc() = py::cast<std::string>(cls_KalmanFilter.doc()) + add_doc;
    }

    
}

}; // struct bind_frc__KalmanFilter

}; // namespace rpygen
