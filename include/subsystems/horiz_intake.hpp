/**
* Purpose: Run the linear slide and rollers that are
*   responsible for taking cubes in to a position
*   that the vertical intake can utilize
* Usage: 
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

public:

  HorizIntake(okapi::MotorGroup linear_slide, okapi::MotorGroup slide_rollers):
  linear_slide(linear_slide), slide_rollers(slide_rollers)
  {}

  //SLIDE FUNCTIONALITY
  void slide_out(){
    linear_slide.moveVoltage(6000);
  }

  void slide_in(){
    linear_slide.moveVoltage(-6000);
  }

  void stop_slide(){
    linear_slide.moveVoltage(0);
  }

  //ROLLER FUNCTIONALITY
  void takeIn(){
    slide_rollers.moveVoltage(6000);
  }

  void release(){
    slide_rollers.moveVoltage(-6000);
  }

  void stop_roller(){
    slide_rollers.moveVoltage(0);
  }

};

#endif
