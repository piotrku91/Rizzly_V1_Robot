/*
 * ServoDriver.cpp
 *
 *  Created on: May 24, 2022
 *      Author: piotr
 */

#include "ServoDriver.hpp"
#include <algorithm>

ServoDriver::ServoDriver(TIM_HandleTypeDef* htim, uint32_t channel, uint16_t min_angle, uint16_t max_angle, uint16_t min_microsecs, uint16_t max_microsecs, bool init_by_ctor)
    : htim_{htim}, channel_{channel}, min_angle_{min_angle}, max_angle_{max_angle}, min_microsecs_{min_microsecs}, max_microsecs_{max_microsecs}, current_position_angle_{0}, target_position_angle_{0}, locked_{false} {
    if (init_by_ctor) {
        init();
    };
}

void ServoDriver::init() {
    HAL_TIM_PWM_Start(htim_, channel_);
    init_ok_ = true;
};

void ServoDriver::deinit() {
    HAL_TIM_PWM_Stop(htim_, channel_);
    init_ok_ = false;
}

bool ServoDriver::inTargetPosition() const {
    return current_position_angle_ == target_position_angle_;
}

void ServoDriver::setTargetAngle(uint16_t target_angle) {
    target_position_angle_ = std::clamp(target_angle, min_angle_, max_angle_);
}

void ServoDriver::setCurrentPositionAngle(uint16_t new_current_angle) {
    current_position_angle_ = std::clamp(new_current_angle, min_angle_, max_angle_);
}

void ServoDriver::moveToAngle() {
    if (!inTargetPosition()) {
        setCurrentPositionAngle(target_position_angle_);
        moveToMicrosecs(MapValue(current_position_angle_, min_angle_, max_angle_, min_microsecs_, max_microsecs_));
        inmove_ = true;
    }
    inmove_ = false;
}

void ServoDriver::moveToAngleWithAcceleration(uint16_t acceleration_step) {
    if (current_position_angle_ < target_position_angle_) {
        setCurrentPositionAngle(current_position_angle_ + acceleration_step);
        moveToMicrosecs(MapValue(current_position_angle_, min_angle_, max_angle_, min_microsecs_, max_microsecs_));
        inmove_ = true;
        return;
    }

    if (current_position_angle_ > target_position_angle_) {
        setCurrentPositionAngle(current_position_angle_ - acceleration_step);
        moveToMicrosecs(MapValue(current_position_angle_, min_angle_, max_angle_, min_microsecs_, max_microsecs_));
        inmove_ = true;
        return;
    }

    inmove_ = false;
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

bool ServoDriver::inMove() const {
    return inmove_;
}

ServoDriver::~ServoDriver() {
    // TODO Auto-generated destructor stub
}
