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

#include "print.h"

#include QMK_KEYBOARD_H
#include "rgb_matrix.h"

#define CUSTOM_SAFE_RANGE SAFE_RANGE
#include "lang_shift/include.h"

#define L_ENG 0
#define L_GAME 1
#define L_RU 2
#define L_MEDIA 3
#define L_NAV 4
#define L_MOUSE 5
#define L_SYM 6
#define L_NUM 7
#define L_FUN 8

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_ENG] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                        ,-----------------------------------------------------------------------.
         KC_ESC,    G(KC_ESC),   XXXXXXX,     KC_X,       KC_Q,      XXXXXXX, /*DF(L_GAME),*/                KC_J,       KC_D,       KC_L,       KC_K,       KC_C,     XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
          KC_F,   LWIN_T(KC_S),ALT_T(KC_E),CTL_T(KC_O),SFT_T(KC_A),  XXXXXXX,                               KC_G,  SFT_T(KC_T),CTL_T(KC_N),ALT_T(KC_V),LWIN_T(KC_H),  XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,     KC_W,       KC_U,       KC_Y,       KC_I,      XXXXXXX,                               KC_B,       KC_M,       KC_R,       KC_P,       KC_Z,     LA_CHNG,
    //|-----------+-----------+-----------+-----------+-----------+-----------+-----------||-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                            LT(L_MEDIA, KC_ENT),  LT(L_MOUSE, KC_SPC),     MO(L_NAV),            MO(L_SYM),        LT(L_FUN, KC_BSPC),       MO(L_NUM)
                        //`+--------------------+--------------------+--------------------||--------------------+--------------------+--------------------+'
    ),

    [L_RU] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                        ,-----------------------------------------------------------------------.
          KC_ESC,      KC_O,     KC_QUOT,     KC_Z,       KC_S,      KC_RBRC,                               KC_Q,       KC_L,      KC_K,       KC_R,        KC_W,     KC_SCLN,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_A, RWIN_T(KC_C),RALT_T(KC_T),RCTL_T(KC_J),SFT_T(KC_F),  KC_M,                                 KC_U, SFT_T(KC_N),RCTL_T(KC_Y),RALT_T(KC_D),RWIN_T(KC_LBRC),KC_X,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         LA_CHNG,      KC_I,     KC_DOT,      KC_E,       KC_B,      KC_GRV,                               KC_COMM,     KC_V,      KC_H,       KC_G,        KC_P,     XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------+-----------||-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                            LT(L_MEDIA, KC_ENT),  LT(L_MOUSE, KC_SPC),     MO(L_NAV),             MO(L_SYM),      LT(L_FUN, KC_BSPC),       MO(L_NUM)
                        //`+--------------------+--------------------+--------------------||--------------------+--------------------+--------------------+'
    ),

    [L_MEDIA] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                        ,-----------------------------------------------------------------------.
         QK_BOOT,    KC_RWIN,    KC_RALT,    KC_RCTL,    KC_RSFT,    XXXXXXX,                              NK_ON,     KC_VOLD,    KC_VOLU,    LA_SYNC,    RGB_TOG,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,    KC_LWIN,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,                             NK_TOGG,    KC_MPLY,    KC_MPRV,    KC_MNXT,    KC_MUTE,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,    KC_RWIN,    KC_RALT,    KC_RCTL,    KC_RSFT,    XXXXXXX,                             NK_OFF,     LA_CAPS,    LA_ALSH,    LA_CTSH,    LA_WISP,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------+-----------||-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                         XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX
                                                   //`+-----------+-----------+-----------||----------+-----------+-----------+'
    ),

    [L_NAV] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                        ,-----------------------------------------------------------------------.
         XXXXXXX,    XXXXXXX,    C(KC_Z),    C(KC_C),    C(KC_V),   RCS(KC_V),                            C(KC_Y),    C(KC_V),    C(KC_C),    C(KC_X),    C(KC_Z),    C(KC_S),
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         C(KC_F),    KC_LWIN,    KC_LALT,    KC_LCTL,    KC_LSFT,  S(KC_CAPS),                            XXXXXXX,    KC_LEFT,    KC_DOWN,     KC_UP,     KC_RGHT,    KC_TAB,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,    XXXXXXX,    C(KC_Y),    C(KC_A),    C(KC_X),   RCS(KC_C),                              KC_INS,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_DEL,
    //|-----------+-----------+-----------+-----------+-----------+-----------+-----------||-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                         XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX
                                                   //`+-----------+-----------+-----------||-----------+-----------+-----------+'
    ),

    [L_MOUSE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                        ,-----------------------------------------------------------------------.
         XXXXXXX,    KC_BTN5,    KC_BTN1,    KC_BTN3,    KC_BTN2,    XXXXXXX,                             C(KC_Y),    C(KC_V),    C(KC_C),    C(KC_X),    C(KC_Z),    C(KC_S),
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,    KC_LWIN,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,                             KC_CAPS,    KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_TAB,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,    KC_BTN4,    KC_ACL2,    KC_ACL1,    KC_ACL0,    XXXXXXX,                              KC_INS,    KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,    KC_DEL,
    //|-----------+-----------+-----------+-----------+-----------+-----------+-----------||-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                         XXXXXXX,    XXXXXXX,    XXXXXXX,     KC_BTN1,    KC_BTN3,    KC_BTN2
                                                   //`+-----------+-----------+-----------||-----------+-----------+-----------+'
    ),

    [L_SYM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                        ,-----------------------------------------------------------------------.
         XXXXXXX,     EN_AT,     EN_HASH,  ONCE_SHIFT,    AG_DOT,    EN_CIRC,                             EN_AMPR,    AG_ASTR,    AG_MINS,    AG_PLUS,     AG_EQL,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         AG_COMM,    AG_EXCL,    AG_QUES,  COMMA_SPACE, SMART_DOT,   AG_PERC,                             EN_PIPE,    AG_LPRN,    EN_LBRC,    EN_LCBR,     EN_LT,     EN_GRV,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         CW_TOGG,    EN_SLSH,    RU_NUME,    AG_DQUO,    EN_QUOT,     EN_DLR,                             AG_BSLS,    AG_RPRN,    EN_RBRC,    EN_RCBR,     EN_GT,     EN_TILD,
    //|-----------+-----------+-----------+-----------+-----------+-----------+-----------||-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                         AG_UNDS,    AG_COLN,    AG_SCLN,     XXXXXXX,    XXXXXXX,    XXXXXXX
                                                   //`+-----------+-----------+-----------||-----------+-----------+-----------+'
    ),

    [L_NUM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                        ,-----------------------------------------------------------------------.
         XXXXXXX,     XXXXXXX,    AG_1,       AG_2,       AG_3,      XXXXXXX,                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,      AG_0,      AG_4,       AG_5,       AG_6,      XXXXXXX,                             XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LWIN,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,     KC_PSCR,    AG_7,       AG_8,       AG_9,      XXXXXXX,                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------+-----------||-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                          KC_ENT,     KC_SPC,    XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX
                                                   //`+-----------+-----------+-----------||-----------+-----------+-----------+'
    ),

    [L_FUN] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                        ,-----------------------------------------------------------------------.
         XXXXXXX,     KC_F10,      KC_F1,      KC_F2,      KC_F3,     XXXXXXX,                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,     KC_F11,      KC_F4,      KC_F5,      KC_F6,     XXXXXXX,                             XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LWIN,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,     KC_F12,      KC_F7,      KC_F8,      KC_F9,     XXXXXXX,                             XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------+-----------||-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                         XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX
                                                   //`+-----------+-----------+-----------||-----------+-----------+-----------+'
    ),

    [L_GAME] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                        ,-----------------------------------------------------------------------.
          KC_ESC,    KC_TAB,        KC_Q,      KC_W,       KC_E,       KC_R,                                KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,     DF(L_ENG),
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_G,     KC_LSFT,       KC_A,      KC_S,       KC_D,       KC_F,                                KC_H,       KC_J,       KC_UP,      KC_K,       KC_L,      KC_GRV,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_B,     KC_LCTL,       KC_X,      KC_Z,       KC_M,       KC_V,                                KC_N,      KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_C,      KC_SLSH,
    //|-----------+-----------+-----------+-----------+-----------+-----------+-----------||-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                  KC_LALT,              KC_SPC,          MO(L_NUM),                  KC_H,             KC_SPC,         LT(L_FUN, KC_ENT)
                        //`+--------------------+--------------------+--------------------||--------------------+--------------------+--------------------+'
    )
};

bool modify_layer(uint16_t keycode, keyrecord_t *record) {
    if (!record->tap.count && record->event.pressed) { // Кнопка зажата
        register_code(keycode);
        lang_shift_process_record(LA_CHNG, record);
        return false;
    } else if (!record->tap.count && !record->event.pressed) { // Кнопка отжата после зажатия
        unregister_code(keycode);
        record->event.pressed = true;
        lang_shift_process_record(LA_CHNG, record);
        record->event.pressed = false;
        return false;
    }
    return true;
};

void reg_unreg(uint16_t keycode) {
    register_code(keycode);
    unregister_code(keycode);
}

bool shift_on_next_key = false;

const char* key_to_str(uint16_t keycode) {
    // 1. Твои кастомные кейкоды (lang_shift, слои и символы)
    // Здесь мы возвращаем ровно то, что написано в твоем keymap.c
    switch (keycode) {
        case LA_CHNG:    return "LA_CHNG";
        case LA_SYNC:    return "LA_SYNC";
        case LA_CAPS:    return "LA_CAPS";
        case LA_ALSH:    return "LA_ALSH";
        case LA_CTSH:    return "LA_CTSH";
        case LA_WISP:    return "LA_WISP";
        case SMART_DOT:  return "SMART_DOT";
        case ONCE_SHIFT: return "ONCE_SHIFT";
        case COMMA_SPACE:return "COMMA_SPACE";
        case RU_NUME:    return "RU_NUME";
        case CW_TOGG:    return "CW_TOGG";
        case EN_AT:      return "EN_AT";
        case EN_HASH:    return "EN_HASH";
        case AG_DOT:     return "AG_DOT";
        case EN_CIRC:    return "EN_CIRC";
        case EN_AMPR:    return "EN_AMPR";
        case AG_ASTR:    return "AG_ASTR";
        case AG_MINS:    return "AG_MINS";
        case AG_PLUS:    return "AG_PLUS";
        case AG_EQL:     return "AG_EQL";
        case AG_COMM:    return "AG_COMM";
        case AG_EXCL:    return "AG_EXCL";
        case AG_QUES:    return "AG_QUES";
        case AG_PERC:    return "AG_PERC";
        case EN_PIPE:    return "EN_PIPE";
        case AG_LPRN:    return "AG_LPRN";
        case AG_RPRN:    return "AG_RPRN";
        case EN_LBRC:    return "EN_LBRC";
        case EN_RBRC:    return "EN_RBRC";
        case EN_LCBR:    return "EN_LCBR";
        case EN_RCBR:    return "EN_RCBR";
        case EN_LT:      return "EN_LT";
        case EN_GT:      return "EN_GT";
        case EN_SLSH:    return "EN_SLSH";
        case AG_BSLS:    return "AG_BSLS";
        case AG_DQUO:    return "AG_DQUO";
        case EN_QUOT:    return "EN_QUOT";
        case EN_DLR:     return "EN_DLR";
        case AG_UNDS:    return "AG_UNDS";
        case AG_COLN:    return "AG_COLN";
        case AG_SCLN:    return "AG_SCLN";
        case EN_TILD:    return "EN_TILD";
        case EN_GRV:     return "EN_GRV";
        case AG_0: return "AG_0"; case AG_1: return "AG_1";
        case AG_2: return "AG_2"; case AG_3: return "AG_3";
        case AG_4: return "AG_4"; case AG_5: return "AG_5";
        case AG_6: return "AG_6"; case AG_7: return "AG_7";
        case AG_8: return "AG_8"; case AG_9: return "AG_9";
    }

    // 2. Извлекаем "чистый" кейкод (Base Key)
    // Это позволит увидеть "KC_A" внутри "SFT_T(KC_A)" или "C(KC_Z)"
    uint16_t clean_keycode = keycode;
    if (keycode >= QK_MOD_TAP) clean_keycode = keycode & 0xFF;
    else if (keycode >= QK_LAYER_TAP) clean_keycode = keycode & 0xFF;
    else if (keycode > 0xFF) clean_keycode = keycode & 0xFF;

    // 3. Точные стандартные имена QMK
    switch (clean_keycode) {
        case KC_A ... KC_Z: {
            static char b[] = "KC_X";
            b[3] = 'A' + (clean_keycode - KC_A);
            return b;
        }
        case KC_1 ... KC_0: {
            static char b[] = "KC_X";
            b[3] = (clean_keycode == KC_0) ? '0' : '1' + (clean_keycode - KC_1);
            return b;
        }
        case KC_ESC:  return "KC_ESC";
        case KC_ENT:  return "KC_ENT";
        case KC_BSPC: return "KC_BSPC";
        case KC_SPC:  return "KC_SPC";
        case KC_TAB:  return "KC_TAB";
        case KC_CAPS: return "KC_CAPS";
        case KC_LSFT: return "KC_LSFT";
        case KC_LCTL: return "KC_LCTL";
        case KC_LALT: return "KC_LALT";
        case KC_LWIN: return "KC_LWIN";
        case KC_RSFT: return "KC_RSFT";
        case KC_RCTL: return "KC_RCTL";
        case KC_RALT: return "KC_RALT";
        case KC_RWIN: return "KC_RWIN";
        case KC_LEFT: return "KC_LEFT";
        case KC_RGHT: return "KC_RGHT";
        case KC_UP:   return "KC_UP";
        case KC_DOWN: return "KC_DOWN";
        case KC_COMM: return "KC_COMM";
        case KC_DOT:  return "KC_DOT";
        case KC_SCLN: return "KC_SCLN";
        case KC_QUOT: return "KC_QUOT";
        case KC_GRV:  return "KC_GRV";
        case KC_SLSH: return "KC_SLSH";
        case KC_BSLS: return "KC_BSLS";
        case KC_MINS: return "KC_MINS";
        case KC_EQL:  return "KC_EQL";
        case KC_LBRC: return "KC_LBRC";
        case KC_RBRC: return "KC_RBRC";
        case KC_PSCR: return "KC_PSCR";
        case KC_INS:  return "KC_INS";
        case KC_DEL:  return "KC_DEL";
        case KC_HOME: return "KC_HOME";
        case KC_END:  return "KC_END";
        case KC_PGUP: return "KC_PGUP";
        case KC_PGDN: return "KC_PGDN";
        // Мышь - точные имена
        case KC_MS_U: return "KC_MS_U";
        case KC_MS_D: return "KC_MS_D";
        case KC_MS_L: return "KC_MS_L";
        case KC_MS_R: return "KC_MS_R";
        case KC_BTN1: return "KC_BTN1";
        case KC_BTN2: return "KC_BTN2";
        case KC_BTN3: return "KC_BTN3";
        case KC_BTN4: return "KC_BTN4";
        case KC_BTN5: return "KC_BTN5";
        case KC_WH_U: return "KC_WH_U";
        case KC_WH_D: return "KC_WH_D";
        case KC_WH_L: return "KC_WH_L";
        case KC_WH_R: return "KC_WH_R";
        case KC_ACL0: return "KC_ACL0";
        case KC_ACL1: return "KC_ACL1";
        case KC_ACL2: return "KC_ACL2";
        // Медиа - точные имена
        case KC_VOLD: return "KC_VOLD";
        case KC_VOLU: return "KC_VOLU";
        case KC_MUTE: return "KC_MUTE";
        case KC_MPLY: return "KC_MPLY";
        case KC_MPRV: return "KC_MPRV";
        case KC_MNXT: return "KC_MNXT";
        // Системные
        case QK_BOOT: return "QK_BOOT";
        case NK_ON:   return "NK_ON";
        case NK_OFF:  return "NK_OFF";
        case NK_TOGG: return "NK_TOGG";
        case RGB_TOG: return "RGB_TOG";

        case KC_F1: return "KC_F1"; case KC_F2: return "KC_F2";
        case KC_F3: return "KC_F3"; case KC_F4: return "KC_F4";
        case KC_F5: return "KC_F5"; case KC_F6: return "KC_F6";
        case KC_F7: return "KC_F7"; case KC_F8: return "KC_F8";
        case KC_F9: return "KC_F9"; case KC_F10: return "KC_F10";
        case KC_F11: return "KC_F11"; case KC_F12: return "KC_F12";

        case 0: return "KC_NO";
        default: return "UNKNOWN";
    }
}

// Обработка нажатий
bool process_record_user(uint16_t keycode, keyrecord_t *record) {   // В конце должно быть true, чтоб символ напечатался.
#ifdef CONSOLE_ENABLE
    if (record->event.pressed) {
        const char* name = key_to_str(keycode);

        // Если это сложный код (Mod-Tap, Layer-Tap, Combo)
        if (keycode > 0xFF) {
            uprintf("PRESSED: Complex Key: Raw=%u, Base=%s\n", keycode, name);
        } else {
            // Если это обычная одиночная клавиша
            uprintf("PRESSED: Key: %s\n", name);
        }
    } else {
        const char* name = key_to_str(keycode);

        // Если это сложный код (Mod-Tap, Layer-Tap, Combo)
        if (keycode > 0xFF) {
            uprintf("RELESED: Complex Key: Raw=%u, Base=%s\n", keycode, name);
        } else {
            // Если это обычная одиночная клавиша
            uprintf("RELESED: Key: %s\n", name);
        }
    }
#endif

    // lang_shift
    if (!lang_shift_process_record(keycode, record))
        return false;


    // Одиночный шифт от GPT4. Потому что одиночный шифт lang_shift не нравится. Но этот шифт не умеет работать с кастом кейкодами lang_shift
    if (keycode == ONCE_SHIFT && record->event.pressed) {
        shift_on_next_key = true;
        return false;
    }

    if (shift_on_next_key && record->event.pressed) {
        register_code(KC_LSFT);
        register_code(keycode);
        unregister_code(keycode);
        unregister_code(KC_LSFT);
        shift_on_next_key = false;
        return false;
    }


    // Умная точка
    if (keycode == SMART_DOT && record->event.pressed) {
        lang_shift_tap_key(AG_DOT);
        reg_unreg(KC_SPC);
        shift_on_next_key = true;
        return false;
    }


    // Запятая + пробел
    if (keycode == COMMA_SPACE && record->event.pressed) {
        lang_shift_tap_key(AG_COMM);
        reg_unreg(KC_SPC);
        return false;
    }


    // Модификаторы со сменой слоя на енг
    switch (keycode) {
        case RWIN_T(KC_C):
        case RWIN_T(KC_LBRC):
            if (!modify_layer(KC_LWIN, record)) {
                return false;
            } else {
                break;
            }

        case RALT_T(KC_T):
        case RALT_T(KC_D):
            if (!modify_layer(KC_LALT, record)) {
                return false;
            } else {
                break;
            }

        case RCTL_T(KC_J):
        case RCTL_T(KC_Y):
            if (!modify_layer(KC_LCTL, record)) {
                return false;
            } else {
                break;
            }
    }

    return true;    // Если условия выше не сработали, то отправить символ как есть
};

void user_timer(void) {
    lang_shift_user_timer();
};



// Lighting Layers
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // https://github.com/qmk/qmk_firmware/blob/master/quantum/color.h
    HSV hsv = {255, 255, 255};

    // Определяем цвет слоя в HSV
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case L_ENG:   hsv = (HSV){HSV_PINK};    break;
        case L_RU:    hsv = (HSV){HSV_PURPLE};  break;
        case L_MEDIA: hsv = (HSV){HSV_MAGENTA}; break;
        case L_NAV:   hsv = (HSV){HSV_CYAN};    break;
        case L_MOUSE: hsv = (HSV){HSV_YELLOW};  break;
        case L_SYM:   hsv = (HSV){HSV_GREEN};   break;
        case L_NUM:   hsv = (HSV){HSV_BLUE};    break;
        case L_FUN:   hsv = (HSV){HSV_RED};     break;
        case L_GAME:  hsv = (HSV){HSV_ORANGE};  break;
        default:      hsv = (HSV){HSV_WHITE};   break;
    }

    // Ограничиваем яркость глобальной настройкой
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }

    // Конвертируем HSV в RGB
    RGB rgb = hsv_to_rgb(hsv);

    // Применяем цвет ко всем светодиодам
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return false;
}


void matrix_scan_user(void) {
    user_timer();
}


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        case KC_QUOT:
        case KC_RBRC:
        case KC_SCLN:
        case KC_COMM:
        case KC_GRV:
        case KC_LBRC:
        case KC_DOT:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
