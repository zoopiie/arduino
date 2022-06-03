#include <Servo.h>

Servo sd;
int axex = A5;
int valx;
int tempx =90;
int var = 15;
int but = 3;
int truc = 13;
int aa = 0;
int ledr = 4;
int ledv = 5;
int tab[100];
int taille;
int bb ;

void setup()
{
  pinMode(axex, INPUT);
  pinMode(but, INPUT);
  pinMode(truc, INPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledv, OUTPUT);
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

  int etint = digitalRead(truc);
  if (etint==1)
  {
    taille = 0;
    aa=0;
    tab[taille]=sd.read();
  }
  while(etint==1)
  {
    digitalWrite(ledr, HIGH);
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
  taille++;
  tab[taillle]= sd.write();
 
  etint = digitalRead(truc);
  }
  digitalWrite(ledr, LOW);

  int etbut = digitalRead(but);
  if(etbut == 1)
  {
    digitalWrite(ledv, HIGH);
    for(int  i =0; i<=taille; i++)
    {
      int taab = tab[i];
      aa = tab[i] - tab[i+1]
      sd.write(taab);
      delay(250);
    }
  }
  digitalWrite(ledv, LOW);

  

  
}
