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
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Left-hand home row (number layer) mods
#define HOME_1 LGUI_T(KC_1)
#define HOME_2 LALT_T(KC_2)
#define HOME_3 LCTL_T(KC_3)
#define HOME_4 LSFT_T(KC_4)

// Right-hand home row mods
#define HOME_7 RSFT_T(KC_7)
#define HOME_8 RCTL_T(KC_8)
#define HOME_9 RALT_T(KC_9)
#define HOME_0 RGUI_T(KC_0)
//
// Left-hand home row (number layer) mods
#define HM_GRV  LGUI_T(KC_GRV)
#define HM_MINS LALT_T(KC_MINS)
#define HM_EQL  LCTL_T(KC_EQL)
#define HM_BSLS LSFT_T(KC_BSLS)

// Right-hand home row mods
#define HM_LBRC RSFT_T(KC_LBRC)
#define HM_RBRC RCTL_T(KC_RBRC)
//
// Right-hand home row mods
#define HM_LEFT RSFT_T(KC_LEFT)
#define HM_DOWN RCTL_T(KC_DOWN)
#define HM_UP RALT_T(KC_UP)
#define HM_RGHT RGUI_T(KC_RIGHT)

// Tap for Esc hold for Layer Toggle
#define ESC_LT(layer) LT(layer, KC_ESC)
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
      KC_CAPS,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  CAPSWRD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
ESC_LT(L_FUNC), HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN,KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      MO(L_TRANS),MO(L_SYM), KC_SPC,     KC_ENT,MO(L_NUM),MO(L_TRANS)
                                      //`--------------------------'  `--------------------------'

  ),

  [L_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_CAPS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, CAPSWRD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  HOME_1,  HOME_2,  HOME_3,  HOME_4,    KC_5,                         KC_6,  HOME_7,  HOME_8,  HOME_9,  HOME_0,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX,                      XXXXXXX, XXXXXXX, CEDILLA, XXXXXXX, XXXXXXX, KC_BSPC,

  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_SPC,     KC_ENT, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [L_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_CAPS, KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, XXXXXXX,                      XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, CAPSWRD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  HM_GRV, HM_MINS,  HM_EQL, HM_BSLS, XXXXXXX,                      XXXXXXX, HM_LBRC, HM_RBRC, KC_RALT, KC_RGUI,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_SPC,     KC_ENT, KC_MUTE, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [L_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_PSCR,                      HM_LEFT, HM_DOWN,   HM_UP, HM_RGHT, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      KC_PGUP,  KC_END, KC_HOME, KC_PGDN, XXXXXXX, CAPSWRD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, RGB_MOD, KC_PGUP,    KC_PGDN, RGB_TOG, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [L_GAME] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_RSFT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 LCTL_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI,MO(L_GAME_NUM),KC_SPC,     KC_ENT,MO(L_GAME_NUM), KC_LALT
                                        //`--------------------------'  `--------------------------'

  ),

  [L_GAME_NUM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TAB,  KC_GRV, KC_MINS,  KC_EQL, KC_BSLS, KC_TILD,                      XXXXXXX, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 LCTL_T(KC_ESC),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI,DF(L_BASE),KC_SPC,     KC_ENT,DF(L_BASE), KC_RALT
                                        //`--------------------------'  `--------------------------'

  ),

  [L_TRANS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CAPSWRD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
KC_DEL, ESC_LT(L_FUNC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC,  KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       DF(L_GAME), XXXXXXX,  KC_ENT,     KC_SPC, XXXXXXX, DF(L_GAME)
                                      //`--------------------------'  `--------------------------'

  ),

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

#define IDLE_FRAMES 1
#define IDLE_SPEED 35 // below this wpm value your animation will idle

#define TAP_FRAMES 5
#define TAP_SPEED 50

#define ANIM_FRAME_DURATION 100 // how long each frame lasts in ms
#define ANIM_SIZE 512 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 0;

static const char PROGMEM lambda[ANIM_SIZE] = LAMBDA;
static const char PROGMEM glitched_lambda[ANIM_SIZE] = GLITCHED_LAMBDA;
static const char PROGMEM inverted_lambda[ANIM_SIZE] = INVERTED_LAMBDA;

static void render_anim(void) {
    static const char * idle[IDLE_FRAMES] = { lambda };

    static const char * tap[TAP_FRAMES] = {
        glitched_lambda, glitched_lambda, lambda, glitched_lambda, lambda
    };

    void animation_phase(void) {
        if(get_current_wpm() <=IDLE_SPEED){
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
         } else {
             current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
             oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
         }
    }
    if(get_current_wpm() != 000) {
        oled_on();
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
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

void caps_word_set_user(bool active) { caps_word_active = active; }

bool previous_caps_active = 0;

void oled_render_layer_state(void) {
    oled_set_cursor(0, 0);
    bool inverted = caps_word_active || host_keyboard_led_state().caps_lock;

    if(biton32(default_layer_state) == L_BASE && layer_state_is(L_BASE))
        oled_write_P(PSTR("BASE"), inverted);
    if(layer_state_is(L_NUM))
        oled_write_P(PSTR("NUM"), inverted);
    if(layer_state_is(L_SYM))
        oled_write_P(PSTR("SYM"), inverted);
    if(layer_state_is(L_FUNC))
        oled_write_P(PSTR("FUNC"), inverted);
    if(biton32(default_layer_state) == L_GAME && layer_state_is(L_BASE))
        oled_write_P(PSTR("GAME"), inverted);
    if(layer_state_is(L_GAME_NUM))
        oled_write_P(PSTR("GME_N"), inverted);
    if(layer_state_is(L_TRANS))
        oled_write_P(PSTR("TRNS"), inverted);
}

bool oled_task_user(void) {
    bool caps_active = caps_word_active || host_keyboard_led_state().caps_lock;

    if (is_keyboard_master()) {
      if (caps_active != previous_caps_active)
        oled_clear();

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
