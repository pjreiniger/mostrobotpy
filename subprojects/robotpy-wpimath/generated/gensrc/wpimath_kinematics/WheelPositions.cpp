
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/kinematics/WheelPositions.h>
















#include <type_traits>


  using namespace frc;





struct rpybuild_WheelPositions_initializer {













  py::module &m;

  
  rpybuild_WheelPositions_initializer(py::module &m) :

  

  

  

  

    m(m)
  {
    
    

    
  }

void finish() {










}

}; // struct rpybuild_WheelPositions_initializer

static std::unique_ptr<rpybuild_WheelPositions_initializer> cls;

void begin_init_WheelPositions(py::module &m) {
  cls = std::make_unique<rpybuild_WheelPositions_initializer>(m);
}

void finish_init_WheelPositions() {
  cls->finish();
  cls.reset();
}