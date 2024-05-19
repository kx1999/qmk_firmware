/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "kylex.h"
extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_5x6(
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_DEL ,
  //|-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
     KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_G   ,                        KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_SCLN,KC_BSPC,
  //|-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
     KC_CESC,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_D   ,                        KC_H   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_QUOT,
  //|-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
     KC_CSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                        KC_K   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
                     KC_LBRC,KC_RBRC,                                                        KC_MINS,KC_EQL,
  //                +-------+-------+                                                       +-------+------+
  //                            +-------+-------+                               +-------+-------+
                                 KC_LALT,KC_ENT ,                                KC_SPC ,KC_LGUI,
  //                            +-------+-------+                               +-------+-------+
                                 KC_NUMP,KC_LOWR,                                KC_RASE,KC_GAME,
  //                                |-------+-------|                       |-------+-------|
                                     KC_DSCR,KC_NAV ,                        KC_MPLY,KC_HYP
  //                                +-------+-------+                       +-------+-------+
  ),

  [_QWERTY] = LAYOUT_5x6(
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_DEL ,
  //|-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
     KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                        KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSPC,
  //|-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
     KC_CESC,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                        KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
  //|-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
     KC_CSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                        KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
                     KC_LBRC,KC_RBRC,                                                        KC_MINS,KC_EQL,
  //                +-------+-------+                                                       +-------+------+
  //                            +-------+-------+                               +-------+-------+
                                 KC_LALT,KC_ENT ,                                KC_SPC ,KC_LGUI,
  //                            +-------+-------+                               +-------+-------+
                                 KC_NUMP,KC_LOWR,                                KC_RASE,KC_GAME,
  //                                |-------+-------|                       |-------+-------|
                                     KC_DSCR,KC_NAV ,                        KC_MPLY,KC_HYP
  //                                +-------+-------+                       +-------+-------+
  ),

  [_DVORAK] = LAYOUT_5x6(
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_DEL ,
  //|-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
     KC_TAB ,KC_QUOT,KC_COMM,KC_DOT, KC_P   ,KC_Y   ,                        KC_F   ,KC_G   ,KC_C   ,KC_R   ,KC_L   ,KC_BSPC,
  //|-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
     KC_CESC,KC_A   ,KC_O   ,KC_E   ,KC_U   ,KC_I   ,                        KC_D   ,KC_H   ,KC_T   ,KC_N   ,KC_S   ,KC_SLSH,
  //|-------+-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------+-------|
     KC_CSFT,KC_SCLN,KC_Q   ,KC_J   ,KC_K   ,KC_X   ,                        KC_B   ,KC_M   ,KC_W   ,KC_V   ,KC_Z   ,KC_BSLS,
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
                     KC_LBRC,KC_RBRC,                                                        KC_MINS,KC_EQL,
  //                +-------+-------+                                                       +-------+------+
  //                            +-------+-------+                               +-------+-------+
                                 KC_LALT,KC_ENT ,                                KC_SPC ,KC_LGUI,
  //                            +-------+-------+                               +-------+-------+
                                 KC_NUMP,KC_LOWR,                                KC_RASE,KC_GAME,
  //                                |-------+-------|                       |-------+-------|
                                     KC_DSCR,KC_NAV ,                        KC_MPLY,KC_HYP
  //                                +-------+-------+                       +-------+-------+
  ),

  [_GAMETEST] = LAYOUT_5x6(
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_DEL ,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     KC_TAB ,KC_T   ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,                        KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSPC,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     KC_CESC,KC_G   ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,                        KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     KC_CSFT,KC_B   ,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,                        KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
                     KC_LBRC,KC_RBRC,                                                        KC_MINS,KC_EQL,
  //                +-------+-------+                                                       +-------+------+
  //                            +-------+-------+                               +-------+-------+
                                 KC_LALT,KC_ENT ,                                KC_SPC ,KC_LGUI,
  //                            +-------+-------+                               +-------+-------+
                                 KC_NUMP,KC_LOWR,                                KC_RASE,KC_GAME,
  //                                |-------+-------|                       |-------+-------|
                                     KC_DSCR,KC_NAV ,                        KC_MPLY,KC_HYP
  //                                +-------+-------+                       +-------+-------+
  ),

  [_GAME] = LAYOUT_5x6(
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
     KC_ESC ,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     KC_LCTL,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     KC_LSFT,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
                     _______,_______,                                                        _______,_______,
  //                +-------+-------+                                                       +-------+-------+
  //                            +-------+-------+                               +-------+-------+
                                 _______,KC_SPC ,                                _______,_______,
  //                            +-------+-------+                               +-------+-------+
                                 _______,KC_ENT ,                                _______,_______,
  //                                |-------+-------|                       |-------+-------|
                                     _______,KC_GRV ,                        _______,_______
  //                                +-------+-------+                       +-------+-------+
  ),

  [_LOWER] = LAYOUT_5x6(
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                         KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,KC_HOME,KC_SUP ,KC_BTAB,KC_FTAB,KC_PGUP,                        _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,KC_END ,KC_SDN ,KC_BACK,KC_FRWD,KC_PGDN,                        _______,_______,_______,_______,_______,_______,
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
                     _______,_______,                                                        _______,_______,
  //                +-------+-------+                                                       +-------+-------+
  //                            +-------+-------+                               +-------+-------+
                                 _______,_______,                                _______,_______,
  //                            +-------+-------+                               +-------+-------+
                                 _______,_______,                                _______,_______,
  //                                |-------+-------|                       |-------+-------|
                                     _______,_______,                        _______,_______
  //                                +-------+-------+                       +-------+-------+
  ),

  [_RAISE] = LAYOUT_5x6(
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
     KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                        KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,_______,_______,KC_UP  ,_______,_______,                        _______,KC_MPRV,KC_UP  ,KC_MNXT,KC_VOLU,KC_SUP ,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,                        KC_PGUP,KC_LEFT,KC_DOWN,KC_RGHT,KC_VOLD,KC_SDN ,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,_______,_______,_______,_______,_______,                        KC_PGDN,KC_HOME,KC_END ,KC_INS ,KC_LCA0,KC_LCA9,
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
                     _______,_______,                                                        KC_BTAB,KC_FTAB,
  //                +-------+-------+                                                       +-------+-------+
  //                            +-------+-------+                               +-------+-------+
                                 _______,_______,                                _______,_______,
  //                            +-------+-------+                               +-------+-------+
                                 _______,_______,                                _______,_______,
  //                                |-------+-------|                       |-------+-------|
                                     _______,_______,                        _______,_______
  //                                +-------+-------+                       +-------+-------+

  ),

  [_ADJUST] = LAYOUT_5x6(
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
     XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     XXXXXXX,XXXXXXX,KC_CTXT,KC_WTXT,AS_TOGG,XXXXXXX,                        XXXXXXX,KC_QWER,KC_COLE,KC_DVOR,XXXXXXX,XXXXXXX,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     XXXXXXX,KC_RTOG,KC_RHUI,KC_RSAI,KC_RVAI,KC_RSPI,                        XXXXXXX,KC_MAKE,XXXXXXX,XXXXXXX,QK_BOOT,XXXXXXX,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     KC_LSFT,KC_RMOD,KC_RHUD,KC_RSAD,KC_RVAD,KC_RSPD,                        XXXXXXX,KC_VRSN,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
                     XXXXXXX,XXXXXXX,                                                        XXXXXXX,XXXXXXX,
  //                +-------+-------+                                                       +-------+-------+
  //                            +-------+-------+                               +-------+-------+
                                 XXXXXXX,XXXXXXX,                                XXXXXXX,XXXXXXX,
  //                            +-------+-------+                               +-------+-------+
                                 XXXXXXX,XXXXXXX,                                XXXXXXX,XXXXXXX,
  //                                |-------+-------|                       |-------+-------|
                                     XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX
  //                                +-------+-------+                       +-------+-------+

  ),

  [_NAV] = LAYOUT_5x6(
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,_______,_______,KC_UP  ,_______,_______,                        _______,_______, KC_UP ,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,                        _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,_______,KC_PRED,KC_NEXD,_______,_______,                        _______,_______,KC_PRED,KC_NEXD,_______,_______,
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
                     KC_CLOD,KC_NEWD,                                                        KC_CLOD,KC_NEWD,
  //                +-------+-------+                                                       +-------+-------+
  //                            +-------+-------+                               +-------+-------+
                                 _______,_______,                                _______,_______,
  //                            +-------+-------+                               +-------+-------+
                                 _______,_______,                                _______,_______,
  //                                |-------+-------|                       |-------+-------|
                                     _______,_______,                        _______,_______
  //                                +-------+-------+                       +-------+-------+

  ),

  [_NUMPAD] = LAYOUT_5x6(
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
     _______,_______,KC_NUM ,KC_PSLS,KC_PAST,KC_PMNS,                        _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,_______, KC_P7 , KC_P8 , KC_P9 ,KC_PPLS,                        _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,KC_DEL , KC_P4 , KC_P5 , KC_P6 ,_______,                        _______,_______,_______,_______,_______,_______,
  //|-------+-------+-------+-------+-------+-------|						|-------+-------+-------+-------+-------+-------|
     _______,KC_BSPC, KC_P1 , KC_P2 , KC_P3 ,KC_PENT,                        _______,_______,_______,_______,_______,_______,
  //+-------+-------+-------+-------+-------+-------+                       +-------+-------+-------+-------+-------+-------+
                     KC_P0  ,KC_PDOT,                                                        _______,_______,
  //                +-------+-------+                                                       +-------+-------+
  //                            +-------+-------+                               +-------+-------+
                                 _______,_______,                                _______,_______,
  //                            +-------+-------+                               +-------+-------+
                                 _______,_______,                                _______,_______,
  //                                |-------+-------|                       |-------+-------|
                                     _______,_______,                        _______,_______
  //                                +-------+-------+                       +-------+-------+
  ),

};

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
  {
  // Key Matrix to LED Index
    { 5  ,    4  ,    3  ,    2  ,    1  ,    0      },
    { 6  ,    7  ,    8  ,    9  ,    10 ,    11     },
    { 17 ,    16 ,    15 ,    14 ,    13 ,    12     },
    { 18 ,    19 ,    20 ,    21 ,    22 ,    23     },
    { NO_LED, NO_LED, 27 ,    26 ,    25 ,    24     },
    { NO_LED, NO_LED, 29 ,    30 ,    28 ,    31     },

    { 32 ,    33 ,    34 ,    35 ,    36 ,    37     },
    { 43 ,    42 ,    41 ,    40 ,    39 ,    38     },
    { 44 ,    45 ,    46 ,    47 ,    48 ,    49     },
    { 55 ,    54 ,    53 ,    52 ,    51 ,    50     },
    { 56 ,    57 ,    58 ,    59 ,    NO_LED, NO_LED },
    { 63 ,    60 ,    62 ,    61 ,    NO_LED, NO_LED }
  }, {

    //{ L00,   L01,   L02, L03, L04, L05 }
    //{ L10,   L11,   L12, L13, L14, L15 }
    //{ L20,   L21,   L22, L23, L24, L25 }
    //{ L30,   L31,   L32, L33, L34, L35 }
    //{ KC_NO, KC_NO, L42, L43, L44, L45 }
    //{ KC_NO, KC_NO, L52, L53, L54, L55 }
    //
    //{ R00, R01, R02, R03, R04,   R05   }
    //{ R10, R11, R12, R13, R14,   R15   }
    //{ R20, R21, R22, R23, R24,   R25   }
    //{ R30, R31, R32, R33, R34,   R35   }
    //{ R40, R41, R42, R43, KC_NO, KC_NO }
    //{ R50, R51, R52, R53, KC_NO, KC_NO }

    //L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05
    //L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15
    //L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25
    //L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35
    //          L42, L43,                                              R42, R43,
    //                    L44, L45,                          R40, R41,
    //                              L54, L55,      R50, R51,
    //                              L52, L53,      R52, R53

    // LED Index to Physical Position
    {  86 ,  0  }, { 69  ,  0  }, { 52  ,  0  }, { 34  ,  0  }, { 17  ,  0  }, { 0   ,  0  },
    {  0  ,  9  }, { 17  ,  9  }, { 34  ,  9  }, { 52  ,  9  }, { 69  ,  9  }, { 86  ,  9  },
    {  86 ,  18 }, { 69  ,  18 }, { 52  ,  18 }, { 34  ,  18 }, { 17  ,  18 }, { 0   ,  18 },
    {  0  ,  27 }, { 17  ,  27 }, { 34  ,  27 }, { 52  ,  27 }, { 69  ,  27 }, { 86  ,  27 },
                                  { 86  ,  46 }, { 69  ,  46 }, { 52  ,  37 }, { 34  ,  37 },
                                  { 86  ,  55 }, { 86  ,  64 }, { 103 ,  64 }, { 103 ,  55 },

    { 138 ,  0  }, { 155 ,  0  }, { 172 ,  0  }, { 190 ,  0  }, { 207 ,  0  }, { 224 ,  0  },
    { 224 ,  9  }, { 207 ,  9  }, { 190 ,  9  }, { 172 ,  9  }, { 155 ,  9  }, { 138 ,  9  },
    { 138 ,  18 }, { 155 ,  18 }, { 172 ,  18 }, { 190 ,  18 }, { 207 ,  18 }, { 224 ,  18 },
    { 224 ,  27 }, { 207 ,  27 }, { 190 ,  27 }, { 172 ,  27 }, { 155 ,  27 }, { 138 ,  27 },
    { 138 ,  37 }, { 155 ,  37 }, { 172 ,  46 }, { 190 ,  46 },
    { 138 ,  55 }, { 138 ,  64 }, { 120 ,  64 }, { 120 ,  55 }
  }, {
    // LED Index to Flag
    4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,
          1, 1, 1, 1,
          1, 1, 1, 1,

    4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,
          1, 1, 1, 1,
          1, 1, 1, 1,
  }
};
#endif
