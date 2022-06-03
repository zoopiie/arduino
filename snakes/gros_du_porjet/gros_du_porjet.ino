#include <SPI.h>
#include <Wire.h>
#include <U8glib.h>


U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

// variable

int aux = 1;
int dir = 1;
int score = 0;
int taille = 4;
int pommex= random(0,127);
int pommey= random(0,63);
int snakex []={64,65,66,67};
int snakey []={32,32,32,32};
int tetex = 67;
int tetey = 32;
int tabx[] = {64,65,66,67};
int taby[] = {32,32,32,32};




void setup ()
{
  welcome();
  
  u8g.firstPage();
  
  
  pinMode(2, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  u8g.firstPage();
  do
  {
    u8g.setPrintPos(30, 15);
    
  

  u8g.print("move to");
  u8g.setPrintPos(30, 32);

  u8g.print("start");
 
  delay(20);
  int a0 = analogRead(A0);
  int a1 = analogRead(A1);
  int buttonstate = digitalRead(2);
  while( buttonstate== LOW)
  {
    buttonstate = digitalRead(2);
    delay(50);
  }
   }
  while (u8g.nextPage());
 
  empomme(pommex, pommey);
  affichage(tabx, taby, snakex,  snakey, pommex, pommey, taille);
  
  
  }
  
void loop()
{
  delay(20);

  tetex = snakex[taille];
  tetey = snakey[taille];

  int a0 = analogRead(A0);
  int a1 = analogRead(A1);
  if (800<a0)
  {
    aux=1;
  }
  if (a0<300)
  {
    aux=2;
  }
  if (a1<300)
  {
    aux=3;
  }
  if (800<a1)
  {
    aux=4;
  }
  verifdir(dir, aux);
  dir=aux;
  delay(50);
  avance(snakex, snakey, dir, tabx, taby, tetex, tetey, taille);
  delay(100);
  
  for (int i = 0; i<taille; i++)
  {
  snakex[i] = tabx[i];
  snakey[i] = taby[i];
  }
  affichage(tabx, taby, snakex,  snakey, pommex, pommey, taille);
  delay(50);
  if (pommex==tetex && pommey==tetey)
  {
    allongement(snakex, snakey, tetex, tetey, score);
    empomme(pommex, pommey); 
    delay(20); 
  }
  
  if (tetex==0||tetex==64||tetey==0||tetey==128)
  {
    verifechec(score, pommex, pommey, taille, snakex, snakey, tetex, tetey, tabx, taby);

  delay(50);
  }
  

}







void affichage(int *tabx,int *taby,int  *snakex,int *snakey, int pommex, int pommey, int taille)
{
  
  u8g.firstPage();
  do{
 for (int i = 0; i < taille; i++)
     {
      u8g.drawPixel(snakex[i], snakey[i]); 
     }

      u8g.drawPixel(pommex, pommey);
  }while(u8g.nextPage());
  
}



int avance(int *snakex,int *snakey,int dir,int *tabx,int *taby, int tetex, int tetey,int taille)
{
  switch (dir){
    case 1:
    tetex+=1;
    break;
    case 2:
     tetex-=1;
    break;
    case 3:
    tetey+=1;
    break;
    case 4:
     tetey-=1;
    break;
  }
    for (int i=0; i<taille-1; i++)
  {
    int ip=i+1;
    tabx[i] = snakex[ip];
    taby[i] = snakey[ip];
    
  }
   int at=taille-1;
   tabx[at]=tetex;
   taby[at]=tetey;
  
   return (tabx, taby, tetex, tetey); 
   
  
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




  


int empomme(int pommex,int pommey)
{
  int rx = random(0,127);
  int ry = random(0,63);
  pommex=rx;
  pommey=ry;
  return (pommex, pommey);
}




int allongement(int *snakex,int *snakey ,int tetex,int tetey,int score)
{
  int snakep1x[]= {snakex, tetex};
  int snakep1y[]= {snakey, tetey};
  score+=1;
  return (snakep1x, snakep1y, score);
}




void verifechec( int score,int pommex,int pommey,int taille,int *snakex,int *snakey,int tetex,int tetey, int *tabx, int *taby)
{
 if (tetex<0||tetex>128||tetey<0||tetey>64)
 {
  u8g.firstPage();
  do
  {
  u8g.setFont(u8g_font_gdr14r);
  u8g.setPrintPos(30, 20);
  u8g.print( "game over");
  u8g.setPrintPos(50, 45);
  u8g.print(score);
  
  }
  while(u8g.nextPage());
  delay(5000);

  u8g.drawBox(1,1,125,60);
  
  u8g.firstPage();
  do 
  {
  u8g.setPrintPos(30, 20);
  u8g.print( "press");
  }
  while(u8g.nextPage());
  int buttonstate = digitalRead(2);
  while( buttonstate== LOW)
  {
    buttonstate = digitalRead(2);
    delay(50);
  }
  u8g.firstPage();
  do 
  {
  u8g.drawBox(1,1,125,60);
   u8g.nextPage();
   u8g.setFont(u8g_font_gdr14r);
  u8g.setPrintPos(30, 15);
  u8g.print("move to");
  u8g.setPrintPos(30, 32);
  u8g.print("start");
  }
  while(u8g.nextPage());
  int a0 = analogRead(A0);
  int a1 = analogRead(A1);
  int aux = 1;
  int dir = 1;
  int score = 0;
  int taille = 4;
  int pommex= 0;
  int pommey=0;
  int snakex []={64,65,66,67};
  int snakey []={32,32,32,32};
  int tetex = 67;
  int tetey = 32;
  int tabx[] = {64,65,66,67};
  int taby[] = {32,32,32,32};
  while (480<a0<540||480<a1<540)
  {
    delay(10);
  }
  u8g.setFont(u8g_font_unifont);
  empomme(pommex, pommey);
  affichage(tabx, taby, snakex, snakey, pommex, pommey, taille);
  score=0;
 } 
}

void welcome()
{
   u8g.firstPage();
   
   do{
   
     u8g.setFont(u8g_font_gdr14r);
     u8g.setPrintPos(5, 20);
     u8g.print("Attention");
     u8g.setPrintPos(5, 38);
     u8g.print("  ca peut");
     u8g.setFont(u8g_font_gdr14r);
     u8g.setPrintPos(38, 55);
     u8g.print("bugger");
     delay(250);
   }
   while (u8g.nextPage());
  u8g.drawBox(1,1,125,60);
    
}
