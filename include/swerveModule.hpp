#ifndef _SWERVE_MODULE_
#define _SWERVE_MODULE_

#include "pros/motors.hpp"
#include "main.h"

class SwerveModule
{
private:
  pros::Motor *drive_motor;
  pros::Motor *dir_motor;
public:
  bool set_rotation(int degree);
  void set_speed(float speed);

  SwerveModule(pros::Motor* direction, pros::Motor* drive)
  {
    drive_motor=drive;
    dir_motor=direction;

    dir_motor->set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
  }

  bool set_angle(int degrees, int speed);

};

#endif
