#include <msp430.h>
#include <lcdutils.h>
#include "draw.h"
#include "shapeStates.h"

#define W COLOR_WHITE
#define B COLOR_BLACK
#define R COLOR_RED
#define O COLOR_DARK_ORANGE

void state1()
{
  clearScreen(B);
  drawSquare((screenWidth / 2),
	     (screenHeight/ 2),
	     10, 10, W);
  drawSquare((screenWidth / 2),
	     (screenHeight/ 2),
	     5, 5, B);
}

void state2()
{
  clearScreen(B);
  drawSquare((screenWidth / 2),
	     (screenHeight/ 2),
	     15, 15, W);
  drawSquare((screenWidth / 2),
	     (screenHeight/ 2),
	     10, 10, B);
  drawSquare((screenWidth / 2),
	     (screenHeight/ 2),
	     5, 5, W);
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
  centerString8x12(15, "Button 1", W, B);
  centerString8x12(30, "Fur Elise", W, B);
  
  centerString8x12(45, "Button 2", R, B);
  centerString8x12(60, "In the Hall of", R, B);
  centerString8x12(75, "the Mountain King", R, B);
  centerString8x12(90, "Button 3", O, B);
  centerString8x12(105, "Rickroll'd", O, B);
}
