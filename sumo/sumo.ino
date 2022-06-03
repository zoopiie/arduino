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
int vitessecombat = 0;
int vitessecroisiere = 45;
int distancecombatlat = 50;
int distancecombatcharge = 50;

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
  delay(15);
  Serial.println(digitalRead(bouton));
  
  if (digitalRead(bouton) == LOW){  
      Serial.println("je suis dans le bbuuuzzeerr");
      //tone(buzzer, 1740, 300);
      delay(1100);
      //tone(buzzer, 1740, 300);
      delay(1000);
      //tone(buzzer, 1740, 300);
      delay(1000);
      //tone(buzzer, 1770, 1000);
      varbut=0;

    while (varbut == 0){
      
      delay(1000);
      if (digitalRead(capteurcouleurdroit)==0 || digitalRead(capteurcouleurgauche)==0){
        Serial.println("je vais me cassez lagueule");
         digitalWrite(directiongauche, LOW);
         digitalWrite(directiondroite, LOW);
         analogWrite(vitessedroite, 55);
         analogWrite(vitessegauche, 55);
         delay(500);
         digitalWrite(directiongauche, HIGH);
         digitalWrite(directiondroite, HIGH);
         analogWrite(vitessedroite, 0);
         analogWrite(vitessegauche, 191);;
         delay(300);
        
      }
     if (digitalRead(capteurcouleurdroit)==1 && digitalRead(capteurcouleurgauche)==1){
      Serial.println("attend je mesure");
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
      Serial.print(" diantce avant : ");
      Serial.println(distmmav);
      Serial.print(" diantceeeeeeeeeee gauche : ");
      Serial.println(distmmg);
      Serial.print(" diantceeeeeeeeeeeeeeeee droite : ");
      Serial.println(distmmd);
      if ( distmmd < distancecombatlat && 2 < distmmd){
        Serial.println("y'a people a droite");
        digitalWrite(directiongauche, HIGH);
        digitalWrite(directiondroite, HIGH);
        analogWrite(vitessedroite, 0);
        analogWrite(vitessegauche, 191);
        delay(150);
        digitalWrite(directiongauche, HIGH);
        digitalWrite(directiondroite, HIGH);
        analogWrite(vitessedroite, vitessecombat);
        analogWrite(vitessegauche, vitessecombat);
      }
      if (distmmg < distancecombatlat && 2 < distmmg){
        Serial.println("je vais me bagarre a gauche");
        digitalWrite(directiongauche, HIGH);
        digitalWrite(directiondroite, HIGH);
        analogWrite(vitessedroite, 191);
        analogWrite(vitessegauche, 0);
        delay(150);
        digitalWrite(directiongauche, HIGH);
        digitalWrite(directiondroite, HIGH);
        analogWrite(vitessedroite, vitessecombat);
        analogWrite(vitessegauche, vitessecombat);
      }
      if (distmmav < distancecombatcharge && 2 < distmmav){
        Serial.println("chargéééééééééééééééééééééééééééééééééééééé");
        digitalWrite(directiongauche, HIGH);
        digitalWrite(directiondroite, HIGH);
        analogWrite(vitessedroite, vitessecombat);
        analogWrite(vitessegauche, vitessecombat);    
      } 
      if(distmmav >= distancecombatcharge && distmmg >= distancecombatlat && distmmd >= distancecombatlat){
        Serial.println("on se fait chier non ?");
        digitalWrite(directiongauche, HIGH);
        digitalWrite(directiondroite, HIGH);
        analogWrite(vitessedroite, vitessecroisiere);
        analogWrite(vitessegauche, vitessecroisiere);  
      }
      if (digitalRead(bouton) == LOW){
        varbut=1;
      }
     }
    }
   }
  }
