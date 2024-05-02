/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "symbols.h"

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

// Left-hand home row (number layer) mods
#define HOME_1 LCTL_T(KC_1)
#define HOME_2 LALT_T(KC_2)
#define HOME_3 LGUI_T(KC_3)
#define HOME_4 LSFT_T(KC_4)

// Right-hand home row mods
#define HOME_7 RSFT_T(KC_7)
#define HOME_8 RGUI_T(KC_8)
#define HOME_9 RALT_T(KC_9)
#define HOME_0 RCTL_T(KC_0)

// Left-hand home row (number layer) mods
#define HM_GRV LCTL_T(KC_GRV)
#define HM_MINS LALT_T(KC_MINS)
#define HM_EQL LGUI_T(KC_EQL)
#define HM_BSLS LSFT_T(KC_BSLS)

// Right-hand home row mods
#define HM_LBRC RSFT_T(KC_LBRC)
#define HM_RBRC RGUI_T(KC_RBRC)

// Right-hand func layer home row mods
#define RHM_DOWN RSFT_T(KC_DOWN)
#define RHM_UP RGUI_T(KC_UP)
#define RHM_RGHT RALT_T(KC_RIGHT)

// Left-hand func layer home row mods
#define HM_DEL RCTL_T(KC_DEL)
#define LHM_LEFT RALT_T(KC_LEFT)
#define LHM_DOWN RGUI_T(KC_DOWN)
#define LHM_UP RSFT_T(KC_UP)

// Modified keys
#define C_PGDN C(KC_PGDN)
#define C_PGUP C(KC_PGUP)
#define SC_PGDN S(C(KC_PGDN))
#define SC_PGUP S(C(KC_PGUP))

// Tap for SPC hold for Layer Toggle
#define SPC_LT(layer) LT(layer, KC_SPC)
// Tap for Enter hold for Layer Toggle
#define ENT_LT(layer) LT(layer, KC_ENT)
// Tap for Esc hold for Layer Toggle
#define ESC_LT(layer) LT(layer, KC_ESC)
// Tap for Backspace hold for Layer Toggle
#define BS_LT(layer) LT(layer, KC_BSPC)
// Tap for Tab hold for Layer Toggle
#define TB_LT(layer) LT(layer, KC_TAB)
// Tap for Delete hold for Layer Toggle
#define DL_LT(layer) LT(layer, KC_DEL)
// Tap for Quote hold for Layer Toggle
#define QT_LT(layer) LT(layer, KC_QUOT)

// ç
#define CEDILLA RAG(KC_COMM)

// LAYER ALIASES
#define L_BASE 0
#define L_NUM 1
#define L_SYM 2
#define L_FUNC 3
#define L_GAME 4
#define L_GAME_NUM 5
#define L_TRANS 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, HOME_A, HOME_S, HOME_D, HOME_F, KC_G, KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_QUOT, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_BSPC, KC_ESC, SPC_LT(L_FUNC), ENT_LT(L_SYM), TB_LT(L_NUM), KC_DEL
        //`--------------------------'  `--------------------------'
        ),

    [L_NUM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, HOME_1, HOME_2, HOME_3, HOME_4, KC_5, KC_6, HOME_7, HOME_8, HOME_9, HOME_0, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MNXT, KC_CAPS, CEDILLA, XXXXXXX, XXXXXXX, XXXXXXX,

        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_SPC, KC_ENT, XXXXXXX, XXXXXXX
        //`--------------------------'  `--------------------------'
        ),

    [L_SYM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, HM_GRV, HM_MINS, HM_EQL, HM_BSLS, RGB_MOD, XXXXXXX, HM_LBRC, HM_RBRC, KC_RALT, KC_RCTL, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        EE_CLR, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, KC_ENT, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_SPC, KC_ENT, XXXXXXX, XXXXXXX
        //`--------------------------'  `--------------------------'
        ),

    [L_FUNC] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, HM_DEL, LHM_LEFT, LHM_DOWN, LHM_UP, KC_RIGHT, KC_LEFT, RHM_DOWN, RHM_UP, RHM_RGHT, KC_RCTL, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, SC_PGUP, C_PGUP, C_PGDN, SC_PGDN, KC_PSCR, KC_PGUP, KC_END, KC_HOME, KC_PGDN, KC_SLSH, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_BSPC, RGB_MOD, KC_PGUP, KC_PGDN, KC_TAB, RGB_TOG
        //`--------------------------'  `--------------------------'
        ),

    [L_GAME] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RSFT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, MO(L_GAME_NUM), KC_SPC, KC_ENT, MO(L_GAME_NUM), KC_LALT
        //`--------------------------'  `--------------------------'

        ),

    [L_GAME_NUM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_GRV, KC_MINS, KC_EQL, KC_BSLS, KC_TILD, XXXXXXX, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_RSFT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        LCTL_T(KC_ESC), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, DF(L_BASE), KC_SPC, KC_ENT, DF(L_BASE), KC_RALT
        //`--------------------------'  `--------------------------'

        ),

    [L_TRANS] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        DF(L_GAME), XXXXXXX, KC_ENT, KC_SPC, XXXXXXX, DF(L_GAME)
        //`--------------------------'  `--------------------------'

        ),

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_0; // prevent flipping
    }

    return rotation;
}

#    define IDLE_FRAMES 1
#    define IDLE_SPEED 35 // below this wpm value your animation will idle

#    define TAP_FRAMES 5
#    define TAP_SPEED 50

#    define ANIM_FRAME_DURATION 100 // how long each frame lasts in ms
#    define ANIM_SIZE 512           // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;
uint8_t  current_tap_frame  = 0;

static const char PROGMEM lambda[ANIM_SIZE]          = LAMBDA;
static const char PROGMEM glitched_lambda[ANIM_SIZE] = GLITCHED_LAMBDA;
static const char PROGMEM inverted_lambda[ANIM_SIZE] = INVERTED_LAMBDA;

static void render_anim(void) {
    static const char *idle[IDLE_FRAMES] = {lambda};

    static const char *tap[TAP_FRAMES] = {glitched_lambda, glitched_lambda, lambda, glitched_lambda, lambda};

    void animation_phase(void) {
        if (get_current_wpm() <= IDLE_SPEED) {
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
        } else {
            current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
            oled_write_raw_P(tap[abs((TAP_FRAMES - 1) - current_tap_frame)], ANIM_SIZE);
        }
    }
    if (get_current_wpm() != 000) {
        oled_on();
        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

void oled_render_logo(void) {
    oled_write_raw_P(lambda, sizeof(lambda));
}

void oled_render_caps(void) {
    oled_write_raw_P(inverted_lambda, sizeof(inverted_lambda));
}

bool caps_word_active = 0;

void maybe_render_caps(void) {
    led_t led_state = host_keyboard_led_state();

    if (led_state.caps_lock || caps_word_active) {
        oled_render_caps();
    } else {
        oled_clear();
    }
}

void caps_word_set_user(bool active) {
    caps_word_active = active;
}

bool previous_caps_active = 0;

void oled_render_layer_state(void) {
    oled_set_cursor(0, 0);
    bool inverted = caps_word_active || host_keyboard_led_state().caps_lock;

    if (biton32(default_layer_state) == L_BASE && layer_state_is(L_BASE)) oled_write_P(PSTR("BASE"), inverted);
    if (layer_state_is(L_NUM)) oled_write_P(PSTR("NUM"), inverted);
    if (layer_state_is(L_SYM)) oled_write_P(PSTR("SYM"), inverted);
    if (layer_state_is(L_FUNC)) oled_write_P(PSTR("FUNC"), inverted);
    if (biton32(default_layer_state) == L_GAME && layer_state_is(L_BASE)) oled_write_P(PSTR("GAME"), inverted);
    if (layer_state_is(L_GAME_NUM)) oled_write_P(PSTR("GME_N"), inverted);
    if (layer_state_is(L_TRANS)) oled_write_P(PSTR("TRNS"), inverted);
}

bool oled_task_user(void) {
    bool caps_active = caps_word_active || host_keyboard_led_state().caps_lock;

    if (is_keyboard_master()) {
        if (caps_active != previous_caps_active) oled_clear();

        if ((previous_caps_active = caps_active)) {
            oled_render_caps();
            oled_render_layer_state();
        } else {
            render_anim();
            oled_render_layer_state();
        }
    } else {
        oled_render_logo();
    }

    return false;
}

#endif // OLED_ENABLE
