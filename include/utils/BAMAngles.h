#ifndef BAMANGLES_H
#define BAMANGLES_H

/**
 * \file BAMAngles.h
 *   \brief Library for handling conversions to or from Binary Angle Measure.
 *
 * Binary Angle Measure is a way of measuring angles such that math works like
 *   it should on a circle.  Once you've converted an angle into BAM, you can
 *   do regular math with it, and it will wrap around appropriately, and stay
 *   within one rotation of a circle.
 * \author Alex Kneipp
 * \written 10/3/2019
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t bamAngle_t;

/**
 * Convert a floating point angle into Binary Angle Measure.
 * \param degrees
 *   The number of degrees, from [-180, 180].
 * \return
 *   \p degrees represented as BAM.
 */
bamAngle_t floatToBAM(float degrees);

/**
 * Convert a Binary Angle Measure type into a floationg point number of degrees.
 * \param bam
 *   The angle in BAM.
 * \return
 *   The number of degrees \p bam represents, from [-180, 180].
 */
float bamToFloat(bamAngle_t bam);

#ifdef __cplusplus
}
#endif

#endif
