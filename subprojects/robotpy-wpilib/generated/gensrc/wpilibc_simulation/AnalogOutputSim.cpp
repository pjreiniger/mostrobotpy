
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/simulation/AnalogOutputSim.h>


#include <pybind11/functional.h>













#include <frc/AnalogOutput.h>



#include <type_traits>


  using namespace frc;

  using namespace frc::sim;





struct rpybuild_AnalogOutputSim_initializer {


  

  












  py::class_<typename frc::sim::AnalogOutputSim> cls_AnalogOutputSim;

    

    
    

  py::module &m;

  
  rpybuild_AnalogOutputSim_initializer(py::module &m) :

  

  

  

  
    cls_AnalogOutputSim(m, "AnalogOutputSim"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_AnalogOutputSim.doc() =
    "Class to control a simulated analog output.";

  cls_AnalogOutputSim
  
    
  .def(py::init<const AnalogOutput&>(),
      py::arg("analogOutput"), release_gil()
    , py::keep_alive<1, 2>(), py::doc(
    "Constructs from an AnalogOutput object.\n"
"\n"
":param analogOutput: AnalogOutput to simulate")
  )
  
  
  
    
  .def(py::init<int>(),
      py::arg("channel"), release_gil(), py::doc(
    "Constructs from an analog output channel number.\n"
"\n"
":param channel: Channel number")
  )
  
  
  
    
  .
def
("registerVoltageCallback", &frc::sim::AnalogOutputSim::RegisterVoltageCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the voltage changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to call the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def
("getVoltage", &frc::sim::AnalogOutputSim::GetVoltage, release_gil(), py::doc(
    "Read the analog output voltage.\n"
"\n"
":returns: the voltage on this analog output")
  )
  
  
  
    
  .
def
("setVoltage", &frc::sim::AnalogOutputSim::SetVoltage,
      py::arg("voltage"), release_gil(), py::doc(
    "Set the analog output voltage.\n"
"\n"
":param voltage: the new voltage on this analog output")
  )
  
  
  
    
  .
def
("registerInitializedCallback", &frc::sim::AnalogOutputSim::RegisterInitializedCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run when this analog output is initialized.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to run the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def
("getInitialized", &frc::sim::AnalogOutputSim::GetInitialized, release_gil(), py::doc(
    "Check whether this analog output has been initialized.\n"
"\n"
":returns: true if initialized")
  )
  
  
  
    
  .
def
("setInitialized", &frc::sim::AnalogOutputSim::SetInitialized,
      py::arg("initialized"), release_gil(), py::doc(
    "Define whether this analog output has been initialized.\n"
"\n"
":param initialized: whether this object is initialized")
  )
  
  
  
    
  .
def
("resetData", &frc::sim::AnalogOutputSim::ResetData, release_gil(), py::doc(
    "Reset all simulation data on this object.")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_AnalogOutputSim_initializer

static std::unique_ptr<rpybuild_AnalogOutputSim_initializer> cls;

void begin_init_AnalogOutputSim(py::module &m) {
  cls = std::make_unique<rpybuild_AnalogOutputSim_initializer>(m);
}

void finish_init_AnalogOutputSim() {
  cls->finish();
  cls.reset();
}