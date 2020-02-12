#include "hardware.hpp"

okapi::ADIGyro Hardware::gyro(1, .1);

//Drive train motors (true = reversed)
pros::Motor Hardware::right_front(20, true);
pros::Motor Hardware::right_back(19, true);
pros::Motor Hardware::left_front(11);
pros::Motor Hardware::left_back (12);

//
TankDrive Hardware::drive_system(left_front, right_front, left_back, right_back, pros::E_MOTOR_GEARSET_18, &Hardware::gyro, &config::drive_config, &config::drive_pid, &config::turn_pid);

//
okapi::MotorGroup Hardware::tilt_drive = {1, -10};

//
okapi::MotorGroup Hardware::intake_motors = {7, -6};

//
pros::Controller Hardware::master(pros::E_CONTROLLER_MASTER);
