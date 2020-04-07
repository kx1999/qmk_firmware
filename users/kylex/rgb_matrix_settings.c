#include "kylex.h"

static uint8_t layer = _QWERTY;
extern rgb_config_t rgbset;
extern bool nav;
extern bool ashift;

void rgb_matrix_indicators_user(void) {
  if (!ctxt) {
    if (caps) {
      rgb_matrix_set_color( 18 , 125, 125, 125);
      rgb_matrix_set_color( 28 , 125, 125, 125);
    }
  }

  if (nav) {
    //Left side
    rgb_matrix_set_color( 9  , 125, 30 , 125);
    rgb_matrix_set_color( 13 , 125, 30 , 125);
    rgb_matrix_set_color( 14 , 125, 30 , 125);
    rgb_matrix_set_color( 15 , 125, 30 , 125);
    rgb_matrix_set_color( 20 , 125, 30 , 125);
    rgb_matrix_set_color( 21 , 125, 30 , 125);
    rgb_matrix_set_color( 26 , 125, 30 , 125);
    rgb_matrix_set_color( 27 , 125, 30 , 125);
    //Right side
    rgb_matrix_set_color( 41 , 125, 30 , 125);
    rgb_matrix_set_color( 45 , 125, 30 , 125);
    rgb_matrix_set_color( 46 , 125, 30 , 125);
    rgb_matrix_set_color( 47 , 125, 30 , 125);
    rgb_matrix_set_color( 52 , 125, 30 , 125);
    rgb_matrix_set_color( 53 , 125, 30 , 125);
    rgb_matrix_set_color( 58 , 125, 30 , 125);
    rgb_matrix_set_color( 59 , 125, 30 , 125);
  }
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    caps = true;
  } else {
    caps = false;
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  layer = biton32(state);
    switch (layer) {
      case _RAISE:
        rgb_matrix_config.hsv.h = 19;
        rgb_matrix_config.hsv.s = 255;
        rgb_matrix_config.hsv.v = 125;
        rgb_matrix_config.speed = 255;
        rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
        break;
      case _LOWER:
        rgb_matrix_config.hsv.h = 147;
        rgb_matrix_config.hsv.s = 240;
        rgb_matrix_config.hsv.v = 125;
        rgb_matrix_config.speed = 255;
        rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
        break;
      case _QWERTY:
        if (ashift) {
          autoshift_enable();
        }
        rgb_matrix_config.hsv.h = rgbset.hsv.h;
        rgb_matrix_config.hsv.s = rgbset.hsv.s;
        rgb_matrix_config.hsv.v = rgbset.hsv.v;
        rgb_matrix_config.speed = rgbset.speed;
        rgb_matrix_mode_noeeprom(rgbset.mode);
        break;
      #ifdef GAME_MODE
        case _GAME:
          autoshift_disable();
          rgb_matrix_config.hsv.h = 255;
          rgb_matrix_config.hsv.s = 255;
          rgb_matrix_config.hsv.v = 125;
          rgb_matrix_config.speed = 50;
          rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
          break;
      #endif
      case _NAV:
        break;
      case _RGBL:
        rgb_matrix_config.hsv.h = rgbset.hsv.h;
        rgb_matrix_config.hsv.s = rgbset.hsv.s;
        rgb_matrix_config.hsv.v = rgbset.hsv.v;
        rgb_matrix_config.speed = rgbset.speed;
        rgb_matrix_mode_noeeprom(rgbset.mode);
        break;
    }
  return state;
}
