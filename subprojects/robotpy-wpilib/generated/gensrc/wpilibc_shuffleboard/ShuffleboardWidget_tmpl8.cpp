// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/shuffleboard/ShuffleboardWidget.h>


#include <pybind11/stl.h>








#include <rpygen/frc__ShuffleboardWidget.hpp>
#include "ShuffleboardWidget_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_frc__ShuffleboardWidget<frc::SuppliedValueWidget<std::vector<std::string>>>;
static std::unique_ptr<BindType> inst;

bind_frc__ShuffleboardWidget_7::bind_frc__ShuffleboardWidget_7(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_frc__ShuffleboardWidget_7::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen
