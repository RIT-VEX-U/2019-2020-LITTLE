/**
* Purpose: Run the linear slide and rollers that are
*   responsible for taking cubes in to a position
*   that the vertical intake can utilize
* Usage: include the hardware file where the intake
    is declared, Hardware::[name of horizontal intake].[function]
* @author Dana Colletti
*/
#ifndef _HORIZ_INTAKE_
#define _HORIZ_INTAKE_

#include "okapi/impl/device/motor/motorGroup.hpp"

using namespace pros;

class HorizIntake
{
private:

  okapi::MotorGroup linear_slide;
  okapi::MotorGroup slide_rollers;

  //The encoder value at the maximum entension of the linear slide
  int slide_max = 10; //!!RANDOM VALUE, WILL BE CHANGED!!

public:
  //Constructor
  HorizIntake(okapi::MotorGroup linear_slide, okapi::MotorGroup slide_rollers):
  linear_slide(linear_slide), slide_rollers(slide_rollers)
  {
    //linear_slide.setReversed(true);
  }

  //SLIDE FUNCTIONALITY

  //Bring the linear slide out
  void slide_out(){
    //TODO: Checks if it can extend further
    linear_slide.moveVoltage(12000);
  }

  /*
  * Bring the linear slide in
  * @return true if the slide is all the way in, false otherwise
  */
  bool slide_in(){
    linear_slide.moveVoltage(-12000);
    //Checks if it can keep going in
    //if(linear_slide.getPosition() <= 0){
    //  linear_slide.moveVoltage(0);
    //  return true;
    //}
    return false;
  }

  //Stops the slide from moving
  void stop_slide(){
    linear_slide.moveVoltage(0);
  }

  //ROLLER FUNCTIONALITY

  //Roll the compliant wheels in
  void takeIn(){
    slide_rollers.moveVoltage(6000);
  }

  //Roll the compliant wheels out
  void release(){
    slide_rollers.moveVoltage(-6000);
  }

  //Stop the compliant wheels from moving
  void stop_roller(){
    slide_rollers.moveVoltage(0);
  }

};

#endif
