#include "main.h"
#include "hardware.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

using namespace Hardware;

/*
* CONTROL LAYOUT:
*
*/
void opcontrol() {
	char const *debug_format = "encoder: %f";
	char debug[100];

	while(!drive_system.drive_forward(5, 0.75)){
		pros::delay(50);
	}

	while (true) {
		//tank drive controls
    drive_system.drive(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_Y));


    //
		if(master.get_digital(DIGITAL_L1)){
      tilt_drive.moveVoltage(6000);
		}
		else if(master.get_digital(DIGITAL_L2)){
			tilt_drive.moveVoltage(-6000);
		}
    else{
      tilt_drive.moveVoltage(0);
    }


		if(master.get_digital(DIGITAL_A)){
			intake_motors.moveVoltage(12000);
		}
		else if(master.get_digital(DIGITAL_B)){
			intake_motors.moveVoltage(-12000);
		}
		else{
			intake_motors.moveVoltage(0);
		}
		pros::delay(50);
	}
}
