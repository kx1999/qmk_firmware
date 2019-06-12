#include QMK_KEYBOARD_H
#include "kylex.h"

extern keymap_config_t keymap_config;

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
                             RALT,LOWR,ENT ,         SPC ,RASE,LGUI
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
               ,NUMP,SHRG,    ,    ,LCBR,               RCBR,    ,    ,    ,    ,    ,
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
               ,WTXT,TTXT, UP ,    ,MINS,               PLUS,MPRV, UP ,MNXT,VOLU,    ,
    //    |----+----+----+----+----+----|              |----+----+----+----+----+----|
               ,    ,LEFT,DOWN,RGHT,UNDS,               EQL ,LEFT,DOWN,RGHT,VOLD,PGUP,
    //    |----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
               ,VRSN,    ,    ,    ,PIPE,    ,     MAKE,BSLS,CALC,MYCM,    ,INS ,PGDN,
    //    `----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                                 ,    ,    ,             ,    ,RSET
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
