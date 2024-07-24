

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/estimator/PoseEstimator.h>


#include <frc/kinematics/DifferentialDriveWheelPositions.h>

#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>

#include <frc/kinematics/MecanumDriveWheelPositions.h>

#include <frc/kinematics/MecanumDriveWheelSpeeds.h>

#include <frc/kinematics/SwerveDriveKinematics.h>

#include <frc/kinematics/SwerveDriveWheelPositions.h>









#include <units_time_type_caster.h>

#include <wpi_array_type_caster.h>


namespace rpygen {


using namespace frc;




template <typename WheelSpeeds, typename WheelPositions>
struct bind_frc__PoseEstimator {

    

    
  
  

    

    py::class_<typename frc::PoseEstimator<WheelSpeeds, WheelPositions>> cls_PoseEstimator;

    

    
    

    py::module &m;
    std::string clsName;

bind_frc__PoseEstimator(py::module &m, const char * clsName) :
    
    cls_PoseEstimator(m, clsName),

  

  
  
    m(m),
    clsName(clsName)
{
    
  

}

void finish(const char * set_doc = NULL, const char * add_doc = NULL) {

    

  cls_PoseEstimator.doc() =
    "This class wraps odometry to fuse latency-compensated\n"
"vision measurements with encoder measurements. Robot code should not use this\n"
"directly- Instead, use the particular type for your drivetrain (e.g.,\n"
"DifferentialDrivePoseEstimator). It will correct for noisy vision\n"
"measurements and encoder drift. It is intended to be an easy drop-in for\n"
"Odometry.\n"
"\n"
"Update() should be called every robot loop.\n"
"\n"
"AddVisionMeasurement() can be called as infrequently as you want; if you\n"
"never call it, then this class will behave like regular encoder odometry.\n"
"\n"
"@tparam WheelSpeeds Wheel speeds type.\n"
"@tparam WheelPositions Wheel positions type.";

  cls_PoseEstimator
  
    
  .def(py::init<Kinematics<WheelSpeeds, WheelPositions>&, Odometry<WheelSpeeds, WheelPositions>&, const wpi::array<double, 3>&, const wpi::array<double, 3>&>(),
      py::arg("kinematics"), py::arg("odometry"), py::arg("stateStdDevs"), py::arg("visionMeasurementStdDevs"), release_gil()
    , py::keep_alive<1, 2>()
    , py::keep_alive<1, 3>()
    , py::keep_alive<1, 4>()
    , py::keep_alive<1, 5>(), py::doc(
    "Constructs a PoseEstimator.\n"
"\n"
":param kinematics:               A correctly-configured kinematics object for your\n"
"                                 drivetrain.\n"
":param odometry:                 A correctly-configured odometry object for your drivetrain.\n"
":param stateStdDevs:             Standard deviations of the pose estimate (x position in\n"
"                                 meters, y position in meters, and heading in radians). Increase these\n"
"                                 numbers to trust your state estimate less.\n"
":param visionMeasurementStdDevs: Standard deviations of the vision pose\n"
"                                 measurement (x position in meters, y position in meters, and heading in\n"
"                                 radians). Increase these numbers to trust the vision pose measurement\n"
"                                 less.")
  )
  
  
  
    
  .
def
("setVisionMeasurementStdDevs", &frc::PoseEstimator<WheelSpeeds, WheelPositions>::SetVisionMeasurementStdDevs,
      py::arg("visionMeasurementStdDevs"), release_gil(), py::doc(
    "Sets the pose estimator's trust in vision measurements. This might be used\n"
"to change trust in vision measurements after the autonomous period, or to\n"
"change trust as distance to a vision target increases.\n"
"\n"
":param visionMeasurementStdDevs: Standard deviations of the vision pose\n"
"                                 measurement (x position in meters, y position in meters, and heading in\n"
"                                 radians). Increase these numbers to trust the vision pose measurement\n"
"                                 less.")
  )
  
  
  
    
  .
def
("resetPosition", &frc::PoseEstimator<WheelSpeeds, WheelPositions>::ResetPosition,
      py::arg("gyroAngle"), py::arg("wheelPositions"), py::arg("pose"), release_gil(), py::doc(
    "Resets the robot's position on the field.\n"
"\n"
"The gyroscope angle does not need to be reset in the user's robot code.\n"
"The library automatically takes care of offsetting the gyro angle.\n"
"\n"
":param gyroAngle:      The current gyro angle.\n"
":param wheelPositions: The distances traveled by the encoders.\n"
":param pose:           The estimated pose of the robot on the field.")
  )
  
  
  
    
  .
def
("getEstimatedPosition", &frc::PoseEstimator<WheelSpeeds, WheelPositions>::GetEstimatedPosition, release_gil(), py::doc(
    "Gets the estimated robot pose.\n"
"\n"
":returns: The estimated robot pose in meters.")
  )
  
  
  
    
  .
def
("addVisionMeasurement", static_cast<void(frc::PoseEstimator<WheelSpeeds, WheelPositions>::*)(const Pose2d&, units::second_t)>(
        &frc::PoseEstimator<WheelSpeeds, WheelPositions>::AddVisionMeasurement),
      py::arg("visionRobotPose"), py::arg("timestamp"), release_gil(), py::doc(
    "Adds a vision measurement to the Kalman Filter. This will correct\n"
"the odometry pose estimate while still accounting for measurement noise.\n"
"\n"
"This method can be called as infrequently as you want, as long as you are\n"
"calling Update() every loop.\n"
"\n"
"To promote stability of the pose estimate and make it robust to bad vision\n"
"data, we recommend only adding vision measurements that are already within\n"
"one meter or so of the current pose estimate.\n"
"\n"
":param visionRobotPose: The pose of the robot as measured by the vision\n"
"                        camera.\n"
":param timestamp:       The timestamp of the vision measurement in seconds. Note\n"
"                        that if you don't use your own time source by calling UpdateWithTime(),\n"
"                        then you must use a timestamp with an epoch since FPGA startup (i.e.,\n"
"                        the epoch of this timestamp is the same epoch as\n"
"                        frc::Timer::GetFPGATimestamp(). This means that you should use\n"
"                        frc::Timer::GetFPGATimestamp() as your time source in this case.")
  )
  
  
  
    
  .
def
("addVisionMeasurement", static_cast<void(frc::PoseEstimator<WheelSpeeds, WheelPositions>::*)(const Pose2d&, units::second_t, const wpi::array<double, 3>&)>(
        &frc::PoseEstimator<WheelSpeeds, WheelPositions>::AddVisionMeasurement),
      py::arg("visionRobotPose"), py::arg("timestamp"), py::arg("visionMeasurementStdDevs"), release_gil(), py::doc(
    "Adds a vision measurement to the Kalman Filter. This will correct\n"
"the odometry pose estimate while still accounting for measurement noise.\n"
"\n"
"This method can be called as infrequently as you want, as long as you are\n"
"calling Update() every loop.\n"
"\n"
"To promote stability of the pose estimate and make it robust to bad vision\n"
"data, we recommend only adding vision measurements that are already within\n"
"one meter or so of the current pose estimate.\n"
"\n"
"Note that the vision measurement standard deviations passed into this\n"
"method will continue to apply to future measurements until a subsequent\n"
"call to SetVisionMeasurementStdDevs() or this method.\n"
"\n"
":param visionRobotPose:          The pose of the robot as measured by the vision\n"
"                                 camera.\n"
":param timestamp:                The timestamp of the vision measurement in seconds. Note\n"
"                                 that if you don't use your own time source by calling UpdateWithTime(),\n"
"                                 then you must use a timestamp with an epoch since FPGA startup (i.e.,\n"
"                                 the epoch of this timestamp is the same epoch as\n"
"                                 frc::Timer::GetFPGATimestamp(). This means that you should use\n"
"                                 frc::Timer::GetFPGATimestamp() as your time source in this case.\n"
":param visionMeasurementStdDevs: Standard deviations of the vision pose\n"
"                                 measurement (x position in meters, y position in meters, and heading in\n"
"                                 radians). Increase these numbers to trust the vision pose measurement\n"
"                                 less.")
  )
  
  
  
    
  .
def
("update", &frc::PoseEstimator<WheelSpeeds, WheelPositions>::Update,
      py::arg("gyroAngle"), py::arg("wheelPositions"), release_gil(), py::doc(
    "Updates the pose estimator with wheel encoder and gyro information. This\n"
"should be called every loop.\n"
"\n"
":param gyroAngle:      The current gyro angle.\n"
":param wheelPositions: The distances traveled by the encoders.\n"
"\n"
":returns: The estimated pose of the robot in meters.")
  )
  
  
  
    
  .
def
("updateWithTime", &frc::PoseEstimator<WheelSpeeds, WheelPositions>::UpdateWithTime,
      py::arg("currentTime"), py::arg("gyroAngle"), py::arg("wheelPositions"), release_gil(), py::doc(
    "Updates the pose estimator with wheel encoder and gyro information. This\n"
"should be called every loop.\n"
"\n"
":param currentTime:    The time at which this method was called.\n"
":param gyroAngle:      The current gyro angle.\n"
":param wheelPositions: The distances traveled by the encoders.\n"
"\n"
":returns: The estimated pose of the robot in meters.")
  )
  
  
  ;

  



    if (set_doc) {
        cls_PoseEstimator.doc() = set_doc;
    }
    if (add_doc) {
        cls_PoseEstimator.doc() = py::cast<std::string>(cls_PoseEstimator.doc()) + add_doc;
    }

    
}

}; // struct bind_frc__PoseEstimator

}; // namespace rpygen