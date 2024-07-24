

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/simulation/LinearSystemSim.h>










namespace rpygen {


using namespace frc::sim;





template <int States, int Inputs, int Outputs, typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__sim__LinearSystemSim :

    CfgBase

{
    using Base = frc::sim::LinearSystemSim<States, Inputs, Outputs>;

    
    
    using override_base_KGetCurrentDraw_v = frc::sim::LinearSystemSim<States, Inputs, Outputs>;
    
    using override_base_UpdateX_KRTVectord_KRTVectord_Tsecond_t = frc::sim::LinearSystemSim<States, Inputs, Outputs>;
    
};



template <typename PyTrampolineBase, int States, int Inputs, int Outputs, typename PyTrampolineCfg>
struct PyTrampoline_frc__sim__LinearSystemSim : PyTrampolineBase, virtual py::trampoline_self_life_support {
    using PyTrampolineBase::PyTrampolineBase;





    template <int S, int I, int O> using LinearSystem = frc::LinearSystem<S, I, O>;

    template <int I> using Vectord = frc::Vectord<I>;







    
    
#ifndef RPYGEN_DISABLE_KGetCurrentDraw_v
    units::ampere_t GetCurrentDraw() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetCurrentDraw_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(units::ampere_t), LookupBase,
            "getCurrentDraw", );
        return CxxCallBase::GetCurrentDraw();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_UpdateX_KRTVectord_KRTVectord_Tsecond_t
    Vectord<States> UpdateX(const Vectord<States>& currentXhat, const Vectord<Inputs>& u, units::second_t dt) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_UpdateX_KRTVectord_KRTVectord_Tsecond_t;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(Vectord<States>), LookupBase,
            "_updateX", currentXhat, u, dt);
        return CxxCallBase::UpdateX(std::forward<decltype(currentXhat)>(currentXhat), std::forward<decltype(u)>(u), std::move(dt));
    
    
    
    }
#endif

    

    
    
#ifndef RPYBLD_DISABLE_ClampInput_TVectord

  #ifndef RPYBLD_UDISABLE_frc__sim__LinearSystemSim_ClampInput
    using frc::sim::LinearSystemSim<States, Inputs, Outputs>::ClampInput;
    #define RPYBLD_UDISABLE_frc__sim__LinearSystemSim_ClampInput
  #endif
#endif
    

    
    using frc::sim::LinearSystemSim<States, Inputs, Outputs>::m_plant;
    
    using frc::sim::LinearSystemSim<States, Inputs, Outputs>::m_x;
    
    using frc::sim::LinearSystemSim<States, Inputs, Outputs>::m_u;
    
    using frc::sim::LinearSystemSim<States, Inputs, Outputs>::m_y;
    
    using frc::sim::LinearSystemSim<States, Inputs, Outputs>::m_measurementStdDevs;
    

    
};

}; // namespace rpygen







#include <pybind11/eigen.h>

#include <pybind11/stl.h>

#include <units_current_type_caster.h>

#include <units_time_type_caster.h>


namespace rpygen {


using namespace frc::sim;




template <int States, int Inputs, int Outputs>
struct bind_frc__sim__LinearSystemSim {

    
    template <int S, int I, int O> using LinearSystem = frc::LinearSystem<S, I, O>;
  
    template <int I> using Vectord = frc::Vectord<I>;
  

    
  
  

    

    
  using LinearSystemSim_Trampoline = rpygen::PyTrampoline_frc__sim__LinearSystemSim<typename frc::sim::LinearSystemSim<States, Inputs, Outputs>, States, Inputs, Outputs, typename rpygen::PyTrampolineCfg_frc__sim__LinearSystemSim<States, Inputs, Outputs>>;
    static_assert(std::is_abstract<LinearSystemSim_Trampoline>::value == false, "frc::sim::LinearSystemSim<States, Inputs, Outputs> " RPYBUILD_BAD_TRAMPOLINE);
  py::class_<typename frc::sim::LinearSystemSim<States, Inputs, Outputs>, LinearSystemSim_Trampoline> cls_LinearSystemSim;

    

    
    

    py::module &m;
    std::string clsName;

bind_frc__sim__LinearSystemSim(py::module &m, const char * clsName) :
    
    cls_LinearSystemSim(m, clsName),

  

  
  
    m(m),
    clsName(clsName)
{
    
  

}

void finish(const char * set_doc = NULL, const char * add_doc = NULL) {

    

  cls_LinearSystemSim.doc() =
    "This class helps simulate linear systems. To use this class, do the following\n"
"in the simulationPeriodic() method.\n"
"\n"
"Call the SetInput() method with the inputs to your system (generally\n"
"voltage). Call the Update() method to update the simulation. Set simulated\n"
"sensor readings with the simulated positions in the GetOutput() method.\n"
"\n"
"@tparam States  Number of states of the system.\n"
"@tparam Inputs  Number of inputs to the system.\n"
"@tparam Outputs Number of outputs of the system.";

  cls_LinearSystemSim
  
    
  .def(py::init<const LinearSystem<States, Inputs, Outputs>&, const std::array<double, Outputs>&>(),
      py::arg("system"), py::arg("measurementStdDevs") = std::array<double, Outputs>{}, release_gil()
    , py::keep_alive<1, 2>()
    , py::keep_alive<1, 3>(), py::doc(
    "Creates a simulated generic linear system.\n"
"\n"
":param system:             The system to simulate.\n"
":param measurementStdDevs: The standard deviations of the measurements.")
  )
  
  
  
    
  .
def
("update", &frc::sim::LinearSystemSim<States, Inputs, Outputs>::Update,
      py::arg("dt"), release_gil(), py::doc(
    "Updates the simulation.\n"
"\n"
":param dt: The time between updates.")
  )
  
  
  
    
  .
def
("getOutput", static_cast<const Vectord<Outputs>&(frc::sim::LinearSystemSim<States, Inputs, Outputs>::*)() const>(
        &frc::sim::LinearSystemSim<States, Inputs, Outputs>::GetOutput), release_gil(), py::doc(
    "Returns the current output of the plant.\n"
"\n"
":returns: The current output of the plant.")
  )
  
  
  
    
  .
def
("getOutput", static_cast<double(frc::sim::LinearSystemSim<States, Inputs, Outputs>::*)(int) const>(
        &frc::sim::LinearSystemSim<States, Inputs, Outputs>::GetOutput),
      py::arg("row"), release_gil(), py::doc(
    "Returns an element of the current output of the plant.\n"
"\n"
":param row: The row to return.\n"
"\n"
":returns: An element of the current output of the plant.")
  )
  
  
  
    
  .
def
("setInput", static_cast<void(frc::sim::LinearSystemSim<States, Inputs, Outputs>::*)(const Vectord<Inputs>&)>(
        &frc::sim::LinearSystemSim<States, Inputs, Outputs>::SetInput),
      py::arg("u"), release_gil(), py::doc(
    "Sets the system inputs (usually voltages).\n"
"\n"
":param u: The system inputs.")
  )
  
  
  
    
  .
def
("setInput", static_cast<void(frc::sim::LinearSystemSim<States, Inputs, Outputs>::*)(int, double)>(
        &frc::sim::LinearSystemSim<States, Inputs, Outputs>::SetInput),
      py::arg("row"), py::arg("value"), release_gil()
  )
  
  
  
    
  .
def
("setState", &frc::sim::LinearSystemSim<States, Inputs, Outputs>::SetState,
      py::arg("state"), release_gil(), py::doc(
    "Sets the system state.\n"
"\n"
":param state: The new state.")
  )
  
  
  
    
  .
def
("getCurrentDraw", &frc::sim::LinearSystemSim<States, Inputs, Outputs>::GetCurrentDraw, release_gil(), py::doc(
    "Returns the current drawn by this simulated system. Override this method to\n"
"add a custom current calculation.\n"
"\n"
":returns: The current drawn by this simulated mechanism.")
  )
  
  
  
    
  .
def
("_updateX", static_cast<Vectord<States>(frc::sim::LinearSystemSim<States, Inputs, Outputs>::*)(const Vectord<States>&, const Vectord<Inputs>&, units::second_t)>(&LinearSystemSim_Trampoline::UpdateX),
      py::arg("currentXhat"), py::arg("u"), py::arg("dt"), release_gil(), py::doc(
    "Updates the state estimate of the system.\n"
"\n"
":param currentXhat: The current state estimate.\n"
":param u:           The system inputs (usually voltage).\n"
":param dt:          The time difference between controller updates.")
  )
  
  
  
    
  .
def
("_clampInput", static_cast<Vectord<Inputs>(frc::sim::LinearSystemSim<States, Inputs, Outputs>::*)(Vectord<Inputs>)>(&LinearSystemSim_Trampoline::ClampInput),
      py::arg("u"), release_gil(), py::doc(
    "Clamp the input vector such that no element exceeds the given voltage. If\n"
"any does, the relative magnitudes of the input will be maintained.\n"
"\n"
":param u: The input vector.\n"
"\n"
":returns: The normalized input.")
  )
  
  
  
    .def_readonly("_m_plant", &rpygen::PyTrampoline_frc__sim__LinearSystemSim<typename frc::sim::LinearSystemSim<States, Inputs, Outputs>, States, Inputs, Outputs, typename rpygen::PyTrampolineCfg_frc__sim__LinearSystemSim<States, Inputs, Outputs>>::m_plant, py::doc(
    "The plant that represents the linear system."))
    .def_readonly("_m_x", &rpygen::PyTrampoline_frc__sim__LinearSystemSim<typename frc::sim::LinearSystemSim<States, Inputs, Outputs>, States, Inputs, Outputs, typename rpygen::PyTrampolineCfg_frc__sim__LinearSystemSim<States, Inputs, Outputs>>::m_x, py::doc(
    "State vector."))
    .def_readonly("_m_u", &rpygen::PyTrampoline_frc__sim__LinearSystemSim<typename frc::sim::LinearSystemSim<States, Inputs, Outputs>, States, Inputs, Outputs, typename rpygen::PyTrampolineCfg_frc__sim__LinearSystemSim<States, Inputs, Outputs>>::m_u, py::doc(
    "Input vector."))
    .def_readonly("_m_y", &rpygen::PyTrampoline_frc__sim__LinearSystemSim<typename frc::sim::LinearSystemSim<States, Inputs, Outputs>, States, Inputs, Outputs, typename rpygen::PyTrampolineCfg_frc__sim__LinearSystemSim<States, Inputs, Outputs>>::m_y, py::doc(
    "Output vector."))
    .def_readonly("_m_measurementStdDevs", &rpygen::PyTrampoline_frc__sim__LinearSystemSim<typename frc::sim::LinearSystemSim<States, Inputs, Outputs>, States, Inputs, Outputs, typename rpygen::PyTrampolineCfg_frc__sim__LinearSystemSim<States, Inputs, Outputs>>::m_measurementStdDevs, py::doc(
    "The standard deviations of measurements, used for adding noise to the\n"
"measurements."));

  



    if (set_doc) {
        cls_LinearSystemSim.doc() = set_doc;
    }
    if (add_doc) {
        cls_LinearSystemSim.doc() = py::cast<std::string>(cls_LinearSystemSim.doc()) + add_doc;
    }

    
}

}; // struct bind_frc__sim__LinearSystemSim

}; // namespace rpygen