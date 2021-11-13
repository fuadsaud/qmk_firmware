#include QMK_KEYBOARD_H

enum custom_keycodes {
  M_WSS = SAFE_RANGE,
  X_DENUS,
  X_PMAIL,
  X_WMAIL,
  D_I3,
  D_GNOME,
  D_MACOS,
};

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
#define G_ENTER KC_ENT
#define M_ENTER KC_ENT

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

#define G_PTT KC_F20
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
  /* i3 QWERTY LAYER
   *
   *                     ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                     │  `  │  1  │  2  │  3  │  4  │  5  │  ▶  │                 │LOCK │  6  │  7  │  8  │  9  │  0  │  \  │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │ TAB │  Q  │  W  │  E  │  R  │  T  │HOME │                 │PGUP │  Y  │  U  │  I  │  O  │  P  │  '  │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *      Tap for ESC -- │ CTL │  A  │  S  │  D  │  F  │  G  │ END │                 │PGDN │  H  │  J  │  K  │  L  │  ;  │  ↵  │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┐     ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *        Tap for ( ---│SHIFT│  Z  │  X  │  C  │  V  │  B  │VOL- │     │     │     │VOL+ │  N  │  M  │  ,  │  .  │  /  │SHIFT│--- Tap for )
   *                     ├─────┼─────┼─────┼─────┴─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┴─────┼─────┼─────┼─────┤
   *                     │LEADR│SUPER│ ALT │  CONTROL  │SUPER│LOWER│  ␣  │     │ ⌫   │RAISE│  ↵  │   HYPER   │ MEH │ PTT │META │
   *                     └─────┴─────┴─────┴───────────┴─────┴─────┴─────┘     └─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
   *                              |           |           |                                   |     |           |
   *                              |           |        Tap for -                         Tap for =  |           |
   *                              |           |                                                     |           |
   *                              |      Tap for [                                             Tap for ]        |
   *                              |                                                                             |
   *                     Tap for app launcher                                                              Tap for leader
   */

  [LAYER_QWERTY_I3] = LAYOUT(
    KC_GRV   , KC_1    , KC_2    , KC_3    , KC_4  , KC_5    , I_MPLY           ,           I_LOCK  , KC_6    , KC_7 , KC_8    , KC_9    , KC_0    , KC_BSLS,
    KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R  , KC_T    , KC_HOME          ,           KC_PGUP , KC_Y    , KC_U , KC_I    , KC_O    , KC_P    , KC_QUOT,
    LCTL_ESC , KC_A    , KC_S    , KC_D    , KC_F  , KC_G    , KC_END           ,           KC_PGDN , KC_H    , KC_J , KC_K    , KC_L    , KC_SCLN , G_ENTER,
    KC_LSPO  , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B    , G_VOLD           ,           G_VOLU  , KC_N    , KC_M , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC,
    KC_LEAD  , KC_LGUI , KC_LALT ,      I_C_BRO    , I_C_BRO , I_LOWER , KC_SPC , KC_BSPC , I_RAISE , HYP_BRC ,    HYP_BRC     , MEH_LEA , I_PTT   , META
  ),

  [LAYER_QWERTY_MACOS] = LAYOUT(
    KC_GRV   , KC_1    , KC_2    , KC_3    , KC_4  , KC_5    , M_MPLY           ,           M_LOCK  , KC_6    , KC_7 , KC_8    , KC_9    , KC_0    , KC_BSLS,
    KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R  , KC_T    , KC_HOME          ,           KC_PGUP , KC_Y    , KC_U , KC_I    , KC_O    , KC_P    , KC_QUOT,
    LCTL_ESC , KC_A    , KC_S    , KC_D    , KC_F  , KC_G    , KC_END           ,           KC_PGDN , KC_H    , KC_J , KC_K    , KC_L    , KC_SCLN , M_ENTER,
    KC_LSPO  , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B    , M_VOLD           ,           M_VOLU  , KC_N    , KC_M , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC,
    KC_LEAD  , KC_LGUI , KC_LALT ,      M_C_BRO    , M_C_BRO , M_LOWER , KC_SPC , KC_BSPC , M_RAISE , HYP_BRC ,    HYP_BRC     , MEH_LEA , M_PTT   , META
  ),

  /* LOWER LAYER
   *
   *                     ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                     │     │ F1  │ F2  │ F3  │ F4  │ F5  │MUTE │                 │PGUP │ F6  │ F7  │ F8  │ F9  │ F10 │  \  │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │  !  │  @  │  #  │  $  │  %  │     │                 │PGDN │  ^  │  &  │  *  │  (  │  )  │  '  │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │  ◌̀  │  ◌̂  │  ◌̧  │  ◌́  │  ◌̃  │     │                 │VOL+ │     │  {  │  }  │     │  |  │     │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┐     ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │     │     │     │PMAIL│WMAIL│♪ PRV│     │     │     │♪ NXT│     │  (  │  )  │     │  \  │     │
   *                     ├─────┼─────┼─────┼─────┴─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┴─────┼─────┼─────┼─────┤
   *                     │     │     │     │           │|||||│     │     │     │ DEL │     │     │           │     │     │     │
   *                     └─────┴─────┴─────┴───────────┴─────┴─────┴─────┘     └─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
   */

  [LAYER_LOWER_I3] = LAYOUT(
    _______  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , G_MUTE            ,           _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10    , I_SS    ,
    KC_TILD  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , _______           ,           _______ , I_WIN_L , I_WIN_D , I_WIN_U , I_WIN_R , I_WIN_MAX , I_WSS   ,
    _______  , G_GRAVE , G_CIRCU , G_CEDIL , G_ACUTE , G_TILDE , _______           ,           _______ , _______ , KC_LCBR , KC_RCBR , _______ , KC_PIPE   , I_SSS   ,
    _______  , _______ , _______ , _______ , X_PMAIL , X_WMAIL , I_MPRV            ,           I_MNXT  , _______ , KC_LPRN , KC_RPRN , _______ , KC_BSLS   , _______ ,
    _______  , _______ , _______ ,      _______      , _______ , _______ , _______ , KC_DEL  , _______ , _______ ,      _______      , _______ , _______   , _______
  ),

  /* RAISE LAYER
   *
   *                     ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                     │     │ F11 │ F12 │ F13 │ F14 │ F15 │MUTE │                 │     │ F16 │ F17 │ F18 │ F19 │ F20 │ SS  │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │     │WIN ←│WIN ↓│WIN ↑│WIN →│     │                 │     │     │W SWI│WSW P│WSW N│     │ SSS │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │     │MON ←│MON ↓│MON ↑│MON →│     │                 │     │  ←  │  ↓  │  ↑  │  →  │     │ WSS │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┐     ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │     │     │TAB ←│TAB →│     │♪ PRV│     │     │     │♪ NXT│     │BACK │ FWD │     │     │     │
   *                     ├─────┼─────┼─────┼─────┴─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┴─────┼─────┼─────┼─────┤
   *                     │     │     │     │           │     │     │     │     │     │     │|||||│           │     │     │     │
   *                     └─────┴─────┴─────┴───────────┴─────┴─────┴─────┘     └─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
   */

  [LAYER_RAISE_I3] = LAYOUT(
    _______  , KC_F11  , KC_F12  , KC_F13  , KC_F14  , KC_F15  , G_MUTE            ,           _______ , KC_F16  , KC_F17  , KC_F18  , KC_F19   , KC_F20    , I_SS    ,
    _______  , I_WMV_L , I_WMV_D , I_WMV_U , I_WMV_R , _______ , _______           ,           _______ , I_WIN_L , I_WIN_D , I_WIN_U , I_WIN_R  , I_WIN_MAX , I_WSS   ,
    _______  , I_MON_L , I_MON_D , I_MON_U , I_MON_R , _______ , _______           ,           _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______   , I_SSS   ,
    _______  , _______ , _______ , G_GLEFT , G_GRIGH , _______ , I_MPRV            ,           I_MNXT  , _______ , G_BACK  , G_FRWD  , _______  , _______   , _______ ,
    _______  , _______ , _______ ,      _______      , _______ , _______ , _______ , _______ , _______ , _______ ,      _______      , _______  , _______   , _______
  ),

  /* META LAYER
   *
   *                     ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                     │RESET│     │     │RGBPM│RGBPM│     │     │                 │     │     │     │     │     │     │     │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │     │RGBTG│VAL -│VAL +│     │     │                 │     │     │BLINC│BLDEC│BL TG│     │  '  │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │     │     │HUE -│HUE +│     │     │                 │     │     │     │     │     │     │     │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┐     ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │     │     │SAT -│SAT +│     │     │     │     │     │     │     │     │     │     │     │     │
   *                     ├─────┼─────┼─────┼─────┴─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┴─────┼─────┼─────┼─────┤
   *                     │     │     │     │           │     │     │     │     │     │     │     │           │     │     │     │
   *                     └─────┴─────┴─────┴───────────┴─────┴─────┴─────┘     └─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
   */
  [LAYER_META] = LAYOUT(
    RESET    , _______ , _______ , RGB_RMOD, RGB_MOD , _______ , _______           ,           _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
    _______  , _______ , RGB_TOG , RGB_VAD , RGB_VAI , _______ , _______           ,           _______ , _______ , BL_DEC  , BL_INC  , BL_TOGG  , _______ , _______ ,
    _______  , _______ , _______ , RGB_HUD , RGB_HUI , _______ , _______           ,           _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
    _______  , _______ , _______ , RGB_SAD , RGB_SAI , _______ , _______           ,           _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
    _______  , _______ , _______ ,      _______      , _______ , _______ , _______ , _______ , _______ , _______ ,      _______      , _______  , _______ , _______
  )
};

  /* LAYER TEMPLATE
   *
   *                     ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                     │     │     │     │     │     │     │     │                 │     │     │     │     │     │     │     │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │     │     │     │     │     │     │                 │     │     │     │     │     │     │  '  │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │     │     │     │     │     │     │                 │     │     │     │     │     │     │     │
   *                     ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┐     ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   *                     ├─────┼─────┼─────┼─────┴─────┼─────┼─────┤     │     │     ├─────┼─────┼─────┴─────┼─────┼─────┼─────┤
   *                     │     │     │     │           │     │     │     │     │     │     │     │           │     │     │     │
   *                     └─────┴─────┴─────┴───────────┴─────┴─────┴─────┘     └─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
   */

  /*
   *
   * [LAYER_TRANSPARENT_TEMPLATE] = LAYOUT(
   *   _______  , _______ , _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
   *   _______  , _______ , _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
   *   _______  , _______ , _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
   *   _______  , _______ , _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______  , _______ , _______ ,
   *   _______  , _______ , _______ ,      _______      , _______ , _______ , _______ , _______ , _______ , _______ ,      _______      , _______  , _______ , _______
   * ),
   */

  /*
   * [LAYER_NOOP_TEMPLATE] = LAYOUT(
   *   ___x___  , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___           ,           ___x___ , ___x___ , ___x___ , ___x___ , ___x___  , ___x___ , ___x___ ,
   *   ___x___  , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___           ,           ___x___ , ___x___ , ___x___ , ___x___ , ___x___  , ___x___ , ___x___ ,
   *   ___x___  , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___           ,           ___x___ , ___x___ , ___x___ , ___x___ , ___x___  , ___x___ , ___x___ ,
   *   ___x___  , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___           ,           ___x___ , ___x___ , ___x___ , ___x___ , ___x___  , ___x___ , ___x___ ,
   *   ___x___  , ___x___ , ___x___ ,      ___x___      , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ , ___x___ ,      ___x___      , ___x___  , ___x___ , ___x___
   * ),
   */

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
  }
  return true;
}
