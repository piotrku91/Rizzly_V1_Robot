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

enum class MoveJointType
{
    Level,
    Rotation
};

class MoveForward : public MovePattern, MovePatternLegsInput
{
public:
    MoveForward(LegsVector& legs);
    void run() override;
    virtual ~MoveForward() {};

private:
    inline bool moveForwardStandardStepCreate(LegsOrder current_leg, LegsVector& legs_vector, MoveJointType move_joint_type, uint16_t target_angle);
    

};

#endif /* MOVES_MOVEFORWARD_HPP_ */
