#include "Buttons.h"

Buttons::Buttons(): _buttonState(ButtonState::Default)
{

}

void Buttons::Init(button_handler_t buttonHandler)
{
    ReturnCode rc = (ReturnCode) dk_buttons_init(buttonHandler);
    CHECK_RETURN_CODE(rc);
}

ButtonState Buttons::GetButtonState()
{
    return (ButtonState)dk_get_buttons();
}
