#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw.h"

void drawSquare(u_char centerX, u_char centerY, u_char width, u_char height, u_int color)
{
  u_char leftX = centerX - width / 2;
  u_char topY  = centerY - height / 2;
  for (u_char r = 0; r < width; r++) {
    for (u_char c = 0; c < height; c++) {
      drawPixel(topY + c, leftX + r, color);
    }
  }
}

void drawChar8x12(u_char rcol, u_char rrow, char c, u_int fgColorBGR, u_int bgColorBGR)
{
  u_char col = 0;
  u_char row = 0;
  u_char bit = 0x80;
  u_char oc = c - 0x20;

  lcd_setArea(rcol, rrow, rcol + 7, rrow + 11);

  while (row < 12) {
    u_char holder = font_8x12[oc][row];
    while (col < 8) {
      u_int colorBGR = (holder & bit) ? fgColorBGR:bgColorBGR;
      lcd_writeColor(colorBGR);
      col++;
      bit >>= 1;
    }
    bit = 0x80;
    col = 0;
    row++;
  }
}

void drawString8x12(u_char col, u_char row, char *string, u_int fgColorBGR, u_int bgColorBGR)
{
  u_char cols = col;
  while (*string) {
    drawChar8x12(cols, row, *string++, fgColorBGR, bgColorBGR);
    cols += 9;
  }
}

void centerString8x12(u_char row, char *string, u_int fgColorBGR, u_int bgColorBGR)
{
  u_char length = 0;
  while (*string++) {
    length += 9;
  }
  drawString8x12((screenWidth - length) / 2,
		 row, string,
		 fgColorBGR, bgColorBGR);
}
