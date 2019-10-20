#ifndef _HARDWARE_
#define _HARDWARE_

#include "pros/motors.hpp"
#include "main.h"
#include "subsystems/swerveModule.hpp"

namespace hardware
{
    pros::Controller master(pros::E_CONTROLLER_MASTER);

    pros::Motor lf_drive(11);
    pros::Motor lf_dir(12);
    pros::Motor rf_drive(2);
    pros::Motor rf_dir(1);
    pros::Motor lr_drive(19);
    pros::Motor lr_dir(20);
    pros::Motor rr_drive(10);
    pros::Motor rr_dir(9);

    SwerveModule lf_module(lf_dir, lf_drive, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_GEARSET_06);
    SwerveModule rf_module(rf_dir, rf_drive, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_GEARSET_06);
    SwerveModule lr_module(lr_dir, lr_drive, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_GEARSET_06);
    SwerveModule rr_module(rr_dir, rr_drive, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_GEARSET_06);
}
#endif
