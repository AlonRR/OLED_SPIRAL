#include <U8g2lib.h>

#ifndef SETUP_FOR_OLED_HPP
#define SETUP_FOR_OLED_HPP

class U8G2_SSD1315_128X64_NONAME_F_HW_I2C : public U8G2
{
public:
    U8G2_SSD1315_128X64_NONAME_F_HW_I2C(
        const u8g2_cb_t *rotation,
        uint8_t reset = U8X8_PIN_NONE,
        uint8_t clock = U8X8_PIN_NONE,
        uint8_t data = U8X8_PIN_NONE) : U8G2()
    {
        u8g2_Setup_ssd1306_i2c_128x64_noname_f(
            &u8g2,
            rotation,
            u8x8_byte_arduino_hw_i2c, u8x8_gpio_and_delay_arduino);
        u8x8_SetPin_HW_I2C(getU8x8(), reset, clock, data);
    }
    bool begin(void) // This overrides the begin method in U8G2
    {
/* note: call to u8x8_utf8_init is not required here, this is done in the setup procedures before */
#ifndef U8G2_USE_DYNAMIC_ALLOC
        initDisplay();
        setFlipMode(1);
        clearDisplay();
        sendBuffer();
        setFlipMode(0);
        clearDisplay();
        sendBuffer();
        setPowerSave(0); // Display ON
        return 1;
#else
        return 0;
#endif
    }
};

#endif // SETUP_FOR_OLED_HPP