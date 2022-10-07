#include "MovePattern.hpp"


void MovePattern::run(LegsVector& legs) {
    if (!isAnyStep()) {
        return;
    };

    if (*current_step_ && current_step_ != steps.end()) {
        (*current_step_)(legs);
    }
    else {
        setStepZero();
    }
}

size_t MovePattern::isAnyStep() { return (steps.size() > 0); };

bool MovePattern::setNextStep()
{
    if (current_step_ != steps.end()) { current_step_++; return true; }; return false;
};

void MovePattern::setStepZero() { current_step_ = steps.begin(); };
