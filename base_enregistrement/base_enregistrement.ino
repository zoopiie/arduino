#include <Servo.h>

Servo servo;

int led = 4;                // déclaration des pins
int interrupteur = 13;
int ledv = 5;
int but = 3;
int axex =A5;

int var = 8;    // variable pour changer la vitesse du bras

int valx;         // variable qui servirons pour les enregistrements et les déplacements
int tempx = 90;
int taille;
int tab[100];
int ut;


void setup ()
{
  pinMode(led, OUTPUT); 
  pinMode(interrupteur, INPUT);
  pinMode(ledv, OUTPUT);
  pinMode(but, INPUT);
  pinMode(axex, INPUT);
  servo.attach(11); 
}


void loop()
{


  
 valx= analogRead(axex);                  // debut de la partie qui gère le ralenti de déplacement
    valx = map (valx, 0, 1023, 0, 179);   // adapte la la valeur recu du potentiometre en angle
    delay(25);
    
    
     if (tempx<valx)            // verifie si la nouvelle valeur est plus ou moins grande que la dernière valeur donnée au servo
    {
    for (int i=tempx; i<valx; i++)    // boucle de la dernière valeur jusqu'a la nouvelle en faisant une pause chaque degré
    {                                 // i++ est équivalent à i=i+1, même chose pour i--, i=i-1
      delay(var);
      servo.write(i);
    }
    }
      else 
    {
       for (int i=tempx; valx<=i; i--)    // même principe mais en décroissant (si la nouvelle valeur est plus petite que l'ancienne)
    {
      delay(var);
      servo.write(i);
    }
    }
    tempx=valx;           // enregistre la dernière valeur obtenu pour pouvoir la comparer après avec la nouvelle
                        // fin de la partie qui gère le ralenti





    
  int etat= digitalRead(interrupteur);      // debut de la partie d'enregistrement et vérification de l'état de l'interrupteur
  if (etat==HIGH)                       // le if ici sert à initialiser la séquence enregistrer
  {
    digitalWrite(led, HIGH);
    taille =0;
    valx= analogRead(axex);
    valx = map (valx, 0, 1023, 0, 179);   
    tab[taille]= valx;
  }                   /* on a juste donnée la première valeur , allumer la led et initialiser la taille a 0 parce qu'un
                         tableau commence a la case numéro 0*/
  
  while(etat==HIGH)   // on commence ici la séquence d'enregistrement
  {
   
   
   
   
   valx= analogRead(axex);                  // on utilise la même partie que précedement pour les deplacements
    valx = map (valx, 0, 1023, 0, 179);
    delay(25);
    
    
     if (tempx<valx)
    {
    for (int i=tempx; i<valx; i++)
    {
      delay(var);
      servo.write(i);
    }
    }
      else 
    {
       for (int i=tempx; valx<=i; i--)
    {
      delay(var);
      servo.write(i);
    }
    }
    tempx=valx; 




    
  taille++; // on augmente la taille de 1
  if (taille<100)         // on verifie que l'on puisse stocker la valeur dans le tableau
  {
  
  tab[taille]=tempx;          // on stock la dernière valeur obtenu dans taille-ème case du tableau tab
  delay(250);                 // ce delai permet de ne pas stocker trop d'information, il stock les info toutes les 0,25sec
  }
  else
  {
    digitalWrite(ledv, HIGH);
  }
  
    
    etat = digitalRead(interrupteur);     // on vérifie si l'interrupteur est encore dans l'état HIGH
  }
  
  digitalWrite(ledv, LOW);
  digitalWrite(led, LOW);             // on éteint la led pour indiquer que l'enregistrement s'arrete
  
  int etbut = digitalRead(but);       // on regarde ici si le bouton est enclenché
 
  
 if (etbut == 1)                  // on commence la boucle qui va appliquer la séquence enregistrer
{                                 // je rapelle que 1 est équivalent à HIGH
    digitalWrite(ledv, HIGH);     // on indique que la séquence commence en allumant la led
    for (int i= 0; i<taille; i++)
    {
      ut = tab[i+1];              // au lieu de lire est transformer la valeur ici on récupere juste la valeur enregistrée
      valx = ut;                  // la on change juste le nom de la variable

      
       
       delay(25);
    
    
     if (tempx<valx)                // c'est la partie qui gère le ralenti que l'on a déjà vu
    {
    for (int i=tempx; i<valx; i++) // c'est le for qui va s'occuper de boucler, une fois le bouton presser une fois peu importe
    {                              // la suite le programme va répeter la séquence en ignorant tout le reste
      delay(var);
      servo.write(i);
    }
    }
      else 
    {
       for (int i=tempx; valx<=i; i--)
    {
      delay(var);
      servo.write(i);
    }
    }
    tempx=valx; 



    
      
      delay(250);         // on reprend le delai qu'on avait mis précedemment pour reproduire au mieux la même sequence
    }
}
  digitalWrite(ledv, LOW);     // on eteint la led pour indiquer que la sequence est fini d'éxecuter
  delay(10);                  // petite pause pour le programme pour éviter qu'il retourne directement dans le if
}






/*void dep1(int tempx, int valx)       // dep droite
{
  valx = map (valx, 0, 1023, 0, 180);
    delay(25);
    
     if (tempx<valx)
    {
    for (int i=tempx; i<valx; i++)
    {
      delay(var);
      servo.write(i);
      
    }
    }
      else 
    {
       for (int i=tempx; valx<=i; i--)
    {
      delay(var);
      servo.write(i);
      
    }
    }
}*/
