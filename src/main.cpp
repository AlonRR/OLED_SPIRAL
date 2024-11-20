#include <arduino.h>
#include "u8g2Spiral.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8g2Spiral u8g2Spiral = U8g2Spiral();

void setup(void)
{
  u8g2Spiral.begin();
}

void loop(void)
{
  u8g2Spiral.DrawSpiral(10);
  u8g2Spiral.clearBuffer();
  u8g2Spiral.sendBuffer();
}