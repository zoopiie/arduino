#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> 
#endif

#define PIN        6 

#define NUMPIXELS 16 

int x;
int i = 0;
String chaine;
String r ;
String g ;
String b ;

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

void loop ()
{
  while(Serial.available()>0){
    chaine += char(Serial.read());
    delay(2);
  }
  if(chaine != ""){
    Serial.println(chaine);
    String r = chaine.substring(0,3);
    String g = chaine.substring(3,6);
    String b = chaine.substring(6,9);
    String lum = chaine.substring(9,12);

    for (int i= 0; i <=16; i++)
    {
    pixels.setPixelColor(( i % 16), pixels.Color(r.toInt(), g.toInt(), b.toInt()));
    pixels.setBrightness(lum.toInt());
    pixels.show();
    } 
    chaine = "";
      
  }
}


    
