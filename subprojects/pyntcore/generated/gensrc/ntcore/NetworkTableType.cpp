
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <networktables/NetworkTableType.h>
















#include <type_traits>


  using namespace nt;





struct rpybuild_NetworkTableType_initializer {







  
  py::enum_<nt::NetworkTableType> enum1;







  py::module &m;

  
  rpybuild_NetworkTableType_initializer(py::module &m) :

  

  
    enum1
  (m, "NetworkTableType"
  ,
    "NetworkTable entry type.\n"
"@ingroup ntcore_cpp_api"),
  

  

  

    m(m)
  {
    
    
      enum1
  
    .value("kUnassigned", nt::NetworkTableType::kUnassigned,
      "Unassigned data type.")
  
    .value("kBoolean", nt::NetworkTableType::kBoolean,
      "Boolean data type.")
  
    .value("kDouble", nt::NetworkTableType::kDouble,
      "Double precision floating-point data type.")
  
    .value("kString", nt::NetworkTableType::kString,
      "String data type.")
  
    .value("kRaw", nt::NetworkTableType::kRaw,
      "Raw data type.")
  
    .value("kBooleanArray", nt::NetworkTableType::kBooleanArray,
      "Boolean array data type.")
  
    .value("kDoubleArray", nt::NetworkTableType::kDoubleArray,
      "Double precision floating-point array data type.")
  
    .value("kStringArray", nt::NetworkTableType::kStringArray,
      "String array data type.")
  
    .value("kInteger", nt::NetworkTableType::kInteger,
      "Integer data type.")
  
    .value("kFloat", nt::NetworkTableType::kFloat,
      "Single precision floating-point data type.")
  
    .value("kIntegerArray", nt::NetworkTableType::kIntegerArray,
      "Integer array data type.")
  
    .value("kFloatArray", nt::NetworkTableType::kFloatArray,
      "Single precision floating-point array data type.")
  ;

    

    
  }

void finish() {










}

}; // struct rpybuild_NetworkTableType_initializer

static std::unique_ptr<rpybuild_NetworkTableType_initializer> cls;

void begin_init_NetworkTableType(py::module &m) {
  cls = std::make_unique<rpybuild_NetworkTableType_initializer>(m);
}

void finish_init_NetworkTableType() {
  cls->finish();
  cls.reset();
}