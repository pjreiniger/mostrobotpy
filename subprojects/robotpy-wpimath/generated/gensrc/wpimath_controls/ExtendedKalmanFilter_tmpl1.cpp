// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/estimator/ExtendedKalmanFilter.h>


#include <pybind11/eigen.h>

#include <pybind11/functional.h>

#include <units_time_type_caster.h>

#include <wpi_array_type_caster.h>








#include <rpygen/frc__ExtendedKalmanFilter.hpp>
#include "ExtendedKalmanFilter_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_frc__ExtendedKalmanFilter<1, 1, 1>;
static std::unique_ptr<BindType> inst;

bind_frc__ExtendedKalmanFilter_0::bind_frc__ExtendedKalmanFilter_0(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_frc__ExtendedKalmanFilter_0::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen
