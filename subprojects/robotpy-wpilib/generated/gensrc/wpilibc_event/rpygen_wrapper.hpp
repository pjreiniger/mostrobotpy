// This file is autogenerated, DO NOT EDIT
#pragma once
#include <robotpy_build.h>

// forward declarations
void begin_init_BooleanEvent(py::module &m);
void finish_init_BooleanEvent();
void begin_init_EventLoop(py::module &m);
void finish_init_EventLoop();
void begin_init_NetworkBooleanEvent(py::module &m);
void finish_init_NetworkBooleanEvent();

static void initWrapper(py::module &m) {
    begin_init_BooleanEvent(m);
    begin_init_EventLoop(m);
    begin_init_NetworkBooleanEvent(m);

    finish_init_BooleanEvent();
    finish_init_EventLoop();
    finish_init_NetworkBooleanEvent();
}