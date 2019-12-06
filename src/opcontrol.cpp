#include "main.h"
#include "hardware.hpp"
#include "logging.hpp"

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>


/**
* Block all logic flow until the gyro is finished resetting
*/
void block_gyro_reset(){
	//Hardware::drive_system.drive(0, 0);
  Hardware::gyro.reset();
  //delay 1.5 seconds
  pros::delay(1500);
}


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
void opcontrol() {
	int logTimer = 500;
	int logTime = 0;

	// clear the log file
	logging::clearLogFile();

  //using the hardware defined within hardware.hpp
  using namespace Hardware;
	while (true) {
		//pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		//                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		//                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int mag = master.get_analog(ANALOG_LEFT_Y);
		//int dir = hardware::master->get_analog(ANALOG_RIGHT_Y);

		int dir = ((180.0/3.14159265) * atan2(master.get_analog(ANALOG_LEFT_X), master.get_analog(ANALOG_LEFT_Y)));
		int speed = sqrt(pow(master.get_analog(ANALOG_LEFT_Y),2) + pow(master.get_analog(ANALOG_LEFT_X),2));
		drive_mtr.move_velocity(speed);

		if(master.get_digital(DIGITAL_L1)){
      lift.raise(100);
    }
    else if(master.get_digital(DIGITAL_L2)){
      lift.lower(100);
    }
    else{
      lift.stop();
    }

    if(master.get_digital(DIGITAL_X)){
      linear_slide.moveVoltage(100);
    }
    else{
      linear_slide.moveVoltage(0);
    }

    if(master.get_digital(DIGITAL_Y)){
      intake_rollers.moveVoltage(100);
    }
    else{
      intake_rollers.moveVoltage(0);
    }

    if(master.get_digital(DIGITAL_R1)){
      claw.moveVoltage(100);
    }
    else if(master.get_digital(DIGITAL_R2)){
      claw.moveVoltage(-100);
    }
    else{
      claw.moveVoltage(0);
    }

    if(master.get_digital(DIGITAL_A)){
      magazine.move(100);
    }
    else{
      magazine.move(0);
    }

		/*
		pros::lcd::print(0, "direction: %i", dir);

		FILE* motor_log = fopen("/usd/motor_log.txt","w");
		fprintf(motor_log, "System Time: %d\n", pros::millis());
		for(int i = 0; i < 12; i++){
			fprintf(motor_log, "Motor %d: ", i);
			fputs("\n", motor_log);
		}
		fflush(motor_log);
		fclose(motor_log);
		*/

	}
}
