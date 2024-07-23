

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <networktables/NTSendableBuilder.h>










#include <rpygen/wpi__SendableBuilder.hpp>



namespace rpygen {


using namespace nt;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_nt__NTSendableBuilder :


    PyTrampolineCfg_wpi__SendableBuilder<

CfgBase
>

{
    using Base = nt::NTSendableBuilder;

    
    
    using override_base_SetUpdateTable_Tunique_function = nt::NTSendableBuilder;
    
    using override_base_GetTopic_Tstring_view = nt::NTSendableBuilder;
    
    using override_base_GetTable_v = nt::NTSendableBuilder;
    
    using override_base_KGetBackendKind_v = nt::NTSendableBuilder;
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_nt__NTSendableBuilder =

    PyTrampoline_wpi__SendableBuilder<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_nt__NTSendableBuilder : PyTrampolineBase_nt__NTSendableBuilder<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_nt__NTSendableBuilder<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_nt__NTSendableBuilder;





    using BackendKind = wpi::SendableBuilder::BackendKind;







    
    
#ifndef RPYGEN_DISABLE_SetUpdateTable_Tunique_function
    void SetUpdateTable(wpi::unique_function<void ()> func) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(NTSendableBuilder, PYBIND11_TYPE(void), LookupBase,
            "setUpdateTable", SetUpdateTable, func);
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_GetTopic_Tstring_view
    Topic GetTopic(std::string_view key) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(NTSendableBuilder, PYBIND11_TYPE(Topic), LookupBase,
            "getTopic", GetTopic, key);
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_GetTable_v
    std::shared_ptr<NetworkTable> GetTable() override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(NTSendableBuilder, PYBIND11_TYPE(std::shared_ptr<NetworkTable>), LookupBase,
            "getTable", GetTable, );
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_KGetBackendKind_v
    BackendKind GetBackendKind() const override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        using CxxCallBase = typename PyTrampolineCfg::override_base_KGetBackendKind_v;
        PYBIND11_OVERRIDE_IMPL(PYBIND11_TYPE(BackendKind), LookupBase,
            "getBackendKind", );
        return CxxCallBase::GetBackendKind();
    
    
    
    }
#endif

    

    
    

    

    
};

}; // namespace rpygen


