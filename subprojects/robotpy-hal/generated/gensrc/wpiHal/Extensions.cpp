
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <hal/Extensions.h>
















#include <type_traits>






struct rpybuild_Extensions_initializer {













  py::module &m;

  
  rpybuild_Extensions_initializer(py::module &m) :

  

  

  

  

    m(m)
  {
    
    

    
  }

void finish() {







m
  

  #ifndef __FRC_ROBORIO__
  .
def
("loadOneExtension", &::HAL_LoadOneExtension,
      py::arg("library"), release_gil(), py::doc(
    "Loads a single extension from a direct path.\n"
"\n"
"Expected to be called internally, not by users.\n"
"\n"
":param library: the library path\n"
"\n"
":returns: the success state of the initialization")
  )
  
  
  #endif // __FRC_ROBORIO__
  ;
m
  

  #ifndef __FRC_ROBORIO__
  .
def
("loadExtensions", &::HAL_LoadExtensions, release_gil(), py::doc(
    "Loads any extra halsim libraries provided in the HALSIM_EXTENSIONS\n"
"environment variable.\n"
"\n"
":returns: the success state of the initialization")
  )
  
  
  #endif // __FRC_ROBORIO__
  ;
m
  

  #ifndef __FRC_ROBORIO__
  .
def
("setShowExtensionsNotFoundMessages", &::HAL_SetShowExtensionsNotFoundMessages,
      py::arg("showMessage"), release_gil(), py::doc(
    "Enables or disables the message saying no HAL extensions were found.\n"
"\n"
"Some apps don't care, and the message create clutter. For general team code,\n"
"we want it.\n"
"\n"
"This must be called before HAL_Initialize is called.\n"
"\n"
"This defaults to true.\n"
"\n"
":param showMessage: true to show message, false to not.")
  )
  
  
  #endif // __FRC_ROBORIO__
  ;



}

}; // struct rpybuild_Extensions_initializer

static std::unique_ptr<rpybuild_Extensions_initializer> cls;

void begin_init_Extensions(py::module &m) {
  cls = std::make_unique<rpybuild_Extensions_initializer>(m);
}

void finish_init_Extensions() {
  cls->finish();
  cls.reset();
}