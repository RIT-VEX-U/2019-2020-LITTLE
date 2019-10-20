#include "utils/BAMAngles.h"
#include <math.h>

/**
 * \file BAMAngles.c
 *   Library for handling conversions to or from Binary Angle Measure.
 * \author Alex Kneipp
 * \written 10/3/2019
 */

#ifdef __cplusplus
extern "C" {
#endif

bamAngle_t floatToBAM(float degrees)
{
  //degrees/180 makes the angle into a multiplier from [-1, 1], which we can
  //then mutiply by INT32_MAX to create a BAM angle.
  bamAngle_t bam = (bamAngle_t)(degrees/180 * INT32_MAX);
  return bam;
}

float bamToFloat(bamAngle_t bam)
{
  //Turn our BAM back into a multiplier from [-1, 1], then multiply by 180 degrees
  //to get our angle back
  float degrees = (((float)(bam)) / INT32_MAX) * 180.0;
  return degrees;
}

#ifdef __cplusplus
}
#endif
