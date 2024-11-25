#include "u8g2Spiral.h"
#define HEIGHT 64
#define WIDTH 128

U8g2Spiral::U8g2Spiral() : U8G2_SSD1315_128X64_NONAME_F_HW_I2C(U8G2_R0, /* reset=*/U8X8_PIN_NONE)
{
    setFont(u8g2_font_6x10_tf);
    setFontRefHeightExtendedText();
    setDrawColor(1);
    setFontPosTop();
    setFontDirection(0);
}

void U8g2Spiral::DrawSpiral(int8_t cycles)
{
    int x = WIDTH / 2;
    int y = HEIGHT / 2;
    int length = 1;
    drawStr(0, 0, "Spiral");
    for (int8_t i = 0; i < cycles; i++)
    {
        for (int8_t j = 0; j < 4; j++)
        {
            length++;
            switch (j)
            {
            case 0:
                drawLine(x, y, x + length, y);
                x += length;
                break;
            case 1:
                drawLine(x, y, x, y - length);
                y -= length;
                break;
            case 2:
                drawLine(x, y, x - length, y);
                x -= length;
                break;
            case 3:
                drawLine(x, y, x, y + length);
                y += length;
                break;
            }
            sendBuffer();
            delay(100);
        }
    }
}
