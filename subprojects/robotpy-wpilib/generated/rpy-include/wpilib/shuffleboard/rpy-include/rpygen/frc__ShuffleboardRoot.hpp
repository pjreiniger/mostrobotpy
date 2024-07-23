

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/shuffleboard/ShuffleboardRoot.h>


#include <frc/shuffleboard/ShuffleboardTab.h>









namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__ShuffleboardRoot :

    CfgBase

{
    using Base = frc::ShuffleboardRoot;

    
    
    using override_base_GetTab_Tstring_view = frc::ShuffleboardRoot;
    
    using override_base_Update_v = frc::ShuffleboardRoot;
    
    using override_base_EnableActuatorWidgets_v = frc::ShuffleboardRoot;
    
    using override_base_DisableActuatorWidgets_v = frc::ShuffleboardRoot;
    
    using override_base_SelectTab_i = frc::ShuffleboardRoot;
    
    using override_base_SelectTab_Tstring_view = frc::ShuffleboardRoot;
    
};



template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__ShuffleboardRoot : PyTrampolineBase, virtual py::trampoline_self_life_support {
    using PyTrampolineBase::PyTrampolineBase;











    
    
#ifndef RPYGEN_DISABLE_GetTab_Tstring_view
    ShuffleboardTab& GetTab(std::string_view title) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(ShuffleboardRoot, PYBIND11_TYPE(ShuffleboardTab&), LookupBase,
            "getTab", GetTab, title);
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_Update_v
    void Update() override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(ShuffleboardRoot, PYBIND11_TYPE(void), LookupBase,
            "update", Update, );
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_EnableActuatorWidgets_v
    void EnableActuatorWidgets() override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(ShuffleboardRoot, PYBIND11_TYPE(void), LookupBase,
            "enableActuatorWidgets", EnableActuatorWidgets, );
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_DisableActuatorWidgets_v
    void DisableActuatorWidgets() override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(ShuffleboardRoot, PYBIND11_TYPE(void), LookupBase,
            "disableActuatorWidgets", DisableActuatorWidgets, );
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SelectTab_i
    void SelectTab(int index) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(ShuffleboardRoot, PYBIND11_TYPE(void), LookupBase,
            "selectTab", SelectTab, index);
    
    
    
    }
#endif

    
#ifndef RPYGEN_DISABLE_SelectTab_Tstring_view
    void SelectTab(std::string_view title) override {
    
    
    
    
        using LookupBase = typename PyTrampolineCfg::Base;
    
    
        RPYBUILD_OVERRIDE_PURE_NAME(ShuffleboardRoot, PYBIND11_TYPE(void), LookupBase,
            "selectTab", SelectTab, title);
    
    
    
    }
#endif

    

    
    

    

    
};

}; // namespace rpygen


