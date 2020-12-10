#include <msp430.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "draw.h"
#include "shapeStates.h"
#include "main.h"

#define W COLOR_WHITE
#define B COLOR_BLACK
#define R COLOR_RED
#define O COLOR_DARK_ORANGE

void state1()
{
  static char state = 0;
  int color = W;
  switch (state) {
  case 0:
    color = R;
    state++;
    break;
  case 1:
    color = W;
    state = 0;
    break;
  }

  clearScreen(B);
  drawSquare((screenWidth / 2),
	     (screenHeight/ 2),
	     11, 11, color);
  drawSquare((screenWidth / 2),
	     (screenHeight/ 2),
	     5, 5, B);
  redrawScreen = 1;
}

void state2()
{
  static char state = 0;
  int color = W;
  switch (state) {
  case 0:
    color = O;
    state++;
    break;
  case 1:
    color = W;
    state = 0;
    break;
  }
  
  clearScreen(B);
  drawSquare((screenWidth / 2),
	     (screenHeight/ 2),
	     15, 15, color);
  drawSquare((screenWidth / 2),
	     (screenHeight/ 2),
	     11, 11, B);
  drawSquare((screenWidth / 2),
	     (screenHeight/ 2),
	     5, 5, color);
  redrawScreen = 1;
}

void state3()
{
  state2();
  drawSquare((screenWidth / 2),
	     (screenHeight/ 2),
	     3, 3, R);
}

void state4()
{
  
  clearScreen(B);
  
  centerString8x12(30, "Button 1", W, B);
  centerString8x12(45, "Fur Elise", W, B);
  
  centerString8x12(60, "Button 2", R, B);
  centerString8x12(75, "In the Hall of", R, B);
  centerString8x12(90, "the Mountain King", R, B);
  
  centerString8x12(105, "Button 3", O, B);
  centerString8x12(120, "Rickroll'd", O, B);

  redrawScreen = 0;
}
