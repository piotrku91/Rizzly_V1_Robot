/*
 * MovePattern.hpp
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#ifndef MOVES_INC_MOVEPATTERN_HPP_
#define MOVES_INC_MOVEPATTERN_HPP_

#include "Leg.hpp"
#include "defines.hpp"
#include <vector>
#include <functional>

using MoveStep = std::function<bool(LegsVector&)>;

class MovePatternLegsInput
{
    protected:
    LegsVector& legs_;

    public:
    MovePatternLegsInput(LegsVector& legs):legs_(legs){};
};

class MovePattern {
    protected:
    std::vector<MoveStep> steps;
    std::vector<MoveStep>::iterator current_step_;
    bool wait_;
    int wait_time_;



    public:
    MovePattern(): wait_(false), wait_time_(0){};
    virtual void run(LegsVector& legs);
    virtual bool createDefaultMoveStep(LegsOrder current_leg, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle);
    virtual bool createParallelMoveStep(std::vector<LegsOrder> legs_to_move, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle);
    virtual bool createDefaultMoveStepWithWait(LegsOrder current_leg, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle, int wait_time);
    size_t isAnyStep();
    bool setNextStep();
    void setStepZero();

};
#endif /* MOVES_INC_MOVEPATTERN_HPP_ */
