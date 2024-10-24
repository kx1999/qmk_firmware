#include "kylex.h"

//int TAP_CODE_DELAY = 0;
bool ashift = true;
#ifdef RGB_MATRIX_ENABLE
rgb_config_t rgbset;
#endif
bool rgblayer = false;
bool nav = false;
bool game = false;
bool rgbt = true;
//#ifdef AUDIO_ENABLE
//  float pt_disco[][2] = SONG(PLATINUM_DISCO);
//#endif

struct {
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
    case KC_QWER:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case KC_COLE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case KC_DVOR:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case KC_LOWR:
      if (!game) {
        #ifdef RGB_MATRIX_ENABLE
        rgbset = rgb_matrix_config;
        #endif
      }
      return true;
      break;
    case KC_RASE:
      if (!game) {
        #ifdef RGB_MATRIX_ENABLE
        rgbset = rgb_matrix_config;
        #endif
      }
      return true;
      break;
    case KC_GAME:
      if (record->event.pressed) {
        break;
      } else {
        if (game) {
          if (ashift) {
            if (!ctxt && !wtxt.on) {
              autoshift_enable();
            } else if (ctxt || wtxt.on) {
              autoshift_disable();
            }
          }
        } else {
          #ifdef RGB_MATRIX_ENABLE
          rgbset = rgb_matrix_config;
          #endif
          autoshift_disable();
        }
        game = !game;
      }
      return true;
      break;
    case KC_GTST:
      if (record->event.pressed) {
        break;
      } else {
        layer_invert(_GAME);
        if (game) {
          if (ashift) {
            if (!ctxt && !wtxt.on) {
              autoshift_enable();
            } else if (ctxt || wtxt.on) {
              autoshift_disable();
            }
          }
        } else {
          autoshift_disable();
        }
        game = !game;
      }
      return true;
      break;
/*    case KC_SUP:
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
      break;*/
    case KC_WTXT:
      if (record->event.pressed) {
        wtxt.on = !wtxt.on;
        wtxt.first = true;
        if (!ctxt && !wtxt.on) {
          autoshift_enable();
        } else if (ctxt || wtxt.on) {
          autoshift_disable();
        }
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
        if (!ctxt && !wtxt.on) {
          autoshift_enable();
        } else if (ctxt || wtxt.on) {
          autoshift_disable();
        }
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
        send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), 1);
      }
      return false;
      break;
    case KC_NEXD:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        register_code(KC_RIGHT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
        unregister_code(KC_RIGHT);
      }
      return false;
      break;
    case KC_PRED:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        register_code(KC_LEFT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
        unregister_code(KC_LEFT);
      }
      return false;
      break;
    case KC_NEWD:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        register_code(KC_D);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
        unregister_code(KC_D);
      }
      return false;
      break;
    case KC_CLOD:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        register_code(KC_F4);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
        unregister_code(KC_F4);
      }
      return false;
      break;
    case AS_TOGG:
      if (record->event.pressed) {
        ashift = !ashift;
      }
      return true;
      break;
    case KC_NAV:
      if (record->event.pressed) {
        nav = !nav;
      } else {
        nav = !nav;
      }
      return true;
      break;
    case KC_RTOG:
      if (record->event.pressed) {
        return true;
        break;
      } else {
        rgbt = !rgbt;
        return true;
        break;
      }
  }
  return process_record_keymap(keycode, record);
}
