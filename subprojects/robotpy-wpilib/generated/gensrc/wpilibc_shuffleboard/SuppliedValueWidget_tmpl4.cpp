// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/shuffleboard/SuppliedValueWidget.h>


#include <pybind11/stl.h>








#include <rpygen/frc__SuppliedValueWidget.hpp>
#include "SuppliedValueWidget_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_frc__SuppliedValueWidget<int64_t>;
static std::unique_ptr<BindType> inst;

bind_frc__SuppliedValueWidget_3::bind_frc__SuppliedValueWidget_3(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_frc__SuppliedValueWidget_3::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen
