
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/simulation/BuiltInAccelerometerSim.h>


#include <pybind11/functional.h>













#include <frc/BuiltInAccelerometer.h>



#include <type_traits>


  using namespace frc;

  using namespace frc::sim;





struct rpybuild_BuiltInAccelerometerSim_initializer {


  

  












  py::class_<typename frc::sim::BuiltInAccelerometerSim> cls_BuiltInAccelerometerSim;

    

    
    

  py::module &m;

  
  rpybuild_BuiltInAccelerometerSim_initializer(py::module &m) :

  

  

  

  
    cls_BuiltInAccelerometerSim(m, "BuiltInAccelerometerSim"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_BuiltInAccelerometerSim.doc() =
    "Class to control a simulated built-in accelerometer.";

  cls_BuiltInAccelerometerSim
  
    
  .def(py::init<>(), release_gil(), py::doc(
    "Constructs for the first built-in accelerometer.")
  )
  
  
  
    
  .def(py::init<const BuiltInAccelerometer&>(),
      py::arg("accel"), release_gil()
    , py::keep_alive<1, 2>(), py::doc(
    "Constructs from a BuiltInAccelerometer object.\n"
"\n"
":param accel: BuiltInAccelerometer to simulate")
  )
  
  
  
    
  .
def
("registerActiveCallback", &frc::sim::BuiltInAccelerometerSim::RegisterActiveCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run when this accelerometer activates.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to run the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def
("getActive", &frc::sim::BuiltInAccelerometerSim::GetActive, release_gil(), py::doc(
    "Check whether the accelerometer is active.\n"
"\n"
":returns: true if active")
  )
  
  
  
    
  .
def
("setActive", &frc::sim::BuiltInAccelerometerSim::SetActive,
      py::arg("active"), release_gil(), py::doc(
    "Define whether this accelerometer is active.\n"
"\n"
":param active: the new state")
  )
  
  
  
    
  .
def
("registerRangeCallback", &frc::sim::BuiltInAccelerometerSim::RegisterRangeCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the range changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to call the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def
("getRange", &frc::sim::BuiltInAccelerometerSim::GetRange, release_gil(), py::doc(
    "Check the range of this accelerometer.\n"
"\n"
":returns: the accelerometer range")
  )
  
  
  
    
  .
def
("setRange", &frc::sim::BuiltInAccelerometerSim::SetRange,
      py::arg("range"), release_gil(), py::doc(
    "Change the range of this accelerometer.\n"
"\n"
":param range: the new accelerometer range")
  )
  
  
  
    
  .
def
("registerXCallback", &frc::sim::BuiltInAccelerometerSim::RegisterXCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the X axis value changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to call the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def
("getX", &frc::sim::BuiltInAccelerometerSim::GetX, release_gil(), py::doc(
    "Measure the X axis value.\n"
"\n"
":returns: the X axis measurement")
  )
  
  
  
    
  .
def
("setX", &frc::sim::BuiltInAccelerometerSim::SetX,
      py::arg("x"), release_gil(), py::doc(
    "Change the X axis value of the accelerometer.\n"
"\n"
":param x: the new reading of the X axis")
  )
  
  
  
    
  .
def
("registerYCallback", &frc::sim::BuiltInAccelerometerSim::RegisterYCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the Y axis value changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to call the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def
("getY", &frc::sim::BuiltInAccelerometerSim::GetY, release_gil(), py::doc(
    "Measure the Y axis value.\n"
"\n"
":returns: the Y axis measurement")
  )
  
  
  
    
  .
def
("setY", &frc::sim::BuiltInAccelerometerSim::SetY,
      py::arg("y"), release_gil(), py::doc(
    "Change the Y axis value of the accelerometer.\n"
"\n"
":param y: the new reading of the Y axis")
  )
  
  
  
    
  .
def
("registerZCallback", &frc::sim::BuiltInAccelerometerSim::RegisterZCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the Z axis value changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to call the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def
("getZ", &frc::sim::BuiltInAccelerometerSim::GetZ, release_gil(), py::doc(
    "Measure the Z axis value.\n"
"\n"
":returns: the Z axis measurement")
  )
  
  
  
    
  .
def
("setZ", &frc::sim::BuiltInAccelerometerSim::SetZ,
      py::arg("z"), release_gil(), py::doc(
    "Change the Z axis value of the accelerometer.\n"
"\n"
":param z: the new reading of the Z axis")
  )
  
  
  
    
  .
def
("resetData", &frc::sim::BuiltInAccelerometerSim::ResetData, release_gil(), py::doc(
    "Reset all simulation data of this object.")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_BuiltInAccelerometerSim_initializer

static std::unique_ptr<rpybuild_BuiltInAccelerometerSim_initializer> cls;

void begin_init_BuiltInAccelerometerSim(py::module &m) {
  cls = std::make_unique<rpybuild_BuiltInAccelerometerSim_initializer>(m);
}

void finish_init_BuiltInAccelerometerSim() {
  cls->finish();
  cls.reset();
}