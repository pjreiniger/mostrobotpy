
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/kinematics/DifferentialDriveWheelPositions.h>


#include <units_length_type_caster.h>



#include <pybind11/operators.h>













#include <type_traits>


  using namespace frc;





struct rpybuild_DifferentialDriveWheelPositions_initializer {


  

  












  py::class_<typename frc::DifferentialDriveWheelPositions> cls_DifferentialDriveWheelPositions;

    

    
    

  py::module &m;

  
  rpybuild_DifferentialDriveWheelPositions_initializer(py::module &m) :

  

  

  

  
    cls_DifferentialDriveWheelPositions(m, "DifferentialDriveWheelPositions"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_DifferentialDriveWheelPositions.doc() =
    "Represents the wheel positions for a differential drive drivetrain.";

  cls_DifferentialDriveWheelPositions
  
    .def(py::init<>(), release_gil())
  
    
  .def(py::self == py::self, py::doc(
    "Checks equality between this DifferentialDriveWheelPositions and another\n"
"object.\n"
"\n"
":param other: The other object.\n"
"\n"
":returns: Whether the two objects are equal.")
  )
  
  
  
    
  .def(py::self != py::self, py::doc(
    "Checks inequality between this DifferentialDriveWheelPositions and another\n"
"object.\n"
"\n"
":param other: The other object.\n"
"\n"
":returns: Whether the two objects are not equal.")
  )
  
  
  
    
  .
def
("interpolate", &frc::DifferentialDriveWheelPositions::Interpolate,
      py::arg("endValue"), py::arg("t"), release_gil()
  )
  
  
  
    .def_readwrite("left", &frc::DifferentialDriveWheelPositions::left, py::doc(
    "Distance driven by the left side."))
  
    .def_readwrite("right", &frc::DifferentialDriveWheelPositions::right, py::doc(
    "Distance driven by the right side."))
  ;

  


  }






}

}; // struct rpybuild_DifferentialDriveWheelPositions_initializer

static std::unique_ptr<rpybuild_DifferentialDriveWheelPositions_initializer> cls;

void begin_init_DifferentialDriveWheelPositions(py::module &m) {
  cls = std::make_unique<rpybuild_DifferentialDriveWheelPositions_initializer>(m);
}

void finish_init_DifferentialDriveWheelPositions() {
  cls->finish();
  cls.reset();
}