#include "InputHardwareButtons.hpp"
#include "gpio.h"
#include "defines.hpp"

InputAxis InputHardwareButtons::getInput() 
{
	if ((HAL_GPIO_ReadPin(GPIOA, 0)) && (HAL_GetTick() - last_ >= debounceTime_)) {
		last_ = HAL_GetTick();
		return InputAxis::Front;
	};
    return InputAxis::None;
}
