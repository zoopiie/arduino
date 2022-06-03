const int E1 = 10;
const int M1 = 12;
const int E2 = 11;
const int M2 = 13;
int min =  27;
String tps = "";
String chaine = "";
int oldspeed = 0;
int value = 0;



void setup ()
{
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M2, OUTPUT);
  Serial.begin(9600);
}

void loop (){
   while(Serial.available()>0){
    chaine += char(Serial.read());
    delay(2);
  }
  
  if(chaine != ""){
    if (chaine=="1"){
      Serial.println("je 1");
      digitalWrite(M2, HIGH);
      digitalWrite(M1, HIGH);
      analogWrite(E2, 100);
      analogWrite(E1, 100);
      delay(500);      
    }
    if (chaine=="2"){
      Serial.println("je 2");
      digitalWrite(M2, LOW);
      digitalWrite(M1, HIGH);
      analogWrite(E2, 100);
      analogWrite(E1, 100);
      delay(500);      
    }
    if (chaine=="3"){
      Serial.println("je 3");
      digitalWrite(M2, HIGH);
      digitalWrite(M1, LOW);
      analogWrite(E2, 100);
      analogWrite(E1, 100);
      delay(500);      
    }
    if (chaine=="4"){
      Serial.println("je 4");
      digitalWrite(M2, LOW);
      digitalWrite(M1, LOW);
      analogWrite(E2, 100);
      analogWrite(E1, 100);
      delay(500);      
    }
    analogWrite(E2, 0);
    analogWrite(E1, 0);
    
    chaine="";
  }
  delay(10);


  
}
