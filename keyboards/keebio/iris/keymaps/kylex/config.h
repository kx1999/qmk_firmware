#include "copyrighted_songs.h"

#define USE_SERIAL
#define EE_HANDS

#define NO_ACTION_ONESHOT

#undef RGBLED_NUM
#define RGBLED_NUM 12
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_CHRISTMAS_STEP 6
#define RGBLIGHT_EFFECT_CHRISTMAS_INTERVAL 800
#define RGBLIGHT_EFFECT_SNAKE_LENGTH 12
#define RGBLIGHT_SLEEP

#define PERMISSIVE_HOLD
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 1
#undef TAPPING_TERM
#define TAPPING_TERM 175
#define FORCE_NKRO
#undef TAP_HOLD_CAPS_DELAY
#define TAP_HOLD_CAPS_DELAY 0

#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT 120
//#define AUTO_SHIFT_SETUP

#undef QMK_ESC_OUTPUT
#undef QMK_ESC_INPUT
#define QMK_ESC_OUTPUT D2
#define QMK_ESC_INPUT F1

#ifdef AUDIO_ENABLE
	#undef AUDIO_CLICKY
	#define NO_MUSIC_MODE
	#define C6_AUDIO
	#define STARTUP_SONG SONG(RENAI_CIRCULATION)
#endif
