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
	#ifdef GAME_MODE
		_GAME,
	#endif
	_LOWER,
	_RAISE,
	_NUMPAD,
	_MISC,
};

void rgblight_wait(void);
void rgblight_init_real(void);
void matrix_init_user(void);
void matrix_scan_user(void);
