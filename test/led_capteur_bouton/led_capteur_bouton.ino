const int button =  13 ;
const int led = 2 ;
int buttonstate = 0;
int c = 0;
int nuit = 325;
const int pr = A0;
int valeur = 0;
int tempo = 0;


void setup ()
{
  pinMode(button , INPUT);
  pinMode(led , OUTPUT);
}

void loop ()
{
  buttonstate = digitalRead(button);
  valeur = analogRead(pr);
  if (valeur < nuit && tempo == 0)
  {
  digitalWrite(led , HIGH);
    tempo=1;
    c=0;
  }
  if (valeur > nuit)
  {
  digitalWrite(led , LOW);
    tempo=0;
  }
    while( valeur < nuit)
    {

      valeur = analogRead(pr);
      buttonstate = digitalRead(button);
      delay(20);
      
   if (c == 0)
      {
       digitalWrite(led , HIGH);
      }
     if (c == 1)
      {
        digitalWrite(led , LOW);
     }
    
   
     if (buttonstate == LOW)
   {
      c = 1 - c;
      delay(200);
      
    }
}

}
