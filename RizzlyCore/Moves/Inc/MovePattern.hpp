/*
 * MovePattern.hpp
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#ifndef MOVES_INC_MOVEPATTERN_HPP_
#define MOVES_INC_MOVEPATTERN_HPP_

#include "Leg.hpp"

class MovePattern {
    protected:
    size_t current_step_{0};
    size_t all_steps_count_{0};

    public:
    virtual void run(LegsVector& Legs) = 0;
    size_t isAnyStep() {return (all_steps_count_ > 0);};
    void setCurrentStep(size_t new_step) { if (new_step < all_steps_count_) {current_step_ = new_step;};};
    void setStepsCount(size_t new_step_count) {all_steps_count_ = new_step_count;};
    bool setNextStep() {if (current_step_ < all_steps_count_) {current_step_++; return true;}; 
    if (current_step_ == all_steps_count_) {setStepZero(); 
    }
    return false;
    };
    void setStepZero() {current_step_ = 0;};
};


#endif /* MOVES_INC_MOVEPATTERN_HPP_ */
