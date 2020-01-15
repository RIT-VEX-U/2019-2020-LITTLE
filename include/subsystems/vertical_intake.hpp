#include "okapi/impl/device/motor/motorGroup.hpp"

class VerticalIntake{
private:
  okapi::MotorGroup v_intake_motors;
  pros::Motor spool;

public:
  //Contructor
  VerticalIntake(okapi::MotorGroup v_intake_motors, pros::Motor spool)
    : v_intake_motors(v_intake_motors), spool(spool){

    }

    //suck in a cube
  void takeIn(){
    v_intake_motors.moveVoltage(6000);
  }

  //drop a cube
  void drop(){
    v_intake_motors.moveVoltage(-6000);
  }

  void stop(){
    v_intake_motors.moveVoltage(0);
  }


};
