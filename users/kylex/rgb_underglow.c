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

void suspend_power_down_user(void) {
  rgblight_disable();
}

void suspend_wakeup_init_user(void) {
  rgblight_enable();
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
          rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 5);
          rgblight_sethsv_noeeprom(0, 0, 255);
          break;
        case _LOWER:
          rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 4);
          rgblight_sethsv_noeeprom(0, 0, 255);
          break;
        default:
          #ifdef KYLEX_RGB
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 9);
            rgblight_sethsv_noeeprom(245/*350*/, 0, 255);
          #else
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2);
            rgblight_sethsv_noeeprom(245/*350*/, 127, 255);
          #endif
          break;
        }
    } else if (!caps) {
      switch (layer) {
        case _RAISE:
          rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 5);
          rgblight_sethsv_noeeprom(100/*140*/, 255, 255);
          break;
        case _LOWER:
          rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 4);
          rgblight_sethsv_noeeprom(121/*170*/, 255, 255);
          break;
        case _QWERTY:
          #ifdef KYLEX_RGB
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 9);
            rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
          #else
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2);
            rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
          #endif
          break;
        #ifdef GAME_MODE
          case _GAME:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
            rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
            break;
        #endif
        #ifdef NUMPAD_LAYER
          case _NUMPAD:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
            rgblight_sethsv_noeeprom(0, 255, 255);
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
          rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 5);
          rgblight_sethsv_noeeprom(0, 0, 255);
        } else {
          rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 5);
          rgblight_sethsv_noeeprom(100/*140*/, 255, 255);
        }
        break;
      case _LOWER:
        if (caps && !ctxt) {
          rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 4);
          rgblight_sethsv_noeeprom(0, 0, 255);
        } else {
          rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 4);
          rgblight_sethsv_noeeprom(121/*170*/, 255, 255);
        }
        break;
      case _QWERTY:
        if (caps && !ctxt) {
          #ifdef KYLEX_RGB
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 9);
            rgblight_sethsv_noeeprom(0, 0, 255);
          #else
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2);
            rgblight_sethsv_noeeprom(245/*350*/, 127, 255);
          #endif
        } else {
          #ifdef KYLEX_RGB
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 9);
            rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
          #else
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2);
            rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
          #endif
          break;
        }
        break;
      #ifdef GAME_MODE
        case _GAME:
          if (caps && !ctxt) {
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
            rgblight_sethsv_noeeprom(0, 0, 255);
          } else {
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
            rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
          }
          break;
      #endif
      #ifdef NUMPAD_LAYER
        case _NUMPAD:
          if (caps && !ctxt) {
            rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
            rgblight_sethsv_noeeprom(0, 0, 255);
          } else {
            rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
            rgblight_sethsv_noeeprom(0, 255, 255);
          }
          break;
      #endif
    }
  return state;
}
