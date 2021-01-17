#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw.h"
#include "shapeStates.h"

void state1()
{
  static char s1_state = 0;
  u_int color;
  switch (s1_state) {
  case 0:
    color = COLOR_WHITE;
    s1_state++;
    break;
  case 1:
    color = COLOR_RED;
    s1_state = 0;
    break;
  }
  drawSquare(screenWidth / 2,
	     screenHeight/ 2,
	     11, 11, color);
}

void state2()
{
  static char s2_state = 0;
  u_int color;
  switch (s2_state) {
  case 0:
    color = COLOR_DARK_ORANGE;
    s2_state++;
    break;
  case 1:
  case 2:
    color = COLOR_RED;
    s2_state++;
    break;
  case 3:
    color = COLOR_WHITE;
    s2_state = 0;
    break;
  }
  drawSquare(screenWidth / 2,
	     screenHeight/ 2,
	     15, 15, color);
}

void state3()
{
  state2();
  drawSquare(screenWidth / 2,
	     screenHeight/ 2,
	     11, 11, COLOR_BLACK);
}

void state4()
{
  drawString8x12(0, 0, "Hello! and now", COLOR_WHITE, COLOR_BLACK);
  drawString8x12(0, 15, "Among Us:", COLOR_WHITE, COLOR_BLACK);
  drawString8x12(0, 30, "---------", COLOR_WHITE, COLOR_BLACK);
  drawString8x12(0, 45, "> where?", COLOR_RED, COLOR_BLACK);
  drawString8x12(0, 60, "> where?", COLOR_GREEN, COLOR_BLACK);
  drawString8x12(0, 75, "> elec", COLOR_BLUE, COLOR_BLACK);
  drawString8x12(0, 90, "> any sus?", COLOR_RED, COLOR_BLACK);
  drawString8x12(0, 105, "> you because", COLOR_BLUE, COLOR_BLACK);
  drawString8x12(0, 120, "  you're red", COLOR_BLUE, COLOR_BLACK);
  drawString8x12(0, 135, "> *I Voted*", COLOR_GREEN, COLOR_BLACK);
}
