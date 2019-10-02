#include "subsystems/swerveDrive.hpp"
#include "main.h"
#include <math.h>

//Control algorithm based on papers found at this link:
//https://www.chiefdelphi.com/t/paper-4-wheel-independent-drive-independent-steering-swerve/107383

void SwerveDrive::drive(float direction, float speed, float rotation)
{
  float dirRads = direction * (PI/180);
  //the X axis is defined so the robot strafing towards the starboard direction
  //is positive x
  float x = speed * (cos( dirRads ));
  //The Y axis is defined so the robot traveling in the forward direction is
  //positive y
  float y = speed * (sin( dirRads ));
  //The z axis is defined using the right hand rule relative to the robots rotation
  float z = -rotation;


}

bool SwerveDrive::set_direction(float direction)
{

}

bool SwerveDrive::set_rotation(float direction)
{

}

bool SwerveDrive::set_speed(float speed)
{

}

bool SwerveDrive::auto_drive_inches(float direction, float speed)
{

}

bool SwerveDrive::auto_rotate_degrees(float degrees, float speed)
{

}
