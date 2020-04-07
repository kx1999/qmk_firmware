#include "kylex.h"

int TAP_CODE_DELAY = 0;
static int prev = 0;
bool ashift = false;
rgb_config_t rgbset;
bool rgblayer = false;
static uint16_t timer;
//#ifdef AUDIO_ENABLE
//  float pt_disco[][2] = SONG(PLATINUM_DISCO);
//#endif

static struct {
    bool on;
    bool first;
  } wtxt = {false, false};

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (wtxt.on) {
    if (record->event.pressed) {
      switch (keycode) {
        case KC_A...KC_0:
        case KC_SPC:
          if (wtxt.first) {
            wtxt.first = false;
          } else {
            send_char(' ');
          }
          break;
        case KC_ENT:
          wtxt.first = true;
          break;
        case KC_BSPC:
          send_char('\b'); // backspace
          break;
      }
    }
  }
	if (ctxt) {
    if (record->event.pressed) {
      tap_code(KC_CAPS);
    }
	}

  switch (keycode) {
    case KC_LOWR:
      if (record->event.pressed) {
        prev = 0;
        if (layer_state_is(_RAISE)) {
          prev = 2;
        } else {
          prev = 0;
        }
        layer_off(_RAISE);
        timer = timer_read();
      } else if ((prev == 2) && (timer_elapsed(timer) > TAPPING_TERM)) {
        layer_on(_RAISE);
      } else if ((prev == 0) && (timer_elapsed(timer) > TAPPING_TERM)) {
        layer_off(_RAISE);
      }
      return true;
      break;
    case KC_RASE:
      if (record->event.pressed) {
        prev = 0;
        if (layer_state_is(_LOWER)) {
          prev = 1;
        } else {
          prev = 0;
        }
        layer_off(_LOWER);
        timer = timer_read();
      } else if ((prev == 1) && (timer_elapsed(timer) > TAPPING_TERM)) {
        layer_on(_LOWER);
      } else if ((prev == 0) && (timer_elapsed(timer) > TAPPING_TERM)) {
        layer_off(_LOWER);
      }
      return true;
      break;
    case KC_SUP:
      if (record->event.pressed) {
        up = true;
      } else {
        up = false;
      }
      return false;
      break;
    case KC_SDN:
      if (record->event.pressed) {
        dn = true;
      } else {
        dn = false;
      }
      return false;
      break;
    case KC_WTXT:
      if (record->event.pressed) {
        wtxt.on = !wtxt.on;
        wtxt.first = true;
      }
      return false;
      break;
    case KC_CTXT:
     	if (record->event.pressed) {
     		ctxt = !ctxt;
        if (caps) {
          tap_code(KC_CAPS);
        }
        tap_code(KC_CAPS);
     	}
     	return false;
      break;
    case KC_SHRG: // ¯\_(ツ)_/¯
      if (record->event.pressed) {
        #ifdef UNICODE_ENABLE
        send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
        #endif
      }
      return false;
      break;
    case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
      if (!record->event.pressed) {
      	uint8_t mods = get_mods();
        clear_mods();
        send_string_with_delay_P(PSTR("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP "\n"), 1); //New way
        set_mods(mods);
      }
      return false;
      break;
    case KC_VRSN: // Prints firmware version
      if (record->event.pressed) {
        send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), TAP_CODE_DELAY);
      }
      return false;
      break;
    case KC_NEXD:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTRL);
        register_code(KC_RIGHT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTRL);
        unregister_code(KC_RIGHT);
      }
      return false;
      break;
    case KC_PRED:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTRL);
        register_code(KC_LEFT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTRL);
        unregister_code(KC_LEFT);
      }
      return false;
      break;
    case KC_NEWD:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTRL);
        register_code(KC_D);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTRL);
        unregister_code(KC_D);
      }
      return false;
      break;
    case KC_CLOD:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTRL);
        register_code(KC_F4);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTRL);
        unregister_code(KC_F4);
      }
      return false;
      break;
    case KC_ASTG:
      if (record->event.pressed) {
        ashift = !ashift;
      }
      return true;
      break;
    case KC_RGBL:
      if (record->event.pressed) {
        if (rgblayer) {
          rgbset = rgb_matrix_config;
          rgblayer = !rgblayer;
        } else {
          rgblayer = !rgblayer;
        }
      }
      return true;
      break;
  }
  return process_record_keymap(keycode, record);
}
