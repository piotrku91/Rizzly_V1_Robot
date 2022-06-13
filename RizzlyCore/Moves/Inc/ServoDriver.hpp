/*
 * ServoDriver.hpp
 *
 *  Created on: May 24, 2022
 *      Author: piotr
 */

#ifndef SERVODRIVER_HPP_
#define SERVODRIVER_HPP_

#include "stm32f4xx_hal.h"
#include "template_defines.hpp"
#include "common_interfaces.hpp"
#include <map>
#include <memory>

enum class ServoOrder;
class ServoDriver;
using ServoDriverPtr = std::shared_ptr<ServoDriver>;
using ServosVector = std::map<ServoOrder, ServoDriverPtr>;

class ServoDriver : public Initable{
private:
    TIM_HandleTypeDef* htim_;
    uint32_t channel_;
    uint16_t min_angle_;
    uint16_t max_angle_;
    uint16_t min_microsecs_;
    uint16_t max_microsecs_;
    uint16_t current_position_angle_;
    uint16_t target_position_angle_;
    bool inmove_;
	bool locked_;

public:
    ServoDriver(TIM_HandleTypeDef* htim, uint32_t channel, uint16_t min_angle_, uint16_t max_angle, uint16_t min_microsecs, uint16_t max_microsecs, bool init_by_ctor = false);
    virtual ~ServoDriver();

	void init() override;
	void deinit() override;

    void setTargetAngle(uint16_t target_angle);
	void moveToAngleWithAcceleration(uint16_t acceleration_step);
    void moveToAngle();
    void moveToMicrosecs(uint16_t microsecs);
	void lock();
	void unlock();
	bool isLocked() const;
	bool inMove() const;
    bool inTargetPosition() const;

    private:
    void setCurrentPositionAngle(uint16_t new_current_angle);
};


#endif /* SERVODRIVER_HPP_ */
