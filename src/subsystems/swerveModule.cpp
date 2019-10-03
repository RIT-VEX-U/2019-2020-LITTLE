#include "subsystems/swerveModule.hpp"

/**
* Stops all motors associated with this module
*/
void SwerveModule::stop(void)
{
  dir_motor.move_velocity(0);
  drive_motor.move_velocity(0);
}

/**
* Set the direction and speed at the same time, taking into account that the
* drive motor will move if the direction motor moves.
*/
void SwerveModule::set_module(float drive_percent, float direction_degrees)
{
  float current_angle = drive_motor.get_position()/direction_gear_ratio;
  //float reduced_angle = current_angle - (current_angle-(current_angle%360));
  int velocity = (drive_percent * max_rpm_drive) - (dir_motor.get_actual_velocity()/direction_gear_ratio);

  dir_motor.move_absolute(direction_degrees * direction_gear_ratio, max_rpm_direction);
  drive_motor.move_velocity(velocity);
}

/**
* Sets the speed of the drive motor, between -1.0 and 1.0
*/
void SwerveModule::set_speed(float percent)
{
  drive_motor.move_velocity(percent * max_rpm_drive);
}

/**
* Sets the angle of the wheel by setting the "direction" motor
* to the angle, taking into account the gear ratio for the
* direction motor. Also compensates for the direction motor turning the wheel.
*/
bool SwerveModule::set_angle(float degrees)
{
  dir_motor.move_absolute(degrees * direction_gear_ratio, max_rpm_direction);
  drive_motor.move_velocity(-dir_motor.get_actual_velocity() / direction_gear_ratio);
}

/**
* Reset the position of the direction motor. Do not use unless in an emergency
* situation, this might ruin the drivetrain for the match.
*/
void SwerveModule::reset_angle(void)
{
  dir_motor.tare_position();
}
