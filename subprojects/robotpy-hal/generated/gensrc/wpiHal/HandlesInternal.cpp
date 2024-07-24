
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <hal/handles/HandlesInternal.h>
















#include <type_traits>


  using namespace hal;





struct rpybuild_HandlesInternal_initializer {







  
  py::enum_<hal::HAL_HandleEnum> enum1;







  py::module &m;

  
  rpybuild_HandlesInternal_initializer(py::module &m) :

  

  
    enum1
  (m, "HandleEnum"
  ,
    "Enum of HAL handle types. Vendors/Teams should use Vendor (17)."),
  

  

  

    m(m)
  {
    
    
      enum1
  
    .value("Undefined", hal::HAL_HandleEnum::Undefined)
  
    .value("DIO", hal::HAL_HandleEnum::DIO)
  
    .value("Port", hal::HAL_HandleEnum::Port)
  
    .value("Notifier", hal::HAL_HandleEnum::Notifier)
  
    .value("Interrupt", hal::HAL_HandleEnum::Interrupt)
  
    .value("AnalogOutput", hal::HAL_HandleEnum::AnalogOutput)
  
    .value("AnalogInput", hal::HAL_HandleEnum::AnalogInput)
  
    .value("AnalogTrigger", hal::HAL_HandleEnum::AnalogTrigger)
  
    .value("Relay", hal::HAL_HandleEnum::Relay)
  
    .value("PWM", hal::HAL_HandleEnum::PWM)
  
    .value("DigitalPWM", hal::HAL_HandleEnum::DigitalPWM)
  
    .value("Counter", hal::HAL_HandleEnum::Counter)
  
    .value("FPGAEncoder", hal::HAL_HandleEnum::FPGAEncoder)
  
    .value("Encoder", hal::HAL_HandleEnum::Encoder)
  
    .value("Compressor", hal::HAL_HandleEnum::Compressor)
  
    .value("Solenoid", hal::HAL_HandleEnum::Solenoid)
  
    .value("AnalogGyro", hal::HAL_HandleEnum::AnalogGyro)
  
    .value("Vendor", hal::HAL_HandleEnum::Vendor)
  
    .value("SimulationJni", hal::HAL_HandleEnum::SimulationJni)
  
    .value("CAN", hal::HAL_HandleEnum::CAN)
  
    .value("SerialPort", hal::HAL_HandleEnum::SerialPort)
  
    .value("DutyCycle", hal::HAL_HandleEnum::DutyCycle)
  
    .value("DMA", hal::HAL_HandleEnum::DMA)
  
    .value("AddressableLED", hal::HAL_HandleEnum::AddressableLED)
  
    .value("CTREPCM", hal::HAL_HandleEnum::CTREPCM)
  
    .value("CTREPDP", hal::HAL_HandleEnum::CTREPDP)
  
    .value("REVPDH", hal::HAL_HandleEnum::REVPDH)
  
    .value("REVPH", hal::HAL_HandleEnum::REVPH)
  ;

    

    
  }

void finish() {







m
  .
def
("getHandleIndex", &hal::getHandleIndex,
      py::arg("handle"), release_gil(), py::doc(
    "Get the handle index from a handle.\n"
"\n"
":param handle: the handle\n"
"\n"
":returns: the index")
  )
  
  ;
m
  .
def
("getHandleType", &hal::getHandleType,
      py::arg("handle"), release_gil(), py::doc(
    "Get the handle type from a handle.\n"
"\n"
":param handle: the handle\n"
"\n"
":returns: the type")
  )
  
  ;
m
  .
def
("isHandleType", &hal::isHandleType,
      py::arg("handle"), py::arg("handleType"), release_gil(), py::doc(
    "Get if the handle is a specific type.\n"
"\n"
":param handle:     the handle\n"
":param handleType: the type to check\n"
"\n"
":returns: true if the type is correct, otherwise false")
  )
  
  ;
m
  .
def
("isHandleCorrectVersion", &hal::isHandleCorrectVersion,
      py::arg("handle"), py::arg("version"), release_gil(), py::doc(
    "Get if the version of the handle is correct.\n"
"\n"
"Do not use on the roboRIO, used specifically for the sim to handle resets.\n"
"\n"
":param handle:  the handle\n"
":param version: the handle version to check\n"
"\n"
":returns: true if the handle is the right version, otherwise false")
  )
  
  ;
m
  .
def
("getHandleTypedIndex", &hal::getHandleTypedIndex,
      py::arg("handle"), py::arg("enumType"), py::arg("version"), release_gil(), py::doc(
    "Get if the handle is a correct type and version.\n"
"\n"
"Note the version is not checked on the roboRIO.\n"
"\n"
":param handle:   the handle\n"
":param enumType: the type to check\n"
":param version:  the handle version to check\n"
"\n"
":returns: true if the handle is proper version and type, otherwise\n"
"          false.")
  )
  
  ;
m
  .
def
("getPortHandleChannel", &hal::getPortHandleChannel,
      py::arg("handle"), release_gil(), py::doc(
    "Gets the port channel of a port handle.\n"
"\n"
":param handle: the port handle\n"
"\n"
":returns: the port channel")
  )
  
  ;
m
  .
def
("getPortHandleModule", &hal::getPortHandleModule,
      py::arg("handle"), release_gil(), py::doc(
    "Gets the port module of a port handle.\n"
"\n"
":param handle: the port handle\n"
"\n"
":returns: the port module")
  )
  
  ;
m
  .
def
("getPortHandleSPIEnable", &hal::getPortHandleSPIEnable,
      py::arg("handle"), release_gil(), py::doc(
    "Gets the SPI channel of a port handle.\n"
"\n"
":param handle: the port handle\n"
"\n"
":returns: the port SPI channel")
  )
  
  ;
m
  .
def
("createPortHandle", &hal::createPortHandle,
      py::arg("channel"), py::arg("module"), release_gil(), py::doc(
    "Create a port handle.\n"
"\n"
":param channel: the channel\n"
":param module:  the module\n"
"\n"
":returns: port handle for the module and channel")
  )
  
  ;
m
  .
def
("createPortHandleForSPI", &hal::createPortHandleForSPI,
      py::arg("channel"), release_gil(), py::doc(
    "Create a port handle for SPI.\n"
"\n"
":param channel: the SPI channel\n"
"\n"
":returns: port handle for the channel")
  )
  
  ;
m
  .
def
("createHandle", &hal::createHandle,
      py::arg("index"), py::arg("handleType"), py::arg("version"), release_gil(), py::doc(
    "Create a handle for a specific index, type and version.\n"
"\n"
"Note the version is not checked on the roboRIO.\n"
"\n"
":param index:      the index\n"
":param handleType: the handle type\n"
":param version:    the handle version\n"
"\n"
":returns: the created handle")
  )
  
  ;



}

}; // struct rpybuild_HandlesInternal_initializer

static std::unique_ptr<rpybuild_HandlesInternal_initializer> cls;

void begin_init_HandlesInternal(py::module &m) {
  cls = std::make_unique<rpybuild_HandlesInternal_initializer>(m);
}

void finish_init_HandlesInternal() {
  cls->finish();
  cls.reset();
}