
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <hal/LEDs.h>
















#include <type_traits>






struct rpybuild_LEDs_initializer {







  
  py::enum_<::HAL_RadioLEDState> enum1;







  py::module &m;

  
  rpybuild_LEDs_initializer(py::module &m) :

  

  
    enum1
  (m, "HAL_RadioLEDState"
  ),
  

  

  

    m(m)
  {
    
    
      enum1
  
    .value("HAL_RadioLED_kOff", ::HAL_RadioLEDState::HAL_RadioLED_kOff)
  
    .value("HAL_RadioLED_kGreen", ::HAL_RadioLEDState::HAL_RadioLED_kGreen)
  
    .value("HAL_RadioLED_kRed", ::HAL_RadioLEDState::HAL_RadioLED_kRed)
  
    .value("HAL_RadioLED_kOrange", ::HAL_RadioLEDState::HAL_RadioLED_kOrange)
  ;

    

    
  }

void finish() {







m
  .
def
("HAL_SetRadioLEDState", [](HAL_RadioLEDState state) {
                    int32_t status;
          ::HAL_SetRadioLEDState(std::move(state), &status);
          return status;
        },
      py::arg("state"), release_gil(), py::doc(
    "Set the state of the \"Radio\" LED.\n"
"\n"
":param state: The state to set the LED to.\n"
":param out:   status the error code, or 0 for success")
  )
  
  ;
m
  .
def
("HAL_GetRadioLEDState", []() {
                    int32_t status;
          auto __ret =::HAL_GetRadioLEDState(&status);
          return std::make_tuple(__ret,status);
        }, release_gil(), py::doc(
    "Get the state of the \"Radio\" LED.\n"
"\n"
":param out: status the error code, or 0 for success\n"
"\n"
":returns: The state of the LED.")
  )
  
  ;



}

}; // struct rpybuild_LEDs_initializer

static std::unique_ptr<rpybuild_LEDs_initializer> cls;

void begin_init_LEDs(py::module &m) {
  cls = std::make_unique<rpybuild_LEDs_initializer>(m);
}

void finish_init_LEDs() {
  cls->finish();
  cls.reset();
}