#pragma once

#include <dk_buttons_and_leds.h>
#include "ReturnCode.h"
#include "HelperFunctions.h"

#define LED1 DK_LED1
#define LED2 DK_LED2
#define LED3 DK_LED3
#define LED4 DK_LED4
#define LEDNONE 5

#define RUN_LED_BLINK_INTERVAL 2000

class LedController
{
public:
    LedController();
    void Init();
    static void SetLED(uint8_t LED);
    void SetAllLedsOn();
    void SwitchAllLeds();
    void SetAllLedsOff();
private:
    uint32_t _blink_status;
};