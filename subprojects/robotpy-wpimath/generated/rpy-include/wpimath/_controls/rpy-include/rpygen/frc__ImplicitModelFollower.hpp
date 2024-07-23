

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/controller/ImplicitModelFollower.h>










#include <pybind11/eigen.h>


namespace rpygen {


using namespace frc;




template <int States, int Inputs>
struct bind_frc__ImplicitModelFollower {

    

    
  
  
    using StateVector [[maybe_unused]] = typename frc::ImplicitModelFollower<States, Inputs>::StateVector;
  
    using InputVector [[maybe_unused]] = typename frc::ImplicitModelFollower<States, Inputs>::InputVector;
  

    

    py::class_<typename frc::ImplicitModelFollower<States, Inputs>> cls_ImplicitModelFollower;

    

    
    

    py::module &m;
    std::string clsName;

bind_frc__ImplicitModelFollower(py::module &m, const char * clsName) :
    
    cls_ImplicitModelFollower(m, clsName),

  

  
  
    m(m),
    clsName(clsName)
{
    
  

}

void finish(const char * set_doc = NULL, const char * add_doc = NULL) {

    

  cls_ImplicitModelFollower.doc() =
    "Contains the controller coefficients and logic for an implicit model\n"
"follower.\n"
"\n"
"Implicit model following lets us design a feedback controller that erases the\n"
"dynamics of our system and makes it behave like some other system. This can\n"
"be used to make a drivetrain more controllable during teleop driving by\n"
"making it behave like a slower or more benign drivetrain.\n"
"\n"
"For more on the underlying math, read appendix B.3 in\n"
"https://file.tavsys.net/control/controls-engineering-in-frc.pdf.\n"
"\n"
"@tparam States Number of states.\n"
"@tparam Inputs Number of inputs.";

  cls_ImplicitModelFollower
  
    
  .def(py::init<const Matrixd<States, States>&, const Matrixd<States, Inputs>&, const Matrixd<States, States>&, const Matrixd<States, Inputs>&>(),
      py::arg("A"), py::arg("B"), py::arg("Aref"), py::arg("Bref"), release_gil()
    , py::keep_alive<1, 2>()
    , py::keep_alive<1, 3>()
    , py::keep_alive<1, 4>()
    , py::keep_alive<1, 5>(), py::doc(
    "Constructs a controller with the given coefficients and plant.\n"
"\n"
":param A:    Continuous system matrix of the plant being controlled.\n"
":param B:    Continuous input matrix of the plant being controlled.\n"
":param Aref: Continuous system matrix whose dynamics should be followed.\n"
":param Bref: Continuous input matrix whose dynamics should be followed.")
  )
  
  
  
    
  .
def
("U", static_cast<const InputVector&(frc::ImplicitModelFollower<States, Inputs>::*)() const>(
        &frc::ImplicitModelFollower<States, Inputs>::U), release_gil(), py::doc(
    "Returns the control input vector u.\n"
"\n"
":returns: The control input.")
  )
  
  
  
    
  .
def
("U", static_cast<double(frc::ImplicitModelFollower<States, Inputs>::*)(int) const>(
        &frc::ImplicitModelFollower<States, Inputs>::U),
      py::arg("i"), release_gil(), py::doc(
    "Returns an element of the control input vector u.\n"
"\n"
":param i: Row of u.\n"
"\n"
":returns: The row of the control input vector.")
  )
  
  
  
    
  .
def
("reset", &frc::ImplicitModelFollower<States, Inputs>::Reset, release_gil(), py::doc(
    "Resets the controller.")
  )
  
  
  
    
  .
def
("calculate", &frc::ImplicitModelFollower<States, Inputs>::Calculate,
      py::arg("x"), py::arg("u"), release_gil(), py::doc(
    "Returns the next output of the controller.\n"
"\n"
":param x: The current state x.\n"
":param u: The current input for the original model.")
  )
  
  
  ;

  



    if (set_doc) {
        cls_ImplicitModelFollower.doc() = set_doc;
    }
    if (add_doc) {
        cls_ImplicitModelFollower.doc() = py::cast<std::string>(cls_ImplicitModelFollower.doc()) + add_doc;
    }

    cls_ImplicitModelFollower
  .def(py::init<const frc::LinearSystem<States, Inputs, 1>&, const frc::LinearSystem<States, Inputs, 1>&>(),
    py::arg("plant"), py::arg("plantRef"))
  .def(py::init<const frc::LinearSystem<States, Inputs, 2>&, const frc::LinearSystem<States, Inputs, 2>&>(),
    py::arg("plant"), py::arg("plantRef"))
  .def(py::init<const frc::LinearSystem<States, Inputs, 3>&, const frc::LinearSystem<States, Inputs, 3>&>(),
    py::arg("plant"), py::arg("plantRef"))
  ;

}

}; // struct bind_frc__ImplicitModelFollower

}; // namespace rpygen
