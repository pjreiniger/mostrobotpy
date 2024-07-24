

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/kinematics/Odometry.h>


#include <frc/kinematics/DifferentialDriveWheelPositions.h>

#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>

#include <frc/kinematics/MecanumDriveWheelPositions.h>

#include <frc/kinematics/MecanumDriveWheelSpeeds.h>

#include <frc/kinematics/SwerveDriveKinematics.h>

#include <frc/kinematics/SwerveDriveWheelPositions.h>










namespace rpygen {


using namespace frc;




template <typename WheelSpeeds, typename WheelPositions>
struct bind_frc__Odometry {

    

    
  
  

    

    py::class_<typename frc::Odometry<WheelSpeeds, WheelPositions>> cls_Odometry;

    

    
    

    py::module &m;
    std::string clsName;

bind_frc__Odometry(py::module &m, const char * clsName) :
    
    cls_Odometry(m, clsName),

  

  
  
    m(m),
    clsName(clsName)
{
    
  

}

void finish(const char * set_doc = NULL, const char * add_doc = NULL) {

    

  cls_Odometry.doc() =
    "Class for odometry. Robot code should not use this directly- Instead, use the\n"
"particular type for your drivetrain (e.g., DifferentialDriveOdometry).\n"
"Odometry allows you to track the robot's position on the field over a course\n"
"of a match using readings from your wheel encoders.\n"
"\n"
"Teams can use odometry during the autonomous period for complex tasks like\n"
"path following. Furthermore, odometry can be used for latency compensation\n"
"when using computer-vision systems.\n"
"\n"
"@tparam WheelSpeeds Wheel speeds type.\n"
"@tparam WheelPositions Wheel positions type.";

  cls_Odometry
  
    
  .def(py::init<const Kinematics<WheelSpeeds, WheelPositions>&, const Rotation2d&, const WheelPositions&, const Pose2d&>(),
      py::arg("kinematics"), py::arg("gyroAngle"), py::arg("wheelPositions"), py::arg("initialPose") = Pose2d{}, release_gil()
    , py::keep_alive<1, 2>()
    , py::keep_alive<1, 3>()
    , py::keep_alive<1, 4>()
    , py::keep_alive<1, 5>(), py::doc(
    "Constructs an Odometry object.\n"
"\n"
":param kinematics:     The kinematics for your drivetrain.\n"
":param gyroAngle:      The angle reported by the gyroscope.\n"
":param wheelPositions: The current distances measured by each wheel.\n"
":param initialPose:    The starting position of the robot on the field.")
  )
  
  
  
    
  .
def
("resetPosition", &frc::Odometry<WheelSpeeds, WheelPositions>::ResetPosition,
      py::arg("gyroAngle"), py::arg("wheelPositions"), py::arg("pose"), release_gil(), py::doc(
    "Resets the robot's position on the field.\n"
"\n"
"The gyroscope angle does not need to be reset here on the user's robot\n"
"code. The library automatically takes care of offsetting the gyro angle.\n"
"\n"
":param gyroAngle:      The angle reported by the gyroscope.\n"
":param wheelPositions: The current distances measured by each wheel.\n"
":param pose:           The position on the field that your robot is at.")
  )
  
  
  
    
  .
def
("getPose", &frc::Odometry<WheelSpeeds, WheelPositions>::GetPose, release_gil(), py::doc(
    "Returns the position of the robot on the field.\n"
"\n"
":returns: The pose of the robot.")
  )
  
  
  
    
  .
def
("update", &frc::Odometry<WheelSpeeds, WheelPositions>::Update,
      py::arg("gyroAngle"), py::arg("wheelPositions"), release_gil(), py::doc(
    "Updates the robot's position on the field using forward kinematics and\n"
"integration of the pose over time. This method takes in an angle parameter\n"
"which is used instead of the angular rate that is calculated from forward\n"
"kinematics, in addition to the current distance measurement at each wheel.\n"
"\n"
":param gyroAngle:      The angle reported by the gyroscope.\n"
":param wheelPositions: The current distances measured by each wheel.\n"
"\n"
":returns: The new pose of the robot.")
  )
  
  
  ;

  



    if (set_doc) {
        cls_Odometry.doc() = set_doc;
    }
    if (add_doc) {
        cls_Odometry.doc() = py::cast<std::string>(cls_Odometry.doc()) + add_doc;
    }

    
}

}; // struct bind_frc__Odometry

}; // namespace rpygen