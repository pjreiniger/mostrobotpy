// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/trajectory/ExponentialProfile.h>


#include <units_compound_type_caster.h>

#include <units_length_type_caster.h>

#include <units_time_type_caster.h>

#include <units_velocity_type_caster.h>

#include <units_voltage_type_caster.h>



#include <pybind11/operators.h>






#include <rpygen/frc__ExponentialProfile.hpp>
#include "ExponentialProfile_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_frc__ExponentialProfile<units::meter, units::volt>;
static std::unique_ptr<BindType> inst;

bind_frc__ExponentialProfile_0::bind_frc__ExponentialProfile_0(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_frc__ExponentialProfile_0::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen
