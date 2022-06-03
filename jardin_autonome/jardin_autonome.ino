#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);

void setup()
{
Serial.begin(9600);
lcd.init();
pinMode(2, OUTPUT);
digitalWrite(2, 1);
}


void loop()
{
lcd.backlight();
// Envoi du message
lcd.setCursor(0, 0);
lcd.print(analogRead(A0));
Serial.println(analogRead(A0));
delay(1500);
lcd.clear();
if (analogRead(A0)<50){
  digitalWrite(2, 1);  
}
else{
  digitalWrite(2, 0);
}
}
