
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>

#include <functional>




#include <networktables/NTSendableBuilder.h>


#include <pybind11/functional.h>







#define RPYGEN_ENABLE_nt__NTSendableBuilder_PROTECTED_CONSTRUCTORS
#include <rpygen/nt__NTSendableBuilder.hpp>









#include <type_traits>


  using namespace nt;





struct rpybuild_NTSendableBuilder_initializer {


  
    using BackendKind = wpi::SendableBuilder::BackendKind;
  

  












  
  using NTSendableBuilder_Trampoline = rpygen::PyTrampoline_nt__NTSendableBuilder<typename nt::NTSendableBuilder, typename rpygen::PyTrampolineCfg_nt__NTSendableBuilder<>>;
    static_assert(std::is_abstract<NTSendableBuilder_Trampoline>::value == false, "nt::NTSendableBuilder " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename nt::NTSendableBuilder, NTSendableBuilder_Trampoline, wpi::SendableBuilder> cls_NTSendableBuilder;

    

    
    

  py::module &m;

  
  rpybuild_NTSendableBuilder_initializer(py::module &m) :

  

  

  

  
    cls_NTSendableBuilder(m, "NTSendableBuilder"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  
  {
    auto vcheck = [](NTSendableBuilder *self, std::function<void()> func) {
  self->SetUpdateTable(std::move(func));
};
    static_assert(std::is_convertible<decltype(vcheck), std::function<void(nt::NTSendableBuilder*, wpi::unique_function<void ()>) >>::value,
      "nt::NTSendableBuilder::SetUpdateTable must have virtual_xform if cpp_code signature doesn't match original function");
  }
  

  cls_NTSendableBuilder.doc() =
    "Helper class for building Sendable dashboard representations for\n"
"NetworkTables.";

  cls_NTSendableBuilder
  
    .def(py::init<>(), release_gil())
  
    
  .
def
("setUpdateTable", [](NTSendableBuilder *self, std::function<void()> func) {
  self->SetUpdateTable(std::move(func));
}
,
      py::arg("func"), py::doc(
    "Set the function that should be called to update the network table\n"
"for things other than properties.  Note this function is not passed\n"
"the network table object; instead it should use the entry handles\n"
"returned by GetEntry().\n"
"\n"
":param func: function")
  )
  
  
  
    
  .
def
("getTopic", &nt::NTSendableBuilder::GetTopic,
      py::arg("key"), release_gil(), py::doc(
    "Add a property without getters or setters.  This can be used to get\n"
"entry handles for the function called by SetUpdateTable().\n"
"\n"
":param key: property name\n"
"\n"
":returns: Network table topic")
  )
  
  
  
    
  .
def
("getTable", &nt::NTSendableBuilder::GetTable, release_gil(), py::doc(
    "Get the network table.\n"
"\n"
":returns: The network table")
  )
  
  
  
    
  .
def
("getBackendKind", &nt::NTSendableBuilder::GetBackendKind, release_gil(), py::doc(
    "Gets the kind of backend being used.\n"
"\n"
":returns: Backend kind")
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_NTSendableBuilder_initializer

static std::unique_ptr<rpybuild_NTSendableBuilder_initializer> cls;

void begin_init_NTSendableBuilder(py::module &m) {
  cls = std::make_unique<rpybuild_NTSendableBuilder_initializer>(m);
}

void finish_init_NTSendableBuilder() {
  cls->finish();
  cls.reset();
}