
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/simulation/XboxControllerSim.h>














#include <frc/XboxController.h>



#include <type_traits>


  using namespace frc;

  using namespace frc::sim;





struct rpybuild_XboxControllerSim_initializer {


  
    using XboxController = frc::XboxController;
  

  












  py::class_<typename frc::sim::XboxControllerSim, frc::sim::GenericHIDSim> cls_XboxControllerSim;

    

    
    

  py::module &m;

  
  rpybuild_XboxControllerSim_initializer(py::module &m) :

  

  

  

  
    cls_XboxControllerSim(m, "XboxControllerSim"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_XboxControllerSim.doc() =
    "Class to control a simulated Xbox 360 or Xbox One controller.";

  cls_XboxControllerSim
  
    
  .def(py::init<const XboxController&>(),
      py::arg("joystick"), release_gil()
    , py::keep_alive<1, 2>(), py::doc(
    "Constructs from a XboxController object.\n"
"\n"
":param joystick: controller to simulate")
  )
  
  
  
    
  .def(py::init<int>(),
      py::arg("port"), release_gil(), py::doc(
    "Constructs from a joystick port number.\n"
"\n"
":param port: port number")
  )
  
  
  
    
  .
def
("setLeftX", &frc::sim::XboxControllerSim::SetLeftX,
      py::arg("value"), release_gil(), py::doc(
    "Change the X axis value of the controller's left stick.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setRightX", &frc::sim::XboxControllerSim::SetRightX,
      py::arg("value"), release_gil(), py::doc(
    "Change the X axis value of the controller's right stick.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setLeftY", &frc::sim::XboxControllerSim::SetLeftY,
      py::arg("value"), release_gil(), py::doc(
    "Change the Y axis value of the controller's left stick.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setRightY", &frc::sim::XboxControllerSim::SetRightY,
      py::arg("value"), release_gil(), py::doc(
    "Change the Y axis value of the controller's right stick.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setLeftTriggerAxis", &frc::sim::XboxControllerSim::SetLeftTriggerAxis,
      py::arg("value"), release_gil(), py::doc(
    "Change the left trigger axis value of the joystick.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setRightTriggerAxis", &frc::sim::XboxControllerSim::SetRightTriggerAxis,
      py::arg("value"), release_gil(), py::doc(
    "Change the right trigger axis value of the joystick.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setLeftBumper", &frc::sim::XboxControllerSim::SetLeftBumper,
      py::arg("value"), release_gil(), py::doc(
    "Change the left bumper value of the joystick.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setRightBumper", &frc::sim::XboxControllerSim::SetRightBumper,
      py::arg("value"), release_gil(), py::doc(
    "Change the right bumper value of the joystick.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setLeftStickButton", &frc::sim::XboxControllerSim::SetLeftStickButton,
      py::arg("value"), release_gil(), py::doc(
    "Change the left button value of the joystick.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setRightStickButton", &frc::sim::XboxControllerSim::SetRightStickButton,
      py::arg("value"), release_gil(), py::doc(
    "Change the right button value of the joystick.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setAButton", &frc::sim::XboxControllerSim::SetAButton,
      py::arg("value"), release_gil(), py::doc(
    "Change the value of the A button.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setBButton", &frc::sim::XboxControllerSim::SetBButton,
      py::arg("value"), release_gil(), py::doc(
    "Change the value of the B button.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setXButton", &frc::sim::XboxControllerSim::SetXButton,
      py::arg("value"), release_gil(), py::doc(
    "Change the value of the X button.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setYButton", &frc::sim::XboxControllerSim::SetYButton,
      py::arg("value"), release_gil(), py::doc(
    "Change the value of the Y button.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setBackButton", &frc::sim::XboxControllerSim::SetBackButton,
      py::arg("value"), release_gil(), py::doc(
    "Change the value of the Back button.\n"
"\n"
":param value: the new value")
  )
  
  
  
    
  .
def
("setStartButton", &frc::sim::XboxControllerSim::SetStartButton,
      py::arg("value"), release_gil(), py::doc(
    "Change the value of the Start button.\n"
"\n"
":param value: the new value")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_XboxControllerSim_initializer

static std::unique_ptr<rpybuild_XboxControllerSim_initializer> cls;

void begin_init_XboxControllerSim(py::module &m) {
  cls = std::make_unique<rpybuild_XboxControllerSim_initializer>(m);
}

void finish_init_XboxControllerSim() {
  cls->finish();
  cls.reset();
}