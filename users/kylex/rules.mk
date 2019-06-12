SRC += kylex.c \
			custom_keycodes.c

LINK_TIME_OPTIMIZATION = yes
AUTO_SHIFT_ENABLE = yes

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tap_dance_macros.c
endif

ifeq ($(strip $(COPYRIGHTED_SONGS)), yes)
  OPT_DEFS += -DCOPYRIGHTED_SONGS
endif
ifeq ($(strip $(TAP_DANCE_MACROS)), yes)
  OPT_DEFS += -DTAP_DANCE_MACROS
endif
