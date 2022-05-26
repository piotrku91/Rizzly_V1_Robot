/*
 * Leg.cpp
 *
 *  Created on: 24 maj 2022
 *      Author: piotr
 */

#include "Leg.hpp"

Leg::Leg(ServoDriverPtr level_joint, ServoDriverPtr rotation_joint)
    : levelJoint_{level_joint}, rotationJoint_{rotation_joint} {
    // TODO Auto-generated constructor stub
}

void Leg::setLevelAngle(uint16_t target_angle) {
    levelJoint_->moveToAngle(target_angle);
};

void Leg::setRotationAngle(uint16_t target_angle) {
    rotationJoint_->moveToAngle(target_angle);
};

void Leg::setAll(uint16_t level_target_angle, uint16_t rotation_target_angle) {
    setLevelAngle(level_target_angle);
    setRotationAngle(rotation_target_angle);
};

void Leg::setLevelAngleWithAcceleration(uint16_t level_target_angle, uint16_t acceleration_step) {
    
    levelJoint_->moveToAngleWithAcceleration(level_target_angle, acceleration_step);
    levelInMove_ = levelJoint_->inMove();
};

void Leg::setRotationAngleWithAcceleration(uint16_t rotation_target_angle, uint16_t acceleration_step) {
    rotationJoint_->moveToAngleWithAcceleration(rotation_target_angle, acceleration_step);
    rotationInMove_ = rotationJoint_->inMove();
};

void Leg::setAllWithAcceleration(uint16_t level_target_angle, uint16_t rotation_target_angle, uint16_t acceleration_step) {

};

Leg::~Leg() {
    // TODO Auto-generated destructor stub
}
