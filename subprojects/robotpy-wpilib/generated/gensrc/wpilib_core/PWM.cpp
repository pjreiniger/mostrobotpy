
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/PWM.h>


#include <units_time_type_caster.h>







#define RPYGEN_ENABLE_frc__PWM_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__PWM.hpp>







#include <wpi/sendable/SendableBuilder.h>

#include <frc/AddressableLED.h>

#include <wpi/SmallString.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_PWM_initializer {


  

  












  
  using PWM_Trampoline = rpygen::PyTrampoline_frc__PWM<typename frc::PWM, typename rpygen::PyTrampolineCfg_frc__PWM<>>;
    static_assert(std::is_abstract<PWM_Trampoline>::value == false, "frc::PWM " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::PWM, PWM_Trampoline, wpi::Sendable> cls_PWM;

    
    
  py::enum_<frc::PWM::PeriodMultiplier> cls_PWM_enum1;
    

    
    

  py::module &m;

  
  rpybuild_PWM_initializer(py::module &m) :

  

  

  

  
    cls_PWM(m, "PWM"),

  
    cls_PWM_enum1
  (cls_PWM, "PeriodMultiplier"
  ,
    "Represents the amount to multiply the minimum servo-pulse pwm period by."),
  

  
  
  

    m(m)
  {
    
    

    
    
  
    cls_PWM_enum1
  
    .value("kPeriodMultiplier_1X", frc::PWM::PeriodMultiplier::kPeriodMultiplier_1X,
      "Don't skip pulses. PWM pulses occur every 5.05 ms")
  
    .value("kPeriodMultiplier_2X", frc::PWM::PeriodMultiplier::kPeriodMultiplier_2X,
      "Skip every other pulse. PWM pulses occur every 10.10 ms")
  
    .value("kPeriodMultiplier_4X", frc::PWM::PeriodMultiplier::kPeriodMultiplier_4X,
      "Skip three out of four pulses. PWM pulses occur every 20.20 ms")
  ;

  

    
    
  }

void finish() {





  {
  
  
  using PeriodMultiplier [[maybe_unused]] = typename frc::PWM::PeriodMultiplier;
  
  


  

  cls_PWM.doc() =
    "Class implements the PWM generation in the FPGA.\n"
"\n"
"The values supplied as arguments for PWM outputs range from -1.0 to 1.0. They\n"
"are mapped to the microseconds to keep the pulse high, with a range of 0\n"
"(off) to 4096. Changes are immediately sent to the FPGA, and the update\n"
"occurs at the next FPGA cycle (5.05ms). There is no delay.";

  cls_PWM
  
    
  .def(py::init<int, bool>(),
      py::arg("channel"), py::arg("registerSendable") = true, release_gil(), py::doc(
    "Allocate a PWM given a channel number.\n"
"\n"
"Checks channel value range and allocates the appropriate channel.\n"
"The allocation is only done to help users ensure that they don't double\n"
"assign channels.\n"
"\n"
":param channel:          The PWM channel number. 0-9 are on-board, 10-19 are on the\n"
"                         MXP port\n"
":param registerSendable: If true, adds this instance to SendableRegistry\n"
"                         and LiveWindow")
  )
  
  
  
    
  .
def
("setPulseTime", &frc::PWM::SetPulseTime,
      py::arg("time"), release_gil(), py::doc(
    "Set the PWM pulse time directly to the hardware.\n"
"\n"
"Write a microsecond value to a PWM channel.\n"
"\n"
":param time: Microsecond PWM value.")
  )
  
  
  
    
  .
def
("getPulseTime", &frc::PWM::GetPulseTime, release_gil(), py::doc(
    "Get the PWM pulse time directly from the hardware.\n"
"\n"
"Read a microsecond value from a PWM channel.\n"
"\n"
":returns: Microsecond PWM control value.")
  )
  
  
  
    
  .
def
("setPosition", &frc::PWM::SetPosition,
      py::arg("pos"), release_gil(), py::doc(
    "Set the PWM value based on a position.\n"
"\n"
"This is intended to be used by servos.\n"
"\n"
"@pre SetBounds() called.\n"
"\n"
":param pos: The position to set the servo between 0.0 and 1.0.")
  )
  
  
  
    
  .
def
("getPosition", &frc::PWM::GetPosition, release_gil(), py::doc(
    "Get the PWM value in terms of a position.\n"
"\n"
"This is intended to be used by servos.\n"
"\n"
"@pre SetBounds() called.\n"
"\n"
":returns: The position the servo is set to between 0.0 and 1.0.")
  )
  
  
  
    
  .
def
("setSpeed", &frc::PWM::SetSpeed,
      py::arg("speed"), release_gil(), py::doc(
    "Set the PWM value based on a speed.\n"
"\n"
"This is intended to be used by motor controllers.\n"
"\n"
"@pre SetBounds() called.\n"
"\n"
":param speed: The speed to set the motor controller between -1.0 and 1.0.")
  )
  
  
  
    
  .
def
("getSpeed", &frc::PWM::GetSpeed, release_gil(), py::doc(
    "Get the PWM value in terms of speed.\n"
"\n"
"This is intended to be used by motor controllers.\n"
"\n"
"@pre SetBounds() called.\n"
"\n"
":returns: The most recently set speed between -1.0 and 1.0.")
  )
  
  
  
    
  .
def
("setDisabled", &frc::PWM::SetDisabled, release_gil(), py::doc(
    "Temporarily disables the PWM output. The next set call will re-enable\n"
"the output.")
  )
  
  
  
    
  .
def
("setPeriodMultiplier", &frc::PWM::SetPeriodMultiplier,
      py::arg("mult"), release_gil(), py::doc(
    "Slow down the PWM signal for old devices.\n"
"\n"
":param mult: The period multiplier to apply to this channel")
  )
  
  
  
    
  .
def
("setZeroLatch", &frc::PWM::SetZeroLatch, release_gil(), py::doc(
    "Latches PWM to zero.")
  )
  
  
  
    
  .
def
("enableDeadbandElimination", &frc::PWM::EnableDeadbandElimination,
      py::arg("eliminateDeadband"), release_gil(), py::doc(
    "Optionally eliminate the deadband from a motor controller.\n"
"\n"
":param eliminateDeadband: If true, set the motor curve on the motor\n"
"                          controller to eliminate the deadband in the middle\n"
"                          of the range. Otherwise, keep the full range\n"
"                          without modifying any values.")
  )
  
  
  
    
  .
def
("setBounds", &frc::PWM::SetBounds,
      py::arg("max"), py::arg("deadbandMax"), py::arg("center"), py::arg("deadbandMin"), py::arg("min"), release_gil(), py::doc(
    "Set the bounds on the PWM pulse widths.\n"
"\n"
"This sets the bounds on the PWM values for a particular type of controller.\n"
"The values determine the upper and lower speeds as well as the deadband\n"
"bracket.\n"
"\n"
":param max:         The max PWM pulse width in us\n"
":param deadbandMax: The high end of the deadband range pulse width in us\n"
":param center:      The center (off) pulse width in us\n"
":param deadbandMin: The low end of the deadband pulse width in us\n"
":param min:         The minimum pulse width in us")
  )
  
  
  
    
  .
def
("getBounds", &frc::PWM::GetBounds,
      py::arg("max"), py::arg("deadbandMax"), py::arg("center"), py::arg("deadbandMin"), py::arg("min"), release_gil(), py::doc(
    "Get the bounds on the PWM values.\n"
"\n"
"This gets the bounds on the PWM values for a particular each type of\n"
"controller. The values determine the upper and lower speeds as well as the\n"
"deadband bracket.\n"
"\n"
":param max:         The maximum pwm value\n"
":param deadbandMax: The high end of the deadband range\n"
":param center:      The center speed (off)\n"
":param deadbandMin: The low end of the deadband range\n"
":param min:         The minimum pwm value")
  )
  
  
  
    
  .
def
("setAlwaysHighMode", &frc::PWM::SetAlwaysHighMode, release_gil(), py::doc(
    "Sets the PWM output to be a continuous high signal while enabled.")
  )
  
  
  
    
  .
def
("getChannel", &frc::PWM::GetChannel, release_gil()
  )
  
  
  
    
  .
def
("_initSendable", static_cast<void(frc::PWM::*)(wpi::SendableBuilder&)>(&PWM_Trampoline::InitSendable),
      py::arg("builder"), release_gil()
  )
  
  
  ;

  


  }







  cls_PWM
  .def("__repr__", [](py::handle self) {
    py::object type_name = self.get_type().attr("__qualname__");
    int channel = self.cast<PWM&>().GetChannel();
    return py::str("<{} {}>").format(type_name, channel);
  });


}

}; // struct rpybuild_PWM_initializer

static std::unique_ptr<rpybuild_PWM_initializer> cls;

void begin_init_PWM(py::module &m) {
  cls = std::make_unique<rpybuild_PWM_initializer>(m);
}

void finish_init_PWM() {
  cls->finish();
  cls.reset();
}