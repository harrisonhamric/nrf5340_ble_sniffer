#pragma once

#include <sys/printk.h>
#include <stdint.h>
#include <dk_buttons_and_leds.h>

#include "ReturnCode.h"
#include "HelperFunctions.h"
#include "LedController.h"
#include "Buttons.h"
#include "Sniffer.h"
#include "bleCentral.h"

class Sniffer 
{
public:
    Sniffer();
    void Run(void);
    LedController GetLeds();
    bleCentral GetBle();
private:
    LedController _LEDS;
    Buttons _buttons;
    bleCentral _ble;
};