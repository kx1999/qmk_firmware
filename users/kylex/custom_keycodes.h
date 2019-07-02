#pragma once

#include "kylex.h"

enum global_keycodes {
	KC_SUP = SAFE_RANGE,
	KC_SDN,
	KC_CTXT,
	KC_WTXT,
	KC_MAKE,
	KC_SHRG,
	KC_VRSN,
};

#define KC_         KC_TRNS
#define KC_BACK     KC_WBAK                                                                                                    // Back
#define KC_FRWD     KC_WFWD                                                                                                    // Forward
#define KC_CSFT     SFT_T(KC_CAPSLOCK)                                                                                         // Hold for Shift, tap for Caps Lock
#define KC_CESC     CTL_T(KC_ESC)                                                                                              // Hold for Ctrl, tap for Esc
#define KC_LOWR     TT(_LOWER)                                                                                                 // Tap toggle _LOWER layer
#define KC_RASE     TT(_RAISE)                                                                                                 // Tap toggle _RAISE layer
#define KC_MISC			TT(_MISC)
#ifdef NUMPAD_LAYER
#define KC_NUMP     TG(_NUMPAD)                                                                                                // Toggle _NUMPAD layer
#endif
#define KC_FTAB     LCTL(KC_TAB)                                                                                               // Next tab
#define KC_BTAB     LCTL(LSFT(KC_TAB))                                                                                         // Previous tab
#define KC_MDIA     TD(MDIA)                                                                                                   // Tap 1 for Play/Pause Media, Tap 2 to Toggle RGB Underglow
#define KC_HYP      TD(HY)                                                                                                     // HYP: Tap 1 for Printscreen, Tap 2 for Task Manager, Tap 3 to Ctrl+Alt+Del, Tap 4 to Sleep, Tap 5 to Shut Down, Tap 1 and Hold for Meh modifier, Tap 2 and Hold for Hyper modifier
#define KC_DSCR     TD(DC)                                                                                                     // DSCR: Tap 1 for Discord mute, Tap 2 for Discord deafen, Tap 3 to Toggle _GAME layer
#define KC_RSET			RESET

#ifdef RGB_MATRIX_ENABLE
	#define KC_RTOG		RGB_TOG
	#define KC_RHUI		RGB_HUI
	#define KC_RHUD	 	RGB_HUD
	#define KC_RSAI		RGB_SAI
	#define KC_RSAD		RGB_SAD
	#define KC_RVAI		RGB_VAI
	#define KC_RVAD		RGB_VAD
	#define KC_RMOD		RGB_MOD
	#define KC_RSPI		RGB_SPI
	#define KC_RSPD		RGB_SPD
#endif