#include "hardware.hpp"

using namespace pros;

/*
* MOTOR LAYOUT
*
* DRIVE
* Left front: 20
* Right front: 10
* Left back: 19
* Right back: 9
*
* LIFT
* Lower left: 11, reversed
* Lower right: 1
* Upper left: 12
* Upper right: 2, reversed
*
* INTAKE
* Vertical:
*   Compliant wheels:
*     front: 14
*     back: 4
*   Spool: 3
* Horizontal:
*   Right linear slide: 8
*   Left linear slide: 18
*   Right roller: 7
*   Left roller: 17
*/

Controller Hardware::master(pros::E_CONTROLLER_MASTER);

okapi::ADIGyro Hardware::gyro(1, .1);

//DRIVE MOTORS
Motor Hardware::left_front(20);
Motor Hardware::right_front(10);
Motor Hardware::left_rear(19);
Motor Hardware::right_rear(9);

TankDrive Hardware::drive_system(left_front, right_front, left_rear, right_rear, E_MOTOR_GEARSET_18, &gyro, &config::drive_config, &config::drive_pid, &config::turn_pid);

okapi::MotorGroup Hardware::lift_motors = {12, -2, -11, 1};

rd4Bar Hardware::lift(Hardware::lift_motors, 20, &config::lift_pid_config);

//Horizontal intake components
okapi::MotorGroup Hardware::linear_slide = {8, -18};  //left:1 right: 11
okapi::MotorGroup Hardware::slide_rollers = {17, -7}; //right: 3 left: 12

//Vertical intake components
okapi::MotorGroup Hardware::compliant_wheels = {4, 14};
Motor Hardware::spool(3);

VerticalIntake Hardware::vert_intake(compliant_wheels, spool);

HorizIntake Hardware::horiz_intake(linear_slide, slide_rollers);
