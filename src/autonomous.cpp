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

/*
* Jostles the robot front & back
* to flip the intake out
*/
void intake_out(){
  while(drive_system.drive_forward(1, 1)){}
  while(drive_system.drive_forward(-1, 1)){}
}

/*
*
*/
void hold_lift(void* pos){
  float* pos_val = (float*)pos;
  while(true){
    lift.hold_pos(*pos_val);
  }
}

/*
* Places a cube in the tower using the button
*   to line up to the tower
* @precondition: Robot has a cube in its claw
*/
void tower_place(float tower_height){
  //Lift to tower height
  Task hold_lift_task(hold_lift, &tower_height);

  //Records time when the function was called
  timer.placeMark();

  //Lining up w/ the tower
  while(timer.getDtFromMark().getValue() < 1000 && !Hardware::tower_button.get_value()){
    drive_system.drive(60, 60);
  }

  //Opening the claw to drop the cube in the tower
  while(!claw.open()){}

  hold_lift_task.remove();
}

//Aim: one cube in center tower closest to starting squares
void autonomous(){
  //Starting position: on starting square furthest from drivers
  intake_out();
  while(!drive_system.drive_forward(24, 0.75)){}
  while(!drive_system.turn_degrees(curr_color * 90, 0.5)){}
  while(!claw.open()){}
  while(!drive_system.drive_forward(15, 0.75)){}
  while(!claw.close()){}
  tower_place(0.8);
}
