#ifndef _HARDWARE_
#define _HARDWARE_

#include "pros/motors.hpp"
#include "main.h"
#include "swerveModule.hpp"

namespace hardware
{

pros::Controller* master = new pros::Controller(pros::E_CONTROLLER_MASTER);

pros::Motor* drive_mtr = new pros::Motor(11);
pros::Motor* dir_mtr = new pros::Motor(12);

SwerveModule* swerve = new SwerveModule(dir_mtr, drive_mtr, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_GEARSET_18);
}
#endif
