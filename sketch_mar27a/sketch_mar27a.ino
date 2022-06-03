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
  for(int i = 0; i < 256; i++){
        matrix.setPixelColor(i, matrix.Color(0,0,0));
      }
  matrix.show();
  
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


    if (lum.toInt() == 0) {
      matrix.setPixelColor(pix.toInt(), matrix.Color(255, 0, 0));
    }
    if(lum.toInt() == 1) {
      matrix.setPixelColor(pix.toInt(), matrix.Color(0, 255, 0));
    }
    if(lum.toInt() == 2) {
      for(int i = 0; i < 256; i++){
        matrix.setPixelColor(i, matrix.Color(0,0,0));
      }
    }
    
    matrix.show();


    chaine = "";

  }


}
