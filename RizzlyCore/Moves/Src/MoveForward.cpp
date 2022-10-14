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
    MoveStep setmax_level_frontleft = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::FrontLeft, Legs, MoveJointType::Level, TypicalAngles::Pos120);
    };

    MoveStep setmax_rotation_frontleft = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::FrontLeft, Legs, MoveJointType::Rotation, TypicalAngles::Pos120);
    };

    MoveStep setmin_level_frontleft = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::FrontLeft, Legs, MoveJointType::Level, TypicalAngles::Pos0);
    };

    MoveStep setmin_rotation_frontleft = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::FrontLeft, Legs, MoveJointType::Rotation, TypicalAngles::Pos0);
    };

    MoveStep setmax_level_backright = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::BackRight, Legs, MoveJointType::Level, TypicalAngles::Pos120);
    };

    MoveStep setmax_rotation_backright = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::BackRight, Legs, MoveJointType::Rotation, TypicalAngles::Pos120);
    };

    MoveStep setmin_level_backright = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::BackRight, Legs, MoveJointType::Level, TypicalAngles::Pos0);
    };

    MoveStep setmin_rotation_backright = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::BackRight, Legs, MoveJointType::Rotation, TypicalAngles::Pos0);
    };

    steps.push_back(setmax_level_frontleft);
    steps.push_back(setmax_rotation_frontleft);
    steps.push_back(setmin_level_frontleft);
    steps.push_back(setmin_rotation_frontleft);
    steps.push_back(setmax_level_backright);
    steps.push_back(setmax_rotation_backright);
    steps.push_back(setmin_level_backright);
    steps.push_back(setmin_rotation_backright);

    setStepZero();
}

bool MoveForward::createDefaultMoveStep(LegsOrder current_leg, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle) {
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

