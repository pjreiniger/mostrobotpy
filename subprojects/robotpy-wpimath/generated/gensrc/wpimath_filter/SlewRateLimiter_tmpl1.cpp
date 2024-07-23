// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/filter/SlewRateLimiter.h>


#include <units_compound_type_caster.h>

#include <units_misc_type_caster.h>

#include <units_time_type_caster.h>








#include <rpygen/frc__SlewRateLimiter.hpp>
#include "SlewRateLimiter_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_frc__SlewRateLimiter<units::dimensionless::scalar>;
static std::unique_ptr<BindType> inst;

bind_frc__SlewRateLimiter_0::bind_frc__SlewRateLimiter_0(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_frc__SlewRateLimiter_0::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen
