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

void opcontrol() {
	char const *debug_format = "encoder: %f";
	char debug[100];

	//left_front.move_absolute(1.5, 127);

	pros::lcd::print(1, "Before loop");

	while (true) {

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

    //
    if(master.get_digital(DIGITAL_R1)){
      lift_motors.moveVoltage(12000);
    }
    else if(master.get_digital(DIGITAL_R2)){
      lift_motors.moveVoltage(-12000);
    }
    else{
      lift_motors.moveVoltage(0);
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

    /*if(master.get_digital(DIGITAL_A)){
			if(intake_motors.getVoltage() == 0){
      	intake_motors.moveVoltage(12000);
			}
			else{
				intake_motors.moveVoltage(0);
			}
    }
    else if(master.get_digital(DIGITAL_B)){
			if(intake_motors.getVoltage() == 0){
      	intake_motors.moveVoltage(-12000);
			}
			else{
				intake_motors.moveVoltage(0);
			}
    }*/
			//sprintf(debug, debug_format, left_front.get_position());
			//master.print(1, 1, debug);
			//pros::lcd::print(1, "encoder: %f", left_front.get_position());
			while(!drive_system.drive_forward(7, 1.0)){ pros::delay(50); }
			pros::delay(50);
	}
}
