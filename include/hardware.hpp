#ifndef _HARDWARE_
#define _HARDWARE_

#include "pros/motors.hpp"
#include "main.h"
#include "subsystems/swerveModule.hpp"

namespace hardware
{
    extern pros::Controller master;

    extern pros::Motor drive_mtr;
    extern pros::Motor dir_mtr;

    extern SwerveModule swerve;
}
#endif
