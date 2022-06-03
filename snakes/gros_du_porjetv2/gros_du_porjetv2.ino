#include <SPI.h>
#include <Wire.h>
#include <U8glib.h>


U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

// variable

int aux = 1;
int dir = 1;
int score = 0;
int taille = 4;
int pomme[]= {0,0};
int snake [][2]={
  {64,32},
  {65,32},
  {66,32},
  {67,32}};
int tete[]= {67,32};
int tabaux [][2]= {
  {0,0},
  {0,0},
  {0,0},
  {0,0}
  };


void affichage(int **ta,int  **sn,int *pm)
{
  u8g.setFont(u8g_font_unifont);
  for (int i=0; i<ta; i++)
  {
    int x = sn[i][0];
    int y = sn[i][1];
    u8g.drawPixel(x, y);
    delay(10);
  }
  int xp = pm[0];
  int yp = pm[1];
  u8g.drawPixel(xp, yp);
}



int avance(int **sn,int dir,int **tx,int tt,int ta)
{
  int tap=ta-1;
  switch (dir){
    case 1:
    int xt = sn[tap][0]+1;
    int yt = sn[tap][1];
    tt = {xt , yt};
    break;
    case 2:
     xt = sn[tap][0]-1;
     yt = sn[tap][1];
     tt = {xt , yt};
    break;
    case 3:
     xt = sn[tap][0];
     yt = sn[tap][1]+1;
     tt = {xt , yt};
    break;
    case 4:
     xt = sn[tap][0];
     yt = (sn[tap][1])-1;
     tt = {xt , yt};
    break;
  }
  
  
  for (int i=0; i<(ta-1); i++)
  {
    int ip=i+1
    int xa = sn[ip][0];
    int ya = sn[ip][1];
    int tx[i][0]=xa;
    int tx[i][1]=ya;
  }
  at=ta-1
   tx[at][0]=xt;
   tx[at][1]=yt;
   return (tx, tt); 
  
}


int verifdir(int dir, int aux)
{
  if (dir==1 && aux==2)
  {
    aux=1;
  }
  if (dir==2 && aux==1)
  {
    aux=2;
  }
  if (dir==3 && aux==4)
  {
    aux=3;
  }
  if (dir==4 && aux==3)
  {
    aux=4;
  }
  return (aux);
  }
}

int empomme(pomme)
{
  int rx = random(0,127);
  int ry = random(0,63);
  pomme[0]=rx;
  pomme[1]=ry;
  return (pomme, rx, ry);
}

int allongement(sn, tt, sc)
{
  int snp1[][]= {sn, tt};
  sc+=1;
  return (snp1, sc);
}

void verifechec(int tx,int ty, int score,int pomme,int taille,int snake, int tete, int tabaux)
{
 if (tx==-1||tx==128||ty==-1||ty==64)
 {
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(30, 20, "game over");
  u8g.drawStr(50, 45, score);
  delay(5000)
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(30, 20, "press to reset");
  int buttonstate = digitalRead(2);
  while( buttonstate== LOW)
  {
    delay(50);
  }
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(30, 15,"move to");
  u8g.drawStr(30, 32,"start");
  int a0 = analogRead(A0);
  int a1 = analogRead(A1);
  int snake [][]={
  {64,32},
  {65,32},
  {66,32},
  {67,32}};
  int taille = 4;
  int tete[]= {67,32};
  int tabaux [][]= {
    {0,0},
    {0,0},
    {0,0},
    {0,0}
    };
  
  int aux = 1;
  int dir = 1;
  while (480<a0<540||480<a1<540)
  {
    delay(10);
  }
  u8g.setFont(u8g_font_unifont);
  empomme(pomme);
  affichage(taille, snake, pomme);
  score=0
 } 
}

void setup ()
{
  pinMode(2, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(30, 15,"move to");
  u8g.drawStr(30, 32,"start");
  int a0 = analogRead(A0);
  int a1 = analogRead(A1);
  while (480<a0<540||480<a1<540)
  {
    delay(10);
  }
  u8g.setFont(u8g_font_unifont);
  empomme(pomme);
  affichage(taille, snake, pomme);
  
  
  }
  
void loop()
{
  affichage(taille, snake, pomme);
  delay(20)
  int tx = snake[taille][0];
  int ty = snake[taille][1];
  tete[]= {tx, ty};
  int a0 = analogRead(A0);
  int a1 = analogRead(A1);
  if (600<a0)
  {
    aux=1;
  }
  if (a0<400)
  {
    aux=2;
  }
  if (a1<400)
  {
    aux=3;
  }
  if (600<a1)
  {
    aux=4;
  }
  verifdir(dir, aux);
  dir = aux;
  delay(20);
  avance(snake, dir, tabaux, tete, taille);
  snake= tabaux;
  affichage(taille, snake, pomme);
  delay(50)
  if (rx==tx && ry==ty)
  {
    allongement(snake, tete, score);
    empomme(pomme);  
  }
  verifechec(tx, ty, score, pomme, taille, snake, tete, tabaux);
  delay(50);
  
}
