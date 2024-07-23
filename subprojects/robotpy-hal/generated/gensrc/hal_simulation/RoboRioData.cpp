
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <hal/simulation/RoboRioData.h>
















#include <type_traits>






struct rpybuild_RoboRioData_initializer {













  py::module &m;

  
  rpybuild_RoboRioData_initializer(py::module &m) :

  

  

  

  

    m(m)
  {
    
    

    
  }

void finish() {







m
  .
def
("resetRoboRioData", &::HALSIM_ResetRoboRioData, release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioFPGAButtonCallback", &::HALSIM_CancelRoboRioFPGAButtonCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioFPGAButton", &::HALSIM_GetRoboRioFPGAButton, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioFPGAButton", &::HALSIM_SetRoboRioFPGAButton,
      py::arg("fPGAButton"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioVInVoltageCallback", &::HALSIM_CancelRoboRioVInVoltageCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioVInVoltage", &::HALSIM_GetRoboRioVInVoltage, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioVInVoltage", &::HALSIM_SetRoboRioVInVoltage,
      py::arg("vInVoltage"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioVInCurrentCallback", &::HALSIM_CancelRoboRioVInCurrentCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioVInCurrent", &::HALSIM_GetRoboRioVInCurrent, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioVInCurrent", &::HALSIM_SetRoboRioVInCurrent,
      py::arg("vInCurrent"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserVoltage6VCallback", &::HALSIM_CancelRoboRioUserVoltage6VCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserVoltage6V", &::HALSIM_GetRoboRioUserVoltage6V, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserVoltage6V", &::HALSIM_SetRoboRioUserVoltage6V,
      py::arg("userVoltage6V"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserCurrent6VCallback", &::HALSIM_CancelRoboRioUserCurrent6VCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserCurrent6V", &::HALSIM_GetRoboRioUserCurrent6V, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserCurrent6V", &::HALSIM_SetRoboRioUserCurrent6V,
      py::arg("userCurrent6V"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserActive6VCallback", &::HALSIM_CancelRoboRioUserActive6VCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserActive6V", &::HALSIM_GetRoboRioUserActive6V, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserActive6V", &::HALSIM_SetRoboRioUserActive6V,
      py::arg("userActive6V"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserVoltage5VCallback", &::HALSIM_CancelRoboRioUserVoltage5VCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserVoltage5V", &::HALSIM_GetRoboRioUserVoltage5V, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserVoltage5V", &::HALSIM_SetRoboRioUserVoltage5V,
      py::arg("userVoltage5V"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserCurrent5VCallback", &::HALSIM_CancelRoboRioUserCurrent5VCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserCurrent5V", &::HALSIM_GetRoboRioUserCurrent5V, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserCurrent5V", &::HALSIM_SetRoboRioUserCurrent5V,
      py::arg("userCurrent5V"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserActive5VCallback", &::HALSIM_CancelRoboRioUserActive5VCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserActive5V", &::HALSIM_GetRoboRioUserActive5V, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserActive5V", &::HALSIM_SetRoboRioUserActive5V,
      py::arg("userActive5V"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserVoltage3V3Callback", &::HALSIM_CancelRoboRioUserVoltage3V3Callback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserVoltage3V3", &::HALSIM_GetRoboRioUserVoltage3V3, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserVoltage3V3", &::HALSIM_SetRoboRioUserVoltage3V3,
      py::arg("userVoltage3V3"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserCurrent3V3Callback", &::HALSIM_CancelRoboRioUserCurrent3V3Callback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserCurrent3V3", &::HALSIM_GetRoboRioUserCurrent3V3, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserCurrent3V3", &::HALSIM_SetRoboRioUserCurrent3V3,
      py::arg("userCurrent3V3"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserActive3V3Callback", &::HALSIM_CancelRoboRioUserActive3V3Callback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserActive3V3", &::HALSIM_GetRoboRioUserActive3V3, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserActive3V3", &::HALSIM_SetRoboRioUserActive3V3,
      py::arg("userActive3V3"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserFaults6VCallback", &::HALSIM_CancelRoboRioUserFaults6VCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserFaults6V", &::HALSIM_GetRoboRioUserFaults6V, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserFaults6V", &::HALSIM_SetRoboRioUserFaults6V,
      py::arg("userFaults6V"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserFaults5VCallback", &::HALSIM_CancelRoboRioUserFaults5VCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserFaults5V", &::HALSIM_GetRoboRioUserFaults5V, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserFaults5V", &::HALSIM_SetRoboRioUserFaults5V,
      py::arg("userFaults5V"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioUserFaults3V3Callback", &::HALSIM_CancelRoboRioUserFaults3V3Callback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioUserFaults3V3", &::HALSIM_GetRoboRioUserFaults3V3, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioUserFaults3V3", &::HALSIM_SetRoboRioUserFaults3V3,
      py::arg("userFaults3V3"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioBrownoutVoltageCallback", &::HALSIM_CancelRoboRioBrownoutVoltageCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioBrownoutVoltage", &::HALSIM_GetRoboRioBrownoutVoltage, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioBrownoutVoltage", &::HALSIM_SetRoboRioBrownoutVoltage,
      py::arg("brownoutVoltage"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioTeamNumberCallback", &::HALSIM_CancelRoboRioTeamNumberCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioTeamNumber", &::HALSIM_GetRoboRioTeamNumber, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioTeamNumber", &::HALSIM_SetRoboRioTeamNumber,
      py::arg("teamNumber"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioSerialNumberCallback", &::HALSIM_CancelRoboRioSerialNumberCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioSerialNumber", [](size_t size) {
                    char buffer;
          auto __ret =::HALSIM_GetRoboRioSerialNumber(&buffer, std::move(size));
          return std::make_tuple(__ret,buffer);
        },
      py::arg("size"), release_gil()
  )
  
  ;
m
  .
def
("setRoboRioSerialNumber", &::HALSIM_SetRoboRioSerialNumber,
      py::arg("serialNumber"), py::arg("size"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioCommentsCallback", &::HALSIM_CancelRoboRioCommentsCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioComments", [](size_t size) {
                    char buffer;
          auto __ret =::HALSIM_GetRoboRioComments(&buffer, std::move(size));
          return std::make_tuple(__ret,buffer);
        },
      py::arg("size"), release_gil()
  )
  
  ;
m
  .
def
("setRoboRioComments", &::HALSIM_SetRoboRioComments,
      py::arg("comments"), py::arg("size"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioCPUTempCallback", &::HALSIM_CancelRoboRioCPUTempCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioCPUTemp", &::HALSIM_GetRoboRioCPUTemp, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioCPUTemp", &::HALSIM_SetRoboRioCPUTemp,
      py::arg("cpuTemp"), release_gil()
  )
  
  ;
m
  .
def
("cancelRoboRioRadioLEDStateCallback", &::HALSIM_CancelRoboRioRadioLEDStateCallback,
      py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getRoboRioRadioLEDState", &::HALSIM_GetRoboRioRadioLEDState, release_gil()
  )
  
  ;
m
  .
def
("setRoboRioRadioLEDState", &::HALSIM_SetRoboRioRadioLEDState,
      py::arg("state"), release_gil()
  )
  
  ;



}

}; // struct rpybuild_RoboRioData_initializer

static std::unique_ptr<rpybuild_RoboRioData_initializer> cls;

void begin_init_RoboRioData(py::module &m) {
  cls = std::make_unique<rpybuild_RoboRioData_initializer>(m);
}

void finish_init_RoboRioData() {
  cls->finish();
  cls.reset();
}