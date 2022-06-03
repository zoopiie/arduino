#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> 
#endif

#define PIN        6 

#define NUMPIXELS 16 

int x;
int i = 0;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 

void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
Serial.begin(9600);
Serial.setTimeout(1);
  

  pixels.begin();
}

void loop() {
  i++;
  if (i > 256){
    i = 0;
  }
    pixels.setPixelColor(((i + 1) % 16), pixels.Color(255 , 95 , 0));
    pixels.show();  
    delay(10);
    pixels.setPixelColor(((i + 2) % 16), pixels.Color(255 , 191 , 0));
    pixels.show(); 
    delay(10);
    pixels.setPixelColor(((i + 3) % 16), pixels.Color(224 , 255 , 0));
    pixels.show();  
    delay(10);
    pixels.setPixelColor(((i + 4) % 16), pixels.Color(128 , 255 , 0));
    pixels.show();  
    delay(10);
    pixels.setPixelColor(((i + 5) % 16), pixels.Color(32 , 255 , 0));
    pixels.show(); 
    delay(10);
    pixels.setPixelColor(((i + 6) % 16), pixels.Color(0 , 255 , 63));
    pixels.show(); 
    delay(10);
    pixels.setPixelColor(((i + 7) % 16), pixels.Color(0 , 255 , 159));
    pixels.show(); 
    delay(10);
    pixels.setPixelColor(((i + 8) % 16), pixels.Color(0 , 255 , 255));
    pixels.show(); 
    delay(10);
    pixels.setPixelColor(((i + 9) % 16), pixels.Color(0 , 160 , 255));
    pixels.show();  
    delay(10);
    pixels.setPixelColor(((i + 10) % 16), pixels.Color(0 , 64 , 255));
    pixels.show(); 
    delay(10);
    pixels.setPixelColor(((i + 11) % 16), pixels.Color(31 , 0 , 255));
    pixels.show(); 
    delay(10);
    pixels.setPixelColor(((i + 12) % 16), pixels.Color(127 , 0 , 255));
    pixels.show(); 
    delay(10);
    pixels.setPixelColor(((i + 13) % 16), pixels.Color(223 , 0 , 255));
    pixels.show(); 
    delay(10);
    pixels.setPixelColor(((i + 14) % 16), pixels.Color(255 , 0 , 192));
    pixels.show();  
    delay(10);
    pixels.setPixelColor(((i + 15) % 16), pixels.Color(255 , 0 , 96));
    pixels.show(); 
    delay(10);
    pixels.setPixelColor(((i + 16) % 16), pixels.Color(255 , 0 , 0));
    pixels.show(); 
    delay(10);
    delay(450);

   
  
}
