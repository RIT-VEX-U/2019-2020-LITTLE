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
	char const *debug_format = "%s mode";
	char debug[100];
	intake_arms.setEncoderUnits(okapi::MotorGroup::encoderUnits::rotations);
	ramp.setEncoderUnits(okapi::MotorGroup::encoderUnits::rotations);

	float intake_pos = 0.0;
	float drive_mult = 0.005;

	while (true) {
		//tank drive controls
    drive_system.drive(master.get_analog(ANALOG_LEFT_Y) * drive_mult, master.get_analog(ANALOG_RIGHT_Y) * drive_mult);

		if(drive_mult == 1.0){
			sprintf(debug, debug_format, "SPEED RACER");
		}
		else{
			sprintf(debug, debug_format, "scoring");
		}
		master.print(2, 1, debug);

		if(master.get_digital(DIGITAL_RIGHT)){
			drive_mult = 1.0;
		}
		else if(master.get_digital(DIGITAL_LEFT)){
			drive_mult = 0.005;
		}

    //
		if(master.get_digital(DIGITAL_L1)){
      ramp.moveVoltage(6000);
		}
		else if(master.get_digital(DIGITAL_L2)){
			ramp.moveVoltage(-6000);
		}
    else{
      ramp.moveVoltage(0);
    }

		if(master.get_digital(DIGITAL_X)){
			intake_pos = -5.9;
		}
		else if(master.get_digital(DIGITAL_R1)){
			intake_arms.moveVoltage(12000);
			intake_pos = intake_arms.getPosition();
		}
		else if(master.get_digital(DIGITAL_R2)){
			intake_arms.moveVoltage(-12000);
			intake_pos = intake_arms.getPosition();
		}
		else{
			intake_arms.moveAbsolute(intake_pos, 200);
		}

		if(master.get_digital(DIGITAL_A) ){
			intake_chain.moveVoltage(12000);
		}
		else if(master.get_digital(DIGITAL_Y)){
			intake_chain.moveVoltage(-12000);
		}
		else if(master.get_digital(DIGITAL_B)){
			intake_chain.moveVoltage(0);
		}

		if(master.get_digital(DIGITAL_UP)){
			drop_off();
		}

		pros::delay(50);
	}
}
