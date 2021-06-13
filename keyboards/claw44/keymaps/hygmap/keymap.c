#include QMK_KEYBOARD_H
#include <stdio.h>


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


// カスタムキーコード定義のための設定
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _ADJUST,
};

// カスタムキー定義

// common: 共通設定
#define KC_ KC_TRNS //前レイヤーの承継
#define KC_XXXX KC_NO //定義無し


// layer: レイヤー変更 変換＋RAISEと無変換+LOWER、Enterと＿ADJUST
#define KC_LOWER MO(_LOWER)
#define KC_RAISE MO(_RAISE)
#define KC_G_JA RGUI_T(KC_HENK)
#define KC_G_EN LGUI_T(KC_MHEN)
#define KC_AD_ENT LT(_ADJUST, KC_ENT)

#define KC_C_BS LCTL_T(KC_BSPC)      // backspace ctrl
#define KC_A_BS ALT_T(KC_BSPC)      // backspace alt
//#define KC_A_DEL ALT_T(KC_DEL)       // alt
#define KC_C_TAB LCTL_T(KC_TAB)     //tab and ctrl

// cmd_tap alpha
//#define KC_G_D LGUI_T(KC_D)
//#define KC_G_K RGUI_T(KC_K)

// ctl_tap alpha
//#define KC_C_F LCTL_T(KC_F)
//#define KC_C_J RCTL_T(KC_J)

// alt_tap alpha
//#define KC_A_S ALT_T(KC_S)
//#define KC_A_L ALT_T(KC_L)

// shift_tap alfa
#define KC_S_A LSFT_T(KC_A)    //shift down key
#define KC_S_SC RSFT_T(KC_SCLN)   //shift up key


// Shift holdは余裕を持たせる：全体が170に対して、文字キーのみ190に設定。
#define TAPPING_LAYER_TERM 190
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_S_A:
      return TAPPING_LAYER_TERM;
    case KC_S_SC:
      return TAPPING_LAYER_TERM;
    default:
      return TAPPING_TERM;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_kc( \
   //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
      ESC, Q  , W  , E  , R  , T  ,       Y  , U  , I  , O  , P  ,MINS,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     C_TAB,S_A, S  , D  , F  , G  ,       H  , J  , K  , L  ,S_SC,QUOT,
  //|----+----+----+----+----+----+     |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B ,        N  , M  ,COMM,DOT,SLSH,AD_ENT,
  //`----+----+----+----+----+----/     \----+----+----+----+----+----'
               G_EN,LOWER,SPC,A_BS,      C_BS,SPC,RAISE,G_JA
  //          `----+----+----+----'     `----+----+----+----'
  ),

    [_RAISE] = LAYOUT_kc( \
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,EXLM,AT  ,HASH,DLR ,PERC,      CIRC,AMPR,ASTR,EQL ,BSLS,BSPC,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LCTL,    ,GRV ,DQUO,QUOT,TILD,      LEFT,DOWN, UP ,RGHT,PLUS,PIPE,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
     LSFT,    ,    ,LCBR,LBRC,LPRN,      RPRN,RBRC,RCBR,    ,    ,ENT ,
  //`----+----+----+----+----+----/     \----+----+----+----+----+----'
                   ,    ,ENT ,DEL ,          ,    ,    ,
  //          `----+----+----+----'     `----+----+----+----'
  ),

    [_LOWER] = LAYOUT_kc( \
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,EXLM,AT  ,HASH,DLR ,PERC,      CIRC,AMPR,ASTR,EQL ,BSLS,BSPC,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
    LCTL, 1   , 2  , 3  , 4  , 5  ,       6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
    LSFT,    ,     ,LCBR,LBRC,LPRN,      RPRN,RBRC,COMM,DOT ,SLSH,ENT ,
  //`----+----+----+--+-+----+----/     \----+----+----+----+----+----'
                   ,    ,    ,    ,      DEL ,ENT ,    ,
  //          `----+----+----+----'     `----+----+----+----'
  ),

    [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.     ,----+----+----+----+----+----.
         ,F1  ,F2  ,F3  ,F4  ,F5  ,          ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,F6 , F7  ,F8  ,F9  ,F10  ,          ,    ,    ,MS_U,MS_R,    ,
  //|----+----+----+----+----+----|     |----+----+----+----+----+----|
         ,F11 ,F12 ,    ,    ,    ,        ,MS_BTN1,MS_L,MS_D,MS_BTN2,  ,
  //`----+----+----+--+-+----+----/     \----+----+----+----+----+----'
                   ,    ,    ,    ,          ,    ,    ,
  //          `----+----+----+----'     `----+----+----+----'
  ),
};

#ifdef OLED_DRIVER_ENABLE

void render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Layer: Default"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Layer: Raise"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Layer: Lower"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Layer: Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Layer: Undefined"), false);
    }
}

void render_logo(void) {
    static const char PROGMEM logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(logo, false);
}

char keylog_str[24]  = {};
char keylogs_str[21] = {};
int  keylogs_str_idx = 0;

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name);

    // update keylogs
    if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
        keylogs_str_idx = 0;
        for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
            keylogs_str[i] = ' ';
        }
    }

    keylogs_str[keylogs_str_idx] = name;
    keylogs_str_idx++;
}

const char *read_keylog(void) { return keylog_str; }
const char *read_keylogs(void) { return keylogs_str; }

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_state();
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
    } else {
        render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    return rotation;
}

#endif

