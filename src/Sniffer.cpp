#include "Sniffer.h"


// static void LEDButtonHandler(uint32_t button_state, uint32_t has_changed)
// {
//     ButtonState bs = (ButtonState) button_state;
//     switch(bs)
//     {
//     case ButtonState::Button1:
//         LedController::SetLED(LED1);
//         break;
//     case ButtonState::Button2:
//         LedController::SetLED(LED2);
//         break;
//     case ButtonState::Button3:
//         LedController::SetLED(LED3);
//         break;
//     case ButtonState::Button4:
//         LedController::SetLED(LED4);
//         break;
//     default:
//         LedController::SetLED(LEDNONE);
//         break;
//     }
// }

Sniffer::Sniffer(): 
                _LEDS(),
                _buttons(),
                _ble()
{

}

void Sniffer::Run()
{
    _LEDS.Init();
    _ble.InitBleScanner();
    // _buttons.Init((button_handler_t)LEDButtonHandler());
    // dk_buttons_init(LEDButtonHandler);
}

LedController Sniffer::GetLeds()
{
    return _LEDS;
}

bleCentral Sniffer::GetBle()
{
    return _ble;
}


