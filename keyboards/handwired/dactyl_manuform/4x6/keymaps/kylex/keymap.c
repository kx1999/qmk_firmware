/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H
#include "kylex.h"
extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_4x6_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                         Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     CESC, A  , S  , D  , F  , G  ,                         H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     CSFT, Z  , X  , C  , V  , B  ,                         N  , M  ,COMM,DOT ,SLSH,BSLS,
  //+----+----+----+----+----+----+                       +----+----+----+----+----+----+
               LBRC,RBRC,                                            MINS,EQL ,
  //          +----+----+                                           +----+----+
  //                    +----+----+                       +----+----+
                         LALT,ENT ,                        SPC ,LGUI,
  //                    +----+----+--+                 +--+----+----+
                            NAV ,LOWR,                  RASE,HYP ,
  //                       |----+----|                 |----+----|
                                 DSCR,                  MPLY
  //                            +----+                 +----+
  ),

  [_COLEMAK] = LAYOUT_4x6_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     TAB , Q  , W  , F  , P  , G  ,                         J  , L  , U  , Y  ,SCLN,BSPC,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     CESC, A  , R  , S  , T  , D  ,                         H  , N  , E  , I  , O  ,QUOT,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     CSFT, Z  , X  , C  , V  , B  ,                         K  , M  ,COMM,DOT ,SLSH,BSLS,
  //+----+----+----+----+----+----+                       +----+----+----+----+----+----+
               LBRC,RBRC,                                            MINS,EQL ,
  //          +----+----+                                           +----+----+
  //                    +----+----+                       +----+----+
                         LALT,ENT ,                        SPC ,LGUI,
  //                    +----+----+--+                 +--+----+----+
                            NAV ,LOWR,                  RASE,HYP ,
  //                       |----+----|                 |----+----|
                                 DSCR,                  MPLY
  //                            +----+                 +----+
  ),

  [_DVORAK] = LAYOUT_4x6_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     TAB ,QUOT,COMM,DOT , P  , Y  ,                         F  , G  , C  , R  , L  ,BSPC,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     CESC, A  , O  , E  , U  , I  ,                         D  , H  , T  , N  , S  ,SLSH,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     CSFT,SCLN, Q  , J  , K  , X  ,                         B  , M  , W  , V  , Z  ,BSLS,
  //+----+----+----+----+----+----+                       +----+----+----+----+----+----+
               LBRC,RBRC,                                            MINS,EQL ,
  //          +----+----+                                           +----+----+
  //                    +----+----+                       +----+----+
                         LALT,ENT ,                        SPC ,LGUI,
  //                    +----+----+--+                 +--+----+----+
                            NAV ,LOWR,                  RASE,HYP ,
  //                       |----+----|                 |----+----|
                                 DSCR,                  MPLY 
  //                            +----+                 +----+
  ),

  [_GAMETEST] = LAYOUT_4x6_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     TAB , T  , Q  , W  , E  , R  ,                         Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     CESC, G  , A  , S  , D  , F  ,                         H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     CSFT, B  , Z  , X  , C  , V  ,                         N  , M  ,COMM,DOT ,SLSH,BSLS,
  //+----+----+----+----+----+----+                       +----+----+----+----+----+----+
               LBRC,RBRC,                                            MINS,EQL ,
  //          +----+----+                                           +----+----+
  //                    +----+----+                       +----+----+
                         LALT,ENT ,                        SPC ,LGUI,
  //                    +----+----+--+                 +--+----+----+
                            NAV ,LOWR,                  RASE,HYP ,
  //                       |----+----|                 |----+----|
                                 DSCR,                  MPLY
  //                            +----+                 +----+
  ),

  [_GAME] = LAYOUT_4x6_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                            ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     LCTL,    ,    ,    ,    ,    ,                            ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,    ,                            ,    ,    ,    ,    ,    ,
  //+----+----+----+----+----+----+                       +----+----+----+----+----+----+
                   ,    ,                                                ,    ,
  //          +----+----+                                           +----+----+
  //                    +----+----+                       +----+----+
                             ,SPC ,                            ,    ,
  //                    +----+----+--+                 +--+----+----+
                                ,ENT ,                      ,    ,
  //                       |----+----|                 |----+----|
                                 GRV ,                      
  //                            +----+                 +----+
  ),

  [_LOWER] = LAYOUT_4x6_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     GRV , 1  , 2  , 3  , 4  , 5  ,                         6  , 7  , 8  , 9  , 0  ,DEL ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         ,HOME,SUP ,BTAB,FTAB,PGUP,                            ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         ,END ,SDN ,BACK,FRWD,PGDN,                            ,    ,    ,    ,    ,    ,
  //+----+----+----+----+----+----+                       +----+----+----+----+----+----+
                   ,    ,                                                ,    ,
  //          +----+----+                                           +----+----+
  //                    +----+----+                       +----+----+
                             ,    ,                            ,    ,
  //                    +----+----+--+                 +--+----+----+
                                ,    ,                      ,    ,
  //                       |----+----|                 |----+----|
                                     ,                      
  //                            +----+                 +----+

  ),

  [_RAISE] = LAYOUT_4x6_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     GRV , F9 , F10, F11, F12,    ,                            ,MPRV, UP ,MNXT,VOLU,DEL ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         , F5 , F6 , F7 , F8 ,    ,                            ,LEFT,DOWN,RGHT,VOLD,    ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         , F1 , F2 , F3 , F4 ,    ,                            ,CALC,MYCM,INS ,    ,    ,
  //+----+----+----+----+----+----+                       +----+----+----+----+----+----+
                   ,    ,                                                ,    ,
  //          +----+----+                                           +----+----+
  //                    +----+----+                       +----+----+
                             ,    ,                            ,    ,
  //                    +----+----+--+                 +--+----+----+
                                ,    ,                      ,    ,
  //                       |----+----|                 |----+----|
                                     ,                      
  //                            +----+                 +----+

  ),

  [_ADJUST] = LAYOUT_4x6_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     ____,____,WTXT,CTXT,ASTG,____,                        ____,QWER,COLE,DVOR,____,____,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     ____,____,____,____,____,____,                        ____,MAKE,____,____,RSET,____,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
     LSFT,____,____,____,____,____,                        ____,VRSN,____,____,____,____,
  //+----+----+----+----+----+----+                       +----+----+----+----+----+----+
               ____,____,                                            ____,____,
  //          +----+----+                                           +----+----+
  //                    +----+----+                       +----+----+
                         ____,____,                        ____,____,
  //                    +----+----+--+                 +--+----+----+
                            ____,____,                  ____,____,
  //                       |----+----|                 |----+----|
                                 ____,                  ____
  //                            +----+                 +----+

  ),

  [_NAV] = LAYOUT_4x6_kc(
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         ,    ,    , UP ,    ,    ,                            ,    , UP ,    ,    ,    ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         ,    ,LEFT,DOWN,RGHT,    ,                            ,LEFT,DOWN,RGHT,    ,    ,
  //|----+----+----+----+----+----|                       |----+----+----+----+----+----|
         ,    ,PRED,NEXD,    ,    ,                            ,    ,PRED,NEXD,    ,    ,
  //+----+----+----+----+----+----+                       +----+----+----+----+----+----+
               NEWD,CLOD,                                            NEWD,CLOD,
  //          +----+----+                                           +----+----+
  //                    +----+----+                       +----+----+
                             ,    ,                            ,    ,
  //                    +----+----+--+                 +--+----+----+
                                ,    ,                      ,    ,
  //                       |----+----|                 |----+----|
                                     ,                      
  //                            +----+                 +----+

  ),

};
