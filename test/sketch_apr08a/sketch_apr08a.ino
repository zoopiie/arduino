const int button =  3 ;
const int led = 12 ;
int buttonstate = 0;
int c = 0;


void setup ()
{
  pinMode(button , INPUT);
  pinMode(led , OUTPUT);
}

void loop ()
{
  delay(50);
  buttonstate = digitalRead(button);
    
    if (c == 1)
    {
      digitalWrite(led , HIGH);
    }
    if (c == 0)
    {
      digitalWrite(led , LOW);
    }
    
    if (buttonstate == HIGH)
  {
    c = 1 - c;
    delay(200);
  
  }
  
}
