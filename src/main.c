#include <msp430.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "p2switches.h"
#include "buzz.h"
#include "led.h"
#include "stateMachine.h"
#include "draw.h"
#include "shapeStates.h"

short needRedraw = 1;
char last_button_state = 0;

void wdt_c_handler()
{
  static char interrupt_count = 0;

  if (++interrupt_count == 62 && button_state == 0) {
    needRedraw = 1;
    interrupt_count = 0;
  } else if (interrupt_count == 80 && button_state == 1) {
    needRedraw = 1;
    interrupt_count = 0;
  } else if (interrupt_count == 50 && button_state == 2) {
    needRedraw = 1;
    interrupt_count = 0;
  } else if (interrupt_count == 62 && button_state == 3) {
    needRedraw = 1;
    interrupt_count = 0;
  }
}

int main()
{
  P1DIR |= GREEN;
  P1OUT |= GREEN;
  configureClocks();
  lcd_init();
  led_init();
  buzzer_init();
  p2sw_init(SWITCHES);
  
  enableWDTInterrupts();
  or_sr(0x8); // GIE on

  clearScreen(COLOR_BLACK);
  while (1) {
    if (needRedraw) {
      needRedraw = 0;
      if (button_state != last_button_state)
	clearScreen(COLOR_BLACK);
      song_advance();
      song_advance();
      switch (button_state) {
      case 0:
	state1();
	last_button_state = 0;
	break;
      case 1:
	state2();
	last_button_state = 1;
	break;
      case 2:
	state3();
	last_button_state = 2;
	break;
      case 3:
	state4();
	last_button_state = 3;
	break;
      }
    }

    P1OUT &= ~GREEN; /* green off */
    or_sr(0x10); // CPU off
    P1OUT |= GREEN; /* green on */
  }  
  
}
