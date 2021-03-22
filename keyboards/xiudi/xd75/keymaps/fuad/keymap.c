/* Copyright 2017 Fuad Saud
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
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
  LAYER_QWERTY_I3,
  LAYER_LOWER_I3,
  LAYER_RAISE_I3,
  LAYER_QWERTY_GNOME,
  LAYER_LOWER_GNOME,
  LAYER_RAISE_GNOME,
  LAYER_QWERTY_MACOS,
  LAYER_LOWER_MACOS,
  LAYER_RAISE_MACOS,
  LAYER_META
};

enum user_keycodes {
  M_WSS = SAFE_RANGE,
  X_PMAIL,
  X_WMAIL,
  D_I3,
  D_GNOME,
  D_MACOS,
};

// aliases
#define ___x___ KC_NO

// layer switching
#define G_LOWER LT(LAYER_LOWER_GNOME, KC_UNDERSCORE)
#define G_RAISE LT(LAYER_RAISE_GNOME, KC_EQUAL)
#define I_LOWER LT(LAYER_LOWER_I3, KC_UNDERSCORE)
#define I_RAISE LT(LAYER_RAISE_I3, KC_EQUAL)
#define M_LOWER LT(LAYER_LOWER_MACOS, KC_UNDERSCORE)
#define M_RAISE LT(LAYER_RAISE_MACOS, KC_EQUAL)
#define META MO(LAYER_META)

// mod-tap
#define LCTL_ESC LCTL_T(KC_ESC)
#define G_ENTER LGUI_T(KC_ENT)
#define M_ENTER LCMD_T(KC_ENT)

#define G_C_BRO LCTL_T(KC_LBRC)
#define I_C_BRO LGUI_T(KC_LBRC)
#define M_C_BRO LCMD_T(KC_LBRC)
#define MEH_LEA MEH(KC_LEAD)
#define HYP_BRC HYPR_T(KC_RBRC)
#define GUI_BRC LGUI_T(KC_RBRC)

// app launcher
#define G_LNCHR KC_LGUI
#define I_LNCHR LGUI(KC_D)
#define M_LNCHR LCMD(KC_SPC)

// misc
#define G_SS  KC_PSCREEN
#define G_WSS LALT(KC_PSCREEN)
#define G_SSS LSFT(KC_PSCREEN)
#define I_SS  KC_PSCREEN
#define I_WSS LALT(KC_PSCREEN)
#define I_SSS LSFT(KC_PSCREEN)
#define M_SS  LCMD(LSFT(KC_3))
#define M_SSS LCMD(LSFT(KC_4))

#define G_SPC KC_SPC
#define G_BSP KC_BSPC
#define I_SPC KC_SPC
#define I_BSP KC_BSPC
#define M_SPC KC_SPC
#define M_BSP KC_BSPC

#define G_BACK LALT(KC_LEFT)
#define G_FRWD LALT(KC_RIGHT)
#define M_BACK LCMD(KC_LEFT)
#define M_FRWD LCMD(KC_RIGHT)

#define G_GLEFT LCTL(LSFT(KC_TAB))
#define G_GRIGH LCTL(KC_TAB)
#define M_GLEFT LCMD(LSFT(KC_LBRC))
#define M_GRIGH LCMD(LSFT(KC_RBRC))

#define G_LOCK LGUI(KC_L)
#define I_LOCK LGUI(KC_BSLS)
#define M_LOCK LCTL(LSFT(KC_POWER))

#define G_VOLD KC_VOLD
#define G_VOLU KC_VOLU
#define G_MUTE KC_MUTE
#define M_VOLD KC__VOLDOWN
#define M_VOLU KC__VOLUP
#define M_MUTE KC__MUTE

#define G_MPLY LALT(KC_MPLY)
#define G_MNXT LALT(KC_MNXT)
#define G_MPRV LALT(KC_MPRV)
#define I_MPLY KC_MPLY
#define I_MNXT KC_MNXT
#define I_MPRV KC_MPRV
#define M_MPLY KC_MPLY
#define M_MNXT KC_MFFD
#define M_MPRV KC_MRWD

#define G_PTT LGUI(KC_BSLS)
#define I_PTT KC_F20
#define M_PTT ___x___

// diacritics
#define G_GRAVE RALT(KC_GRV)
#define G_ACUTE RALT(KC_QUOT)
#define G_TILDE RALT(KC_TILDE)
#define G_CIRCU RALT(KC_CIRCUMFLEX)
#define G_CEDIL RALT(KC_COMM)
#define M_GRAVE LALT(KC_GRV)
#define M_ACUTE LALT(KC_E)
#define M_TILDE LALT(KC_N)
#define M_CIRCU LALT(KC_I)
#define M_CEDIL LALT(KC_C)

// window management
#define I_WIN_L LGUI(KC_LEFT)
#define I_WIN_R LGUI(KC_RIGHT)
#define I_WIN_U LGUI(KC_UP)
#define I_WIN_D LGUI(KC_DOWN)

#define G_WIN_MAX LGUI(KC_UP)
#define G_WIN_RST LGUI(KC_DOWN)
#define I_WIN_MAX LGUI(KC_F)
#define I_WIN_RST LGUI(KC_F)
#define M_WIN_MAX LCMD(LALT(KC_F))
#define M_WIN_RST LCTL(LALT(KC_BSPC))

#define G_WMV_L LGUI(KC_LEFT)
#define G_WMV_R LGUI(KC_RIGHT)
#define I_WMV_L SGUI(KC_LEFT)
#define I_WMV_R SGUI(KC_RIGHT)
#define I_WMV_U SGUI(KC_UP)
#define I_WMV_D SGUI(KC_DOWN)
#define M_WMV_L LCMD(LALT(KC_LEFT))
#define M_WMV_R LCMD(LALT(KC_RIGHT))

#define G_MON_L SGUI(KC_LEFT)
#define G_MON_D SGUI(KC_DOWN)
#define G_MON_U SGUI(KC_UP)
#define G_MON_R SGUI(KC_RIGHT)
#define I_MON_L HYPR(KC_LEFT)
#define I_MON_D HYPR(KC_DOWN)
#define I_MON_U HYPR(KC_UP)
#define I_MON_R HYPR(KC_RIGHT)
#define M_MON_L LCAG(KC_LEFT)
#define M_MON_D XXXXXXX
#define M_MON_U XXXXXXX
#define M_MON_R LCAG(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* GNOME QWERTY LAYER
   *
   *                              ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                              │  `  │  1  │  2  │  3  │  4  │  5  │  -  │ ESC │  =  │  6  │  7  │  8  │  9  │  0  │  \  │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │ TAB │  Q  │  W  │  E  │  R  │  T  │  {  │  \  │  }  │  Y  │  U  │  I  │  O  │  P  │  '  │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *               Tap for ESC -- │ CTL │  A  │  S  │  D  │  F  │  G  │HOME │LOCK │PGUP │  H  │  J  │  K  │  L  │  ;  │SUPER│ -- Tap for ↵
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 Tap for ( ---│SHIFT│  Z  │  X  │  C  │  V  │  B  │ END │ MUT │PGDN │  N  │  M  │  ,  │  .  │  /  │SHIFT│--- Tap for )
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │LEADR│SUPER│ ALT │ CTL │LOWER│  ␣  │VOL -│  ▶  │VOL +│  ⌫  │RAISE│ HYP │ MEH │ PTT │ MET │
   *                              └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                                       |           |     |                                   |     |     |
   *                                       |           |  Tap for -                         Tap for =  |     |
   *                                       |           |                                               |     |
   *                                       |      Tap for [                                       Tap for ]  |
   *                                       |                                                                 |
   *                              Tap for app launcher                                                  Tap for leader
   */

  /* i3 QWERTY LAYER
   *
   *                              ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                              │  `  │  1  │  2  │  3  │  4  │  5  │  -  │ ESC │  =  │  6  │  7  │  8  │  9  │  0  │  \  │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │ TAB │  Q  │  W  │  E  │  R  │  T  │  {  │  \  │  }  │  Y  │  U  │  I  │  O  │  P  │  '  │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *               Tap for ESC -- │ CTL │  A  │  S  │  D  │  F  │  G  │HOME │LOCK │PGUP │  H  │  J  │  K  │  L  │  ;  │SUPER│ -- Tap for ↵
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 Tap for ( ---│SHIFT│  Z  │  X  │  C  │  V  │  B  │ END │ MUT │PGDN │  N  │  M  │  ,  │  .  │  /  │SHIFT│--- Tap for )
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │LEADR│SUPER│ ALT │ CTL │LOWER│  ␣  │VOL -│  ▶  │VOL +│  ⌫  │RAISE│ HYP │ MEH │ PTT │ MET │
   *                              └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                                       |           |     |                                   |     |     |
   *                                       |           |  Tap for -                         Tap for =  |     |
   *                                       |           |                                               |     |
   *                                       |      Tap for [                                       Tap for ]  |
   *                                       |                                                                 |
   *                              Tap for app launcher                                                  Tap for leader
   */

  /* MACOS QWERTY LAYER
   *
   *                              ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                              │  `  │  1  │  2  │  3  │  4  │  5  │  -  │ ESC │  =  │  6  │  7  │  8  │  9  │  0  │  \  │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  {  │  \  │  }  │  Y  │  U  │  I  │  O  │  P  │  '  │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *               Tap for ESC ---│  ⌃  │  A  │  S  │  D  │  F  │  G  │  ↖  │LOCK │  ⇞  │  H  │  J  │  K  │  L  │  ;  │  ⌘  │--- Tap for ↵
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 Tap for ( ---│  ⇧  │  Z  │  X  │  C  │  V  │  B  │  ↘  │ MUT │  ⇟  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │--- Tap for )
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │LEADR│LNCHR│  ⌥  │  ⌘  │LOWER│  ␣  │VOL -│  ▶  │VOL +│  ⌫  │RAISE│ HYP │ MEH │ PTT │ MET │
   *                              └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                                                   |     |                                   |     |     |
   *                                                   |  Tap for -                         Tap for =  |     |
   *                                                   |                                               |     |
   *                                              Tap for [                                       Tap for ]  |
   *                                                                                                         |
   *                                                                                                    Tap for leader
   */

  [LAYER_QWERTY_GNOME] = {
    { KC_GRV   , KC_1    , KC_2    , KC_3    , KC_4    , KC_5  , KC_MINS , KC_ESC  , KC_EQL  , KC_6  , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS },
    { KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T  , KC_LBRC , KC_BSLS , KC_RBRC , KC_Y  , KC_U    , KC_I    , KC_O    , KC_P    , KC_QUOT },
    { LCTL_ESC , KC_A    , KC_S    , KC_D    , KC_F    , KC_G  , KC_HOME , G_LOCK  , KC_PGUP , KC_H  , KC_J    , KC_K    , KC_L    , KC_SCLN , G_ENTER },
    { KC_LSPO  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B  , KC_END  , G_MUTE  , KC_PGDN , KC_N  , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC },
    { KC_LEAD  , G_LNCHR , KC_LALT , G_C_BRO , G_LOWER , G_SPC , G_VOLD  , G_MPLY  , G_VOLU  , G_BSP , G_RAISE , HYP_BRC , MEH_LEA , G_PTT   , META    },
  },

  [LAYER_QWERTY_I3] = {
    { KC_GRV   , KC_1    , KC_2    , KC_3    , KC_4    , KC_5  , KC_MINS , KC_ESC  , KC_EQL  , KC_6  , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS },
    { KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T  , KC_LBRC , KC_BSLS , KC_RBRC , KC_Y  , KC_U    , KC_I    , KC_O    , KC_P    , KC_QUOT },
    { LCTL_ESC , KC_A    , KC_S    , KC_D    , KC_F    , KC_G  , KC_HOME , I_LOCK  , KC_PGUP , KC_H  , KC_J    , KC_K    , KC_L    , KC_SCLN , G_ENTER },
    { KC_LSPO  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B  , KC_END  , G_MUTE  , KC_PGDN , KC_N  , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC },
    { KC_LEAD  , KC_LGUI , KC_LALT , I_C_BRO , I_LOWER , I_SPC , G_VOLD  , I_MPLY  , G_VOLU  , I_BSP , I_RAISE , GUI_BRC , MEH_LEA , I_PTT   , META    },
  },

  [LAYER_QWERTY_MACOS] = {
    { KC_GRV   , KC_1    , KC_2    , KC_3    , KC_4    , KC_5  , KC_MINS , KC_ESC  , KC_EQL  , KC_6  , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS },
    { KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T  , KC_LBRC , KC_BSLS , KC_RBRC , KC_Y  , KC_U    , KC_I    , KC_O    , KC_P    , KC_QUOT },
    { LCTL_ESC , KC_A    , KC_S    , KC_D    , KC_F    , KC_G  , KC_HOME , M_LOCK  , KC_PGUP , KC_H  , KC_J    , KC_K    , KC_L    , KC_SCLN , M_ENTER },
    { KC_LSPO  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B  , KC_END  , M_MUTE  , KC_PGDN , KC_N  , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC },
    { KC_LEAD  , M_LNCHR , KC_LALT , M_C_BRO , M_LOWER , M_SPC , M_VOLD  , M_MPLY  , M_VOLU  , M_BSP , M_RAISE , HYP_BRC , MEH_LEA , M_PTT   , META    },
  },

  /* RAISE LAYER
   *
   *                              ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                              │     │ F11 │ F12 │ F13 │ F14 │ F15 │     │     │     │ F16 │ F17 │ F18 │ F19 │ F20 │ SS  │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │WIN ←│WIN ↓│WIN ↑│WIN →│     │     │     │     │W SWI│WSW P│WSW N│     │ SSS │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │MON ←│MON ↓│MON ↑│MON →│TAB ←│     │TAB →│  ←  │  ↓  │  ↑  │  →  │     │ WSS │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │TAB ←│TAB →│     │GUI ←│BRIG+│GUI →│     │GUI ←│GUI →│     │     │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │     │     │LNCHR│♪ PRV│BRIG-│♪ NXT│     │|||||│     │     │     │     │
   *                              └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *
   */

  [LAYER_RAISE_GNOME] = {
    { _______ , KC_F11  , KC_F12    , KC_F13    , KC_F14  , KC_F15  , _______ , _______ , _______ , KC_F16  , KC_F17  , KC_F18  , KC_F19   , KC_F20  , G_SS    },
    { _______ , G_WMV_L , G_WIN_RST , G_WIN_MAX , G_WMV_R , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , G_WSS   },
    { _______ , G_MON_L , G_MON_D   , G_MON_U   , G_MON_R , _______ , G_GLEFT , _______ , G_GRIGH , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______ , G_SSS   },
    { _______ , _______ , _______   , G_GLEFT   , G_GRIGH , _______ , G_BACK  , ___x___ , G_FRWD  , _______ , G_BACK  , G_FRWD  , _______  , _______ , _______ },
    { _______ , _______ , _______   , _______   , _______ , G_LNCHR , G_MPRV  , _______ , G_MNXT  , _______ , _______ , _______ , _______  , _______ , _______ },
  },

  [LAYER_RAISE_I3] = {
    { _______ , KC_F11  , KC_F12    , KC_F13    , KC_F14  , KC_F15  , _______ , _______ , _______ , KC_F16    , KC_F17  , KC_F18  , KC_F19   , KC_F20    , I_SS    },
    { _______ , I_WMV_L , I_WMV_D   , I_WMV_U   , I_WMV_R , _______ , _______ , _______ , _______ , I_WIN_L   , I_WIN_D , I_WIN_U , I_WIN_R  , I_WIN_MAX , I_WSS   },
    { _______ , I_MON_L , I_MON_D   , I_MON_U   , I_MON_R , _______ , G_GLEFT , _______ , G_GRIGH , KC_LEFT   , KC_DOWN , KC_UP   , KC_RIGHT , _______   , I_SSS   },
    { _______ , _______ , _______   , G_GLEFT   , G_GRIGH , _______ , G_BACK  , ___x___ , G_FRWD  , _______   , G_BACK  , G_FRWD  , _______  , _______   , _______ },
    { _______ , _______ , _______   , _______   , _______ , I_LNCHR , I_MPRV  , _______ , I_MNXT  , KC_INSERT , _______ , _______ , _______  , _______   , _______ },
  },

  [LAYER_RAISE_MACOS] = {
    { _______ , KC_F11  , KC_F12    , KC_F13    , KC_F14  , KC_F15  , _______ , _______ , _______ , KC_F16  , KC_F17  , KC_F18  , KC_F19   , KC_F20  , M_SS    },
    { _______ , M_WMV_L , M_WIN_RST , M_WIN_MAX , M_WMV_R , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , M_SSS   , M_WSS   },
    { _______ , M_MON_L , M_MON_D   , M_MON_U   , M_MON_R , _______ , M_GLEFT , _______ , M_GRIGH , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______ , _______ },
    { _______ , _______ , _______   , M_GLEFT   , M_GRIGH , _______ , M_BACK  , KC_PAUS , M_FRWD  , _______ , M_BACK  , M_FRWD  , _______  , _______ , _______ },
    { _______ , _______ , _______   , _______   , _______ , M_LNCHR , M_MPRV  , KC_SLCK , M_MNXT  , _______ , _______ , _______ , _______  , _______ , _______ },
  },


  /* LOWER LAYER
   *
   *                              ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                              │     │ F1  │ F2  │ F3  │ F4  │ F5  │     │     │     │ F6  │ F7  │ F8  │ F9  │ F10 │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │  !  │  @  │  #  │  $  │  %  │     │     │     │  ^  │  &  │  *  │  (  │  )  │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │  ◌̀  │  ◌̂  │  ◌̧  │  ◌́  │  ◌̃  │TAB ←│BRIG+│TAB →│     │  {  │  }  │     │  |  │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │     │PMAIL│WMAIL│GUI ←│BRIG-│GUI →│     │  (  │  )  │     │  \  │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │     │|||||│     │     │     │     │ ⌦   │     │     │     │     │     │
   *                              └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *
   */

  [LAYER_LOWER_GNOME] = {
    { _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ , _______ , _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , _______ },
    { KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , _______ , _______ , _______ , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______ },
    { _______ , G_GRAVE , G_CIRCU , G_CEDIL , G_ACUTE , G_TILDE , G_GLEFT , _______ , G_GRIGH , _______ , KC_LCBR , KC_RCBR , _______ , KC_PIPE , _______ },
    { _______ , _______ , _______ , _______ , X_PMAIL , X_WMAIL , G_BACK  , _______ , G_FRWD  , _______ , KC_LPRN , KC_RPRN , _______ , KC_BSLS , _______ },
    { _______ , _______ , _______ , _______ , _______ , _______ , G_MPRV  , _______ , G_MNXT  , KC_DEL  , _______ , _______ , _______ , _______ , _______ },
  },

  [LAYER_LOWER_I3] = {
    { _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ , _______ , _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , _______ },
    { KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , _______ , _______ , _______ , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______ },
    { _______ , G_GRAVE , G_CIRCU , G_CEDIL , G_ACUTE , G_TILDE , G_GLEFT , _______ , G_GRIGH , _______ , KC_LCBR , KC_RCBR , _______ , KC_PIPE , _______ },
    { _______ , _______ , _______ , _______ , X_PMAIL , X_WMAIL , G_BACK  , _______ , G_FRWD  , _______ , KC_LPRN , KC_RPRN , _______ , KC_BSLS , _______ },
    { _______ , _______ , _______ , _______ , _______ , _______ , I_MPRV  , _______ , I_MNXT  , KC_DEL  , _______ , _______ , _______ , _______ , _______ },
  },

  [LAYER_LOWER_MACOS] = {
    { _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ , _______ , _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , _______ },
    { KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , _______ , _______ , _______ , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______ },
    { _______ , G_GRAVE , G_CIRCU , G_CEDIL , G_ACUTE , G_TILDE , M_GLEFT , _______ , M_GRIGH , _______ , KC_LCBR , KC_RCBR , _______ , KC_PIPE , _______ },
    { _______ , _______ , _______ , _______ , X_PMAIL , X_WMAIL , M_BACK  , _______ , _______ , _______ , KC_LPRN , KC_RPRN , _______ , KC_BSLS , _______ },
    { _______ , _______ , _______ , _______ , _______ , _______ , M_MPRV  , _______ , M_MNXT  , KC_DEL  , _______ , _______ , _______ , _______ , _______ },
  },


  /* META LAYER
   *
   *                              ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                              │     │     │     │     │     │     │     │RESET│     │     │     │     │     │     │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │     │     │     │     │DEBUG│     │     │     │ I3  │     │     │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │     │     │GNOME│RGBHI│RGBSI│RGBVI│     │     │     │     │     │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │     │     │     │RGBHD│RGBSI│RGBVD│     │MACOS│     │     │     │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │     │     │     │RGBPM│RGBTG│RGBNM│     │     │     │     │     │|||||│
   *                              └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *
   */

  [LAYER_META] = {
    { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___  , RESET   , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ },
    { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___  , DEBUG   , ___x___ , ___x___ , ___x___ , D_I3    , ___x___ , ___x___ , ___x___ },
    { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , D_GNOME , RGB_HUI  , RGB_SAI , RGB_VAI , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ },
    { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , RGB_HUD  , RGB_SAD , RGB_VAD , ___x___ , D_MACOS , ___x___ , ___x___ , ___x___ , ___x___ },
    { ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , RGB_RMOD , RGB_TOG , RGB_MOD , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ },
  }
};

  /* TEMPLATE LAYER
   *
   *                              ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                              │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                              ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                              │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                              └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
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

    case X_PMAIL:
      if (record->event.pressed) {
        SEND_STRING("fuadfsaud@gmail.com");
      }
      return false;

    case X_WMAIL:
      if (record->event.pressed) {
        SEND_STRING("fuad.saud@nubank.com.br");
      }
      return false;

    case D_GNOME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(LAYER_QWERTY_GNOME);
      }
      return false;

    case D_I3:
      if (record->event.pressed) {
        set_single_persistent_default_layer(LAYER_QWERTY_I3);
      }
      return false;

    case D_MACOS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(LAYER_QWERTY_MACOS);
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
  }
}

/* uint32_t layer_state_set_user(uint32_t state) { */
/*     switch (biton32(state)) { */
/*     case LAYER_QWERTY_GNOME: */
/*     case LAYER_QWERTY_MACOS: */
/*         rgblight_setrgb (0x4D,  0x19, 0x83); */
/*         break; */
/*     case LAYER_LOWER_GNOME: */
/*     case LAYER_LOWER_MACOS: */
/*         rgblight_setrgb (0x00,  0x8F, 0x60); */
/*         break; */
/*     case LAYER_RAISE_L: */
/*     case LAYER_RAISE_MACOS: */
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
