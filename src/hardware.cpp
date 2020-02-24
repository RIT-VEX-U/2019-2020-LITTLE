#include "hardware.hpp"

//Timer used for "timing out" auto functions like drop_off
okapi::Timer timer = okapi::Timer();

okapi::ADIGyro Hardware::gyro(1, .1);

//Drive train motors (true = reversed)
pros::Motor Hardware::right_front(20, true);
pros::Motor Hardware::right_back(19, true);
pros::Motor Hardware::left_front(11);
pros::Motor Hardware::left_back (12);

TankDrive Hardware::drive_system(Hardware::left_front, Hardware::right_front,
  Hardware::left_back, Hardware::right_back, pros::E_MOTOR_GEARSET_18,
  &Hardware::gyro, &config::drive_config, &config::drive_pid,
  &config::turn_pid);


okapi::MotorGroup Hardware::ramp = {1, -10};

okapi::MotorGroup Hardware::intake_chain = {3, -8};

okapi::MotorGroup Hardware::intake_arms = {9, 2};

pros::Controller Hardware::master(pros::E_CONTROLLER_MASTER);

using namespace Hardware;

void Hardware::drop_off(){
  //place a time mark to compare current time to when drop_off
  //was originally called
  timer.placeMark();

  //lifting the ramp, "time out" if it has not reached the position after
  //5 seconds
	while(ramp.getPosition() < 3.06 && timer.getDtFromMark().getValue() < 5000){
		ramp.moveAbsolute(3.06, 100);
		intake_arms.moveVoltage(3000);
		intake_chain.moveVoltage(-3000);
	}

	pros::delay(500);
	intake_chain.moveVoltage(0);

  //TO BE REMOVED: will find a ramp pos that does not require a push to the stack
  while(!drive_system.drive_forward(2, 0.5)
    && timer.getDtFromMark().getValue() < 10000){}

  pros::delay(500);

  //Back away from the stack
	drive_system.drive_forward(-4, 0.5);

  //Return robot to unfolded position
	while(ramp.getPosition() > 0 && timer.getDtFromMark().getValue() < 10000){
		ramp.moveAbsolute(0, 100);
		intake_arms.moveAbsolute(-6, 100);
	}
}

char const *debug_format_2 = "encoder: %f";
char debug_2[100];

void Hardware::unfold(){
  //flip out ramp via "shaking" the robot while bringing arms out
  intake_arms.tarePosition();
  for(int i = 0; i < 3; i++){
    while(!drive_system.drive_forward(9, 1)){
      intake_arms.moveAbsolute(-5.9, 200);
    }
    while(!drive_system.drive_forward(-9, 1)){
      intake_arms.moveAbsolute(-5.9, 200);
    }
  }

  sprintf(debug_2, debug_format_2, intake_arms.getPosition());
  master.print(2, 1, debug_2);

  //ensure the arms have reached their fully flipped out position
  while(intake_arms.getPosition() > -6){
    intake_arms.moveAbsolute(-6, 200);
  }
}
