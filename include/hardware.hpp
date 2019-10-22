#ifndef _HARDWARE_
#define _HARDWARE_

#include "pros/motors.hpp"
#include "main.h"
#include "subsystems/swerveModule.hpp"
#include "subsystems/swerveDrive.hpp"

namespace hardware
{
    extern pros::Controller master;

    extern pros::Motor lf_drive;
    extern pros::Motor lf_dir;
    extern pros::Motor rf_drive;
    extern pros::Motor rf_dir;
    extern pros::Motor lr_drive;
    extern pros::Motor lr_dir;
    extern pros::Motor rr_drive;
    extern pros::Motor rr_dir;

    extern SwerveModule lf_module;
    extern SwerveModule rf_module;
    extern SwerveModule lr_module;
    extern SwerveModule rr_module;

    extern SwerveDrive swerve;
}
#endif
