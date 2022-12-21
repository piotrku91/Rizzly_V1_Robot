#pragma once

#include "InputInterface.hpp"

class InputHardwareButtons : public InputInterface
{
    private:
    int last_;
    int debounceTime_;

    public:
    InputHardwareButtons():last_(0), debounceTime_(100) {};

    virtual InputAxis getInput() override;
};
