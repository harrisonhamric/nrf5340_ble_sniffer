#include "bleCentral.h"

uint8_t globalSigStrength;

void bleCentral::InitBleScanner()
{
    _bleScanParameter = {
        .type = BT_LE_SCAN_TYPE_ACTIVE,
        .options = BT_LE_SCAN_OPT_NONE, //might change this to long range = BT_LE_SCAN_OPT_CODED
        .interval = BT_GAP_SCAN_FAST_INTERVAL,
        .window = BT_GAP_SCAN_FAST_WINDOW,
        .timeout = 0,
    };

    globalSigStrength = 0;
}

void bleCentral::BleScannerFoundCallback(const bt_addr_le_t* addr, int8_t rssi, uint8_t type,
                                        struct net_buf_simple* ad)
{
    if(rssi > globalSigStrength)
    {
        globalSigStrength = rssi;
    }
}

void bleCentral::StartScanBle()
{
    int err;

    err = bt_le_scan_start(&_bleScanParameter, BleScannerFoundCallback);

    if (err)
    {
        printk("SCANNING FAILED TO START");
        return;
    }
}

uint8_t bleCentral::GetSignalStrength()
{
    return globalSigStrength;
}

uint8_t bleCentral::GetSleepTimeFromSigStrength()
{
    uint8_t localSigStrength = GetSignalStrength();
    //sigstrength is 0-255, we need a time eq that will be like 0-2000 lol
    double logResult = log(localSigStrength);
    uint8_t result = (-700 * logResult) + 1750;
    return result;
}