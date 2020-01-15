#include "hardware.hpp"

using namespace pros;

Controller Hardware::master(pros::E_CONTROLLER_MASTER);

okapi::ADIGyro Hardware::gyro(1, .1);

Motor Hardware::left_front(12);
Motor Hardware::right_front(13);
Motor Hardware::left_rear(14);
Motor Hardware::right_rear(15);

TankDrive Hardware::drive_system(left_front, right_front, left_rear, right_rear, E_MOTOR_GEARSET_18, &gyro, &config::drive_config, &config::drive_pid, &config::turn_pid);

okapi::MotorGroup Hardware::lift_motors = {5, -6, -7, 8};

rd4Bar Hardware::lift(Hardware::lift_motors, 20);

//!!! TEMP VALS !!!
okapi::MotorGroup Hardware::linear_slide = {-1, 11};
okapi::MotorGroup Hardware::slide_rollers = {12, -3};
okapi::MotorGroup Hardware::compliant_wheels = {17, 18};

Motor Hardware::spool(16);

VerticalIntake Hardware::vert_intake(compliant_wheels, spool);

HorizIntake Hardware::horiz_intake(linear_slide, slide_rollers);
