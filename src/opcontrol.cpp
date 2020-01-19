#include "main.h"
#include "hardware.hpp"
#include "logging.hpp"

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>

//Using the components defined in the namespace Hardware
//which exists in hardware.hpp
using namespace Hardware;

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

  char const *print_format = "intake in: %d";
  char print_statement[100];
  master.clear();

	while (true)
  {
    //Runs tank drive
    drive_system.drive(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_Y));

    //Lift
    if(master.get_digital(DIGITAL_R2)){
      lift.raise(12000);
    }
    else if(master.get_digital(DIGITAL_R1)){
      lift.lower(12000);
    }
    else{
      lift.stop();
    }

    //Rollers for horizontal intake
    if(master.get_digital(DIGITAL_X)){
      horiz_intake.takeIn();
    }
    else if(master.get_digital(DIGITAL_Y)){
      horiz_intake.release();
    }
    else{
      horiz_intake.stop_roller();
    }

    //Linear side for horizontal intake
    if(master.get_digital(DIGITAL_A)){
      horiz_intake.slide_out();
    }
    else if(master.get_digital(DIGITAL_B)){
      horiz_intake.slide_in();
        //sprintf(print_statement, print_format, 1);
      //}
      //sprintf(print_statement, print_format, 0);
    }
    else{
      horiz_intake.stop_slide();
    }

    master.print(2, 1, print_statement);

    if(master.get_digital(DIGITAL_L1)){
      vert_intake.takeIn();
    }
    else if(master.get_digital(DIGITAL_L2)){
      vert_intake.drop();
    }
    else{
      vert_intake.stop();
    }

    if(master.get_digital(DIGITAL_UP)){
      vert_intake.windSpool();
    }
    else if(master.get_digital(DIGITAL_DOWN)){
      vert_intake.unwindSpool();
    }
    else{
      vert_intake.stop_spool();
    }

    delay(20);
	}
}
