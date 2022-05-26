/*
 * template_defines.hpp
 *
 *  Created on: May 24, 2022
 *      Author: piotr
 */

#ifndef COMMONUTILS_TEMPLATE_DEFINES_HPP_
#define COMMONUTILS_TEMPLATE_DEFINES_HPP_

template <typename T>
T MapValue(T input, T input_minimum_of_range, T input_maximum_of_range, T output_minimum_of_range, T output_maximum_of_range) {
    return ((((input - input_minimum_of_range) * (output_maximum_of_range - output_minimum_of_range)) / (input_maximum_of_range - input_minimum_of_range)) + output_minimum_of_range);
}

template <typename T1>
bool timePast(T1 timestamp, T1 target_time) {
    if ((HAL_GetTick() - timestamp) < target_time) {
        return true;
    }
    return false;
}

#endif /* COMMONUTILS_TEMPLATE_DEFINES_HPP_ */
