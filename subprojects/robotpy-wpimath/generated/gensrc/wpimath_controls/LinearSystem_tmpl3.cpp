// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/system/LinearSystem.h>


#include <pybind11/eigen.h>

#include <units_time_type_caster.h>








#include <rpygen/frc__LinearSystem.hpp>
#include "LinearSystem_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_frc__LinearSystem<1, 1, 3>;
static std::unique_ptr<BindType> inst;

bind_frc__LinearSystem_2::bind_frc__LinearSystem_2(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_frc__LinearSystem_2::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen
