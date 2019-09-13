#include "swerveModule.hpp"

bool SwerveModule::set_angle(int degrees, int speed)
{
  dir_motor->move_absolute(degrees, speed);
}
