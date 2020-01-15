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
    //Runs tank drive
    drive_system.drive(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_Y));

    //Lift
    if(Hardware::master.get_digital(DIGITAL_R2)){
      Hardware::lift.raise(12000);
    }
    else if(Hardware::master.get_digital(DIGITAL_R1)){
      Hardware::lift.lower(12000);
    }
    else{
      Hardware::lift.stop();
    }

    //Rollers for horizontal intake
    if(Hardware::master.get_digital(DIGITAL_X)){
      Hardware::horiz_intake.takeIn();
    }
    else if(Hardware::master.get_digital(DIGITAL_Y)){
      Hardware::horiz_intake.release();
    }
    else{
      Hardware::horiz_intake.stop_roller();
    }

    //Linear side for horizontal intake
    if(Hardware::master.get_digital(DIGITAL_A)){
      Hardware::horiz_intake.slide_out();
    }
    else if(Hardware::master.get_digital(DIGITAL_B)){
      Hardware::horiz_intake.slide_in();
    }
    else{
      Hardware::horiz_intake.stop_slide();
    }



    delay(20);
	}
}
