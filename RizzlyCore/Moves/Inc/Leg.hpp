/*
 * Leg.hpp
 *
 *  Created on: 24 maj 2022
 *      Author: piotr
 */

#ifndef MOVES_LEG_HPP_
#define MOVES_LEG_HPP_

#include <utility>
#include "ServoDriver.hpp"
#include "moveable.hpp"

class Leg : public FullMoveable {
private:
    ServoDriverPtr levelJoint_;
    ServoDriverPtr rotationJoint_;

public:
    Leg(ServoDriverPtr level_joint, ServoDriverPtr rotation_joint);

    void setLevelAngle(uint16_t target_angle) override;
    void setRotationAngle(uint16_t target_angle) override;
    void setAngle(uint16_t level_target_angle, uint16_t rotation_target_angle) override;

    virtual ~Leg();
};

#endif /* MOVES_LEG_HPP_ */
