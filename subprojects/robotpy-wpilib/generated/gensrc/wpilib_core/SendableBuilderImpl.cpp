
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>

#include <functional>




#include <frc/smartdashboard/SendableBuilderImpl.h>


#include <pybind11/functional.h>

#include <pybind11/stl.h>

#include <wpi_smallvectorimpl_type_caster.h>

#include <wpi_span_type_caster.h>







#define RPYGEN_ENABLE_frc__SendableBuilderImpl_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__SendableBuilderImpl.hpp>









#include <type_traits>


  using namespace frc;





struct rpybuild_SendableBuilderImpl_initializer {


  

  












  
  using SendableBuilderImpl_Trampoline = rpygen::PyTrampoline_frc__SendableBuilderImpl<typename frc::SendableBuilderImpl, typename rpygen::PyTrampolineCfg_frc__SendableBuilderImpl<>>;
    static_assert(std::is_abstract<SendableBuilderImpl_Trampoline>::value == false, "frc::SendableBuilderImpl " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::SendableBuilderImpl, SendableBuilderImpl_Trampoline, nt::NTSendableBuilder> cls_SendableBuilderImpl;

    

    
    

  py::module &m;

  
  rpybuild_SendableBuilderImpl_initializer(py::module &m) :

  

  

  

  
    cls_SendableBuilderImpl(m, "SendableBuilderImpl"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  
  {
    auto vcheck = [](SendableBuilderImpl *self, std::function<void()> func) {
  self->SetUpdateTable(std::move(func));
};
    static_assert(std::is_convertible<decltype(vcheck), std::function<void(frc::SendableBuilderImpl*, wpi::unique_function<void ()>) >>::value,
      "frc::SendableBuilderImpl::SetUpdateTable must have virtual_xform if cpp_code signature doesn't match original function");
  }
  

  cls_SendableBuilderImpl.doc() =
    "Implementation detail for SendableBuilder.";

  cls_SendableBuilderImpl
  
    
  .def(py::init<>(), release_gil()
  )
  
  
  
    
  .
def
("setTable", &frc::SendableBuilderImpl::SetTable,
      py::arg("table"), release_gil(), py::doc(
    "Set the network table.  Must be called prior to any Add* functions being\n"
"called.\n"
"\n"
":param table: Network table")
  )
  
  
  
    
  .
def
("getTable", &frc::SendableBuilderImpl::GetTable, release_gil(), py::doc(
    "Get the network table.\n"
"\n"
":returns: The network table")
  )
  
  
  
    
  .
def
("isPublished", &frc::SendableBuilderImpl::IsPublished, release_gil(), py::doc(
    "Return whether this sendable has an associated table.\n"
"\n"
":returns: True if it has a table, false if not.")
  )
  
  
  
    
  .
def
("isActuator", &frc::SendableBuilderImpl::IsActuator, release_gil(), py::doc(
    "Return whether this sendable should be treated as an actuator.\n"
"\n"
":returns: True if actuator, false if not.")
  )
  
  
  
    
  .
def
("update", &frc::SendableBuilderImpl::Update, release_gil(), py::doc(
    "Synchronize with network table values by calling the getters for all\n"
"properties and setters when the network table value has changed.")
  )
  
  
  
    
  .
def
("startListeners", &frc::SendableBuilderImpl::StartListeners, release_gil(), py::doc(
    "Hook setters for all properties.")
  )
  
  
  
    
  .
def
("stopListeners", &frc::SendableBuilderImpl::StopListeners, release_gil(), py::doc(
    "Unhook setters for all properties.")
  )
  
  
  
    
  .
def
("startLiveWindowMode", &frc::SendableBuilderImpl::StartLiveWindowMode, release_gil(), py::doc(
    "Start LiveWindow mode by hooking the setters for all properties.  Also\n"
"calls the SafeState function if one was provided.")
  )
  
  
  
    
  .
def
("stopLiveWindowMode", &frc::SendableBuilderImpl::StopLiveWindowMode, release_gil(), py::doc(
    "Stop LiveWindow mode by unhooking the setters for all properties.  Also\n"
"calls the SafeState function if one was provided.")
  )
  
  
  
    
  .
def
("clearProperties", &frc::SendableBuilderImpl::ClearProperties, release_gil(), py::doc(
    "Clear properties.")
  )
  
  
  
    
  .
def
("setSmartDashboardType", &frc::SendableBuilderImpl::SetSmartDashboardType,
      py::arg("type"), release_gil()
  )
  
  
  
    
  .
def
("setActuator", &frc::SendableBuilderImpl::SetActuator,
      py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("setSafeState", &frc::SendableBuilderImpl::SetSafeState,
      py::arg("func").none(false), release_gil()
  )
  
  
  
    
  .
def
("setUpdateTable", [](SendableBuilderImpl *self, std::function<void()> func) {
  self->SetUpdateTable(std::move(func));
}
,
      py::arg("func")
  )
  
  
  
    
  .
def
("getTopic", &frc::SendableBuilderImpl::GetTopic,
      py::arg("key"), release_gil()
  )
  
  
  
    
  .
def
("addBooleanProperty", &frc::SendableBuilderImpl::AddBooleanProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("publishConstBoolean", &frc::SendableBuilderImpl::PublishConstBoolean,
      py::arg("key"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("addIntegerProperty", &frc::SendableBuilderImpl::AddIntegerProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("publishConstInteger", &frc::SendableBuilderImpl::PublishConstInteger,
      py::arg("key"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("addFloatProperty", &frc::SendableBuilderImpl::AddFloatProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("publishConstFloat", &frc::SendableBuilderImpl::PublishConstFloat,
      py::arg("key"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("addDoubleProperty", &frc::SendableBuilderImpl::AddDoubleProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("publishConstDouble", &frc::SendableBuilderImpl::PublishConstDouble,
      py::arg("key"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("addStringProperty", &frc::SendableBuilderImpl::AddStringProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("publishConstString", &frc::SendableBuilderImpl::PublishConstString,
      py::arg("key"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("addBooleanArrayProperty", &frc::SendableBuilderImpl::AddBooleanArrayProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("publishConstBooleanArray", &frc::SendableBuilderImpl::PublishConstBooleanArray,
      py::arg("key"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("addIntegerArrayProperty", &frc::SendableBuilderImpl::AddIntegerArrayProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("publishConstIntegerArray", &frc::SendableBuilderImpl::PublishConstIntegerArray,
      py::arg("key"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("addFloatArrayProperty", &frc::SendableBuilderImpl::AddFloatArrayProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("publishConstFloatArray", &frc::SendableBuilderImpl::PublishConstFloatArray,
      py::arg("key"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("addDoubleArrayProperty", &frc::SendableBuilderImpl::AddDoubleArrayProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("publishConstDoubleArray", &frc::SendableBuilderImpl::PublishConstDoubleArray,
      py::arg("key"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("addStringArrayProperty", &frc::SendableBuilderImpl::AddStringArrayProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("publishConstStringArray", &frc::SendableBuilderImpl::PublishConstStringArray,
      py::arg("key"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("addRawProperty", &frc::SendableBuilderImpl::AddRawProperty,
      py::arg("key"), py::arg("typeString"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("publishConstRaw", &frc::SendableBuilderImpl::PublishConstRaw,
      py::arg("key"), py::arg("typeString"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("addSmallStringProperty", &frc::SendableBuilderImpl::AddSmallStringProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("addSmallBooleanArrayProperty", &frc::SendableBuilderImpl::AddSmallBooleanArrayProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("addSmallIntegerArrayProperty", &frc::SendableBuilderImpl::AddSmallIntegerArrayProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("addSmallFloatArrayProperty", &frc::SendableBuilderImpl::AddSmallFloatArrayProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("addSmallDoubleArrayProperty", &frc::SendableBuilderImpl::AddSmallDoubleArrayProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("addSmallStringArrayProperty", &frc::SendableBuilderImpl::AddSmallStringArrayProperty,
      py::arg("key"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  
    
  .
def
("addSmallRawProperty", &frc::SendableBuilderImpl::AddSmallRawProperty,
      py::arg("key"), py::arg("typeString"), py::arg("getter").none(false), py::arg("setter").none(false), release_gil()
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_SendableBuilderImpl_initializer

static std::unique_ptr<rpybuild_SendableBuilderImpl_initializer> cls;

void begin_init_SendableBuilderImpl(py::module &m) {
  cls = std::make_unique<rpybuild_SendableBuilderImpl_initializer>(m);
}

void finish_init_SendableBuilderImpl() {
  cls->finish();
  cls.reset();
}