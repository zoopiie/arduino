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
String red;
String blue;
String green;

void setup()
{

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  Serial.begin(9600);
  Serial.setTimeout(1);


  matrix.begin();           // Initialize all pixels to 'off'
  matrix.setBrightness(25);   // overall brightness
  
 delay(100);
}


void loop()
{
  while (Serial.available() > 0) {
    chaine += char(Serial.read());
    delay(2);
  }
  if (chaine != "") {
    lum = chaine.substring(0, 1);
    red = chaine.substring(1, 4);
    green = chaine.substring(4, 7);
    blue = chaine.substring(7, 10);
    pix = chaine.substring(10, 13);

    if (lum.toInt() == 2){
      for (int i = 0; i < 257; i++){
        matrix.setPixelColor(i,matrix.Color(255, 255, 255));
        
      }
    }

    if (lum.toInt() == 3){
      for (int i = 0; i < 257; i++){
        matrix.setPixelColor(i,matrix.Color(0, 0, 0));
        
      }
    }


    if (lum.toInt() == 1) {
      matrix.setPixelColor(pix.toInt(), matrix.Color(red.toInt(), green.toInt(), blue.toInt()));
    }
    else if(lum.toInt() == 0) {
      matrix.setPixelColor(pix.toInt(), matrix.Color(0,0,0));
    }
    matrix.show();


    chaine = "";

  }
  delay(10);


}
