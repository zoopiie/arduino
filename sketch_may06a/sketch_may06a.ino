const byte trigav = A0;
const byte echoav = A1;
const byte trigg = A2;
const byte echog = A3;
const byte trigd = A4;
const byte echod = A5;
const int vitessedroite = 10;
const int vitessegauche = 11;
const int directiongauche = 13;
const int directiondroite = 12;
const int capteurcouleurdroit = 2;
const int capteurcouleurgauche = 3;
const int bouton = 7;
const int buzzer = 4;

const unsigned long ref = 25000UL;
const float son = 340.0 / 1000;
int varbut = 0;
int vitessecombat = 45;
int vitessecroisiere = 45;
int distancecombatlat = 100;
int distancecombatcharge = 100;

void setup () {
  pinMode(trigav, OUTPUT);
  digitalWrite(trigav, LOW);
  pinMode(echoav, INPUT);
  pinMode(trigg, OUTPUT);
  digitalWrite(trigg, LOW);
  pinMode(echog, INPUT);
  pinMode(trigd, OUTPUT);
  digitalWrite(trigd, LOW);
  pinMode(echod, INPUT);
  pinMode(vitessedroite, OUTPUT);
  pinMode(directiondroite, OUTPUT);
  pinMode(vitessegauche, OUTPUT);
  pinMode(directiongauche, OUTPUT);
  pinMode(capteurcouleurdroit, INPUT);
  pinMode(capteurcouleurgauche, INPUT);
  pinMode(bouton, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop () {
  delay(1500);
  digitalWrite(trigav, HIGH);
      delay(10);
      digitalWrite(trigav, LOW);
      long mesureav = pulseIn(echoav, HIGH, ref);
      digitalWrite(trigg, HIGH);
      delay(10);
      digitalWrite(trigg, LOW);
      long mesureg = pulseIn(echog, HIGH, ref);
      digitalWrite(trigd, HIGH);
      delay(10);
      digitalWrite(trigd, LOW);
      long mesured = pulseIn(echod, HIGH, ref);
      float distmmav = mesureav / 2.0*son;
      float distmmg = mesureg / 2.0*son;
      float distmmd = mesured / 2.0*son;

      Serial.print("voici la distance avant :");
      Serial.println(distmmav);

      Serial.print("voici la distance gaucheeeee :");
      Serial.println(distmmg);

      Serial.print("voici la distance droiteeeeeeeeee :");
      Serial.println(distmmd);
}
