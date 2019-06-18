#pragma once

#define NO_ACTION_ONESHOT

#ifdef RGBLIGHT_ENABLE
	#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	#define RGBLIGHT_EFFECT_SNAKE
	#define RGBLIGHT_EFFECT_STATIC_GRADIENT
	#ifdef NUMPAD_LAYER
		#define RGBLIGHT_EFFECT_CHRISTMAS
		#define RGBLIGHT_EFFECT_CHRISTMAS_STEP (RGBLED_NUM/6)
		#define RGBLIGHT_EFFECT_CHRISTMAS_INTERVAL 800
	#endif
	#define RGBLIGHT_EFFECT_SNAKE_LENGTH RGBLED_NUM
	#define RGBLIGHT_SLEEP
#endif

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

#undef QMK_ESC_OUTPUT
#undef QMK_ESC_INPUT
#define QMK_ESC_OUTPUT D2
#define QMK_ESC_INPUT F1

#ifdef AUDIO_ENABLE
	#ifdef KYLEX_SONGS
		#undef CLOSE_ENCOUNTERS_5_NOTE
		#undef DOE_A_DEER
		#undef IN_LIKE_FLINT
		#undef IMPERIAL_MARCH
		#undef BASKET_CASE
		#undef COIN_SOUND
		#undef ONE_UP_SOUND
		#undef SONIC_RING
		#undef ZELDA_PUZZLE
		#undef ZELDA_TREASURE
		#undef OVERWATCH_THEME
		#undef MARIO_THEME
		#undef MARIO_GAMEOVER
		#undef MARIO_MUSHROOM
		#undef E1M1_DOOM
		#undef DISNEY_SONG
		#undef NUMBER_ONE
		#undef CABBAGE_SONG
		#undef OLD_SPICE
		#undef VICTORY_FANFARE_SHORT
		#undef ALL_STAR
		#undef RICK_ROLL
		#undef FF_PRELUDE
		#undef TO_BOLDLY_GO
		#undef KATAWARE_DOKI
		#undef MEGALOVANIA
		#undef MICHISHIRUBE
		#undef LIEBESLEID
		#undef MELODIES_OF_LIFE
		#undef EYES_ON_ME
		#undef SONG_OF_THE_ANCIENTS
		#undef NIER_AMUSEMENT_PARK
		#undef COPIED_CITY
		#undef VAGUE_HOPE_COLD_RAIN
		#undef KAINE_SALVATION
		#undef WEIGHT_OF_THE_WORLD
		#undef ISABELLAS_LULLABY
		#undef TERRAS_THEME
		#undef RENAI_CIRCULATION
		#undef PLATINUM_DISCO
		#include "kylex_songs.h"
	#endif
	#undef AUDIO_CLICKY
	#define NO_MUSIC_MODE
	#define STARTUP_SONG SONG(RENAI_CIRCULATION)
#endif
