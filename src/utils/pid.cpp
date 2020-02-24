#include "utils/pid.hpp"
#include "api.h"
#include "okapi/impl/util/timer.hpp"
#include "hardware.hpp"

//Whether or not the pid has already been called once
bool initialized = false;

//Timer for finding the time passed since the pid was originally called
okapi::Timer timer2 = okapi::Timer();

/**
 * Reset the PID loop by resetting time since 0 and accumulated error.
 */
void PID::reset()
{
    last_error = 0;
    last_time = 0;
    accum_error = 0;

    is_checking_on_target = false;
    initialized = false;
    on_target_last_time = 0;
}

char const *debug_format = "error: %f";
char debug[100];

/**
 * Update the PID loop by taking the time difference from last update,
 * and running the PID formula with the new sensor data
 */
void PID::update(double sensorVal)
{
    //Place a timer "mark" to compare current time to
    //if this is the first call to update
    if (!initialized){
      timer2.placeMark();
      initialized = true;
    }

    this->sensorVal = sensorVal;

    //getting the time difference from the first call to update
    double time_delta = timer2.getDtFromMark().getValue();

    accum_error += time_delta * get_error();


    out = (config->feedforward)
        + (config->p * get_error())
        + (config->i * accum_error)
        + (config->d * (get_error() - last_error) / time_delta);

    last_time = pros::c::millis() / 1000.0;
    last_error = get_error();

    if(lower_limit != 0 || upper_limit != 0)
        out = (out < lower_limit) ? lower_limit : (out > upper_limit) ? upper_limit : out;

}

/**
 * Gets the current PID out value, from when update() was last run
 */
double PID::get()
{
    return out;
}

/**
 * Get the delta between the current sensor data and the target
 */
double PID::get_error()
{
    return target - sensorVal;
}

/**
 * Set the target for the PID loop, where the robot is trying to end up
 */
void PID::set_target(double target)
{
    this->target = target;
}

/**
 * Set the limits on the PID out. The PID out will "clip" itself to be
 * between the limits.
 */
void PID::set_limits(double lower, double upper)
{
    lower_limit = lower;
    upper_limit = upper;
}

bool PID::is_on_target()
{
    if(fabs(get_error()) < config->deadband)
    {
        if(is_checking_on_target == false)
        {
            on_target_last_time = (pros::c::millis() / 1000.0);
            is_checking_on_target = true;
        }else if((pros::c::millis() / 1000.0) - on_target_last_time > config->on_target_time)
        {
            return true;
        }

    }else
    {
        is_checking_on_target = false;
    }

    return false;
}
