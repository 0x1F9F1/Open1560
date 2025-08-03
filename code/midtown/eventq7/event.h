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

#include "replay.h"

class eqEventMonitor;

class eqEventHandler
{
public:
    // ??0eqEventHandler@@QAE@XZ
    ARTS_EXPORT eqEventHandler();

    // ??_GeqEventHandler@@UAEPAXI@Z
    // ??_EeqEventHandler@@UAEPAXI@Z
    // ??1eqEventHandler@@UAE@XZ
    ARTS_EXPORT virtual ~eqEventHandler();

    virtual i32 BeginGfx(i32 width, i32 height, b32 fullscreen) = 0;

    virtual void EndGfx() = 0;

    virtual void Update(i32 = 0) = 0;

    virtual void BeginTracking() = 0;

    virtual void EndTracking() = 0;

    virtual const char* GKeyName(i32 arg1) = 0;

    // ?AddClient@eqEventHandler@@QAEXPAVeqEventMonitor@@@Z
    ARTS_EXPORT void AddClient(eqEventMonitor* monitor);

    // ?RemoveClient@eqEventHandler@@QAEXPAVeqEventMonitor@@@Z
    ARTS_EXPORT void RemoveClient(eqEventMonitor* monitor);

    // ?EKeyName@eqEventHandler@@SAPADH@Z | unused
    ARTS_EXPORT static const char* EKeyName(i32 key_code);

    // ?SuperQ@eqEventHandler@@2PAV1@A
    ARTS_EXPORT static eqEventHandler* SuperQ;

protected:
    friend class eqEventMonitor;

    b32 debug_ {};
    u32 tracked_events_ {};
    i32 channels_ {-1};
    eqEventMonitor* monitors_[8] {};
    u32 wants_motion_ {1};
    i32 mouse_x_ {};
    i32 mouse_y_ {};
    u32 buttons_ {};
    i32 tracking_x_ {};
    i32 tracking_y_ {};
    u32 prev_buttons_ {};
    u8 key_states_[256] {};
    f32 center_x_ {};
    f32 center_y_ {};
    f32 scale_x_ {};
    f32 scale_y_ {};
    i32 mouse_virtual_x_ {};
    i32 mouse_virtual_y_ {};
};

check_size(eqEventHandler, 0x164);

class eqEventMonitor
{
public:
    // ??0eqEventMonitor@@QAE@H@Z
    ARTS_EXPORT eqEventMonitor(i32 channels);

    // ??_EeqEventMonitor@@UAEPAXI@Z
    // ??_GeqEventMonitor@@UAEPAXI@Z
    // ??1eqEventMonitor@@UAE@XZ
    ARTS_EXPORT virtual ~eqEventMonitor();

    // ?Redraw@eqEventMonitor@@UAEXPAXHHHH@Z
    ARTS_EXPORT virtual void Redraw(void* window, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

    // ?Refocus@eqEventMonitor@@UAEXPAXH@Z
    ARTS_EXPORT virtual void Refocus(void* window, i32 focused);

    // ?Mouse@eqEventMonitor@@UAEXPAXHHHHHHH@Z
    ARTS_EXPORT virtual void Mouse(void* window, i32 new_buttons, i32 changed_buttons, i32 buttons, i32 mouse_x,
        i32 mouse_y, i32 window_x, i32 window_y);

    // ?Keyboard@eqEventMonitor@@UAEXPAXHHHH@Z
    ARTS_EXPORT virtual void Keyboard(void* window, i32 modifiers, i32 virtual_key, i32 ascii_key, i32 state);

    // ?Destroy@eqEventMonitor@@UAEXPAX@Z
    ARTS_EXPORT virtual void Destroy(void* window);

    // ?Activate@eqEventMonitor@@UAEXPAXH@Z
    ARTS_EXPORT virtual void Activate(void* window, b32 active);

    // ?SetWantMotion@eqEventMonitor@@QAEXH@Z | unused
    ARTS_EXPORT void SetWantMotion(i32 enabled);

    // private:
    friend class eqEventHandler;

    eqEventHandler* handler_ {};
    u32 field_8 {};
    i32 handler_index_ {};
    u32 channels_ {};
};

check_size(eqEventMonitor, 0x14);

class eqEventReplayChannelClass final : public eqReplayChannel
{
public:
    // ??0eqEventReplayChannelClass@@QAE@XZ
    ARTS_EXPORT eqEventReplayChannelClass();

    // ??1eqEventReplayChannelClass@@QAE@XZ | inline
    ARTS_EXPORT ~eqEventReplayChannelClass() = default;

    // ?DoPlayback@eqEventReplayChannelClass@@UAEXPAVStream@@@Z
    ARTS_EXPORT void DoPlayback(Stream* file) override;

    // ?DoRecord@eqEventReplayChannelClass@@UAEXPAVStream@@@Z
    ARTS_EXPORT void DoRecord(Stream* file) override;

    // ?QueueKeyboard@eqEventReplayChannelClass@@QAEXHHHH@Z
    ARTS_EXPORT void QueueKeyboard(i32 arg1, i32 arg2, i32 arg3, i32 arg4);

    // ?QueueMouse@eqEventReplayChannelClass@@QAEXHHHHHHH@Z
    ARTS_EXPORT void QueueMouse(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7);

    u32 MouseX {};
    u32 MouseY {};
    u32 Flags {};
    u8 KeyStates[256] {};
    u32 MouseRawX {};
    u32 MouseRawY {};

    u32 Events[256] {};
    i32 EventCount {};

    u32 PrevMouseX {};
    u32 PrevMouseY {};
    u32 PrevFlags {};
    u8 PrevKeyStates[256] {};
    u32 PrevMouseRawX {};
    u32 PrevMouseRawY {};
};

check_size(eqEventReplayChannelClass, 0x638);

// ?DeallocateEventQueue@@YAXXZ
ARTS_EXPORT void DeallocateEventQueue();

// ?InitEventQueue@@YAXXZ
ARTS_EXPORT void InitEventQueue();

// ?CloseCallback@@3P6AXXZA
ARTS_EXPORT extern void (*CloseCallback)(void);

// ?eqEventReplayChannel@@3VeqEventReplayChannelClass@@A
ARTS_EXPORT extern eqEventReplayChannelClass eqEventReplayChannel;

extern mem::cmd_param PARAM_pause;
