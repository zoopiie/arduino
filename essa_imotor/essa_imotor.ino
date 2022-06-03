const int vitessedroite = 10;
const int directiondroite = 12;
const int vitessegauche = 11;
const int directiongauche = 13;
int min =  27;
int tps = 250;


void setup ()
{
  pinMode(vitessedroite, OUTPUT);
  pinMode(directiondroite, OUTPUT);
  pinMode(vitessegauche, OUTPUT);
  pinMode(directiongauche, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Motor('C', 'Av' , 50);  /* fait avitessedroitencé */ 
  Serial.println("les deux 50%");
  delay(tps);
  Motor('B', 'Av' , 50);  /* fait avitessedroitencé */ 
  Serial.println("droite 50%");
  delay(tps);
  Motor('A', 'Av' , 50);  /* fait avitessedroitencé */ 
  Serial.println("gauche 50%");
  delay(tps);
  Motor('C', 'Av' , 100);  /* fait avitessedroitencé */ 
  Serial.println("les deux 100%");
  delay(tps);
  Motor('B', 'Av' , 100);  /* fait avitessedroitencé */ 
  Serial.println("droite 100%");
  delay(tps);
  Motor('A', 'Av' , 100);  /* fait avitessedroitencé */ 
  Serial.println("gauche 100%");
  delay(tps);
  Motor('C', 'Av' , 0);  /* fait avitessedroitencé */ 
  Serial.println("les deux 0%");
  delay(tps);
  Motor('B', 'Av' , 0);  /* fait avitessedroitencé */ 
  Serial.println("droite 0%");
  delay(tps);
  Motor('A', 'Av' , 0);  /* fait avitessedroitencé */ 
  Serial.println("gauche 0%");
  delay(tps);



  
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
    digitalWrite(directiongauche, LOW);
    analogWrite(vitessegauche, 0);
    if (dir == 'Av')
    {
      digitalWrite(directiondroite, HIGH);
      
      }
    else if ( dir == 'Re')
    {
      digitalWrite(directiondroite, LOW);
    }
    analogWrite(vitessedroite, ns);
    break;

    case 'B': /* controle du moteur B*/
    digitalWrite(directiondroite, LOW);
    analogWrite(vitessedroite, 0);
    if (dir == 'Av')
    {
      digitalWrite(directiongauche, HIGH);
    }
    else if (dir == 'Re')
    {
      digitalWrite(directiongauche, LOW);
    }
    analogWrite(vitessegauche, ns);
    break;

    case 'C':
    if (dir == 'Av')
    {
      digitalWrite(directiongauche, HIGH);
      digitalWrite(directiondroite, HIGH);
    }
    else if ( dir == 'Re')
  {
    digitalWrite(directiongauche, LOW);
    digitalWrite(directiondroite, LOW);
  }
  analogWrite(vitessedroite, ns);
  analogWrite(vitessegauche, ns);
  break;

    
    
    }
  }
