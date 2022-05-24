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

class ServoDriver : public Initable{
private:
    TIM_HandleTypeDef* htim_;
    uint32_t channel_;
    uint16_t min_angle_;
    uint16_t max_angle_;
    uint16_t min_microsecs_;
    uint16_t max_microsecs_;
    uint16_t current_position_angle_;
	bool locked_;

public:
    ServoDriver(TIM_HandleTypeDef* htim, uint32_t channel, uint16_t min_angle_, uint16_t max_angle, uint16_t min_microsecs, uint16_t max_microsecs);
    virtual ~ServoDriver();

	void init() override;
	void deinit() override;

    void moveToAngle(uint16_t angle);
    void moveToMicrosecs(uint16_t microsecs);
	void lock();
	void unlock();
	bool isLocked() const;
};
#endif /* SERVODRIVER_HPP_ */
