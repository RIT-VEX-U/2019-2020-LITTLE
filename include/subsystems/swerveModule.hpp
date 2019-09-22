#ifndef _SWERVE_MODULE_
#define _SWERVE_MODULE_

#include "pros/motors.hpp"
#include "main.h"

class SwerveModule
{
private:
  pros::Motor drive_motor;
  pros::Motor dir_motor;
public:
  void stop(void);
  void set_speed(float speed);
  bool set_angle(int degrees, int speed);
  void reset_angle(void);

  /**
  * Create the SwerveModule object. There will be four of these per
  * drivetrain, one on each corner.
  * \param direction
  *        The motor involved with rotating the wheel
  * \param drive
  *        The motor involved with driving the wheel
  * \param dir_gear_ratio
  *        The gearing core inserted into the direction motor
  * \param drive_gear_ratio
  *        The gearing core inserted into the drive motor
  */
  SwerveModule(pros::Motor direction, pros::Motor drive,
               pros::motor_gearset_e_t dir_gear_ratio,
               pros::motor_gearset_e_t drive_gear_ratio):
                drive_motor(drive), dir_motor(direction)
  {
    dir_motor.set_gearing(dir_gear_ratio);
    drive_motor.set_gearing(drive_gear_ratio);

    dir_motor.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
  }
};

#endif
