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

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {30, 15, 8};
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {60, 50, 40};
const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {0, 0, 0, 0, 0};
static uint8_t layer = _QWERTY;

void led_set_user(uint8_t usb_led) {
  static uint8_t old_usb_led = 0;
  if ((usb_led & (1 << USB_LED_CAPS_LOCK)) && !(old_usb_led & (1 << USB_LED_CAPS_LOCK))) {
    caps = true;
  } else if (!(usb_led & (1 << USB_LED_CAPS_LOCK)) && (old_usb_led & (1 << USB_LED_CAPS_LOCK))) {
    caps = false;
  }
  old_usb_led = usb_led;

  if (!ctxt) {
    if (caps) {
      switch (layer) {
        case _RAISE:
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 5);
            rgblight_sethsv_noeeprom(0, 0, 255);
          #endif
          break;
        case _LOWER:
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 4);
            rgblight_sethsv_noeeprom(0, 0, 255);
          #endif
          break;
        default:
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 9);
            rgblight_sethsv_noeeprom(0, 0, 255);
          #endif
          break;
        }
    } else if (!caps) {
      switch (layer) {
        case _RAISE:
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 5);
            rgblight_sethsv_noeeprom(100/*140*/, 255, 255);
          #endif
          break;
        case _LOWER:
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 4);
            rgblight_sethsv_noeeprom(121/*170*/, 255, 255);
          #endif
          break;
        case _QWERTY:
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 9);
            rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
          #endif
          break;
        #ifdef GAME_MODE
          case _GAME:
            #ifdef RGBLIGHT_ENABLE
              rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
              rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
            #endif
            break;
        #endif
        #ifdef NUMPAD_LAYER
          case _NUMPAD:
            #ifdef RGBLIGHT_ENABLE
              rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
              rgblight_sethsv_noeeprom(0, 255, 255);
            #endif
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
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 5);
            rgblight_sethsv_noeeprom(0, 0, 255);
          #endif
        } else {
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 5);
            rgblight_sethsv_noeeprom(100/*140*/, 255, 255);
          #endif
        }
        break;
      case _LOWER:
        if (caps && !ctxt) {
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 4);
            rgblight_sethsv_noeeprom(0, 0, 255);
          #endif
        } else {
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 4);
            rgblight_sethsv_noeeprom(121/*170*/, 255, 255);
          #endif
        }
        break;
      case _QWERTY:
        if (caps && !ctxt) {
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 9);
            rgblight_sethsv_noeeprom(0, 0, 255);
          #endif
        } else {
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 9);
            rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
          #endif
        }
        break;
      #ifdef GAME_MODE
        case _GAME:
          if (caps && !ctxt) {
            #ifdef RGBLIGHT_ENABLE
              rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
              rgblight_sethsv_noeeprom(0, 0, 255);
            #endif
          } else {
            #ifdef RGBLIGHT_ENABLE
              rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
              rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
            #endif
          }
          break;
      #endif
      #ifdef NUMPAD_LAYER
        case _NUMPAD:
          if (caps && !ctxt) {
            #ifdef RGBLIGHT_ENABLE
              rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
              rgblight_sethsv_noeeprom(0, 0, 255);
            #endif
          } else {
            #ifdef RGBLIGHT_ENABLE
              rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
              rgblight_sethsv_noeeprom(0, 255, 255);
            #endif
          }
          break;
      #endif
    }
  return state;
}
