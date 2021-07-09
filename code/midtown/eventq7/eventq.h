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

/*
    eventq7:eventq

    0x5639F0 | public: __thiscall eqEventQ::eqEventQ(int,int,int) | ??0eqEventQ@@QAE@HHH@Z
    0x563A80 | public: virtual __thiscall eqEventQ::~eqEventQ(void) | ??1eqEventQ@@UAE@XZ
    0x563AF0 | public: virtual void __thiscall eqEventQ::Redraw(void *,int,int,int,int) | ?Redraw@eqEventQ@@UAEXPAXHHHH@Z
    0x563B50 | public: virtual void __thiscall eqEventQ::Refocus(void *,int) | ?Refocus@eqEventQ@@UAEXPAXH@Z
    0x563B90 | public: virtual void __thiscall eqEventQ::Mouse(void *,int,int,int,int,int,int,int) | ?Mouse@eqEventQ@@UAEXPAXHHHHHHH@Z
    0x563C20 | public: virtual void __thiscall eqEventQ::Keyboard(void *,int,int,int,int) | ?Keyboard@eqEventQ@@UAEXPAXHHHH@Z
    0x563C80 | public: virtual void __thiscall eqEventQ::Destroy(void *) | ?Destroy@eqEventQ@@UAEXPAX@Z
    0x563CC0 | public: virtual void __thiscall eqEventQ::Activate(void *,int) | ?Activate@eqEventQ@@UAEXPAXH@Z
    0x563D00 | private: void __thiscall eqEventQ::Queue(union eqEvent &) | ?Queue@eqEventQ@@AAEXAATeqEvent@@@Z
    0x563D40 | public: int __thiscall eqEventQ::Pop(union eqEvent *) | ?Pop@eqEventQ@@QAEHPATeqEvent@@@Z
    0x563DB0 | public: virtual void * __thiscall eqEventQ::`vector deleting destructor'(unsigned int) | ??_EeqEventQ@@UAEPAXI@Z
    0x563DB0 | public: virtual void * __thiscall eqEventQ::`scalar deleting destructor'(unsigned int) | ??_GeqEventQ@@UAEPAXI@Z
    0x621B00 | const eqEventQ::`vftable' | ??_7eqEventQ@@6B@
*/

#include "event.h"

enum class eqEventType : u32
{
    Redraw = 0x0,
    Refocus = 0x1,
    Mouse = 0x2,
    Keyboard = 0x3,
    Destroy = 0x5,
    Activate = 0x6,
};

#define EQ_EVENT_MASK(EVENT) (1 << static_cast<u32>(EVENT))

struct eqCommonEvent
{
    void* Window;
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

union eqEvent
{
    eqCommonEvent Common;

    eqRedrawEvent Redraw;
    eqRefocusEvent Refocus;
    eqMouseEvent Mouse;
    eqKeyboardEvent Key;
    eqDestroyEvent Destroy;
    eqActivateEvent Activate;
};

check_size(eqEvent, 0x24);

class eqEventQ final : public eqEventMonitor
{
    // const eqEventQ::`vftable' @ 0x621B00

public:
    // 0x5639F0 | ??0eqEventQ@@QAE@HHH@Z
    ARTS_EXPORT eqEventQ(i32 arg1, i32 enabled_events, i32 max_events);

    // 0x563DB0 | ??_GeqEventQ@@UAEPAXI@Z
    // 0x563DB0 | ??_EeqEventQ@@UAEPAXI@Z
    // 0x563A80 | ??1eqEventQ@@UAE@XZ
    ARTS_EXPORT ~eqEventQ() override;

    // 0x563CC0 | ?Activate@eqEventQ@@UAEXPAXH@Z
    ARTS_EXPORT void Activate(void* window, b32 active) override;

    // 0x563C80 | ?Destroy@eqEventQ@@UAEXPAX@Z
    ARTS_EXPORT void Destroy(void* window) override;

    // 0x563C20 | ?Keyboard@eqEventQ@@UAEXPAXHHHH@Z
    ARTS_EXPORT void Keyboard(void* window, i32 modifiers, i32 virtual_key, i32 ascii_key, i32 state) override;

    // 0x563B90 | ?Mouse@eqEventQ@@UAEXPAXHHHHHHH@Z
    ARTS_EXPORT void Mouse(void* window, i32 new_buttons, i32 changed_buttons, i32 buttons, i32 mouse_x, i32 mouse_y,
        i32 window_x, i32 window_y) override;

    // 0x563D40 | ?Pop@eqEventQ@@QAEHPATeqEvent@@@Z
    ARTS_EXPORT b32 Pop(union eqEvent* event);

    // 0x563AF0 | ?Redraw@eqEventQ@@UAEXPAXHHHH@Z
    ARTS_EXPORT void Redraw(void* window, i32 arg2, i32 arg3, i32 arg4, i32 arg5) override;

    // 0x563B50 | ?Refocus@eqEventQ@@UAEXPAXH@Z
    ARTS_EXPORT void Refocus(void* window, i32 focused) override;

    void Clear();

private:
    // 0x563D00 | ?Queue@eqEventQ@@AAEXAATeqEvent@@@Z
    ARTS_EXPORT void Queue(union eqEvent& event);

    Ptr<eqEvent[]> events_;
    u32 enabled_events_ {0};
    u32 max_events_ {0};
    u32 write_head_ {0};
    u32 read_head_ {0};
    b32 registered_ {0};
};

check_size(eqEventQ, 0x2C);
