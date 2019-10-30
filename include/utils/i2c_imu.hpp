#ifndef _I2CIMU_
#define _I2CIMU_

#include <stdint.h>

/*

  Library for the MPU-9250 or MPU-14159265
  Register map found: https://www.invensense.com/wp-content/uploads/2015/02/RM-MPU-9250A-00-v1.6.pdf
  Documentation found: https://www.invensense.com/wp-content/uploads/2015/02/PS-MPU-9250A-01-v1.1.pdf

  This library implements the I2C protocol over the v5 GPIO ports, for the cheaper (and not discontinued)
  MPU-9265 Inertial Measurement Unit (IMU).

*/

// Available configurations for the gyro
// This represents the full scale range, in Degrees per Second.
// eg DPS_250 = +/-250 degrees per second at it's maximum / minimum value
enum i2c_config_gyro
{
  DPS_250 = 0b00000000,
  DPS_500 = 0b00001000,
  DPS_1000 = 0b00010000,
  DPS_2000 = 0b00011000
};

// Available configurations for the accelerometers
// Represents the maximum and minimum values for the accelerometer.
// eg 2G = +/- (2 * 9.81) m/s^2 at it's max / min value
enum i2c_config_accel
{
  FSR_2G = 0b00000000,
  FSR_4G = 0b00001000,
  FSR_8G = 0b00010000,
  FSR_16G = 0b00011000
};

class I2CImu
{

private:

const uint8_t clock, data;
const uint8_t SLAVE_ADDR = 0x68;

// CONFIG REGISTERS
const uint8_t GYRO_CONFIG = 0x1B;
const uint8_t ACCEL_CONFIG = 0x1C;
const uint8_t ACCEL_CONFIG_2 = 0x1D;

// ACCELEROMETER REGISTERS
const uint8_t ACCEL_X_H = 0x3B;
const uint8_t ACCEL_X_L = 0x3C;
const uint8_t ACCEL_Y_H = 0x3D;
const uint8_t ACCEL_Y_L = 0x3E;
const uint8_t ACCEL_Z_H = 0x3F;
const uint8_t ACCEL_Z_L = 0x40;

// GYRO REGISTERS
const uint8_t GYRO_X_H = 0x43;
const uint8_t GYRO_X_L = 0x44;
const uint8_t GYRO_Y_H = 0x45;
const uint8_t GYRO_Y_L = 0x46;
const uint8_t GYRO_Z_H = 0x47;
const uint8_t GYRO_Z_L = 0x48;

void send_byte(uint8_t _register, uint8_t _value);

uint8_t revceive_byte(uint8_t _register);

public:

void initialize();

void config_accel(i2c_config_accel _config_type);

void config_gyro(i2c_config_gyro _config_type);


I2CImu (uint8_t _clock, uint8_t _data):
clock(_clock), data(_data)
{

}

};

#endif
