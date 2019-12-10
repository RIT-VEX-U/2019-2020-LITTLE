#include "main.h"

enum AutoState
{
INIT, COLLECTI, TURN1, DRIVE1, COLLECTJ, TURN2, 
DRIVE2, TURN3, COLLECTM3, TURN4, DRIVE3, TURN5, DRIVE4, DROP_OFF, END
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

        break;
        case TURN1:
        // Turn torwards the second cube

        break;
        case DRIVE1:
        // Drive towards the second cube

        break;
        case COLLECTJ:
        // Slow down and collect the second cube

        break;
        case TURN2:
        // 1st turn for lateral movement

        break;
        case DRIVE2:
        // Drive to finish lateral movement

        break;
        case TURN3:
        // Turn towards last cube

        break;
        case COLLECTM3:
        // Drive forward and collect last cube

        break;
        case TURN4:
        // Turn toward the wall 

        break;
        case DRIVE3:
        // Drive toward the wall

        break;
        case TURN5:
        // Turn toward the goal

        break;
        case DRIVE4:
        // Drive toward the goal

        break;
        case DROP_OFF:
        // Drop the cube off at the goal

        break;
        default:
        case END:

        return;
    }

    }
}
