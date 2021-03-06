#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>




#define PIN 6

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
  NEO_MATRIX_TOP    + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(255, 255, 0),matrix.Color(0, 0, 255), matrix.Color(255, 0, 255), matrix.Color(0, 255, 255), matrix.Color(255, 255, 255)};

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(80);
  matrix.setTextColor(colors[0]);
  matrix.setTextSize(0);
 
}



void loop() {

  matrix.setCursor(0, 0);
  matrix.setTextColor(matrix.Color(255,0,0)); 
  matrix.print("F");
   matrix.show();

   
  matrix.setCursor(5, 0);
  matrix.setTextColor(matrix.Color(255,255,0)); 
  matrix.print("A");
   matrix.show();

  matrix.setCursor(10, 0);
  matrix.setTextColor(matrix.Color(0,255,0)); 
  matrix.print("B");
   matrix.show();

  matrix.setCursor(15, 0);
  matrix.setTextColor(matrix.Color(0,255,255)); 
  matrix.print("L");
   matrix.show();

  matrix.setCursor(20, 0);
  matrix.setTextColor(matrix.Color(0,0,255)); 
  matrix.print("A");
   matrix.show();

  matrix.setCursor(25, 0);
  matrix.setTextColor(matrix.Color(255,0,255)); 
  matrix.print("B");
   matrix.show();


}
