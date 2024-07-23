
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/SPI.h>


#include <units_time_type_caster.h>

#include <wpi_span_type_caster.h>







#define RPYGEN_ENABLE_frc__SPI_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__SPI.hpp>







#include <frc/DigitalSource.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_SPI_initializer {


  

  












  
  using SPI_Trampoline = rpygen::PyTrampoline_frc__SPI<typename frc::SPI, typename rpygen::PyTrampolineCfg_frc__SPI<>>;
    static_assert(std::is_abstract<SPI_Trampoline>::value == false, "frc::SPI " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::SPI, SPI_Trampoline> cls_SPI;

    
    
  py::enum_<frc::SPI::Port> cls_SPI_enum1;
    
    
  py::enum_<frc::SPI::Mode> cls_SPI_enum2;
    

    
    

  py::module &m;

  
  rpybuild_SPI_initializer(py::module &m) :

  

  

  

  
    cls_SPI(m, "SPI"),

  
    cls_SPI_enum1
  (cls_SPI, "Port"
  ,
    "SPI port."),
  
    cls_SPI_enum2
  (cls_SPI, "Mode"
  ,
    "SPI mode."),
  

  
  
  

    m(m)
  {
    
    

    
    
  
    cls_SPI_enum1
  
    .value("kOnboardCS0", frc::SPI::Port::kOnboardCS0,
      "Onboard SPI bus port CS0.")
  
    .value("kOnboardCS1", frc::SPI::Port::kOnboardCS1,
      "Onboard SPI bus port CS1.")
  
    .value("kOnboardCS2", frc::SPI::Port::kOnboardCS2,
      "Onboard SPI bus port CS2.")
  
    .value("kOnboardCS3", frc::SPI::Port::kOnboardCS3,
      "Onboard SPI bus port CS3.")
  
    .value("kMXP", frc::SPI::Port::kMXP,
      "MXP (roboRIO MXP) SPI bus port.")
  ;

  
    cls_SPI_enum2
  
    .value("kMode0", frc::SPI::Mode::kMode0,
      "Clock idle low, data sampled on rising edge.")
  
    .value("kMode1", frc::SPI::Mode::kMode1,
      "Clock idle low, data sampled on falling edge.")
  
    .value("kMode2", frc::SPI::Mode::kMode2,
      "Clock idle high, data sampled on falling edge.")
  
    .value("kMode3", frc::SPI::Mode::kMode3,
      "Clock idle high, data sampled on rising edge.")
  ;

  

    
    
  }

void finish() {





  {
  
  
  using Port [[maybe_unused]] = typename frc::SPI::Port;
  
  using Mode [[maybe_unused]] = typename frc::SPI::Mode;
  
  


  

  cls_SPI.doc() =
    "SPI bus interface class.\n"
"\n"
"This class is intended to be used by sensor (and other SPI device) drivers.\n"
"It probably should not be used directly.";

  cls_SPI
  
    
  .def(py::init<Port>(),
      py::arg("port"), release_gil(), py::doc(
    "Constructor\n"
"\n"
":param port: the physical SPI port")
  )
  
  
  
    
  .
def
("getPort", &frc::SPI::GetPort, release_gil(), py::doc(
    "Returns the SPI port.\n"
"\n"
":returns: The SPI port.")
  )
  
  
  
    
  .
def
("setClockRate", &frc::SPI::SetClockRate,
      py::arg("hz"), release_gil(), py::doc(
    "Configure the rate of the generated clock signal.\n"
"\n"
"The default value is 500,000Hz.\n"
"The maximum value is 4,000,000Hz.\n"
"\n"
":param hz: The clock rate in Hertz.")
  )
  
  
  
    
  .
def
("setMode", &frc::SPI::SetMode,
      py::arg("mode"), release_gil(), py::doc(
    "Sets the mode for the SPI device.\n"
"\n"
"Mode 0 is Clock idle low, data sampled on rising edge\n"
"\n"
"Mode 1 is Clock idle low, data sampled on falling edge\n"
"\n"
"Mode 2 is Clock idle high, data sampled on falling edge\n"
"\n"
"Mode 3 is Clock idle high, data sampled on rising edge\n"
"\n"
":param mode: The mode to set.")
  )
  
  
  
    
  .
def
("setChipSelectActiveHigh", &frc::SPI::SetChipSelectActiveHigh, release_gil(), py::doc(
    "Configure the chip select line to be active high.")
  )
  
  
  
    
  .
def
("setChipSelectActiveLow", &frc::SPI::SetChipSelectActiveLow, release_gil(), py::doc(
    "Configure the chip select line to be active low.")
  )
  
  
  
    
  .
def
("write", [](frc::SPI * __that,const py::buffer& data) {
                    int size;
          auto __data = data.request(false);
          size = __data.size * __data.itemsize;
          auto __ret =__that->Write((uint8_t*)__data.ptr, size);
          return __ret;
        },
      py::arg("data"), release_gil(), py::doc(
    "Write data to the peripheral device.  Blocks until there is space in the\n"
"output FIFO.\n"
"\n"
"If not running in output only mode, also saves the data received\n"
"on the CIPO input during the transfer into the receive FIFO.")
  )
  
  
  
    
  .
def
("read", [](frc::SPI * __that,bool initiate, const py::buffer& dataReceived) {
                    int size;
          auto __dataReceived = dataReceived.request(true);
          size = __dataReceived.size * __dataReceived.itemsize;
          auto __ret =__that->Read(std::move(initiate), (uint8_t*)__dataReceived.ptr, size);
          return __ret;
        },
      py::arg("initiate"), py::arg("dataReceived"), release_gil(), py::doc(
    "Read a word from the receive FIFO.\n"
"\n"
"Waits for the current transfer to complete if the receive FIFO is empty.\n"
"\n"
"If the receive FIFO is empty, there is no active transfer, and initiate\n"
"is false, errors.\n"
"\n"
":param initiate:     If true, this function pushes \"0\" into the transmit\n"
"                     buffer and initiates a transfer. If false, this\n"
"                     function assumes that data is already in the receive\n"
"                     FIFO from a previous write.\n"
":param dataReceived: Buffer to receive data from the device\n"
":param size:         The length of the transaction, in bytes")
  )
  
  
  
    
  .
def
("transaction", [](frc::SPI * __that,const py::buffer& dataToSend, const py::buffer& dataReceived) {
                    int size;
          auto __dataToSend = dataToSend.request(false);
          size = __dataToSend.size * __dataToSend.itemsize;
          auto __dataReceived = dataReceived.request(true);
          size = __dataReceived.size * __dataReceived.itemsize;
          auto __ret =__that->Transaction((uint8_t*)__dataToSend.ptr, (uint8_t*)__dataReceived.ptr, size);
          return __ret;
        },
      py::arg("dataToSend"), py::arg("dataReceived"), release_gil(), py::doc(
    "Perform a simultaneous read/write transaction with the device\n"
"\n"
":param dataToSend:   The data to be written out to the device\n"
":param dataReceived: Buffer to receive data from the device\n"
":param size:         The length of the transaction, in bytes")
  )
  
  
  
    
  .
def
("initAuto", &frc::SPI::InitAuto,
      py::arg("bufferSize"), release_gil(), py::doc(
    "Initialize automatic SPI transfer engine.\n"
"\n"
"Only a single engine is available, and use of it blocks use of all other\n"
"chip select usage on the same physical SPI port while it is running.\n"
"\n"
":param bufferSize: buffer size in bytes")
  )
  
  
  
    
  .
def
("freeAuto", &frc::SPI::FreeAuto, release_gil(), py::doc(
    "Frees the automatic SPI transfer engine.")
  )
  
  
  
    
  .
def
("setAutoTransmitData", &frc::SPI::SetAutoTransmitData,
      py::arg("dataToSend"), py::arg("zeroSize"), release_gil(), py::doc(
    "Set the data to be transmitted by the engine.\n"
"\n"
"Up to 16 bytes are configurable, and may be followed by up to 127 zero\n"
"bytes.\n"
"\n"
":param dataToSend: data to send (maximum 16 bytes)\n"
":param zeroSize:   number of zeros to send after the data")
  )
  
  
  
    
  .
def
("startAutoRate", &frc::SPI::StartAutoRate,
      py::arg("period"), release_gil(), py::doc(
    "Start running the automatic SPI transfer engine at a periodic rate.\n"
"\n"
"InitAuto() and SetAutoTransmitData() must be called before calling this\n"
"function.\n"
"\n"
":param period: period between transfers (us resolution)")
  )
  
  
  
    
  .
def
("startAutoTrigger", &frc::SPI::StartAutoTrigger,
      py::arg("source"), py::arg("rising"), py::arg("falling"), release_gil(), py::doc(
    "Start running the automatic SPI transfer engine when a trigger occurs.\n"
"\n"
"InitAuto() and SetAutoTransmitData() must be called before calling this\n"
"function.\n"
"\n"
":param source:  digital source for the trigger (may be an analog trigger)\n"
":param rising:  trigger on the rising edge\n"
":param falling: trigger on the falling edge")
  )
  
  
  
    
  .
def
("stopAuto", &frc::SPI::StopAuto, release_gil(), py::doc(
    "Stop running the automatic SPI transfer engine.")
  )
  
  
  
    
  .
def
("forceAutoRead", &frc::SPI::ForceAutoRead, release_gil(), py::doc(
    "Force the engine to make a single transfer.")
  )
  
  
  
    
  .
def
("readAutoReceivedData", [](frc::SPI * __that,const py::buffer& buffer, units::second_t timeout) {
                    int numToRead;
          auto __buffer = buffer.request(true);
          numToRead = __buffer.size * __buffer.itemsize;
          auto __ret =__that->ReadAutoReceivedData((uint32_t*)__buffer.ptr, numToRead, std::move(timeout));
          return __ret;
        },
      py::arg("buffer"), py::arg("timeout"), release_gil(), py::doc(
    "Read data that has been transferred by the automatic SPI transfer engine.\n"
"\n"
"Transfers may be made a byte at a time, so it's necessary for the caller\n"
"to handle cases where an entire transfer has not been completed.\n"
"\n"
"Each received data sequence consists of a timestamp followed by the\n"
"received data bytes, one byte per word (in the least significant byte).\n"
"The length of each received data sequence is the same as the combined\n"
"size of the data and zeroSize set in SetAutoTransmitData().\n"
"\n"
"Blocks until numToRead words have been read or timeout expires.\n"
"May be called with numToRead=0 to retrieve how many words are available.\n"
"\n"
":param buffer:    buffer where read words are stored\n"
":param numToRead: number of words to read\n"
":param timeout:   timeout (ms resolution)\n"
"\n"
":returns: Number of words remaining to be read")
  )
  
  
  
    
  .
def
("getAutoDroppedCount", &frc::SPI::GetAutoDroppedCount, release_gil(), py::doc(
    "Get the number of bytes dropped by the automatic SPI transfer engine due\n"
"to the receive buffer being full.\n"
"\n"
":returns: Number of bytes dropped")
  )
  
  
  
    
  .
def
("configureAutoStall", &frc::SPI::ConfigureAutoStall,
      py::arg("port"), py::arg("csToSclkTicks"), py::arg("stallTicks"), py::arg("pow2BytesPerRead"), release_gil(), py::doc(
    "Configure the Auto SPI Stall time between reads.\n"
"\n"
":param port:             The number of the port to use. 0-3 for Onboard CS0-CS2, 4 for\n"
"                         MXP.\n"
":param csToSclkTicks:    the number of ticks to wait before asserting the cs\n"
"                         pin\n"
":param stallTicks:       the number of ticks to stall for\n"
":param pow2BytesPerRead: the number of bytes to read before stalling")
  )
  
  
  
    
  .
def
("initAccumulator", &frc::SPI::InitAccumulator,
      py::arg("period"), py::arg("cmd"), py::arg("xferSize"), py::arg("validMask"), py::arg("validValue"), py::arg("dataShift"), py::arg("dataSize"), py::arg("isSigned"), py::arg("bigEndian"), release_gil(), py::doc(
    "Initialize the accumulator.\n"
"\n"
":param period:     Time between reads\n"
":param cmd:        SPI command to send to request data\n"
":param xferSize:   SPI transfer size, in bytes\n"
":param validMask:  Mask to apply to received data for validity checking\n"
":param validValue: After valid_mask is applied, required matching value for\n"
"                   validity checking\n"
":param dataShift:  Bit shift to apply to received data to get actual data\n"
"                   value\n"
":param dataSize:   Size (in bits) of data field\n"
":param isSigned:   Is data field signed?\n"
":param bigEndian:  Is device big endian?")
  )
  
  
  
    
  .
def
("freeAccumulator", &frc::SPI::FreeAccumulator, release_gil(), py::doc(
    "Frees the accumulator.")
  )
  
  
  
    
  .
def
("resetAccumulator", &frc::SPI::ResetAccumulator, release_gil(), py::doc(
    "Resets the accumulator to zero.")
  )
  
  
  
    
  .
def
("setAccumulatorCenter", &frc::SPI::SetAccumulatorCenter,
      py::arg("center"), release_gil(), py::doc(
    "Set the center value of the accumulator.\n"
"\n"
"The center value is subtracted from each value before it is added to the\n"
"accumulator. This is used for the center value of devices like gyros and\n"
"accelerometers to make integration work and to take the device offset into\n"
"account when integrating.")
  )
  
  
  
    
  .
def
("setAccumulatorDeadband", &frc::SPI::SetAccumulatorDeadband,
      py::arg("deadband"), release_gil(), py::doc(
    "Set the accumulator's deadband.")
  )
  
  
  
    
  .
def
("getAccumulatorLastValue", &frc::SPI::GetAccumulatorLastValue, release_gil(), py::doc(
    "Read the last value read by the accumulator engine.")
  )
  
  
  
    
  .
def
("getAccumulatorValue", &frc::SPI::GetAccumulatorValue, release_gil(), py::doc(
    "Read the accumulated value.\n"
"\n"
":returns: The 64-bit value accumulated since the last Reset().")
  )
  
  
  
    
  .
def
("getAccumulatorCount", &frc::SPI::GetAccumulatorCount, release_gil(), py::doc(
    "Read the number of accumulated values.\n"
"\n"
"Read the count of the accumulated values since the accumulator was last\n"
"Reset().\n"
"\n"
":returns: The number of times samples from the channel were accumulated.")
  )
  
  
  
    
  .
def
("getAccumulatorAverage", &frc::SPI::GetAccumulatorAverage, release_gil(), py::doc(
    "Read the average of the accumulated value.\n"
"\n"
":returns: The accumulated average value (value / count).")
  )
  
  
  
    
  .
def
("getAccumulatorOutput", [](frc::SPI * __that) {
                    int64_t value;
          int64_t count;
          __that->GetAccumulatorOutput(value, count);
          return std::make_tuple(value,count);
        }, release_gil(), py::doc(
    "Read the accumulated value and the number of accumulated values atomically.\n"
"\n"
"This function reads the value and count atomically.\n"
"This can be used for averaging.\n"
"\n"
":param value: Pointer to the 64-bit accumulated output.\n"
":param count: Pointer to the number of accumulation cycles.")
  )
  
  
  
    
  .
def
("setAccumulatorIntegratedCenter", &frc::SPI::SetAccumulatorIntegratedCenter,
      py::arg("center"), release_gil(), py::doc(
    "Set the center value of the accumulator integrator.\n"
"\n"
"The center value is subtracted from each value*dt before it is added to the\n"
"integrated value. This is used for the center value of devices like gyros\n"
"and accelerometers to take the device offset into account when integrating.")
  )
  
  
  
    
  .
def
("getAccumulatorIntegratedValue", &frc::SPI::GetAccumulatorIntegratedValue, release_gil(), py::doc(
    "Read the integrated value.  This is the sum of (each value * time between\n"
"values).\n"
"\n"
":returns: The integrated value accumulated since the last Reset().")
  )
  
  
  
    
  .
def
("getAccumulatorIntegratedAverage", &frc::SPI::GetAccumulatorIntegratedAverage, release_gil(), py::doc(
    "Read the average of the integrated value.  This is the sum of (each value\n"
"times the time between values), divided by the count.\n"
"\n"
":returns: The average of the integrated value accumulated since the last\n"
"          Reset().")
  )
  
  
  
    .def_readonly("_m_mode", &rpygen::PyTrampoline_frc__SPI<typename frc::SPI, typename rpygen::PyTrampolineCfg_frc__SPI<>>::m_mode);

  


  }






}

}; // struct rpybuild_SPI_initializer

static std::unique_ptr<rpybuild_SPI_initializer> cls;

void begin_init_SPI(py::module &m) {
  cls = std::make_unique<rpybuild_SPI_initializer>(m);
}

void finish_init_SPI() {
  cls->finish();
  cls.reset();
}