#include "tap_dance_macros.h"

int cur_dance (tap_dance_state_t *state) {
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
  } else {
    return 4;
  }
}

static tap tap_state = {
  .is_press_action = true,
  .state = 0
};

void hyp_f (tap_dance_state_t *state, void *user_data) {
  tap_state.state = cur_dance(state);
  switch (tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_PSCR);
      unregister_code(KC_PSCR);
      break;
    case SINGLE_HOLD:
      register_code(KC_LSFT);
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LGUI);
      break;
    case DOUBLE_TAP:
      register_code(KC_LSFT);
      register_code(KC_LCTL);
      register_code(KC_ESC);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
      unregister_code(KC_ESC);
      break;
    case TRIPLE_TAP:
      register_code(KC_SLEP);
      unregister_code(KC_SLEP);
      break;
  }
}

void hyp_r (tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case SINGLE_HOLD:
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
      unregister_code(KC_LALT);
      unregister_code(KC_LGUI);
      break;
  }
}

void dsc_f (tap_dance_state_t *state, void *user_data) {
  tap_state.state = cur_dance(state);
  switch (tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_LSFT);
      register_code(KC_LCTL);
      //register_code(KC_LALT);
      //register_code(KC_LGUI);
      register_code(KC_M);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
      //unregister_code(KC_LALT);
      //unregister_code(KC_LGUI);
      unregister_code(KC_M);
      break;
    case SINGLE_HOLD:
      register_code(KC_LSFT);
      //register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LGUI);
      break;
    case DOUBLE_TAP:
      register_code(KC_LSFT);
      register_code(KC_LCTL);
      //register_code(KC_LALT);
      //register_code(KC_LGUI);
      register_code(KC_D);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
      //unregister_code(KC_LALT);
      //unregister_code(KC_LGUI);
      unregister_code(KC_D);
      break;
  }
}

void dsc_r (tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case SINGLE_HOLD:
      unregister_code(KC_LSFT);
      //unregister_code(KC_LCTL);
      unregister_code(KC_LALT);
      unregister_code(KC_LGUI);
      break;
  }
}

void game_f (tap_dance_state_t *state, void *user_data) {
  tap_state.state = cur_dance(state);
  switch (tap_state.state) {
    case SINGLE_TAP:
      #ifdef GAME_MODE
        if (layer_state_is(_QWERTY)) {
          layer_on(_GAME);
          break;
        } else if (layer_state_is(_GAME)) {
          layer_off(_GAME);
          break;
        }
      #endif
      break;
    case DOUBLE_TAP:
      #ifdef RGBLIGHT_ENABLE
        rgblight_toggle_noeeprom();
        layer_state_set_user(layer_state);
        //led_set_user(usb_led);
      #endif
      #ifdef RGB_MATRIX_ENABLE
        rgb_matrix_toggle();
        layer_state_set_user(layer_state);
      #endif
      break;
  }
}

void game_r (tap_dance_state_t *state, void *user_data) {
}

tap_dance_action_t tap_dance_actions[] = {
  [HY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, hyp_f, hyp_r),
  [DC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dsc_f, dsc_r),
  [GAME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, game_f, game_r)
};
