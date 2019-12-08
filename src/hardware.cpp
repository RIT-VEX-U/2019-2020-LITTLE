#include "hardware.hpp"

using namespace pros;

Controller Hardware::master(pros::E_CONTROLLER_MASTER);

okapi::ADIGyro Hardware::gyro(1, .1);

Motor Hardware::drive_mtr(11);
Motor Hardware::dir_mtr(12);

okapi::MotorGroup Hardware::lift_motors = {5, -6, 7, -8};

rd4Bar Hardware::lift(Hardware::lift_motors, 20);

//!!! TEMP VALS !!!
okapi::MotorGroup Hardware::linear_slide = {1, 2};
okapi::MotorGroup Hardware::intake_rollers = {3, 4};

okapi::MotorGroup Hardware::claw = {9, 10};

Motor Hardware::magazine(13);
