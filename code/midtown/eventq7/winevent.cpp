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

#include "key_codes.h"
#include "pcwindis/pcwindis.h"
#include "replay.h"

#include <windowsx.h>

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

static i32 MouseScrollWheelPosition = 0;
static u32 CurrentKeyModifiers = 0;
static u32 OldPriorityClass = 0;

// TODO: Include mmautio/manager.h
ARTS_IMPORT void RestoreApplication();
ARTS_IMPORT void DeactivateApplication();

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
