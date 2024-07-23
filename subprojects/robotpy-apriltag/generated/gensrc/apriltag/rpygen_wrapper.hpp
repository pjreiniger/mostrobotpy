// This file is autogenerated, DO NOT EDIT
#pragma once
#include <robotpy_build.h>

// forward declarations
void begin_init_AprilTagFields(py::module &m);
void finish_init_AprilTagFields();
void begin_init_AprilTag(py::module &m);
void finish_init_AprilTag();
void begin_init_AprilTagDetection(py::module &m);
void finish_init_AprilTagDetection();
void begin_init_AprilTagDetector(py::module &m);
void finish_init_AprilTagDetector();
void begin_init_AprilTagFieldLayout(py::module &m);
void finish_init_AprilTagFieldLayout();
void begin_init_AprilTagPoseEstimate(py::module &m);
void finish_init_AprilTagPoseEstimate();
void begin_init_AprilTagPoseEstimator(py::module &m);
void finish_init_AprilTagPoseEstimator();

static void initWrapper(py::module &m) {
    begin_init_AprilTagFields(m);
    begin_init_AprilTag(m);
    begin_init_AprilTagDetection(m);
    begin_init_AprilTagDetector(m);
    begin_init_AprilTagFieldLayout(m);
    begin_init_AprilTagPoseEstimate(m);
    begin_init_AprilTagPoseEstimator(m);

    finish_init_AprilTagFields();
    finish_init_AprilTag();
    finish_init_AprilTagDetection();
    finish_init_AprilTagDetector();
    finish_init_AprilTagFieldLayout();
    finish_init_AprilTagPoseEstimate();
    finish_init_AprilTagPoseEstimator();
}