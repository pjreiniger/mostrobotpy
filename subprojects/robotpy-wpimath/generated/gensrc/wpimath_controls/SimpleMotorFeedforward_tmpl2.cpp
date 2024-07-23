// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/controller/SimpleMotorFeedforward.h>


#include <units_acceleration_type_caster.h>

#include <units_angle_type_caster.h>

#include <units_angular_acceleration_type_caster.h>

#include <units_angular_velocity_type_caster.h>

#include <units_compound_type_caster.h>

#include <units_length_type_caster.h>

#include <units_time_type_caster.h>

#include <units_velocity_type_caster.h>

#include <units_voltage_type_caster.h>








#include <rpygen/frc__SimpleMotorFeedforward.hpp>
#include "SimpleMotorFeedforward_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_frc__SimpleMotorFeedforward<units::radian>;
static std::unique_ptr<BindType> inst;

bind_frc__SimpleMotorFeedforward_1::bind_frc__SimpleMotorFeedforward_1(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_frc__SimpleMotorFeedforward_1::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen
