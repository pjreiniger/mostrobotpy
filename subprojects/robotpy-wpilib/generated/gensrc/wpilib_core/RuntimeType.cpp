
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/RuntimeType.h>
















#include <type_traits>


  using namespace frc;





struct rpybuild_RuntimeType_initializer {







  
  py::enum_<frc::RuntimeType> enum1;







  py::module &m;

  
  rpybuild_RuntimeType_initializer(py::module &m) :

  

  
    enum1
  (m, "RuntimeType"
  ,
    "Runtime type."),
  

  

  

    m(m)
  {
    
    
      enum1
  
    .value("kRoboRIO", frc::RuntimeType::kRoboRIO,
      "roboRIO 1.0.")
  
    .value("kRoboRIO2", frc::RuntimeType::kRoboRIO2,
      "roboRIO 2.0.")
  
    .value("kSimulation", frc::RuntimeType::kSimulation,
      "Simulation runtime.")
  ;

    

    
  }

void finish() {










}

}; // struct rpybuild_RuntimeType_initializer

static std::unique_ptr<rpybuild_RuntimeType_initializer> cls;

void begin_init_RuntimeType(py::module &m) {
  cls = std::make_unique<rpybuild_RuntimeType_initializer>(m);
}

void finish_init_RuntimeType() {
  cls->finish();
  cls.reset();
}