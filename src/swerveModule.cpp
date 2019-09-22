#include "subsystems/swerveModule.hpp"

// 25 teeth on the motor, 50 teeth on the output
float direction_gear_ratio=50.0/25.0;

/**
* Stops all motors associated with this module
*/
void SwerveModule::stop(void)
{
  dir_motor.move_velocity(0);
  drive_motor.move_velocity(0);
}

/**
* Sets the angle of the wheel by setting the "direction" motor
* to the angle, taking into account the gear ratio for the
* direction motor
*/
bool SwerveModule::set_angle(int degrees, int speed)
{
  dir_motor.move_absolute(direction_gear_ratio*degrees, speed);
}

void SwerveModule::reset_angle(void)
{

}
