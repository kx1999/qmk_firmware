SRC += kylex.c \
			custom_keycodes.c

LINK_TIME_OPTIMIZATION = yes

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tap_dance_macros.c
endif
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += rgb_underglow.c
endif

ifeq ($(strip $(KYLEX_SONGS)), yes)
  OPT_DEFS += -DKYLEX_SONGS
endif
ifeq ($(strip $(TAP_DANCE_MACROS)), yes)
  OPT_DEFS += -DTAP_DANCE_MACROS
endif
ifeq ($(strip $(GAME_MODE)), yes)
	OPT_DEFS += -DGAME_MODE
endif
ifeq ($(strip $(NUMPAD_LAYER)), yes)
	OPT_DEFS += -DNUMPAD_LAYER
endif