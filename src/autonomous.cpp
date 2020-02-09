#include "main.h"
#include "hardware.hpp"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

using namespace Hardware;

// Timer object used to "time out" functions
okapi::Timer timer;

enum COLOR {BLUE = 1, RED = -1};

COLOR curr_color = BLUE;

//Aim: one cube in center tower closest to starting squares
void autonomous(){
  
}
