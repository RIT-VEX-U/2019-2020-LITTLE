/**
* Purpose: Includes all the functionality for a reverse
*   double four bar
* Usage: include the hardware file where the lift
    is declared, Hardware::[name of rd4Bar].[function]
* @author Dana Colletti
*/
#ifndef _RD_4_BAR_
#define _RD_4_BAR_
#include "okapi/impl/device/motor/motorGroup.hpp"
#include "logging.hpp"
#include "utils/pid.hpp"

class rd4Bar{

private:
  //One MotorGroup since all the motors always move together
  okapi::MotorGroup lift_motors;

  PID *lift_pid;

  //Position it is currently holding, -1 if none
  float holdingPos = -1;

  //The minimum motor velocity needed to hold the lift in a certain position
  int holdingPower;

public:
//Constructor
  rd4Bar(okapi::MotorGroup lift_motors, int holdingPower, PID::config_t *lift_pid_config) : lift_motors(lift_motors){
    this -> holdingPower = holdingPower;
    lift_pid = new PID(lift_pid_config);
    lift_motors.setEncoderUnits(okapi::AbstractMotor::encoderUnits::rotations);
  }

//Set all motors to a positive voltage to raise the lift indefinitely
  void raise(int power){
    lift_motors.moveVoltage(power);
  }

//Set all motors to a negative voltage to lower the lift indefinitely
  void lower(int power){
    lift_motors.moveVoltage(-power);
  }

//Set all motors to a zero velocity to stop the lift from moving
  void stop(){
    lift_motors.moveVelocity(0);
  }

//Raise/Lower the lift to a specified point and have it keep that poisition
  void moveTo(float encoderVal, bool hold){
    //While it is too high, lower it
    while(fabs(lift_motors.getPosition()) > encoderVal){
      lift_motors.moveVoltage(12000);
    }

    //While it is too low, raise it
    while(fabs(lift_motors.getPosition()) < encoderVal){
      lift_motors.moveVoltage(-12000);
    }

    //if the lift should maintain this position
    if(hold){
      holdingPos = encoderVal;
      hold_pos(holdingPos);
    }
    else{
      lift_motors.moveVelocity(0);
    }
  }

  int hold_pos(float newHoldingPos){
    if(holdingPos != newHoldingPos){
      holdingPos = newHoldingPos;
    }
    lift_pid -> set_target(holdingPos);
    lift_pid -> update(lift_motors.getPosition());
    int power = lift_pid -> get();
    lift_motors.moveVoltage(power);
    return power;
  }

  bool is_holding(){ return holdingPos > -1; }

  float getHoldingPos(){ return holdingPos; }

  float getCurrPos(){ return lift_motors.getPosition(); }

  void release_hold(){
    holdingPos = -1;
  }

//Checks if there is voltage going to the lift motors
  bool isMoving(){
    return lift_motors.getVoltage() > 0;
  }

//Logging function
  void logLift(){
    logging::log(lift_motors.getCurrentDraw(), lift_motors.getPosition());
    //TODO: Log individual motors?
  }

};

#endif
