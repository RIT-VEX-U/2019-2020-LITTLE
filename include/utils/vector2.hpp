#ifndef _VECTOR2_
#define _VECTOR2_

#include <cmath>

class Vector2
{
public:

  float x, y;

  float get_length()
  {
    return sqrt((x*x) + (y*y));
  }

  float get_angle_rad()
  {
    return atan2(x, y);
  }

  float get_angle_deg()
  {
    return get_angle_rad * (180.0/3.141592654);
  }

  Vector2 operator+(const Vector2& rhs)
  {
    return Vector2().setxy(x+rhs.x, y+rhs.y);
  }

  Vector2 operator-(const Vector2& rhs)
  {
    return Vector2().setxy(x-rhs.x, y-rhs.y);
  }

  void setxy(float x, float y)
  {
    this->x = x;
    this->y = y;
  }

  void set_length_dir(float length, float dir)
  {
    x = length * cos(dir);
    y = length * sin(dir);
  }
}

#endif
