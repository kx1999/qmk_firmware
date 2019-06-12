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
bool ttxt;
const uint8_t repeat;

enum iris_layers {
	_QWERTY,
	_GAME,
	_NUMPAD,
	_LOWER,
	_RAISE,
};

void rgblight_wait(void);
void rgblight_init_real(void);
void matrix_init_user(void);
void matrix_scan_user(void);
void led_set_user(uint8_t usb_led);
uint32_t layer_state_set_user(uint32_t state);
