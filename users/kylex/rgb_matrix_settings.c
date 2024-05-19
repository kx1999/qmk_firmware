#include "kylex.h"

static uint8_t layer = _COLEMAK;
extern rgb_config_t rgbset;
extern bool nav;
extern bool game;
extern bool ashift;
extern bool rgbt;
extern struct {
  bool on;
  bool first;
} wtxt;

bool rgb_matrix_indicators_user(void) {
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
  return true;
}

bool led_update_user(led_t led_state) {
    static uint8_t caps_state = 0;
    if (caps_state != led_state.caps_lock) {
        led_state.caps_lock ? (caps = true) : (caps = false);
        caps_state = led_state.caps_lock;
    }
    return true;
}

layer_state_t layer_state_set_rgb(layer_state_t state) {
  layer = biton32(state);
  switch (layer) {
    case _COLEMAK:
      rgb_matrix_config.hsv.h = rgbset.hsv.h;
      break;
    #ifdef GAME_MODE
      case _GAME:
        rgb_matrix_config.hsv.v = rgbset.hsv.v;                          // Changes current colors
        break;
    #endif
  }
  return layer_state_set_keymap(state);
}
