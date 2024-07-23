
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/simulation/AnalogGyroSim.h>


#include <pybind11/functional.h>













#include <frc/AnalogGyro.h>



#include <type_traits>


  using namespace frc;

  using namespace frc::sim;





struct rpybuild_AnalogGyroSim_initializer {


  

  












  py::class_<typename frc::sim::AnalogGyroSim> cls_AnalogGyroSim;

    

    
    

  py::module &m;

  
  rpybuild_AnalogGyroSim_initializer(py::module &m) :

  

  

  

  
    cls_AnalogGyroSim(m, "AnalogGyroSim"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_AnalogGyroSim.doc() =
    "Class to control a simulated analog gyro.";

  cls_AnalogGyroSim
  
    
  .def(py::init<const AnalogGyro&>(),
      py::arg("gyro"), release_gil()
    , py::keep_alive<1, 2>(), py::doc(
    "Constructs from an AnalogGyro object.\n"
"\n"
":param gyro: AnalogGyro to simulate")
  )
  
  
  
    
  .def(py::init<int>(),
      py::arg("channel"), release_gil(), py::doc(
    "Constructs from an analog input channel number.\n"
"\n"
":param channel: Channel number")
  )
  
  
  
    
  .
def
("registerAngleCallback", &frc::sim::AnalogGyroSim::RegisterAngleCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback on the angle.\n"
"\n"
":param callback:      the callback that will be called whenever the angle changes\n"
":param initialNotify: if true, the callback will be run on the initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def
("getAngle", &frc::sim::AnalogGyroSim::GetAngle, release_gil(), py::doc(
    "Get the current angle of the gyro.\n"
"\n"
":returns: the angle measured by the gyro")
  )
  
  
  
    
  .
def
("setAngle", &frc::sim::AnalogGyroSim::SetAngle,
      py::arg("angle"), release_gil(), py::doc(
    "Change the angle measured by the gyro.\n"
"\n"
":param angle: the new value")
  )
  
  
  
    
  .
def
("registerRateCallback", &frc::sim::AnalogGyroSim::RegisterRateCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback on the rate.\n"
"\n"
":param callback:      the callback that will be called whenever the rate changes\n"
":param initialNotify: if true, the callback will be run on the initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def
("getRate", &frc::sim::AnalogGyroSim::GetRate, release_gil(), py::doc(
    "Get the rate of angle change on this gyro.\n"
"\n"
":returns: the rate")
  )
  
  
  
    
  .
def
("setRate", &frc::sim::AnalogGyroSim::SetRate,
      py::arg("rate"), release_gil(), py::doc(
    "Change the rate of the gyro.\n"
"\n"
":param rate: the new rate")
  )
  
  
  
    
  .
def
("registerInitializedCallback", &frc::sim::AnalogGyroSim::RegisterInitializedCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback on whether the gyro is initialized.\n"
"\n"
":param callback:      the callback that will be called whenever the gyro is\n"
"                      initialized\n"
":param initialNotify: if true, the callback will be run on the initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def
("getInitialized", &frc::sim::AnalogGyroSim::GetInitialized, release_gil(), py::doc(
    "Check if the gyro is initialized.\n"
"\n"
":returns: true if initialized")
  )
  
  
  
    
  .
def
("setInitialized", &frc::sim::AnalogGyroSim::SetInitialized,
      py::arg("initialized"), release_gil(), py::doc(
    "Set whether this gyro is initialized.\n"
"\n"
":param initialized: the new value")
  )
  
  
  
    
  .
def
("resetData", &frc::sim::AnalogGyroSim::ResetData, release_gil(), py::doc(
    "Reset all simulation data for this object.")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_AnalogGyroSim_initializer

static std::unique_ptr<rpybuild_AnalogGyroSim_initializer> cls;

void begin_init_AnalogGyroSim(py::module &m) {
  cls = std::make_unique<rpybuild_AnalogGyroSim_initializer>(m);
}

void finish_init_AnalogGyroSim() {
  cls->finish();
  cls.reset();
}