#pragma once 

#include <stdint.h>

class MoveableLevel {
	protected:
	virtual void setLevelAngle(uint16_t target_angle) = 0;
};

class MoveableRotation {
	protected:
	virtual void setRotationAngle(uint16_t target_angle) = 0;
};

class FullMoveable : public MoveableLevel, public MoveableRotation {
    virtual void setAngle(uint16_t level_target_angle, uint16_t rotation_target_angle) = 0;
};