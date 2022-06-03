#include <Adafruit_NeoPixel.h>

#define PIN 5
#define STRIPSIZE 16

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoPixel ringr = Adafruit_NeoPixel(16, 6, NEO_GRB + NEO_KHZ800);


int var = 0;
int col = 1;

void setup() {
  ringr.begin();
  ringr.setBrightness(25);  // Lower brightness and save eyeballs!
  ringr.show(); // Initialize all pixels to 'off'
  
}

void loop(){
  rainbowring(10);
  
}

void rainbowring(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i< 16; i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / 16);
      ringr.setPixelColor(i, ringr.gamma32(ringr.ColorHSV(pixelHue)));
    }
    ringr.show();
    delay(10);
  }
}
