

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <networktables/StructArrayTopic.h>










#include <rpygen/nt__Publisher.hpp>



namespace rpygen {


using namespace nt;





template <typename T, typename I, typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_nt__StructArrayPublisher :


    PyTrampolineCfg_nt__Publisher<

CfgBase
>

{
    using Base = nt::StructArrayPublisher<T, I>;

    
    
};




template <typename PyTrampolineBase, typename T, typename I, typename PyTrampolineCfg>
using PyTrampolineBase_nt__StructArrayPublisher =

    PyTrampoline_nt__Publisher<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename T, typename I, typename PyTrampolineCfg>
struct PyTrampoline_nt__StructArrayPublisher : PyTrampolineBase_nt__StructArrayPublisher<PyTrampolineBase, T, I, PyTrampolineCfg> {
    using PyTrampolineBase_nt__StructArrayPublisher<PyTrampolineBase, T, I, PyTrampolineCfg>::PyTrampolineBase_nt__StructArrayPublisher;






    using TopicType [[maybe_unused]] = typename nt::StructArrayPublisher<T, I>::TopicType;

    using ValueType [[maybe_unused]] = typename nt::StructArrayPublisher<T, I>::ValueType;

    using ParamType [[maybe_unused]] = typename nt::StructArrayPublisher<T, I>::ParamType;

    using TimestampedValueType [[maybe_unused]] = typename nt::StructArrayPublisher<T, I>::TimestampedValueType;






    
    

    
    

    

    
};

}; // namespace rpygen







#include <pybind11/stl.h>

#include <wpi_json_type_caster.h>

#include <wpi_span_type_caster.h>

#include <wpystruct.h>


namespace rpygen {


using namespace nt;




template <typename T, typename I>
struct bind_nt__StructArrayPublisher {

    

    
  
  
    using TopicType [[maybe_unused]] = typename nt::StructArrayPublisher<T, I>::TopicType;
  
    using ValueType [[maybe_unused]] = typename nt::StructArrayPublisher<T, I>::ValueType;
  
    using ParamType [[maybe_unused]] = typename nt::StructArrayPublisher<T, I>::ParamType;
  
    using TimestampedValueType [[maybe_unused]] = typename nt::StructArrayPublisher<T, I>::TimestampedValueType;
  

    

    
  using StructArrayPublisher_Trampoline = rpygen::PyTrampoline_nt__StructArrayPublisher<typename nt::StructArrayPublisher<T, I>, T, I, typename rpygen::PyTrampolineCfg_nt__StructArrayPublisher<T, I>>;
    static_assert(std::is_abstract<StructArrayPublisher_Trampoline>::value == false, "nt::StructArrayPublisher<T, I> " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename nt::StructArrayPublisher<T, I>, StructArrayPublisher_Trampoline, nt::Publisher> cls_StructArrayPublisher;

    

    
    

    py::module &m;
    std::string clsName;

bind_nt__StructArrayPublisher(py::module &m, const char * clsName) :
    
    cls_StructArrayPublisher(m, clsName),

  

  
  
    m(m),
    clsName(clsName)
{
    
  

}

void finish(const char * set_doc = NULL, const char * add_doc = NULL) {

    

  cls_StructArrayPublisher.doc() =
    "NetworkTables struct-encoded value array publisher.";

  cls_StructArrayPublisher
  
    
  .
def
("set", static_cast<void(nt::StructArrayPublisher<T, I>::*)(std::span<const T>, int64_t)>(
        &nt::StructArrayPublisher<T, I>::Set),
      py::arg("value"), py::arg("time") = 0, release_gil(), py::doc(
    "Publish a new value.\n"
"\n"
":param value: value to publish\n"
":param time:  timestamp; 0 indicates current NT time should be used")
  )
  
  
  
    
  .
def
("setDefault", static_cast<void(nt::StructArrayPublisher<T, I>::*)(std::span<const T>)>(
        &nt::StructArrayPublisher<T, I>::SetDefault),
      py::arg("value"), release_gil(), py::doc(
    "Publish a default value.\n"
"On reconnect, a default value will never be used in preference to a\n"
"published value.\n"
"\n"
":param value: value")
  )
  
  
  
    
  .
def
("getTopic", &nt::StructArrayPublisher<T, I>::GetTopic, release_gil(), py::doc(
    "Get the corresponding topic.\n"
"\n"
":returns: Topic")
  )
  
  
  .def("close", [](nt::StructArrayPublisher<T, I> *self) {
  py::gil_scoped_release release;
  *self = nt::StructArrayPublisher<T, I>();
}, py::doc("Destroys the publisher"))
.def("__enter__", [](nt::StructArrayPublisher<T, I> *self) {
  return self;
})
.def("__exit__", [](nt::StructArrayPublisher<T, I> *self, py::args args) {
  py::gil_scoped_release release;
  *self = nt::StructArrayPublisher<T, I>();
})
;

  



    if (set_doc) {
        cls_StructArrayPublisher.doc() = set_doc;
    }
    if (add_doc) {
        cls_StructArrayPublisher.doc() = py::cast<std::string>(cls_StructArrayPublisher.doc()) + add_doc;
    }

    
}

}; // struct bind_nt__StructArrayPublisher

}; // namespace rpygen