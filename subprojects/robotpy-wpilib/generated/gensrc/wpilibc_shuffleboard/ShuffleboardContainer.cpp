
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/shuffleboard/ShuffleboardContainer.h>


#include <pybind11/functional.h>

#include <pybind11/stl.h>

#include <wpi_span_type_caster.h>













#include <frc/shuffleboard/ComplexWidget.h>

#include <wpi/sendable/Sendable.h>

#include <frc/shuffleboard/ShuffleboardLayout.h>

#include <frc/shuffleboard/SimpleWidget.h>

#include <ShuffleboardData.h>

#include <frc/Errors.h>

#include <wpi/sendable/SendableRegistry.h>



#include <type_traits>


  using namespace cs;

  using namespace wpi;

  using namespace frc;





struct rpybuild_ShuffleboardContainer_initializer {


  

  












  py::class_<typename frc::ShuffleboardContainer, frc::ShuffleboardValue> cls_ShuffleboardContainer;

    

    
    

  py::module &m;

  
  rpybuild_ShuffleboardContainer_initializer(py::module &m) :

  

  

  

  
    cls_ShuffleboardContainer(m, "ShuffleboardContainer"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_ShuffleboardContainer.doc() =
    "Common interface for objects that can contain shuffleboard components.";

  cls_ShuffleboardContainer
  
    
  .
def
("getComponents", &frc::ShuffleboardContainer::GetComponents, release_gil(), py::doc(
    "Gets the components that are direct children of this container.")
  )
  
  
  
    
  .
def
("getLayout", static_cast<ShuffleboardLayout&(frc::ShuffleboardContainer::*)(std::string_view, BuiltInLayouts)>(
        &frc::ShuffleboardContainer::GetLayout),
      py::arg("title"), py::arg("type"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Gets the layout with the given type and title, creating it if it does not\n"
"already exist at the time this method is called.\n"
"\n"
":param title: the title of the layout\n"
":param type:  the type of the layout, eg \"List\" or \"Grid\"\n"
"\n"
":returns: the layout")
  )
  
  
  
    
  .
def
("getLayout", static_cast<ShuffleboardLayout&(frc::ShuffleboardContainer::*)(std::string_view, const LayoutType&)>(
        &frc::ShuffleboardContainer::GetLayout),
      py::arg("title"), py::arg("type"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Gets the layout with the given type and title, creating it if it does not\n"
"already exist at the time this method is called.\n"
"\n"
":param title: the title of the layout\n"
":param type:  the type of the layout, eg \"List\" or \"Grid\"\n"
"\n"
":returns: the layout")
  )
  
  
  
    
  .
def
("getLayout", static_cast<ShuffleboardLayout&(frc::ShuffleboardContainer::*)(std::string_view, std::string_view)>(
        &frc::ShuffleboardContainer::GetLayout),
      py::arg("title"), py::arg("type"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Gets the layout with the given type and title, creating it if it does not\n"
"already exist at the time this method is called. Note: this method should\n"
"only be used to use a layout type that is not already built into\n"
"Shuffleboard. To use a layout built into Shuffleboard, use\n"
"GetLayout(std::string_view, const LayoutType&) and the layouts in\n"
"BuiltInLayouts.\n"
"\n"
":param title: the title of the layout\n"
":param type:  the type of the layout, eg \"List Layout\" or \"Grid Layout\"\n"
"\n"
":returns: the layout\n"
"          @see GetLayout(std::string_view, const LayoutType&)")
  )
  
  
  
    
  .
def
("getLayout", static_cast<ShuffleboardLayout&(frc::ShuffleboardContainer::*)(std::string_view)>(
        &frc::ShuffleboardContainer::GetLayout),
      py::arg("title"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Gets the already-defined layout in this container with the given title.\n"
"\n"
"<pre>{@code\n"
"Shuffleboard::GetTab(\"Example Tab\")->getLayout(\"My Layout\",\n"
"&BuiltInLayouts.kList);\n"
"\n"
"// Later...\n"
"Shuffleboard::GetTab(\"Example Tab\")->GetLayout(\"My Layout\");\n"
"}</pre>\n"
"\n"
":param title: the title of the layout to get\n"
"\n"
":returns: the layout with the given title\n"
"          @throws if no layout has yet been defined with the given title")
  )
  
  
  
    
  .
def
("add", [](ShuffleboardContainer *self, py::str &key, std::shared_ptr<wpi::Sendable> sendable) -> frc::ComplexWidget& {
  if (!sendable) {
    throw FRC_MakeError(err::NullParameter, "{}", "value");
  }

  // convert key to a raw string so that we can create a StringRef
  Py_ssize_t raw_size;
  const char *raw_str = PyUnicode_AsUTF8AndSize(key.ptr(), &raw_size);
  if (raw_str == NULL) {
    throw py::error_already_set();
  }

  std::string_view keyRef(raw_str, raw_size);
  auto &rval = self->Add(keyRef, *sendable);

  // this comes after the Add to ensure that the original object doesn't die
  // while Add is called
  rpy::addShuffleboardData(key, sendable);

  return rval;
}
,
      py::arg("title"), py::arg("defaultValue"), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given sendable.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the sendable to display\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title")
  )
  
  
  
    
  .
def
("add", [](ShuffleboardContainer *self, std::shared_ptr<wpi::Sendable> value) -> frc::ComplexWidget& {
  auto &rval = self->Add(*value);
  // this comes after the PutData to ensure that the original object doesn't die
  // while PutData is called
  auto name = wpi::SendableRegistry::GetName(value.get());
  if (!name.empty()) {
    py::str key(name);
    rpy::addShuffleboardData(key, value);
  }
  return rval;
}
,
      py::arg("defaultValue"), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given sendable.\n"
"\n"
":param defaultValue: the sendable to display\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title, or if the sendable's name has not been\n"
"          specified")
  )
  
  
  
    
  .
def
("add", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, const nt::Value&)>(
        &frc::ShuffleboardContainer::Add),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given data.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title\n"
"          @see AddPersistent(std::string_view, std::shared_ptr<nt::Value>)\n"
"          Add(std::string_view title, std::shared_ptr<nt::Value> defaultValue)")
  )
  
  
  
    
  .
def
("add", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, bool)>(
        &frc::ShuffleboardContainer::Add),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given data.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title\n"
"          @see AddPersistent(std::string_view, bool)\n"
"          Add(std::string_view title, bool defaultValue)")
  )
  
  
  
    
  .
def
("add", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, double)>(
        &frc::ShuffleboardContainer::Add),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given data.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title\n"
"          @see AddPersistent(std::string_view, double)\n"
"          Add(std::string_view title, double defaultValue)")
  )
  
  
  
    
  .
def
("add", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, float)>(
        &frc::ShuffleboardContainer::Add),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given data.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title\n"
"          @see AddPersistent(std::string_view, double)\n"
"          Add(std::string_view title, double defaultValue)")
  )
  
  
  
    
  .
def
("add", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, int)>(
        &frc::ShuffleboardContainer::Add),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given data.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title\n"
"          @see AddPersistent(std::string_view, int)\n"
"          Add(std::string_view title, int defaultValue)")
  )
  
  
  
    
  .
def
("add", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::string_view)>(
        &frc::ShuffleboardContainer::Add),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given data.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title\n"
"          @see AddPersistent(std::string_view, std::string_view)\n"
"          Add(std::string_view title, std::string_view defaultValue)")
  )
  
  
  
    
  .
def
("add", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::span<const bool>)>(
        &frc::ShuffleboardContainer::Add),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given data.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title\n"
"          @see AddPersistent(std::string_view, std::span<const bool>)\n"
"          Add(std::string_view title, std::span<const bool> defaultValue)")
  )
  
  
  
    
  .
def
("add", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::span<const double>)>(
        &frc::ShuffleboardContainer::Add),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given data.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title\n"
"          @see AddPersistent(std::string_view, std::span<const double>)\n"
"          Add(std::string_view title, std::span<const double> defaultValue)")
  )
  
  
  
    
  .
def
("add", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::span<const float>)>(
        &frc::ShuffleboardContainer::Add),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given data.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title\n"
"          @see AddPersistent(std::string_view, std::span<const double>)\n"
"          Add(std::string_view title, std::span<const double> defaultValue)")
  )
  
  
  
    
  .
def
("add", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::span<const int64_t>)>(
        &frc::ShuffleboardContainer::Add),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given data.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title\n"
"          @see AddPersistent(std::string_view, std::span<const double>)\n"
"          Add(std::string_view title, std::span<const double> defaultValue)")
  )
  
  
  
    
  .
def
("add", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::span<const std::string>)>(
        &frc::ShuffleboardContainer::Add),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display the given data.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @throws IllegalArgumentException if a widget already exists in this\n"
"          container with the given title\n"
"          @see AddPersistent(std::string_view, std::span<const std::string>)\n"
"          Add(std::string_view title, std::span<const std::string> defaultValue)")
  )
  
  
  
    
  .
def
("addString", &frc::ShuffleboardContainer::AddString,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addNumber", &frc::ShuffleboardContainer::AddNumber,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addDouble", &frc::ShuffleboardContainer::AddDouble,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addFloat", &frc::ShuffleboardContainer::AddFloat,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addInteger", &frc::ShuffleboardContainer::AddInteger,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addBoolean", &frc::ShuffleboardContainer::AddBoolean,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addStringArray", &frc::ShuffleboardContainer::AddStringArray,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addNumberArray", &frc::ShuffleboardContainer::AddNumberArray,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addDoubleArray", &frc::ShuffleboardContainer::AddDoubleArray,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addFloatArray", &frc::ShuffleboardContainer::AddFloatArray,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addIntegerArray", &frc::ShuffleboardContainer::AddIntegerArray,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addBooleanArray", &frc::ShuffleboardContainer::AddBooleanArray,
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addRaw", static_cast<SuppliedValueWidget<std::vector<uint8_t>>&(frc::ShuffleboardContainer::*)(std::string_view, std::function<std::vector<uint8_t> ()>)>(
        &frc::ShuffleboardContainer::AddRaw),
      py::arg("title"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:    the title of the widget\n"
":param supplier: the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addRaw", static_cast<SuppliedValueWidget<std::vector<uint8_t>>&(frc::ShuffleboardContainer::*)(std::string_view, std::string_view, std::function<std::vector<uint8_t> ()>)>(
        &frc::ShuffleboardContainer::AddRaw),
      py::arg("title"), py::arg("typeString"), py::arg("supplier").none(false), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container. The widget will display the data provided\n"
"by the value supplier. Changes made on the dashboard will not propagate to\n"
"the widget object, and will be overridden by values from the value\n"
"supplier.\n"
"\n"
":param title:      the title of the widget\n"
":param typeString: the NT type string\n"
":param supplier:   the supplier for values\n"
"\n"
":returns: a widget to display data")
  )
  
  
  
    
  .
def
("addPersistent", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, const nt::Value&)>(
        &frc::ShuffleboardContainer::AddPersistent),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display a simple piece of data.\n"
"\n"
"Unlike Add(std::string_view, std::shared_ptr<nt::Value>), the value in the\n"
"widget will be saved on the robot and will be used when the robot program\n"
"next starts rather than ``defaultValue``.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @see Add(stdd::string_view, std::shared_ptr<nt::Value>)\n"
"          Add(std::string_view title, std::shared_ptr<nt::Value> defaultValue)")
  )
  
  
  
    
  .
def
("addPersistent", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, bool)>(
        &frc::ShuffleboardContainer::AddPersistent),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display a simple piece of data.\n"
"\n"
"Unlike Add(std::string_view, bool), the value in the widget will be saved\n"
"on the robot and will be used when the robot program next starts rather\n"
"than ``defaultValue``.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @see Add(std::string_view, bool)\n"
"          Add(std::string_view title, bool defaultValue)")
  )
  
  
  
    
  .
def
("addPersistent", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, double)>(
        &frc::ShuffleboardContainer::AddPersistent),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display a simple piece of data.\n"
"\n"
"Unlike Add(std::string_view, double), the value in the widget will be saved\n"
"on the robot and will be used when the robot program next starts rather\n"
"than ``defaultValue``.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @see Add(std::string_view, double)\n"
"          Add(std::string_view title, double defaultValue)")
  )
  
  
  
    
  .
def
("addPersistent", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, float)>(
        &frc::ShuffleboardContainer::AddPersistent),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display a simple piece of data.\n"
"\n"
"Unlike Add(std::string_view, float), the value in the widget will be saved\n"
"on the robot and will be used when the robot program next starts rather\n"
"than ``defaultValue``.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @see Add(std::string_view, float)\n"
"          Add(std::string_view title, float defaultValue)")
  )
  
  
  
    
  .
def
("addPersistent", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, int)>(
        &frc::ShuffleboardContainer::AddPersistent),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display a simple piece of data.\n"
"\n"
"Unlike Add(std::string_view, int64_t), the value in the widget will be\n"
"saved on the robot and will be used when the robot program next starts\n"
"rather than ``defaultValue``.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @see Add(std:string_view, int64_t)\n"
"          Add(std::string_view title, int64_t defaultValue)")
  )
  
  
  
    
  .
def
("addPersistent", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::string_view)>(
        &frc::ShuffleboardContainer::AddPersistent),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display a simple piece of data.\n"
"\n"
"Unlike Add(std::string_view, std::string_view), the value in the widget\n"
"will be saved on the robot and will be used when the robot program next\n"
"starts rather than ``defaultValue``.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @see Add(std::string_view, std::string_view)\n"
"          Add(std::string_view title, std::string_view defaultValue)")
  )
  
  
  
    
  .
def
("addPersistent", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::span<const bool>)>(
        &frc::ShuffleboardContainer::AddPersistent),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display a simple piece of data.\n"
"\n"
"Unlike Add(std::string_view, std::span<const bool>), the value in the\n"
"widget will be saved on the robot and will be used when the robot program\n"
"next starts rather than ``defaultValue``.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @see Add(std::string_view, std::span<const bool>)\n"
"          Add(std::string_view title, std::span<const bool> defaultValue)")
  )
  
  
  
    
  .
def
("addPersistent", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::span<const double>)>(
        &frc::ShuffleboardContainer::AddPersistent),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display a simple piece of data.\n"
"\n"
"Unlike Add(std::string_view, std::span<const double>), the value in the\n"
"widget will be saved on the robot and will be used when the robot program\n"
"next starts rather than ``defaultValue``.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @see Add(std::string_view, std::span<const double>)\n"
"          Add(std::string_view title, std::span<const double> defaultValue)")
  )
  
  
  
    
  .
def
("addPersistent", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::span<const float>)>(
        &frc::ShuffleboardContainer::AddPersistent),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display a simple piece of data.\n"
"\n"
"Unlike Add(std::string_view, std::span<const float>), the value in the\n"
"widget will be saved on the robot and will be used when the robot program\n"
"next starts rather than ``defaultValue``.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @see Add(std::string_view, std::span<const float>)\n"
"          Add(std::string_view title, std::span<const float> defaultValue)")
  )
  
  
  
    
  .
def
("addPersistent", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::span<const int64_t>)>(
        &frc::ShuffleboardContainer::AddPersistent),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display a simple piece of data.\n"
"\n"
"Unlike Add(std::string_view, std::span<const int64_t>), the value in the\n"
"widget will be saved on the robot and will be used when the robot program\n"
"next starts rather than ``defaultValue``.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @see Add(std::string_view, std::span<const int64_t>)\n"
"          Add(std::string_view title, std::span<const int64_t> defaultValue)")
  )
  
  
  
    
  .
def
("addPersistent", static_cast<SimpleWidget&(frc::ShuffleboardContainer::*)(std::string_view, std::span<const std::string>)>(
        &frc::ShuffleboardContainer::AddPersistent),
      py::arg("title"), py::arg("defaultValue"), release_gil(), py::return_value_policy::reference_internal, py::doc(
    "Adds a widget to this container to display a simple piece of data.\n"
"\n"
"Unlike Add(std::string_view, std::span<const std::string>), the value in\n"
"the widget will be saved on the robot and will be used when the robot\n"
"program next starts rather than ``defaultValue``.\n"
"\n"
":param title:        the title of the widget\n"
":param defaultValue: the default value of the widget\n"
"\n"
":returns: a widget to display the sendable data\n"
"          @see Add(std::string_view, std::span<const std::string>)\n"
"          Add(std::string_view title, std::span<const std::string> defaultValue)")
  )
  
  
  
    
  .
def
("enableIfActuator", &frc::ShuffleboardContainer::EnableIfActuator, release_gil()
  )
  
  
  
    
  .
def
("disableIfActuator", &frc::ShuffleboardContainer::DisableIfActuator, release_gil()
  )
  
  
  ;

  


  }






}

}; // struct rpybuild_ShuffleboardContainer_initializer

static std::unique_ptr<rpybuild_ShuffleboardContainer_initializer> cls;

void begin_init_ShuffleboardContainer(py::module &m) {
  cls = std::make_unique<rpybuild_ShuffleboardContainer_initializer>(m);
}

void finish_init_ShuffleboardContainer() {
  cls->finish();
  cls.reset();
}