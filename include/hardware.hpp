#ifndef _HARDWARE_
#define _HARDWARE_
#include "main.h"
#include "okapi/impl/device/motor/motorGroup.hpp"
#include "subsystems/rd4Bar.hpp"
#include "subsystems/vertical_intake.hpp"
#include "subsystems/horiz_intake.hpp"
#include "okapi/impl/device/rotarysensor/adiGyro.hpp"
#include "subsystems/tank_drive.hpp"
#include "config.hpp"

namespace Hardware
{
    //using the pros Motor & hardware APIs (unless okapi:: is specified)
    using namespace pros;

    extern Controller master;

    //DRIVE MOTORS
    extern Motor left_front;
    extern Motor right_front;
    extern Motor left_rear;
    extern Motor right_rear;

    extern TankDrive drive_system;

    extern okapi::ADIGyro gyro;

    //Motors and functions pertaining to the
    //reverse double 4 bar (rd4Bar)
    extern okapi::MotorGroup lift_motors;
    extern rd4Bar lift;

    //Horizontal intake components
    extern okapi::MotorGroup linear_slide;
    extern okapi::MotorGroup slide_rollers;

    //Vertical intake components
    extern okapi::MotorGroup compliant_wheels;
    extern Motor spool;

    extern VerticalIntake vert_intake;

    extern HorizIntake horiz_intake;

    extern Motor magazine;
}
#endif
