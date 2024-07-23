
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/shuffleboard/ShuffleboardRoot.h>








#define RPYGEN_ENABLE_frc__ShuffleboardRoot_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__ShuffleboardRoot.hpp>







#include <frc/shuffleboard/ShuffleboardTab.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_ShuffleboardRoot_initializer {


  

  












  
  using ShuffleboardRoot_Trampoline = rpygen::PyTrampoline_frc__ShuffleboardRoot<typename frc::ShuffleboardRoot, typename rpygen::PyTrampolineCfg_frc__ShuffleboardRoot<>>;
    static_assert(std::is_abstract<ShuffleboardRoot_Trampoline>::value == false, "frc::ShuffleboardRoot " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::ShuffleboardRoot, ShuffleboardRoot_Trampoline> cls_ShuffleboardRoot;

    

    
    

  py::module &m;

  
  rpybuild_ShuffleboardRoot_initializer(py::module &m) :

  

  

  

  
    cls_ShuffleboardRoot(m, "_ShuffleboardRoot"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_ShuffleboardRoot.doc() =
    "The root of the data placed in Shuffleboard. It contains the tabs, but no\n"
"data is placed directly in the root.\n"
"\n"
"This class is package-private to minimize API surface area.";

  cls_ShuffleboardRoot
  
    .def(py::init<>(), release_gil())
  
    
  .
def
("getTab", &frc::ShuffleboardRoot::GetTab,
      py::arg("title"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Gets the tab with the given title, creating it if it does not already\n"
"exist.\n"
"\n"
":param title: the title of the tab\n"
"\n"
":returns: the tab with the given title")
  )
  
  
  
    
  .
def
("update", &frc::ShuffleboardRoot::Update, release_gil(), py::doc(
    "Updates all tabs.")
  )
  
  
  
    
  .
def
("enableActuatorWidgets", &frc::ShuffleboardRoot::EnableActuatorWidgets, release_gil(), py::doc(
    "Enables all widgets in Shuffleboard that offer user control over actuators.")
  )
  
  
  
    
  .
def
("disableActuatorWidgets", &frc::ShuffleboardRoot::DisableActuatorWidgets, release_gil(), py::doc(
    "Disables all widgets in Shuffleboard that offer user control over\n"
"actuators.")
  )
  
  
  
    
  .
def
("selectTab", static_cast<void(frc::ShuffleboardRoot::*)(int)>(
        &frc::ShuffleboardRoot::SelectTab),
      py::arg("index"), release_gil(), py::doc(
    "Selects the tab in the dashboard with the given index in the range\n"
"[0..n-1], where *n* is the number of tabs in the dashboard at the time\n"
"this method is called.\n"
"\n"
":param index: the index of the tab to select")
  )
  
  
  
    
  .
def
("selectTab", static_cast<void(frc::ShuffleboardRoot::*)(std::string_view)>(
        &frc::ShuffleboardRoot::SelectTab),
      py::arg("title"), release_gil(), py::doc(
    "Selects the tab in the dashboard with the given title.\n"
"\n"
":param title: the title of the tab to select")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_ShuffleboardRoot_initializer

static std::unique_ptr<rpybuild_ShuffleboardRoot_initializer> cls;

void begin_init_ShuffleboardRoot(py::module &m) {
  cls = std::make_unique<rpybuild_ShuffleboardRoot_initializer>(m);
}

void finish_init_ShuffleboardRoot() {
  cls->finish();
  cls.reset();
}