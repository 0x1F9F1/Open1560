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

define_dummy_symbol(eventq7_winevent);

#include "winevent.h"

#include "geinputLib.h"
#include "key_codes.h"
#include "pcwindis/pcwindis.h"
#include "replay.h"
#include "mmaudio/manager.h"

#include <windowsx.h>

#include <array>

void DeallocateEventQueue()
{
    delete eqEventHandler::SuperQ;

    eqEventHandler::SuperQ = nullptr;
}

void InitEventQueue()
{
    if (eqEventHandler::SuperQ == nullptr)
    {
        eqEventHandler::SuperQ = new WINEventHandler();
    }
}

static u32 WinEventHandlerMsgs[] {WM_MOUSEMOVE, WM_LBUTTONDOWN, WM_RBUTTONDOWN, WM_MBUTTONDOWN, WM_LBUTTONUP,
    WM_RBUTTONUP, WM_MBUTTONUP, WM_KILLFOCUS, WM_SETFOCUS, WM_KEYDOWN, WM_KEYUP, WM_CHAR, WM_ACTIVATE, WM_SIZE,
    WM_CLOSE, WM_SYSCOMMAND, WM_SETCURSOR, WM_MOUSEWHEEL, WM_SYSKEYDOWN, WM_SYSKEYUP};

WINEventHandler::WINEventHandler()
{
    RegisterMap("EventQ", WinEventHandlerMsgs, std::size(WinEventHandlerMsgs), this);
}

WINEventHandler::~WINEventHandler()
{
    UnregisterMap("EventQ");
}

void WINEventHandler::AdjustMouse(i32& mouse_x, i32& mouse_y)
{
    POINT point;
    GetCursorPos(&point);

    if (point.x != cursor_x_ || point.y != cursor_y_)
    {
        SetCursorPos(cursor_x_, cursor_y_);

        mouse_x = cursor_x_ + (cursor_x_ - point.x);
        mouse_y = cursor_y_ + (cursor_y_ - point.y);

        tracked_events_ |= 0x2;
    }
    else
    {
        mouse_x = point.x;
        mouse_y = point.y;
    }
}

i32 WINEventHandler::BeginGfx(i32 arg1, i32 arg2, i32 arg3)
{
    input_method_ = arg3 != 0 ? 3 : 1;

    center_x_ = arg1 * 0.5f;
    center_y_ = arg2 * 0.5f;

    scale_x_ = 1.0f / center_x_;
    scale_y_ = 1.0f / center_y_;

    if (inputSetup(arg1, arg2, arg3, 1, 1))
        input_method_ = 0;

    return 0;
}

void WINEventHandler::BeginTracking()
{
    tracked_events_ |= 3u;

    POINT point;
    GetCursorPos(&point);

    cursor_x_ = point.x;
    cursor_y_ = point.y;
}

void WINEventHandler::EndGfx()
{
    if (input_method_)
        geinputCleanup();

    input_method_ = 0;
}

static i32 MouseScrollWheelPosition = 0;
static u32 CurrentKeyModifiers = 0;
static u32 OldPriorityClass = 0;

void WINEventHandler::EndTracking()
{
    tracked_events_ &= ~0x1;

    SetCursorPos(cursor_x_, cursor_y_);
}

const char* WINEventHandler::GKeyName(i32 arg1)
{
    switch (arg1)
    {
        case VK_BACK: return "BACK";
        case VK_TAB: return "TAB";

        case VK_CLEAR: return "CLEAR";
        case VK_RETURN: return "RETURN";

        case VK_SHIFT: return "SHIFT";
        case VK_CONTROL: return "CONTROL";
        case VK_MENU: return "MENU";
        case VK_PAUSE: return "PAUSE";
        case VK_CAPITAL: return "CAPITAL";

        case VK_ESCAPE: return "ESCAPE";

        case VK_SPACE: return "SPACE";
        case VK_PRIOR: return "PRIOR";
        case VK_NEXT: return "NEXT";
        case VK_END: return "END";
        case VK_HOME: return "HOME";
        case VK_LEFT: return "LEFT";
        case VK_UP: return "UP";
        case VK_RIGHT: return "RIGHT";
        case VK_DOWN: return "DOWN";
        case VK_SELECT: return "SELECT";
        case VK_PRINT: return "PRINT";
        case VK_EXECUTE: return "EXECUTE";
        case VK_SNAPSHOT: return "SNAPSHOT";
        case VK_INSERT: return "INSERT";
        case VK_DELETE: return "DELETE";
        case VK_HELP: return "HELP";

        case '0': return "0";
        case '1': return "1";
        case '2': return "2";
        case '3': return "3";
        case '4': return "4";
        case '5': return "5";
        case '6': return "6";
        case '7': return "7";
        case '8': return "8";
        case '9': return "9";

        case 'A': return "A";
        case 'B': return "B";
        case 'C': return "C";
        case 'D': return "D";
        case 'E': return "E";
        case 'F': return "F";
        case 'G': return "G";
        case 'H': return "H";
        case 'I': return "I";
        case 'J': return "J";
        case 'K': return "K";
        case 'L': return "L";
        case 'M': return "M";
        case 'N': return "N";
        case 'O': return "O";
        case 'P': return "P";
        case 'Q': return "Q";
        case 'R': return "R";
        case 'S': return "S";
        case 'T': return "T";
        case 'U': return "U";
        case 'V': return "V";
        case 'W': return "W";
        case 'X': return "X";
        case 'Y': return "Y";
        case 'Z': return "Z";

        case VK_LWIN: return "LWIN";
        case VK_RWIN: return "RWIN";
        case VK_APPS: return "APPS";

        case VK_NUMPAD0: return "NUMPAD0";
        case VK_NUMPAD1: return "NUMPAD1";
        case VK_NUMPAD2: return "NUMPAD2";
        case VK_NUMPAD3: return "NUMPAD3";
        case VK_NUMPAD4: return "NUMPAD4";
        case VK_NUMPAD5: return "NUMPAD5";
        case VK_NUMPAD6: return "NUMPAD6";
        case VK_NUMPAD7: return "NUMPAD7";
        case VK_NUMPAD8: return "NUMPAD8";
        case VK_NUMPAD9: return "NUMPAD9";

        case VK_MULTIPLY: return "MULTIPLY";
        case VK_ADD: return "ADD";
        case VK_SEPARATOR: return "SEPARATOR";
        case VK_SUBTRACT: return "SUBTRACT";
        case VK_DECIMAL: return "DECIMAL";
        case VK_DIVIDE: return "DIVIDE";

        case VK_F1: return "F1";
        case VK_F2: return "F2";
        case VK_F3: return "F3";
        case VK_F4: return "F4";
        case VK_F5: return "F5";
        case VK_F6: return "F6";
        case VK_F7: return "F7";
        case VK_F8: return "F8";
        case VK_F9: return "F9";
        case VK_F10: return "F10";
        case VK_F11: return "F11";
        case VK_F12: return "F12";
        case VK_F13: return "F13";
        case VK_F14: return "F14";
        case VK_F15: return "F15";
        case VK_F16: return "F16";
        case VK_F17: return "F17";
        case VK_F18: return "F18";
        case VK_F19: return "F19";
        case VK_F20: return "F20";
        case VK_F21: return "F21";
        case VK_F22: return "F22";
        case VK_F23: return "F23";
        case VK_F24: return "F24";

        case VK_NAVIGATION_VIEW: return "NAVIGATION_VIEW";
        case VK_NAVIGATION_MENU: return "NAVIGATION_MENU";
        case VK_NAVIGATION_UP: return "NAVIGATION_UP";
        case VK_NAVIGATION_DOWN: return "NAVIGATION_DOWN";
        case VK_NAVIGATION_LEFT: return "NAVIGATION_LEFT";
        case VK_NAVIGATION_RIGHT: return "NAVIGATION_RIGHT";
        case VK_NAVIGATION_ACCEPT: return "NAVIGATION_ACCEPT";
        case VK_NAVIGATION_CANCEL: return "NAVIGATION_CANCEL";

        case VK_NUMLOCK: return "NUMLOCK";
        case VK_SCROLL: return "SCROLL";

        case VK_OEM_1: return "OEM_1";
        case VK_OEM_PLUS: return "OEM_PLUS";
        case VK_OEM_COMMA: return "OEM_COMMA";
        case VK_OEM_MINUS: return "OEM_MINUS";
        case VK_OEM_PERIOD: return "OEM_PERIOD";
        case VK_OEM_2: return "OEM_2";
        case VK_OEM_3: return "OEM_3";
        case VK_OEM_4: return "OEM_4";
        case VK_OEM_5: return "OEM_5";
        case VK_OEM_6: return "OEM_6";
        case VK_OEM_7: return "OEM_7";
        case VK_OEM_8: return "OEM_8";

        default: return "[Unknown]";
    }
}

static constexpr std::array<u8, 256> VK_To_EQ_Mapping = [] {
    std::array<u8, 256> lookup {};

    lookup[VK_BACK] = EQ_KEY_BACK;
    lookup[VK_TAB] = EQ_KEY_TAB;
    lookup[VK_RETURN] = EQ_KEY_RETURN;
    lookup[VK_SHIFT] = EQ_KEY_LSHIFT;
    lookup[VK_CONTROL] = EQ_KEY_LCONTROL;
    lookup[VK_CAPITAL] = EQ_KEY_CAPITAL;
    lookup[VK_ESCAPE] = EQ_KEY_ESCAPE;
    lookup[VK_SPACE] = EQ_KEY_SPACE;
    lookup[VK_PRIOR] = EQ_KEY_PRIOR;
    lookup[VK_NEXT] = EQ_KEY_NEXT;
    lookup[VK_END] = EQ_KEY_END;
    lookup[VK_HOME] = EQ_KEY_HOME;
    lookup[VK_LEFT] = EQ_KEY_LEFT;
    lookup[VK_UP] = EQ_KEY_UP;
    lookup[VK_RIGHT] = EQ_KEY_RIGHT;
    lookup[VK_DOWN] = EQ_KEY_DOWN;
    lookup[VK_INSERT] = EQ_KEY_INSERT;
    lookup[VK_DELETE] = EQ_KEY_DELETE;

    lookup['0'] = EQ_KEY_0;
    lookup['1'] = EQ_KEY_1;
    lookup['2'] = EQ_KEY_2;
    lookup['3'] = EQ_KEY_3;
    lookup['4'] = EQ_KEY_4;
    lookup['5'] = EQ_KEY_5;
    lookup['6'] = EQ_KEY_6;
    lookup['7'] = EQ_KEY_7;
    lookup['8'] = EQ_KEY_8;
    lookup['9'] = EQ_KEY_9;

    lookup['A'] = EQ_KEY_A;
    lookup['B'] = EQ_KEY_B;
    lookup['C'] = EQ_KEY_C;
    lookup['D'] = EQ_KEY_D;
    lookup['E'] = EQ_KEY_E;
    lookup['F'] = EQ_KEY_F;
    lookup['G'] = EQ_KEY_G;
    lookup['H'] = EQ_KEY_H;
    lookup['I'] = EQ_KEY_I;
    lookup['J'] = EQ_KEY_J;
    lookup['K'] = EQ_KEY_K;
    lookup['L'] = EQ_KEY_L;
    lookup['M'] = EQ_KEY_M;
    lookup['N'] = EQ_KEY_N;
    lookup['O'] = EQ_KEY_O;
    lookup['P'] = EQ_KEY_P;
    lookup['Q'] = EQ_KEY_Q;
    lookup['R'] = EQ_KEY_R;
    lookup['S'] = EQ_KEY_S;
    lookup['T'] = EQ_KEY_T;
    lookup['U'] = EQ_KEY_U;
    lookup['V'] = EQ_KEY_V;
    lookup['W'] = EQ_KEY_W;
    lookup['X'] = EQ_KEY_X;
    lookup['Y'] = EQ_KEY_Y;
    lookup['Z'] = EQ_KEY_Z;

    lookup[VK_LWIN] = EQ_KEY_LWIN;
    lookup[VK_RWIN] = EQ_KEY_RWIN;
    lookup[VK_APPS] = EQ_KEY_APPS;
    lookup[VK_NUMPAD0] = EQ_KEY_NUMPAD0;
    lookup[VK_NUMPAD1] = EQ_KEY_NUMPAD1;
    lookup[VK_NUMPAD2] = EQ_KEY_NUMPAD2;
    lookup[VK_NUMPAD3] = EQ_KEY_NUMPAD3;
    lookup[VK_NUMPAD4] = EQ_KEY_NUMPAD4;
    lookup[VK_NUMPAD5] = EQ_KEY_NUMPAD5;
    lookup[VK_NUMPAD6] = EQ_KEY_NUMPAD6;
    lookup[VK_NUMPAD7] = EQ_KEY_NUMPAD7;
    lookup[VK_NUMPAD8] = EQ_KEY_NUMPAD8;
    lookup[VK_NUMPAD9] = EQ_KEY_NUMPAD9;
    lookup[VK_MULTIPLY] = EQ_KEY_MULTIPLY;
    lookup[VK_ADD] = EQ_KEY_ADD;
    lookup[VK_SUBTRACT] = EQ_KEY_SUBTRACT;
    lookup[VK_DECIMAL] = EQ_KEY_DECIMAL;
    lookup[VK_DIVIDE] = EQ_KEY_DIVIDE;

    lookup[VK_F1] = EQ_KEY_F1;
    lookup[VK_F2] = EQ_KEY_F2;
    lookup[VK_F3] = EQ_KEY_F3;
    lookup[VK_F4] = EQ_KEY_F4;
    lookup[VK_F5] = EQ_KEY_F5;
    lookup[VK_F6] = EQ_KEY_F6;
    lookup[VK_F7] = EQ_KEY_F7;
    lookup[VK_F8] = EQ_KEY_F8;
    lookup[VK_F9] = EQ_KEY_F9;
    lookup[VK_F10] = EQ_KEY_F10;
    lookup[VK_F11] = EQ_KEY_F11;
    lookup[VK_F12] = EQ_KEY_F12;
    lookup[VK_F13] = EQ_KEY_F13;
    lookup[VK_F14] = EQ_KEY_F14;
    lookup[VK_F15] = EQ_KEY_F15;

    lookup[VK_NUMLOCK] = EQ_KEY_NUMLOCK;
    lookup[VK_SCROLL] = EQ_KEY_SCROLL;
    lookup[VK_LSHIFT] = EQ_KEY_LSHIFT;
    lookup[VK_RSHIFT] = EQ_KEY_RSHIFT;
    lookup[VK_LCONTROL] = EQ_KEY_LCONTROL;
    lookup[VK_RCONTROL] = EQ_KEY_RCONTROL;
    lookup[VK_LMENU] = EQ_KEY_LMENU;
    lookup[VK_RMENU] = EQ_KEY_RMENU;

    return lookup;
}();

void WINEventHandler::Update(i32)
{
    buttons_ &= ~(EQ_BUTTON_WHEEL_UP | EQ_BUTTON_WHEEL_DOWN);

    MSG msg;
    while (ActiveFlag ? PeekMessageA(&msg, 0, 0, 0, 1u) : GetMessageA(&msg, 0, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    if (eqReplay::Playback)
    {
        std::memcpy(key_states_, eqEventReplayChannel.KeyStates, sizeof(key_states_));

        i32 index = 0;

        while (index < eqEventReplayChannel.EventCount)
        {
            u32* events = &eqEventReplayChannel.Events[index];

            if (*events == 'MOUS')
            {
                if (index + 8 > eqEventReplayChannel.EventCount)
                    Quitf("eqReplay playback: corrupt mouse event");

                for (eqEventMonitor* monitor : monitors_)
                {
                    if (monitor && (monitor->dword10 & dwordC))
                        monitor->Mouse(
                            nullptr, events[1], events[2], events[3], events[4], events[5], events[6], events[7]);
                }

                index += 8;
            }
            else if (*events == 'KEYB')
            {
                if (index + 4 > eqEventReplayChannel.EventCount)
                    Quitf("eqReplay playback: corrupt keyboard event");

                for (eqEventMonitor* monitor : monitors_)
                {
                    if (monitor && (monitor->dword10 & dwordC))
                        monitor->Keyboard(0, events[1], events[2], events[3], 0);
                }

                index += 4;
            }
            else
            {
                Quitf("eqReplay playback: bad event");
            }
        }
    }
    else if (input_method_)
    {
        memcpy(key_states_, geinputGetKeyboard(), sizeof(key_states_));
    }
    else
    {
        BYTE key_states[256];
        GetKeyboardState(key_states);

        for (i32 i = 0; i < 256; ++i)
        {
            key_states_[VK_To_EQ_Mapping[i]] = !!(key_states[i] & 0x80);
        }
    }

    if (eqReplay::Playback)
    {
        mouse_x_ = eqEventReplayChannel.MouseX;
        mouse_y_ = eqEventReplayChannel.MouseY;
        mouse_delta_x_ = eqEventReplayChannel.MouseDeltaX;
        mouse_delta_y_ = eqEventReplayChannel.MouseDeltaY;
        buttons_ = eqEventReplayChannel.Flags;
    }
    else if (input_method_ == 3)
    {
        long mouse_x = 0;
        long mouse_y = 0;

        long mouse_delta_x = 0;
        long mouse_delta_y = 0;
        long mouse_delta_z = 0;

        char mouse_button_l = 0;
        char mouse_button_r = 0;
        char mouse_button_m = 0;

        geinputGetMouse(&mouse_x, &mouse_y, &mouse_button_l, &mouse_button_r, &mouse_delta_x, &mouse_delta_y,
            &mouse_delta_z, &mouse_button_m);

        mouse_x_ = mouse_x;
        mouse_y_ = mouse_y;

        mouse_delta_x_ = mouse_delta_x;
        mouse_delta_y_ = mouse_delta_y;

        buttons_ = 0;

        if (mouse_button_l)
            buttons_ |= EQ_BUTTON_LEFT;

        if (mouse_button_r)
            buttons_ |= EQ_BUTTON_RIGHT;

        if (mouse_button_m)
            buttons_ |= EQ_BUTTON_MIDDLE;
    }

    if (eqReplay::Recording)
    {
        std::memcpy(eqEventReplayChannel.KeyStates, key_states_, sizeof(eqEventReplayChannel.KeyStates));

        eqEventReplayChannel.MouseX = mouse_x_;
        eqEventReplayChannel.MouseY = mouse_y_;
        eqEventReplayChannel.MouseDeltaX = mouse_delta_x_;
        eqEventReplayChannel.MouseDeltaY = mouse_delta_y_;
        eqEventReplayChannel.Flags = buttons_;
    }
}

LRESULT WINEventHandler::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (eqReplay::Playback)
        return 0;

    LRESULT result = 0;

    switch (uMsg)
    {
        case WM_MOUSEMOVE:
        case WM_MOUSEWHEEL:
        case WM_LBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_RBUTTONDOWN:
        case WM_RBUTTONUP:
        case WM_MBUTTONDOWN:
        case WM_MBUTTONUP: {
            if (uMsg == WM_MOUSEMOVE)
            {
                if (!wants_motion_ && !(wParam & (MK_LBUTTON | MK_RBUTTON | MK_MBUTTON)))
                    break;
            }

            mouse_x_ = GET_X_LPARAM(lParam);
            mouse_x_ = GET_Y_LPARAM(lParam);

            buttons_ = 0;

            if (wParam & MK_LBUTTON)
                buttons_ |= EQ_BUTTON_LEFT;

            if (wParam & MK_RBUTTON)
                buttons_ |= EQ_BUTTON_RIGHT;

            if (wParam & MK_MBUTTON)
                buttons_ |= EQ_BUTTON_MIDDLE;

            if (uMsg == WM_MOUSEWHEEL)
            {
                MouseScrollWheelPosition += GET_WHEEL_DELTA_WPARAM(wParam);

                if (MouseScrollWheelPosition >= 120)
                {
                    MouseScrollWheelPosition -= 120;
                    buttons_ |= EQ_BUTTON_WHEEL_UP;
                }
                else if (MouseScrollWheelPosition <= -120)
                {
                    MouseScrollWheelPosition += 120;
                    buttons_ |= EQ_BUTTON_WHEEL_DOWN;
                }
            }

            RECT rect;
            GetWindowRect(hwnd, &rect);

            if (tracked_events_ & 0x1)
                AdjustMouse(mouse_x_, mouse_y_);

            u32 changed_buttons = buttons_ ^ prev_buttons_;
            u32 new_buttons = buttons_ & changed_buttons;

            for (eqEventMonitor* monitor : monitors_)
            {
                if (monitor && (monitor->dword10 & dwordC))
                    monitor->Mouse(
                        hwnd, new_buttons, changed_buttons, buttons_, mouse_x_, mouse_y_, rect.left, rect.top);
            }

            if (eqReplay::Recording)
                eqEventReplayChannel.QueueMouse(
                    new_buttons, changed_buttons, buttons_, mouse_x_, mouse_y_, rect.left, rect.top);

            prev_buttons_ = buttons_;

            break;
        }

        case WM_KEYDOWN:
        case WM_KEYUP:
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP: {
            u32 key_mods = 0;

            switch (wParam)
            {
                case VK_CONTROL: key_mods = EQ_KMOD_CTRL; break;
                case VK_MENU: key_mods = EQ_KMOD_ALT; break;
                case VK_SHIFT: key_mods = EQ_KMOD_SHIFT; break;
            }

            if ((uMsg == WM_KEYDOWN) || (uMsg == WM_SYSKEYDOWN))
                CurrentKeyModifiers |= key_mods;
            else
                CurrentKeyModifiers &= ~key_mods;

            u32 modifiers = CurrentKeyModifiers;

            if (!(lParam & 0x80000000))
                modifiers |= EQ_KMOD_DOWN;

            for (eqEventMonitor* monitor : monitors_)
            {
                if (monitor && (monitor->dword10 & dwordC))
                    monitor->Keyboard(hwnd, modifiers, wParam, 0, lParam);
            }

            if (eqReplay::Recording)
                eqEventReplayChannel.QueueKeyboard(modifiers, wParam, 0, 0);

            break;
        }

        case WM_CHAR: {
            u32 modifiers = CurrentKeyModifiers;

            if (!(lParam & 0x80000000))
                modifiers |= EQ_KMOD_DOWN;

            for (eqEventMonitor* monitor : monitors_)
            {
                if (monitor && (monitor->dword10 & dwordC))
                    monitor->Keyboard(hwnd, modifiers, 0, wParam, lParam);
            }

            if (eqReplay::Recording)
                eqEventReplayChannel.QueueKeyboard(modifiers, 0, wParam, 0);

            break;
        }

        case WM_SETCURSOR: {
            if ((InitialCursorState != -1) || (LOWORD(lParam) != HTCLIENT))
            {
                result = DefWindowProcA(hwnd, uMsg, wParam, lParam);
            }
            else
            {
                SetCursor(NULL);
                result = 1;
            }

            break;
        }

        case WM_SIZE:
        case WM_ACTIVATE: {
            bool focused = false;

            if (uMsg == WM_SIZE)
            {
                Displayf("\n\n***** HWND = %d, New Size = %d x %d", hwnd, LOWORD(lParam), HIWORD(lParam));

                if (wParam != SIZE_MINIMIZED)
                    break;

                Displayf("EventQ: Minimize requested, blocking.");
            }
            else if (uMsg == WM_ACTIVATE)
            {
                if (wParam != WA_INACTIVE)
                {
                    Displayf("EventQ: Regaining focus, returning to caller.");

                    focused = true;
                }
                else
                {
                    Displayf("EventQ: Losing focus, blocking.");
                }
            }

            if (focused)
            {
                SetPriorityClass(GetCurrentProcess(), OldPriorityClass);
                ActiveFlag |= 1;
                RestoreApplication();
            }
            else
            {
                DeactivateApplication();
                OldPriorityClass = GetPriorityClass(GetCurrentProcess());
                SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);
                ActiveFlag &= ~1;
            }

            break;
        }

        case WM_SETFOCUS:
        case WM_KILLFOCUS: {
            bool focused = uMsg == WM_SETFOCUS;

            for (eqEventMonitor* monitor : monitors_)
            {
                if (monitor && (monitor->dword10 & dwordC))
                    monitor->Refocus(hwnd, focused);
            }

            break;
        }

        case WM_PAINT: {
            for (eqEventMonitor* monitor : monitors_)
            {
                if (monitor && (monitor->dword10 & dwordC))
                    monitor->Redraw(hwnd, 0, 0, 0, 0);
            }

            break;
        }

        case WM_SYSCOMMAND: {
            if ((wParam != SC_KEYMENU) || !(ActiveFlag & 1))
                result = DefWindowProcA(hwnd, uMsg, wParam, lParam);

            break;
        }

        case WM_CLOSE: {
            Displayf("Close requested.");

            if (CloseCallback)
                CloseCallback();

            ActiveFlag = 1;

            break;
        }
    }

    return result;
}
