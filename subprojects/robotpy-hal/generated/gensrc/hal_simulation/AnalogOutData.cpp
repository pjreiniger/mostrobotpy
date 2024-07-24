
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <hal/simulation/AnalogOutData.h>
















#include <type_traits>






struct rpybuild_AnalogOutData_initializer {













  py::module &m;

  
  rpybuild_AnalogOutData_initializer(py::module &m) :

  

  

  

  

    m(m)
  {
    
    

    
  }

void finish() {







m
  .
def
("resetAnalogOutData", &::HALSIM_ResetAnalogOutData,
      py::arg("index"), release_gil()
  )
  
  ;
m
  .
def
("cancelAnalogOutVoltageCallback", &::HALSIM_CancelAnalogOutVoltageCallback,
      py::arg("index"), py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getAnalogOutVoltage", &::HALSIM_GetAnalogOutVoltage,
      py::arg("index"), release_gil()
  )
  
  ;
m
  .
def
("setAnalogOutVoltage", &::HALSIM_SetAnalogOutVoltage,
      py::arg("index"), py::arg("voltage"), release_gil()
  )
  
  ;
m
  .
def
("cancelAnalogOutInitializedCallback", &::HALSIM_CancelAnalogOutInitializedCallback,
      py::arg("index"), py::arg("uid"), release_gil()
  )
  
  ;
m
  .
def
("getAnalogOutInitialized", &::HALSIM_GetAnalogOutInitialized,
      py::arg("index"), release_gil()
  )
  
  ;
m
  .
def
("setAnalogOutInitialized", &::HALSIM_SetAnalogOutInitialized,
      py::arg("index"), py::arg("initialized"), release_gil()
  )
  
  ;



}

}; // struct rpybuild_AnalogOutData_initializer

static std::unique_ptr<rpybuild_AnalogOutData_initializer> cls;

void begin_init_AnalogOutData(py::module &m) {
  cls = std::make_unique<rpybuild_AnalogOutData_initializer>(m);
}

void finish_init_AnalogOutData() {
  cls->finish();
  cls.reset();
}