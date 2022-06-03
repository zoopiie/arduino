#include <Servo.h>

Servo sd;
Servo sg;
Servo sr;
Servo sp;
int axex = A5;
int axey = A4;
int axexx =A3;
int axeyy = A2;
int valx;
int valy;
int valxx;
int valyy;
int tempx=135;
int tempy = 130;
int tempxx =90;
int tempyy = 90;

int var = 10;

void setup()
{
  pinMode(axex, INPUT);
  pinMode(axey, INPUT);
  pinMode(axexx, INPUT);
  pinMode(axeyy, INPUT);
  sd.attach(11);
  sg.attach(10);
  sr.attach(9);
  sp.attach(6);
}

void loop()
{
  valx = analogRead(axex);          //droite
  while(valx<350)
  {
    if(tempx<80)
    {
      sd.write(81);
      tempx = 81;
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




  valy = analogRead(axey);      // gauche
  while(valy<350)
  {
    if(tempy<90)
    {
     sg.write(91);
     tempy=91; 
    }
    else
    {
    tempy--;
    sg.write(tempy);
    delay(var);
    valy = analogRead(axey);  
    }
  }
  valy = analogRead(axey);
  while(valy>750)
  {
    if (tempy>180)
    {
     sg.write(179);
     tempy=179;
    }
    else
    {
    tempy++;
    sg.write(tempy);
    delay(var);
    valy = analogRead(axey);
    }
  }





  valxx = analogRead(axexx);          // rotation
  while(valxx<350)
  {
    if(tempxx<1)
    {
      sr.write(2);
      tempxx=2;
    }
    else
    {
    tempxx--;
    sr.write(tempxx);
    delay(var);
    valxx = analogRead(axexx);  
    }
  }
  valxx = analogRead(axexx);
  while(valxx>750)
  {
    if (tempxx>180)
    {
      sr.write(179);
      tempxx=179;
    }
    else
    {
    tempxx++;
    sr.write(tempxx);
    delay(var);
    valxx = analogRead(axexx);
    }
  }






  valyy = analogRead(axeyy);        //pince
  while(valyy<350)
  {
    if(tempyy<1)
    {
      sp.write(2);
      tempyy=2;
    }
    else
    {
    tempyy--;
    sp.write(tempyy);
    delay(var);
    valyy = analogRead(axeyy);  
    }
  }
  valyy = analogRead(axeyy);
  while(valyy>750)
  {
    if (tempyy>180)
    {
      sp.write(179);
      tempyy=179;
    }
    else
    {
    tempyy++;
    sp.write(tempyy);
    delay(var);
    valyy = analogRead(axeyy);
    }
  }
}
