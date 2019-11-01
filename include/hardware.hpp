#ifndef _HARDWARE_
#define _HARDWARE_
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
