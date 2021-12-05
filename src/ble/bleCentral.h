#pragma once
// #include <zephyr.h>
#include <bluetooth/bluetooth.h>
#include <sys/printk.h>
#include <math.h>

extern uint8_t globalSigStrength;

class bleCentral 
{
private:
    uint8_t _signalStrength;
    struct bt_le_scan_param _bleScanParameter;
    
public:
    void InitBleScanner();
    void StartScanBle();
    uint8_t GetSignalStrength();
    uint8_t GetSleepTimeFromSigStrength();
    static void BleScannerFoundCallback(const bt_addr_le_t* addr, int8_t rssi, uint8_t type,
                                        struct net_buf_simple* ad); //idk if this right
};