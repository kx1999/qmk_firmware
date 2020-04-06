#include "kylex.h"

// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow
// 9-14 = Swirl (Left and right)
// 15-20 = Snake (Left and right)
// 21-23 = Nightrider
// 24 = Christmas
// 25-34 = Static Gradient

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {60, 30, 15};
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {60, 50, 40};
const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {0, 0, 0, 0, 0};
static uint8_t layer = _QWERTY;
HSV hsv = {0, 0, 0};

void rgb_matrix_indicators_user(void) {
  if (!ctxt) {
    if (caps) {
      hsv.h = rgb_matrix_get_hue();
      hsv.s = rgb_matrix_get_sat();
      hsv.v = rgb_matrix_get_val();
      rgb_matrix_set_color( 18 , 255, 0  , 0  );
    } else {
      rgb_matrix_set_color( 18 ,hsv.h,hsv.s,hsv.v);
    }
  }
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    caps = true;
  } else {
    caps = false;
  }

  if (!ctxt) {
    if (caps) {
      switch (layer) {
        case _RAISE:
          rgb_matrix_mode_noeeprom(1);
          break;
        case _LOWER:
          rgb_matrix_mode_noeeprom(1);
          break;
        default:
          rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
          break;
        }
    } else if (!caps) {
      switch (layer) {
        case _RAISE:
          rgb_matrix_mode_noeeprom(1);
          break;
        case _LOWER:
          rgb_matrix_mode_noeeprom(1);
          break;
        case _QWERTY:
          rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
          break;
        #ifdef GAME_MODE
          case _GAME:
            rgb_matrix_mode_noeeprom(1);
            break;
        #endif
        #ifdef NUMPAD_LAYER
          case _NUMPAD:
            rgb_matrix_mode_noeeprom(1);
            break;
        #endif
      }
    }
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  layer = biton32(state);
    switch (layer) {
      case _RAISE:
        if (caps && !ctxt) {
          rgb_matrix_mode_noeeprom(1);
        } else {
          rgb_matrix_mode_noeeprom(1);
        }
        break;
      case _LOWER:
        if (caps && !ctxt) {
          rgb_matrix_mode_noeeprom(1);
        } else {
          rgb_matrix_mode_noeeprom(1);
        }
        break;
      case _QWERTY:
        if (caps && !ctxt) {
          rgb_matrix_mode_noeeprom(1);
        } else {
          rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
          break;
        }
        break;
      #ifdef GAME_MODE
        case _GAME:
          if (caps && !ctxt) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
          } else {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_ALL);
          }
          break;
      #endif
      #ifdef NUMPAD_LAYER
        case _NUMPAD:
          if (caps && !ctxt) {
            rgb_matrix_mode_noeeprom(1);
          } else {
            rgb_matrix_mode_noeeprom(1);
          }
          break;
      #endif
    }
  return state;
}
