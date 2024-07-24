
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/XboxController.h>








#define RPYGEN_ENABLE_frc__XboxController_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__XboxController.hpp>







#include <frc/DriverStation.h>

#include <frc/event/BooleanEvent.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_XboxController_initializer {


  

  












  
  using XboxController_Trampoline = rpygen::PyTrampoline_frc__XboxController<typename frc::XboxController, typename rpygen::PyTrampolineCfg_frc__XboxController<>>;
    static_assert(std::is_abstract<XboxController_Trampoline>::value == false, "frc::XboxController " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::XboxController, XboxController_Trampoline, frc::GenericHID> cls_XboxController;

    

    
    
    py::class_<typename frc::XboxController::Button> cls_Button;

    

    
    
    
    py::class_<typename frc::XboxController::Axis> cls_Axis;

    

    
    
    

  py::module &m;

  
  rpybuild_XboxController_initializer(py::module &m) :

  

  

  

  
    cls_XboxController(m, "XboxController"),

  

  
  
    cls_Button(cls_XboxController, "Button"),

  

  
  
  
    cls_Axis(cls_XboxController, "Axis"),

  

  
  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  

    
    
  

    
    
  }

void finish() {





  {
  
  using Button [[maybe_unused]] = typename frc::XboxController::Button;
  
  using Axis [[maybe_unused]] = typename frc::XboxController::Axis;
  
  
  


  

  cls_XboxController.doc() =
    "Handle input from Xbox 360 or Xbox One controllers connected to the Driver\n"
"Station.\n"
"\n"
"This class handles Xbox input that comes from the Driver Station. Each time a\n"
"value is requested the most recent value is returned. There is a single class\n"
"instance for each controller and the mapping of ports to hardware buttons\n"
"depends on the code in the Driver Station.\n"
"\n"
"Only first party controllers from Microsoft are guaranteed to have the\n"
"correct mapping, and only through the official NI DS. Sim is not guaranteed\n"
"to have the same mapping, as well as any 3rd party controllers.";

  cls_XboxController
  
    
  .def(py::init<int>(),
      py::arg("port"), release_gil(), py::doc(
    "Construct an instance of an Xbox controller.\n"
"\n"
"The controller index is the USB port on the Driver Station.\n"
"\n"
":param port: The port on the Driver Station that the controller is plugged\n"
"             into (0-5).")
  )
  
  
  
    
  .
def
("getLeftX", &frc::XboxController::GetLeftX, release_gil(), py::doc(
    "Get the X axis value of left side of the controller.\n"
"\n"
":returns: the axis value")
  )
  
  
  
    
  .
def
("getRightX", &frc::XboxController::GetRightX, release_gil(), py::doc(
    "Get the X axis value of right side of the controller.\n"
"\n"
":returns: the axis value")
  )
  
  
  
    
  .
def
("getLeftY", &frc::XboxController::GetLeftY, release_gil(), py::doc(
    "Get the Y axis value of left side of the controller.\n"
"\n"
":returns: the axis value")
  )
  
  
  
    
  .
def
("getRightY", &frc::XboxController::GetRightY, release_gil(), py::doc(
    "Get the Y axis value of right side of the controller.\n"
"\n"
":returns: the axis value")
  )
  
  
  
    
  .
def
("getLeftTriggerAxis", &frc::XboxController::GetLeftTriggerAxis, release_gil(), py::doc(
    "Get the left trigger (LT) axis value of the controller. Note that this axis\n"
"is bound to the range of [0, 1] as opposed to the usual [-1, 1].\n"
"\n"
":returns: the axis value")
  )
  
  
  
    
  .
def
("getRightTriggerAxis", &frc::XboxController::GetRightTriggerAxis, release_gil(), py::doc(
    "Get the right trigger (RT) axis value of the controller. Note that this\n"
"axis is bound to the range of [0, 1] as opposed to the usual [-1, 1].\n"
"\n"
":returns: the axis value")
  )
  
  
  
    
  .
def
("getLeftBumper", &frc::XboxController::GetLeftBumper, release_gil(), py::doc(
    "Read the value of the left bumper (LB) button on the controller.\n"
"\n"
":returns: the state of the button")
  )
  
  
  
    
  .
def
("getRightBumper", &frc::XboxController::GetRightBumper, release_gil(), py::doc(
    "Read the value of the right bumper (RB) button on the controller.\n"
"\n"
":returns: the state of the button")
  )
  
  
  
    
  .
def
("getLeftBumperPressed", &frc::XboxController::GetLeftBumperPressed, release_gil(), py::doc(
    "Whether the left bumper (LB) was pressed since the last check.\n"
"\n"
":returns: Whether the button was pressed since the last check")
  )
  
  
  
    
  .
def
("getRightBumperPressed", &frc::XboxController::GetRightBumperPressed, release_gil(), py::doc(
    "Whether the right bumper (RB) was pressed since the last check.\n"
"\n"
":returns: Whether the button was pressed since the last check")
  )
  
  
  
    
  .
def
("getLeftBumperReleased", &frc::XboxController::GetLeftBumperReleased, release_gil(), py::doc(
    "Whether the left bumper (LB) was released since the last check.\n"
"\n"
":returns: Whether the button was released since the last check.")
  )
  
  
  
    
  .
def
("getRightBumperReleased", &frc::XboxController::GetRightBumperReleased, release_gil(), py::doc(
    "Whether the right bumper (RB) was released since the last check.\n"
"\n"
":returns: Whether the button was released since the last check.")
  )
  
  
  
    
  .
def
("leftBumper", &frc::XboxController::LeftBumper,
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the left bumper's digital signal.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance representing the left bumper's digital signal\n"
"          attached to the given loop.")
  )
  
  
  
    
  .
def
("rightBumper", &frc::XboxController::RightBumper,
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the right bumper's digital signal.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance representing the right bumper's digital signal\n"
"          attached to the given loop.")
  )
  
  
  
    
  .
def
("getLeftStickButton", &frc::XboxController::GetLeftStickButton, release_gil(), py::doc(
    "Read the value of the left stick button (LSB) on the controller.\n"
"\n"
":returns: the state of the button")
  )
  
  
  
    
  .
def
("getRightStickButton", &frc::XboxController::GetRightStickButton, release_gil(), py::doc(
    "Read the value of the right stick button (RSB) on the controller.\n"
"\n"
":returns: the state of the button")
  )
  
  
  
    
  .
def
("getLeftStickButtonPressed", &frc::XboxController::GetLeftStickButtonPressed, release_gil(), py::doc(
    "Whether the left stick button (LSB) was pressed since the last check.\n"
"\n"
":returns: Whether the button was pressed since the last check.")
  )
  
  
  
    
  .
def
("getRightStickButtonPressed", &frc::XboxController::GetRightStickButtonPressed, release_gil(), py::doc(
    "Whether the right stick button (RSB) was pressed since the last check.\n"
"\n"
":returns: Whether the button was pressed since the last check")
  )
  
  
  
    
  .
def
("getLeftStickButtonReleased", &frc::XboxController::GetLeftStickButtonReleased, release_gil(), py::doc(
    "Whether the left stick button (LSB) was released since the last check.\n"
"\n"
":returns: Whether the button was released since the last check.")
  )
  
  
  
    
  .
def
("getRightStickButtonReleased", &frc::XboxController::GetRightStickButtonReleased, release_gil(), py::doc(
    "Whether the right stick button (RSB) was released since the last check.\n"
"\n"
":returns: Whether the button was released since the last check.")
  )
  
  
  
    
  .
def
("leftStick", &frc::XboxController::LeftStick,
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the left stick's digital signal.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance representing the left stick's digital signal\n"
"          attached to the given loop.")
  )
  
  
  
    
  .
def
("rightStick", &frc::XboxController::RightStick,
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the right stick's digital signal.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance representing the right stick's digital signal\n"
"          attached to the given loop.")
  )
  
  
  
    
  .
def
("getAButton", &frc::XboxController::GetAButton, release_gil(), py::doc(
    "Read the value of the A button on the controller.\n"
"\n"
":returns: The state of the button.")
  )
  
  
  
    
  .
def
("getAButtonPressed", &frc::XboxController::GetAButtonPressed, release_gil(), py::doc(
    "Whether the A button was pressed since the last check.\n"
"\n"
":returns: Whether the button was pressed since the last check.")
  )
  
  
  
    
  .
def
("getAButtonReleased", &frc::XboxController::GetAButtonReleased, release_gil(), py::doc(
    "Whether the A button was released since the last check.\n"
"\n"
":returns: Whether the button was released since the last check.")
  )
  
  
  
    
  .
def
("A", &frc::XboxController::A,
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the A button's digital signal.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance representing the A button's digital signal\n"
"          attached to the given loop.")
  )
  
  
  
    
  .
def
("getBButton", &frc::XboxController::GetBButton, release_gil(), py::doc(
    "Read the value of the B button on the controller.\n"
"\n"
":returns: The state of the button.")
  )
  
  
  
    
  .
def
("getBButtonPressed", &frc::XboxController::GetBButtonPressed, release_gil(), py::doc(
    "Whether the B button was pressed since the last check.\n"
"\n"
":returns: Whether the button was pressed since the last check.")
  )
  
  
  
    
  .
def
("getBButtonReleased", &frc::XboxController::GetBButtonReleased, release_gil(), py::doc(
    "Whether the B button was released since the last check.\n"
"\n"
":returns: Whether the button was released since the last check.")
  )
  
  
  
    
  .
def
("B", &frc::XboxController::B,
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the B button's digital signal.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance representing the B button's digital signal\n"
"          attached to the given loop.")
  )
  
  
  
    
  .
def
("getXButton", &frc::XboxController::GetXButton, release_gil(), py::doc(
    "Read the value of the X button on the controller.\n"
"\n"
":returns: The state of the button.")
  )
  
  
  
    
  .
def
("getXButtonPressed", &frc::XboxController::GetXButtonPressed, release_gil(), py::doc(
    "Whether the X button was pressed since the last check.\n"
"\n"
":returns: Whether the button was pressed since the last check.")
  )
  
  
  
    
  .
def
("getXButtonReleased", &frc::XboxController::GetXButtonReleased, release_gil(), py::doc(
    "Whether the X button was released since the last check.\n"
"\n"
":returns: Whether the button was released since the last check.")
  )
  
  
  
    
  .
def
("X", &frc::XboxController::X,
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the X button's digital signal.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance representing the X button's digital signal\n"
"          attached to the given loop.")
  )
  
  
  
    
  .
def
("getYButton", &frc::XboxController::GetYButton, release_gil(), py::doc(
    "Read the value of the Y button on the controller.\n"
"\n"
":returns: The state of the button.")
  )
  
  
  
    
  .
def
("getYButtonPressed", &frc::XboxController::GetYButtonPressed, release_gil(), py::doc(
    "Whether the Y button was pressed since the last check.\n"
"\n"
":returns: Whether the button was pressed since the last check.")
  )
  
  
  
    
  .
def
("getYButtonReleased", &frc::XboxController::GetYButtonReleased, release_gil(), py::doc(
    "Whether the Y button was released since the last check.\n"
"\n"
":returns: Whether the button was released since the last check.")
  )
  
  
  
    
  .
def
("Y", &frc::XboxController::Y,
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the Y button's digital signal.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance representing the Y button's digital signal\n"
"          attached to the given loop.")
  )
  
  
  
    
  .
def
("getBackButton", &frc::XboxController::GetBackButton, release_gil(), py::doc(
    "Read the value of the back button on the controller.\n"
"\n"
":returns: The state of the button.")
  )
  
  
  
    
  .
def
("getBackButtonPressed", &frc::XboxController::GetBackButtonPressed, release_gil(), py::doc(
    "Whether the back button was pressed since the last check.\n"
"\n"
":returns: Whether the button was pressed since the last check.")
  )
  
  
  
    
  .
def
("getBackButtonReleased", &frc::XboxController::GetBackButtonReleased, release_gil(), py::doc(
    "Whether the back button was released since the last check.\n"
"\n"
":returns: Whether the button was released since the last check.")
  )
  
  
  
    
  .
def
("back", &frc::XboxController::Back,
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the back button's digital signal.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance representing the back button's digital signal\n"
"          attached to the given loop.")
  )
  
  
  
    
  .
def
("getStartButton", &frc::XboxController::GetStartButton, release_gil(), py::doc(
    "Read the value of the start button on the controller.\n"
"\n"
":returns: The state of the button.")
  )
  
  
  
    
  .
def
("getStartButtonPressed", &frc::XboxController::GetStartButtonPressed, release_gil(), py::doc(
    "Whether the start button was pressed since the last check.\n"
"\n"
":returns: Whether the button was pressed since the last check.")
  )
  
  
  
    
  .
def
("getStartButtonReleased", &frc::XboxController::GetStartButtonReleased, release_gil(), py::doc(
    "Whether the start button was released since the last check.\n"
"\n"
":returns: Whether the button was released since the last check.")
  )
  
  
  
    
  .
def
("start", &frc::XboxController::Start,
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the start button's digital signal.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance representing the start button's digital signal\n"
"          attached to the given loop.")
  )
  
  
  
    
  .
def
("leftTrigger", static_cast<BooleanEvent(frc::XboxController::*)(double, EventLoop*) const>(
        &frc::XboxController::LeftTrigger),
      py::arg("threshold"), py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the axis value of the left trigger. The\n"
"returned trigger will be true when the axis value is greater than {@code\n"
"threshold}.\n"
"\n"
":param threshold: the minimum axis value for the returned event to be true.\n"
"                  This value should be in the range [0, 1] where 0 is the unpressed state of\n"
"                  the axis.\n"
":param loop:      the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance that is true when the left trigger's axis exceeds\n"
"          the provided threshold, attached to the given event loop")
  )
  
  
  
    
  .
def
("leftTrigger", static_cast<BooleanEvent(frc::XboxController::*)(EventLoop*) const>(
        &frc::XboxController::LeftTrigger),
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the axis value of the left trigger.\n"
"The returned trigger will be true when the axis value is greater than 0.5.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance that is true when the left trigger's axis\n"
"          exceeds 0.5, attached to the given event loop")
  )
  
  
  
    
  .
def
("rightTrigger", static_cast<BooleanEvent(frc::XboxController::*)(double, EventLoop*) const>(
        &frc::XboxController::RightTrigger),
      py::arg("threshold"), py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the axis value of the right trigger.\n"
"The returned trigger will be true when the axis value is greater than\n"
"``threshold``.\n"
"\n"
":param threshold: the minimum axis value for the returned event to be true.\n"
"                  This value should be in the range [0, 1] where 0 is the unpressed state of\n"
"                  the axis.\n"
":param loop:      the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance that is true when the right trigger's axis\n"
"          exceeds the provided threshold, attached to the given event loop")
  )
  
  
  
    
  .
def
("rightTrigger", static_cast<BooleanEvent(frc::XboxController::*)(EventLoop*) const>(
        &frc::XboxController::RightTrigger),
      py::arg("loop"), release_gil(), py::doc(
    "Constructs an event instance around the axis value of the right trigger.\n"
"The returned trigger will be true when the axis value is greater than 0.5.\n"
"\n"
":param loop: the event loop instance to attach the event to.\n"
"\n"
":returns: an event instance that is true when the right trigger's axis\n"
"          exceeds 0.5, attached to the given event loop")
  )
  
  
  ;

  


  

  cls_Button.doc() =
    "Represents a digital button on an XboxController.";

  cls_Button
  
    .def(py::init<>(), release_gil())
  
    .def_readonly_static("kLeftBumper", &frc::XboxController::Button::kLeftBumper, py::doc(
    "Left bumper."))
  
    .def_readonly_static("kRightBumper", &frc::XboxController::Button::kRightBumper, py::doc(
    "Right bumper."))
  
    .def_readonly_static("kLeftStick", &frc::XboxController::Button::kLeftStick, py::doc(
    "Left stick."))
  
    .def_readonly_static("kRightStick", &frc::XboxController::Button::kRightStick, py::doc(
    "Right stick."))
  
    .def_readonly_static("kA", &frc::XboxController::Button::kA, py::doc(
    "A."))
  
    .def_readonly_static("kB", &frc::XboxController::Button::kB, py::doc(
    "B."))
  
    .def_readonly_static("kX", &frc::XboxController::Button::kX, py::doc(
    "X."))
  
    .def_readonly_static("kY", &frc::XboxController::Button::kY, py::doc(
    "Y."))
  
    .def_readonly_static("kBack", &frc::XboxController::Button::kBack, py::doc(
    "Back."))
  
    .def_readonly_static("kStart", &frc::XboxController::Button::kStart, py::doc(
    "Start."))
  ;

  


  
  

  cls_Axis.doc() =
    "Represents an axis on an XboxController.";

  cls_Axis
  
    .def(py::init<>(), release_gil())
  
    .def_readonly_static("kLeftX", &frc::XboxController::Axis::kLeftX, py::doc(
    "Left X."))
  
    .def_readonly_static("kRightX", &frc::XboxController::Axis::kRightX, py::doc(
    "Right X."))
  
    .def_readonly_static("kLeftY", &frc::XboxController::Axis::kLeftY, py::doc(
    "Left Y."))
  
    .def_readonly_static("kRightY", &frc::XboxController::Axis::kRightY, py::doc(
    "Right Y."))
  
    .def_readonly_static("kLeftTrigger", &frc::XboxController::Axis::kLeftTrigger, py::doc(
    "Left trigger."))
  
    .def_readonly_static("kRightTrigger", &frc::XboxController::Axis::kRightTrigger, py::doc(
    "Right trigger."))
  ;

  


  
  }






}

}; // struct rpybuild_XboxController_initializer

static std::unique_ptr<rpybuild_XboxController_initializer> cls;

void begin_init_XboxController(py::module &m) {
  cls = std::make_unique<rpybuild_XboxController_initializer>(m);
}

void finish_init_XboxController() {
  cls->finish();
  cls.reset();
}