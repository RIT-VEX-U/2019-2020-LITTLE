#include "hardware.hpp"

using namespace pros;

Controller Hardware::master(pros::E_CONTROLLER_MASTER);

okapi::ADIGyro Hardware::gyro(1, .1);

Motor Hardware::left_front(12);
Motor Hardware::right_front(13);
Motor Hardware::left_rear(14);
Motor Hardware::right_rear(15);

TankDrive Hardware::drive_system(left_front, right_front, left_rear, right_rear, E_MOTOR_GEARSET_18, &gyro, &config::drive_config, &config::drive_pid, &config::turn_pid);

okapi::MotorGroup Hardware::lift_motors = {5, -6, 7, -8};

rd4Bar Hardware::lift(Hardware::lift_motors, 20);

//!!! TEMP VALS !!!
okapi::MotorGroup Hardware::linear_slide = {1, 2};
okapi::MotorGroup Hardware::intake_rollers = {3, 4};

okapi::MotorGroup Hardware::claw = {9, 10};

Motor Hardware::magazine(11);
