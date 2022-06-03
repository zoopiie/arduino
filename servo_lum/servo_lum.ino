#include <Servo.h>
Servo truc;
const int r = 2;
const int b = 3;
const int v = 4;


void setup()
{
  pinMode(r, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(v, OUTPUT);
  truc.attach(5);
}

void loop()
{
  for(int p = 0, p=<180, p++)
  {
    delay(20);
    if (p<60)
  {
    digitalWrite(r, HIGH);
  }
  else{
    digitalWrite(r, LOW);
  }
  if ( 60<p<120)
  {
    digitalWrite(v, HIGH);
  }
  else{
    digitalWrite(v, LOW);
  }
  if (120<p)
  {
    digitalWrite(b, HIGH);
  }
  else{
    digitalWrite(b, LOW);
  }
  truc.Write(p);
  }
}
 
