// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <networktables/StructArrayTopic.h>


#include <pybind11/stl.h>

#include <wpi_json_type_caster.h>

#include <wpi_span_type_caster.h>

#include <wpystruct.h>







#define RPYGEN_ENABLE_nt__StructArraySubscriber_PROTECTED_CONSTRUCTORS
#include <rpygen/nt__StructArraySubscriber.hpp>

#define RPYGEN_ENABLE_nt__StructArrayPublisher_PROTECTED_CONSTRUCTORS
#include <rpygen/nt__StructArrayPublisher.hpp>


#include <rpygen/nt__StructArrayTopic.hpp>
#include "StructArrayTopic_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_nt__StructArrayTopic<WPyStruct, WPyStructInfo>;
static std::unique_ptr<BindType> inst;

bind_nt__StructArrayTopic_3::bind_nt__StructArrayTopic_3(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_nt__StructArrayTopic_3::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen