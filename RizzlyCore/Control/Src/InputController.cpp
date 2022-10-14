#include "InputController.hpp"

InputAxis InputController::detectInput()
{
   if (Input_) {
      return Input_->getInput();
   }
   return InputAxis::None;
}

void InputController::changeInput(InputInterface* input)
{
   Input_ = input;

}