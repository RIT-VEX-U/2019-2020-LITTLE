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

//Using objects and functions declared in the Hardware class (hardware.hpp)
using namespace Hardware;

//current color acts as a multiplier for turns, determines right or left
enum COLOR {BLUE = 1, RED = -1};
COLOR curr_color = BLUE;

void collect_cube_dist(double inches){
  while(!drive_system.drive_forward(inches, 0.75)){
    intake_chain.moveVoltage(12000);
  }
  intake_chain.moveVoltage(0);
}

//Aim: Two cube stack in scoring zone
void autonomous(){
  unfold();
  //while(!drive_system.drive_forward(7, 0.5)){}
  //while(!drive_system.drive_forward(-7, 0.5)){}


  //collect_cube_dist(12);
  //while(!drive_system.drive_forward(5, 0.75)){}
  /*while(!drive_system.turn_degrees(curr_color * 90, 0.5)){}
  collect_cube_dist(24);
  while(!drive_system.turn_degrees(curr_color * 90, 0.5)){}
  while(!drive_system.drive_forward(12, 0.75)){}
  while(!drive_system.turn_degrees(curr_color * -90, 0.5)){}
  while(!drive_system.drive_forward(2, 0.5)){}
  drop_off();*/
}
