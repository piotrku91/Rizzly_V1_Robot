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
    levelJoint_->setTargetAngle(target_angle);
    levelJoint_->moveToAngle();
};

void Leg::setRotationAngle(uint16_t target_angle) {
    rotationJoint_->setTargetAngle(target_angle);
    rotationJoint_->moveToAngle();
};

void Leg::setAll(uint16_t level_target_angle, uint16_t rotation_target_angle) {
    levelJoint_->setTargetAngle(level_target_angle);
    setLevelAngle(level_target_angle);
    rotationJoint_->setTargetAngle(rotation_target_angle);
    setRotationAngle(rotation_target_angle);
};

void Leg::setLevelAngleWithAcceleration(uint16_t level_target_angle, uint16_t acceleration_step) {
    if (levelMoveState_ == MoveStatus::Finished) {
        return;
    };
    levelJoint_->setTargetAngle(level_target_angle);
    levelJoint_->moveToAngleWithAcceleration(acceleration_step);

    if (levelJoint_->inMove()) {
        levelMoveState_ = MoveStatus::Moving;
    } else if (levelJoint_->inTargetPosition()) {
        levelMoveState_ = MoveStatus::Finished;
    };
};

void Leg::setRotationAngleWithAcceleration(uint16_t rotation_target_angle, uint16_t acceleration_step) {
    if (rotationMoveState_ == MoveStatus::Finished) {
        return;
    };
    rotationJoint_->setTargetAngle(rotation_target_angle);
    rotationJoint_->moveToAngleWithAcceleration(acceleration_step);

    if (rotationJoint_->inMove()) {
        rotationMoveState_ = MoveStatus::Moving;
    } else if (rotationJoint_->inTargetPosition()) {
        rotationMoveState_ = MoveStatus::Finished;
    };
};

void Leg::setAllWithAcceleration(uint16_t level_target_angle, uint16_t rotation_target_angle, uint16_t acceleration_step){

};

Leg::~Leg() {
    // TODO Auto-generated destructor stub
}
