#include "main.h"
#include "hardware.hpp"

enum AutoState
{
INIT, COLLECTI, TURN1, DRIVE1, COLLECTJ, TURN2,
DRIVE2, TURN3, COLLECTM3, TURN4, DRIVE3, TURN5, DRIVE4, DROP_OFF,
TURN6, DRIVE5, TURN7, DRIVE6, TURN8, TOWERS, BACKWARD1, TURN9,
COLLECTK, TURN10, DRIVE7, TURN11, DRIVE8, DROP2, END
};

AutoState current_state = INIT;

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

void collect(){
  while(!horiz_intake.slide_in()){} //TBD: Does the slide need to come in to bring the cube to the vertical intake
  horiz_intake.stop_roller();
  vert_intake.takeIn();
  pros::delay(500);
  vert_intake.stop();
}

void autonomous()
{
  while(true)
  {
    switch(current_state)
    {
        case INIT:
        // Initialize any variables, reset sensors, etc

        break;
        case COLLECTI:
        // Drive forward and collect the first cube
          while(!drive_system.drive_forward(12, 0.75)){
            horiz_intake.slide_out();
            horiz_intake.takeIn();
          }
          collect();
        break;
        case TURN1:
        // Turn torwards the second cube
          drive_system.turn_degrees(-90, 0.5);
        break;
        case COLLECTJ:
        // Drive towards and collect the second cube
          while(drive_system.drive_forward(24, 0.75)){
            horiz_intake.slide_out();
            horiz_intake.takeIn();
          }
          collect();
        break;
        case TURN2:
        // 1st turn for lateral movement
          while(drive_system.turn_degrees(-90, 0.5)){}
        break;
        case DRIVE2:
        // Drive to finish lateral movement
          while(drive_system.drive_forward(5, 0.75)){}
        break;
        case TURN3:
        // Turn towards last cube
          while(drive_system.turn_degrees(90, 0.5)){}
        break;
        case COLLECTM3:
        // Drive forward and collect last cube
        while(drive_system.drive_forward(20, 0.75)){
          horiz_intake.slide_out();
          horiz_intake.takeIn();
        }
        collect();
        break;
        case TURN4:
        // Turn toward the wall
          while(drive_system.turn_degrees(-90, 0.5)){}
        break;
        case DRIVE3:
        // Drive toward the wall
          while(drive_system.drive_forward(12, 0.75)){}
        break;
        case TURN5:
        // Turn toward the goal
          while(drive_system.turn_degrees(-90, 0.5)){}
        break;
        case DRIVE4:
        // Drive toward the goal
          while(drive_system.drive_forward(48, 0.75)){}
        break;
        case DROP_OFF:
        // Drop the cube off at the goal

        break;
        case TURN6:
          while(drive_system.turn_degrees(-90, 0.5)){}
        break;
        case DRIVE5:
          while(drive_system.drive_forward(36, 0.75)){}
        break;
        case TURN7:
          while(drive_system.turn_degrees(-90, 0.5)){}
        break;
        case DRIVE6:
          while(drive_system.drive_forward(24, 0.75)){}
        break;
        case TURN8:
          while(drive_system.turn_degrees(90, 0.5)){}
        break;
        case TOWERS:
          while(drive_system.drive_forward(8, 0.5)){
            horiz_intake.slide_out();
            horiz_intake.takeIn();
          }
          collect();
          lift.moveTo(1.6);

        break;
        case BACKWARD1:

        break;
        case TURN9:

        break;
        case COLLECTK:

        break;
        case TURN10:

        break;
        case DRIVE7:

        break;
        case TURN11:

        break;
        case DRIVE8:

        break;
        case DROP2:

        break;

        default:
        case END:

        return;
    }

    }
}
