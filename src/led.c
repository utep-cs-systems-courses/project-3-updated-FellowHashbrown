#include <msp430.h>
#include "led.h"

static char red[] = {0, RED}, green[] = {0, GREEN};

unsigned char red_led_state = 0;
unsigned char green_led_state = 0;

void led_init()
{
  P1DIR |= LEDS;
  led_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed) {
    char ledFlags = 0;

    ledFlags = red[red_on] | green[green_on];

    P1OUT &= (0xff ^ LEDS) | ledFlags;
    P1OUT |= ledFlags;
    led_changed = 0;
  }
}

void dim_75()
{
  switch (red_led_state) {
    case 2:
    case 3:
    case 4:
    case 5:
      red_on = 1;
      if (++red_led_state == 6) {
        red_led_state = 0;
      }
      break;
    case 0:
    case 1:
      red_on = 0;
      red_led_state++;
      break;
  }
  led_changed = 1;
}

void dim_50()
{
  switch (red_led_state) {
    case 0:
    case 1:
    case 2:
      red_on = 1;
      red_led_state++;
      break;
    case 3:
    case 4:
    case 5:
      red_on = 0;
      if (++red_led_state == 6) {
        red_led_state = 0;
      }
      break;
  }
  led_changed = 1;
}

void dim_25()
{
  switch (red_led_state) {
    case 2:
    case 3:
    case 4:
    case 5:
      red_on = 0;
      if (++red_led_state == 6) {
        red_led_state = 0;
      }
      break;
    case 0:
    case 1:
      red_on = 1;
      red_led_state++;
      break;
  }
  led_changed = 1;
}

void dimming_states()
{
  static char dim_state = 0;
  switch (dim_state) {
  case 0:
    dim_75();
    dim_state++;
    break;
  case 6:
  case 18:
    dim_50();
    dim_state++;
    break;
  case 12:
    dim_25();
    dim_state++;
    break;
  case 23:
    dim_state = 0;
    break;
  default:
    dim_state++;
  }
}

void toggle_red()
{
  if (red_on) {
    red_on = 0;
  } else {
    red_on = 1;
  }
  led_changed = 1;
}

void toggle_off()
{
  red_on = 0;
  led_changed = 1;
}
