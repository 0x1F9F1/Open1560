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

#include "keys.h"

u8 VirtualKeyToScanCode(u32 key)
{
    // return MapVirtualKeyA(key, MAPVK_VK_TO_VSC);

    switch (key)
    {
        case EQ_VK_BACK: return EQ_KEY_BACK;
        case EQ_VK_TAB: return EQ_KEY_TAB;
        case EQ_VK_RETURN: return EQ_KEY_RETURN;
        case EQ_VK_SHIFT: return EQ_KEY_LSHIFT;
        case EQ_VK_CONTROL: return EQ_KEY_LCONTROL;
        case EQ_VK_CAPITAL: return EQ_KEY_CAPITAL;
        case EQ_VK_ESCAPE: return EQ_KEY_ESCAPE;
        case EQ_VK_SPACE: return EQ_KEY_SPACE;
        case EQ_VK_PRIOR: return EQ_KEY_PRIOR;
        case EQ_VK_NEXT: return EQ_KEY_NEXT;
        case EQ_VK_END: return EQ_KEY_END;
        case EQ_VK_HOME: return EQ_KEY_HOME;
        case EQ_VK_LEFT: return EQ_KEY_LEFT;
        case EQ_VK_UP: return EQ_KEY_UP;
        case EQ_VK_RIGHT: return EQ_KEY_RIGHT;
        case EQ_VK_DOWN: return EQ_KEY_DOWN;
        case EQ_VK_INSERT: return EQ_KEY_INSERT;
        case EQ_VK_DELETE: return EQ_KEY_DELETE;

        case EQ_VK_0: return EQ_KEY_0;
        case EQ_VK_1: return EQ_KEY_1;
        case EQ_VK_2: return EQ_KEY_2;
        case EQ_VK_3: return EQ_KEY_3;
        case EQ_VK_4: return EQ_KEY_4;
        case EQ_VK_5: return EQ_KEY_5;
        case EQ_VK_6: return EQ_KEY_6;
        case EQ_VK_7: return EQ_KEY_7;
        case EQ_VK_8: return EQ_KEY_8;
        case EQ_VK_9: return EQ_KEY_9;

        case EQ_VK_A: return EQ_KEY_A;
        case EQ_VK_B: return EQ_KEY_B;
        case EQ_VK_C: return EQ_KEY_C;
        case EQ_VK_D: return EQ_KEY_D;
        case EQ_VK_E: return EQ_KEY_E;
        case EQ_VK_F: return EQ_KEY_F;
        case EQ_VK_G: return EQ_KEY_G;
        case EQ_VK_H: return EQ_KEY_H;
        case EQ_VK_I: return EQ_KEY_I;
        case EQ_VK_J: return EQ_KEY_J;
        case EQ_VK_K: return EQ_KEY_K;
        case EQ_VK_L: return EQ_KEY_L;
        case EQ_VK_M: return EQ_KEY_M;
        case EQ_VK_N: return EQ_KEY_N;
        case EQ_VK_O: return EQ_KEY_O;
        case EQ_VK_P: return EQ_KEY_P;
        case EQ_VK_Q: return EQ_KEY_Q;
        case EQ_VK_R: return EQ_KEY_R;
        case EQ_VK_S: return EQ_KEY_S;
        case EQ_VK_T: return EQ_KEY_T;
        case EQ_VK_U: return EQ_KEY_U;
        case EQ_VK_V: return EQ_KEY_V;
        case EQ_VK_W: return EQ_KEY_W;
        case EQ_VK_X: return EQ_KEY_X;
        case EQ_VK_Y: return EQ_KEY_Y;
        case EQ_VK_Z: return EQ_KEY_Z;

        case EQ_VK_LWIN: return EQ_KEY_LWIN;
        case EQ_VK_RWIN: return EQ_KEY_RWIN;
        case EQ_VK_APPS: return EQ_KEY_APPS;
        case EQ_VK_NUMPAD0: return EQ_KEY_NUMPAD0;
        case EQ_VK_NUMPAD1: return EQ_KEY_NUMPAD1;
        case EQ_VK_NUMPAD2: return EQ_KEY_NUMPAD2;
        case EQ_VK_NUMPAD3: return EQ_KEY_NUMPAD3;
        case EQ_VK_NUMPAD4: return EQ_KEY_NUMPAD4;
        case EQ_VK_NUMPAD5: return EQ_KEY_NUMPAD5;
        case EQ_VK_NUMPAD6: return EQ_KEY_NUMPAD6;
        case EQ_VK_NUMPAD7: return EQ_KEY_NUMPAD7;
        case EQ_VK_NUMPAD8: return EQ_KEY_NUMPAD8;
        case EQ_VK_NUMPAD9: return EQ_KEY_NUMPAD9;
        case EQ_VK_MULTIPLY: return EQ_KEY_MULTIPLY;
        case EQ_VK_ADD: return EQ_KEY_ADD;
        case EQ_VK_SUBTRACT: return EQ_KEY_SUBTRACT;
        case EQ_VK_DECIMAL: return EQ_KEY_DECIMAL;
        case EQ_VK_DIVIDE: return EQ_KEY_DIVIDE;

        case EQ_VK_F1: return EQ_KEY_F1;
        case EQ_VK_F2: return EQ_KEY_F2;
        case EQ_VK_F3: return EQ_KEY_F3;
        case EQ_VK_F4: return EQ_KEY_F4;
        case EQ_VK_F5: return EQ_KEY_F5;
        case EQ_VK_F6: return EQ_KEY_F6;
        case EQ_VK_F7: return EQ_KEY_F7;
        case EQ_VK_F8: return EQ_KEY_F8;
        case EQ_VK_F9: return EQ_KEY_F9;
        case EQ_VK_F10: return EQ_KEY_F10;
        case EQ_VK_F11: return EQ_KEY_F11;
        case EQ_VK_F12: return EQ_KEY_F12;
        case EQ_VK_F13: return EQ_KEY_F13;
        case EQ_VK_F14: return EQ_KEY_F14;
        case EQ_VK_F15: return EQ_KEY_F15;

        case EQ_VK_NUMLOCK: return EQ_KEY_NUMLOCK;
        case EQ_VK_SCROLL: return EQ_KEY_SCROLL;
        case EQ_VK_LSHIFT: return EQ_KEY_LSHIFT;
        case EQ_VK_RSHIFT: return EQ_KEY_RSHIFT;
        case EQ_VK_LCONTROL: return EQ_KEY_LCONTROL;
        case EQ_VK_RCONTROL: return EQ_KEY_RCONTROL;
        case EQ_VK_LMENU: return EQ_KEY_LMENU;
        case EQ_VK_RMENU: return EQ_KEY_RMENU;

        default: return 0;
    }
}
