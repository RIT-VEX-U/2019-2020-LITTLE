#include "main.h"
#include "hardware.hpp"
#include "logging.hpp"

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>


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

	while (true) {
		//pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		//                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		//                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int mag = hardware::master.get_analog(ANALOG_LEFT_Y);
		//int dir = hardware::master->get_analog(ANALOG_RIGHT_Y);

		int dir = ((180.0/3.14159265) * atan2(hardware::master.get_analog(ANALOG_LEFT_X), hardware::master.get_analog(ANALOG_LEFT_Y)));
		int speed = sqrt(pow(hardware::master.get_analog(ANALOG_LEFT_Y),2) + pow(hardware::master.get_analog(ANALOG_LEFT_X),2));
		hardware::drive_mtr.move_velocity(speed);

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
