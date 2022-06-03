#include <Adafruit_NeoPixel.h>

#define PIN 6              // Arduino pin 6 to DIN of 8x32 matrix.
#define LED_COUNT 256      // 8x32 = 256 NeoPixel leds
#define BRIGHTNESS 80      // to reduce current for 256 NeoPixels

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

int i = 0;

void setup() 
{
  strip.begin();
  strip.show();            // Initialize all pixels to 'off'
  strip.setBrightness(BRIGHTNESS);   // overall brightness
}


void loop() 
{
for (int j=0; j<10; j++)   //do 10 cycles of chasing
  {
    for (int q=0; q < 3; q++) 
    {
      for (int i=0; i < strip.numPixels(); i=i+3) 
      {
        strip.setPixelColor(i+q, strip.Color(0,255,255));    //turn every third pixel on
      }
      strip.show();

      delay(5);

      for (int i=0; i < strip.numPixels(); i=i+3) 
      {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }

}


uint32_t Wheel(byte WheelPos) 
{
  if(WheelPos < 85) 
  {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) 
  {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else 
  {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
