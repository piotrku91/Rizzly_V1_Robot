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
#include "Moveable.hpp"
#include <map>
#include <memory>

enum class MoveJointType
{
    Level,
    Rotation
};

enum class LegsOrder;
class Leg;
using LegsVector = std::map<LegsOrder, std::shared_ptr<Leg>>;


class Leg : public FullMoveable {
private:
    ServoDriverPtr levelJoint_;
    ServoDriverPtr rotationJoint_;

public:
    Leg(ServoDriverPtr level_joint, ServoDriverPtr rotation_joint);

    /* 
    @brief Sets target angle immediately without acceleration steps
    @param target_angle Target servo position
    */
    void setLevelAngle(uint16_t target_angle) override;

     /* 
    @brief Sets target angle immediately without acceleration steps
    @param target_angle Target servo position
    */
    void setRotationAngle(uint16_t target_angle) override;

     /* 
    @brief Sets target angles immediately without acceleration steps
    @param target_angle Target servo position
    */
    void setAll(uint16_t level_target_angle, uint16_t rotation_target_angle) override;

    /* 
    @brief Sets target angle and acceleration step in level joint 
    @param target_angle Target servo position
    @param acceleration_step Step of acceleration
    */
    void setLevelAngleWithAcceleration(uint16_t target_angle, uint16_t acceleration_step) override;

    /* 
    @brief Sets target angle and acceleration step in rotation joint 
    @param target_angle Target servo position
    @param acceleration_step Step of acceleration
    */
    void setRotationAngleWithAcceleration(uint16_t target_angle, uint16_t acceleration_step) override;

    /* 
    @brief Sets target angle and acceleration sttep in level and rotation joints
    @param level_target_angle Target servo level position
    @param rotation_target_angle Target servo rotation position
    @param acceleration_step Step of acceleration
    */
    void setAllWithAcceleration(uint16_t level_target_angle, uint16_t rotation_target_angle, uint16_t acceleration_step) override;

    virtual ~Leg();
};

#endif /* MOVES_LEG_HPP_ */
