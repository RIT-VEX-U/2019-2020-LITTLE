#include "hardware.hpp"

//okapi::MotorGroup Hardware::drive_train = {1, -2, 11, -12};

okapi::ADIGyro Hardware::gyro(1, .1);

pros::Motor Hardware::right_front(20, true);
pros::Motor Hardware::right_back(19, true);
pros::Motor Hardware::left_front(11); //reverse
pros::Motor Hardware::left_back (12); //reverse


TankDrive Hardware::drive_system(left_front, right_front, left_back, right_back, pros::E_MOTOR_GEARSET_18, &Hardware::gyro, &config::drive_config, &config::drive_pid, &config::turn_pid);

okapi::MotorGroup Hardware::tilt_drive = {1, -10};

okapi::MotorGroup Hardware::lift_motors = {6, -7};

okapi::MotorGroup Hardware::intake_motors = {9, -2};

 pros::Controller Hardware::master(pros::E_CONTROLLER_MASTER);
