
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/DigitalGlitchFilter.h>








#define RPYGEN_ENABLE_frc__DigitalGlitchFilter_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__DigitalGlitchFilter.hpp>







#include <wpi/sendable/SendableBuilder.h>

#include <frc/Counter.h>

#include <frc/Encoder.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_DigitalGlitchFilter_initializer {


  

  












  
  using DigitalGlitchFilter_Trampoline = rpygen::PyTrampoline_frc__DigitalGlitchFilter<typename frc::DigitalGlitchFilter, typename rpygen::PyTrampolineCfg_frc__DigitalGlitchFilter<>>;
    static_assert(std::is_abstract<DigitalGlitchFilter_Trampoline>::value == false, "frc::DigitalGlitchFilter " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::DigitalGlitchFilter, DigitalGlitchFilter_Trampoline, wpi::Sendable> cls_DigitalGlitchFilter;

    

    
    

  py::module &m;

  
  rpybuild_DigitalGlitchFilter_initializer(py::module &m) :

  

  

  

  
    cls_DigitalGlitchFilter(m, "DigitalGlitchFilter"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_DigitalGlitchFilter.doc() =
    "Class to enable glitch filtering on a set of digital inputs.\n"
"\n"
"This class will manage adding and removing digital inputs from a FPGA glitch\n"
"filter. The filter lets the user configure the time that an input must remain\n"
"high or low before it is classified as high or low.";

  cls_DigitalGlitchFilter
  
    
  .def(py::init<>(), release_gil()
  )
  
  
  
    
  .
def
("add", static_cast<void(frc::DigitalGlitchFilter::*)(DigitalSource*)>(
        &frc::DigitalGlitchFilter::Add),
      py::arg("input"), release_gil(), py::doc(
    "Assigns the DigitalSource to this glitch filter.\n"
"\n"
":param input: The DigitalSource to add.")
  )
  
  
  
    
  .
def
("add", static_cast<void(frc::DigitalGlitchFilter::*)(Encoder*)>(
        &frc::DigitalGlitchFilter::Add),
      py::arg("input"), release_gil(), py::doc(
    "Assigns the Encoder to this glitch filter.\n"
"\n"
":param input: The Encoder to add.")
  )
  
  
  
    
  .
def
("add", static_cast<void(frc::DigitalGlitchFilter::*)(Counter*)>(
        &frc::DigitalGlitchFilter::Add),
      py::arg("input"), release_gil(), py::doc(
    "Assigns the Counter to this glitch filter.\n"
"\n"
":param input: The Counter to add.")
  )
  
  
  
    
  .
def
("remove", static_cast<void(frc::DigitalGlitchFilter::*)(DigitalSource*)>(
        &frc::DigitalGlitchFilter::Remove),
      py::arg("input"), release_gil(), py::doc(
    "Removes a digital input from this filter.\n"
"\n"
"Removes the DigitalSource from this glitch filter and re-assigns it to\n"
"the default filter.\n"
"\n"
":param input: The DigitalSource to remove.")
  )
  
  
  
    
  .
def
("remove", static_cast<void(frc::DigitalGlitchFilter::*)(Encoder*)>(
        &frc::DigitalGlitchFilter::Remove),
      py::arg("input"), release_gil(), py::doc(
    "Removes an encoder from this filter.\n"
"\n"
"Removes the Encoder from this glitch filter and re-assigns it to\n"
"the default filter.\n"
"\n"
":param input: The Encoder to remove.")
  )
  
  
  
    
  .
def
("remove", static_cast<void(frc::DigitalGlitchFilter::*)(Counter*)>(
        &frc::DigitalGlitchFilter::Remove),
      py::arg("input"), release_gil(), py::doc(
    "Removes a counter from this filter.\n"
"\n"
"Removes the Counter from this glitch filter and re-assigns it to\n"
"the default filter.\n"
"\n"
":param input: The Counter to remove.")
  )
  
  
  
    
  .
def
("setPeriodCycles", &frc::DigitalGlitchFilter::SetPeriodCycles,
      py::arg("fpgaCycles"), release_gil(), py::doc(
    "Sets the number of cycles that the input must not change state for.\n"
"\n"
":param fpgaCycles: The number of FPGA cycles.")
  )
  
  
  
    
  .
def
("setPeriodNanoSeconds", &frc::DigitalGlitchFilter::SetPeriodNanoSeconds,
      py::arg("nanoseconds"), release_gil(), py::doc(
    "Sets the number of nanoseconds that the input must not change state for.\n"
"\n"
":param nanoseconds: The number of nanoseconds.")
  )
  
  
  
    
  .
def
("getPeriodCycles", &frc::DigitalGlitchFilter::GetPeriodCycles, release_gil(), py::doc(
    "Gets the number of cycles that the input must not change state for.\n"
"\n"
":returns: The number of cycles.")
  )
  
  
  
    
  .
def
("getPeriodNanoSeconds", &frc::DigitalGlitchFilter::GetPeriodNanoSeconds, release_gil(), py::doc(
    "Gets the number of nanoseconds that the input must not change state for.\n"
"\n"
":returns: The number of nanoseconds.")
  )
  
  
  
    
  .
def
("initSendable", &frc::DigitalGlitchFilter::InitSendable,
      py::arg("builder"), release_gil()
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_DigitalGlitchFilter_initializer

static std::unique_ptr<rpybuild_DigitalGlitchFilter_initializer> cls;

void begin_init_DigitalGlitchFilter(py::module &m) {
  cls = std::make_unique<rpybuild_DigitalGlitchFilter_initializer>(m);
}

void finish_init_DigitalGlitchFilter() {
  cls->finish();
  cls.reset();
}