#pragma once

#include <stdint.h>

#include "ReturnCode.h"
#include "HelperFunctions.h"
#include "ButtonState.h"

class Buttons 
{
public: 
    Buttons();
    void Init(button_handler_t buttonHandler);
    ButtonState GetButtonState();
private:
    ButtonState _buttonState;
};