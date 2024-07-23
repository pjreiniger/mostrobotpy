
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/ADXL345_SPI.h>








#define RPYGEN_ENABLE_frc__ADXL345_SPI_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__ADXL345_SPI.hpp>







#include <networktables/NTSendableBuilder.h>

#include <frc/DigitalSource.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_ADXL345_SPI_initializer {


  

  static constexpr auto kRange_2G = frc::ADXL345_SPI::Range::kRange_2G;
  












  
  using ADXL345_SPI_Trampoline = rpygen::PyTrampoline_frc__ADXL345_SPI<typename frc::ADXL345_SPI, typename rpygen::PyTrampolineCfg_frc__ADXL345_SPI<>>;
    static_assert(std::is_abstract<ADXL345_SPI_Trampoline>::value == false, "frc::ADXL345_SPI " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::ADXL345_SPI, ADXL345_SPI_Trampoline, nt::NTSendable> cls_ADXL345_SPI;

    
    
  py::enum_<frc::ADXL345_SPI::Range> cls_ADXL345_SPI_enum1;
    
    
  py::enum_<frc::ADXL345_SPI::Axes> cls_ADXL345_SPI_enum2;
    

    
    
    py::class_<typename frc::ADXL345_SPI::AllAxes> cls_AllAxes;

    

    
    
    

  py::module &m;

  
  rpybuild_ADXL345_SPI_initializer(py::module &m) :

  

  

  

  
    cls_ADXL345_SPI(m, "ADXL345_SPI"),

  
    cls_ADXL345_SPI_enum1
  (cls_ADXL345_SPI, "Range"
  ,
    "Accelerometer range."),
  
    cls_ADXL345_SPI_enum2
  (cls_ADXL345_SPI, "Axes"
  ,
    "Accelerometer axes."),
  

  
  
    cls_AllAxes(cls_ADXL345_SPI, "AllAxes"),

  

  
  
  
  

    m(m)
  {
    
    

    
    
  
    cls_ADXL345_SPI_enum1
  
    .value("kRange_2G", frc::ADXL345_SPI::Range::kRange_2G,
      "2 Gs max.")
  
    .value("kRange_4G", frc::ADXL345_SPI::Range::kRange_4G,
      "4 Gs max.")
  
    .value("kRange_8G", frc::ADXL345_SPI::Range::kRange_8G,
      "8 Gs max.")
  
    .value("kRange_16G", frc::ADXL345_SPI::Range::kRange_16G,
      "16 Gs max.")
  ;

  
    cls_ADXL345_SPI_enum2
  
    .value("kAxis_X", frc::ADXL345_SPI::Axes::kAxis_X,
      "X axis.")
  
    .value("kAxis_Y", frc::ADXL345_SPI::Axes::kAxis_Y,
      "Y axis.")
  
    .value("kAxis_Z", frc::ADXL345_SPI::Axes::kAxis_Z,
      "Z axis.")
  ;

  

    
    
  

    
    
  }

void finish() {





  {
  
  using AllAxes [[maybe_unused]] = typename frc::ADXL345_SPI::AllAxes;
  
  
  using Range [[maybe_unused]] = typename frc::ADXL345_SPI::Range;
  
  using Axes [[maybe_unused]] = typename frc::ADXL345_SPI::Axes;
  
  


  

  cls_ADXL345_SPI.doc() =
    "ADXL345 Accelerometer on SPI.\n"
"\n"
"This class allows access to an Analog Devices ADXL345 3-axis accelerometer\n"
"via SPI. This class assumes the sensor is wired in 4-wire SPI mode.";

  cls_ADXL345_SPI
  
    
  .def(py::init<SPI::Port, Range>(),
      py::arg("port"), py::arg("range") = kRange_2G, release_gil(), py::doc(
    "Constructor.\n"
"\n"
":param port:  The SPI port the accelerometer is attached to\n"
":param range: The range (+ or -) that the accelerometer will measure")
  )
  
  
  
    
  .
def
("getSpiPort", &frc::ADXL345_SPI::GetSpiPort, release_gil()
  )
  
  
  
    
  .
def
("setRange", &frc::ADXL345_SPI::SetRange,
      py::arg("range"), release_gil(), py::doc(
    "Set the measuring range of the accelerometer.\n"
"\n"
":param range: The maximum acceleration, positive or negative, that the\n"
"              accelerometer will measure.")
  )
  
  
  
    
  .
def
("getX", &frc::ADXL345_SPI::GetX, release_gil(), py::doc(
    "Returns the acceleration along the X axis in g-forces.\n"
"\n"
":returns: The acceleration along the X axis in g-forces.")
  )
  
  
  
    
  .
def
("getY", &frc::ADXL345_SPI::GetY, release_gil(), py::doc(
    "Returns the acceleration along the Y axis in g-forces.\n"
"\n"
":returns: The acceleration along the Y axis in g-forces.")
  )
  
  
  
    
  .
def
("getZ", &frc::ADXL345_SPI::GetZ, release_gil(), py::doc(
    "Returns the acceleration along the Z axis in g-forces.\n"
"\n"
":returns: The acceleration along the Z axis in g-forces.")
  )
  
  
  
    
  .
def
("getAcceleration", &frc::ADXL345_SPI::GetAcceleration,
      py::arg("axis"), release_gil(), py::doc(
    "Get the acceleration of one axis in Gs.\n"
"\n"
":param axis: The axis to read from.\n"
"\n"
":returns: Acceleration of the ADXL345 in Gs.")
  )
  
  
  
    
  .
def
("getAccelerations", &frc::ADXL345_SPI::GetAccelerations, release_gil(), py::doc(
    "Get the acceleration of all axes in Gs.\n"
"\n"
":returns: An object containing the acceleration measured on each axis of the\n"
"          ADXL345 in Gs.")
  )
  
  
  
    
  .
def
("initSendable", &frc::ADXL345_SPI::InitSendable,
      py::arg("builder"), release_gil()
  )
  
  
  ;

  


  

  cls_AllAxes.doc() =
    "Container type for accelerations from all axes.";

  cls_AllAxes
  
    .def(py::init<>(), release_gil())
  
    .def_readwrite("XAxis", &frc::ADXL345_SPI::AllAxes::XAxis, py::doc(
    "Acceleration along the X axis in g-forces."))
  
    .def_readwrite("YAxis", &frc::ADXL345_SPI::AllAxes::YAxis, py::doc(
    "Acceleration along the Y axis in g-forces."))
  
    .def_readwrite("ZAxis", &frc::ADXL345_SPI::AllAxes::ZAxis, py::doc(
    "Acceleration along the Z axis in g-forces."))
  ;

  


  
  }






}

}; // struct rpybuild_ADXL345_SPI_initializer

static std::unique_ptr<rpybuild_ADXL345_SPI_initializer> cls;

void begin_init_ADXL345_SPI(py::module &m) {
  cls = std::make_unique<rpybuild_ADXL345_SPI_initializer>(m);
}

void finish_init_ADXL345_SPI() {
  cls->finish();
  cls.reset();
}