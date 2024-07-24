
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/simulation/RoboRioSim.h>


#include <pybind11/functional.h>

#include <units_current_type_caster.h>

#include <units_temperature_type_caster.h>

#include <units_voltage_type_caster.h>















#include <type_traits>


  using namespace frc::sim;





struct rpybuild_RoboRioSim_initializer {


  

  












  py::class_<typename frc::sim::RoboRioSim> cls_RoboRioSim;

    

    
    

  py::module &m;

  
  rpybuild_RoboRioSim_initializer(py::module &m) :

  

  

  

  
    cls_RoboRioSim(m, "RoboRioSim"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_RoboRioSim.doc() =
    "A utility class to control a simulated RoboRIO.";

  cls_RoboRioSim
  
    .def(py::init<>(), release_gil())
  
    
  .
def_static
("registerFPGAButtonCallback", &frc::sim::RoboRioSim::RegisterFPGAButtonCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run when the FPGA button state changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to run the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getFPGAButton", &frc::sim::RoboRioSim::GetFPGAButton, release_gil(), py::doc(
    "Query the state of the FPGA button.\n"
"\n"
":returns: the FPGA button state")
  )
  
  
  
    
  .
def_static
("setFPGAButton", &frc::sim::RoboRioSim::SetFPGAButton,
      py::arg("fPGAButton"), release_gil(), py::doc(
    "Define the state of the FPGA button.\n"
"\n"
":param fPGAButton: the new state")
  )
  
  
  
    
  .
def_static
("registerVInVoltageCallback", &frc::sim::RoboRioSim::RegisterVInVoltageCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the Vin voltage changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to call the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getVInVoltage", &frc::sim::RoboRioSim::GetVInVoltage, release_gil(), py::doc(
    "Measure the Vin voltage.\n"
"\n"
":returns: the Vin voltage")
  )
  
  
  
    
  .
def_static
("setVInVoltage", &frc::sim::RoboRioSim::SetVInVoltage,
      py::arg("vInVoltage"), release_gil(), py::doc(
    "Define the Vin voltage.\n"
"\n"
":param vInVoltage: the new voltage")
  )
  
  
  
    
  .
def_static
("registerVInCurrentCallback", &frc::sim::RoboRioSim::RegisterVInCurrentCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the Vin current changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getVInCurrent", &frc::sim::RoboRioSim::GetVInCurrent, release_gil(), py::doc(
    "Measure the Vin current.\n"
"\n"
":returns: the Vin current")
  )
  
  
  
    
  .
def_static
("setVInCurrent", &frc::sim::RoboRioSim::SetVInCurrent,
      py::arg("vInCurrent"), release_gil(), py::doc(
    "Define the Vin current.\n"
"\n"
":param vInCurrent: the new current")
  )
  
  
  
    
  .
def_static
("registerUserVoltage6VCallback", &frc::sim::RoboRioSim::RegisterUserVoltage6VCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 6V rail voltage changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserVoltage6V", &frc::sim::RoboRioSim::GetUserVoltage6V, release_gil(), py::doc(
    "Measure the 6V rail voltage.\n"
"\n"
":returns: the 6V rail voltage")
  )
  
  
  
    
  .
def_static
("setUserVoltage6V", &frc::sim::RoboRioSim::SetUserVoltage6V,
      py::arg("userVoltage6V"), release_gil(), py::doc(
    "Define the 6V rail voltage.\n"
"\n"
":param userVoltage6V: the new voltage")
  )
  
  
  
    
  .
def_static
("registerUserCurrent6VCallback", &frc::sim::RoboRioSim::RegisterUserCurrent6VCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 6V rail current changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserCurrent6V", &frc::sim::RoboRioSim::GetUserCurrent6V, release_gil(), py::doc(
    "Measure the 6V rail current.\n"
"\n"
":returns: the 6V rail current")
  )
  
  
  
    
  .
def_static
("setUserCurrent6V", &frc::sim::RoboRioSim::SetUserCurrent6V,
      py::arg("userCurrent6V"), release_gil(), py::doc(
    "Define the 6V rail current.\n"
"\n"
":param userCurrent6V: the new current")
  )
  
  
  
    
  .
def_static
("registerUserActive6VCallback", &frc::sim::RoboRioSim::RegisterUserActive6VCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 6V rail active state changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserActive6V", &frc::sim::RoboRioSim::GetUserActive6V, release_gil(), py::doc(
    "Get the 6V rail active state.\n"
"\n"
":returns: true if the 6V rail is active")
  )
  
  
  
    
  .
def_static
("setUserActive6V", &frc::sim::RoboRioSim::SetUserActive6V,
      py::arg("userActive6V"), release_gil(), py::doc(
    "Set the 6V rail active state.\n"
"\n"
":param userActive6V: true to make rail active")
  )
  
  
  
    
  .
def_static
("registerUserVoltage5VCallback", &frc::sim::RoboRioSim::RegisterUserVoltage5VCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 5V rail voltage changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserVoltage5V", &frc::sim::RoboRioSim::GetUserVoltage5V, release_gil(), py::doc(
    "Measure the 5V rail voltage.\n"
"\n"
":returns: the 5V rail voltage")
  )
  
  
  
    
  .
def_static
("setUserVoltage5V", &frc::sim::RoboRioSim::SetUserVoltage5V,
      py::arg("userVoltage5V"), release_gil(), py::doc(
    "Define the 5V rail voltage.\n"
"\n"
":param userVoltage5V: the new voltage")
  )
  
  
  
    
  .
def_static
("registerUserCurrent5VCallback", &frc::sim::RoboRioSim::RegisterUserCurrent5VCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 5V rail current changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserCurrent5V", &frc::sim::RoboRioSim::GetUserCurrent5V, release_gil(), py::doc(
    "Measure the 5V rail current.\n"
"\n"
":returns: the 5V rail current")
  )
  
  
  
    
  .
def_static
("setUserCurrent5V", &frc::sim::RoboRioSim::SetUserCurrent5V,
      py::arg("userCurrent5V"), release_gil(), py::doc(
    "Define the 5V rail current.\n"
"\n"
":param userCurrent5V: the new current")
  )
  
  
  
    
  .
def_static
("registerUserActive5VCallback", &frc::sim::RoboRioSim::RegisterUserActive5VCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 5V rail active state changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserActive5V", &frc::sim::RoboRioSim::GetUserActive5V, release_gil(), py::doc(
    "Get the 5V rail active state.\n"
"\n"
":returns: true if the 5V rail is active")
  )
  
  
  
    
  .
def_static
("setUserActive5V", &frc::sim::RoboRioSim::SetUserActive5V,
      py::arg("userActive5V"), release_gil(), py::doc(
    "Set the 5V rail active state.\n"
"\n"
":param userActive5V: true to make rail active")
  )
  
  
  
    
  .
def_static
("registerUserVoltage3V3Callback", &frc::sim::RoboRioSim::RegisterUserVoltage3V3Callback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 3.3V rail voltage changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserVoltage3V3", &frc::sim::RoboRioSim::GetUserVoltage3V3, release_gil(), py::doc(
    "Measure the 3.3V rail voltage.\n"
"\n"
":returns: the 3.3V rail voltage")
  )
  
  
  
    
  .
def_static
("setUserVoltage3V3", &frc::sim::RoboRioSim::SetUserVoltage3V3,
      py::arg("userVoltage3V3"), release_gil(), py::doc(
    "Define the 3.3V rail voltage.\n"
"\n"
":param userVoltage3V3: the new voltage")
  )
  
  
  
    
  .
def_static
("registerUserCurrent3V3Callback", &frc::sim::RoboRioSim::RegisterUserCurrent3V3Callback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 3.3V rail current changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserCurrent3V3", &frc::sim::RoboRioSim::GetUserCurrent3V3, release_gil(), py::doc(
    "Measure the 3.3V rail current.\n"
"\n"
":returns: the 3.3V rail current")
  )
  
  
  
    
  .
def_static
("setUserCurrent3V3", &frc::sim::RoboRioSim::SetUserCurrent3V3,
      py::arg("userCurrent3V3"), release_gil(), py::doc(
    "Define the 3.3V rail current.\n"
"\n"
":param userCurrent3V3: the new current")
  )
  
  
  
    
  .
def_static
("registerUserActive3V3Callback", &frc::sim::RoboRioSim::RegisterUserActive3V3Callback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 3.3V rail active state changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserActive3V3", &frc::sim::RoboRioSim::GetUserActive3V3, release_gil(), py::doc(
    "Get the 3.3V rail active state.\n"
"\n"
":returns: true if the 3.3V rail is active")
  )
  
  
  
    
  .
def_static
("setUserActive3V3", &frc::sim::RoboRioSim::SetUserActive3V3,
      py::arg("userActive3V3"), release_gil(), py::doc(
    "Set the 3.3V rail active state.\n"
"\n"
":param userActive3V3: true to make rail active")
  )
  
  
  
    
  .
def_static
("registerUserFaults6VCallback", &frc::sim::RoboRioSim::RegisterUserFaults6VCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 6V rail number of faults\n"
"changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserFaults6V", &frc::sim::RoboRioSim::GetUserFaults6V, release_gil(), py::doc(
    "Get the 6V rail number of faults.\n"
"\n"
":returns: number of faults")
  )
  
  
  
    
  .
def_static
("setUserFaults6V", &frc::sim::RoboRioSim::SetUserFaults6V,
      py::arg("userFaults6V"), release_gil(), py::doc(
    "Set the 6V rail number of faults.\n"
"\n"
":param userFaults6V: number of faults")
  )
  
  
  
    
  .
def_static
("registerUserFaults5VCallback", &frc::sim::RoboRioSim::RegisterUserFaults5VCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 5V rail number of faults\n"
"changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserFaults5V", &frc::sim::RoboRioSim::GetUserFaults5V, release_gil(), py::doc(
    "Get the 5V rail number of faults.\n"
"\n"
":returns: number of faults")
  )
  
  
  
    
  .
def_static
("setUserFaults5V", &frc::sim::RoboRioSim::SetUserFaults5V,
      py::arg("userFaults5V"), release_gil(), py::doc(
    "Set the 5V rail number of faults.\n"
"\n"
":param userFaults5V: number of faults")
  )
  
  
  
    
  .
def_static
("registerUserFaults3V3Callback", &frc::sim::RoboRioSim::RegisterUserFaults3V3Callback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the 3.3V rail number of faults\n"
"changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getUserFaults3V3", &frc::sim::RoboRioSim::GetUserFaults3V3, release_gil(), py::doc(
    "Get the 3.3V rail number of faults.\n"
"\n"
":returns: number of faults")
  )
  
  
  
    
  .
def_static
("setUserFaults3V3", &frc::sim::RoboRioSim::SetUserFaults3V3,
      py::arg("userFaults3V3"), release_gil(), py::doc(
    "Set the 3.3V rail number of faults.\n"
"\n"
":param userFaults3V3: number of faults")
  )
  
  
  
    
  .
def_static
("registerBrownoutVoltageCallback", &frc::sim::RoboRioSim::RegisterBrownoutVoltageCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the brownout voltage changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to call the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getBrownoutVoltage", &frc::sim::RoboRioSim::GetBrownoutVoltage, release_gil(), py::doc(
    "Measure the brownout voltage.\n"
"\n"
":returns: the brownout voltage")
  )
  
  
  
    
  .
def_static
("setBrownoutVoltage", &frc::sim::RoboRioSim::SetBrownoutVoltage,
      py::arg("brownoutVoltage"), release_gil(), py::doc(
    "Define the brownout voltage.\n"
"\n"
":param brownoutVoltage: the new voltage")
  )
  
  
  
    
  .
def_static
("registerCPUTempCallback", &frc::sim::RoboRioSim::RegisterCPUTempCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the cpu temp changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to call the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getCPUTemp", &frc::sim::RoboRioSim::GetCPUTemp, release_gil(), py::doc(
    "Get the cpu temp.\n"
"\n"
":returns: the cpu temp.")
  )
  
  
  
    
  .
def_static
("setCPUTemp", &frc::sim::RoboRioSim::SetCPUTemp,
      py::arg("cpuTemp"), release_gil(), py::doc(
    "Define the cpu temp.\n"
"\n"
":param cpuTemp: the new cpu temp.")
  )
  
  
  
    
  .
def_static
("registerTeamNumberCallback", &frc::sim::RoboRioSim::RegisterTeamNumberCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the team number changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether to call the callback with the initial state\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getTeamNumber", &frc::sim::RoboRioSim::GetTeamNumber, release_gil(), py::doc(
    "Get the team number.\n"
"\n"
":returns: the team number.")
  )
  
  
  
    
  .
def_static
("setTeamNumber", &frc::sim::RoboRioSim::SetTeamNumber,
      py::arg("teamNumber"), release_gil(), py::doc(
    "Set the team number.\n"
"\n"
":param teamNumber: the new team number.")
  )
  
  
  
    
  .
def_static
("getSerialNumber", &frc::sim::RoboRioSim::GetSerialNumber, release_gil(), py::doc(
    "Get the serial number.\n"
"\n"
":returns: The serial number.")
  )
  
  
  
    
  .
def_static
("setSerialNumber", &frc::sim::RoboRioSim::SetSerialNumber,
      py::arg("serialNumber"), release_gil(), py::doc(
    "Set the serial number.\n"
"\n"
":param serialNumber: The serial number.")
  )
  
  
  
    
  .
def_static
("getComments", &frc::sim::RoboRioSim::GetComments, release_gil(), py::doc(
    "Get the comments.\n"
"\n"
":returns: The comments.")
  )
  
  
  
    
  .
def_static
("setComments", &frc::sim::RoboRioSim::SetComments,
      py::arg("comments"), release_gil(), py::doc(
    "Set the comments.\n"
"\n"
":param comments: The comments.")
  )
  
  
  
    
  .
def_static
("registerRadioLEDStateCallback", &frc::sim::RoboRioSim::RegisterRadioLEDStateCallback,
      py::arg("callback"), py::arg("initialNotify"), release_gil(), py::doc(
    "Register a callback to be run whenever the Radio led state changes.\n"
"\n"
":param callback:      the callback\n"
":param initialNotify: whether the callback should be called with the\n"
"                      initial value\n"
"\n"
":returns: the CallbackStore object associated with this callback")
  )
  
  
  
    
  .
def_static
("getRadioLEDState", &frc::sim::RoboRioSim::GetRadioLEDState, release_gil(), py::doc(
    "Get the state of the radio led.\n"
"\n"
":returns: The state of the radio led.")
  )
  
  
  
    
  .
def_static
("setRadioLEDState", &frc::sim::RoboRioSim::SetRadioLEDState,
      py::arg("state"), release_gil(), py::doc(
    "Set the state of the radio led.\n"
"\n"
":param state: The state of the radio led.")
  )
  
  
  
    
  .
def_static
("resetData", &frc::sim::RoboRioSim::ResetData, release_gil(), py::doc(
    "Reset all simulation data.")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_RoboRioSim_initializer

static std::unique_ptr<rpybuild_RoboRioSim_initializer> cls;

void begin_init_RoboRioSim(py::module &m) {
  cls = std::make_unique<rpybuild_RoboRioSim_initializer>(m);
}

void finish_init_RoboRioSim() {
  cls->finish();
  cls.reset();
}