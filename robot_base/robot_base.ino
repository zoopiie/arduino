const int buz = 4;
const int VA = 10;
const int DA = 12;
const int VB = 11;
const int DB = 13;
const byte trig = A4;
const byte echo = A5;
const unsigned long ref = 25000UL;
const float son = 340.0 / 1000;
int min = 27;


void setup ()
{
  pinMode(VA, OUTPUT);
  pinMode(DA, OUTPUT);
  pinMode(VB, OUTPUT);
  pinMode(DB, OUTPUT);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  Serial.begin(9600);
    
}

void loop()
{
  Motor('C', 'Av' , 50);  /* fait avancé */ 
  delay(200);

digitalWrite(trig, HIGH);/* mesure de la distance */
delay(100);
digitalWrite(trig, LOW);
 long mesure = pulseIn(echo, HIGH, ref);
 float distmm = mesure / 2.0*son;
 Serial.println(distmm);

 if (distmm<300)
 {
  Serial.println('objet detecter');
 Motor('C', 'Av', 0);/*Stop*/

 Motor('A','Av', 50); /*tourne pour éviter l'obstacle*/
 Motor('B', 'Re', 50);
 delay(200);
 Motor('C', 'Av', 50);
 }
  
}


void Motor( char mot, char dir, int speed)
{
  int ns; 
  if (speed==0)
  {ns = 0;}
  else {
    ns = map(speed, 1, 100, min, 255);
  }
  switch(mot){
    case 'A':  /*controle du moteur A*/
    if (dir == 'Av')
    {
      digitalWrite(DA, HIGH);
      }
    else if ( dir == 'Re')
    {
      digitalWrite(DA, LOW);
    }
    analogWrite(VA, ns);
    break;

    case 'B': /* controle du moteur B*/
    if (dir == 'Av')
    {
      digitalWrite(DB, HIGH);
    }
    else if (dir == 'Re')
    {
      digitalWrite(DB, LOW);
    }
    analogWrite(VB, ns);
    break;

    case 'C':
    if (dir == 'Av')
    {
      digitalWrite(DB, HIGH);
      digitalWrite(DA, HIGH);
    }
    else if ( dir == 'Re')
  {
    digitalWrite(DB, LOW);
    digitalWrite(DA, LOW);
  }
  analogWrite(VA, ns);
  analogWrite(VB, ns);
  break;

    
    
    }
  }
