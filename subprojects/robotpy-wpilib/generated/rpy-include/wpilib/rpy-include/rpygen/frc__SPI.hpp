

// This file is autogenerated. DO NOT EDIT

#pragma once
#include <robotpy_build.h>



#include <frc/SPI.h>


#include <frc/DigitalSource.h>









namespace rpygen {


using namespace frc;





template <typename CfgBase = EmptyTrampolineCfg>
struct PyTrampolineCfg_frc__SPI :

    CfgBase

{
    using Base = frc::SPI;

    
    
};



template <typename PyTrampolineBase, typename PyTrampolineCfg>
struct PyTrampoline_frc__SPI : PyTrampolineBase, virtual py::trampoline_self_life_support {
    using PyTrampolineBase::PyTrampolineBase;




  using Port [[maybe_unused]] = typename frc::SPI::Port;

  using Mode [[maybe_unused]] = typename frc::SPI::Mode;








    
    

    
    

    
    using frc::SPI::m_mode;
    

    
};

}; // namespace rpygen


