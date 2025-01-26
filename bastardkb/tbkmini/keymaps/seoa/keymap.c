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
         KC_ESC,    G(KC_ESC),   XXXXXXX,     KC_X,       KC_Q,      XXXXXXX,/*DF(L_GAME),*/                KC_J,       KC_D,       KC_L,       KC_K,       KC_C,     XXXXXXX,
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
                                                   //`+-----------+-----------+-----------||-----------+-----------+-----------+'
    ),

    [L_NAV] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                        ,-----------------------------------------------------------------------.
         XXXXXXX,    XXXXXXX,    C(KC_Z),    C(KC_C),    C(KC_V),    XXXXXXX,                            C(KC_Y),    C(KC_V),    C(KC_C),    C(KC_X),    C(KC_Z),    C(KC_S),
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         C(KC_F),    KC_LWIN,    KC_LALT,    KC_LCTL,    KC_LSFT,  S(KC_CAPS),                            XXXXXXX,    KC_LEFT,    KC_DOWN,     KC_UP,     KC_RGHT,    KC_TAB,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,    XXXXXXX,    C(KC_Y),    C(KC_A),    C(KC_X),    XXXXXXX,                              KC_INS,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_DEL,
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
         KC_TAB,       KC_T,       KC_Q,      KC_W,       KC_E,       KC_R,                                KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,     DF(L_ENG),
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         KC_LSFT,      KC_G,       KC_A,      KC_S,       KC_D,       KC_F,                                KC_H,       KC_J,       KC_UP,      KC_K,       KC_L,      KC_GRV,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                        |-----------+-----------+-----------+-----------+-----------+-----------|
         KC_LCTL,      KC_B,       KC_Z,      KC_X,       KC_C,       KC_V,                                KC_N,      KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_M,      KC_SLSH,
    //|-----------+-----------+-----------+-----------+-----------+-----------+-----------||-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                  KC_LALT,              KC_SPC,        LT(L_NUM, KC_ESC),           KC_H,               KC_SPC,         LT(L_FUN, KC_ENT)
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

// Обработка нажатий?
bool process_record_user(uint16_t keycode, keyrecord_t *record) {   // В конце должно быть true, чтоб символ напечатался.
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
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case L_ENG:
                rgb_matrix_set_color(i, RGB_PINK);
            break;
            case L_RU:
                rgb_matrix_set_color(i, RGB_PURPLE);
            break;
            case L_MEDIA:
                rgb_matrix_set_color(i, RGB_MAGENTA);
            break;
            case L_NAV:
                rgb_matrix_set_color(i, RGB_CYAN);
            break;
            case L_MOUSE:
                rgb_matrix_set_color(i, RGB_YELLOW);
            break;
            case L_SYM:
                rgb_matrix_set_color(i, RGB_GREEN);
            break;
            case L_NUM:
                rgb_matrix_set_color(i, RGB_BLUE);
            break;
            case L_FUN:
                rgb_matrix_set_color(i, RGB_RED);
            break;
            case L_GAME:
                rgb_matrix_set_color(i, RGB_ORANGE);
            break;
            
            default: // for any other layers, or the default layer
                rgb_matrix_set_color(i, RGB_WHITE);
            break;
        }
    }
    return false;
}


void matrix_scan_user(void) {
    user_timer();

    // // Проверяем, активен ли слой
    // if (!layer_state_cmp(layer_state, L_MEDIA) &&
    //     !layer_state_cmp(layer_state, L_NAV) &&
    //     !layer_state_cmp(layer_state, L_MOUSE) &&
    //     !layer_state_cmp(layer_state, L_SYM) &&
    //     !layer_state_cmp(layer_state, L_NUM) &&
    //     !layer_state_cmp(layer_state, L_FUN) &&
    //     !layer_state_cmp(layer_state, L_RU)) {
    //     // Если ни один из этих слоев не активен, обновляем подсветку на основе текущего базового слоя
    //     default_layer_state_set_user(default_layer_state);
    //     }
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
