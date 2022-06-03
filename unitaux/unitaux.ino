#include <Servo.h>

Servo sd;
int axex = A5;
int valx;
int tempx =90;
int var = 15;


void setup()
{
  pinMode(axex, INPUT);
    sd.attach(6);
}

void loop()
{
  valx = analogRead(axex);          //droite
  while(valx<350)
  {
    if(tempx<1)
    {
      sd.write(2);
      tempx = 2;
    }
    else
    {
    tempx--;
    sd.write(tempx);
    delay(var);
    valx = analogRead(axex);  
    }
  }
  valx = analogRead(axex);
  while(valx>750)
  {
    if (tempx>180)
    {
      sd.write(179);
      tempx=179;
    }
    else
    {
    tempx++;
    sd.write(tempx);
    delay(var);
    valx = analogRead(axex);
    }
  }
}
