#pragma once

#define USE_SERIAL
#define EE_HANDS

#ifdef RGBLED_ENABLE
	#undef RGBLED_NUM
	#define RGBLED_NUM 12
#endif

#ifdef AUDIO_ENABLE
	#define C6_AUDIO
#endif
