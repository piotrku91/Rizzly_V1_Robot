#pragma once

#include <stdint.h>

enum class MoveStatus
{
    ReadyToGo,
    Moving,
    Finished
};


class MoveableLevel {
protected:
    MoveStatus levelMoveState_{MoveStatus::ReadyToGo};
    virtual void setLevelAngle(uint16_t target_angle) = 0;
    virtual void setLevelAngleWithAcceleration(uint16_t target_angle, uint16_t acceleration_step) = 0;

public:
    MoveStatus getLevelMoveStatus() { return levelMoveState_; };
   void levelStatusReset() {levelMoveState_ = MoveStatus::ReadyToGo;};
};

class MoveableRotation {
protected:
    MoveStatus rotationMoveState_{MoveStatus::ReadyToGo};
    virtual void setRotationAngle(uint16_t target_angle) = 0;
    virtual void setRotationAngleWithAcceleration(uint16_t target_angle, uint16_t acceleration_step) = 0;

public:
    MoveStatus getRotationMoveStatus() { return rotationMoveState_; };
    void rotationStatusReset() {rotationMoveState_ = MoveStatus::ReadyToGo;};
};

class FullMoveable : public MoveableLevel, public MoveableRotation {
    virtual void setAll(uint16_t level_target_angle, uint16_t rotation_target_angle) = 0;
    virtual void setAllWithAcceleration(uint16_t level_target_angle, uint16_t rotation_target_angle, uint16_t acceleration_step) = 0;

public:
    void resetMoveStatus() {levelMoveState_ = MoveStatus::ReadyToGo; rotationMoveState_ = MoveStatus::ReadyToGo;};
    bool finished() {return (getLevelMoveStatus() == MoveStatus::Finished && getRotationMoveStatus() == MoveStatus::Finished);};
};
