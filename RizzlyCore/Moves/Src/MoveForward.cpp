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
        Legs[LegsOrder::FrontLeft]->setLevelAngleWithAcceleration(TypicalAngles::Pos120, 5);
        HAL_Delay(20);
        if (Legs[LegsOrder::FrontLeft]->getLevelMoveStatus() == MoveStatus::Finished) {
            setNextStep();
            Legs[LegsOrder::FrontLeft]->resetMoveStatus();
            HAL_Delay(100);
            return true;
        };
        return false;
    };

    MoveStep step_fl_setmax_rotation = [this](LegsVector& Legs) {
        Legs[LegsOrder::FrontLeft]->setRotationAngleWithAcceleration(TypicalAngles::Pos120, 5);
        HAL_Delay(20);

        if (Legs[LegsOrder::FrontLeft]->getRotationMoveStatus() == MoveStatus::Finished) {
            setNextStep();
            Legs[LegsOrder::FrontLeft]->resetMoveStatus();
            HAL_Delay(100);
            return true;
        };

        return false;
    };

    MoveStep step_fl_setmin_level = [this](LegsVector& Legs) {
        legs_[LegsOrder::FrontLeft]->setLevelAngleWithAcceleration(TypicalAngles::Pos0, 5);
        HAL_Delay(20);

        if (legs_[LegsOrder::FrontLeft]->getLevelMoveStatus() == MoveStatus::Finished) {
            setNextStep();
            legs_[LegsOrder::FrontLeft]->resetMoveStatus();
            HAL_Delay(100);
            return true;
        };

        return false;
    };

    MoveStep step_fl_setmin_rotation = [this](LegsVector& Legs) {
        legs_[LegsOrder::FrontLeft]->setRotationAngleWithAcceleration(TypicalAngles::Pos0, 5);
        HAL_Delay(20);

        if (legs_[LegsOrder::FrontLeft]->getRotationMoveStatus() == MoveStatus::Finished) {
            setNextStep();
            legs_[LegsOrder::FrontLeft]->resetMoveStatus();
            HAL_Delay(100);
            return true;
        };

        return false;
    };

    MoveStep step_br_setmax_level = [this](LegsVector& Legs) {
        Legs[LegsOrder::BackRight]->setLevelAngleWithAcceleration(TypicalAngles::Pos120, 5);
        HAL_Delay(20);
        if (Legs[LegsOrder::BackRight]->getLevelMoveStatus() == MoveStatus::Finished) {
            setNextStep();
            Legs[LegsOrder::BackRight]->resetMoveStatus();
            HAL_Delay(100);
            return true;
        };
        return false;
    };

    MoveStep step_br_setmax_rotation = [this](LegsVector& Legs) {
        Legs[LegsOrder::BackRight]->setRotationAngleWithAcceleration(TypicalAngles::Pos120, 5);
        HAL_Delay(20);

        if (Legs[LegsOrder::BackRight]->getRotationMoveStatus() == MoveStatus::Finished) {
            setNextStep();
            Legs[LegsOrder::BackRight]->resetMoveStatus();
            HAL_Delay(100);
            return true;
        };

        return false;
    };

    MoveStep step_br_setmin_level = [this](LegsVector& Legs) {
        legs_[LegsOrder::BackRight]->setLevelAngleWithAcceleration(TypicalAngles::Pos0, 5);
        HAL_Delay(20);

        if (legs_[LegsOrder::BackRight]->getLevelMoveStatus() == MoveStatus::Finished) {
            setNextStep();
            legs_[LegsOrder::BackRight]->resetMoveStatus();
            HAL_Delay(100);
            return true;
        };

        return false;
    };

    MoveStep step_br_setmin_rotation = [this](LegsVector& Legs) {
        legs_[LegsOrder::BackRight]->setRotationAngleWithAcceleration(TypicalAngles::Pos0, 5);
        HAL_Delay(20);

        if (legs_[LegsOrder::BackRight]->getRotationMoveStatus() == MoveStatus::Finished) {
            setNextStep();
            legs_[LegsOrder::BackRight]->resetMoveStatus();
            HAL_Delay(100);
            return true;
        };

        return false;
    };

    steps.push_back(step_fl_setmax_level);
    steps.push_back(step_fl_setmax_rotation);
    steps.push_back(step_fl_setmin_level);
    steps.push_back(step_br_setmin_rotation);
    steps.push_back(step_br_setmax_level);
    steps.push_back(step_br_setmax_rotation);
    steps.push_back(step_br_setmin_level);
    steps.push_back(step_br_setmin_rotation);

    setStepZero();
}

void MoveForward::run() {
    if (!isAnyStep()) {
        return;
    };

    if (*current_step_ && current_step_ != steps.end()) {
        (*current_step_)(legs_);
    } else {
        setStepZero();
    }
}
