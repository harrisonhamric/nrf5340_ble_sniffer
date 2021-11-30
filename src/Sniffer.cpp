#include <zephyr.h>

#include <sys/printk.h>
#include <stdint.h>
#include <dk_buttons_and_leds.h>

#include "ReturnCode.h"
#include "HelperFunctions.h"
#include "LedController.h"
#include "Buttons.h"
#include "Sniffer.h"

#define SLEEP_TIME 500

static void LEDButtonHandler(uint32_t button_state, uint32_t has_changed)
{
    ButtonState bs = (ButtonState) button_state;
    switch(bs)
    {
    case ButtonState::Button1:
        LedController::SetLED(LED1);
        break;
    case ButtonState::Button2:
        LedController::SetLED(LED2);
        break;
    case ButtonState::Button3:
        LedController::SetLED(LED3);
        break;
    case ButtonState::Button4:
        LedController::SetLED(LED4);
        break;
    default:
        LedController::SetLED(LEDNONE);
        break;
    }
}

Sniffer::Sniffer(): 
                _LEDS(),
                _buttons()
{

}

void Sniffer::Run()
{
    _LEDS.Init();
    // _buttons.Init((button_handler_t)LEDButtonHandler());
    // dk_buttons_init(LEDButtonHandler);
}

LedController Sniffer::GetLeds()
{
    return _LEDS;
}


int main()
{   
    Sniffer daSniff = Sniffer();
    daSniff.Run();
    LedController localLEDS = daSniff.GetLeds();
    //BluetoothController BLE = daSniff.GetBLE();
    for (;;) {
        localLEDS.SetAllLedsOn();
		k_sleep(K_MSEC(SLEEP_TIME));
        localLEDS.SetAllLedsOff();
        k_sleep(K_MSEC(SLEEP_TIME));
	}
    return 0;
}