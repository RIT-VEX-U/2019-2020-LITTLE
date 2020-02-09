#include "config.hpp"

TankDrive::config_t config::drive_config = {};
PID::config_t config::drive_pid = {};
PID::config_t config::turn_pid = {};
PID::config_t config::lift_pid_config = {};

void config::initialize()
{

    drive_config.omni_config = TankDrive::omni_config_t::center_dr;
    drive_config.wheel_size = 4;

    drive_pid.p = 0;
    drive_pid.i = 0;
    drive_pid.d = 0;
    drive_pid.feedforward = 0;
    drive_pid.deadband = 0;
    drive_pid.on_target_time = 0;

    turn_pid.p = 0;
    turn_pid.i = 0;
    turn_pid.d = 0;
    turn_pid.feedforward = 0;
    turn_pid.deadband = 0;
    turn_pid.on_target_time = 0;
}
