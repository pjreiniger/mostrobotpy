
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/shuffleboard/WidgetType.h>
















#include <type_traits>


  using namespace frc;





struct rpybuild_WidgetType_initializer {


  

  












  py::class_<typename frc::WidgetType> cls_WidgetType;

    

    
    

  py::module &m;

  
  rpybuild_WidgetType_initializer(py::module &m) :

  

  

  

  
    cls_WidgetType(m, "WidgetType"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_WidgetType.doc() =
    "Represents the type of a widget in Shuffleboard. Using this is preferred over\n"
"specifying raw strings, to avoid typos and having to know or look up the\n"
"exact string name for a desired widget.\n"
"\n"
"@see BuiltInWidgets the built-in widget types";

  cls_WidgetType
  
    
  .def(py::init<const char*>(),
      py::arg("widgetName"), release_gil()
  )
  
  
  
    
  .
def
("getWidgetName", &frc::WidgetType::GetWidgetName, release_gil(), py::doc(
    "Gets the string type of the widget as defined by that widget in\n"
"Shuffleboard.")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_WidgetType_initializer

static std::unique_ptr<rpybuild_WidgetType_initializer> cls;

void begin_init_WidgetType(py::module &m) {
  cls = std::make_unique<rpybuild_WidgetType_initializer>(m);
}

void finish_init_WidgetType() {
  cls->finish();
  cls.reset();
}