#pragma once

#include "kylex.h"

enum global_keycodes {
	KC_SUP = SAFE_RANGE,
	KC_SDN,
	KC_QWER,
	KC_GTST,
	KC_COLE,
	KC_DVOR,
	KC_CTXT,
	KC_WTXT,
	KC_MAKE,
	KC_VRSN,
	KC_NEXD,
	KC_PRED,
	KC_NEWD,
	KC_CLOD
};

#define KC_LCA0     LCA(KC_0)                                                                                                   // Left Control + Alt + 0 ==== OBS Save Replay Buffer
#define KC_LCA9     LCA(KC_9)                                                                                                   // Left Control + Alt + 9 ==== OBS Toggle Recording
//#define KC_BACK     KC_WBAK                                                                                                     // Back
//#define KC_FRWD     KC_WFWD                                                                                                     // Forward
#define KC_CSFT     SFT_T(KC_CAPS_LOCK)                                                                                         // Hold for Shift, tap for Caps Lock
#define KC_CESC     CTL_T(KC_ESC)                                                                                               // Hold for Ctrl, tap for Esc

#define KC_LOWR     MO(_LOWER)                                                                                                  // Tap toggle _LOWER layer
#define KC_RASE     MO(_RAISE)                                                                                                  // Tap toggle _RAISE layer
#define KC_NAV		MO(_NAV)
#define KC_NUMP     MO(_NUMPAD)                                                                                                 // Toggle _NUMPAD layer

#define KC_FTAB     LCTL(KC_TAB)                                                                                                // Next tab
#define KC_BTAB     LCTL(LSFT(KC_TAB))                                                                                          // Previous tab
#define KC_HYP      TD(HY)                                                                                                      // HYP: Tap 1 for Printscreen, Tap 2 for Task Manager, Tap 3 to Ctrl+Alt+Del, Tap 4 to Sleep, Tap 5 to Shut Down, Tap 1 and Hold for Meh modifier, Tap 2 and Hold for Hyper modifier
#define KC_DSCR     TD(DC)                                                                                                      // DSCR: Tap 1 for Discord mute, Tap 2 for Discord deafen, Tap 3 to Toggle _GAME layer
#define KC_GAME		TG(_GAME)
#define KC_GTST		TG(_GAMETEST)
#define KC_RSET		RESET

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
