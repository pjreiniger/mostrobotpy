// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/shuffleboard/ShuffleboardComponent.h>


#include <pybind11/stl.h>

#include <wpi_string_map_caster.h>








#include <rpygen/frc__ShuffleboardComponent.hpp>
#include "ShuffleboardComponent_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_frc__ShuffleboardComponent<frc::SuppliedValueWidget<double>>;
static std::unique_ptr<BindType> inst;

bind_frc__ShuffleboardComponent_4::bind_frc__ShuffleboardComponent_4(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_frc__ShuffleboardComponent_4::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen
