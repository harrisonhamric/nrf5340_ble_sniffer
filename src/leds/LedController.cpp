#include "LedController.h"

LedController::LedController(): _blink_status(0)
{

}

void LedController::Init()
{
    ReturnCode rc = (ReturnCode)dk_leds_init();
    CHECK_RETURN_CODE(rc);
}

void LedController::SwitchAllLeds()
{
    dk_set_leds(DK_ALL_LEDS_MSK);
}

void LedController::SetAllLedsOn()
{
    for(uint8_t i=0; i < 4; i++)
    {
        dk_set_led_on(i);
    }
}

void LedController::SetAllLedsOff()
{
    for(uint8_t i=0; i < 4; i++)
    {
        dk_set_led_off(i);
    }
}

void LedController::SetLED(uint8_t LED)
{
    ReturnCode rc;
    for(uint8_t i=0; i < 4; i++)
    {
        if(i == LED)
        {
            rc = (ReturnCode) dk_set_led_on(LED);
        }
        else
        {
            rc = (ReturnCode) dk_set_led_off(i);
        }
    }
}

// void LedController::InitLED(uint8_t LED)
// {
//     ReturnCode rc = dk_set_led_on(LED3);
//     CHECK_RETURN_CODE(rc);
// }
