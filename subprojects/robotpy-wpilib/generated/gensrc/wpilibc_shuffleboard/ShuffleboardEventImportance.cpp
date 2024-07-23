
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/shuffleboard/ShuffleboardEventImportance.h>
















#include <type_traits>


  using namespace frc;





struct rpybuild_ShuffleboardEventImportance_initializer {







  
  py::enum_<frc::ShuffleboardEventImportance> enum1;







  py::module &m;

  
  rpybuild_ShuffleboardEventImportance_initializer(py::module &m) :

  

  
    enum1
  (m, "ShuffleboardEventImportance"
  ),
  

  

  

    m(m)
  {
    
    
      enum1
  
    .value("kTrivial", frc::ShuffleboardEventImportance::kTrivial)
  
    .value("kLow", frc::ShuffleboardEventImportance::kLow)
  
    .value("kNormal", frc::ShuffleboardEventImportance::kNormal)
  
    .value("kHigh", frc::ShuffleboardEventImportance::kHigh)
  
    .value("kCritical", frc::ShuffleboardEventImportance::kCritical)
  ;

    

    
  }

void finish() {







m
  .
def
("shuffleboardEventImportanceName", &frc::ShuffleboardEventImportanceName,
      py::arg("importance"), release_gil(), py::doc(
    "Returns name of the given enum.\n"
"\n"
":returns: Name of the given enum.")
  )
  
  ;



}

}; // struct rpybuild_ShuffleboardEventImportance_initializer

static std::unique_ptr<rpybuild_ShuffleboardEventImportance_initializer> cls;

void begin_init_ShuffleboardEventImportance(py::module &m) {
  cls = std::make_unique<rpybuild_ShuffleboardEventImportance_initializer>(m);
}

void finish_init_ShuffleboardEventImportance() {
  cls->finish();
  cls.reset();
}