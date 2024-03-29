/*
 * MoveForward.hpp
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#ifndef MOVES_MOVEFORWARD_HPP_
#define MOVES_MOVEFORWARD_HPP_

#include "MovePattern.hpp"
#include "defines.hpp"

class MoveForward : public MovePattern, MovePatternLegsInput
{
public:
    MoveForward(LegsVector& legs);
    virtual ~MoveForward() {};

private:
    virtual bool createDefaultMoveStep(LegsOrder current_leg, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle) override;
    virtual bool createParallelMoveStep(std::vector<LegsOrder> legs_to_move, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle) override;
    virtual bool createDefaultMoveStepWithWait(LegsOrder current_leg, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle, int wait_time) override;
};

#endif /* MOVES_MOVEFORWARD_HPP_ */
