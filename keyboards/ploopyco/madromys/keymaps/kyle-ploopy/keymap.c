/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "pointing_device.h"

static bool mouse_moved = false;

// implementation by evan-goode
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    mouse_moved = true;

    static int16_t scroll_buffer_h = 0;
    static int16_t scroll_buffer_v = 0;
    static uint32_t last_scroll_time = 0;
    scroll_buffer_h += mouse_report.h;
    scroll_buffer_v += mouse_report.v;
    mouse_report.h = 0;
    mouse_report.v = 0;
    if (timer_elapsed32(last_scroll_time) < 16) {
        return mouse_report;
    }
    last_scroll_time = timer_read32();
    mouse_report.h = scroll_buffer_h;
    mouse_report.v = scroll_buffer_v;
    scroll_buffer_h = 0;
    scroll_buffer_v = 0;
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            if (record->event.pressed) {
                mouse_moved = false;
            } else {
                if (!mouse_moved) {
                    register_code16(KC_BTN3);
                    unregister_code16(KC_BTN3);
                }
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( KC_BTN4, KC_BTN5, DRAG_SCROLL, KC_BTN2, KC_BTN1, DPI_CONFIG )
};
