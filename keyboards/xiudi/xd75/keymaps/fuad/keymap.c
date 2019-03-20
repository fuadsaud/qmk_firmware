/* Copyright 2017 Fuad Saud
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"

enum user_layers {
  LAYER_QWERTY_L,
  LAYER_LOWER_L,
  LAYER_RAISE_L,
  LAYER_QWERTY_M,
  LAYER_LOWER_M,
  LAYER_RAISE_M,
  LAYER_KEBAB,
  LAYER_META
};

enum user_keycodes {
  M_WSS = SAFE_RANGE,
  DENUS,
  D_MACOS,
  D_LINUX,
  STCH_EX
};

// aliases
#define ___x___ KC_NO

// layer switching
#define L_LOWER LT(LAYER_LOWER_L, KC_UNDERSCORE)
#define L_RAISE LT(LAYER_RAISE_L, KC_EQUAL)
#define M_LOWER LT(LAYER_LOWER_M, KC_UNDERSCORE)
#define M_RAISE LT(LAYER_RAISE_M, KC_EQUAL)
/* #define L_LOWER LT(LAYER_LOWER_L, KC_LBRC) */
/* #define L_RAISE LT(LAYER_RAISE_L, KC_RBRC) */
/* #define M_LOWER LT(LAYER_LOWER_M, KC_LBRC) */
/* #define M_RAISE LT(LAYER_RAISE_M, KC_RBRC) */
#define L_META  MO(LAYER_META)
#define M_META  MO(LAYER_META)

// mod-tap
#define LCTL_ESC LCTL_T(KC_ESC)
#define L_ENTER LGUI_T(KC_ENT)
#define M_ENTER LCMD_T(KC_ENT)

#define L_C_BRO CTL_T(KC_LBRC)
#define M_C_BRO CMD_T(KC_LBRC)
#define HYP_BRC ALL_T(KC_RBRC)

// misc
#define L_SS  KC_PSCREEN
#define L_WSS LALT(KC_PSCREEN)
#define L_SSS LSFT(KC_PSCREEN)
#define M_SS  LCMD(LSFT(KC_3))
#define M_SSS LCMD(LSFT(KC_4))

#define L_SPC KC_SPC
#define L_BSP KC_BSPC
#define M_SPC KC_SPC
#define M_BSP KC_BSPC

#define L_BACK LALT(KC_LEFT)
#define L_FRWD LALT(KC_RIGHT)
#define M_BACK LCMD(KC_LEFT)
#define M_FRWD LCMD(KC_RIGHT)

#define L_GLEFT LCTL(LSFT(KC_TAB))
#define L_GRIGH LCTL(KC_TAB)
#define M_GLEFT LCMD(LSFT(KC_LBRC))
#define M_GRIGH LCMD(LSFT(KC_RBRC))

#define L_LOCK LGUI(KC_L)
#define M_LOCK LCTL(LSFT(KC_POWER))

#define L_VOLD KC_VOLD
#define L_VOLU KC_VOLU
#define L_MUTE KC_MUTE
#define M_VOLD KC__VOLDOWN
#define M_VOLU KC__VOLUP
#define M_MUTE KC__MUTE

// diacritics
#define L_GRAVE RALT(KC_GRV)
#define L_ACUTE RALT(KC_QUOT)
#define L_TILDE RALT(KC_TILDE)
#define L_CIRCU RALT(KC_CIRCUMFLEX)
#define L_CEDIL RALT(KC_COMM)
#define M_GRAVE LALT(KC_GRV)
#define M_ACUTE LALT(KC_E)
#define M_TILDE LALT(KC_N)
#define M_CIRCU LALT(KC_I)
#define M_CEDIL LALT(KC_C)

// window management
#define L_MON_L SGUI(KC_LEFT)
#define L_MON_D SGUI(KC_DOWN)
#define L_MON_U LGUI(KC_UP)
#define L_MON_R SGUI(KC_RIGHT)
#define M_MON_L LCAG(KC_LEFT)
#define M_MON_D XXXXXXX
#define M_MON_U XXXXXXX
#define M_MON_R LCAG(KC_RIGHT)

#define L_WIN_MAX LGUI(KC_UP)
#define L_WIN_RST LGUI(KC_DOWN)
#define L_WIN_L LGUI(KC_LEFT)
#define L_WIN_R LGUI(KC_RIGHT)
#define M_WIN_MAX LCMD(LCTL(KC_F))
#define M_WIN_RST LCMD(LCTL(KC_F))
#define M_WIN_L LCMD(LALT(KC_LEFT))
#define M_WIN_R LCMD(LALT(KC_RIGHT))

#define L_WIN_F KC_TAB
#define L_WIN_B LSFT(KC_TAB)
#define M_WIN_F KC_TAB
#define M_WIN_B LSFT(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* MACOS QWERTY LAYER
   *
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │  `  │  1  │  2  │  3  │  4  │  5  │  -  │ ESC │  =  │  6  │  7  │  8  │  9  │  0  │  \  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  {  │  \  │  }  │  Y  │  U  │  I  │  O  │  P  │  '  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Tap for ESC -- │  ⌃  │  A  │  S  │  D  │  F  │  G  │  ↖  │LOCK │  ⇞  │  H  │  J  │  K  │  L  │  ;  │  ⌘  │ -- Tap for ↵
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  ↘  │ MUT │  ⇟  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  ↓  │ CTL │  ⌥  │  ⌘  │  ↓  │  ␣  │VOL -│  ▶  │VOL +│  ⌫  │  ↑  │  ⌘  │  ⌥  │HYPER│ MET │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *
   */

  /* LINUX QWERTY LAYER
   *
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │  `  │  1  │  2  │  3  │  4  │  5  │  -  │ ESC │  =  │  6  │  7  │  8  │  9  │  0  │  \  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │ TAB │  Q  │  W  │  E  │  R  │  T  │  {  │  \  │  }  │  Y  │  U  │  I  │  O  │  P  │  '  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Tap for ESC -- │ CTL │  A  │  S  │  D  │  F  │  G  │HOME │LOCK │PGUP │  H  │  J  │  K  │  L  │  ;  │ ALT │ -- Tap for ENTER
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │SHIFT│  Z  │  X  │  C  │  V  │  B  │ END │ MUT │PGDN │  N  │  M  │  ,  │  .  │  /  │SHIFT│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  ↓  │SUPER│ ALT │ CTL │  ↓  │  ␣  │VOL -│  ▶  │VOL +│  ⌫  │  ↑  │ CTL │ ALT │HYPER│ MET │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *
   */

  [LAYER_QWERTY_L] = {
    { KC_GRV   , KC_1    , KC_2    , KC_3    , KC_4    , KC_5  , KC_MINS , KC_ESC  , KC_EQL  , KC_6  , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS },
    { KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T  , KC_LBRC , KC_BSLS , KC_RBRC , KC_Y  , KC_U    , KC_I    , KC_O    , KC_P    , KC_QUOT },
    { LCTL_ESC , KC_A    , KC_S    , KC_D    , KC_F    , KC_G  , KC_HOME , L_LOCK  , KC_PGUP , KC_H  , KC_J    , KC_K    , KC_L    , KC_SCLN , L_ENTER },
    { KC_LSPO  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B  , KC_END  , L_MUTE  , KC_PGDN , KC_N  , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC },
    { L_LOWER  , KC_LGUI , KC_LALT , L_C_BRO , L_LOWER , L_SPC , L_VOLD  , KC_MPLY , L_VOLU  , L_BSP , L_RAISE , HYP_BRC , KC_LEAD , KC_LEAD , L_META  },
  },
[LAYER_QWERTY_M] = {
    { KC_GRV   , KC_1    , KC_2    , KC_3    , KC_4    , KC_5  , KC_MINS , KC_ESC  , KC_EQL  , KC_6  , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS },
    { KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T  , KC_LBRC , KC_BSLS , KC_RBRC , KC_Y  , KC_U    , KC_I    , KC_O    , KC_P    , KC_QUOT },
    { LCTL_ESC , KC_A    , KC_S    , KC_D    , KC_F    , KC_G  , KC_HOME , M_LOCK  , KC_PGUP , KC_H  , KC_J    , KC_K    , KC_L    , KC_SCLN , M_ENTER },
    { KC_LSPO  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B  , KC_END  , M_MUTE  , KC_PGDN , KC_N  , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC },
    { M_LOWER  , KC_LCTL , KC_LALT , M_C_BRO , M_LOWER , M_SPC , M_VOLD  , KC_MPLY , M_VOLU  , M_BSP , M_RAISE , HYP_BRC , KC_LEAD , KC_LEAD , M_META  },
  },

  /* RAISE LAYER
   *
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │ F11 │ F12 │ F13 │ F14 │ F15 │     │     │     │ F16 │ F17 │ F18 │ F19 │ F20 │ SS  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │WIN ←│WIN ↓│WIN ↑│WIN →│     │     │     │     │W SWI│WSW P│WSW N│     │ SSS │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │MON ←│MON ↓│MON ↑│MON →│TAB ←│     │TAB →│  ←  │  ↓  │  ↑  │  →  │     │ WSS │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │TAB ←│TAB →│     │GUI ←│BRIG+│GUI →│     │TAB ←│TAB →│     │     │     │
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━┪─────┼─────┼─────┼─────┤
   *                 ┃|||||┃     │     │     │     │LEAD │♪ PRV│BRIG-│♪ NXT│     ┃|||||┃     │     │     │     │
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┛─────┴─────┴─────┴─────┘
   *
   */

  [LAYER_RAISE_L] = {
    { _______ , KC_F11  , KC_F12    , KC_F13    , KC_F14  , KC_F15  , _______ , _______ , _______ , KC_F16  , KC_F17  , KC_F18  , KC_F19   , KC_F20  , L_SS    },
    { _______ , L_WIN_L , L_WIN_RST , L_WIN_MAX , L_WIN_R , _______ , _______ , _______ , _______ , _______ , KC_LALT , L_WIN_B , L_WIN_F  , _______ , L_WSS   },
    { _______ , L_MON_L , L_MON_D   , L_MON_U   , L_MON_R , _______ , L_GLEFT , _______ , L_GRIGH , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______ , L_SSS   },
    { _______ , _______ , _______   , L_GLEFT   , L_GRIGH , _______ , L_BACK  , ___x___ , L_FRWD  , _______ , L_BACK  , L_FRWD  , _______  , _______ , _______ },
    { _______ , _______ , _______   , _______   , _______ , KC_LEAD , KC_MPRV , ___x___ , KC_MNXT , _______ , _______ , _______ , _______  , _______ , _______ },
  },

  [LAYER_RAISE_M] = {
    { _______ , KC_F11  , KC_F12    , KC_F13    , KC_F14  , KC_F15  , _______ , _______ , _______ , KC_F16  , KC_F17  , KC_F18  , KC_F19   , KC_F20  , M_SS    },
    { _______ , M_WIN_L , M_WIN_RST , M_WIN_MAX , M_WIN_R , _______ , _______ , _______ , _______ , _______ , KC_LCMD , M_WIN_B , M_WIN_F  , _______ , M_WSS   },
    { _______ , M_MON_L , M_MON_D   , M_MON_U   , M_MON_R , _______ , M_GLEFT , _______ , M_GRIGH , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______ , M_SSS   },
    { _______ , _______ , _______   , M_GLEFT   , M_GRIGH , _______ , M_BACK  , KC_PAUS , M_FRWD  , _______ , M_BACK  , M_FRWD  , _______  , _______ , _______ },
    { _______ , _______ , _______   , _______   , _______ , KC_LEAD , KC_MRWD , KC_SLCK , KC_MFFD , _______ , _______ , _______ , _______  , _______ , _______ },
  },


  /* LOWER LAYER
   *
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │ F1  │ F2  │ F3  │ F4  │ F5  │     │     │     │ F6  │ F7  │ F8  │ F9  │ F10 │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │  {  │  }  │  $  │  %  │     │     │     │  ^  │  &  │  (  │  )  │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  ◌̀  │  ◌̂  │  ◌̧  │  ◌́  │  ◌̃  │TAB ←│BRIG+│TAB →│  |  │  {  │  }  │  [  │  ]  │  \  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │GUI ←│BRIG-│GUI →│     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────╆━━━━━┪─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     ┃|||||┃     │     │     │     │  ⌦  │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┺━━━━━┛─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *
   */

  [LAYER_LOWER_L] = {
    { _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ , _______ , _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F20  , _______ },
    { _______ , _______ , KC_LCBR , KC_RCBR , KC_DLR  , KC_PERC , _______ , _______ , _______ , KC_CIRC , KC_AMPR , KC_LPRN , KC_RPRN , _______ , _______ },
    { _______ , L_GRAVE , L_CIRCU , L_CEDIL , L_ACUTE , L_TILDE , L_GLEFT , _______ , L_GRIGH , KC_PIPE , KC_LCBR , KC_RCBR , KC_LBRC , KC_RBRC , KC_BSLS },
    { _______ , _______ , _______ , _______ , _______ , _______ , L_BACK  , _______ , L_FRWD  , _______ , DENUS   , _______ , _______ , _______ , _______ },
    { _______ , _______ , _______ , _______ , _______ , _______ , KC_MPRV , _______ , KC_MNXT , KC_DEL  , _______ , _______ , _______ , _______ , _______ },
  },

  [LAYER_LOWER_M] = {
    { _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ , _______ , _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F20  , _______ },
    { _______ , _______ , KC_LCBR , KC_RCBR , KC_DLR  , KC_PERC , _______ , _______ , _______ , KC_CIRC , KC_AMPR , KC_LPRN , KC_RPRN , _______ , _______ },
    { _______ , M_GRAVE , M_CIRCU , M_CEDIL , M_ACUTE , M_TILDE , M_GLEFT , _______ , M_GRIGH , KC_PIPE , KC_LCBR , KC_RCBR , KC_LBRC , KC_RBRC , KC_BSLS },
    { _______ , _______ , _______ , _______ , _______ , _______ , M_BACK  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ },
    { _______ , _______ , _______ , _______ , _______ , _______ , KC_MRWD , _______ , KC_MFFD , KC_DEL  , _______ , _______ , _______ , _______ , _______ },
  },


  /* KEBAB LAYER
   *
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │EXIT │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │  -  │     │     │     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *
   */

  [LAYER_KEBAB] = {
    { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ },
    { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ },
    { STCH_EX , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ },
    { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ },
    { _______ , _______ , _______ , _______ , _______ , KC_MINS , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ },
  },

  /* META LAYER
   *
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │RESET│     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │PREV │DEBUG│NEXT │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │RGBHI│RGBSI│RGBVI│     │     │     │LINUX│     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │RGBHD│RGBSI│RGBVD│     │MACOS│     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━┪
   *                 │     │     │     │     │     │     │RGBNM│RGBTG│RGBPM│     │     │     │     │     ┃|||||┃
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┛
   *
   */

  [LAYER_META] = {
    { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___  , RESET   , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ },
    { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___  , DEBUG   , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ },
    { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , RGB_HUI  , RGB_SAI , RGB_VAI , ___x___ , ___x___ , ___x___ , D_LINUX , ___x___ , ___x___ },
    { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , RGB_HUD  , RGB_SAD , RGB_VAD , ___x___ , D_MACOS , ___x___ , ___x___ , ___x___ , ___x___ },
    { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , RGB_RMOD , RGB_TOG , RGB_MOD , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ },
  }
};

  /* TEMPLATE LAYER
   *
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┼─────╆━━━━━┪
   *                 ┃|||||┃     │     │     │     │     │     ┃|||||┃     │     │     │     │     │     ┃|||||┃
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┛
   *
   */

  /* [LAYER_TRANSPARENT_TEMPLATE] = { */
  /*   { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ }, */
  /*   { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ }, */
  /*   { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ }, */
  /*   { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ }, */
  /*   { _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ }, */
  /* }, */

  /* [LAYER_NOOP_TEMPLATE] = { */
  /*   { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ }, */
  /*   { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ }, */
  /*   { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ }, */
  /*   { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ }, */
  /*   { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ }, */
  /* }, */


const uint16_t PROGMEM fn_actions[] = {

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case M_WSS:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSHIFT) SS_TAP(X_4) SS_UP(X_LGUI) SS_UP(X_LSHIFT));
        _delay_ms(100);
        SEND_STRING(SS_TAP(X_SPACE));
      }
      return false;

    case DENUS:
      if (record->event.pressed) {
        SEND_STRING(":denunsia: ");
      }
      return false;

    case D_LINUX:
      if (record->event.pressed) {
        set_single_persistent_default_layer(LAYER_QWERTY_L);
      }
      return false;

    case D_MACOS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(LAYER_QWERTY_M);
      }
      return false;

    case STCH_EX:
      if (record->event.pressed) {
        layer_off(LAYER_KEBAB);
      }
      return false;
  }

  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_SPACE, KC_K) {
      layer_on(LAYER_KEBAB);
    }
  }
}

/* uint32_t layer_state_set_user(uint32_t state) { */
/*     switch (biton32(state)) { */
/*     case LAYER_QWERTY_L: */
/*     case LAYER_QWERTY_M: */
/*         rgblight_setrgb (0x4D,  0x19, 0x83); */
/*         break; */
/*     case LAYER_LOWER_L: */
/*     case LAYER_LOWER_M: */
/*         rgblight_setrgb (0x00,  0x8F, 0x60); */
/*         break; */
/*     case LAYER_RAISE_L: */
/*     case LAYER_RAISE_M: */
/*         rgblight_setrgb (0xF0,  0x78, 0x46); */
/*         break; */
/*     case LAYER_META: */
/*         rgblight_setrgb (0xFF,  0x00, 0x00); */
/*         break; */
/*     default: //  for any other layers, or the default layer */
/*         rgblight_setrgb (0x00,  0xFF, 0xFF); */
/*         break; */
/*     } */
/*   return state; */
/* } */
