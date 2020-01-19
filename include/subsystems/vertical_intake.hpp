/**
* Purpose: Includes all the functionality for little bot's
*   vertical intake which includes 2 compliant wheels and a
*   spool of string for holding its stack together
* Usage: include the hardware file where the lift
    is declared, Hardware::[name of rd4Bar].[function]
* @author Dana Colletti
*/
#include "okapi/impl/device/motor/motorGroup.hpp"

class VerticalIntake{
private:
  okapi::MotorGroup compliant_wheels;
  pros::Motor spool;

public:
  //Contructor
  VerticalIntake(okapi::MotorGroup compliant_wheels, pros::Motor spool)
    : compliant_wheels(compliant_wheels), spool(spool){

    }

  //COMPLIANT WHEELS

  //Run the compliant wheels in so the cube gets sucked up
  void takeIn(){
    compliant_wheels.moveVoltage(6000);
  }

  //Run the compliant wheels out so the cube gets dropped
  void drop(){
    compliant_wheels.moveVoltage(-6000);
  }

  //Cuts all voltage to the compliant wheels
  void stop(){
    compliant_wheels.moveVoltage(0);
  }

  //SPOOL

  //Spin the spool in to wind up the string and increase tension
  void windSpool(){
    spool.move_voltage(6000);
  }

  //Spin the spool out to unwind the string and decrease tension
  void unwindSpool(){
    spool.move_voltage(-6000);
  }

  //Cuts all voltage to the spool
  void stop_spool(){
    spool.move_voltage(0);
  }

};
