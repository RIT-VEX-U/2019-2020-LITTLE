#include "hardware.hpp"

pros::Controller hardware::master(pros::E_CONTROLLER_MASTER);

pros::Motor hardware::drive_mtr(11);
pros::Motor hardware::dir_mtr(12);
