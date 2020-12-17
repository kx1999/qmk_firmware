#include "kylex.h"

static uint8_t layer = _QWERTY;
extern rgb_config_t rgbset;
extern bool nav;
extern bool game;
extern bool ashift;
extern struct {
  bool on;
  bool first;
} wtxt;

void rgb_matrix_indicators_user(void) {
  if (!ctxt) {
    if (caps) {
      rgb_matrix_set_color( 18 , 125, 0  , 0  );
    }
  }

  if (!game) {
    rgb_matrix_set_color( 31 , 0  , 60 , 125);
    rgb_matrix_set_color( 63 , 125, 40 , 0  );
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
    case _QWERTY:
      if (ashift) {
        if (!ctxt && !wtxt.on) {
          autoshift_enable();
        } else if (ctxt || wtxt.on) {
          autoshift_disable();
        }
      }
      rgb_matrix_config.hsv.h = rgbset.hsv.h;
      break;
    #ifdef GAME_MODE
      case _GAME:
        autoshift_disable();
        rgb_matrix_config.hsv.h = rgbset.hsv.h+63;                          // Rotates current colors 90 degrees
        break;
    #endif
  }
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}
