
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/simulation/JoystickSim.h>














#include <frc/Joystick.h>



#include <type_traits>


  using namespace frc;

  using namespace frc::sim;





struct rpybuild_JoystickSim_initializer {


  

  












  py::class_<typename frc::sim::JoystickSim, frc::sim::GenericHIDSim> cls_JoystickSim;

    

    
    

  py::module &m;

  
  rpybuild_JoystickSim_initializer(py::module &m) :

  

  

  

  
    cls_JoystickSim(m, "JoystickSim"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_JoystickSim.doc() =
    "Class to control a simulated joystick.";

  cls_JoystickSim
  
    
  .def(py::init<const Joystick&>(),
      py::arg("joystick"), release_gil()
    , py::keep_alive<1, 2>(), py::doc(
    "Constructs from a Joystick object.\n"
"\n"
":param joystick: joystick to simulate")
  )
  
  
  
    
  .def(py::init<int>(),
      py::arg("port"), release_gil(), py::doc(
    "Constructs from a joystick port number.\n"
"\n"
":param port: port number")
  )
  
  
  
    
  .
def
("setX", &frc::sim::JoystickSim::SetX,
      py::arg("value"), release_gil(), py::doc(
    "Set the X value of the joystick.\n"
"\n"
":param value: the new X value")
  )
  
  
  
    
  .
def
("setY", &frc::sim::JoystickSim::SetY,
      py::arg("value"), release_gil(), py::doc(
    "Set the Y value of the joystick.\n"
"\n"
":param value: the new Y value")
  )
  
  
  
    
  .
def
("setZ", &frc::sim::JoystickSim::SetZ,
      py::arg("value"), release_gil(), py::doc(
    "Set the Z value of the joystick.\n"
"\n"
":param value: the new Z value")
  )
  
  
  
    
  .
def
("setTwist", &frc::sim::JoystickSim::SetTwist,
      py::arg("value"), release_gil(), py::doc(
    "Set the twist value of the joystick.\n"
"\n"
":param value: the new twist value")
  )
  
  
  
    
  .
def
("setThrottle", &frc::sim::JoystickSim::SetThrottle,
      py::arg("value"), release_gil(), py::doc(
    "Set the throttle value of the joystick.\n"
"\n"
":param value: the new throttle value")
  )
  
  
  
    
  .
def
("setTrigger", &frc::sim::JoystickSim::SetTrigger,
      py::arg("state"), release_gil(), py::doc(
    "Set the trigger value of the joystick.\n"
"\n"
":param state: the new value")
  )
  
  
  
    
  .
def
("setTop", &frc::sim::JoystickSim::SetTop,
      py::arg("state"), release_gil(), py::doc(
    "Set the top state of the joystick.\n"
"\n"
":param state: the new state")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_JoystickSim_initializer

static std::unique_ptr<rpybuild_JoystickSim_initializer> cls;

void begin_init_JoystickSim(py::module &m) {
  cls = std::make_unique<rpybuild_JoystickSim_initializer>(m);
}

void finish_init_JoystickSim() {
  cls->finish();
  cls.reset();
}