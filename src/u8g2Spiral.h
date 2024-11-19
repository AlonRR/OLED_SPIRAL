
#include <Arduino.h>
#include <U8g2lib.h>
#include "../lib/setup_for_oled.hpp"

class U8g2Spiral : public U8G2_SSD1315_128X64_NONAME_F_HW_I2C
{
public:
    U8g2Spiral();
    void DrawSpiral(int8_t cycles);
};
