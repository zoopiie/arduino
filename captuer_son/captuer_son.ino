const byte trigav = A0;
const byte echoav = A1;
const byte trigg = A2;
const byte echog = A3;
const byte trigd = A4;
const byte echod = A5;
const unsigned long ref = 25000UL;
const float son = 340.0 / 1000;


void setup ()
{

  pinMode(trig1, OUTPUT);
  digitalWrite(trig1, LOW);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  digitalWrite(trig2, LOW);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  digitalWrite(trig3, LOW);
  pinMode(echo3, INPUT);
  Serial.begin(9600);
    
}

void loop()
{
digitalWrite(trig1, HIGH);/* mesure de la distance */
delay(10);
digitalWrite(trig1, LOW);
long mesure1 = pulseIn(echo1, HIGH, ref);
digitalWrite(trig2, HIGH);
delay(10);
digitalWrite(trig2, LOW);
long mesure2 = pulseIn(echo2, HIGH, ref);
digitalWrite(trig3, HIGH);
delay(10);
digitalWrite(trig3, LOW);
 long mesure3 = pulseIn(echo3, HIGH, ref);
 float distmm1 = mesure1 / 2.0*son;
 float distmm2 = mesure2 / 2.0*son;
 float distmm3 = mesure3 / 2.0*son;
 Serial.print("capteur 1 : ");
 Serial.println(distmm1);
 Serial.print("capteur 2 : ");
 Serial.println(distmm2);
 Serial.print("capteur 3 : ");
 Serial.println(distmm3);
delay(1000);
 
}
