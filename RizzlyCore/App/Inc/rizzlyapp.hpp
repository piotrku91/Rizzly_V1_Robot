/*
 * rizzlyapp.hpp
 *
 *  Created on: May 24, 2022
 *      Author: piotr
 */

#ifndef APP_INC_RIZZLYAPP_HPP_
#define APP_INC_RIZZLYAPP_HPP_

#include "tim.h"
#include "gpio.h"
#include "ServoDriver.hpp"
#include "defines.hpp"
#include <mpu_armv7.h>
#include <memory>
#include <map>

void RizzlyAppMainLoop();
void RizzlyAppInit();


#endif /* APP_INC_RIZZLYAPP_HPP_ */
