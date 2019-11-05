
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
RGBLIGHT_ENABLE = no             # Enable WS2812 RGB underlight
LEADER_ENABLE = no                # Enable leader key chording
NO_USB_STARTUP_CHECK = yes        # Disables usb suspend check after keyboard startup
TAP_DANCE_ENABLE = yes            # Enables Tap-Dance functionality
AUTO_SHIFT_ENABLE = yes           # Enables auto shift functionality
BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SLEEP_LED_ENABLE = no
NKRO_ENABLE = yes
BACKLIGHT_ENABLE = no
MIDI_ENABLE = no
UNICODE_ENABLE = no
UNICODEMAP_ENABLE = no
UCIS_ENABLE = no
BLUETOOTH_ENABLE = no
AUDIO_ENABLE = no
FAUXCLICKY_ENABLE = no
API_SYSEX_ENABLE = no
KEY_LOCK_ENABLE = no

RGB_MATRIX_ENABLE = WS2812		  # Enables RGB matrix functionality

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no             # Breathing sleep LED during USB suspend

KYLEX_SONGS = no                  # Includes copyrighted songs
TAP_DANCE_MACROS = yes            # Includes custom macros
MISC_LAYER = yes
NUMPAD_LAYER = no
HLD_RGB = no
PORTAL_RGB = no
GAME_MODE = no

BOOTLOADER = qmk-dfu

# If you want to change the display of OLED, you need to change here
SRC +=  users/kylex/lib/glcdfont.c \
		users/kylex/lib/layer_state_reader.c \
        users/kylex/lib/logo_reader.c \
        #users/kylex/lib/host_led_state_reader.c \
        # users/kylex/lib/rgb_state_reader.c \
        # users/kylex/lib/keylogger.c \
        # users/kylex/lib/mode_icon_reader.c \
        # users/kylex/lib/timelogger.c \
