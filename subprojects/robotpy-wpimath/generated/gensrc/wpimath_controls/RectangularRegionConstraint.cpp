
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/trajectory/constraint/RectangularRegionConstraint.h>


#include <units_compound_type_caster.h>

#include <units_velocity_type_caster.h>







#define RPYGEN_ENABLE_frc__RectangularRegionConstraint_PROTECTED_CONSTRUCTORS
#include <rpygen/frc__RectangularRegionConstraint.hpp>





#include "RectangularRegionConstraint_tmpl.hpp"



#include <PyTrajectoryConstraint.h>



#include <type_traits>


  using namespace frc;





struct rpybuild_RectangularRegionConstraint_initializer {




  py::module pkg_constraint;









  
      rpygen::bind_frc__RectangularRegionConstraint_0 tmplCls0;
    

  py::module &m;

  
  rpybuild_RectangularRegionConstraint_initializer(py::module &m) :

  
    pkg_constraint(m.def_submodule("constraint")),
  

  

  

  
    
        tmplCls0(pkg_constraint, "RectangularRegionConstraint"),
      
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {



  tmplCls0.finish(
    NULL,
    NULL
  );








}

}; // struct rpybuild_RectangularRegionConstraint_initializer

static std::unique_ptr<rpybuild_RectangularRegionConstraint_initializer> cls;

void begin_init_RectangularRegionConstraint(py::module &m) {
  cls = std::make_unique<rpybuild_RectangularRegionConstraint_initializer>(m);
}

void finish_init_RectangularRegionConstraint() {
  cls->finish();
  cls.reset();
}