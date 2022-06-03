#include <Servo.h>
const int pr = A0;
Servo truc;
int val = 0;




void setup ()
{
  truc.attach(3);
}

void loop ()
{
  val = analogRead(pr);
  val = map(val, 0 , 1023, 0 , 180);
  truc.write(val);
  delay(10);
  
}
