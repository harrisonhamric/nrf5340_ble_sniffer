#include <zephyr.h>

#include <sys/printk.h>
#include <stdint.h>
#include <dk_buttons_and_leds.h>

#include "ReturnCode.h"
#include "HelperFunctions.h"
#include "LedController.h"
#include "Buttons.h"
#include "Sniffer.h"
#include "bleCentral.h"

#define SLEEP_TIME 500

int main()
{   
    Sniffer daSniff = Sniffer();
    daSniff.Run();
    LedController localLEDS = daSniff.GetLeds();
    bleCentral localBle = daSniff.GetBle();
    uint8_t sleepTimeFromSigStrength; // = 3000
    for (;;) {
        sleepTimeFromSigStrength = localBle.GetSleepTimeFromSigStrength();
        localLEDS.SetAllLedsOn();
		k_sleep(K_MSEC(sleepTimeFromSigStrength));
        localLEDS.SetAllLedsOff();
        k_sleep(K_MSEC(sleepTimeFromSigStrength));
	}
    return 0;
}