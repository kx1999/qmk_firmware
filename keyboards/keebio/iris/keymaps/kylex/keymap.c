#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum iris_layers {
  _QWERTY,
  _GAME,
  _NUMPAD,
  _LOWER,
  _RAISE,
};

enum custom_keycodes {
	KC_SUP = SAFE_RANGE,
  KC_SDN,
  KC_TTXT,
  KC_WTXT,
};

enum {
  HY = 0,
  DC,
  MDIA,
};

#define KC_         KC_TRNS
#define KC_BACK     KC_WBAK                                                                                                    // Back
#define KC_FRWD     KC_WFWD                                                                                                    // Forward
#define KC_CSFT     SFT_T(KC_CAPSLOCK)                                                                                         // Hold for Shift, tap for Caps Lock
#define KC_CESC     CTL_T(KC_ESC)                                                                                              // Hold for Ctrl, tap for Esc
#define KC_LOWR     TT(_LOWER)                                                                                                 // Tap toggle _LOWER layer
#define KC_RASE     TT(_RAISE)                                                                                                 // Tap toggle _RAISE layer
#define KC_NUMP     TG(_NUMPAD)                                                                                                // Toggle _NUMPAD layer
#define KC_FTAB     LCTL(KC_TAB)                                                                                               // Next tab
#define KC_BTAB     LCTL(LSFT(KC_TAB))                                                                                         // Previous tab
#define KC_MDIA     TD(MDIA)                                                                                                   // Tap 1 for Play/Pause Media, Tap 2 to Toggle RGB Underglow
#define KC_HYP      TD(HY)                                                                                                     // HYP: Tap 1 for Printscreen, Tap 2 for Task Manager, Tap 3 to Ctrl+Alt+Del, Tap 4 to Sleep, Tap 5 to Shut Down, Tap 1 and Hold for Meh modifier, Tap 2 and Hold for Hyper modifier
#define KC_DSCR     TD(DC)                                                                                                     // DSCR: Tap 1 for Discord mute, Tap 2 for Discord deafen, Tap 3 to Toggle _GAME layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
    //    ,----+----+----+----+----+----.              ,----+----+----+----+----+----.
           GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,DEL ,
    //    |----+----+----+----+----+----|              |----+----+----+----+----+----|
           TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
    //    |----+----+----+----+----+----|              |----+----+----+----+----+----|
           CESC, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
    //    |----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
           CSFT, Z  , X  , C  , V  , B  ,DSCR,     MDIA, N  , M  ,COMM,DOT ,SLSH,HYP ,
    //    `----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                             LALT,LOWR,ENT ,         SPC ,RASE,LGUI
    //                      `----+----+----'        `----+----+----'
    ),

  [_GAME] = LAYOUT_kc(
    //    ,----+----+----+----+----+----.              ,----+----+----+----+----+----.
           ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,DEL ,
    //    |----+----+----+----+----+----|              |----+----+----+----+----+----|
           TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
    //    |----+----+----+----+----+----|              |----+----+----+----+----+----|
           LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
    //    |----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
           LSFT, Z  , X  , C  , V  , B  ,DSCR,     MDIA, N  , M  ,COMM,DOT ,SLSH,HYP ,
    //    `----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                             LALT,SPC ,ENT ,         SPC ,RASE,LGUI
    //                      `----+----+----'        `----+----+----'
    ),

  [_LOWER] = LAYOUT_kc(
    //    ,----+----+----+----+----+----.              ,----+----+----+----+----+----.
               ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,    ,
    //    |----+----+----+----+----+----|              |----+----+----+----+----+----|
               ,NUMP,WTXT,TTXT,    ,LCBR,               RCBR,    ,    ,    ,    ,    ,
    //    |----+----+----+----+----+----|              |----+----+----+----+----+----|
               ,HOME, SUP,BTAB,FTAB,LPRN,               RPRN,    ,    ,    ,    ,    ,
    //    |----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
               ,END , SDN,BACK,FRWD,LBRC,    ,         ,RBRC,    ,    ,    ,    ,    ,
    //    `----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                                 ,    ,    ,             ,    ,    
    //                      `----+----+----'        `----+----+----'
    ),

  [_RAISE] = LAYOUT_kc(
    //    ,----+----+----+----+----+----.              ,----+----+----+----+----+----.
           F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
    //    |----+----+----+----+----+----|              |----+----+----+----+----+----|
               ,    ,    , UP ,    ,MINS,               PLUS,MPRV, UP ,MNXT,VOLU,    ,
    //    |----+----+----+----+----+----|              |----+----+----+----+----+----|
               ,    ,LEFT,DOWN,RGHT,UNDS,               EQL ,LEFT,DOWN,RGHT,VOLD,PGUP,
    //    |----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
               ,    ,    ,    ,    ,PIPE,    ,         ,BSLS,CALC,MYCM,    ,INS ,PGDN,
    //    `----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                                 ,    ,    ,             ,    ,
    //                      `----+----+----'        `----+----+----'
    ),

  [_NUMPAD] = LAYOUT_kc(
    //    ,----+----+----+----+----+----.              ,----+----+----+----+----+----.
               ,    ,NLCK,PSLS,PAST,PMNS,                   ,    ,    ,    ,    ,DEL ,
    //    |----+----+----+----+----+----|              |----+----+----+----+----+----|
               ,NUMP, P7 , P8 , P9 ,PPLS,                   ,    ,    ,    ,    ,BSPC,
    //    |----+----+----+----+----+----|              |----+----+----+----+----+----|
               ,DEL , P4 , P5 , P6 ,    ,                   ,    ,    ,    ,    ,    ,
    //    |----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
               ,BSPC, P1 , P2 , P3 ,PDOT,    ,         ,    ,    ,    ,    ,    ,    ,
    //    `----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                                 , P0 ,PENT,             ,    ,     
    //                      `----+----+----'        `----+----+----'
    ),

};

int prev = 0;
bool up = false;
bool dn = false;
const uint8_t repeat = 5;                                                                                                      // Time between auto-repeated keystrokes (ms)
static uint16_t timer;
bool caps = false;

static struct {
    bool on;
    bool first;
  } wtxt = {false, false};
static bool ttxt = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (wtxt.on) {
    if (record->event.pressed) {
      switch (keycode) {
        case KC_A...KC_0:
        case KC_SPC:
          if (wtxt.first) {
            wtxt.first = false;
          } else {
            send_char(' ');
          }
          break;
        case KC_ENT:
          wtxt.first = true;
          break;
        case KC_BSPC:
          send_char('\b'); // backspace
          break;
      }
    }
  }
	if (ttxt) {
    if (record->event.pressed) {
      tap_code(KC_CAPS);
    }
	}

  switch (keycode) {
    case KC_LOWR:
      if (record->event.pressed) {
        prev = 0;
        if (layer_state_is(_RAISE)) {
          prev = 2;
        } else {
          prev = 0;
        }
        layer_off(_RAISE);
        timer = timer_read();
      } else if ((prev == 2) && (timer_elapsed(timer) > TAPPING_TERM)) {
        layer_on(_RAISE);
      } else if ((prev == 0) && (timer_elapsed(timer) > TAPPING_TERM)) {
        layer_off(_RAISE);
      }
      return true;
      break;
    case KC_RASE:
      if (record->event.pressed) {
        prev = 0;
        if (layer_state_is(_LOWER)) {
          prev = 1;
        } else {
          prev = 0;
        }
        layer_off(_LOWER);
        timer = timer_read();
      } else if ((prev == 1) && (timer_elapsed(timer) > TAPPING_TERM)) {
        layer_on(_LOWER);
      } else if ((prev == 0) && (timer_elapsed(timer) > TAPPING_TERM)) {
        layer_off(_LOWER);
      }
      return true;
      break;
    case KC_SUP:
      if (record->event.pressed) {
        up = true;
      } else {
        up = false;
      }
      return false;
      break;
    case KC_SDN:
      if (record->event.pressed) {
        dn = true;
      } else {
        dn = false;
      }
      return false;
      break;
    case KC_WTXT:
      if (record->event.pressed) {
        wtxt.on = !wtxt.on;
        wtxt.first = true;
      }
      return false;
    case KC_TTXT:
     	if (record->event.pressed) {
     	  ttxt = !ttxt;
     	  tap_code(KC_CAPS);
     	}
     	return false;
  }
  return true;
}

// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow
// 9-14 = Swirl (Left and right)
// 15-20 = Snake (Left and right)
// 21-23 = Nightrider
// 24 = Christmas
// 25-34 = Static Gradient

const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 15, 8, 4};
const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {60, 30, 15};
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {30, 15, 8};
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {60, 50, 40};
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {60, 45, 30};
const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {180, 120, 90, 60, 45};

uint8_t layer = _QWERTY;
int delay_runonce;
int INIT_DELAY = 100;
static bool runonce = true;

void rgblight_wait(void) {
  delay_runonce = timer_read();
}

void rgblight_init_real(void) {
  if (runonce && timer_elapsed(delay_runonce) > INIT_DELAY) {
    runonce = false;
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(9);
    rgblight_sethsv_noeeprom(249/*350*/, 255, 255);
  }
}

void matrix_init_user(void) {
  rgblight_wait();
};

void matrix_scan_user(void) {
  rgblight_init_real();
  if (up) {
    register_code(KC_UP);
    unregister_code(KC_UP);
    _delay_ms(repeat);
  }
  if (dn) {
    register_code(KC_DOWN);
    unregister_code(KC_DOWN);
    _delay_ms(repeat);
  }
}

void led_set_user(uint8_t usb_led) {
  static uint8_t old_usb_led = 0;
  if ((usb_led & (1 << USB_LED_CAPS_LOCK)) && !(old_usb_led & (1 << USB_LED_CAPS_LOCK))) {
    switch (layer) {
      case _RAISE:
        rgblight_mode_noeeprom(20);
        rgblight_sethsv_noeeprom(0, 0, 255);
        break;
      case _LOWER:
        rgblight_mode_noeeprom(19);
        rgblight_sethsv_noeeprom(0, 0, 255);
        break;
      default:
        rgblight_mode_noeeprom(9);
        rgblight_sethsv_noeeprom(0, 0, 255);
        break;
      }
    caps = true;
  } else if (!(usb_led & (1 << USB_LED_CAPS_LOCK)) && (old_usb_led & (1 << USB_LED_CAPS_LOCK))) {
    switch (layer) {
      case _RAISE:
        rgblight_mode_noeeprom(20);
        rgblight_sethsv_noeeprom(100/*140*/, 255, 255);
        break;
      case _LOWER:
        rgblight_mode_noeeprom(19);
        rgblight_sethsv_noeeprom(121/*170*/, 255, 255);
        break;
      case _QWERTY:
        rgblight_mode_noeeprom(9);
        rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
        break;
      case _GAME:
        rgblight_mode_noeeprom(6);
        rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
        break;
      case _NUMPAD:
        rgblight_mode_noeeprom(24);
        rgblight_sethsv_noeeprom(0, 255, 255);
        break;
    }
    caps = false;
  }
  old_usb_led = usb_led;
}

uint32_t layer_state_set_user(uint32_t state) {
  layer = biton32(state);
    switch (layer) {
      case _RAISE:
        if (caps) {
          rgblight_mode_noeeprom(20);
          rgblight_sethsv_noeeprom(0, 0, 255);
        } else {
          rgblight_mode_noeeprom(20);
          rgblight_sethsv_noeeprom(100/*140*/, 255, 255);
        }
        break;
      case _LOWER:
        if (caps) {
          rgblight_mode_noeeprom(19);
          rgblight_sethsv_noeeprom(0, 0, 255);
        } else {
          rgblight_mode_noeeprom(19);
          rgblight_sethsv_noeeprom(121/*170*/, 255, 255);
        }
        break;
      case _QWERTY:
        if (caps) {
          rgblight_mode_noeeprom(9);
          rgblight_sethsv_noeeprom(0, 0, 255);
        } else {
          rgblight_mode_noeeprom(9);
          rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
        }
        break;
      case _GAME:
        if (caps) {
          rgblight_mode_noeeprom(6);
          rgblight_sethsv_noeeprom(0, 0, 255);
        } else {
          rgblight_mode_noeeprom(6);
          rgblight_sethsv_noeeprom(245/*350*/, 255, 255);
        }
        break;
      case _NUMPAD:
        if (caps) {
          rgblight_mode_noeeprom(24);
          rgblight_sethsv_noeeprom(0, 0, 255);
        } else {
          rgblight_mode_noeeprom(24);
          rgblight_sethsv_noeeprom(0, 255, 255);
        }
        break;
    }
  return state;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------ TAP DANCE STUFF ------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  TRIPLE_TAP,
  QUAD_TAP,
  QUIN_TAP,
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->pressed) {
      return SINGLE_HOLD;
    } else { 
      return SINGLE_TAP;
    }
  } else if (state->count == 2) {
    if (state->pressed) {
      return DOUBLE_HOLD;
    } else { 
      return DOUBLE_TAP;
    }
  } else if (state->count == 3) {
    return TRIPLE_TAP;
  } else if (state->count == 4) {
    return QUAD_TAP;
  } else if (state->count == 5) {
    return QUIN_TAP;
  } else {
    return 8;
  }
}

static tap tap_state = {
  .is_press_action = true,
  .state = 0
};

void hyp_f (qk_tap_dance_state_t *state, void *user_data) {
  tap_state.state = cur_dance(state);
  switch (tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_PSCR);
      unregister_code(KC_PSCR);
      break;
    case SINGLE_HOLD: 
      register_code(KC_LSHIFT);
      register_code(KC_LCTRL);
      register_code(KC_LALT);
      break;
    case DOUBLE_TAP:
      register_code(KC_LSHIFT);
      register_code(KC_LCTRL);
      register_code(KC_ESC);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LCTRL);
      unregister_code(KC_ESC);
      break;
    case DOUBLE_HOLD:
      register_code(KC_LSHIFT);
      register_code(KC_LCTRL);
      register_code(KC_LALT);
      register_code(KC_LGUI);
      break;
    case TRIPLE_TAP:
      register_code(KC_SLEP);
      unregister_code(KC_SLEP);
      break;
    case QUAD_TAP:
      register_code(KC_PWR);
      unregister_code(KC_PWR);
      break;
    case QUIN_TAP:
      reset_keyboard();
      break;
  }
}

void hyp_r (qk_tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case SINGLE_HOLD:
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LCTRL);
      unregister_code(KC_LALT);
      break;
    case DOUBLE_HOLD:
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LCTRL);
      unregister_code(KC_LALT);
      unregister_code(KC_LGUI);
      break;
  }
}

void dsc_f (qk_tap_dance_state_t *state, void *user_data) {
  tap_state.state = cur_dance(state);
  switch (tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_LSHIFT);
      register_code(KC_LCTRL);
      register_code(KC_LALT);
      register_code(KC_LGUI);
      register_code(KC_M);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LCTRL);
      unregister_code(KC_LALT);
      unregister_code(KC_LGUI);
      unregister_code(KC_M);
      break;
    case SINGLE_HOLD: 
      register_code(KC_LSHIFT);
      break;
    case DOUBLE_TAP:
      register_code(KC_LSHIFT);
      register_code(KC_LCTRL);
      register_code(KC_LALT);
      register_code(KC_LGUI);
      register_code(KC_D);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LCTRL);
      unregister_code(KC_LALT);
      unregister_code(KC_LGUI);
      unregister_code(KC_D);
      break;
    case TRIPLE_TAP:
      if (layer_state_is(_QWERTY)) {
        layer_on(_GAME);
        break;
      } else if (layer_state_is(_GAME)) {
        layer_off(_GAME);
        break;
      }
      break;
  }
}

void dsc_r (qk_tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case SINGLE_HOLD: 
      unregister_code(KC_LSHIFT);
      break;
  }
}

void mdia_f (qk_tap_dance_state_t *state, void *user_data) {
  tap_state.state = cur_dance(state);
  switch (tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_MPLY);
      unregister_code(KC_MPLY);
      break;
    case DOUBLE_TAP:
      rgblight_toggle_noeeprom();
      break;
  }
}

void mdia_r (qk_tap_dance_state_t *state, void *user_data) {
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [HY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, hyp_f, hyp_r),
  [DC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dsc_f, dsc_r),
  [MDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mdia_f, mdia_r)
};
