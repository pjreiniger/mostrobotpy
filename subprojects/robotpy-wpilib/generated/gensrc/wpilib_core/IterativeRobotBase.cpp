
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/IterativeRobotBase.h>


#include <units_time_type_caster.h>







#define RPYGEN_ENABLE_frc__IterativeRobotBase_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__IterativeRobotBase.hpp>









#include <type_traits>


  using namespace frc;





struct rpybuild_IterativeRobotBase_initializer {


  

  












  
  using IterativeRobotBase_Trampoline = rpygen::PyTrampoline_frc__IterativeRobotBase<typename frc::IterativeRobotBase, typename rpygen::PyTrampolineCfg_frc__IterativeRobotBase<>>;
    static_assert(std::is_abstract<IterativeRobotBase_Trampoline>::value == false, "frc::IterativeRobotBase " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::IterativeRobotBase, IterativeRobotBase_Trampoline, frc::RobotBase> cls_IterativeRobotBase;

    

    
    

  py::module &m;

  
  rpybuild_IterativeRobotBase_initializer(py::module &m) :

  

  

  

  
    cls_IterativeRobotBase(m, "IterativeRobotBase"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_IterativeRobotBase.doc() =
    "IterativeRobotBase implements a specific type of robot program framework,\n"
"extending the RobotBase class.\n"
"\n"
"The IterativeRobotBase class does not implement StartCompetition(), so it\n"
"should not be used by teams directly.\n"
"\n"
"This class provides the following functions which are called by the main\n"
"loop, StartCompetition(), at the appropriate times:\n"
"\n"
"RobotInit() -- provide for initialization at robot power-on\n"
"\n"
"Init() functions -- each of the following functions is called once when the\n"
"appropriate mode is entered:\n"
"\n"
"- DisabledInit() -- called each and every time disabled is entered from another mode\n"
"- AutonomousInit() -- called each and every time autonomous is entered from another mode\n"
"- TeleopInit() -- called each and every time teleop is entered from another mode\n"
"- TestInit() -- called each and every time test is entered from another mode\n"
"\n"
"Periodic() functions -- each of these functions is called on an interval:\n"
"\n"
"- RobotPeriodic()\n"
"- DisabledPeriodic()\n"
"- AutonomousPeriodic()\n"
"- TeleopPeriodic()\n"
"- TestPeriodic()\n"
"\n"
"Exit() functions -- each of the following functions is called once when the\n"
"appropriate mode is exited:\n"
"\n"
"- DisabledExit() -- called each and every time disabled is exited\n"
"- AutonomousExit() -- called each and every time autonomous is exited\n"
"- TeleopExit() -- called each and every time teleop is exited\n"
"- TestExit() -- called each and every time test is exited\n";

  cls_IterativeRobotBase
  
    
  .
def
("robotInit", &frc::IterativeRobotBase::RobotInit, release_gil(), py::doc(
    "Robot-wide initialization code should go here.\n"
"\n"
"Users should override this method for default Robot-wide initialization\n"
"which will be called when the robot is first powered on. It will be called\n"
"exactly one time.\n"
"\n"
"Warning: the Driver Station \"Robot Code\" light and FMS \"Robot Ready\"\n"
"indicators will be off until RobotInit() exits. Code in RobotInit() that\n"
"waits for enable will cause the robot to never indicate that the code is\n"
"ready, causing the robot to be bypassed in a match.")
  )
  
  
  
    
  .
def
("driverStationConnected", &frc::IterativeRobotBase::DriverStationConnected, release_gil(), py::doc(
    "Code that needs to know the DS state should go here.\n"
"\n"
"Users should override this method for initialization that needs to occur\n"
"after the DS is connected, such as needing the alliance information.")
  )
  
  
  
    
  .
def
("_simulationInit", &frc::IterativeRobotBase::SimulationInit, release_gil(), py::doc(
    "Robot-wide simulation initialization code should go here.\n"
"\n"
"Users should override this method for default Robot-wide simulation\n"
"related initialization which will be called when the robot is first\n"
"started. It will be called exactly one time after RobotInit is called\n"
"only when the robot is in simulation.")
  )
  
  
  
    
  .
def
("disabledInit", &frc::IterativeRobotBase::DisabledInit, release_gil(), py::doc(
    "Initialization code for disabled mode should go here.\n"
"\n"
"Users should override this method for initialization code which will be\n"
"called each time\n"
"the robot enters disabled mode.")
  )
  
  
  
    
  .
def
("autonomousInit", &frc::IterativeRobotBase::AutonomousInit, release_gil(), py::doc(
    "Initialization code for autonomous mode should go here.\n"
"\n"
"Users should override this method for initialization code which will be\n"
"called each time the robot enters autonomous mode.")
  )
  
  
  
    
  .
def
("teleopInit", &frc::IterativeRobotBase::TeleopInit, release_gil(), py::doc(
    "Initialization code for teleop mode should go here.\n"
"\n"
"Users should override this method for initialization code which will be\n"
"called each time the robot enters teleop mode.")
  )
  
  
  
    
  .
def
("testInit", &frc::IterativeRobotBase::TestInit, release_gil(), py::doc(
    "Initialization code for test mode should go here.\n"
"\n"
"Users should override this method for initialization code which will be\n"
"called each time the robot enters test mode.")
  )
  
  
  
    
  .
def
("robotPeriodic", &frc::IterativeRobotBase::RobotPeriodic, release_gil(), py::doc(
    "Periodic code for all modes should go here.\n"
"\n"
"This function is called each time a new packet is received from the driver\n"
"station.")
  )
  
  
  
    
  .
def
("_simulationPeriodic", &frc::IterativeRobotBase::SimulationPeriodic, release_gil(), py::doc(
    "Periodic simulation code should go here.\n"
"\n"
"This function is called in a simulated robot after user code executes.")
  )
  
  
  
    
  .
def
("disabledPeriodic", &frc::IterativeRobotBase::DisabledPeriodic, release_gil(), py::doc(
    "Periodic code for disabled mode should go here.\n"
"\n"
"Users should override this method for code which will be called each time a\n"
"new packet is received from the driver station and the robot is in disabled\n"
"mode.")
  )
  
  
  
    
  .
def
("autonomousPeriodic", &frc::IterativeRobotBase::AutonomousPeriodic, release_gil(), py::doc(
    "Periodic code for autonomous mode should go here.\n"
"\n"
"Users should override this method for code which will be called each time a\n"
"new packet is received from the driver station and the robot is in\n"
"autonomous mode.")
  )
  
  
  
    
  .
def
("teleopPeriodic", &frc::IterativeRobotBase::TeleopPeriodic, release_gil(), py::doc(
    "Periodic code for teleop mode should go here.\n"
"\n"
"Users should override this method for code which will be called each time a\n"
"new packet is received from the driver station and the robot is in teleop\n"
"mode.")
  )
  
  
  
    
  .
def
("testPeriodic", &frc::IterativeRobotBase::TestPeriodic, release_gil(), py::doc(
    "Periodic code for test mode should go here.\n"
"\n"
"Users should override this method for code which will be called each time a\n"
"new packet is received from the driver station and the robot is in test\n"
"mode.")
  )
  
  
  
    
  .
def
("disabledExit", &frc::IterativeRobotBase::DisabledExit, release_gil(), py::doc(
    "Exit code for disabled mode should go here.\n"
"\n"
"Users should override this method for code which will be called each time\n"
"the robot exits disabled mode.")
  )
  
  
  
    
  .
def
("autonomousExit", &frc::IterativeRobotBase::AutonomousExit, release_gil(), py::doc(
    "Exit code for autonomous mode should go here.\n"
"\n"
"Users should override this method for code which will be called each time\n"
"the robot exits autonomous mode.")
  )
  
  
  
    
  .
def
("teleopExit", &frc::IterativeRobotBase::TeleopExit, release_gil(), py::doc(
    "Exit code for teleop mode should go here.\n"
"\n"
"Users should override this method for code which will be called each time\n"
"the robot exits teleop mode.")
  )
  
  
  
    
  .
def
("testExit", &frc::IterativeRobotBase::TestExit, release_gil(), py::doc(
    "Exit code for test mode should go here.\n"
"\n"
"Users should override this method for code which will be called each time\n"
"the robot exits test mode.")
  )
  
  
  
    
  .
def
("setNetworkTablesFlushEnabled", &frc::IterativeRobotBase::SetNetworkTablesFlushEnabled,
      py::arg("enabled"), release_gil(), py::doc(
    "Enables or disables flushing NetworkTables every loop iteration.\n"
"By default, this is enabled.\n"
"\n"
":param enabled: True to enable, false to disable")
  )
  
  
  
    
  .
def
("enableLiveWindowInTest", &frc::IterativeRobotBase::EnableLiveWindowInTest,
      py::arg("testLW"), release_gil(), py::doc(
    "Sets whether LiveWindow operation is enabled during test mode.\n"
"\n"
":param testLW: True to enable, false to disable. Defaults to false.\n"
"               @throws if called in test mode.")
  )
  
  
  
    
  .
def
("isLiveWindowEnabledInTest", &frc::IterativeRobotBase::IsLiveWindowEnabledInTest, release_gil(), py::doc(
    "Whether LiveWindow operation is enabled during test mode.")
  )
  
  
  
    
  .
def
("getPeriod", &frc::IterativeRobotBase::GetPeriod, release_gil(), py::doc(
    "Gets time period between calls to Periodic() functions.")
  )
  
  
  
    
  .def(py::init<units::second_t>(),
      py::arg("period"), release_gil(), py::doc(
    "Constructor for IterativeRobotBase.\n"
"\n"
":param period: Period.")
  )
  
  
  
    
  .
def
("_loopFunc", static_cast<void(frc::IterativeRobotBase::*)()>(&IterativeRobotBase_Trampoline::LoopFunc), release_gil(), py::doc(
    "Loop function.")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_IterativeRobotBase_initializer

static std::unique_ptr<rpybuild_IterativeRobotBase_initializer> cls;

void begin_init_IterativeRobotBase(py::module &m) {
  cls = std::make_unique<rpybuild_IterativeRobotBase_initializer>(m);
}

void finish_init_IterativeRobotBase() {
  cls->finish();
  cls.reset();
}