SRC += kylex.c \
			custom_keycodes.c

LTO_ENABLE = yes

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += rgb_underglow.c
endif
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += rgb_matrix_settings.c
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
ifeq ($(strip $(MISC_LAYER)), yes)
	OPT_DEFS += -DMISC_LAYER
endif
