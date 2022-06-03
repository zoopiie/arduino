#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#ifdef __AVR__
#include <avr/power.h>
#endif



#define PIN 6              // Arduino pin 6 to DIN of 8x32 matrix.


Adafruit_NeoPixel matrix = Adafruit_NeoPixel(256, PIN, NEO_GRB + NEO_KHZ800);

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
clock_prescale_set(clock_div_1);
#endif


String chaine;
String lum;
String pix;

void setup()
{

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  Serial.begin(9600);
  Serial.setTimeout(1);


  matrix.begin();           // Initialize all pixels to 'off'
  matrix.setBrightness(18);   // overall brightness
  
 delay(100);
 rainbow(1);
}


void loop()
{
  while (Serial.available() > 0) {
    chaine += char(Serial.read());
    delay(2);
  }
  if (chaine != "") {
    lum = chaine.substring(0, 1);
    pix = chaine.substring(1, 4);

    if (lum.toInt() == 2){
      rainbow(1);
    }

    if (lum.toInt() == 3){
      for (int i = 0; i < 257; i++){
        matrix.setPixelColor(i,matrix.Color(0, 0, 0));
        
      }
    }


    if (lum.toInt() == 0) {
      matrix.setPixelColor(pix.toInt(), matrix.Color(0, 0, 0));
    }
    else if(lum.toInt() == 1) {
      matrix.setPixelColor(pix.toInt(), Wheel((pix.toInt()) & 255));
    }
    matrix.show();


    chaine = "";

  }
  delay(10);


}



void rainbow(uint8_t wait)
{

  for (int i = 0; i < 257; i++)
  {
    matrix.setPixelColor(i, Wheel((i) & 255));
  }
  matrix.show();
  delay(wait);

}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85)
  {
    return matrix.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  else if (WheelPos < 170)
  {
    WheelPos -= 85;
    return matrix.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  else
  {
    WheelPos -= 170;
    return matrix.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
