#pragma once

#define USE_SERIAL
#define EE_HANDS

#ifdef RGBLIGHT_ENABLE
	#undef RGBLED_NUM
	#define RGBLED_NUM 12
	#undef RGBLIGHT_EFFECT_CHRISTMAS_STEP
	#define RGBLIGHT_EFFECT_CHRISTMAS_STEP 3
#endif

#ifdef AUDIO_ENABLE
	#define C6_AUDIO
#endif
