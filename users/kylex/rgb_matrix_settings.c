#include "kylex.h"

static uint8_t layer = _QWERTY;
extern rgb_config_t rgbset;
extern bool nav;
extern bool game;
extern bool ashift;
extern bool rgbt;
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

  if (!game && rgbt) {
    rgb_matrix_set_color( 31 , 0  , 60 , 125);
    rgb_matrix_set_color( 63 , 125, 40 , 0  );
  }

  if (nav) {
    //Left side
    rgb_matrix_set_color( 9  , 30 , 30 , 125);
    rgb_matrix_set_color( 13 , 30 , 30 , 125);
    rgb_matrix_set_color( 14 , 30 , 30 , 125);
    rgb_matrix_set_color( 15 , 30 , 30 , 125);
    rgb_matrix_set_color( 20 , 30 , 30 , 125);
    rgb_matrix_set_color( 21 , 30 , 30 , 125);
    rgb_matrix_set_color( 26 , 30 , 30 , 125);
    rgb_matrix_set_color( 27 , 30 , 30 , 125);
    //Right side
    rgb_matrix_set_color( 41 , 30 , 30 , 125);
    rgb_matrix_set_color( 45 , 30 , 30 , 125);
    rgb_matrix_set_color( 46 , 30 , 30 , 125);
    rgb_matrix_set_color( 47 , 30 , 30 , 125);
    rgb_matrix_set_color( 52 , 30 , 30 , 125);
    rgb_matrix_set_color( 53 , 30 , 30 , 125);
    rgb_matrix_set_color( 58 , 30 , 30 , 125);
    rgb_matrix_set_color( 59 , 30 , 30 , 125);
  }
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    caps = true;
  } else {
    caps = false;
  }
}

layer_state_t layer_state_set_rgb(uint32_t state) {
  layer = biton32(state);
  switch (layer) {
    case _QWERTY:
      rgb_matrix_config.hsv.h = rgbset.hsv.h;
      break;
    #ifdef GAME_MODE
      case _GAME:
        rgb_matrix_config.hsv.h = rgbset.hsv.h+110;                          // Rotates current colors 90 degrees
        break;
    #endif
  }
  return layer_state_set_keymap(state);
}
