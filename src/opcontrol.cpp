#include "main.h"
#include "hardware.hpp"
#include "logging.hpp"

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace Hardware;


/**
* Block all logic flow until the gyro is finished resetting
*/
void block_gyro_reset(){
	//Hardware::drive_system.drive(0, 0);
  gyro.reset();
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

	while (true)
  {
    drive_system.drive(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_Y));



    delay(20);
	}
}
