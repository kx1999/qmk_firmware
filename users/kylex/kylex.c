#include "kylex.h"

bool up = false;
bool dn = false;
bool caps = false;
bool ctxt = false;
const uint8_t repeat = 5;                                                                                                      // Time between auto-repeated keystrokes (ms)
//static uint8_t layer = _QWERTY;
#ifdef RGB_MATRIX_ENABLE
extern rgb_config_t rgbset;
#endif

__attribute__ ((weak))
void matrix_init_keymap(void) {}

void matrix_init_user(void) {
	#ifdef UNICODE_ENABLE
	set_unicode_input_mode(UC_WINC);
	#endif
  matrix_init_keymap();
  #ifdef RGB_MATRIX_ENABLE
  rgbset = rgb_matrix_config;
  #endif
};

__attribute__ ((weak))
layer_state_t layer_state_set_keymap(layer_state_t state) {
  return state;
}

__attribute__ ((weak))
layer_state_t layer_state_set_rgb(layer_state_t state) {
  return layer_state_set_keymap(state);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return layer_state_set_rgb(state);
}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
  if (up) {
    register_code(KC_UP);
    unregister_code(KC_UP);
    wait_ms(repeat);
  }
  if (dn) {
    register_code(KC_DOWN);
    unregister_code(KC_DOWN);
    wait_ms(repeat);
  }
  matrix_scan_keymap();
}

void suspend_power_down_kb(void)
{
  #ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(true);
  #endif
  suspend_power_down_user();
}

void suspend_wakeup_init_kb(void)
{
  #ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_suspend_state(false);
  #endif
  suspend_wakeup_init_user();
}
