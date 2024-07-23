
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <hal/simulation/AnalogTriggerData.h>
















#include <type_traits>






struct rpybuild_AnalogTriggerData_initializer {







  
  py::enum_<::HALSIM_AnalogTriggerMode> enum1;







  py::module &m;

  
  rpybuild_AnalogTriggerData_initializer(py::module &m) :

  

  
    enum1
  (m, "AnalogTriggerMode"
  ),
  

  

  

    m(m)
  {
    
    
      enum1
  
    .value("HALSIM_AnalogTriggerUnassigned", ::HALSIM_AnalogTriggerMode::HALSIM_AnalogTriggerUnassigned)
  
    .value("HALSIM_AnalogTriggerFiltered", ::HALSIM_AnalogTriggerMode::HALSIM_AnalogTriggerFiltered)
  
    .value("HALSIM_AnalogTriggerDutyCycle", ::HALSIM_AnalogTriggerMode::HALSIM_AnalogTriggerDutyCycle)
  
    .value("HALSIM_AnalogTriggerAveraged", ::HALSIM_AnalogTriggerMode::HALSIM_AnalogTriggerAveraged)
  ;

    

    
  }

void finish() {







m
  .
def
("findAnalogTriggerForChannel", &::HALSIM_FindAnalogTriggerForChannel,
      py::arg("channel"), release_gil()
  )
  
  ;
m
  .
def
("resetAnalogTriggerData", &::HALSIM_ResetAnalogTriggerData,
      py::arg("index"), release_gil()
  )
  
  ;
m
  .
def
("cancelAnalogTriggerInitializedCallback", &::HALSIM_CancelAnalogTriggerInitializedCallback,
      py::arg("index"), py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getAnalogTriggerInitialized", &::HALSIM_GetAnalogTriggerInitialized,
      py::arg("index"), release_gil()
  )
  
  ;
m
  .
def
("setAnalogTriggerInitialized", &::HALSIM_SetAnalogTriggerInitialized,
      py::arg("index"), py::arg("initialized"), release_gil()
  )
  
  ;
m
  .
def
("cancelAnalogTriggerTriggerLowerBoundCallback", &::HALSIM_CancelAnalogTriggerTriggerLowerBoundCallback,
      py::arg("index"), py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getAnalogTriggerTriggerLowerBound", &::HALSIM_GetAnalogTriggerTriggerLowerBound,
      py::arg("index"), release_gil()
  )
  
  ;
m
  .
def
("setAnalogTriggerTriggerLowerBound", &::HALSIM_SetAnalogTriggerTriggerLowerBound,
      py::arg("index"), py::arg("triggerLowerBound"), release_gil()
  )
  
  ;
m
  .
def
("cancelAnalogTriggerTriggerUpperBoundCallback", &::HALSIM_CancelAnalogTriggerTriggerUpperBoundCallback,
      py::arg("index"), py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getAnalogTriggerTriggerUpperBound", &::HALSIM_GetAnalogTriggerTriggerUpperBound,
      py::arg("index"), release_gil()
  )
  
  ;
m
  .
def
("setAnalogTriggerTriggerUpperBound", &::HALSIM_SetAnalogTriggerTriggerUpperBound,
      py::arg("index"), py::arg("triggerUpperBound"), release_gil()
  )
  
  ;
m
  .
def
("cancelAnalogTriggerTriggerModeCallback", &::HALSIM_CancelAnalogTriggerTriggerModeCallback,
      py::arg("index"), py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getAnalogTriggerTriggerMode", &::HALSIM_GetAnalogTriggerTriggerMode,
      py::arg("index"), release_gil()
  )
  
  ;
m
  .
def
("setAnalogTriggerTriggerMode", &::HALSIM_SetAnalogTriggerTriggerMode,
      py::arg("index"), py::arg("triggerMode"), release_gil()
  )
  
  ;



}

}; // struct rpybuild_AnalogTriggerData_initializer

static std::unique_ptr<rpybuild_AnalogTriggerData_initializer> cls;

void begin_init_AnalogTriggerData(py::module &m) {
  cls = std::make_unique<rpybuild_AnalogTriggerData_initializer>(m);
}

void finish_init_AnalogTriggerData() {
  cls->finish();
  cls.reset();
}