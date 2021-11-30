#include <stdint.h>
#include <dk_buttons_and_leds.h>

enum class ButtonState : uint32_t
{
    Default = 0,
    Button1 = DK_BTN1_MSK,
    Button2 = DK_BTN2_MSK,
    Button3 = DK_BTN3_MSK,
    Button4 = DK_BTN4_MSK,
    AllButtons = DK_ALL_BTNS_MSK
};