#include "hardware.hpp"

using namespace pros;
using namespace Hardware;
Controller master(pros::E_CONTROLLER_MASTER);

okapi::ADIGyro gyro(1, .1);

Motor drive_mtr(11);
Motor dir_mtr(12);

okapi::MotorGroup lift_motors = {5, -6, 7, -8};

rd4Bar lift(Hardware::lift_motors, 20);

//!!! TEMP VALS !!!
okapi::MotorGroup linear_slide = {1, 2};
okapi::MotorGroup intake_rollers = {3, 4};

okapi::MotorGroup claw = {9, 10};

Motor magazine(13);
