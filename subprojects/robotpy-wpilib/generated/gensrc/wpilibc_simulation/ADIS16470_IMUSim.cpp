
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/simulation/ADIS16470_IMUSim.h>


#include <units_acceleration_type_caster.h>

#include <units_angle_type_caster.h>

#include <units_angular_velocity_type_caster.h>













#include <frc/ADIS16470_IMU.h>



#include <type_traits>


  using namespace frc;

  using namespace frc::sim;





struct rpybuild_ADIS16470_IMUSim_initializer {


  

  












  py::class_<typename frc::sim::ADIS16470_IMUSim> cls_ADIS16470_IMUSim;

    

    
    

  py::module &m;

  
  rpybuild_ADIS16470_IMUSim_initializer(py::module &m) :

  

  

  

  
    cls_ADIS16470_IMUSim(m, "ADIS16470_IMUSim"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_ADIS16470_IMUSim.doc() =
    "Class to control a simulated ADIS16470 IMU.";

  cls_ADIS16470_IMUSim
  
    
  .def(py::init<const ADIS16470_IMU&>(),
      py::arg("imu"), release_gil()
    , py::keep_alive<1, 2>(), py::doc(
    "Constructs from a ADIS16470_IMU object.\n"
"\n"
":param imu: ADIS16470_IMU to simulate")
  )
  
  
  
    
  .
def
("setGyroAngleX", &frc::sim::ADIS16470_IMUSim::SetGyroAngleX,
      py::arg("angle"), release_gil(), py::doc(
    "Sets the X axis angle (CCW positive).\n"
"\n"
":param angle: The angle.")
  )
  
  
  
    
  .
def
("setGyroAngleY", &frc::sim::ADIS16470_IMUSim::SetGyroAngleY,
      py::arg("angle"), release_gil(), py::doc(
    "Sets the Y axis angle (CCW positive).\n"
"\n"
":param angle: The angle.")
  )
  
  
  
    
  .
def
("setGyroAngleZ", &frc::sim::ADIS16470_IMUSim::SetGyroAngleZ,
      py::arg("angle"), release_gil(), py::doc(
    "Sets the Z axis angle (CCW positive).\n"
"\n"
":param angle: The angle.")
  )
  
  
  
    
  .
def
("setGyroRateX", &frc::sim::ADIS16470_IMUSim::SetGyroRateX,
      py::arg("angularRate"), release_gil(), py::doc(
    "Sets the X axis angular rate (CCW positive).\n"
"\n"
":param angularRate: The angular rate.")
  )
  
  
  
    
  .
def
("setGyroRateY", &frc::sim::ADIS16470_IMUSim::SetGyroRateY,
      py::arg("angularRate"), release_gil(), py::doc(
    "Sets the Y axis angular rate (CCW positive).\n"
"\n"
":param angularRate: The angular rate.")
  )
  
  
  
    
  .
def
("setGyroRateZ", &frc::sim::ADIS16470_IMUSim::SetGyroRateZ,
      py::arg("angularRate"), release_gil(), py::doc(
    "Sets the Z axis angular rate (CCW positive).\n"
"\n"
":param angularRate: The angular rate.")
  )
  
  
  
    
  .
def
("setAccelX", &frc::sim::ADIS16470_IMUSim::SetAccelX,
      py::arg("accel"), release_gil(), py::doc(
    "Sets the X axis acceleration.\n"
"\n"
":param accel: The acceleration.")
  )
  
  
  
    
  .
def
("setAccelY", &frc::sim::ADIS16470_IMUSim::SetAccelY,
      py::arg("accel"), release_gil(), py::doc(
    "Sets the Y axis acceleration.\n"
"\n"
":param accel: The acceleration.")
  )
  
  
  
    
  .
def
("setAccelZ", &frc::sim::ADIS16470_IMUSim::SetAccelZ,
      py::arg("accel"), release_gil(), py::doc(
    "Sets the Z axis acceleration.\n"
"\n"
":param accel: The acceleration.")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_ADIS16470_IMUSim_initializer

static std::unique_ptr<rpybuild_ADIS16470_IMUSim_initializer> cls;

void begin_init_ADIS16470_IMUSim(py::module &m) {
  cls = std::make_unique<rpybuild_ADIS16470_IMUSim_initializer>(m);
}

void finish_init_ADIS16470_IMUSim() {
  cls->finish();
  cls.reset();
}