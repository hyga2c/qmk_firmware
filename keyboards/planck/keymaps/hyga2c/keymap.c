/* Copyright 2015-2017 Jack Humbert
 * Updated 2020 mixedfeelings
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation,either version 2 of the License,or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not,see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
  LOWER,
  ADJUST
};

// カスタムキー定義

// common: 共通設定
#define KC_ KC_TRNS //前レイヤーの承継
#define KC_XXXX KC_NO //定義無し

// layer: レイヤー変更 スペースを左に配置してレイヤー2(Lower)に、エンターを右に配置してレイヤー1（Raise)に
//#define KC_L_SPC LT(_LOWER,KC_SPC)
//#define KC_R_SPC LT(_RAISE,KC_SPC)

// JE_t + Layer hold: 変換無変換キータップとWin/Cmd
#define KC_R_JA LT(_RAISE,KC_HENK)
#define KC_L_EN LT(_LOWER,KC_MHEN)

// cmd_t
#define KC_G_D LGUI_T(KC_D)
#define KC_G_K RGUI_T(KC_K)

// ctl_t
#define KC_C_F LCTL_T(KC_F)
#define KC_C_J RCTL_T(KC_J)

// alt_t
#define KC_A_S ALT_T(KC_S)
#define KC_A_L ALT_T(KC_L)

// shift_t
#define KC_S_A LSFT_T(KC_A)    //shift down key
#define KC_S_SC RSFT_T(KC_SCLN)   //shift up key

#define KC_C_BS LCTL_T(KC_BSPC)      // backspace ctrl
#define KC_A_BS ALT_T(KC_BSPC)      // backspace alt
#define KC_A_DEL ALT_T(KC_DEL)       // alt
#define KC_C_TAB LCTL_T(KC_TAB)     //tab and ctrl
#define KC_S_LFT LSFT_T(KC_LEFT)    //shift left key
#define KC_M_RGT LT(_ADJUST,KC_RGHT)    //mod3 right key
#define KC_S_DWN LSFT_T(KC_DOWN)    //shift down key

#define KC_AD_UP LT(_ADJUST, KC_UP)   //shift up key


// S,L,D,K,F,Jはチョット余裕を持たせる：全体が170に対して、文字キーのみ240に設定。シフトは短めで-40にする
#define TAPPING_LAYER_TERM 240
uint16_t get_tapping_term(uint16_t keycode,keyrecord_t *record) {
  switch (keycode) {
    case KC_G_D:
      return TAPPING_LAYER_TERM;
    case KC_G_K:
      return TAPPING_LAYER_TERM;
    case KC_C_F:
      return TAPPING_LAYER_TERM;
    case KC_C_J:
      return TAPPING_LAYER_TERM;
    case KC_A_S:
      return TAPPING_LAYER_TERM;
    case KC_A_L:
      return TAPPING_LAYER_TERM;
    case KC_S_A:
      return TAPPING_LAYER_TERM - 50;
    case KC_S_SC:
      return TAPPING_LAYER_TERM - 50;
    default:
      return TAPPING_TERM;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = KC_KEYMAP(
  //-----+----+----+----+----+----+----+----+----+----+----+----
     ESC ,Q   , W  , E  ,R   , T  , Y  , U  , I  , O  , P  ,MINS,
  //-----+----+----+----+----+----+----+----+----+----+----+----
     C_TAB, S_A, A_S, G_D, C_F, G  , H  , C_J, G_K, A_L,S_SC,QUOT,
  //-----+----+----+----+----+----+----+----+----+----+----+----
     LSFT, Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH,ENT ,
  //-----+----+----+----+----+----+----+----+----+----+----+----
     DOWN,LEFT,LCTL,LGUI,L_EN,SPC ,SPC ,R_JA ,RGUI,RALT,RGHT,AD_UP
  ),


[_RAISE] = KC_KEYMAP(
//  .-----+----+----+----+----+----+----+----+----+----+----+----.
          ,EXLM,AT  ,HASH,DLR ,PERC,CIRC,AMPR,ASTR,EQL ,BSLS,BSPC,
//  |-----+----+----+----+----+----+----+----+----+----+----+----|
     LCTL,    ,GRV ,DQUO,QUOT,TILD, LEFT,DOWN, UP ,RGHT,PLUS,PIPE,
//  |-----+----+----+----+----+----+----+----+----+----+----+----|
     LSFT,    ,    ,LCBR,LBRC,LPRN, RPRN,RBRC,RCBR,    ,    ,    ,
//  |-----+----+----+----+----+----+----+----+----+----+----+----|
          ,    ,    ,    ,    ,ENT ,    ,    ,    ,    ,    ,UP
//  .-----+----+----+----+----+----+----+----+----+----+----+----.
),

[_LOWER] = KC_KEYMAP(
//  .-----+----+----+----+----+----+----+----+----+----+----+----.
          ,EXLM,AT  ,HASH,DLR ,PERC,CIRC,AMPR,ASTR,EQL ,BSLS,BSPC,
//  |-----+----+----+----+----+----+----+----+----+----+----+----|
     LCTL , 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,    ,
//  |-----+----+----+----+----+----+----+----+----+----+----+----|
     LSFT ,    ,    ,LCBR,LBRC,LPRN, RPRN,RBRC,COMM,DOT ,SLSH,ENT ,
//  |-----+----+----+----+----+----+----+----+----+----+----+----|
          ,    ,    ,    ,    ,    ,ENT ,    ,    ,    ,    ,UP
//  .-----+----+----+----+----+----+----+----+----+----+----+----.
),

[_ADJUST] = KC_KEYMAP(
//  .-----+----+----+----+----+----+----+----+----+----+----+----.
          ,F1  ,F2  ,F3  ,F4  ,F5  ,    ,    ,    ,    ,    ,    ,
//  |-----+----+----+----+----+----+----+----+----+----+----+----|
          ,F6 , F7  ,F8  ,F9  ,F10 ,    ,    ,MS_BTN1,MS_U,MS_BTN2,,
//  |-----+----+----+----+----+----+----+----+----+----+----+----|
          ,F11 ,F12 ,    ,    ,    ,    ,    ,MS_L,MS_D,MS_R,    ,
//  |-----+----+----+----+----+----+----+----+----+----+----+----|
          ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,
//  .-----+----+----+----+----+----+----+----+----+----+----+----.
)

};
