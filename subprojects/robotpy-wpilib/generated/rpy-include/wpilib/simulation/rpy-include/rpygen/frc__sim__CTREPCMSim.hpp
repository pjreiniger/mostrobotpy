

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/simulation/CTREPCMSim.h>


#include <frc/Compressor.h>









#include <rpygen/frc__sim__PneumaticsBaseSim.hpp>



namespace rpygen {


using namespace frc::sim;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__sim__CTREPCMSim :


    PyTrampolineCfg_frc__sim__PneumaticsBaseSim<

CfgBase
>

{
    using Base = frc::sim::CTREPCMSim;

    
    
    using override_base_RegisterInitializedCallback_TNotifyCallback_b = frc::sim::CTREPCMSim;
    
    using override_base_KGetInitialized_v = frc::sim::CTREPCMSim;
    
    using override_base_SetInitialized_b = frc::sim::CTREPCMSim;
    
    using override_base_RegisterSolenoidOutputCallback_i_TNotifyCallback_b = frc::sim::CTREPCMSim;
    
    using override_base_KGetSolenoidOutput_i = frc::sim::CTREPCMSim;
    
    using override_base_SetSolenoidOutput_i_b = frc::sim::CTREPCMSim;
    
    using override_base_RegisterCompressorOnCallback_TNotifyCallback_b = frc::sim::CTREPCMSim;
    
    using override_base_KGetCompressorOn_v = frc::sim::CTREPCMSim;
    
    using override_base_SetCompressorOn_b = frc::sim::CTREPCMSim;
    
    using override_base_RegisterPressureSwitchCallback_TNotifyCallback_b = frc::sim::CTREPCMSim;
    
    using override_base_KGetPressureSwitch_v = frc::sim::CTREPCMSim;
    
    using override_base_SetPressureSwitch_b = frc::sim::CTREPCMSim;
    
    using override_base_RegisterCompressorCurrentCallback_TNotifyCallback_b = frc::sim::CTREPCMSim;
    
    using override_base_KGetCompressorCurrent_v = frc::sim::CTREPCMSim;
    
    using override_base_SetCompressorCurrent_d = frc::sim::CTREPCMSim;
    
    using override_base_KGetAllSolenoidOutputs_v = frc::sim::CTREPCMSim;
    
    using override_base_SetAllSolenoidOutputs_c = frc::sim::CTREPCMSim;
    
    using override_base_ResetData_v = frc::sim::CTREPCMSim;
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_frc__sim__CTREPCMSim =

    PyTrampoline_frc__sim__PneumaticsBaseSim<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__sim__CTREPCMSim : PyTrampolineBase_frc__sim__CTREPCMSim<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_frc__sim__CTREPCMSim<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_frc__sim__CTREPCMSim;





    using PneumaticsBase = frc::PneumaticsBase;







    
    
#ifndef RPYGEN_DISABLE_RegisterInitializedCallback_TNotifyCallback_b
    std::unique_ptr<CallbackStore> RegisterInitializedCallback(NotifyCallback callback, bool initialNotify) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_RegisterInitializedCallback_TNotifyCallback_b;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(std::unique_ptr<CallbackStore>), LookupBase,
            "registerInitializedCallback", callback, initialNotify);
        return CxxCallBase::RegisterInitializedCallback(std::move(callback), std::move(initialNotify));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetInitialized_v
    bool GetInitialized() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetInitialized_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(bool), LookupBase,
            "getInitialized", );
        return CxxCallBase::GetInitialized();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SetInitialized_b
    void SetInitialized(bool initialized) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_SetInitialized_b;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "setInitialized", initialized);
        return CxxCallBase::SetInitialized(std::move(initialized));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_RegisterSolenoidOutputCallback_i_TNotifyCallback_b
    std::unique_ptr<CallbackStore> RegisterSolenoidOutputCallback(int channel, NotifyCallback callback, bool initialNotify) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_RegisterSolenoidOutputCallback_i_TNotifyCallback_b;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(std::unique_ptr<CallbackStore>), LookupBase,
            "registerSolenoidOutputCallback", channel, callback, initialNotify);
        return CxxCallBase::RegisterSolenoidOutputCallback(std::move(channel), std::move(callback), std::move(initialNotify));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetSolenoidOutput_i
    bool GetSolenoidOutput(int channel) const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetSolenoidOutput_i;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(bool), LookupBase,
            "getSolenoidOutput", channel);
        return CxxCallBase::GetSolenoidOutput(std::move(channel));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SetSolenoidOutput_i_b
    void SetSolenoidOutput(int channel, bool solenoidOutput) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_SetSolenoidOutput_i_b;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "setSolenoidOutput", channel, solenoidOutput);
        return CxxCallBase::SetSolenoidOutput(std::move(channel), std::move(solenoidOutput));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_RegisterCompressorOnCallback_TNotifyCallback_b
    std::unique_ptr<CallbackStore> RegisterCompressorOnCallback(NotifyCallback callback, bool initialNotify) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_RegisterCompressorOnCallback_TNotifyCallback_b;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(std::unique_ptr<CallbackStore>), LookupBase,
            "registerCompressorOnCallback", callback, initialNotify);
        return CxxCallBase::RegisterCompressorOnCallback(std::move(callback), std::move(initialNotify));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetCompressorOn_v
    bool GetCompressorOn() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetCompressorOn_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(bool), LookupBase,
            "getCompressorOn", );
        return CxxCallBase::GetCompressorOn();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SetCompressorOn_b
    void SetCompressorOn(bool compressorOn) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_SetCompressorOn_b;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "setCompressorOn", compressorOn);
        return CxxCallBase::SetCompressorOn(std::move(compressorOn));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_RegisterPressureSwitchCallback_TNotifyCallback_b
    std::unique_ptr<CallbackStore> RegisterPressureSwitchCallback(NotifyCallback callback, bool initialNotify) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_RegisterPressureSwitchCallback_TNotifyCallback_b;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(std::unique_ptr<CallbackStore>), LookupBase,
            "registerPressureSwitchCallback", callback, initialNotify);
        return CxxCallBase::RegisterPressureSwitchCallback(std::move(callback), std::move(initialNotify));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetPressureSwitch_v
    bool GetPressureSwitch() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetPressureSwitch_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(bool), LookupBase,
            "getPressureSwitch", );
        return CxxCallBase::GetPressureSwitch();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SetPressureSwitch_b
    void SetPressureSwitch(bool pressureSwitch) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_SetPressureSwitch_b;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "setPressureSwitch", pressureSwitch);
        return CxxCallBase::SetPressureSwitch(std::move(pressureSwitch));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_RegisterCompressorCurrentCallback_TNotifyCallback_b
    std::unique_ptr<CallbackStore> RegisterCompressorCurrentCallback(NotifyCallback callback, bool initialNotify) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_RegisterCompressorCurrentCallback_TNotifyCallback_b;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(std::unique_ptr<CallbackStore>), LookupBase,
            "registerCompressorCurrentCallback", callback, initialNotify);
        return CxxCallBase::RegisterCompressorCurrentCallback(std::move(callback), std::move(initialNotify));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetCompressorCurrent_v
    double GetCompressorCurrent() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetCompressorCurrent_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(double), LookupBase,
            "getCompressorCurrent", );
        return CxxCallBase::GetCompressorCurrent();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SetCompressorCurrent_d
    void SetCompressorCurrent(double compressorCurrent) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_SetCompressorCurrent_d;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "setCompressorCurrent", compressorCurrent);
        return CxxCallBase::SetCompressorCurrent(std::move(compressorCurrent));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetAllSolenoidOutputs_v
    uint8_t GetAllSolenoidOutputs() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetAllSolenoidOutputs_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(uint8_t), LookupBase,
            "getAllSolenoidOutputs", );
        return CxxCallBase::GetAllSolenoidOutputs();
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SetAllSolenoidOutputs_c
    void SetAllSolenoidOutputs(uint8_t outputs) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_SetAllSolenoidOutputs_c;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "setAllSolenoidOutputs", outputs);
        return CxxCallBase::SetAllSolenoidOutputs(std::move(outputs));
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_ResetData_v
    void ResetData() override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_ResetData_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(void), LookupBase,
            "resetData", );
        return CxxCallBase::ResetData();
    
    
    
    }
#endif

    

    
    

    

    
};

}; // namespace rpygen


