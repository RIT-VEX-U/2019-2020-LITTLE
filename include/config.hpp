#ifndef _CONFIG_
#define _CONFIG_

#include "subsystems/tank_drive.hpp"
#include "utils/pid.hpp"

namespace config
{
    extern TankDrive::config_t drive_config;

    extern PID::config_t drive_pid;
    extern PID::config_t turn_pid;

    extern PID::config_t lift_pid_config;

    void initialize();

}


#endif
