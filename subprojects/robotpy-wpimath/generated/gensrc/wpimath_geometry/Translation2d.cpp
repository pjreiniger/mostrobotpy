
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/geometry/Translation2d.h>


#include <units_length_type_caster.h>

#include <wpi_span_type_caster.h>



#include <pybind11/operators.h>











#include <rpy/geometryToString.h>

#include <wpystruct.h>

#include <pybind11/eigen.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_Translation2d_initializer {


  

  












  py::class_<typename frc::Translation2d> cls_Translation2d;

    

    
    

  py::module &m;

  
  rpybuild_Translation2d_initializer(py::module &m) :

  

  

  

  
    cls_Translation2d(m, "Translation2d"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_Translation2d.doc() =
    "Represents a translation in 2D space.\n"
"This object can be used to represent a point or a vector.\n"
"\n"
"This assumes that you are using conventional mathematical axes.\n"
"When the robot is at the origin facing in the positive X direction, forward\n"
"is positive X and left is positive Y.";

  cls_Translation2d
  
    
  .def(py::init<>(), release_gil(), py::doc(
    "Constructs a Translation2d with X and Y components equal to zero.")
  )
  
  
  
    
  .def(py::init<units::meter_t, units::meter_t>(),
      py::arg("x"), py::arg("y"), release_gil(), py::doc(
    "Constructs a Translation2d with the X and Y components equal to the\n"
"provided values.\n"
"\n"
":param x: The x component of the translation.\n"
":param y: The y component of the translation.")
  )
  
  
  
    
  .def(py::init<units::meter_t, const Rotation2d&>(),
      py::arg("distance"), py::arg("angle"), release_gil()
    , py::keep_alive<1, 3>(), py::doc(
    "Constructs a Translation2d with the provided distance and angle. This is\n"
"essentially converting from polar coordinates to Cartesian coordinates.\n"
"\n"
":param distance: The distance from the origin to the end of the translation.\n"
":param angle:    The angle between the x-axis and the translation vector.")
  )
  
  
  
    
  .def(py::init<const Eigen::Vector2d&>(),
      py::arg("vector"), release_gil()
    , py::keep_alive<1, 2>(), py::doc(
    "Constructs a Translation2d from the provided translation vector's X and Y\n"
"components. The values are assumed to be in meters.\n"
"\n"
":param vector: The translation vector to represent.")
  )
  
  
  
    
  .
def
("distance", &frc::Translation2d::Distance,
      py::arg("other"), release_gil(), py::doc(
    "Calculates the distance between two translations in 2D space.\n"
"\n"
"The distance between translations is defined as √((x₂−x₁)²+(y₂−y₁)²).\n"
"\n"
":param other: The translation to compute the distance to.\n"
"\n"
":returns: The distance between the two translations.")
  )
  
  
  
    
  .
def
("X", &frc::Translation2d::X, release_gil(), py::doc(
    "Returns the X component of the translation.\n"
"\n"
":returns: The X component of the translation.")
  )
  
  
  
    
  .
def
("Y", &frc::Translation2d::Y, release_gil(), py::doc(
    "Returns the Y component of the translation.\n"
"\n"
":returns: The Y component of the translation.")
  )
  
  
  
    
  .
def
("toVector", &frc::Translation2d::ToVector, release_gil(), py::doc(
    "Returns a vector representation of this translation.\n"
"\n"
":returns: A Vector representation of this translation.")
  )
  
  
  
    
  .
def
("norm", &frc::Translation2d::Norm, release_gil(), py::doc(
    "Returns the norm, or distance from the origin to the translation.\n"
"\n"
":returns: The norm of the translation.")
  )
  
  
  
    
  .
def
("angle", &frc::Translation2d::Angle, release_gil(), py::doc(
    "Returns the angle this translation forms with the positive X axis.\n"
"\n"
":returns: The angle of the translation")
  )
  
  
  
    
  .
def
("rotateBy", &frc::Translation2d::RotateBy,
      py::arg("other"), release_gil(), py::doc(
    "Applies a rotation to the translation in 2D space.\n"
"\n"
"This multiplies the translation vector by a counterclockwise rotation\n"
"matrix of the given angle.\n"
"\n"
"::\n"
"\n"
"  [x_new]   [other.cos, -other.sin][x]\n"
"  [y_new] = [other.sin,  other.cos][y]\n"
"\n"
"For example, rotating a Translation2d of &lt;2, 0&gt; by 90 degrees will\n"
"return a Translation2d of &lt;0, 2&gt;.\n"
"\n"
":param other: The rotation to rotate the translation by.\n"
"\n"
":returns: The new rotated translation.")
  )
  
  
  
    
  .def(py::self + py::self, py::doc(
    "Returns the sum of two translations in 2D space.\n"
"\n"
"For example, Translation3d{1.0, 2.5} + Translation3d{2.0, 5.5} =\n"
"Translation3d{3.0, 8.0}.\n"
"\n"
":param other: The translation to add.\n"
"\n"
":returns: The sum of the translations.")
  )
  
  
  
    
  .def(py::self - py::self, py::doc(
    "Returns the difference between two translations.\n"
"\n"
"For example, Translation2d{5.0, 4.0} - Translation2d{1.0, 2.0} =\n"
"Translation2d{4.0, 2.0}.\n"
"\n"
":param other: The translation to subtract.\n"
"\n"
":returns: The difference between the two translations.")
  )
  
  
  
    
  .def(- py::self, py::doc(
    "Returns the inverse of the current translation. This is equivalent to\n"
"rotating by 180 degrees, flipping the point over both axes, or negating all\n"
"components of the translation.\n"
"\n"
":returns: The inverse of the current translation.")
  )
  
  
  
    
  .def(py::self * double(), py::doc(
    "Returns the translation multiplied by a scalar.\n"
"\n"
"For example, Translation2d{2.0, 2.5} * 2 = Translation2d{4.0, 5.0}.\n"
"\n"
":param scalar: The scalar to multiply by.\n"
"\n"
":returns: The scaled translation.")
  )
  
  
  
    
  .def(py::self / double(), py::doc(
    "Returns the translation divided by a scalar.\n"
"\n"
"For example, Translation2d{2.0, 2.5} / 2 = Translation2d{1.0, 1.25}.\n"
"\n"
":param scalar: The scalar to divide by.\n"
"\n"
":returns: The scaled translation.")
  )
  
  
  
    
  .def(py::self == py::self, py::doc(
    "Checks equality between this Translation2d and another object.\n"
"\n"
":param other: The other object.\n"
"\n"
":returns: Whether the two objects are equal.")
  )
  
  
  
    
  .
def
("nearest", static_cast<Translation2d(frc::Translation2d::*)(std::span<const Translation2d>) const>(
        &frc::Translation2d::Nearest),
      py::arg("translations"), release_gil(), py::doc(
    "Returns the nearest Translation2d from a collection of translations\n"
"\n"
":param translations: The collection of translations.\n"
"\n"
":returns: The nearest Translation2d from the collection.")
  )
  
  
  ;

  


  }







  cls_Translation2d
  .def_static("fromFeet", [](units::foot_t x, units::foot_t y){
    return std::make_unique<Translation2d>(x, y);
  }, py::arg("x"), py::arg("y"))
  .def_property_readonly("x", &Translation2d::X)
  .def_property_readonly("y", &Translation2d::Y)
  .def_property_readonly("x_feet", [](Translation2d * self) -> units::foot_t {
    return self->X();
  })
  .def_property_readonly("y_feet", [](Translation2d * self) -> units::foot_t {
    return self->Y();
  })
  .def("distanceFeet", [](Translation2d * self, const Translation2d &other) -> units::foot_t {
    return self->Distance(other);
  })
  .def("normFeet", [](Translation2d * self) -> units::foot_t {
    return self->Norm();
  })
  .def("__abs__", &Translation2d::Norm)
  .def("__len__", [](const Translation2d& self) { return 2; })
  .def("__getitem__", [](const Translation2d& self, int index) {
    switch (index) {
      case 0:
        return self.X();
      case 1:
        return self.Y();
      default:
        throw std::out_of_range("Translation2d index out of range");
    }
  })
  .def("__repr__", py::overload_cast<const Translation2d&>(&rpy::toString));

SetupWPyStruct<frc::Translation2d>(cls_Translation2d);


}

}; // struct rpybuild_Translation2d_initializer

static std::unique_ptr<rpybuild_Translation2d_initializer> cls;

void begin_init_Translation2d(py::module &m) {
  cls = std::make_unique<rpybuild_Translation2d_initializer>(m);
}

void finish_init_Translation2d() {
  cls->finish();
  cls.reset();
}