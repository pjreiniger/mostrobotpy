
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <rpy/Filesystem.h>
















#include <type_traits>


  using namespace robotpy::filesystem;





struct rpybuild_Filesystem_initializer {













  py::module &m;

  
  rpybuild_Filesystem_initializer(py::module &m) :

  

  

  

  

    m(m)
  {
    
    

    
  }

void finish() {







m
  .
def
("getOperatingDirectory", &robotpy::filesystem::GetOperatingDirectory, release_gil(), py::doc(
    "Obtains the operating directory of the program. On the roboRIO, this\n"
"is /home/lvuser/py. In simulation, it is the location of robot.py\n"
"\n"
":returns: The result of the operating directory lookup.")
  )
  
  ;
m
  .
def
("getDeployDirectory", &robotpy::filesystem::GetDeployDirectory, release_gil(), py::doc(
    "Obtains the deploy directory of the program, which is the remote location\n"
"the deploy directory is deployed to by default. On the roboRIO, this is\n"
"/home/lvuser/py/deploy. In simulation, it is where the simulation was launched\n"
"from, in the subdirectory \"deploy\" (`dirname(robot.py)`/deploy).\n"
"\n"
":returns: The result of the operating directory lookup")
  )
  
  ;



}

}; // struct rpybuild_Filesystem_initializer

static std::unique_ptr<rpybuild_Filesystem_initializer> cls;

void begin_init_Filesystem(py::module &m) {
  cls = std::make_unique<rpybuild_Filesystem_initializer>(m);
}

void finish_init_Filesystem() {
  cls->finish();
  cls.reset();
}