
// This file is autogenerated. DO NOT EDIT
#include <robotpy_build.h>




#include <frc/system/plant/LinearSystemId.h>


#include <units_compound_type_caster.h>

#include <units_length_type_caster.h>

#include <units_mass_type_caster.h>

#include <units_moment_of_inertia_type_caster.h>

#include <units_time_type_caster.h>















#include <type_traits>


  using namespace frc;





struct rpybuild_LinearSystemId_initializer {


  
    using kv_meters = units::unit_t<units::compound_unit<units::volts, units::inverse<units::meters_per_second>>>;
  
    using kv_radians = units::unit_t<units::compound_unit<units::volts, units::inverse<units::radians_per_second>>>;
  
    using ka_meters = units::unit_t<units::compound_unit<units::volts, units::inverse<units::meters_per_second_squared>>>;
  
    using ka_radians = units::unit_t<units::compound_unit<units::volts, units::inverse<units::radians_per_second_squared>>>;
  

  




  py::module pkg_plant;









  py::class_<typename frc::LinearSystemId> cls_LinearSystemId;

    

    
    

  py::module &m;

  
  rpybuild_LinearSystemId_initializer(py::module &m) :

  
    pkg_plant(m.def_submodule("plant")),
  

  

  

  
    cls_LinearSystemId(pkg_plant, "LinearSystemId"),

  

  
  
  

    m(m)
  {
    
    

    
    
  

    
    
  }

void finish() {





  {
  
  
  


  

  cls_LinearSystemId.doc() =
    "Linear system ID utility functions.";

  cls_LinearSystemId
  
    .def(py::init<>(), release_gil())
  
    
  .
def_static
("elevatorSystem", &frc::LinearSystemId::ElevatorSystem,
      py::arg("motor"), py::arg("mass"), py::arg("radius"), py::arg("gearing"), release_gil(), py::doc(
    "Create a state-space model of the elevator system. The states of the system\n"
"are [position, velocity], inputs are [voltage], and outputs are [position].\n"
"\n"
":param motor:   The motor (or gearbox) attached to the carriage.\n"
":param mass:    The mass of the elevator carriage, in kilograms.\n"
":param radius:  The radius of the elevator's driving drum, in meters.\n"
":param gearing: Gear ratio from motor to carriage.\n"
"                @throws std::domain_error if mass <= 0, radius <= 0, or gearing <= 0.")
  )
  
  
  
    
  .
def_static
("singleJointedArmSystem", &frc::LinearSystemId::SingleJointedArmSystem,
      py::arg("motor"), py::arg("J"), py::arg("gearing"), release_gil(), py::doc(
    "Create a state-space model of a single-jointed arm system.The states of the\n"
"system are [angle, angular velocity], inputs are [voltage], and outputs are\n"
"[angle].\n"
"\n"
":param motor:   The motor (or gearbox) attached to the arm.\n"
":param J:       The moment of inertia J of the arm.\n"
":param gearing: Gear ratio from motor to arm.\n"
"                @throws std::domain_error if J <= 0 or gearing <= 0.")
  )
  
  
  
    
  .
def_static
("identifyVelocitySystemMeters", [](kv_meters kV, ka_meters kA) {
  return frc::LinearSystemId::IdentifyVelocitySystem<units::meter>(kV, kA);
}
,
      py::arg("kV"), py::arg("kA"), py::doc(
    "Create a state-space model for a 1 DOF velocity system from its kV\n"
"(volts/(unit/sec)) and kA (volts/(unit/sec²)). These constants can be\n"
"found using SysId. The states of the system are [velocity], inputs are\n"
"[voltage], and outputs are [velocity].\n"
"\n"
"You MUST use an SI unit (i.e. meters or radians) for the Distance template\n"
"argument. You may still use non-SI units (such as feet or inches) for the\n"
"actual method arguments; they will automatically be converted to SI\n"
"internally.\n"
"\n"
"The parameters provided by the user are from this feedforward model:\n"
"\n"
"u = K_v v + K_a a\n"
"\n"
":param kV: The velocity gain, in volts/(unit/sec).\n"
":param kA: The acceleration gain, in volts/(unit/sec²).\n"
"           @throws std::domain_error if kV < 0 or kA <= 0.\n"
"           @see <a\n"
"           href=\"https://github.com/wpilibsuite/sysid\">https://github.com/wpilibsuite/sysid</a>")
  )
  
  
  
    
  .
def_static
("identifyPositionSystemMeters", [](kv_meters kV, ka_meters kA) {
  return frc::LinearSystemId::IdentifyPositionSystem<units::meter>(kV, kA);
}
,
      py::arg("kV"), py::arg("kA"), py::doc(
    "Create a state-space model for a 1 DOF position system from its kV\n"
"(volts/(unit/sec)) and kA (volts/(unit/sec²)). These constants can be\n"
"found using SysId. the states of the system are [position, velocity],\n"
"inputs are [voltage], and outputs are [position].\n"
"\n"
"You MUST use an SI unit (i.e. meters or radians) for the Distance template\n"
"argument. You may still use non-SI units (such as feet or inches) for the\n"
"actual method arguments; they will automatically be converted to SI\n"
"internally.\n"
"\n"
"The parameters provided by the user are from this feedforward model:\n"
"\n"
"u = K_v v + K_a a\n"
"\n"
"@throws std::domain_error if kV < 0 or kA <= 0.\n"
"@see <a\n"
"href=\"https://github.com/wpilibsuite/sysid\">https://github.com/wpilibsuite/sysid</a>\n"
"\n"
":param kV: The velocity gain, in volts/(unit/sec).\n"
":param kA: The acceleration gain, in volts/(unit/sec²).")
  )
  
  
  
    
  .
def_static
("identifyDrivetrainSystem", [](kv_meters kVlinear, ka_meters kAlinear, kv_meters kVangular, ka_meters kAangular) {
  return frc::LinearSystemId::IdentifyDrivetrainSystem(kVlinear, kAlinear, kVangular, kAangular);
}
,
      py::arg("kVLinear"), py::arg("kALinear"), py::arg("kVAngular"), py::arg("kAAngular"), py::doc(
    "Identify a differential drive drivetrain given the drivetrain's kV and kA\n"
"in both linear {(volts/(meter/sec), (volts/(meter/sec²))} and angular\n"
"{(volts/(radian/sec), (volts/(radian/sec²))} cases. These constants can be\n"
"found using SysId.\n"
"\n"
"States: [[left velocity], [right velocity]]\n"
"Inputs: [[left voltage], [right voltage]]\n"
"Outputs: [[left velocity], [right velocity]]\n"
"\n"
":param kVLinear:  The linear velocity gain in volts per (meters per second).\n"
":param kALinear:  The linear acceleration gain in volts per (meters per\n"
"                  second squared).\n"
":param kVAngular: The angular velocity gain in volts per (meters per\n"
"                  second).\n"
":param kAAngular: The angular acceleration gain in volts per (meters per\n"
"                  second squared).\n"
"                  @throws domain_error if kVLinear <= 0, kALinear <= 0, kVAngular <= 0,\n"
"                  or kAAngular <= 0.\n"
"                  @see <a\n"
"                  href=\"https://github.com/wpilibsuite/sysid\">https://github.com/wpilibsuite/sysid</a>")
  )
  
  
  
    
  .
def_static
("identifyDrivetrainSystem", [](kv_meters kVlinear, ka_meters kAlinear, kv_radians kVangular, ka_radians kAangular, units::meter_t trackWidth) {
  return frc::LinearSystemId::IdentifyDrivetrainSystem(kVlinear, kAlinear, kVangular, kAangular, trackWidth);
}
,
      py::arg("kVLinear"), py::arg("kALinear"), py::arg("kVAngular"), py::arg("kAAngular"), py::arg("trackwidth"), py::doc(
    "Identify a differential drive drivetrain given the drivetrain's kV and kA\n"
"in both linear {(volts/(meter/sec)), (volts/(meter/sec²))} and angular\n"
"{(volts/(radian/sec)), (volts/(radian/sec²))} cases. This can be found\n"
"using SysId.\n"
"\n"
"States: [[left velocity], [right velocity]]\n"
"Inputs: [[left voltage], [right voltage]]\n"
"Outputs: [[left velocity], [right velocity]]\n"
"\n"
":param kVLinear:   The linear velocity gain in volts per (meters per\n"
"                   second).\n"
":param kALinear:   The linear acceleration gain in volts per (meters per\n"
"                   second squared).\n"
":param kVAngular:  The angular velocity gain in volts per (radians per\n"
"                   second).\n"
":param kAAngular:  The angular acceleration gain in volts per (radians per\n"
"                   second squared).\n"
":param trackwidth: The distance between the differential drive's left and\n"
"                   right wheels, in meters.\n"
"                   @throws domain_error if kVLinear <= 0, kALinear <= 0, kVAngular <= 0,\n"
"                   kAAngular <= 0, or trackwidth <= 0.\n"
"                   @see <a\n"
"                   href=\"https://github.com/wpilibsuite/sysid\">https://github.com/wpilibsuite/sysid</a>")
  )
  
  
  
    
  .
def_static
("flywheelSystem", &frc::LinearSystemId::FlywheelSystem,
      py::arg("motor"), py::arg("J"), py::arg("gearing"), release_gil(), py::doc(
    "Create a state-space model of a flywheel system, the states of the system\n"
"are [angular velocity], inputs are [voltage], and outputs are [angular\n"
"velocity].\n"
"\n"
":param motor:   The motor (or gearbox) attached to the flywheel.\n"
":param J:       The moment of inertia J of the flywheel.\n"
":param gearing: Gear ratio from motor to flywheel.\n"
"                @throws std::domain_error if J <= 0 or gearing <= 0.")
  )
  
  
  
    
  .
def_static
("DCMotorSystem", static_cast<LinearSystem<2, 1, 2>(*)(DCMotor, units::kilogram_square_meter_t, double)>(
        &frc::LinearSystemId::DCMotorSystem),
      py::arg("motor"), py::arg("J"), py::arg("gearing"), release_gil(), py::doc(
    "Create a state-space model of a DC motor system. The states of the system\n"
"are [angular position, angular velocity], inputs are [voltage], and outputs\n"
"are [angular position, angular velocity].\n"
"\n"
":param motor:   The motor (or gearbox) attached to the system.\n"
":param J:       the moment of inertia J of the DC motor.\n"
":param gearing: Gear ratio from motor to output.\n"
"                @throws std::domain_error if J <= 0 or gearing <= 0.\n"
"                @see <a\n"
"                href=\"https://github.com/wpilibsuite/sysid\">https://github.com/wpilibsuite/sysid</a>")
  )
  
  
  
    
  .
def_static
("DCMotorSystem", [](kv_meters kv, ka_meters ka) {
  return frc::LinearSystemId::DCMotorSystem<units::meter>(kv, ka);
}
,
      py::arg("kV"), py::arg("kA"), py::doc(
    "Create a state-space model of a DC motor system from its kV\n"
"(volts/(unit/sec)) and kA (volts/(unit/sec²)). These constants can be\n"
"found using SysId. the states of the system are [position, velocity],\n"
"inputs are [voltage], and outputs are [position].\n"
"\n"
"You MUST use an SI unit (i.e. meters or radians) for the Distance template\n"
"argument. You may still use non-SI units (such as feet or inches) for the\n"
"actual method arguments; they will automatically be converted to SI\n"
"internally.\n"
"\n"
"The parameters provided by the user are from this feedforward model:\n"
"\n"
"u = K_v v + K_a a\n"
"\n"
"@throws std::domain_error if kV < 0 or kA <= 0.\n"
"\n"
":param kV: The velocity gain, in volts/(unit/sec).\n"
":param kA: The acceleration gain, in volts/(unit/sec²).")
  )
  
  
  
    
  .
def_static
("drivetrainVelocitySystem", &frc::LinearSystemId::DrivetrainVelocitySystem,
      py::arg("motor"), py::arg("mass"), py::arg("r"), py::arg("rb"), py::arg("J"), py::arg("gearing"), release_gil(), py::doc(
    "Create a state-space model of differential drive drivetrain. In this model,\n"
"the states are [left velocity, right velocity], the inputs are [left\n"
"voltage, right voltage], and the outputs are [left velocity, right\n"
"velocity]\n"
"\n"
":param motor:   The motor (or gearbox) driving the drivetrain.\n"
":param mass:    The mass of the robot in kilograms.\n"
":param r:       The radius of the wheels in meters.\n"
":param rb:      The radius of the base (half of the track width), in meters.\n"
":param J:       The moment of inertia of the robot.\n"
":param gearing: Gear ratio from motor to wheel.\n"
"                @throws std::domain_error if mass <= 0, r <= 0, rb <= 0, J <= 0, or\n"
"                gearing <= 0.")
  )
  
  
  .def_static("DCMotorSystemRadians", [](kv_radians kV, ka_radians kA) {
    return frc::LinearSystemId::DCMotorSystem<units::radian>(kV, kA);
  }, py::arg("kV"), py::arg("kA"), release_gil()
)

.def_static("identifyVelocitySystemRadians", [](kv_radians kV, ka_radians kA) {
    return frc::LinearSystemId::IdentifyVelocitySystem<units::radian>(kV, kA);
  }, py::arg("kV"), py::arg("kA"), release_gil()
)
.def_static("identifyPositionSystemRadians", [](kv_radians kV, ka_radians kA) {
    return frc::LinearSystemId::IdentifyPositionSystem<units::radian>(kV, kA);
  }, py::arg("kV"), py::arg("kA"), release_gil()
)
;

  


  }






}

}; // struct rpybuild_LinearSystemId_initializer

static std::unique_ptr<rpybuild_LinearSystemId_initializer> cls;

void begin_init_LinearSystemId(py::module &m) {
  cls = std::make_unique<rpybuild_LinearSystemId_initializer>(m);
}

void finish_init_LinearSystemId() {
  cls->finish();
  cls.reset();
}