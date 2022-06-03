#include <Servo.h>
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
int tempx = 70;
int tempy = 33;
int temp2x = 90;
int temp2y = 90;



const int bs = 4;
const int ba = 5;
int tab[1][4];
int size=1;
int c =0;
int truc [4] ;
int sd = 0;
int sg = 0;
int sr = 0;
int sp = 0;




void setup ()
{
  pinMode(bs, INPUT);
  pinMode(ba, INPUT);
  pinMode(button, INPUT);
  pinMode(buttonj, INPUT);
  pinMode(axey, INPUT);
  pinMode(axex, INPUT);
  pinMode(axe2x, INPUT);
  pinMode(axe2y, INPUT);
  sdroite.attach(11);
  sgauche.attach(10);
  spince.attach(6);
  srot.attach(9);
  
}



void loop ()
{
   val2y= analogRead(axe2y);              //pince
    val2y = map (val2y, 0, 1023, 0, 180);
    delay(25);
     if (temp2y<val2y)
    {
    for (int i=temp2y; i<val2y; i++)
    {
      delay(8);
      spince.write(i);
    }
    }
      else 
    {
       for (int i=temp2y; val2y<=i; i--)
    {
      delay(8);
      spince.write(i);
    }
    }
    temp2y=val2y;




    
     val2x= analogRead(axe2x);              //rotation
    val2x = map (val2x, 0, 1023, 0, 180);
    delay(25);
     if (temp2x<val2x)
    {
    for (int i=temp2x; i<val2x; i++)
    {
      delay(8);
      srot.write(i);
    }
    }
      else 
    {
       for (int i=temp2x; val2x<=i; i--)
    {
      delay(8);
      srot.write(i);
    }
    }
    temp2x=val2x;
     
     
     
     
     valx= analogRead(axex);                // droite
    valx = map (valx, 0, 1023, 0, 100);
    delay(25);
    valx = 180 - valx;
    
    
     if (tempx<valx)
    {
    for (int i=tempx; i<valx; i++)
    {
      delay(10);
      sdroite.write(i);
    }
    }
      else 
    {
       for (int i=tempx; valx<=i; i--)
    {
      delay(10);
      sdroite.write(i);
    }
    }
    tempx=valx;





     valy= analogRead(axey);                    //gauche
    valy = map (valy, 0, 1023, 0, 90);
    delay(25);
    valy = 180 - valy;
      if (tempy<valy)
    {
    for (int i=tempy; i<valy; i++)
    {
      delay(10);
      sgauche.write(i);
    }
    }
      else 
    {
       for (int i=tempy; valy<=i; i--)
    {
      delay(10);
      sgauche.write(i);
    }
    }
    tempy=valy;
      
    }
    
    
  






/*int dep4(int tempp)               // c'est la pince !!!
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
}*/


/*int dep4(int temp2x)                // dep servo pince v2
{
     val2y= analogRead(axe2x);     
    val2y = map (val2y, 0, 1023, 0, 180);
    delay(25);
     if (temp2y<val2y)
    {
    for (int i=temp2y; i<val2y; i++)
    {
      delay(8);
      spince.write(i);
    }
    }
      else 
    {
       for (int i=temp2y; val2y<=i; i--)
    {
      delay(8);
      spince.write(i);
    }
    }
    temp2y=val2y;
    return (temp2y);

    


int dep3(int temp2x)                // dep servo rotation
{
     val2x= analogRead(axe2x);     
    val2x = map (val2x, 0, 1023, 0, 180);
    delay(25);
     if (temp2x<val2x)
    {
    for (int i=temp2x; i<val2x; i++)
    {
      delay(8);
      srot.write(i);
    }
    }
      else 
    {
       for (int i=temp2x; val2x<=i; i--)
    {
      delay(8);
      srot.write(i);
    }
    }
    temp2x=val2x;
    return (temp2x);

}
  
int dep1(int tempx)           // dep servo droit
{ 
   valx= analogRead(axex);            
    valx = map (valx, 0, 1023, 60, 150);
    delay(25);
    valx = 180 - valx;
    
     if (tempx<valx)
    {
    for (int i=tempx; i<valx; i++)
    {
      delay(10);
      sdroite.write(i);
    }
    }
      else 
    {
       for (int i=tempx; valx<=i; i--)
    {
      delay(10);
      sdroite.write(i);
    }
    }
    tempx=valx;
    return (tempx);
}


int dep2 (int tempy)        // dep servo gauche
{      
      valy= analogRead(axey);       
    valy = map (valy, 0, 1023, 110, 180);
    delay(25);
    valy= 180 - valy;
      if (tempy<valy)
    {
    for (int i=tempy; i<valy; i++)
    {
      delay(10);
      sgauche.write(i);
    }
    }
      else 
    {
       for (int i=tempy; valy<=i; i--)
    {
      delay(10);
      sgauche.write(i);
    }
    }
    tempy=valy;
    
    return (tempy);
    
}*/





/*int append(int **tab, int *truc, int size)              // APPEND
{
  int sort[size+1][4];
  for (int i =0; i<size; i++)
  {
    for( int j=0; j<4;j++)
    {
      sort[i][j]=tab[i][j];
    }
  }
  for (int k=0; k<4; k++)
  {
    sort[size][k]=truc[k];
  }
  size+=1;
  return (sort, size);
}*/
