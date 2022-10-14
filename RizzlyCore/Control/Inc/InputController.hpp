#pragma once
#include <memory>
#include "InputInterface.hpp"

class InputController final
{
    private:
    InputInterface* Input_;
    
    public:
    InputController(InputInterface* input):Input_{input} {};
    InputController():Input_{nullptr} {};

    void changeInput(InputInterface* input);

    InputAxis detectInput();
};
