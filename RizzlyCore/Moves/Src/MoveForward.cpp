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
        return createDefaultMoveStep(LegsOrder::FrontLeft, Legs, MoveJointType::Level, TypicalAngles::Pos90);
    };

    MoveStep setmax_rotation_frontleft = [this](LegsVector& Legs) {
        return createDefaultMoveStepWithWait(LegsOrder::FrontLeft, Legs, MoveJointType::Rotation, TypicalAngles::Pos90, 100);
    };

    MoveStep setmax_level_backleft = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::BackLeft, Legs, MoveJointType::Level, TypicalAngles::Pos90);
    };

    MoveStep setmax_rotation_backleft = [this](LegsVector& Legs) {
        return createDefaultMoveStepWithWait(LegsOrder::BackLeft, Legs, MoveJointType::Rotation, TypicalAngles::Pos90, 100);
    };

    MoveStep setmin_level_frontleft = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::FrontLeft, Legs, MoveJointType::Level, TypicalAngles::Pos0);
    };

    MoveStep setmin_rotation_frontleft = [this](LegsVector& Legs) {
        return createDefaultMoveStepWithWait(LegsOrder::FrontLeft, Legs, MoveJointType::Rotation, TypicalAngles::Pos0, 100);
    };

    MoveStep setmin_level_backleft = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::BackLeft, Legs, MoveJointType::Level, TypicalAngles::Pos0);
    };

    MoveStep setmin_rotation_backleft = [this](LegsVector& Legs) {
        return createDefaultMoveStepWithWait(LegsOrder::BackLeft, Legs, MoveJointType::Rotation, TypicalAngles::Pos0, 100);
    };

    MoveStep setmax_level_frontright = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::FrontRight, Legs, MoveJointType::Level, TypicalAngles::Pos90);
    };

    MoveStep setmax_rotation_frontright = [this](LegsVector& Legs) {
        return createDefaultMoveStepWithWait(LegsOrder::FrontRight, Legs, MoveJointType::Rotation, TypicalAngles::Pos90, 100);
    };

    MoveStep setmax_level_backright = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::BackRight, Legs, MoveJointType::Level, TypicalAngles::Pos90);
    };

    MoveStep setmax_rotation_backright = [this](LegsVector& Legs) {
        return createDefaultMoveStepWithWait(LegsOrder::BackRight, Legs, MoveJointType::Rotation, TypicalAngles::Pos90, 100);
    };

    MoveStep setmin_level_frontright = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::FrontRight, Legs, MoveJointType::Level, TypicalAngles::Pos0);
    };

    MoveStep setmin_rotation_frontright = [this](LegsVector& Legs) {
        return createDefaultMoveStepWithWait(LegsOrder::FrontRight, Legs, MoveJointType::Rotation, TypicalAngles::Pos0, 100);
    };

    MoveStep setmin_level_backright = [this](LegsVector& Legs) {
        return createDefaultMoveStep(LegsOrder::BackRight, Legs, MoveJointType::Level, TypicalAngles::Pos0);
    };

    MoveStep setmin_rotation_backright = [this](LegsVector& Legs) {
        return createDefaultMoveStepWithWait(LegsOrder::BackRight, Legs, MoveJointType::Rotation, TypicalAngles::Pos0, 100);
    };

    steps.push_back(setmax_level_frontleft);
    steps.push_back(setmax_rotation_frontleft);
    steps.push_back(setmax_level_backleft);
    steps.push_back(setmax_rotation_backleft);
    steps.push_back(setmin_level_frontleft);
    steps.push_back(setmin_rotation_frontleft);
    steps.push_back(setmin_level_backleft);
    steps.push_back(setmin_rotation_backleft);
    steps.push_back(setmax_level_frontright);
    steps.push_back(setmax_rotation_frontright);
    steps.push_back(setmax_level_backright);
    steps.push_back(setmax_rotation_backright);
    steps.push_back(setmin_level_frontright);
    steps.push_back(setmin_rotation_frontright);
    steps.push_back(setmin_level_backright);
    steps.push_back(setmin_rotation_backright);

    setStepZero();
}

bool MoveForward::createDefaultMoveStep(LegsOrder current_leg, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle) {
    MoveStatus move_status = MoveStatus::ReadyToGo;
    if (move_joint_type == MoveJointType::Level) {
        legs_vector[current_leg]->setLevelAngleWithAcceleration(target_angle, 5);
        move_status = legs_vector[current_leg]->getLevelMoveStatus();
    }
    else {
        legs_vector[current_leg]->setRotationAngleWithAcceleration(target_angle, 5);
        move_status = legs_vector[current_leg]->getRotationMoveStatus();
    }

    if (move_status == MoveStatus::Finished) {
        setNextStep();
        legs_vector[current_leg]->resetMoveStatus();

        return true;
    };


    return false;
}

bool MoveForward::createDefaultMoveStepWithWait(LegsOrder current_leg, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle, int wait_time) {
    MoveStatus move_status = MoveStatus::ReadyToGo;
    if (move_joint_type == MoveJointType::Level) {
        legs_vector[current_leg]->setLevelAngleWithAcceleration(target_angle, 5);
        move_status = legs_vector[current_leg]->getLevelMoveStatus();
    }
    else {
        legs_vector[current_leg]->setRotationAngleWithAcceleration(target_angle, 5);
        move_status = legs_vector[current_leg]->getRotationMoveStatus();
    }

    if (move_status == MoveStatus::Finished) {
        if (wait_)
        {
            if (timePast(wait_time_, wait_time))
            {
                setNextStep();
                legs_vector[current_leg]->resetMoveStatus();
                wait_ = false;
            }
            return true;
        }
        else
        {
            wait_time_ = HAL_GetTick();
            wait_ = true;
        }



        return true;
    };

    return false;
};

bool MoveForward::createParallelMoveStep(std::vector<LegsOrder> legs_to_move, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle)
{
    MoveStatus move_status = MoveStatus::ReadyToGo;
    bool move_finished_for_all = true;

    for (auto& current_leg : legs_to_move) {
        if (move_joint_type == MoveJointType::Level) {
            legs_vector[current_leg]->setLevelAngleWithAcceleration(target_angle, 5);
            move_finished_for_all = move_finished_for_all && (legs_vector[current_leg]->getLevelMoveStatus() == MoveStatus::Finished);
        }
        else {
            legs_vector[current_leg]->setRotationAngleWithAcceleration(target_angle, 5);
            move_finished_for_all = move_finished_for_all && (legs_vector[current_leg]->getRotationMoveStatus() == MoveStatus::Finished);
        }
    };

    move_status = move_finished_for_all ? MoveStatus::Finished : MoveStatus::Moving;

    if (move_status == MoveStatus::Finished) {
        
        setNextStep();

        for (auto& current_leg : legs_to_move) {
        legs_vector[current_leg]->resetMoveStatus();
        };

        return true;
    };

    return false;
}
