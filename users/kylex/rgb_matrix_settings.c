#include "kylex.h"

static uint8_t layer = _QWERTY;
bool ashift;
extern rgb_config_t rgbset;
uint8_t rgbm = RGB_MATRIX_ALPHAS_MODS;

void rgb_matrix_indicators_user(void) {
  if (!ctxt) {
    if (caps) {
      rgb_matrix_set_color( 18 , 255, 0  , 0  );
      rgb_matrix_set_color( 28 , 255, 0  , 0  );
    }
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
        rgb_matrix_mode_noeeprom(1);
        break;
      case _LOWER:
        rgb_matrix_config.hsv.h = 147;
        rgb_matrix_config.hsv.s = 240;
        rgb_matrix_config.hsv.v = 125;
        rgb_matrix_mode_noeeprom(1);
        break;
      case _QWERTY:
        autoshift_enable();
        rgb_matrix_config.hsv.h = rgbset.hsv.h;
        rgb_matrix_config.hsv.s = rgbset.hsv.s;
        rgb_matrix_config.hsv.v = rgbset.hsv.v;
        rgb_matrix_mode_noeeprom(rgbset.mode);
        break;
      #ifdef GAME_MODE
        case _GAME:
          autoshift_disable();
          rgb_matrix_config.hsv.s = 255;
          rgb_matrix_config.hsv.v = 125;
          rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
          break;
      #endif
      case _NAV:
        rgb_matrix_config.hsv.s = 255;
        rgb_matrix_config.hsv.v = 125;
        rgb_matrix_mode_noeeprom(RGB_MATRIX_JELLYBEAN_RAINDROPS);
        break;
      case _RGBL:
        rgb_matrix_config.hsv.h = rgbset.hsv.h;
        rgb_matrix_config.hsv.s = rgbset.hsv.s;
        rgb_matrix_config.hsv.v = rgbset.hsv.v;
        rgb_matrix_mode_noeeprom(rgbset.mode);
    }
  return state;
}
