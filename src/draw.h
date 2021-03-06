#ifndef draw_included
#define draw_included

void drawString8x12(u_char col, u_char row, char *string, u_int fgColorBGR, u_int bgColorBGR);
void drawChar8x12(u_char rcol, u_char rrow, char c, u_int fgColorBGR, u_int bgColorBGR);
void drawSquare(u_char centerX, u_char centerY, u_char width, u_char height, u_int color);
void centerString8x12(u_char row, char *string, u_int fgColorBGR, u_int bgColorBGR);

#endif
