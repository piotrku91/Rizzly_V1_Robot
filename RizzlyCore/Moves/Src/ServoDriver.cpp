/*
 * ServoDriver.cpp
 *
 *  Created on: May 24, 2022
 *      Author: piotr
 */

#include "ServoDriver.hpp"

ServoDriver::ServoDriver(TIM_HandleTypeDef* htim, uint32_t channel, uint16_t min_angle, uint16_t max_angle, uint16_t min_microsecs, uint16_t max_microsecs, bool init_by_ctor)
    : htim_{htim}, channel_{channel}, min_angle_{min_angle}, max_angle_{max_angle}, min_microsecs_{min_microsecs}, max_microsecs_{max_microsecs}, current_position_angle_{0}, locked_{false} {
if (init_by_ctor) {init();};
}

void ServoDriver::init() {
    HAL_TIM_PWM_Start(htim_, channel_);
    init_ok_ = true;
};

void ServoDriver::deinit() {
    HAL_TIM_PWM_Stop(htim_, channel_);
    init_ok_ = false;
}

void ServoDriver::moveToAngle(uint16_t angle) {
    if (!locked_) {
        current_position_angle_ = angle;
        moveToMicrosecs(MapValue(current_position_angle_, min_angle_, max_angle_, min_microsecs_, max_microsecs_));
    };
}

void ServoDriver::moveToMicrosecs(uint16_t microsecs) {
    if (!locked_) {
        __HAL_TIM_SET_COMPARE(htim_, channel_, microsecs);
    }
}

void ServoDriver::lock() {
    locked_ = true;
}

void ServoDriver::unlock() {
    locked_ = false;
}

bool ServoDriver::isLocked() const {
    return locked_;
}

ServoDriver::~ServoDriver() {
    // TODO Auto-generated destructor stub
}
