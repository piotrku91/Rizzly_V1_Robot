/*
 * MoveForward.cpp
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#include "MoveForward.hpp"
#include "defines.hpp"

MoveForward::MoveForward(LegsVector& legs)
    : MovePatternLegsInput(legs) {
    MoveStep step_fl_setmax_level = [this](LegsVector& Legs) {
        return moveForwardStandardStepCreate(LegsOrder::FrontLeft, Legs, MoveJointType::Level, TypicalAngles::Pos120);
    };

    MoveStep step_fl_setmax_rotation = [this](LegsVector& Legs) {
        return moveForwardStandardStepCreate(LegsOrder::FrontLeft, Legs, MoveJointType::Rotation, TypicalAngles::Pos120);
    };

    MoveStep step_fl_setmin_level = [this](LegsVector& Legs) {
        return moveForwardStandardStepCreate(LegsOrder::FrontLeft, Legs, MoveJointType::Level, TypicalAngles::Pos0);
    };

    MoveStep step_fl_setmin_rotation = [this](LegsVector& Legs) {
        return moveForwardStandardStepCreate(LegsOrder::FrontLeft, Legs, MoveJointType::Rotation, TypicalAngles::Pos0);
    };

    MoveStep step_br_setmax_level = [this](LegsVector& Legs) {
        return moveForwardStandardStepCreate(LegsOrder::BackRight, Legs, MoveJointType::Level, TypicalAngles::Pos120);
    };

    MoveStep step_br_setmax_rotation = [this](LegsVector& Legs) {
        return moveForwardStandardStepCreate(LegsOrder::BackRight, Legs, MoveJointType::Rotation, TypicalAngles::Pos120);
    };

    MoveStep step_br_setmin_level = [this](LegsVector& Legs) {
        return moveForwardStandardStepCreate(LegsOrder::BackRight, Legs, MoveJointType::Level, TypicalAngles::Pos0);
    };

    MoveStep step_br_setmin_rotation = [this](LegsVector& Legs) {
        return moveForwardStandardStepCreate(LegsOrder::BackRight, Legs, MoveJointType::Rotation, TypicalAngles::Pos0);
    };

    steps.push_back(step_fl_setmax_level);
    steps.push_back(step_fl_setmax_rotation);
    steps.push_back(step_fl_setmin_level);
    steps.push_back(step_fl_setmin_rotation);
    steps.push_back(step_br_setmax_level);
    steps.push_back(step_br_setmax_rotation);
    steps.push_back(step_br_setmin_level);
    steps.push_back(step_br_setmin_rotation);

    setStepZero();
}

bool MoveForward::moveForwardStandardStepCreate(LegsOrder current_leg, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle) {
    MoveStatus move_status = MoveStatus::ReadyToGo;
	if (move_joint_type == MoveJointType::Level) {
        legs_vector[current_leg]->setLevelAngleWithAcceleration(target_angle, 5);
        move_status = legs_vector[current_leg]->getLevelMoveStatus();
    } else {
        legs_vector[current_leg]->setRotationAngleWithAcceleration(target_angle, 5);
        move_status = legs_vector[current_leg]->getRotationMoveStatus();
    }

    HAL_Delay(20);

    if (move_status == MoveStatus::Finished) {
        setNextStep();
        legs_vector[current_leg]->resetMoveStatus();
        HAL_Delay(100);
        return true;
    };


    return false;
}

