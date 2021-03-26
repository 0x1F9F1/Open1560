/*
    Open1560 - An Open Source Re-Implementation of Midtown Madness 1 Beta
    Copyright (C) 2020 Brick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// clang-format off

// Keyboard Scan Codes (Matches DIK_*)

#define EQ_KEY_ESCAPE          0x01
#define EQ_KEY_1               0x02
#define EQ_KEY_2               0x03
#define EQ_KEY_3               0x04
#define EQ_KEY_4               0x05
#define EQ_KEY_5               0x06
#define EQ_KEY_6               0x07
#define EQ_KEY_7               0x08
#define EQ_KEY_8               0x09
#define EQ_KEY_9               0x0A
#define EQ_KEY_0               0x0B
#define EQ_KEY_MINUS           0x0C    /* - on main keyboard */
#define EQ_KEY_EQUALS          0x0D
#define EQ_KEY_BACK            0x0E    /* backspace */
#define EQ_KEY_TAB             0x0F
#define EQ_KEY_Q               0x10
#define EQ_KEY_W               0x11
#define EQ_KEY_E               0x12
#define EQ_KEY_R               0x13
#define EQ_KEY_T               0x14
#define EQ_KEY_Y               0x15
#define EQ_KEY_U               0x16
#define EQ_KEY_I               0x17
#define EQ_KEY_O               0x18
#define EQ_KEY_P               0x19
#define EQ_KEY_LBRACKET        0x1A
#define EQ_KEY_RBRACKET        0x1B
#define EQ_KEY_RETURN          0x1C    /* Enter on main keyboard */
#define EQ_KEY_LCONTROL        0x1D
#define EQ_KEY_A               0x1E
#define EQ_KEY_S               0x1F
#define EQ_KEY_D               0x20
#define EQ_KEY_F               0x21
#define EQ_KEY_G               0x22
#define EQ_KEY_H               0x23
#define EQ_KEY_J               0x24
#define EQ_KEY_K               0x25
#define EQ_KEY_L               0x26
#define EQ_KEY_SEMICOLON       0x27
#define EQ_KEY_APOSTROPHE      0x28
#define EQ_KEY_GRAVE           0x29    /* accent grave */
#define EQ_KEY_LSHIFT          0x2A
#define EQ_KEY_BACKSLASH       0x2B
#define EQ_KEY_Z               0x2C
#define EQ_KEY_X               0x2D
#define EQ_KEY_C               0x2E
#define EQ_KEY_V               0x2F
#define EQ_KEY_B               0x30
#define EQ_KEY_N               0x31
#define EQ_KEY_M               0x32
#define EQ_KEY_COMMA           0x33
#define EQ_KEY_PERIOD          0x34    /* . on main keyboard */
#define EQ_KEY_SLASH           0x35    /* / on main keyboard */
#define EQ_KEY_RSHIFT          0x36
#define EQ_KEY_MULTIPLY        0x37    /* * on numeric keypad */
#define EQ_KEY_LMENU           0x38    /* left Alt */
#define EQ_KEY_SPACE           0x39
#define EQ_KEY_CAPITAL         0x3A
#define EQ_KEY_F1              0x3B
#define EQ_KEY_F2              0x3C
#define EQ_KEY_F3              0x3D
#define EQ_KEY_F4              0x3E
#define EQ_KEY_F5              0x3F
#define EQ_KEY_F6              0x40
#define EQ_KEY_F7              0x41
#define EQ_KEY_F8              0x42
#define EQ_KEY_F9              0x43
#define EQ_KEY_F10             0x44
#define EQ_KEY_NUMLOCK         0x45
#define EQ_KEY_SCROLL          0x46    /* Scroll Lock */
#define EQ_KEY_NUMPAD7         0x47
#define EQ_KEY_NUMPAD8         0x48
#define EQ_KEY_NUMPAD9         0x49
#define EQ_KEY_SUBTRACT        0x4A    /* - on numeric keypad */
#define EQ_KEY_NUMPAD4         0x4B
#define EQ_KEY_NUMPAD5         0x4C
#define EQ_KEY_NUMPAD6         0x4D
#define EQ_KEY_ADD             0x4E    /* + on numeric keypad */
#define EQ_KEY_NUMPAD1         0x4F
#define EQ_KEY_NUMPAD2         0x50
#define EQ_KEY_NUMPAD3         0x51
#define EQ_KEY_NUMPAD0         0x52
#define EQ_KEY_DECIMAL         0x53    /* . on numeric keypad */
#define EQ_KEY_OEM_102         0x56    /* <> or \| on RT 102-key keyboard (Non-U.S.) */
#define EQ_KEY_F11             0x57
#define EQ_KEY_F12             0x58
#define EQ_KEY_F13             0x64    /*                     (NEC PC98) */
#define EQ_KEY_F14             0x65    /*                     (NEC PC98) */
#define EQ_KEY_F15             0x66    /*                     (NEC PC98) */
#define EQ_KEY_KANA            0x70    /* (Japanese keyboard)            */
#define EQ_KEY_ABNT_C1         0x73    /* /? on Brazilian keyboard */
#define EQ_KEY_CONVERT         0x79    /* (Japanese keyboard)            */
#define EQ_KEY_NOCONVERT       0x7B    /* (Japanese keyboard)            */
#define EQ_KEY_YEN             0x7D    /* (Japanese keyboard)            */
#define EQ_KEY_ABNT_C2         0x7E    /* Numpad . on Brazilian keyboard */
#define EQ_KEY_NUMPADEQUALS    0x8D    /* = on numeric keypad (NEC PC98) */
#define EQ_KEY_PREVTRACK       0x90    /* Previous Track (EQ_KEY_CIRCUMFLEX on Japanese keyboard) */
#define EQ_KEY_AT              0x91    /*                     (NEC PC98) */
#define EQ_KEY_COLON           0x92    /*                     (NEC PC98) */
#define EQ_KEY_UNDERLINE       0x93    /*                     (NEC PC98) */
#define EQ_KEY_KANJI           0x94    /* (Japanese keyboard)            */
#define EQ_KEY_STOP            0x95    /*                     (NEC PC98) */
#define EQ_KEY_AX              0x96    /*                     (Japan AX) */
#define EQ_KEY_UNLABELED       0x97    /*                        (J3100) */
#define EQ_KEY_NEXTTRACK       0x99    /* Next Track */
#define EQ_KEY_NUMPADENTER     0x9C    /* Enter on numeric keypad */
#define EQ_KEY_RCONTROL        0x9D
#define EQ_KEY_MUTE            0xA0    /* Mute */
#define EQ_KEY_CALCULATOR      0xA1    /* Calculator */
#define EQ_KEY_PLAYPAUSE       0xA2    /* Play / Pause */
#define EQ_KEY_MEDIASTOP       0xA4    /* Media Stop */
#define EQ_KEY_VOLUMEDOWN      0xAE    /* Volume - */
#define EQ_KEY_VOLUMEUP        0xB0    /* Volume + */
#define EQ_KEY_WEBHOME         0xB2    /* Web home */
#define EQ_KEY_NUMPADCOMMA     0xB3    /* , on numeric keypad (NEC PC98) */
#define EQ_KEY_DIVIDE          0xB5    /* / on numeric keypad */
#define EQ_KEY_SYSRQ           0xB7
#define EQ_KEY_RMENU           0xB8    /* right Alt */
#define EQ_KEY_PAUSE           0xC5    /* Pause */
#define EQ_KEY_HOME            0xC7    /* Home on arrow keypad */
#define EQ_KEY_UP              0xC8    /* UpArrow on arrow keypad */
#define EQ_KEY_PRIOR           0xC9    /* PgUp on arrow keypad */
#define EQ_KEY_LEFT            0xCB    /* LeftArrow on arrow keypad */
#define EQ_KEY_RIGHT           0xCD    /* RightArrow on arrow keypad */
#define EQ_KEY_END             0xCF    /* End on arrow keypad */
#define EQ_KEY_DOWN            0xD0    /* DownArrow on arrow keypad */
#define EQ_KEY_NEXT            0xD1    /* PgDn on arrow keypad */
#define EQ_KEY_INSERT          0xD2    /* Insert on arrow keypad */
#define EQ_KEY_DELETE          0xD3    /* Delete on arrow keypad */
#define EQ_KEY_LWIN            0xDB    /* Left Windows key */
#define EQ_KEY_RWIN            0xDC    /* Right Windows key */
#define EQ_KEY_APPS            0xDD    /* AppMenu key */
#define EQ_KEY_POWER           0xDE    /* System Power */
#define EQ_KEY_SLEEP           0xDF    /* System Sleep */
#define EQ_KEY_WAKE            0xE3    /* System Wake */
#define EQ_KEY_WEBSEARCH       0xE5    /* Web Search */
#define EQ_KEY_WEBFAVORITES    0xE6    /* Web Favorites */
#define EQ_KEY_WEBREFRESH      0xE7    /* Web Refresh */
#define EQ_KEY_WEBSTOP         0xE8    /* Web Stop */
#define EQ_KEY_WEBFORWARD      0xE9    /* Web Forward */
#define EQ_KEY_WEBBACK         0xEA    /* Web Back */
#define EQ_KEY_MYCOMPUTER      0xEB    /* My Computer */
#define EQ_KEY_MAIL            0xEC    /* Mail */
#define EQ_KEY_MEDIASELECT     0xED    /* Media Select */

#define EQ_KMOD_DOWN   0x1
#define EQ_KMOD_SHIFT  0x2
#define EQ_KMOD_CTRL   0x4
#define EQ_KMOD_ALT    0x8
#define EQ_KMOD_REPEAT 0x10 // NEW

#define EQ_BUTTON_LEFT          0x1
#define EQ_BUTTON_RIGHT         0x2
#define EQ_BUTTON_MIDDLE        0x4
#define EQ_BUTTON_WHEEL_UP      0x8
#define EQ_BUTTON_WHEEL_DOWN    0x10

/*
 * Virtual Keys, Standard Set
 */

#define EQ_VK_LBUTTON        0x01
#define EQ_VK_RBUTTON        0x02
#define EQ_VK_CANCEL         0x03
#define EQ_VK_MBUTTON        0x04    /* NOT contiguous with L & RBUTTON */

#define EQ_VK_XBUTTON1       0x05    /* NOT contiguous with L & RBUTTON */
#define EQ_VK_XBUTTON2       0x06    /* NOT contiguous with L & RBUTTON */

/*
 * 0x07 : reserved
 */


#define EQ_VK_BACK           0x08
#define EQ_VK_TAB            0x09

/*
 * 0x0A - 0x0B : reserved
 */

#define EQ_VK_CLEAR          0x0C
#define EQ_VK_RETURN         0x0D

/*
 * 0x0E - 0x0F : unassigned
 */

#define EQ_VK_SHIFT          0x10
#define EQ_VK_CONTROL        0x11
#define EQ_VK_MENU           0x12
#define EQ_VK_PAUSE          0x13
#define EQ_VK_CAPITAL        0x14

#define EQ_VK_KANA           0x15
#define EQ_VK_HANGEUL        0x15  /* old name - should be here for compatibility */
#define EQ_VK_HANGUL         0x15

/*
 * 0x16 : unassigned
 */

#define EQ_VK_JUNJA          0x17
#define EQ_VK_FINAL          0x18
#define EQ_VK_HANJA          0x19
#define EQ_VK_KANJI          0x19

/*
 * 0x1A : unassigned
 */

#define EQ_VK_ESCAPE         0x1B

#define EQ_VK_CONVERT        0x1C
#define EQ_VK_NONCONVERT     0x1D
#define EQ_VK_ACCEPT         0x1E
#define EQ_VK_MODECHANGE     0x1F

#define EQ_VK_SPACE          0x20
#define EQ_VK_PRIOR          0x21
#define EQ_VK_NEXT           0x22
#define EQ_VK_END            0x23
#define EQ_VK_HOME           0x24
#define EQ_VK_LEFT           0x25
#define EQ_VK_UP             0x26
#define EQ_VK_RIGHT          0x27
#define EQ_VK_DOWN           0x28
#define EQ_VK_SELECT         0x29
#define EQ_VK_PRINT          0x2A
#define EQ_VK_EXECUTE        0x2B
#define EQ_VK_SNAPSHOT       0x2C
#define EQ_VK_INSERT         0x2D
#define EQ_VK_DELETE         0x2E
#define EQ_VK_HELP           0x2F

/*
 * VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
 * 0x3A - 0x40 : unassigned
 * VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
 */

#define EQ_VK_0              0x30
#define EQ_VK_1              0x31
#define EQ_VK_2              0x32
#define EQ_VK_3              0x33
#define EQ_VK_4              0x34
#define EQ_VK_5              0x35
#define EQ_VK_6              0x36
#define EQ_VK_7              0x37
#define EQ_VK_8              0x38
#define EQ_VK_9              0x39

#define EQ_VK_A              0x41
#define EQ_VK_B              0x42
#define EQ_VK_C              0x43
#define EQ_VK_D              0x44
#define EQ_VK_E              0x45
#define EQ_VK_F              0x46
#define EQ_VK_G              0x47
#define EQ_VK_H              0x48
#define EQ_VK_I              0x49
#define EQ_VK_J              0x4A
#define EQ_VK_K              0x4B
#define EQ_VK_L              0x4C
#define EQ_VK_M              0x4D
#define EQ_VK_N              0x4E
#define EQ_VK_O              0x4F
#define EQ_VK_P              0x50
#define EQ_VK_Q              0x51
#define EQ_VK_R              0x52
#define EQ_VK_S              0x53
#define EQ_VK_T              0x54
#define EQ_VK_U              0x55
#define EQ_VK_V              0x56
#define EQ_VK_W              0x57
#define EQ_VK_X              0x58
#define EQ_VK_Y              0x59
#define EQ_VK_Z              0x5A

#define EQ_VK_LWIN           0x5B
#define EQ_VK_RWIN           0x5C
#define EQ_VK_APPS           0x5D

/*
 * 0x5E : reserved
 */

#define EQ_VK_SLEEP          0x5F

#define EQ_VK_NUMPAD0        0x60
#define EQ_VK_NUMPAD1        0x61
#define EQ_VK_NUMPAD2        0x62
#define EQ_VK_NUMPAD3        0x63
#define EQ_VK_NUMPAD4        0x64
#define EQ_VK_NUMPAD5        0x65
#define EQ_VK_NUMPAD6        0x66
#define EQ_VK_NUMPAD7        0x67
#define EQ_VK_NUMPAD8        0x68
#define EQ_VK_NUMPAD9        0x69
#define EQ_VK_MULTIPLY       0x6A
#define EQ_VK_ADD            0x6B
#define EQ_VK_SEPARATOR      0x6C
#define EQ_VK_SUBTRACT       0x6D
#define EQ_VK_DECIMAL        0x6E
#define EQ_VK_DIVIDE         0x6F
#define EQ_VK_F1             0x70
#define EQ_VK_F2             0x71
#define EQ_VK_F3             0x72
#define EQ_VK_F4             0x73
#define EQ_VK_F5             0x74
#define EQ_VK_F6             0x75
#define EQ_VK_F7             0x76
#define EQ_VK_F8             0x77
#define EQ_VK_F9             0x78
#define EQ_VK_F10            0x79
#define EQ_VK_F11            0x7A
#define EQ_VK_F12            0x7B
#define EQ_VK_F13            0x7C
#define EQ_VK_F14            0x7D
#define EQ_VK_F15            0x7E
#define EQ_VK_F16            0x7F
#define EQ_VK_F17            0x80
#define EQ_VK_F18            0x81
#define EQ_VK_F19            0x82
#define EQ_VK_F20            0x83
#define EQ_VK_F21            0x84
#define EQ_VK_F22            0x85
#define EQ_VK_F23            0x86
#define EQ_VK_F24            0x87

/*
 * 0x88 - 0x8F : UI navigation
 */

#define EQ_VK_NAVIGATION_VIEW     0x88 // reserved
#define EQ_VK_NAVIGATION_MENU     0x89 // reserved
#define EQ_VK_NAVIGATION_UP       0x8A // reserved
#define EQ_VK_NAVIGATION_DOWN     0x8B // reserved
#define EQ_VK_NAVIGATION_LEFT     0x8C // reserved
#define EQ_VK_NAVIGATION_RIGHT    0x8D // reserved
#define EQ_VK_NAVIGATION_ACCEPT   0x8E // reserved
#define EQ_VK_NAVIGATION_CANCEL   0x8F // reserved

#define EQ_VK_NUMLOCK        0x90
#define EQ_VK_SCROLL         0x91

/*
 * NEC PC-9800 kbd definitions
 */
#define EQ_VK_OEM_NEC_EQUAL  0x92   // '=' key on numpad

/*
 * Fujitsu/OASYS kbd definitions
 */
#define EQ_VK_OEM_FJ_JISHO   0x92   // 'Dictionary' key
#define EQ_VK_OEM_FJ_MASSHOU 0x93   // 'Unregister word' key
#define EQ_VK_OEM_FJ_TOUROKU 0x94   // 'Register word' key
#define EQ_VK_OEM_FJ_LOYA    0x95   // 'Left OYAYUBI' key
#define EQ_VK_OEM_FJ_ROYA    0x96   // 'Right OYAYUBI' key

/*
 * 0x97 - 0x9F : unassigned
 */

/*
 * VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
 * Used only as parameters to GetAsyncKeyState() and GetKeyState().
 * No other API or message will distinguish left and right keys in this way.
 */
#define EQ_VK_LSHIFT         0xA0
#define EQ_VK_RSHIFT         0xA1
#define EQ_VK_LCONTROL       0xA2
#define EQ_VK_RCONTROL       0xA3
#define EQ_VK_LMENU          0xA4
#define EQ_VK_RMENU          0xA5

#define EQ_VK_BROWSER_BACK        0xA6
#define EQ_VK_BROWSER_FORWARD     0xA7
#define EQ_VK_BROWSER_REFRESH     0xA8
#define EQ_VK_BROWSER_STOP        0xA9
#define EQ_VK_BROWSER_SEARCH      0xAA
#define EQ_VK_BROWSER_FAVORITES   0xAB
#define EQ_VK_BROWSER_HOME        0xAC

#define EQ_VK_VOLUME_MUTE         0xAD
#define EQ_VK_VOLUME_DOWN         0xAE
#define EQ_VK_VOLUME_UP           0xAF
#define EQ_VK_MEDIA_NEXT_TRACK    0xB0
#define EQ_VK_MEDIA_PREV_TRACK    0xB1
#define EQ_VK_MEDIA_STOP          0xB2
#define EQ_VK_MEDIA_PLAY_PAUSE    0xB3
#define EQ_VK_LAUNCH_MAIL         0xB4
#define EQ_VK_LAUNCH_MEDIA_SELECT 0xB5
#define EQ_VK_LAUNCH_APP1         0xB6
#define EQ_VK_LAUNCH_APP2         0xB7

/*
 * 0xB8 - 0xB9 : reserved
 */

#define EQ_VK_OEM_1          0xBA   // ';:' for US
#define EQ_VK_OEM_PLUS       0xBB   // '+' any country
#define EQ_VK_OEM_COMMA      0xBC   // ',' any country
#define EQ_VK_OEM_MINUS      0xBD   // '-' any country
#define EQ_VK_OEM_PERIOD     0xBE   // '.' any country
#define EQ_VK_OEM_2          0xBF   // '/?' for US
#define EQ_VK_OEM_3          0xC0   // '`~' for US

/*
 * 0xC1 - 0xC2 : reserved
 */

/*
 * 0xC3 - 0xDA : Gamepad input
 */

#define EQ_VK_GAMEPAD_A                         0xC3 // reserved
#define EQ_VK_GAMEPAD_B                         0xC4 // reserved
#define EQ_VK_GAMEPAD_X                         0xC5 // reserved
#define EQ_VK_GAMEPAD_Y                         0xC6 // reserved
#define EQ_VK_GAMEPAD_RIGHT_SHOULDER            0xC7 // reserved
#define EQ_VK_GAMEPAD_LEFT_SHOULDER             0xC8 // reserved
#define EQ_VK_GAMEPAD_LEFT_TRIGGER              0xC9 // reserved
#define EQ_VK_GAMEPAD_RIGHT_TRIGGER             0xCA // reserved
#define EQ_VK_GAMEPAD_DPAD_UP                   0xCB // reserved
#define EQ_VK_GAMEPAD_DPAD_DOWN                 0xCC // reserved
#define EQ_VK_GAMEPAD_DPAD_LEFT                 0xCD // reserved
#define EQ_VK_GAMEPAD_DPAD_RIGHT                0xCE // reserved
#define EQ_VK_GAMEPAD_MENU                      0xCF // reserved
#define EQ_VK_GAMEPAD_VIEW                      0xD0 // reserved
#define EQ_VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON    0xD1 // reserved
#define EQ_VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON   0xD2 // reserved
#define EQ_VK_GAMEPAD_LEFT_THUMBSTICK_UP        0xD3 // reserved
#define EQ_VK_GAMEPAD_LEFT_THUMBSTICK_DOWN      0xD4 // reserved
#define EQ_VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT     0xD5 // reserved
#define EQ_VK_GAMEPAD_LEFT_THUMBSTICK_LEFT      0xD6 // reserved
#define EQ_VK_GAMEPAD_RIGHT_THUMBSTICK_UP       0xD7 // reserved
#define EQ_VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN     0xD8 // reserved
#define EQ_VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT    0xD9 // reserved
#define EQ_VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT     0xDA // reserved


#define EQ_VK_OEM_4          0xDB  //  '[{' for US
#define EQ_VK_OEM_5          0xDC  //  '\|' for US
#define EQ_VK_OEM_6          0xDD  //  ']}' for US
#define EQ_VK_OEM_7          0xDE  //  ''"' for US
#define EQ_VK_OEM_8          0xDF

/*
 * 0xE0 : reserved
 */

/*
 * Various extended or enhanced keyboards
 */
#define EQ_VK_OEM_AX         0xE1  //  'AX' key on Japanese AX kbd
#define EQ_VK_OEM_102        0xE2  //  "<>" or "\|" on RT 102-key kbd.
#define EQ_VK_ICO_HELP       0xE3  //  Help key on ICO
#define EQ_VK_ICO_00         0xE4  //  00 key on ICO

#define EQ_VK_PROCESSKEY     0xE5

#define EQ_VK_ICO_CLEAR      0xE6


#define EQ_VK_PACKET         0xE7

/*
 * 0xE8 : unassigned
 */

/*
 * Nokia/Ericsson definitions
 */
#define EQ_VK_OEM_RESET      0xE9
#define EQ_VK_OEM_JUMP       0xEA
#define EQ_VK_OEM_PA1        0xEB
#define EQ_VK_OEM_PA2        0xEC
#define EQ_VK_OEM_PA3        0xED
#define EQ_VK_OEM_WSCTRL     0xEE
#define EQ_VK_OEM_CUSEL      0xEF
#define EQ_VK_OEM_ATTN       0xF0
#define EQ_VK_OEM_FINISH     0xF1
#define EQ_VK_OEM_COPY       0xF2
#define EQ_VK_OEM_AUTO       0xF3
#define EQ_VK_OEM_ENLW       0xF4
#define EQ_VK_OEM_BACKTAB    0xF5

#define EQ_VK_ATTN           0xF6
#define EQ_VK_CRSEL          0xF7
#define EQ_VK_EXSEL          0xF8
#define EQ_VK_EREOF          0xF9
#define EQ_VK_PLAY           0xFA
#define EQ_VK_ZOOM           0xFB
#define EQ_VK_NONAME         0xFC
#define EQ_VK_PA1            0xFD
#define EQ_VK_OEM_CLEAR      0xFE

// clang-format on

u8 VirtualKeyToScanCode(u32 key);
