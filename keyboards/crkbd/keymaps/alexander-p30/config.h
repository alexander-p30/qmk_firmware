/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 150
#define PERMISSIVE_HOLD

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Turn on caps word by pressing lsft and rsft simultaneously
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 1500

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    /* #define RGBLIGHT_EFFECT_RAINBOW_MOOD */
    /* #define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
    /* #define RGBLIGHT_EFFECT_SNAKE */
    /* #define RGBLIGHT_EFFECT_KNIGHT */
    /* #define RGBLIGHT_EFFECT_CHRISTMAS */
    /* #define RGBLIGHT_EFFECT_STATIC_GRADIENT */
    /* #define RGBLIGHT_EFFECT_RGB_TEST */
    /* #define RGBLIGHT_EFFECT_ALTERNATING */
    /* #define RGBLIGHT_EFFECT_TWINKLE */
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT	
    #define RGBLIGHT_DEFAULT_HUE 178
    #define RGBLIGHT_DEFAULT_VAL 60
    #define RGBLIGHT_DEFAULT_SAT 240
    #define RGBLIGHT_SLEEP
#endif


#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
