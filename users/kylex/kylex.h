#pragma once

#include "quantum.h"
#include "eeprom.h"
#include "version.h"
#include "custom_keycodes.h"
#ifdef TAP_DANCE_MACROS
#include "tap_dance_macros.h"
#endif

bool up;
bool dn;
bool caps;
bool ctxt;
const uint8_t repeat;

enum global_layers {
	_QWERTY,
	_COLEMAK,
	_DVORAK,
	_GAMETEST,
	_GAME,
	_LOWER,
	_RAISE,
	_ADJUST,
	_NUMPAD,
	_NAV,
};
layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t layer_state_set_rgb(layer_state_t state);
layer_state_t layer_state_set_user(layer_state_t state);
void rgblight_wait(void);
void rgblight_init_real(void);
void matrix_init_user(void);
void matrix_scan_user(void);
