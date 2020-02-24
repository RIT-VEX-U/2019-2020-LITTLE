#ifndef _HARDWARE_
#define _HARDWARE_

#include "subsystems/tank_drive.hpp"
#include "okapi/impl/device/motor/motorGroup.hpp"
#include "config.hpp"


namespace Hardware{

  // drive train motors
  extern pros::Motor right_front;
  extern pros::Motor right_back;
  extern pros::Motor left_front;
  extern pros::Motor left_back;

  // drive system
  extern TankDrive drive_system;

  extern okapi::ADIGyro gyro;

  extern okapi::MotorGroup ramp;

  //The motors driving the intake "arms"
  extern okapi::MotorGroup intake_arms;

  //The motors driving the flaps/chain around the intake
  extern okapi::MotorGroup intake_chain;

  extern pros::Controller master;

  //auto stack placing function
  void drop_off();

  //auto unfolding function
  void unfold();

}

#endif
