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

#include "event.h"

enum class eqEventType : u32
{
    Redraw = 0,
    Refocus = 1,
    Mouse = 2,
    Keyboard = 3,
    Destroy = 5,
    Activate = 6,
};

#define EQ_EVENT_MASK(EVENT) (1 << static_cast<u32>(EVENT))

struct eqCommonEvent
{
    void* Window;

    // TODO: Move before Window
    eqEventType Type;
};

struct eqRedrawEvent : eqCommonEvent
{
    i32 field_8;
    i32 field_C;
    i32 field_10;
    i32 field_14;
};

struct eqRefocusEvent : eqCommonEvent
{
    i32 Focused;
};

struct eqKeyboardEvent : eqCommonEvent
{
    i32 Modifiers; // EQ_KMOD_*
    i32 Key;       // EQ_KEY_* or EQ_VK_*
    i32 Char;      // Input character
    i32 State;     // Win32 Keystroke Message Flags
};

struct eqMouseEvent : eqCommonEvent
{
    i32 NewButtons;
    i32 ChangedButtons;
    i32 Buttons;
    i32 MouseX;
    i32 MouseY;
    i32 ScreenX;
    i32 ScreenY;
};

struct eqDestroyEvent : eqCommonEvent
{};

struct eqActivateEvent : eqCommonEvent
{
    b32 Active;
};

ARTS_DIAGNOSTIC_PUSH;
ARTS_MSVC_DIAGNOSTIC_IGNORED(4201); // nonstandard extension used: nameless struct/union

union eqEvent
{
    struct
    {
        void* Window;
        eqEventType Type;
    };

    eqRedrawEvent Redraw;
    eqRefocusEvent Refocus;
    eqMouseEvent Mouse;
    eqKeyboardEvent Key;
    eqDestroyEvent Destroy;
    eqActivateEvent Activate;
};

check_size(eqEvent, 0x24);

ARTS_DIAGNOSTIC_POP;

class eqEventQ final : public eqEventMonitor
{
public:
    // ??0eqEventQ@@QAE@HHH@Z
    ARTS_EXPORT eqEventQ(i32 channels, i32 enabled_events, i32 max_events);

    // ??_GeqEventQ@@UAEPAXI@Z
    // ??_EeqEventQ@@UAEPAXI@Z
    // ??1eqEventQ@@UAE@XZ
    ARTS_EXPORT ~eqEventQ() override;

    // ?Activate@eqEventQ@@UAEXPAXH@Z
    ARTS_EXPORT void Activate(void* window, b32 active) override;

    // ?Destroy@eqEventQ@@UAEXPAX@Z
    ARTS_EXPORT void Destroy(void* window) override;

    // ?Keyboard@eqEventQ@@UAEXPAXHHHH@Z
    ARTS_EXPORT void Keyboard(void* window, i32 modifiers, i32 virtual_key, i32 ascii_key, i32 state) override;

    // ?Mouse@eqEventQ@@UAEXPAXHHHHHHH@Z
    ARTS_EXPORT void Mouse(void* window, i32 new_buttons, i32 changed_buttons, i32 buttons, i32 mouse_x, i32 mouse_y,
        i32 window_x, i32 window_y) override;

    // ?Pop@eqEventQ@@QAEHPATeqEvent@@@Z
    ARTS_EXPORT b32 Pop(eqEvent* event);

    // ?Redraw@eqEventQ@@UAEXPAXHHHH@Z
    ARTS_EXPORT void Redraw(void* window, i32 arg2, i32 arg3, i32 arg4, i32 arg5) override;

    // ?Refocus@eqEventQ@@UAEXPAXH@Z
    ARTS_EXPORT void Refocus(void* window, i32 focused) override;

    void Clear();

private:
    // ?Queue@eqEventQ@@AAEXAATeqEvent@@@Z
    ARTS_EXPORT void Queue(eqEvent& event);

    Ptr<eqEvent[]> events_;
    u32 enabled_events_ {};
    u32 max_events_ {};
    u32 write_head_ {};
    u32 read_head_ {};
    b32 registered_ {};
};

check_size(eqEventQ, 0x2C);