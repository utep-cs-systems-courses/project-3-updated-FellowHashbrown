#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzz.h"
#include "p2switches.h"

void state_advance()
{
  static char blink_state = 0;
  switch (blink_state) {
  case 0:
    dim_75();
    blink_state++;
    break;
  case 1:
    dim_50();
    blink_state++;
    break;
  case 2:
    dim_25();
    blink_state++;
    break;
  case 3:
    toggle_off();
    blink_state = 0;
    break;
  }

  led_changed = 1;
}

/*
void song_advance()
{
    switch (button_state) {
      case 0:
	song_1();
	break;
      case 1:
        song_2();
	break;
      case 2:
	song_3();
	break;
      case 3:
	buzzer_set_period(0);
	break;
  }
}
*/
