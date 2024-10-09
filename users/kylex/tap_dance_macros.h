#pragma once
#include "kylex.h"

#ifdef TAP_DANCE_ENABLE
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  TRIPLE_TAP,
};
enum {
  HY = 0,
  DC,
  GAME,
};
#endif

typedef struct {
  bool is_press_action;
  int state;
} tap;
