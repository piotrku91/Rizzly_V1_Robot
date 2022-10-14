#pragma once

#include "InputInterface.hpp"

class InputHardwareButtons : public InputInterface
{
    public:
    InputHardwareButtons() {};

    virtual InputAxis getInput() override;
};