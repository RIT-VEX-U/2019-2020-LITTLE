#include "swerveModule.hpp"

bool swerveModule::setAngle(int degrees, int speed)
{
  dirMotor->move_absolute(degrees, speed);
}
