
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
EXTRAKEY_ENABLE = yes             # Audio control and System control(+450)
NKRO_ENABLE = yes                 # N-key Rollover
AUDIO_ENABLE = no                 # Audio output on port C6
RGBLIGHT_ENABLE = yes             # Enable WS2812 RGB underlight
LEADER_ENABLE = no                # Enable leader key chording
UNICODE_ENABLE = no               # Enables Unicode output with WinCompose
NO_USB_STARTUP_CHECK = yes        # Disables usb suspend check after keyboard startup
TAP_DANCE_ENABLE = yes            # Enables Tap-Dance functionality
BACKLIGHT_ENABLE = no             # Enable keyboard backlight functionality
API_SYSEX_ENABLE = no             # Future API functionality (leave disabled)
AUTO_SHIFT_ENABLE = yes           # Enables auto shift functionality

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no             # Breathing sleep LED during USB suspend

KYLEX_SONGS = no                  # Includes copyrighted songs
TAP_DANCE_MACROS = yes            # Includes custom macros

BOOTLOADER = qmk-dfu

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
