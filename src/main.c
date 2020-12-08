#include <msp430.h>
#include "libTimer.h"
#include "buzz.h"
#include "led.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachine.h"

short redrawScreen = 1;

int main()
{
  configureClocks();
  switch_init();
  buzzer_init();
  lcd_init();
  led_init();
  enableWDTInterrupts();
  or_sr(0x8); // GIE on

  clearScreen(COLOR_BLACK);

  while (1) {
    if (redrawScreen) {
      clearScreen(COLOR_BLACK);
      redrawScreen = 0;
    }

    P1OUT &= ~BIT6; /* green off */
    or_sr(0x10); // CPU off
    P1OUT |= BIT6; /* green on */
  }  
  
}
