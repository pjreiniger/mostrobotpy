
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/geometry/Twist3d.h>


#include <units_angle_type_caster.h>

#include <units_length_type_caster.h>



#include <pybind11/operators.h>











#include <wpystruct.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_Twist3d_initializer {


  

  












  py::class_<typename frc::Twist3d> cls_Twist3d;

    

    
    

  py::module &m;

  
  rpybuild_Twist3d_initializer(py::module &m) :

  

  

  

  
    cls_Twist3d(m, "Twist3d"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_Twist3d.doc() =
    "A change in distance along a 3D arc since the last pose update. We can use\n"
"ideas from differential calculus to create new Pose3ds from a Twist3d and\n"
"vice versa.\n"
"\n"
"A Twist can be used to represent a difference between two poses.";

  cls_Twist3d
  
    
  .def(py::self == py::self, py::doc(
    "Checks equality between this Twist3d and another object.\n"
"\n"
":param other: The other object.\n"
"\n"
":returns: Whether the two objects are equal.")
  )
  
  
  
    
  .def(py::self * double(), py::doc(
    "Scale this by a given factor.\n"
"\n"
":param factor: The factor by which to scale.\n"
"\n"
":returns: The scaled Twist3d.")
  )
  
  
  
    .def_readwrite("dx", &frc::Twist3d::dx, py::doc(
    "Linear \"dx\" component"))
  
    .def_readwrite("dy", &frc::Twist3d::dy, py::doc(
    "Linear \"dy\" component"))
  
    .def_readwrite("dz", &frc::Twist3d::dz, py::doc(
    "Linear \"dz\" component"))
  
    .def_readwrite("rx", &frc::Twist3d::rx, py::doc(
    "Rotation vector x component."))
  
    .def_readwrite("ry", &frc::Twist3d::ry, py::doc(
    "Rotation vector y component."))
  
    .def_readwrite("rz", &frc::Twist3d::rz, py::doc(
    "Rotation vector z component."))
  ;

  


  }







  cls_Twist3d
  .def(
    py::init<units::meter_t, units::meter_t, units::meter_t,
             units::radian_t, units::radian_t, units::radian_t>(),
    py::arg("dx") = 0, py::arg("dy") = 0, py::arg("dz") = 0,
    py::arg("rx") = 0, py::arg("ry") = 0, py::arg("rz") = 0)
  .def_static("fromFeet", [](
    units::foot_t dx, units::foot_t dy, units::foot_t dz,
    units::radian_t rx, units::radian_t ry, units::radian_t rz){
    return Twist3d{dx, dy, dz, rx, ry, rz};
  },
    py::arg("dx") = 0, py::arg("dy") = 0, py::arg("dz") = 0,
    py::arg("rx") = 0, py::arg("ry") = 0, py::arg("rz") = 0)
  .def_property("dx_feet", 
    [](Twist3d * self) -> units::foot_t {
      return self->dx;
    },
    [](Twist3d * self, units::foot_t dx) {
      self->dx = dx;
    }
  )
  .def_property("dy_feet", 
    [](Twist3d * self) -> units::foot_t {
      return self->dy;
    },
    [](Twist3d * self, units::foot_t dy) {
      self->dy = dy;
    }
  )
  .def_property("dz_feet", 
    [](Twist3d * self) -> units::foot_t {
      return self->dz;
    },
    [](Twist3d * self, units::foot_t dz) {
      self->dz = dz;
    }
  )
  .def_property("rx_degrees", 
    [](Twist3d * self) -> units::degree_t {
      return self->rx;
    },
    [](Twist3d * self, units::degree_t rx) {
      self->rx = rx;
    }
  )
  .def_property("ry_degrees", 
    [](Twist3d * self) -> units::degree_t {
      return self->ry;
    },
    [](Twist3d * self, units::degree_t ry) {
      self->ry = ry;
    }
  )
  .def_property("rz_degrees", 
    [](Twist3d * self) -> units::degree_t {
      return self->rz;
    },
    [](Twist3d * self, units::degree_t rz) {
      self->rz = rz;
    }
  )
  .def("__repr__", [](const Twist3d &tw) -> std::string {
    return "Twist3d(dx=" + std::to_string(tw.dx()) + ", "
                   "dy=" + std::to_string(tw.dy()) + ", "
                   "dz=" + std::to_string(tw.dz()) + ", "
                   "rx=" + std::to_string(tw.rx()) + ", "
                   "ry=" + std::to_string(tw.ry()) + ", "
                   "rz=" + std::to_string(tw.rz()) + ")";
  })
;

SetupWPyStruct<frc::Twist3d>(cls_Twist3d);

}

}; // struct rpybuild_Twist3d_initializer

static std::unique_ptr<rpybuild_Twist3d_initializer> cls;

void begin_init_Twist3d(py::module &m) {
  cls = std::make_unique<rpybuild_Twist3d_initializer>(m);
}

void finish_init_Twist3d() {
  cls->finish();
  cls.reset();
}