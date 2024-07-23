// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/kinematics/Kinematics.h>


#include <wpi_array_type_caster.h>







#define RPYGEN_ENABLE_frc__Kinematics_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__Kinematics.hpp>


#include <rpygen/frc__Kinematics.hpp>
#include "Kinematics_tmpl.hpp"

namespace rpygen {

using BindType = rpygen::bind_frc__Kinematics<frc::MecanumDriveWheelSpeeds, frc::MecanumDriveWheelPositions>;
static std::unique_ptr<BindType> inst;

bind_frc__Kinematics_1::bind_frc__Kinematics_1(py::module &m, const char * clsName)
{
    inst = std::make_unique<BindType>(m, clsName);
}

void bind_frc__Kinematics_1::finish(const char *set_doc, const char *add_doc)
{
    inst->finish(set_doc, add_doc);
    inst.reset();
}

}; // namespace rpygen
