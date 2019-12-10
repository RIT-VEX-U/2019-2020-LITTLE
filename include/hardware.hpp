#ifndef _HARDWARE_
#define _HARDWARE_
#include "main.h"
#include "okapi/impl/device/motor/motorGroup.hpp"
#include "subsystems/rd4Bar.hpp"
#include "okapi/impl/device/rotarysensor/adiGyro.hpp"
#include "subsystems/tank_drive.hpp"
#include "config.hpp"

namespace Hardware
{
    //using the pros Motor & hardware APIs (unless okapi:: is specified)
    using namespace pros;

    extern Controller master;

    extern pros::Motor left_front;
    extern pros::Motor right_front;
    extern pros::Motor left_rear;
    extern pros::Motor right_rear;

    extern TankDrive drive_system;

    extern okapi::ADIGyro gyro;

    //Motors and functions pertaining to the
    //reverse double 4 bar (rd4Bar)
    extern okapi::MotorGroup lift_motors;
    extern rd4Bar lift;

    //Both parts of the horizontal intake
    extern okapi::MotorGroup linear_slide;  //2 motors
    extern okapi::MotorGroup intake_rollers;  //2 motors

    //2 motors for vertical claw
    extern okapi::MotorGroup claw;

    extern Motor magazine;
}
#endif
