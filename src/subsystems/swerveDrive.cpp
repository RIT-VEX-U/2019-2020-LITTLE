#include "subsystems/swerveDrive.hpp"
#include "main.h"
#include "utils/vmath.h"
#include <math.h>
#define PI 3.1415926535897932

void drive_test(int leftx, int lefty, int rightx)
{
  
}

//Control algorithm based on papers found at this link:
//https://www.chiefdelphi.com/t/paper-4-wheel-independent-drive-independent-steering-swerve/107383

/**
 * Drive swerve drive
 * \param direction
 *  The direction we should drive, in degrees. 0 is straight ahead, and increases
 *  to the right.
 * \param speed
 *  The speed to drive at, -1 to 1.
 * \param rotation
 *  The speed at which to rotate, -1 to 1.  Positive values are clockwise, negative
 *  are counterclockwise.
 */
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

  //These are just constants from the paper mentioned above, I don't know what they do
  float L = this->wheelbase_mm;
  float W = this->trackwidth_mm;
  float R = sqrt((L * L) + (W * W));
  float A = x + (z * (L/R));
  float B = x - (z * (L/R));
  float C = y + (z * (W/R));
  float D = y - (z * (W/R));

  //Start turning to the angle each wheel has to face
  this->frontRight.set_angle(atan2(B, C) * (180/PI));
  this->frontLeft.set_angle(atan2(B, D) * (180/PI));
  this->backLeft.set_angle(atan2(A, D) * (180/PI));
  this->backRight.set_angle(atan2(A, C) * (180/PI));

  //Calculate the optimal wheel speed
  float frWheelSpeed = sqrt((B * B) + (C * C));
  float flWheelSpeed = sqrt((B * B) + (D * D));
  float rlWheelSpeed = sqrt((A * A) + (D * D));
  float rrWheelSpeed = sqrt((A * A) + (C * C));

  //Find the maximum speed for later
  float max = frWheelSpeed;
  if(flWheelSpeed > max) max = flWheelSpeed;
  if(rlWheelSpeed > max) max = rlWheelSpeed;
  if(rrWheelSpeed > max) max = rrWheelSpeed;

  //Initialize normalized wheel speeds
  float norm_frWheelSpeed = frWheelSpeed;
  float norm_flWheelSpeed = flWheelSpeed;
  float norm_rlWheelSpeed = rlWheelSpeed;
  float norm_rrWheelSpeed = rrWheelSpeed;

  //Normalize the wheel speeds if necessary
  if(max > 1)
  {
    norm_frWheelSpeed = frWheelSpeed / max;
    norm_flWheelSpeed = flWheelSpeed / max;
    norm_rlWheelSpeed = rlWheelSpeed / max;
    norm_rrWheelSpeed = rrWheelSpeed / max;
  }
  //Drive Baby Drive!
  this->frontRight.set_module(norm_frWheelSpeed, atan2(B, C) * (180/PI));
  this->frontLeft.set_module(norm_flWheelSpeed, atan2(B, D) * (180/PI));
  this->backLeft.set_module(norm_rlWheelSpeed, atan2(A, D) * (180/PI));
  this->backRight.set_module(norm_rrWheelSpeed, atan2(A, C) * (180/PI));
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
