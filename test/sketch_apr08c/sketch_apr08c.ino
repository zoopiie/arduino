const int button =  13 ;
const int led = 2 ;
int buttonstate = 0;
int c = 0;
int nuit = 325;
const int pr = A0;
int valeur = 0;


void setup ()
{
  pinMode(button , INPUT);
  pinMode(led , OUTPUT);
}

void loop ()
{
  buttonstate = digitalRead(button);
  valeur = analogRead(pr);
  if (valeur < nuit && c==0)
  {
    c=1;
    delay(50);
  }
  
  if (valeur < nuit && c==1)
  {
 
     while( buttonstate == LOW)
    {
      buttonstate = digitalRead(button);
      if (c == 1)
      {
       digitalWrite(led , HIGH);
      }
     if (c == 0)
      {
        digitalWrite(led , LOW);
     }
    
   }
     if (buttonstate == HIGH)
   {
      c = 1 - c;
      delay(200);
  
    }
  
    
  }
  if (valeur > nuit)
  {
  digitalWrite(led , LOW);
  }
  delay(10);
}
