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
  //Bring it into BAM
  bamAngle_t bam = (bamAngle_t)(degrees/180 * INT32_MAX);
  return bam;
}

float bamToFloat(bamAngle_t bam)
{
  //Scale it to -1 - 1 and bring it back into the degree range
  float degrees = (((float)(bam)) / INT32_MAX) * 180.0;
  return degrees;
}

#ifdef __cplusplus
}
#endif
