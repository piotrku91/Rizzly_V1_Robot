#pragma once

#include <stdint.h>

class MoveableLevel {
protected:
    bool levelInMove_{false};
    virtual void setLevelAngle(uint16_t target_angle) = 0;
    virtual void setLevelAngleWithAcceleration(uint16_t target_angle, uint16_t acceleration_step) = 0;
public:
    virtual bool levelInMove() { return levelInMove_; };
};

class MoveableRotation {
protected:
    bool rotationInMove_{false};
    virtual void setRotationAngle(uint16_t target_angle) = 0;
    virtual void setRotationAngleWithAcceleration(uint16_t target_angle, uint16_t acceleration_step) = 0;

public:
    virtual bool rotationInMove() { return rotationInMove_; };
};

class FullMoveable : public MoveableLevel, public MoveableRotation {
    virtual void setAll(uint16_t level_target_angle, uint16_t rotation_target_angle) = 0;
    virtual void setAllWithAcceleration(uint16_t level_target_angle, uint16_t rotation_target_angle, uint16_t acceleration_step) = 0;

public:
    virtual bool inMove() { return (levelInMove_ && rotationInMove_); };
};