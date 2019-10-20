#include "main.h"
#include "hardware.hpp"

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
	hardware::dir_mtr.set_reversed(true);
	while (true) {

		float x = hardware::master.get_analog(ANALOG_LEFT_X) / 127.0;
		float y = hardware::master.get_analog(ANALOG_LEFT_Y) / 127.0;

		//angle of joystick, -180<dir<180
		float dir = (atan2(-x, y) * (180/3.14159265));
		float speed = sqrt( (y*y) + (x*x) );

		hardware::lf_module.set_module(speed, dir);
		hardware::rf_module.set_module(speed, dir);
		hardware::lr_module.set_module(speed, dir);
		hardware::rr_module.set_module(speed, dir);

		pros::delay(20);

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
