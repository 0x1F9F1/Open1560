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
#include "keys.h"
#include "mmaudio/manager.h"
#include "pcwindis/pcwindis.h"
#include "replay.h"

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
    RegisterMap("EventQ", WinEventHandlerMsgs, ARTS_SSIZE32(WinEventHandlerMsgs), this);
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

i32 WINEventHandler::BeginGfx(i32 width, i32 height, b32 fullscreen)
{
    input_method_ = fullscreen ? 3 : 1;

    center_x_ = width * 0.5f;
    center_y_ = height * 0.5f;

    scale_x_ = 1.0f / center_x_;
    scale_y_ = 1.0f / center_y_;

    if (inputSetup(width, height, fullscreen, 1, 1))
    {
        input_method_ = 0;

        Errorf("inputSetup failed");
    }

    return 0;
}

void WINEventHandler::BeginTracking()
{
    tracked_events_ |= 0x3;

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
        case EQ_VK_BACK: return "BACK";
        case EQ_VK_TAB: return "TAB";

        case EQ_VK_CLEAR: return "CLEAR";
        case EQ_VK_RETURN: return "RETURN";

        case EQ_VK_SHIFT: return "SHIFT";
        case EQ_VK_CONTROL: return "CONTROL";
        case EQ_VK_MENU: return "MENU";
        case EQ_VK_PAUSE: return "PAUSE";
        case EQ_VK_CAPITAL: return "CAPITAL";

        case EQ_VK_ESCAPE: return "ESCAPE";

        case EQ_VK_SPACE: return "SPACE";
        case EQ_VK_PRIOR: return "PRIOR";
        case EQ_VK_NEXT: return "NEXT";
        case EQ_VK_END: return "END";
        case EQ_VK_HOME: return "HOME";
        case EQ_VK_LEFT: return "LEFT";
        case EQ_VK_UP: return "UP";
        case EQ_VK_RIGHT: return "RIGHT";
        case EQ_VK_DOWN: return "DOWN";
        case EQ_VK_SELECT: return "SELECT";
        case EQ_VK_PRINT: return "PRINT";
        case EQ_VK_EXECUTE: return "EXECUTE";
        case EQ_VK_SNAPSHOT: return "SNAPSHOT";
        case EQ_VK_INSERT: return "INSERT";
        case EQ_VK_DELETE: return "DELETE";
        case EQ_VK_HELP: return "HELP";

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

        case EQ_VK_LWIN: return "LWIN";
        case EQ_VK_RWIN: return "RWIN";
        case EQ_VK_APPS: return "APPS";

        case EQ_VK_NUMPAD0: return "NUMPAD0";
        case EQ_VK_NUMPAD1: return "NUMPAD1";
        case EQ_VK_NUMPAD2: return "NUMPAD2";
        case EQ_VK_NUMPAD3: return "NUMPAD3";
        case EQ_VK_NUMPAD4: return "NUMPAD4";
        case EQ_VK_NUMPAD5: return "NUMPAD5";
        case EQ_VK_NUMPAD6: return "NUMPAD6";
        case EQ_VK_NUMPAD7: return "NUMPAD7";
        case EQ_VK_NUMPAD8: return "NUMPAD8";
        case EQ_VK_NUMPAD9: return "NUMPAD9";

        case EQ_VK_MULTIPLY: return "MULTIPLY";
        case EQ_VK_ADD: return "ADD";
        case EQ_VK_SEPARATOR: return "SEPARATOR";
        case EQ_VK_SUBTRACT: return "SUBTRACT";
        case EQ_VK_DECIMAL: return "DECIMAL";
        case EQ_VK_DIVIDE: return "DIVIDE";

        case EQ_VK_F1: return "F1";
        case EQ_VK_F2: return "F2";
        case EQ_VK_F3: return "F3";
        case EQ_VK_F4: return "F4";
        case EQ_VK_F5: return "F5";
        case EQ_VK_F6: return "F6";
        case EQ_VK_F7: return "F7";
        case EQ_VK_F8: return "F8";
        case EQ_VK_F9: return "F9";
        case EQ_VK_F10: return "F10";
        case EQ_VK_F11: return "F11";
        case EQ_VK_F12: return "F12";
        case EQ_VK_F13: return "F13";
        case EQ_VK_F14: return "F14";
        case EQ_VK_F15: return "F15";
        case EQ_VK_F16: return "F16";
        case EQ_VK_F17: return "F17";
        case EQ_VK_F18: return "F18";
        case EQ_VK_F19: return "F19";
        case EQ_VK_F20: return "F20";
        case EQ_VK_F21: return "F21";
        case EQ_VK_F22: return "F22";
        case EQ_VK_F23: return "F23";
        case EQ_VK_F24: return "F24";

#if 0
        case EQ_VK_NAVIGATION_VIEW: return "NAVIGATION_VIEW";
        case EQ_VK_NAVIGATION_MENU: return "NAVIGATION_MENU";
        case EQ_VK_NAVIGATION_UP: return "NAVIGATION_UP";
        case EQ_VK_NAVIGATION_DOWN: return "NAVIGATION_DOWN";
        case EQ_VK_NAVIGATION_LEFT: return "NAVIGATION_LEFT";
        case EQ_VK_NAVIGATION_RIGHT: return "NAVIGATION_RIGHT";
        case EQ_VK_NAVIGATION_ACCEPT: return "NAVIGATION_ACCEPT";
        case EQ_VK_NAVIGATION_CANCEL: return "NAVIGATION_CANCEL";
#endif

        case EQ_VK_NUMLOCK: return "NUMLOCK";
        case EQ_VK_SCROLL: return "SCROLL";

        case EQ_VK_OEM_1: return "OEM_1";
        case EQ_VK_OEM_PLUS: return "OEM_PLUS";
        case EQ_VK_OEM_COMMA: return "OEM_COMMA";
        case EQ_VK_OEM_MINUS: return "OEM_MINUS";
        case EQ_VK_OEM_PERIOD: return "OEM_PERIOD";
        case EQ_VK_OEM_2: return "OEM_2";
        case EQ_VK_OEM_3: return "OEM_3";
        case EQ_VK_OEM_4: return "OEM_4";
        case EQ_VK_OEM_5: return "OEM_5";
        case EQ_VK_OEM_6: return "OEM_6";
        case EQ_VK_OEM_7: return "OEM_7";
        case EQ_VK_OEM_8: return "OEM_8";

        default: return "[Unknown]";
    }
}

void WINEventHandler::Update(i32)
{
    buttons_ &= ~(EQ_BUTTON_WHEEL_UP | EQ_BUTTON_WHEEL_DOWN);

    MSG msg;
    while (ActiveFlag ? PeekMessageA(&msg, 0, 0, 0, PM_REMOVE) : GetMessageA(&msg, 0, 0, 0))
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
                    if (monitor && (monitor->channels_ & channels_))
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
                    if (monitor && (monitor->channels_ & channels_))
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
        std::memcpy(key_states_, geinputGetKeyboard(), sizeof(key_states_));
    }
    else
    {
        if (BYTE key_states[256]; GetKeyboardState(key_states))
        {
            for (i32 i = 0; i < 256; ++i)
                key_states_[VirtualKeyToScanCode(i)] = !!(key_states[i] & 0x80);
        }
    }

    if (eqReplay::Playback)
    {
        mouse_x_ = eqEventReplayChannel.MouseX;
        mouse_y_ = eqEventReplayChannel.MouseY;
        mouse_raw_x_ = eqEventReplayChannel.MouseRawX;
        mouse_raw_y_ = eqEventReplayChannel.MouseRawY;
        buttons_ = eqEventReplayChannel.Flags;
    }
    else if (input_method_ == 3)
    {
        ilong mouse_x = 0;
        ilong mouse_y = 0;

        ilong mouse_raw_x = 0;
        ilong mouse_raw_y = 0;
        ilong mouse_raw_z = 0;

        i8 mouse_button_l = 0;
        i8 mouse_button_r = 0;
        i8 mouse_button_m = 0;

        geinputGetMouse(&mouse_x, &mouse_y, &mouse_button_l, &mouse_button_r, &mouse_raw_x, &mouse_raw_y, &mouse_raw_z,
            &mouse_button_m);

        mouse_x_ = mouse_x;
        mouse_y_ = mouse_y;

        mouse_raw_x_ = mouse_raw_x;
        mouse_raw_y_ = mouse_raw_y;

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
        eqEventReplayChannel.MouseRawX = mouse_raw_x_;
        eqEventReplayChannel.MouseRawY = mouse_raw_y_;
        eqEventReplayChannel.Flags = buttons_;
    }
}

static mem::cmd_param PARAM_pause {"pause"};

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
            OnMouse(hwnd, uMsg, wParam, lParam);
            break;
        }

        case WM_KEYDOWN:
        case WM_KEYUP:
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP: {
            OnKeyPress(hwnd, uMsg, wParam, lParam);
            break;
        }

        case WM_CHAR: {
            OnCharPress(hwnd, uMsg, wParam, lParam);
            break;
        }

        case WM_SETCURSOR: {
            if (/*(InitialCursorState != -1) ||*/ (LOWORD(lParam) != HTCLIENT))
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
                Displayf("\n\n***** HWND = %p, New Size = %d x %d", hwnd, LOWORD(lParam), HIWORD(lParam));

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
                    focused = !PARAM_pause.get_or(true);

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

            if (focused)
            {
                CurrentKeyModifiers = 0;

                if (input_method_)
                {
                    geinputAcquireKeyboard();
                    geinputGetBufferedKeyboard(nullptr);
                }

                if (input_method_ == 3)
                    geinputAcquireMouse();
            }

            for (eqEventMonitor* monitor : monitors_)
            {
                if (monitor && (monitor->channels_ & channels_))
                    monitor->Refocus(hwnd, focused);
            }

            break;
        }

        case WM_PAINT: {
            for (eqEventMonitor* monitor : monitors_)
            {
                if (monitor && (monitor->channels_ & channels_))
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

void WINEventHandler::OnKeyPress(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    u32 key_mods = 0;

    switch (wParam)
    {
        case EQ_VK_CONTROL: key_mods = EQ_KMOD_CTRL; break;
        case EQ_VK_MENU: key_mods = EQ_KMOD_ALT; break;
        case EQ_VK_SHIFT: key_mods = EQ_KMOD_SHIFT; break;
    }

    if ((uMsg == WM_KEYDOWN) || (uMsg == WM_SYSKEYDOWN))
        CurrentKeyModifiers |= key_mods;
    else
        CurrentKeyModifiers &= ~key_mods;

    u32 modifiers = CurrentKeyModifiers;

    if (!(lParam & 0x80000000))
    {
        modifiers |= EQ_KMOD_DOWN;

        if (lParam & 0x40000000)
            modifiers |= EQ_KMOD_REPEAT;
    }

    for (eqEventMonitor* monitor : monitors_)
    {
        if (monitor && (monitor->channels_ & channels_))
            monitor->Keyboard(hwnd, modifiers, wParam, 0, lParam);
    }

    if (eqReplay::Recording)
        eqEventReplayChannel.QueueKeyboard(modifiers, wParam, 0, 0);
}

void WINEventHandler::OnCharPress(HWND hwnd, UINT /*uMsg*/, WPARAM wParam, LPARAM lParam)
{
    u32 modifiers = CurrentKeyModifiers;

    if (!(lParam & 0x80000000))
    {
        modifiers |= EQ_KMOD_DOWN;

        if (lParam & 0x40000000)
            modifiers |= EQ_KMOD_REPEAT;
    }

    for (eqEventMonitor* monitor : monitors_)
    {
        if (monitor && (monitor->channels_ & channels_))
            monitor->Keyboard(hwnd, modifiers, 0, wParam, lParam);
    }

    if (eqReplay::Recording)
        eqEventReplayChannel.QueueKeyboard(modifiers, 0, wParam, 0);
}

void WINEventHandler::OnMouse(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_MOUSEMOVE)
    {
        if (!wants_motion_ && !(wParam & (MK_LBUTTON | MK_RBUTTON | MK_MBUTTON)))
            return;
    }

    buttons_ = 0;

    if (wParam & MK_LBUTTON)
        buttons_ |= EQ_BUTTON_LEFT;

    if (wParam & MK_RBUTTON)
        buttons_ |= EQ_BUTTON_RIGHT;

    if (wParam & MK_MBUTTON)
        buttons_ |= EQ_BUTTON_MIDDLE;

    if (uMsg == WM_MOUSEWHEEL) // Not sent when using MouseDevice
    {
        MouseScrollWheelPosition += GET_WHEEL_DELTA_WPARAM(wParam);
        u32 key_press = 0;

        if (MouseScrollWheelPosition >= WHEEL_DELTA)
        {
            MouseScrollWheelPosition -= WHEEL_DELTA;
            buttons_ |= EQ_BUTTON_WHEEL_UP;
            key_press = EQ_VK_LEFT;
        }
        else if (MouseScrollWheelPosition <= -WHEEL_DELTA)
        {
            MouseScrollWheelPosition += WHEEL_DELTA;
            buttons_ |= EQ_BUTTON_WHEEL_DOWN;
            key_press = EQ_VK_RIGHT;
        }

        // Emulates scrolling for widgets which support VK_[LEFT/RIGHT]
        // if (key_press)
        // {
        //     OnKeyPress(hwnd, WM_KEYDOWN, key_press, 0x00000000);
        //     OnKeyPress(hwnd, WM_KEYUP, key_press, 0xC0000000);
        // }
    }
    else
    {
        mouse_x_ = GET_X_LPARAM(lParam);
        mouse_y_ = GET_Y_LPARAM(lParam);
    }

    RECT rect;
    GetWindowRect(hwnd, &rect);

    if (tracked_events_ & 0x1)
        AdjustMouse(mouse_x_, mouse_y_);

    u32 changed_buttons = buttons_ ^ prev_buttons_;
    u32 new_buttons = buttons_ & changed_buttons;

    for (eqEventMonitor* monitor : monitors_)
    {
        if (monitor && (monitor->channels_ & channels_))
            monitor->Mouse(hwnd, new_buttons, changed_buttons, buttons_, mouse_x_, mouse_y_, rect.left, rect.top);
    }

    if (eqReplay::Recording)
        eqEventReplayChannel.QueueMouse(
            new_buttons, changed_buttons, buttons_, mouse_x_, mouse_y_, rect.left, rect.top);

    prev_buttons_ = buttons_;
}