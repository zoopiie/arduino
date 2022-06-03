#include <Servo.h>
Servo sdroite;
Servo sgauche;
Servo srot;
Servo spince;

int led = 4; 
int lo = 13;
int ledv = 5;
int but = 3;


int var = 8;


int valx;
int valy;
int valxx;
int valyy;


int axex = A5;
int axey = A4;
int axeyy = A2;
int axexx = A3;

int tempx = 90;
int tempy = 90;
int tempxx = 90;
int tempyy = 90;


int taille;
int tabd[100];
int dt;
int tabg[100];
int gt;
int tabr[100];
int rt;
int tabp[100];
int pt;
    


void setup() 
{
  pinMode(led, OUTPUT); 
  pinMode(lo, INPUT);
  pinMode(ledv, OUTPUT);
  pinMode(but, INPUT);
  pinMode(axexx, INPUT);
  pinMode(axey, INPUT);
  pinMode(axex, INPUT);
  pinMode(axeyy, INPUT);
  sgauche.attach(10);
  sdroite.attach(11); 
  srot.attach(9);
  spince.attach(6);
  
}

void loop()  
{
  

  
 valx= analogRead(axex);                  // droite
    valx = map (valx, 0, 1023, 0, 100);
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




valy= analogRead(axey);                     // gauche
    valy = map (valy, 0, 1023, 0, 90);
    delay(25);
    valy = 180 - valy;
    
    
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





 valxx= analogRead(axexx);                  //rotation
    valxx = map (valxx, 0, 1023, 0, 179);
    delay(25);
    
    
     if (tempxx<valxx)
    {
    for (int i=tempxx; i<valxx; i++)
    {
      delay(var);
      srot.write(i);
    }
    }
      else 
    {
       for (int i=tempxx; valxx<=i; i--)
    {
      delay(var);
      srot.write(i);
    }
    }
    tempxx=valxx;






    valyy= analogRead(axeyy);               // pince
    valyy = map (valyy, 0, 1023, 0, 179);
    delay(25);
    
    
     if (tempyy<valyy)
    {
    for (int i=tempyy; i<valyy; i++)
    {
      delay(var);
      spince.write(i);
    }
    }
      else 
    {
       for (int i=tempyy; valyy<=i; i--)
    {
      delay(var);
      spince.write(i);
    }
    }
    tempyy=valyy;





    
    
  int inte= digitalRead(lo);
  if (inte==HIGH)
  {
    digitalWrite(led, HIGH);
    taille =0;
    tabd[taille]=130;
    tabg[taille]=135;
    tabr[taille]=0;
    tabp[taille]=90;
  }
  while(inte==HIGH)                 // WHILE
  {




valx= analogRead(axex);                  // droite
    valx = map (valx, 0, 1023, 0, 100);
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




valy= analogRead(axey);                     // gauche
    valy = map (valy, 0, 1023, 0, 90);
    delay(25);
    valy = 180 - valy;
    
    
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





 valxx= analogRead(axexx);                  //rotation
    valxx = map (valxx, 0, 1023, 0, 179);
    delay(25);
    
    
     if (tempxx<valxx)
    {
    for (int i=tempxx; i<valxx; i++)
    {
      delay(var);
      srot.write(i);
    }
    }
      else 
    {
       for (int i=tempxx; valxx<=i; i--)
    {
      delay(var);
      srot.write(i);
    }
    }
    tempxx=valxx;






    valyy= analogRead(axeyy);               // pince
    valyy = map (valyy, 0, 1023, 0, 179);
    delay(25);
    
    
     if (tempyy<valyy)
    {
    for (int i=tempyy; i<valyy; i++)
    {
      delay(var);
      spince.write(i);
    }
    }
      else 
    {
       for (int i=tempyy; valyy<=i; i--)
    {
      delay(var);
      spince.write(i);
    }
    }
    tempyy=valyy;





    
  taille++;
  tabd[taille]=valx;
  tabg[taille]=valy;
  tabr[taille]=valxx;
  tabp[taille]=valyy;
  delay(250);

    digitalWrite(led, HIGH);
    inte = digitalRead(lo);
  }                                   // FIN WHILE
  
  
  digitalWrite(led, LOW);
  
  int etbut = digitalRead(but);
 
  
 if (etbut == 1)                // DEBUT IF
{
    digitalWrite(ledv, HIGH);
    for (int i= 0; i<taille; i++)
    {



dt = tabd[i+1];                    // debut droite
      valx = dt;

      
       
       delay(25);
    
    
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





    gt = tabg[i+1];                // debut gauche
      valy = gt;

      
       
       delay(25);
    
    
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






    rt = tabr[i+1];              // debut rotation
      valxx = rt;

      
       
       delay(25);
    
    
     if (tempxx<valxx)
    {
    for (int i=tempxx; i<valxx; i++)
    {
      delay(var);
      srot.write(i);
    }
    }
      else 
    {
       for (int i=tempxx; valxx<=i; i--)
    {
      delay(var);
      srot.write(i);
    }
    }
    tempxx=valxx;





    pt = tabp[i+1];              // debut pince
      valyy = pt;

      
       
       delay(25);
    
    
     if (tempyy<valyy)
    {
    for (int i=tempyy; i<valyy; i++)
    {
      delay(var);
      spince.write(i);
    }
    }
      else 
    {
       for (int i=tempyy; valyy<=i; i--)
    {
      delay(var);
      spince.write(i);
    }
    }
    tempyy=valyy;




      
      delay(250);               // FIN DU IF
    }
    etbut = digitalRead(but);
}
  digitalWrite(ledv, LOW);
  delay(100);




}







/*void dep3(int tempx, int valx)     //dep rot
{
  valx = map (valx, 0, 1023, 0, 180);
    delay(25);
    
     if (tempx<valx)
    {
    for (int i=tempx; i<valx; i++)
    {
      delay(var);
      srot.write(i);
      
    }
    }
      else 
    {
       for (int i=tempx; valx<=i; i--)
    {
      delay(var);
      srot.write(i);
      
    }
    }
    tempx=valx;
   
   

}

void dep1(int tempx, int valx)       // dep droite
{
  valx = map (valx, 0, 1023, 0, 180);
    delay(25);
    
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
   
   

}

void dep2(int tempx, int valx)         // dep gauche
{
  valx = map (valx, 0, 1023, 0, 180);
    delay(25);
    
     if (tempx<valx)
    {
    for (int i=tempx; i<valx; i++)
    {
      delay(var);
      sgauche.write(i);
      
    }
    }
      else 
    {
       for (int i=tempx; valx<=i; i--)
    {
      delay(var);
      sgauche.write(i);
      
    }
    }
    tempx=valx;
   
   

}

void dep4(int tempx, int valx)       //dep pince
{
  valx = map (valx, 0, 1023, 0, 180);
    delay(25);
    
     if (tempx<valx)
    {
    for (int i=tempx; i<valx; i++)
    {
      delay(var);
      spince.write(i);
      
    }
    }
      else 
    {
       for (int i=tempx; valx<=i; i--)
    {
      delay(var);
      spince.write(i);
      
    }
    }
    tempx=valx;
   
   

}*/
