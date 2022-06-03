#include <Servo.h>
Servo sdroite;
Servo sgauche;
Servo srot;
Servo spince;


String chaine;
String x ;
String y ;
String rot ;
String pince ;

void setup() 
{
  sgauche.attach(10);
  sdroite.attach(11); 
  spince.attach(6);
  srot.attach(9);
  Serial.begin(9600);
  Serial.setTimeout(1);
  
}

void loop (){
   while(Serial.available()>0){
    chaine += char(Serial.read());
    delay(2);
  }
  if(chaine != ""){
    x = chaine.substring(0,3);
    y = chaine.substring(3,6);
    rot = chaine.substring(6,9);
    pince = chaine.substring(9,12);
   
    sgauche.write(x.toInt());
    sdroite.write(y.toInt());
    spince.write(pince.toInt());
    srot.write(rot.toInt());
    chaine = "";
      
  }
  delay(10);


  
}
