
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <networktables/DoubleArrayTopic.h>


#include <pybind11/stl.h>

#include <wpi_json_type_caster.h>

#include <wpi_span_type_caster.h>







#define RPYGEN_ENABLE_nt__DoubleArraySubscriber_PROTECTED_CONSTRUCTORS
#include <rpygen/nt__DoubleArraySubscriber.hpp>

#define RPYGEN_ENABLE_nt__DoubleArrayPublisher_PROTECTED_CONSTRUCTORS
#include <rpygen/nt__DoubleArrayPublisher.hpp>









#include <type_traits>


  using namespace wpi;

  using namespace nt;





struct rpybuild_DoubleArrayTopic_initializer {


  

  


  

  


  

  


  

  












  
  using DoubleArraySubscriber_Trampoline = rpygen::PyTrampoline_nt__DoubleArraySubscriber<typename nt::DoubleArraySubscriber, typename rpygen::PyTrampolineCfg_nt__DoubleArraySubscriber<>>;
    static_assert(std::is_abstract<DoubleArraySubscriber_Trampoline>::value == false, "nt::DoubleArraySubscriber " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename nt::DoubleArraySubscriber, DoubleArraySubscriber_Trampoline, nt::Subscriber> cls_DoubleArraySubscriber;

    

    
    
  
  using DoubleArrayPublisher_Trampoline = rpygen::PyTrampoline_nt__DoubleArrayPublisher<typename nt::DoubleArrayPublisher, typename rpygen::PyTrampolineCfg_nt__DoubleArrayPublisher<>>;
    static_assert(std::is_abstract<DoubleArrayPublisher_Trampoline>::value == false, "nt::DoubleArrayPublisher " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename nt::DoubleArrayPublisher, DoubleArrayPublisher_Trampoline, nt::Publisher> cls_DoubleArrayPublisher;

    

    
    
  py::class_<typename nt::DoubleArrayEntry, nt::DoubleArraySubscriber, nt::DoubleArrayPublisher> cls_DoubleArrayEntry;

    

    
    
  py::class_<typename nt::DoubleArrayTopic, nt::Topic> cls_DoubleArrayTopic;

    

    
    

  py::module &m;

  
  rpybuild_DoubleArrayTopic_initializer(py::module &m) :

  

  

  

  
    cls_DoubleArraySubscriber(m, "DoubleArraySubscriber"),

  

  
  
  
    cls_DoubleArrayPublisher(m, "DoubleArrayPublisher"),

  

  
  
  
    cls_DoubleArrayEntry(m, "DoubleArrayEntry", py::is_final()),

  

  
  
  
    cls_DoubleArrayTopic(m, "DoubleArrayTopic", py::is_final()),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
    
  

    
    
    
  

    
    
    
  

    
    
  }

void finish() {





  {
  
  
  
    using TopicType [[maybe_unused]] = typename nt::DoubleArraySubscriber::TopicType;
  
    using ValueType [[maybe_unused]] = typename nt::DoubleArraySubscriber::ValueType;
  
    using ParamType [[maybe_unused]] = typename nt::DoubleArraySubscriber::ParamType;
  
    using TimestampedValueType [[maybe_unused]] = typename nt::DoubleArraySubscriber::TimestampedValueType;
  
    using SmallRetType [[maybe_unused]] = typename nt::DoubleArraySubscriber::SmallRetType;
  
    using SmallElemType [[maybe_unused]] = typename nt::DoubleArraySubscriber::SmallElemType;
  
    using TimestampedValueViewType [[maybe_unused]] = typename nt::DoubleArraySubscriber::TimestampedValueViewType;
  


  

  cls_DoubleArraySubscriber.doc() =
    "NetworkTables DoubleArray subscriber.";

  cls_DoubleArraySubscriber
  
    
  .
def
("get", static_cast<ValueType(nt::DoubleArraySubscriber::*)() const>(
        &nt::DoubleArraySubscriber::Get), release_gil(), py::doc(
    "Get the last published value.\n"
"If no value has been published, returns the stored default value.\n"
"\n"
":returns: value")
  )
  
  
  
    
  .
def
("get", static_cast<ValueType(nt::DoubleArraySubscriber::*)(ParamType) const>(
        &nt::DoubleArraySubscriber::Get),
      py::arg("defaultValue"), release_gil(), py::doc(
    "Get the last published value.\n"
"If no value has been published, returns the passed defaultValue.\n"
"\n"
":param defaultValue: default value to return if no value has been published\n"
"\n"
":returns: value")
  )
  
  
  
    
  .
def
("getAtomic", static_cast<TimestampedValueType(nt::DoubleArraySubscriber::*)() const>(
        &nt::DoubleArraySubscriber::GetAtomic), release_gil(), py::doc(
    "Get the last published value along with its timestamp\n"
"If no value has been published, returns the stored default value and a\n"
"timestamp of 0.\n"
"\n"
":returns: timestamped value")
  )
  
  
  
    
  .
def
("getAtomic", static_cast<TimestampedValueType(nt::DoubleArraySubscriber::*)(ParamType) const>(
        &nt::DoubleArraySubscriber::GetAtomic),
      py::arg("defaultValue"), release_gil(), py::doc(
    "Get the last published value along with its timestamp.\n"
"If no value has been published, returns the passed defaultValue and a\n"
"timestamp of 0.\n"
"\n"
":param defaultValue: default value to return if no value has been published\n"
"\n"
":returns: timestamped value")
  )
  
  
  
    
  .
def
("readQueue", &nt::DoubleArraySubscriber::ReadQueue, release_gil(), py::doc(
    "Get an array of all value changes since the last call to ReadQueue.\n"
"Also provides a timestamp for each value.\n"
"\n"
".. note:: The \"poll storage\" subscribe option can be used to set the queue\n"
"   depth.\n"
"\n"
":returns: Array of timestamped values; empty array if no new changes have\n"
"          been published since the previous call.")
  )
  
  
  
    
  .
def
("getTopic", &nt::DoubleArraySubscriber::GetTopic, release_gil(), py::doc(
    "Get the corresponding topic.\n"
"\n"
":returns: Topic")
  )
  
  
  .def("close", [](DoubleArraySubscriber *self) {
  py::gil_scoped_release release;
  *self = DoubleArraySubscriber();
}, py::doc("Destroys the subscriber"))
.def("__enter__", [](DoubleArraySubscriber *self) {
  return self;
})
.def("__exit__", [](DoubleArraySubscriber *self, py::args args) {
  py::gil_scoped_release release;
  *self = DoubleArraySubscriber();
})
;

  


  }

  {
  
  
  
    using TopicType [[maybe_unused]] = typename nt::DoubleArrayPublisher::TopicType;
  
    using ValueType [[maybe_unused]] = typename nt::DoubleArrayPublisher::ValueType;
  
    using ParamType [[maybe_unused]] = typename nt::DoubleArrayPublisher::ParamType;
  
    using SmallRetType [[maybe_unused]] = typename nt::DoubleArrayPublisher::SmallRetType;
  
    using SmallElemType [[maybe_unused]] = typename nt::DoubleArrayPublisher::SmallElemType;
  
    using TimestampedValueType [[maybe_unused]] = typename nt::DoubleArrayPublisher::TimestampedValueType;
  


  

  cls_DoubleArrayPublisher.doc() =
    "NetworkTables DoubleArray publisher.";

  cls_DoubleArrayPublisher
  
    
  .
def
("set", &nt::DoubleArrayPublisher::Set,
      py::arg("value"), py::arg("time") = 0, release_gil(), py::doc(
    "Publish a new value.\n"
"\n"
":param value: value to publish\n"
":param time:  timestamp; 0 indicates current NT time should be used")
  )
  
  
  
    
  .
def
("setDefault", &nt::DoubleArrayPublisher::SetDefault,
      py::arg("value"), release_gil(), py::doc(
    "Publish a default value.\n"
"On reconnect, a default value will never be used in preference to a\n"
"published value.\n"
"\n"
":param value: value")
  )
  
  
  
    
  .
def
("getTopic", &nt::DoubleArrayPublisher::GetTopic, release_gil(), py::doc(
    "Get the corresponding topic.\n"
"\n"
":returns: Topic")
  )
  
  
  .def("close", [](DoubleArrayPublisher *self) {
  py::gil_scoped_release release;
  *self = DoubleArrayPublisher();
}, py::doc("Destroys the publisher"))
.def("__enter__", [](DoubleArrayPublisher *self) {
  return self;
})
.def("__exit__", [](DoubleArrayPublisher *self, py::args args) {
  py::gil_scoped_release release;
  *self = DoubleArrayPublisher();
})
;

  


  }

  {
  
  
  
    using SubscriberType [[maybe_unused]] = typename nt::DoubleArrayEntry::SubscriberType;
  
    using PublisherType [[maybe_unused]] = typename nt::DoubleArrayEntry::PublisherType;
  
    using TopicType [[maybe_unused]] = typename nt::DoubleArrayEntry::TopicType;
  
    using ValueType [[maybe_unused]] = typename nt::DoubleArrayEntry::ValueType;
  
    using ParamType [[maybe_unused]] = typename nt::DoubleArrayEntry::ParamType;
  
    using SmallRetType [[maybe_unused]] = typename nt::DoubleArrayEntry::SmallRetType;
  
    using SmallElemType [[maybe_unused]] = typename nt::DoubleArrayEntry::SmallElemType;
  
    using TimestampedValueType [[maybe_unused]] = typename nt::DoubleArrayEntry::TimestampedValueType;
  


  

  cls_DoubleArrayEntry.doc() =
    "NetworkTables DoubleArray entry.\n"
"\n"
".. note:: Unlike NetworkTableEntry, the entry goes away when this is destroyed.";

  cls_DoubleArrayEntry
  
    
  .
def
("getTopic", &nt::DoubleArrayEntry::GetTopic, release_gil(), py::doc(
    "Get the corresponding topic.\n"
"\n"
":returns: Topic")
  )
  
  
  
    
  .
def
("unpublish", &nt::DoubleArrayEntry::Unpublish, release_gil(), py::doc(
    "Stops publishing the entry if it's published.")
  )
  
  
  .def("close", [](DoubleArrayEntry *self) {
  py::gil_scoped_release release;
  *self = DoubleArrayEntry();
}, py::doc("Destroys the entry"))
.def("__enter__", [](DoubleArrayEntry *self) {
  return self;
})
.def("__exit__", [](DoubleArrayEntry *self, py::args args) {
  py::gil_scoped_release release;
  *self = DoubleArrayEntry();
})
;

  


  }

  {
  
  
  
    using SubscriberType [[maybe_unused]] = typename nt::DoubleArrayTopic::SubscriberType;
  
    using PublisherType [[maybe_unused]] = typename nt::DoubleArrayTopic::PublisherType;
  
    using EntryType [[maybe_unused]] = typename nt::DoubleArrayTopic::EntryType;
  
    using ValueType [[maybe_unused]] = typename nt::DoubleArrayTopic::ValueType;
  
    using ParamType [[maybe_unused]] = typename nt::DoubleArrayTopic::ParamType;
  
    using TimestampedValueType [[maybe_unused]] = typename nt::DoubleArrayTopic::TimestampedValueType;
  
    static constexpr auto kTypeString [[maybe_unused]] = nt::DoubleArrayTopic::kTypeString;
  


  

  cls_DoubleArrayTopic.doc() =
    "NetworkTables DoubleArray topic.";

  cls_DoubleArrayTopic
  
    
  .def(py::init<Topic>(),
      py::arg("topic"), release_gil(), py::doc(
    "Construct from a generic topic.\n"
"\n"
":param topic: Topic")
  )
  
  
  
    
  .
def
("subscribe", &nt::DoubleArrayTopic::Subscribe,
      py::arg("defaultValue"), py::arg("options") = kDefaultPubSubOptions, release_gil(), py::doc(
    "Create a new subscriber to the topic.\n"
"\n"
"The subscriber is only active as long as the returned object\n"
"is not destroyed.\n"
"\n"
".. note:: Subscribers that do not match the published data type do not return\n"
"   any values. To determine if the data type matches, use the appropriate\n"
"   Topic functions.\n"
"\n"
":param defaultValue: default value used when a default is not provided to a\n"
"                     getter function\n"
":param options:      subscribe options\n"
"\n"
":returns: subscriber")
  )
  
  
  
    
  .
def
("subscribeEx", &nt::DoubleArrayTopic::SubscribeEx,
      py::arg("typeString"), py::arg("defaultValue"), py::arg("options") = kDefaultPubSubOptions, release_gil(), py::doc(
    "Create a new subscriber to the topic, with specific type string.\n"
"\n"
"The subscriber is only active as long as the returned object\n"
"is not destroyed.\n"
"\n"
".. note:: Subscribers that do not match the published data type do not return\n"
"   any values. To determine if the data type matches, use the appropriate\n"
"   Topic functions.\n"
"\n"
":param typeString:   type string\n"
":param defaultValue: default value used when a default is not provided to a\n"
"                     getter function\n"
":param options:      subscribe options\n"
"\n"
":returns: subscriber")
  )
  
  
  
    
  .
def
("publish", &nt::DoubleArrayTopic::Publish,
      py::arg("options") = kDefaultPubSubOptions, release_gil(), py::doc(
    "Create a new publisher to the topic.\n"
"\n"
"The publisher is only active as long as the returned object\n"
"is not destroyed.\n"
"\n"
".. note:: It is not possible to publish two different data types to the same\n"
"   topic. Conflicts between publishers are typically resolved by the\n"
"   server on a first-come, first-served basis. Any published values that\n"
"   do not match the topic's data type are dropped (ignored). To determine\n"
"   if the data type matches, use the appropriate Topic functions.\n"
"\n"
":param options: publish options\n"
"\n"
":returns: publisher")
  )
  
  
  
    
  .
def
("publishEx", &nt::DoubleArrayTopic::PublishEx,
      py::arg("typeString"), py::arg("properties"), py::arg("options") = kDefaultPubSubOptions, release_gil(), py::doc(
    "Create a new publisher to the topic, with type string and initial\n"
"properties.\n"
"\n"
"The publisher is only active as long as the returned object\n"
"is not destroyed.\n"
"\n"
".. note:: It is not possible to publish two different data types to the same\n"
"   topic. Conflicts between publishers are typically resolved by the\n"
"   server on a first-come, first-served basis. Any published values that\n"
"   do not match the topic's data type are dropped (ignored). To determine\n"
"   if the data type matches, use the appropriate Topic functions.\n"
"\n"
":param typeString: type string\n"
":param properties: JSON properties\n"
":param options:    publish options\n"
"\n"
":returns: publisher")
  )
  
  
  
    
  .
def
("getEntry", &nt::DoubleArrayTopic::GetEntry,
      py::arg("defaultValue"), py::arg("options") = kDefaultPubSubOptions, release_gil(), py::doc(
    "Create a new entry for the topic.\n"
"\n"
"Entries act as a combination of a subscriber and a weak publisher. The\n"
"subscriber is active as long as the entry is not destroyed. The publisher\n"
"is created when the entry is first written to, and remains active until\n"
"either Unpublish() is called or the entry is destroyed.\n"
"\n"
".. note:: It is not possible to use two different data types with the same\n"
"   topic. Conflicts between publishers are typically resolved by the\n"
"   server on a first-come, first-served basis. Any published values that\n"
"   do not match the topic's data type are dropped (ignored), and the entry\n"
"   will show no new values if the data type does not match. To determine\n"
"   if the data type matches, use the appropriate Topic functions.\n"
"\n"
":param defaultValue: default value used when a default is not provided to a\n"
"                     getter function\n"
":param options:      publish and/or subscribe options\n"
"\n"
":returns: entry")
  )
  
  
  
    
  .
def
("getEntryEx", &nt::DoubleArrayTopic::GetEntryEx,
      py::arg("typeString"), py::arg("defaultValue"), py::arg("options") = kDefaultPubSubOptions, release_gil(), py::doc(
    "Create a new entry for the topic, with specific type string.\n"
"\n"
"Entries act as a combination of a subscriber and a weak publisher. The\n"
"subscriber is active as long as the entry is not destroyed. The publisher\n"
"is created when the entry is first written to, and remains active until\n"
"either Unpublish() is called or the entry is destroyed.\n"
"\n"
".. note:: It is not possible to use two different data types with the same\n"
"   topic. Conflicts between publishers are typically resolved by the\n"
"   server on a first-come, first-served basis. Any published values that\n"
"   do not match the topic's data type are dropped (ignored), and the entry\n"
"   will show no new values if the data type does not match. To determine\n"
"   if the data type matches, use the appropriate Topic functions.\n"
"\n"
":param typeString:   type string\n"
":param defaultValue: default value used when a default is not provided to a\n"
"                     getter function\n"
":param options:      publish and/or subscribe options\n"
"\n"
":returns: entry")
  )
  
  
  
    .def_readonly_static("kTypeString", &nt::DoubleArrayTopic::kTypeString, py::doc(
    "The default type string for this topic type."))
  .def("close", [](DoubleArrayTopic *self) {
  py::gil_scoped_release release;
  *self = DoubleArrayTopic();
}, py::doc("Destroys the topic"))
.def("__enter__", [](DoubleArrayTopic *self) {
  return self;
})
.def("__exit__", [](DoubleArrayTopic *self, py::args args) {
  py::gil_scoped_release release;
  *self = DoubleArrayTopic();
});

  


  }






}

}; // struct rpybuild_DoubleArrayTopic_initializer

static std::unique_ptr<rpybuild_DoubleArrayTopic_initializer> cls;

void begin_init_DoubleArrayTopic(py::module &m) {
  cls = std::make_unique<rpybuild_DoubleArrayTopic_initializer>(m);
}

void finish_init_DoubleArrayTopic() {
  cls->finish();
  cls.reset();
}