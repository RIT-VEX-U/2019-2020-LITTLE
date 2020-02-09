#ifndef _HARDWARE_
#define _HARDWARE_

#include "subsystems/tank_drive.hpp"
#include "okapi/impl/device/motor/motorGroup.hpp"
#include "config.hpp"


namespace Hardware{
  //extern okapi::MotorGroup drive_train;

  extern pros::Motor right_front;
  extern pros::Motor right_back;
  extern pros::Motor left_front;
  extern pros::Motor left_back;

  extern TankDrive drive_system;

  extern okapi::ADIGyro gyro;

  extern okapi::MotorGroup tilt_drive;

  extern okapi::MotorGroup lift_motors;

  extern okapi::MotorGroup intake_motors;

  extern pros::Controller master;


}

#endif
