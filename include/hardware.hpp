#ifndef _HARDWARE_
#define _HARDWARE_
#include "main.h"
#include "okapi/impl/device/motor/motorGroup.hpp"
#include "subsystems/rd4Bar.hpp"
#include "okapi/impl/device/rotarysensor/adiGyro.hpp"

namespace Hardware
{
    //using the pros Motor & hardware APIs (unless okapi:: is specified)
    using namespace pros;

    extern Controller master;

    extern Motor drive_mtr;
    extern Motor dir_mtr;

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
