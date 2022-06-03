#include "U8glib.h"
#define RIGHT 0
#define UP    1
#define LEFT  2
#define DOWN  3
//CLK = 10, MOSI = 9 , CS = 12, DC = 11, RES = 13
U8GLIB_SSD1306_128X64 u8g(10, 9, 12, 11, 13);
int score = 0;
int level = 1;
int gamespeed = 100;
int i;
int aux=1;
int dir=1;
//Constitute the unit, 4x4 pixels in the box.
const uint8_t ele[] PROGMEM = {
  0xf0, //B1111000
  0xb0, //B1011000
  0xd0, //B1101000
  0xf0, //B1111000
};
//snake
void element(int x, int y) {
  u8g.drawBitmapP(x,y, 1,4, ele);
}
struct FOOD {
  int x;
  int y;
  int yes;
};
FOOD food = {5, 50, 1};//(,97)
struct SNAKE {
  int x[200];
  int y[200];
  int node;
  int dir;
  int lefe;
  
};
  SNAKE snake= {{9,5}, {30,30}, 2, RIGHT, 0};
void UI() {   //Basic game interface
  u8g.drawFrame(0,1, 102,62);   //Internal boundary
  u8g.drawFrame(0,0, 102,64);   //External boundary
  u8g.setFont(u8g_font_5x7);    //Set the font
  u8g.drawStr(104,12, "LEVEL"); //Level of tips
  u8g.drawStr(104,40, "SCORE"); //Score tips
}
void printScore(int x, int y, int s) {
  u8g.setFont(u8g_font_6x10);
  u8g.setPrintPos(x, y);
  u8g.print(s);
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

void key() {
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
  if(aux ==2) 
  {
    snake.dir = DOWN;
  }
  if(aux==4) 
  {
    snake.dir = RIGHT;
  }
  if(aux==3) 
  {
    snake.dir = LEFT;
  }
  if(aux==1) 
  {
    snake.dir = UP;
  }
}
void snakeGame() {
  switch(snake.dir) {
    case RIGHT:
          snake.x[0] += 4;
          if(snake.x[0]>=101) {
            snake.x[0] = 1;
          } break;
    case UP:
          snake.y[0] -= 4;
          if(snake.y[0]<=1) {
            snake.y[0] = 58;
          } break;
    case LEFT:
          snake.x[0] -= 4;
          if(snake.x[0]<=0) {
            snake.x[0] = 97;
          } break;
    case DOWN:
          snake.y[0] += 4;
          if(snake.y[0]>=62) {
            snake.y[0] = 2;
          } break;
  }
  if((snake.x[0] == food.x) && (snake.y[0] == food.y)) {
    snake.x[0] = food.x;
    snake.y[0] = food.y;
    snake.node++;
    food.yes = 1;
    score += 2;
    level = score/10+1;//FOOD food = {random(1, 20), 50, 1};
  }
  for(i=snake.node-1;i>0;i--) {
    snake.x[i] = snake.x[i-1];
    snake.y[i] = snake.y[i-1];
  }
}
void setup() {
  pinMode(2, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}
void loop() {
  u8g.firstPage();
  do {
    UI();
    for(i=0; i<snake.node;i++) {
      element(snake.x[i], snake.y[i]);
    }
    element(food.x, food.y);
    printScore(103, 62, food.x);
    printScore(116, 62, food.y);
    printScore(109, 22, level);
    printScore(109, 50, score);
  }while(u8g.nextPage());
  key();
  snakeGame();
  delay(gamespeed);
}
