/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H
#include "kylex.h"
extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6_kc(
     GRV , 1  , 2  , 3  , 4  , 5  ,                         6  , 7  , 8  , 9  , 0  ,DEL ,
     TAB , Q  , W  , E  , R  , T  ,                         Y  , U  , I  , O  , P  ,BSPC,
     CESC, A  , S  , D  , F  , G  ,                         H  , J  , K  , L  ,SCLN,QUOT,
     CSFT, Z  , X  , C  , V  , B  ,                         N  , M  ,COMM,DOT ,SLSH,BSLS,
               LBRC,RBRC,                                                 MINS,EQL ,
                         LALT,ENT ,                         SPC ,LGUI,
                            CSFT,LOWR,                  RASE,RSFT,
                            GRV ,DSCR,                  HYP ,MDIA
  ),

  [_GAME] = LAYOUT_5x6_kc(
     ESC , 1  , 2  , 3  , 4  , 5  ,                         6  , 7  , 8  , 9  , 0  ,DEL ,
     TAB , Q  , W  , E  , R  , T  ,                         Y  , U  , I  , O  , P  ,BSPC,
     ESC , A  , S  , D  , F  , G  ,                         H  , J  , K  , L  ,SCLN,QUOT,
     LSFT, Z  , X  , C  , V  , B  ,                         N  , M  ,COMM,DOT ,SLSH,BSLS,
               LBRC,RBRC,                                                 MINS,EQL ,
                         LALT,ENT ,                         SPC ,LGUI,
                            LSFT,SPC ,                  RASE,RSFT,
                            GRV ,DSCR,                  HYP ,MDIA
  ),

  [_LOWER] = LAYOUT_5x6_kc(

     TILD,EXLM, AT ,HASH,DLR ,PERC,                        CIRC,AMPR,ASTR,LPRN,RPRN,    ,
         ,NUMP,    ,ASTG,    ,    ,                            ,RMOD,RHUI,RSAI,RVAI,    ,
         ,HOME,SUP ,BTAB,FTAB,LPRN,                        RPRN,RTOG,RHUD,RSAD,RVAD,    ,
         ,END ,SDN ,BACK,FRWD,    ,                            ,    ,    ,    ,    ,    ,
                   ,    ,                                                     ,    ,
                             ,    ,                            ,    ,
                                ,    ,                      ,    ,
                                ,    ,                      ,    

  ),

  [_RAISE] = LAYOUT_5x6_kc(

     F12 , F1 , F2 , F3 , F4 , F5 ,                         F6 , F7 , F8 , F9 ,F10 ,F11 ,
         ,WTXT,CTXT, UP ,    ,    ,                            ,MPRV, UP ,MNXT,VOLU,    ,
         ,    ,LEFT,DOWN,RGHT,    ,                            ,LEFT,DOWN,RGHT,VOLD,PGUP,
         ,VRSN,    ,    ,    ,    ,                            ,CALC,MYCM,INS ,    ,PGDN,
                   ,    ,                                                     ,    ,
                             ,    ,                            ,    ,
                                ,    ,                      ,    ,
                                ,    ,                      ,    

  ),
};
