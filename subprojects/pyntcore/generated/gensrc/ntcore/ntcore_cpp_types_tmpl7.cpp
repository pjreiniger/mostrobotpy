// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <ntcore_cpp_types.h>


#include <pybind11/stl.h>

#include <wpi_span_type_caster.h>

#include <wpystruct.h>








#include <rpygen/nt__Timestamped.hpp>
#include "ntcore_cpp_types_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_nt__Timestamped<std::vector<int>>;
static std::unique_ptr<BindType> inst;

bind_nt__Timestamped_6::bind_nt__Timestamped_6(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_nt__Timestamped_6::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen
