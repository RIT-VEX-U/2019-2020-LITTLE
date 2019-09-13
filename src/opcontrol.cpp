#include "main.h"
#include "swerveModule.hpp"

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
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor drive_mtr(11);
	pros::Motor dir_mtr(12);
	swerveModule swerve(&dir_mtr, &drive_mtr);
	while (true) {
		//pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		//                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		//                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int mag = master.get_analog(ANALOG_LEFT_Y);
		int dir = master.get_analog(ANALOG_RIGHT_Y);

		if (master.get_digital_new_press(DIGITAL_A) == 1)
		{
			dir_mtr.tare_position();
			swerve.setAngle(200,200);
		}
		pros::delay(20);
	}
}
