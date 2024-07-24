
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/Encoder.h>


#include <units_time_type_caster.h>







#define RPYGEN_ENABLE_frc__Encoder_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__Encoder.hpp>







#include <wpi/sendable/SendableBuilder.h>

#include <frc/DigitalSource.h>

#include <frc/DigitalGlitchFilter.h>

#include <frc/DMA.h>

#include <frc/DMASample.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_Encoder_initializer {


  
    using EncodingType = frc::Encoder::EncodingType;
  

  












  
  using Encoder_Trampoline = rpygen::PyTrampoline_frc__Encoder<typename frc::Encoder, typename rpygen::PyTrampolineCfg_frc__Encoder<>>;
    static_assert(std::is_abstract<Encoder_Trampoline>::value == false, "frc::Encoder " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::Encoder, Encoder_Trampoline, frc::CounterBase, wpi::Sendable> cls_Encoder;

    
    
  py::enum_<frc::Encoder::IndexingType> cls_Encoder_enum1;
    

    
    

  py::module &m;

  
  rpybuild_Encoder_initializer(py::module &m) :

  

  

  

  
    cls_Encoder(m, "Encoder"),

  
    cls_Encoder_enum1
  (cls_Encoder, "IndexingType"
  ,
    "Encoder indexing types."),
  

  
  
  

    m(m)
  {
    
    

    
    
  
    cls_Encoder_enum1
  
    .value("kResetWhileHigh", frc::Encoder::IndexingType::kResetWhileHigh,
      "Reset while the signal is high.")
  
    .value("kResetWhileLow", frc::Encoder::IndexingType::kResetWhileLow,
      "Reset while the signal is low.")
  
    .value("kResetOnFallingEdge", frc::Encoder::IndexingType::kResetOnFallingEdge,
      "Reset on falling edge of the signal.")
  
    .value("kResetOnRisingEdge", frc::Encoder::IndexingType::kResetOnRisingEdge,
      "Reset on rising edge of the signal.")
  ;

  

    
    
  }

void finish() {





  {
  
  
  using IndexingType [[maybe_unused]] = typename frc::Encoder::IndexingType;
  
  


  

  cls_Encoder.doc() =
    "Class to read quad encoders.\n"
"\n"
"Quadrature encoders are devices that count shaft rotation and can sense\n"
"direction. The output of the QuadEncoder class is an integer that can count\n"
"either up or down, and can go negative for reverse direction counting. When\n"
"creating QuadEncoders, a direction is supplied that changes the sense of the\n"
"output to make code more readable if the encoder is mounted such that forward\n"
"movement generates negative values. Quadrature encoders have two digital\n"
"outputs, an A Channel and a B Channel that are out of phase with each other\n"
"to allow the FPGA to do direction sensing.\n"
"\n"
"All encoders will immediately start counting - Reset() them if you need them\n"
"to be zeroed before use.";

  cls_Encoder
  
    
  .def(py::init<int, int, bool, EncodingType>(),
      py::arg("aChannel"), py::arg("bChannel"), py::arg("reverseDirection") = false, py::arg("encodingType") = frc::Encoder::EncodingType::k4X, release_gil(), py::doc(
    "Encoder constructor.\n"
"\n"
"Construct a Encoder given a and b channels.\n"
"\n"
"The counter will start counting immediately.\n"
"\n"
":param aChannel:         The a channel DIO channel. 0-9 are on-board, 10-25\n"
"                         are on the MXP port\n"
":param bChannel:         The b channel DIO channel. 0-9 are on-board, 10-25\n"
"                         are on the MXP port\n"
":param reverseDirection: represents the orientation of the encoder and\n"
"                         inverts the output values if necessary so forward\n"
"                         represents positive values.\n"
":param encodingType:     either k1X, k2X, or k4X to indicate 1X, 2X or 4X\n"
"                         decoding. If 4X is selected, then an encoder FPGA\n"
"                         object is used and the returned counts will be 4x\n"
"                         the encoder spec'd value since all rising and\n"
"                         falling edges are counted. If 1X or 2X are selected\n"
"                         then a counter object will be used and the returned\n"
"                         value will either exactly match the spec'd count or\n"
"                         be double (2x) the spec'd count.")
  )
  
  
  
    
  .def(py::init<std::shared_ptr<DigitalSource>, std::shared_ptr<DigitalSource>, bool, EncodingType>(),
      py::arg("aSource"), py::arg("bSource"), py::arg("reverseDirection") = false, py::arg("encodingType") = frc::Encoder::EncodingType::k4X, release_gil()
  )
  
  
  
    
  .
def
("get", &frc::Encoder::Get, release_gil(), py::doc(
    "Gets the current count.\n"
"\n"
"Returns the current count on the Encoder. This method compensates for the\n"
"decoding type.\n"
"\n"
":returns: Current count from the Encoder adjusted for the 1x, 2x, or 4x scale\n"
"          factor.")
  )
  
  
  
    
  .
def
("reset", &frc::Encoder::Reset, release_gil(), py::doc(
    "Reset the Encoder distance to zero.\n"
"\n"
"Resets the current count to zero on the encoder.")
  )
  
  
  
    
  .
def
("getPeriod", &frc::Encoder::GetPeriod, release_gil(), py::doc(
    "Returns the period of the most recent pulse.\n"
"\n"
"Returns the period of the most recent Encoder pulse in seconds. This method\n"
"compensates for the decoding type.\n"
"\n"
"Warning: This returns unscaled periods. Use GetRate() for rates that are\n"
"scaled using the value from SetDistancePerPulse().\n"
"\n"
":deprecated: Use getRate() in favor of this method.\n"
"\n"
":returns: Period in seconds of the most recent pulse.")
  )
  
  
  
    
  .
def
("setMaxPeriod", &frc::Encoder::SetMaxPeriod,
      py::arg("maxPeriod"), release_gil(), py::doc(
    "Sets the maximum period for stopped detection.\n"
"\n"
"Sets the value that represents the maximum period of the Encoder before it\n"
"will assume that the attached device is stopped. This timeout allows users\n"
"to determine if the wheels or other shaft has stopped rotating.\n"
"This method compensates for the decoding type.\n"
"\n"
":deprecated: Use SetMinRate() in favor of this method.  This takes unscaled\n"
"             periods and SetMinRate() scales using value from\n"
"             SetDistancePerPulse().\n"
"\n"
":param maxPeriod: The maximum time between rising and falling edges before\n"
"                  the FPGA will report the device stopped. This is expressed\n"
"                  in seconds.")
  )
  
  
  
    
  .
def
("getStopped", &frc::Encoder::GetStopped, release_gil(), py::doc(
    "Determine if the encoder is stopped.\n"
"\n"
"Using the MaxPeriod value, a boolean is returned that is true if the\n"
"encoder is considered stopped and false if it is still moving. A stopped\n"
"encoder is one where the most recent pulse width exceeds the MaxPeriod.\n"
"\n"
":returns: True if the encoder is considered stopped.")
  )
  
  
  
    
  .
def
("getDirection", &frc::Encoder::GetDirection, release_gil(), py::doc(
    "The last direction the encoder value changed.\n"
"\n"
":returns: The last direction the encoder value changed.")
  )
  
  
  
    
  .
def
("getRaw", &frc::Encoder::GetRaw, release_gil(), py::doc(
    "Gets the raw value from the encoder.\n"
"\n"
"The raw value is the actual count unscaled by the 1x, 2x, or 4x scale\n"
"factor.\n"
"\n"
":returns: Current raw count from the encoder")
  )
  
  
  
    
  .
def
("getEncodingScale", &frc::Encoder::GetEncodingScale, release_gil(), py::doc(
    "The encoding scale factor 1x, 2x, or 4x, per the requested encodingType.\n"
"\n"
"Used to divide raw edge counts down to spec'd counts.")
  )
  
  
  
    
  .
def
("getDistance", &frc::Encoder::GetDistance, release_gil(), py::doc(
    "Get the distance the robot has driven since the last reset.\n"
"\n"
":returns: The distance driven since the last reset as scaled by the value\n"
"          from SetDistancePerPulse().")
  )
  
  
  
    
  .
def
("getRate", &frc::Encoder::GetRate, release_gil(), py::doc(
    "Get the current rate of the encoder.\n"
"\n"
"Units are distance per second as scaled by the value from\n"
"SetDistancePerPulse().\n"
"\n"
":returns: The current rate of the encoder.")
  )
  
  
  
    
  .
def
("setMinRate", &frc::Encoder::SetMinRate,
      py::arg("minRate"), release_gil(), py::doc(
    "Set the minimum rate of the device before the hardware reports it stopped.\n"
"\n"
":param minRate: The minimum rate.  The units are in distance per second as\n"
"                scaled by the value from SetDistancePerPulse().")
  )
  
  
  
    
  .
def
("setDistancePerPulse", &frc::Encoder::SetDistancePerPulse,
      py::arg("distancePerPulse"), release_gil(), py::doc(
    "Set the distance per pulse for this encoder.\n"
"\n"
"This sets the multiplier used to determine the distance driven based on the\n"
"count value from the encoder.\n"
"\n"
"Do not include the decoding type in this scale.  The library already\n"
"compensates for the decoding type.\n"
"\n"
"Set this value based on the encoder's rated Pulses per Revolution and\n"
"factor in gearing reductions following the encoder shaft.\n"
"\n"
"This distance can be in any units you like, linear or angular.\n"
"\n"
":param distancePerPulse: The scale factor that will be used to convert\n"
"                         pulses to useful units.")
  )
  
  
  
    
  .
def
("getDistancePerPulse", &frc::Encoder::GetDistancePerPulse, release_gil(), py::doc(
    "Get the distance per pulse for this encoder.\n"
"\n"
":returns: The scale factor that will be used to convert pulses to useful\n"
"          units.")
  )
  
  
  
    
  .
def
("setReverseDirection", &frc::Encoder::SetReverseDirection,
      py::arg("reverseDirection"), release_gil(), py::doc(
    "Set the direction sensing for this encoder.\n"
"\n"
"This sets the direction sensing on the encoder so that it could count in\n"
"the correct software direction regardless of the mounting.\n"
"\n"
":param reverseDirection: true if the encoder direction should be reversed")
  )
  
  
  
    
  .
def
("setSamplesToAverage", &frc::Encoder::SetSamplesToAverage,
      py::arg("samplesToAverage"), release_gil(), py::doc(
    "Set the Samples to Average which specifies the number of samples of the\n"
"timer to average when calculating the period.\n"
"\n"
"Perform averaging to account for mechanical imperfections or as\n"
"oversampling to increase resolution.\n"
"\n"
":param samplesToAverage: The number of samples to average from 1 to 127.")
  )
  
  
  
    
  .
def
("getSamplesToAverage", &frc::Encoder::GetSamplesToAverage, release_gil(), py::doc(
    "Get the Samples to Average which specifies the number of samples of the\n"
"timer to average when calculating the period.\n"
"\n"
"Perform averaging to account for mechanical imperfections or as\n"
"oversampling to increase resolution.\n"
"\n"
":returns: The number of samples being averaged (from 1 to 127)")
  )
  
  
  
    
  .
def
("setIndexSource", static_cast<void(frc::Encoder::*)(int, IndexingType)>(
        &frc::Encoder::SetIndexSource),
      py::arg("channel"), py::arg("type") = frc::Encoder::IndexingType::kResetOnRisingEdge, release_gil(), py::doc(
    "Set the index source for the encoder.\n"
"\n"
"When this source is activated, the encoder count automatically resets.\n"
"\n"
":param channel: A DIO channel to set as the encoder index\n"
":param type:    The state that will cause the encoder to reset")
  )
  
  
  
    
  .
def
("setIndexSource", static_cast<void(frc::Encoder::*)(const DigitalSource&, IndexingType)>(
        &frc::Encoder::SetIndexSource),
      py::arg("source"), py::arg("type") = frc::Encoder::IndexingType::kResetOnRisingEdge, release_gil(), py::doc(
    "Set the index source for the encoder.\n"
"\n"
"When this source is activated, the encoder count automatically resets.\n"
"\n"
":param source: A digital source to set as the encoder index\n"
":param type:   The state that will cause the encoder to reset")
  )
  
  
  
    
  .
def
("setSimDevice", &frc::Encoder::SetSimDevice,
      py::arg("device"), release_gil(), py::doc(
    "Indicates this encoder is used by a simulated device.\n"
"\n"
":param device: simulated device handle")
  )
  
  
  
    
  .
def
("getFPGAIndex", &frc::Encoder::GetFPGAIndex, release_gil()
  )
  
  
  
    
  .
def
("initSendable", &frc::Encoder::InitSendable,
      py::arg("builder"), release_gil()
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_Encoder_initializer

static std::unique_ptr<rpybuild_Encoder_initializer> cls;

void begin_init_Encoder(py::module &m) {
  cls = std::make_unique<rpybuild_Encoder_initializer>(m);
}

void finish_init_Encoder() {
  cls->finish();
  cls.reset();
}