#include <arduino.h>
#include "u8g2Spiral.h"

U8g2Spiral u8g2Spiral = U8g2Spiral();

void setup(void)
{
  u8g2Spiral.begin();
  // u8g2Spiral.start();
}

void loop(void)
{
  u8g2Spiral.DrawSpiral(10);
  delay(200);
  u8g2Spiral.clearBuffer();
  u8g2Spiral.sendBuffer();
}