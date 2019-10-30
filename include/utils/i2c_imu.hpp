#ifndef _I2CIMU_
#define _I2CIMU_

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

public:

I2CImu (uint8_t _clock, uint8_t _data):
clock(_clock), data(_data)
{
  
}

};

#endif
