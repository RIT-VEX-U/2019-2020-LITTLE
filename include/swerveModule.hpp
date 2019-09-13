#ifndef _SWERVE_MODULE_
#define _SWERVE_MODULE_

#include "pros/motors.hpp"
#include "main.h"

class swerveModule
{
private:
  pros::Motor *driveMotor;
  pros::Motor *dirMotor;
public:
  bool setRotation(int degree);
  void setSpeed(float speed);

  swerveModule(pros::Motor* direction, pros::Motor* drive)
  {
    driveMotor=drive;
    dirMotor=direction;
  }

  bool setAngle(int degrees, int speed);

};

#endif
