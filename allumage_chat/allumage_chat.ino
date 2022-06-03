#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


Adafruit_NeoPixel matrix = Adafruit_NeoPixel(256, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ringl(35, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ringr(35, 3, NEO_GRB + NEO_KHZ800);


const int boutonrainbow = 2;
const int boutoncolor = 4;
const int boutonmode = 7;
const int potarlum = A0;
const int potarcolor = A1;
int lum = 0;
int valmod = 0;
int r ;
int g ;
int b ;
int range = 0;

void setup(){

  lum = map (analogRead(potarlum), 0, 1024, 0, 256);
  
  matrix.begin();           
  matrix.setBrightness(lum);
  
  ringl.begin();
  ringl.setBrightness(lum);
  
  ringr.begin();
  ringr.setBrightness(lum);
  
}

void loop(){
  testbut();
  delay(50);
  if (boutonrainbow == HIGH || valmod == 0){
    valmod = 0;
    rainbow(1);
    rainbowring(1);
    lum = map (analogRead(potarlum), 0, 1024, 0, 256);
    matrix.setBrightness(lum);
    ringl.setBrightness(lum);
    ringr.setBrightness(lum);
  
  }
  if (boutoncolor == HIGH || valmod == 1){
      while (valmod == 1){
        for(int i = 0; i < 256; i++){
          matrix.setBrightness(i);
          ringl.setBrightness(i);
          ringr.setBrightness(i);
          color();
        }
          testbut();
          
        }
  }
  if (valmod == 2){
    while (valmod == 2){
      
      range = 1;
      petillant();
      delay(250);
      range = 2;
      petillant();
      delay(250);
      range = 0;
      petillant();
      delay(250);
      testbut();
    }
  }
    
  
}
  
  



void testbut(){
  if (boutonrainbow == HIGH){
    valmod = 0;
  }
  if (boutoncolor == HIGH) {
    valmod = 1;
  }
  if (boutonmode == HIGH) {
    if (valmod == 0 || valmod == 1 || valmod == 3){
      valmod = 2;
    }
    if (valmod == 2){
      valmod = 3;
    }
    
  }
}




void rainbow(uint8_t wait){

  for (int i = 0; i < 257; i++)
  {
    matrix.setPixelColor(i, Wheel((i) & 255));
  }
  matrix.show();
  delay(10);

}


void rainbowring(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i< 35; i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / 35);
      ringl.setPixelColor(i, ringl.gamma32(ringl.ColorHSV(pixelHue)));
      ringr.setPixelColor(i, ringr.gamma32(ringr.ColorHSV(pixelHue)));
    }
    ringl.show();
    ringr.show();
    delay(10);
  }
}



uint32_t Wheel(byte WheelPos){
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


void color(){
    int val = analogRead(potarcolor);
    val = map(val, 0,1023, 0, 1536);
    if ( 0<= val <= 255){
       r = 255;
       g = val;
       b = 0;
    }

    if ( 256<= val <= 511){
       r = 511-val;
       g = 255;
       b = 0;
    }

    if ( 512<= val <= 767){
       r = 0;
       g = 255;
       b = val - 512;
    }

    if ( 768 <= val <= 1023){
       r = 0;
       g = 1023 - val;
       b = 255;
    }

    if ( 1024 <= val <= 1279){
       r = val - 1024;
       g = 0;
       b = 255;
    }

    if ( 1280 <= val <= 1535){
       r = 255;
       g = 0;
       b = 1535 - val;
    }

   if (val==1536){
     r = 255;
     b = 255;
     g = 255;
   }
   for(int i=0; i< 36; i++) { 
      ringl.setPixelColor(i, ringl.Color(r, g, b));
      ringr.setPixelColor(i, ringr.Color(r, g, b));
    }
    ringl.show();
    ringr.show();
    for (int i = 0; i < 257; i++)
  {
    matrix.setPixelColor(i, matrix.Color(r, g, b));
  }
  matrix.show();
  delay(10);

}


void petillant(){
   int val = analogRead(potarcolor);
    val = map(val, 0,1023, 0, 1536);
    if ( 0<= val <= 255){
       r = 255;
       g = val;
       b = 0;
    }

    if ( 256<= val <= 511){
       r = 511-val;
       g = 255;
       b = 0;
    }

    if ( 512<= val <= 767){
       r = 0;
       g = 255;
       b = val - 512;
    }

    if ( 768 <= val <= 1023){
       r = 0;
       g = 1023 - val;
       b = 255;
    }

    if ( 1024 <= val <= 1279){
       r = val - 1024;
       g = 0;
       b = 255;
    }

    if ( 1280 <= val <= 1535){
       r = 255;
       g = 0;
       b = 1535 - val;
    }

   if (val==1536){
     r = 255;
     b = 255;
     g = 255;
   }
  
  for (int i = 0; i < 257; i++){
    range++;
    if (range == 3){
      range = 0;
      matrix.setPixelColor(i, matrix.Color(r, g, b));
    }
  }
 for (int i = 0; i < 36; i++){
    range++;
    if (range == 3){
      range = 0;
      ringr.setPixelColor(i, ringr.Color(r, g, b));
      ringl.setPixelColor(i, ringl.Color(r, g, b));
  
 }
 matrix.show();
 ringr.show();
 ringl.show();
    
    
  }
  

}
