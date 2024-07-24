// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/estimator/PoseEstimator.h>


#include <units_time_type_caster.h>

#include <wpi_array_type_caster.h>








#include <rpygen/frc__PoseEstimator.hpp>
#include "PoseEstimator_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_frc__PoseEstimator<frc::SwerveDriveWheelSpeeds<3>, frc::SwerveDriveWheelPositions<3>>;
static std::unique_ptr<BindType> inst;

bind_frc__PoseEstimator_3::bind_frc__PoseEstimator_3(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_frc__PoseEstimator_3::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen