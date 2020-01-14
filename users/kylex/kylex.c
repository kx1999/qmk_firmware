#include "kylex.h"

bool up = false;
bool dn = false;
bool caps = false;
bool ctxt = false;
const uint8_t repeat = 5;                                                                                                      // Time between auto-repeated keystrokes (ms)

#ifdef RGBLIGHT_ENABLE

static int delay_runonce;
const int INIT_DELAY = 100;
static bool runonce = true;

void rgblight_wait(void) {
  delay_runonce = timer_read();
}

void rgblight_init_real(void) {
  if (runonce && timer_elapsed(delay_runonce) > INIT_DELAY) {
    runonce = false;
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2);
    rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
    #ifdef HLD_RGB
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + 9);
      rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
    #endif
    #ifdef PORTAL_RGB
      rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2);
      rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
    #endif
  }
}
#endif

__attribute__ ((weak))
void matrix_init_keymap(void) {}

void matrix_init_user(void) {
	#ifdef UNICODE_ENABLE
	set_unicode_input_mode(UC_WINC);
	#endif
  #ifdef RGBLIGHT_ENABLE
    rgblight_wait();
  #endif
  matrix_init_keymap();
};

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE
    rgblight_init_real();
  #endif
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
  matrix_scan_keymap();
}

void suspend_power_down_kb(void)
{
  #ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(true);
  #endif
  #ifdef RGBLIGHT_ENABLE
    rgblight_disable();
  #endif
}

void suspend_wakeup_init_kb(void)
{
  #ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(false);
  #endif
  #ifdef RGBLIGHT_ENABLE
    rgblight_enable();
  #endif
}