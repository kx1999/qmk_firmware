#include "kylex.h"

bool up = false;
bool dn = false;
bool caps = false;
bool ctxt = false;
const uint8_t repeat = 5;                                                                                                      // Time between auto-repeated keystrokes (ms)

static int delay_runonce;
const int INIT_DELAY = 100;
static bool runonce = true;

void rgblight_wait(void) {
  delay_runonce = timer_read();
}

void rgblight_init_real(void) {
  if (runonce && timer_elapsed(delay_runonce) > INIT_DELAY) {
    runonce = false;
    #ifdef RGBLIGHT_ENABLE
      rgblight_enable_noeeprom();
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 9);
      rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
    #endif
  }
}

void matrix_init_user(void) {
	#ifdef UNICODE_ENABLE
	set_unicode_input_mode(UC_WINC);
	#endif
  #ifdef RGBLIGHT_ENABLE
    rgblight_wait();
  #endif
};

void matrix_scan_user(void) {
  rgblight_init_real();
  if (up) {
    register_code(KC_UP);
    unregister_code(KC_UP);
    _delay_ms(repeat);
  }
  if (dn) {
    register_code(KC_DOWN);
    unregister_code(KC_DOWN);
    _delay_ms(repeat);
  }
}
