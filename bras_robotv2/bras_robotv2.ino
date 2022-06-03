#include <Servo.h>
#include <stdlib.h>
 Servo sdroite;
 Servo sgauche;
 Servo spince;
 Servo srot;
 int valx = 0;
 int valy = 0;
 int val2x = 0;
 int val2y = 0;
 int valp = 0;
const int axex = A5;
const int axey = A4;
const int axe2x = A2;
const int axe2y = A3;
const int button= 2;
const int buttonj = 4;
const int servod = 11;
const int servog = 10;
const int servor = 9;
const int servop = 6;
const int led = 8;
const int ledv = 4;
int tempx = 70;
int tempy = 33;
int temp2x = 90;
int temp2y = 90;
int tempp = 0;

int hj = 13; 
int hg = 12;

int var  = 8;
const int bs = 6     ;
const int ba = 5;
int tab[100][4];
int *size;
int taille = 1;
int c =0;
int truc [4] ;
int sd = 0;
int sg = 0;
int sr = 0;
int sp = 0;
int sd1 = 0;
int sg1 = 0;
int sr1 = 0;
int sp1 = 0;





void setup ()
{
  pinMode(hj, INPUT);
  pinMode(hg, INPUT);
  pinMode(ba, INPUT);
  pinMode(button, INPUT);
  pinMode(buttonj, INPUT);
  pinMode(axey, INPUT);
  pinMode(axex, INPUT);
  pinMode(axe2x, INPUT);
  pinMode(axe2y, INPUT);
  pinMode(led, OUTPUT);
  pinMode(ledv, OUTPUT);
  sdroite.attach(11);
  sgauche.attach(10);
  spince.attach(6);
  srot.attach(9);
}



void loop ()
{
   val2x= analogRead(axe2x);
    valx= analogRead(axex);
    valy= analogRead(axey);
    tempx = dep1(tempx, valx);
    tempy = dep2(tempy, valy);
    temp2x = dep3(temp2x, val2x);
    tempp = dep4(tempp);
  int etathj = digitalRead(hg);
  
  if (etathj == HIGH)
  {
    taille = 0;
    tab[taille][0] = 70;
    tab[taille][1] = 33;
    tab[taille][2] = 90;
    tab[taille][3] = 0;
  }
 
  while (etathj == HIGH)                           // debut de la sauvergade
  {
    val2x= analogRead(axe2x);
    valx= analogRead(axex);
    valy= analogRead(axey);
   
    tempx = dep1(tempx, valx);
    tempy = dep2(tempy, valy);
    temp2x = dep3(temp2x, val2x);
    tempp = dep4(tempp);
    delay(250);
   
    
    /*if (taille==1)
    {
      sd = tempx;
      sg = tempy;
      sr = temp2x;
      sp = tempp;
      truc[0] = sd;
      truc[1] = sg;
      truc[2] = sr;
      truc[3] = sp;
      
      tab [0][0] = sd;
      tab [0][1] = sg;
      tab [0][2] = sr;
      tab [0][3] = sp;
      
      
      int tabp[1][4]={{sd,sg,sr,sp}};
      
    }
    else 
    {
      sd = tempx;
      sg = tempy;
      sr = temp2x;
      sp = tempp; 
      truc[0] = sd;
      truc[1] = sg;
      truc[2] = sr;
      truc[3] = sp;   
    }*/
    sd = tempx;
    sg = tempy;
    sr = temp2x;
    sp = tempp;
    truc[0] = sd;
    truc[1] = sg;
    truc[2] = sr;
    truc[3] = sp;
    tab[taille+1][0] = sd;
    tab[taille+1][1] = sg;
    tab[taille+1][2] = sr;
    tab[taille+1][3] = sp;
     taille = taille + 1;
     etathj = digitalRead(hg);
     digitalWrite(led, LOW);
     
   }
   digitalWrite(led, HIGH);
   digitalWrite(ledv, LOW);
   int bsta = digitalRead(ba);
   if (bsta == LOW)                    // application
   {
    digitalWrite(ledv, HIGH);
    for (int i = 0; i<taille -1 ; i++)
    {
      sd = tab[i][0];
      sg = tab[i][1];
      sr = tab[i][2];
      sp = tab[i][3];
      sd1 = tab[i+1][0];
      sg1 = tab[i+1][1];
      sr1 = tab[i+1][2];
      sp1 = tab[i+1][3];
      dep1(sd, sd1);
      dep2(sg, sg1);
      dep3(sr, sr1);
      dep4(sp);

      
      delay(250);
     
    }
   }
}





int dep4(int tempp)               // c'est la pince !!!
{
  int buttonstate= digitalRead(buttonj);        

    if (buttonstate==HIGH)
    { 
      valp = spince.read();
     
      if (valp>150)
      {
        for (int i=179; i>2; i--)
        {
          delay(2);
        spince.write(i);
        
        }
        spince.write(0);
        tempp = 0;
      }
      else
      {
        
        for(int i=0; i<178; i++)
        {
        spince.write(i);
        delay(2);
        
        }
        spince.write(179);
        tempp = 179;
      }
      
    }
    return (tempp);
}

int dep3(int temp2x, int val2x)                // dep servo rotation
{
          
    val2x = map (val2x, 0, 1023, 0, 180);
    delay(25);
    
     if (temp2x<val2x)
    {
    for (int i=temp2x; i<val2x; i++)
    {
      delay(var);
      srot.write(i);
      
    }
    }
      else 
    {
       for (int i=temp2x; val2x<=i; i--)
    {
      delay(var);
      srot.write(i);
      
    }
    }
    temp2x=val2x;
   
    return (temp2x);

}
  
int dep1(int tempx, int valx)           // dep servo droit
{ 
               
    valx = map (valx, 0, 1023, 60, 150);
    delay(25);
    
    valx = 180 - valx;
    
     if (tempx<valx)
    {
    for (int i=tempx; i<valx; i++)
    {
      delay(var);
      sdroite.write(i);
      
    }
    }
      else 
    {
       for (int i=tempx; valx<=i; i--)
    {
      delay(var);
      sdroite.write(i);
     
    }
    }
    tempx=valx;
  
    return (tempx);
}


int dep2 (int tempy, int valy)        // dep servo gauche
{      
             
    valy = map (valy, 0, 1023, 110, 180);
    delay(25);
   
    valy= 180 - valy;
      if (tempy<valy)
    {
    for (int i=tempy; i<valy; i++)
    {
      delay(var);
      sgauche.write(i);
      
    }
    }
      else 
    {
       for (int i=tempy; valy<=i; i--)
    {
      delay(var);
      sgauche.write(i);
     
    }
    }
    tempy=valy;

    return (tempy);
    
}





/*int append(int **tab, int *truc, int* size, int taille)              // APPEND
{
  int sort[taille+1][4];
  for (int i =0; i<taille; i++)
  {
    for( int j=0; j<4;j++)
    {
      sort[i][j]=tab[i][j];
    }
  }
  for (int k=0; k<4; k++)
  {
    sort[taille][k]=truc[k];
  }
  size = taille;
  return (sort);
}*/
