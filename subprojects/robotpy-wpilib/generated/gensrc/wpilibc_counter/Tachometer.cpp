
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/counter/Tachometer.h>


#include <units_angular_velocity_type_caster.h>

#include <units_frequency_type_caster.h>

#include <units_time_type_caster.h>







#define RPYGEN_ENABLE_frc__Tachometer_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__Tachometer.hpp>







#include <frc/DigitalSource.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_Tachometer_initializer {


  

  












  
  using Tachometer_Trampoline = rpygen::PyTrampoline_frc__Tachometer<typename frc::Tachometer, typename rpygen::PyTrampolineCfg_frc__Tachometer<>>;
    static_assert(std::is_abstract<Tachometer_Trampoline>::value == false, "frc::Tachometer " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::Tachometer, Tachometer_Trampoline, wpi::Sendable> cls_Tachometer;

    

    
    

  py::module &m;

  
  rpybuild_Tachometer_initializer(py::module &m) :

  

  

  

  
    cls_Tachometer(m, "Tachometer"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_Tachometer.doc() =
    "Tachometer for getting rotational speed from a device.\n"
"\n"
"The Tachometer class measures the time between digital pulses to\n"
"determine the rotation speed of a mechanism. Examples of devices that could\n"
"be used with the tachometer class are a hall effect sensor, break beam\n"
"sensor, or optical sensor detecting tape on a shooter wheel. Unlike\n"
"encoders, this class only needs a single digital input.";

  cls_Tachometer
  
    
  .def(py::init<DigitalSource&>(),
      py::arg("source"), release_gil()
    , py::keep_alive<1, 2>(), py::doc(
    "Constructs a new tachometer.\n"
"\n"
":param source: The source.")
  )
  
  
  
    
  .def(py::init<std::shared_ptr<DigitalSource>>(),
      py::arg("source"), release_gil(), py::doc(
    "Constructs a new tachometer.\n"
"\n"
":param source: The source.")
  )
  
  
  
    
  .
def
("getFrequency", &frc::Tachometer::GetFrequency, release_gil(), py::doc(
    "Gets the tachometer frequency.\n"
"\n"
":returns: Current frequency.")
  )
  
  
  
    
  .
def
("getPeriod", &frc::Tachometer::GetPeriod, release_gil(), py::doc(
    "Gets the tachometer period.\n"
"\n"
":returns: Current period.")
  )
  
  
  
    
  .
def
("getEdgesPerRevolution", &frc::Tachometer::GetEdgesPerRevolution, release_gil(), py::doc(
    "Gets the number of edges per revolution.\n"
"\n"
":returns: Edges per revolution.")
  )
  
  
  
    
  .
def
("setEdgesPerRevolution", &frc::Tachometer::SetEdgesPerRevolution,
      py::arg("edges"), release_gil(), py::doc(
    "Sets the number of edges per revolution.\n"
"\n"
":param edges: Edges per revolution.")
  )
  
  
  
    
  .
def
("getRevolutionsPerSecond", &frc::Tachometer::GetRevolutionsPerSecond, release_gil(), py::doc(
    "Gets the current tachometer revolutions per second.\n"
"\n"
"SetEdgesPerRevolution must be set with a non 0 value for this to work.\n"
"\n"
":returns: Current RPS.")
  )
  
  
  
    
  .
def
("getRevolutionsPerMinute", &frc::Tachometer::GetRevolutionsPerMinute, release_gil(), py::doc(
    "Gets the current tachometer revolutions per minute.\n"
"\n"
"SetEdgesPerRevolution must be set with a non 0 value for this to work.\n"
"\n"
":returns: Current RPM.")
  )
  
  
  
    
  .
def
("getStopped", &frc::Tachometer::GetStopped, release_gil(), py::doc(
    "Gets if the tachometer is stopped.\n"
"\n"
":returns: True if the tachometer is stopped.")
  )
  
  
  
    
  .
def
("getSamplesToAverage", &frc::Tachometer::GetSamplesToAverage, release_gil(), py::doc(
    "Gets the number of sample to average.\n"
"\n"
":returns: Samples to average.")
  )
  
  
  
    
  .
def
("setSamplesToAverage", &frc::Tachometer::SetSamplesToAverage,
      py::arg("samples"), release_gil(), py::doc(
    "Sets the number of samples to average.\n"
"\n"
":param samples: Samples to average.")
  )
  
  
  
    
  .
def
("setMaxPeriod", &frc::Tachometer::SetMaxPeriod,
      py::arg("maxPeriod"), release_gil(), py::doc(
    "Sets the maximum period before the tachometer is considered stopped.\n"
"\n"
":param maxPeriod: The max period.")
  )
  
  
  
    
  .
def
("setUpdateWhenEmpty", &frc::Tachometer::SetUpdateWhenEmpty,
      py::arg("updateWhenEmpty"), release_gil(), py::doc(
    "Sets if to update when empty.\n"
"\n"
":param updateWhenEmpty: True to update when empty.")
  )
  
  
  
    
  .
def
("_initSendable", static_cast<void(frc::Tachometer::*)(wpi::SendableBuilder&)>(&Tachometer_Trampoline::InitSendable),
      py::arg("builder"), release_gil()
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_Tachometer_initializer

static std::unique_ptr<rpybuild_Tachometer_initializer> cls;

void begin_init_Tachometer(py::module &m) {
  cls = std::make_unique<rpybuild_Tachometer_initializer>(m);
}

void finish_init_Tachometer() {
  cls->finish();
  cls.reset();
}