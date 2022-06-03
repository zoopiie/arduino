#include <Servo.h>
//servo1 :
Servo servo1;  
int pos = 0;  

const int axey = A5;
const int axex = A4;
int valx=0;
int truc=2;
int tempx = 90;



void setup() 
{
   pinMode(axey, INPUT);
  pinMode(axex, INPUT);
  servo1.attach(11); 
}

void loop() 
{
          
   valx= analogRead(axex);
    valx = map (valx, 0, 1023, 0, 179);
    delay(25);
    
    
     if (tempx<valx)
    {
    for (int i=tempx; i<valx; i++)
    {
      delay(10);
      servo1.write(i);
    }
    }
      else 
    {
       for (int i=tempx; valx<=i; i--)
    {
      delay(10);
      servo1.write(i);
    }
    }
    tempx=valx; 
    

}
    
    
     
