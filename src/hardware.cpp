#include "hardware.hpp"

pros::Controller hardware::master(pros::E_CONTROLLER_MASTER);

pros::Motor hardware::drive_mtr(11);
pros::Motor hardware::dir_mtr(12);

SwerveModule hardware::swerve(dir_mtr, drive_mtr, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_GEARSET_18);
