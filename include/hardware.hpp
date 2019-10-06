#ifndef _HARDWARE_
#define _HARDWARE_

#include "pros/motors.hpp"
#include "main.h"
#include "subsystems/swerveModule.hpp"

namespace hardware
{
    pros::Controller master(pros::E_CONTROLLER_MASTER);

    pros::Motor drive_mtr(11);
    pros::Motor dir_mtr(12);


    SwerveModule swerve(dir_mtr, drive_mtr, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_GEARSET_06);
}
#endif
