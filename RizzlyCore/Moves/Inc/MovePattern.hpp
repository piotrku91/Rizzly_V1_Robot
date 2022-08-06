/*
 * MovePattern.hpp
 *
 *  Created on: Jun 13, 2022
 *      Author: piotr
 */

#ifndef MOVES_INC_MOVEPATTERN_HPP_
#define MOVES_INC_MOVEPATTERN_HPP_

#include "Leg.hpp"
#include <vector>
#include <functional>

using MoveStep = std::function<bool(LegsVector&)>;

class MovePatternLegsInput
{
    protected:
    LegsVector& legs_;

    public:
    MovePatternLegsInput(LegsVector& legs):legs_(legs){};
};

class MovePattern {
    protected:
    std::vector<MoveStep> steps;
    std::vector<MoveStep>::iterator current_step_;

    public:
    virtual void run() = 0;
    size_t isAnyStep() {return (steps.size() > 0);};
    bool setNextStep() 
    {if (current_step_ != steps.end()) {current_step_++; return true;}; return false;}; 
    void setStepZero() {current_step_ = steps.begin();};
};


#endif /* MOVES_INC_MOVEPATTERN_HPP_ */
