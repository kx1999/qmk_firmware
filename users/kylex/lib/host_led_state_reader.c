#include <stdio.h>
#include "crkbd.h"

char host_led_state_str[24];

const char *read_host_led_state(void)
{
  uint8_t leds = host_keyboard_leds();
  snprintf(host_led_state_str, sizeof(host_led_state_str), "Caps Lock:%s",
           (leds & (1 << USB_LED_CAPS_LOCK)) ? "ON" : "OFF");

  return host_led_state_str;
}
