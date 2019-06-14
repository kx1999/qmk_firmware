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

enum corne_layers {
  _MISC,
};

#define KC_MISC MO(_MISC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      TAB  ,  Q   ,  W   ,  E   ,  R   ,  T   ,                    Y  ,  U   ,  I   ,  O   ,  P   , BSPC ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CESC ,  A   ,  S   ,  D   ,  F   ,  G   ,                    H  ,  U   ,  K   ,  L   , SCLN , QUOT ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CSFT ,  Z   ,  X   ,  C   ,  V   ,  B   ,                    N  ,  M   , COMM ,  DOT , SLSH , MISC ,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  LALT , LOWR , SPC  ,     ENT ,  RASE, LGUI  \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      TAB  ,  1   ,  2   ,  3   ,  4   ,  5   ,                   6   ,  7   ,  8   ,  9   ,  0   , BSPC ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CESC , HOME , SUP  , BTAB , FTAB , LCBR ,                  RCBR ,      ,      ,      ,      ,      ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CSFT , END  , SDN  , BACK , FRWD , LBRC ,                  RBRC ,      ,      ,      ,      ,      ,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                       ,      ,      ,         ,      ,       \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      TAB  , WTXT , CTXT ,  UP  ,      , MINS ,                  PLUS , MPRV ,  UP  , MNXT , VOLU ,      ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CESC ,      , LEFT , DOWN , RGHT , UNDS ,                  EQL  , LEFT , DOWN , RGHT , VOLD ,      ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      CSFT , MDIA , DSCR ,      ,      , PIPE ,                  BSLS , CALC , MYCM , INS  ,      , HYP  ,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                       ,      ,      ,         ,      , RSET  \
                              //`--------------------'  `--------------------'
  ),

  [_MISC] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
           ,      ,      ,      ,      ,      ,                   F1  ,  F2  ,  F3  ,  F4  ,  F5  ,  F6  ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
           ,      ,      ,      ,      ,      ,                   F7  ,  F8  ,  F9  ,  F10 ,  F11 ,  F12 ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
           ,      ,      ,      ,      ,      ,                       ,      ,      ,      ,      ,      ,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                       ,      ,      ,         ,      ,       \
                              //`--------------------'  `--------------------'
  )
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
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_keymap(void) {
   iota_gfx_task();
}

void matrix_render_keymap(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_keymap(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_keymap(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
