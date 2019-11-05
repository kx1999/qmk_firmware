#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif
#include "kylex.h"
extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;
/*
    ________________________________________________________
    |                                                      |
    |              Custom Keycode Information              |
    |______________________________________________________|
    |                                                      |
    |       CESC : Tap = Escape, Hold = LControl           |
    |       CSFT : Tap = Caps Lock, Hold = LShift          |
    |       DSCR : Tap x1 = Hyper(m)                       |
    |              Tap x2 = Hyper(d)                       |
    |       HYP  : Tap x1 = Print screen                   |
    |              Tap x2 = Open Task Manager              |
    |              Tap x3 = Sleep button                   |
    |              Tap x4 = Power button                   |
    |              Hold 1x = Meh Modifier                  |
    |              Hold 2x = Hyper Modifier                |
    |       MDIA : Tap 1x = Play/pause media               |
    |              Tap 2x = Toggle _GAME layer             |
    |              Tap 3x = Toggle RGB underglow           |
    |                       and audio                      |
    |       NUMP : Toggle _NUMPAD layer                    |
    |       SHRG : Unicode shrug                           |
    |       SUP  : Hold to spam Up Arrow                   |
    |       SDN  : Hold to spam Down Arrow                 |
    |       FTAB : Ctrl + Tab                              |
    |       BTAB : Ctrl + Shift + Tab                      |
    |       WTXT : Toggle Wide text mode                   |
    |               eg. w i d e  t e x t                   |
    |       CTXT : Toggle Caps text mode                   |
    |               eg. cApS tExT                          |
    |             (Note: WTXT and CTXT can both be         |
    |               active at the same time.               |
    |               eg.  l A r G e   t E x T )             |
    |       VRSN : Print current firmware information      |
    |       MAKE : make command for current keyboard       |
    |       RSET : Put keyboard into bootloader            |
    |                                                      |
    |______________________________________________________|
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      TAB  ,  Q   ,  W   ,  E   ,  R   ,  T   ,                    Y  ,  U   ,  I   ,  O   ,  P   , BSPC ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CESC ,  A   ,  S   ,  D   ,  F   ,  G   ,                    H  ,  J   ,  K   ,  L   , SCLN , QUOT ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CSFT ,  Z   ,  X   ,  C   ,  V   ,  B   ,                    N  ,  M   , COMM ,  DOT , SLSH , HYP  ,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LALT , LOWR , ENT  ,     SPC ,  RASE, LGUI  \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      TAB  ,  1   ,  2   ,  3   ,  4   ,  5   ,                   6   ,  7   ,  8   ,  9   ,  0   , BSPC ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CESC , HOME , SUP  , BTAB , FTAB , LCBR ,                  RCBR ,  F1  ,  F2  ,  F3  ,  F4  ,  F5  ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CSFT , END  , SDN  , BACK , FRWD , LBRC ,                  RBRC ,  F6  ,  F7  ,  F8  ,  F9  ,  F10 ,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   F11 ,      ,      ,         ,      ,  F12  \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      GRV  , WTXT , CTXT ,  UP  ,      , MINS ,                  PLUS , MPRV ,  UP  , MNXT , VOLU , DEL  ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CESC ,      , LEFT , DOWN , RGHT , UNDS ,                  EQL  , LEFT , DOWN , RGHT , VOLD ,      ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CSFT , DSCR , MDIA ,      , MAKE , PIPE ,                  BSLS , CALC , MYCM , INS  , MISC ,      ,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                       ,      ,      ,         ,      , RSET  \
                              //`--------------------'  `--------------------'
  ),

  [_MISC] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
           ,      ,      ,      ,      ,      ,                       , RMOD , RHUI , RSAI , RVAI , RSPI ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
           ,      ,      ,      ,      ,      ,                       , RTOG , RHUD , RSAD , RVAD , RSPD ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
           ,      ,      ,      ,      ,      ,                       ,      ,      ,      , MISC , ASTG ,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                       ,      ,      ,         ,      ,       \
                              //`--------------------'  `--------------------'
  ),
  
};

int RGB_current_mode;

void matrix_init_keymap(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
      iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
//void set_keylog(uint16_t keycode, keyrecord_t *record);
//const char *read_keylog(void);
//const char *read_keylogs(void);
//
//const char *read_mode_icon(bool swap);
//const char *read_host_led_state(void);
//void set_timelog(void);
//const char *read_timelog(void);

void matrix_scan_keymap(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    // matrix_write_ln(matrix, read_keylog());
    // matrix_write_ln(matrix, read_keylogs());
    // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    // matrix_write_ln(matrix, read_host_led_state());
    // matrix_write_ln(matrix, read_timelog());
    // matrix_write(matrix,read_logo());
  } else {
    // matrix_write_ln(matrix, read_layer_state());
    //matrix_write_ln(matrix, read_host_led_state());
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef SSD1306OLED
      //set_keylog(keycode, record);
    #endif
    //set_timelog();
  }
  return true;
}
