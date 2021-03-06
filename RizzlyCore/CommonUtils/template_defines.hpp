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
    if ((HAL_GetTick() - timestamp) > target_time) {
        return true;
    }
    return false;
}
class DelayedExecutor {
private:
    uint32_t time_;
    uint32_t begin_time_stamp_;
    bool started_;

public:
    DelayedExecutor()
        : time_{0}, begin_time_stamp_{0}, started_{false} {};

    bool isDone() {
        if (time_ == 0) {
            return true;
        };
        return (started_ && timePast(begin_time_stamp_, time_));
    };
    bool isStarted() const { return started_; };

    void start(uint32_t time_to_wait) {
        if (!isStarted()) {
        time_ = time_to_wait;
        begin_time_stamp_ = HAL_GetTick();
        started_ = true;
        }

        if (time_ == 0) {started_ = true;};
    };

    void reset() {
        if (started_) {
        time_ = 0;
        started_ = false;
        };
    }

    bool operator()() {
        return isDone();
    }
};

#endif /* COMMONUTILS_TEMPLATE_DEFINES_HPP_ */
