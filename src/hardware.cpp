#include "hardware.hpp"

pros::Controller hardware::master(pros::E_CONTROLLER_MASTER);

pros::Motor hardware::lf_drive(11);
pros::Motor hardware::lf_dir(12, true);
pros::Motor hardware::rf_drive(2);
pros::Motor hardware::rf_dir(1, true);
pros::Motor hardware::lr_drive(19);
pros::Motor hardware::lr_dir(20, true);
pros::Motor hardware::rr_drive(10);
pros::Motor hardware::rr_dir(9, true);

SwerveModule hardware::lf_module(lf_dir, lf_drive, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_GEARSET_06);
SwerveModule hardware::rf_module(rf_dir, rf_drive, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_GEARSET_06);
SwerveModule hardware::lr_module(lr_dir, lr_drive, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_GEARSET_06);
SwerveModule hardware::rr_module(rr_dir, rr_drive, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_GEARSET_06);

SwerveDrive hardware::swerve(lf_module, rf_module, lr_module, rr_module);
