

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <networktables/StringArrayTopic.h>










#include <rpygen/nt__Publisher.hpp>



namespace rpygen {


using namespace nt;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_nt__StringArrayPublisher :


    PyTrampolineCfg_nt__Publisher<

CfgBase
>

{
    using Base = nt::StringArrayPublisher;

    
    
};




template <typename PyTrampolineBase, typename PyTrampolineCfg>
using PyTrampolineBase_nt__StringArrayPublisher =

    PyTrampoline_nt__Publisher<

        PyTrampolineBase

        
        , PyTrampolineCfg
    >

;

template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_nt__StringArrayPublisher : PyTrampolineBase_nt__StringArrayPublisher<PyTrampolineBase, PyTrampolineCfg> {
    using PyTrampolineBase_nt__StringArrayPublisher<PyTrampolineBase, PyTrampolineCfg>::PyTrampolineBase_nt__StringArrayPublisher;






    using TopicType [[maybe_unused]] = typename nt::StringArrayPublisher::TopicType;

    using ValueType [[maybe_unused]] = typename nt::StringArrayPublisher::ValueType;

    using ParamType [[maybe_unused]] = typename nt::StringArrayPublisher::ParamType;

    using TimestampedValueType [[maybe_unused]] = typename nt::StringArrayPublisher::TimestampedValueType;






    
    

    
    

    

    
};

}; // namespace rpygen


