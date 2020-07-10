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
    eventq7:event

    0x562EB0 | public: __thiscall eqEventHandler::eqEventHandler(void) | ??0eqEventHandler@@QAE@XZ
    0x562F00 | public: virtual __thiscall eqEventHandler::~eqEventHandler(void) | ??1eqEventHandler@@UAE@XZ
    0x562F30 | public: static char * __cdecl eqEventHandler::EKeyName(int) | ?EKeyName@eqEventHandler@@SAPADH@Z
    0x563200 | public: void __thiscall eqEventHandler::AddClient(class eqEventMonitor *) | ?AddClient@eqEventHandler@@QAEXPAVeqEventMonitor@@@Z
    0x563260 | public: void __thiscall eqEventHandler::RemoveClient(class eqEventMonitor *) | ?RemoveClient@eqEventHandler@@QAEXPAVeqEventMonitor@@@Z
    0x5632A0 | public: __thiscall eqEventMonitor::eqEventMonitor(int) | ??0eqEventMonitor@@QAE@H@Z
    0x5632C0 | public: virtual __thiscall eqEventMonitor::~eqEventMonitor(void) | ??1eqEventMonitor@@UAE@XZ
    0x5632E0 | public: virtual void __thiscall eqEventMonitor::Redraw(void *,int,int,int,int) | ?Redraw@eqEventMonitor@@UAEXPAXHHHH@Z
    0x563320 | public: virtual void __thiscall eqEventMonitor::Refocus(void *,int) | ?Refocus@eqEventMonitor@@UAEXPAXH@Z
    0x563360 | public: virtual void __thiscall eqEventMonitor::Mouse(void *,int,int,int,int,int,int,int) | ?Mouse@eqEventMonitor@@UAEXPAXHHHHHHH@Z
    0x5633E0 | public: virtual void __thiscall eqEventMonitor::Keyboard(void *,int,int,int,int) | ?Keyboard@eqEventMonitor@@UAEXPAXHHHH@Z
    0x563470 | public: virtual void __thiscall eqEventMonitor::Destroy(void *) | ?Destroy@eqEventMonitor@@UAEXPAX@Z
    0x5634A0 | public: virtual void __thiscall eqEventMonitor::Activate(void *,int) | ?Activate@eqEventMonitor@@UAEXPAXH@Z
    0x5634E0 | public: void __thiscall eqEventMonitor::SetWantMotion(int) | ?SetWantMotion@eqEventMonitor@@QAEXH@Z
    0x563560 | public: __thiscall eqEventReplayChannelClass::eqEventReplayChannelClass(void) | ??0eqEventReplayChannelClass@@QAE@XZ
    0x563580 | public: virtual void __thiscall eqEventReplayChannelClass::DoRecord(class Stream *) | ?DoRecord@eqEventReplayChannelClass@@UAEXPAVStream@@@Z
    0x563790 | public: virtual void __thiscall eqEventReplayChannelClass::DoPlayback(class Stream *) | ?DoPlayback@eqEventReplayChannelClass@@UAEXPAVStream@@@Z
    0x563880 | public: void __thiscall eqEventReplayChannelClass::QueueMouse(int,int,int,int,int,int,int) | ?QueueMouse@eqEventReplayChannelClass@@QAEXHHHHHHH@Z
    0x563910 | public: void __thiscall eqEventReplayChannelClass::QueueKeyboard(int,int,int,int) | ?QueueKeyboard@eqEventReplayChannelClass@@QAEXHHHH@Z
    0x563980 | public: virtual void * __thiscall eqEventHandler::`vector deleting destructor'(unsigned int) | ??_EeqEventHandler@@UAEPAXI@Z
    0x563980 | public: virtual void * __thiscall eqEventHandler::`scalar deleting destructor'(unsigned int) | ??_GeqEventHandler@@UAEPAXI@Z
    0x5639B0 | public: virtual void * __thiscall eqEventMonitor::`scalar deleting destructor'(unsigned int) | ??_GeqEventMonitor@@UAEPAXI@Z
    0x5639B0 | public: virtual void * __thiscall eqEventMonitor::`vector deleting destructor'(unsigned int) | ??_EeqEventMonitor@@UAEPAXI@Z
    0x5639E0 | public: __thiscall eqEventReplayChannelClass::~eqEventReplayChannelClass(void) | ??1eqEventReplayChannelClass@@QAE@XZ
    0x621AA8 | const eqEventHandler::`vftable' | ??_7eqEventHandler@@6B@
    0x621AC8 | const eqEventMonitor::`vftable' | ??_7eqEventMonitor@@6B@
    0x621AE8 | const eqEventReplayChannelClass::`vftable' | ??_7eqEventReplayChannelClass@@6B@
    0x908C58 | class eqEventReplayChannelClass eqEventReplayChannel | ?eqEventReplayChannel@@3VeqEventReplayChannelClass@@A
    0x909290 | public: static class eqEventHandler * eqEventHandler::SuperQ | ?SuperQ@eqEventHandler@@2PAV1@A
*/

#include "replay.h"

class eqEventMonitor;

class eqEventHandler
{
    // const eqEventHandler::`vftable' @ 0x621AA8

public:
    // 0x562EB0 | ??0eqEventHandler@@QAE@XZ
    ARTS_EXPORT eqEventHandler();

    // 0x563980 | ??_GeqEventHandler@@UAEPAXI@Z
    // 0x563980 | ??_EeqEventHandler@@UAEPAXI@Z
    // 0x562F00 | ??1eqEventHandler@@UAE@XZ
    ARTS_EXPORT virtual ~eqEventHandler();

    virtual i32 BeginGfx(i32 arg1, i32 arg2, i32 arg3) = 0;

    virtual void EndGfx() = 0;

    virtual void Update(i32 arg1) = 0;

    virtual void BeginTracking() = 0;

    virtual void EndTracking() = 0;

    virtual const char* GKeyName(i32 arg1) = 0;

    // 0x563200 | ?AddClient@eqEventHandler@@QAEXPAVeqEventMonitor@@@Z
    ARTS_EXPORT void AddClient(class eqEventMonitor* monitor);

    // 0x563260 | ?RemoveClient@eqEventHandler@@QAEXPAVeqEventMonitor@@@Z
    ARTS_EXPORT void RemoveClient(class eqEventMonitor* monitor);

    // 0x562F30 | ?EKeyName@eqEventHandler@@SAPADH@Z | unused
    ARTS_EXPORT static const char* EKeyName(i32 key_code);

    // 0x909290 | ?SuperQ@eqEventHandler@@2PAV1@A
    ARTS_IMPORT static class eqEventHandler* SuperQ;

protected:
    friend class eqEventMonitor;

    b32 debug_ {false};
    u32 tracked_events_ {0};
    i32 dwordC {-1};
    eqEventMonitor* monitors_[8] {};
    u32 wants_motion_ {1};
    i32 mouse_x_ {0};
    i32 mouse_y_ {0};
    u32 buttons_ {0};
    i32 cursor_x_ {0};
    i32 cursor_y_ {0};
    u32 prev_buttons_ {0};
    u8 key_states_[256] {};
    f32 center_x_ {0.0f};
    f32 center_y_ {0.0f};
    f32 scale_x_ {0.0f};
    f32 scale_y_ {0.0f};
    i32 mouse_delta_x_ {0};
    i32 mouse_delta_y_ {0};
};

check_size(eqEventHandler, 0x164);

class eqEventMonitor
{
    // const eqEventMonitor::`vftable' @ 0x621AC8

public:
    // 0x5632A0 | ??0eqEventMonitor@@QAE@H@Z
    ARTS_EXPORT eqEventMonitor(i32 arg1);

    // 0x5639B0 | ??_EeqEventMonitor@@UAEPAXI@Z
    // 0x5639B0 | ??_GeqEventMonitor@@UAEPAXI@Z
    // 0x5632C0 | ??1eqEventMonitor@@UAE@XZ
    ARTS_EXPORT virtual ~eqEventMonitor();

    // 0x5632E0 | ?Redraw@eqEventMonitor@@UAEXPAXHHHH@Z
    ARTS_EXPORT virtual void Redraw(void* window, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

    // 0x563320 | ?Refocus@eqEventMonitor@@UAEXPAXH@Z
    ARTS_EXPORT virtual void Refocus(void* window, i32 focused);

    // 0x563360 | ?Mouse@eqEventMonitor@@UAEXPAXHHHHHHH@Z
    ARTS_EXPORT virtual void Mouse(void* window, i32 new_buttons, i32 changed_buttons, i32 buttons, i32 mouse_x,
        i32 mouse_y, i32 window_x, i32 window_y);

    // 0x5633E0 | ?Keyboard@eqEventMonitor@@UAEXPAXHHHH@Z
    ARTS_EXPORT virtual void Keyboard(void* window, i32 modifiers, i32 virtual_key, i32 ascii_key, i32 state);

    // 0x563470 | ?Destroy@eqEventMonitor@@UAEXPAX@Z
    ARTS_EXPORT virtual void Destroy(void* window);

    // 0x5634A0 | ?Activate@eqEventMonitor@@UAEXPAXH@Z
    ARTS_EXPORT virtual void Activate(void* window, i32 active);

    // 0x5634E0 | ?SetWantMotion@eqEventMonitor@@QAEXH@Z | unused
    ARTS_EXPORT void SetWantMotion(i32 enabled);

    // private:
    friend class eqEventHandler;

    eqEventHandler* handler_ {nullptr};
    u32 dword8 {0};
    i32 handler_index_ {0};
    u32 dword10 {0};
};

check_size(eqEventMonitor, 0x14);

class eqEventReplayChannelClass /*final*/ : public eqReplayChannel
{
    // const eqEventReplayChannelClass::`vftable' @ 0x621AE8

public:
    // 0x563560 | ??0eqEventReplayChannelClass@@QAE@XZ
    ARTS_EXPORT eqEventReplayChannelClass();

    // 0x5639E0 | ??1eqEventReplayChannelClass@@QAE@XZ | inline
    ARTS_EXPORT ~eqEventReplayChannelClass() = default;

    // 0x563790 | ?DoPlayback@eqEventReplayChannelClass@@UAEXPAVStream@@@Z
    ARTS_EXPORT void DoPlayback(class Stream* file) override;

    // 0x563580 | ?DoRecord@eqEventReplayChannelClass@@UAEXPAVStream@@@Z
    ARTS_EXPORT void DoRecord(class Stream* file) override;

    // 0x563910 | ?QueueKeyboard@eqEventReplayChannelClass@@QAEXHHHH@Z
    ARTS_EXPORT void QueueKeyboard(i32 arg1, i32 arg2, i32 arg3, i32 arg4);

    // 0x563880 | ?QueueMouse@eqEventReplayChannelClass@@QAEXHHHHHHH@Z
    ARTS_EXPORT void QueueMouse(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7);

    u32 MouseX {0};
    u32 MouseY {0};
    u32 Flags {0};
    u8 KeyStates[256] {};
    u32 MouseDeltaX {0};
    u32 MouseDeltaY {0};

    u32 Events[256] {};
    i32 EventCount {0};

    u32 PrevMouseX {0};
    u32 PrevMouseY {0};
    u32 PrevFlags {0};
    u8 PrevKeyStates[256] {};
    u32 PrevMouseDeltaX {0};
    u32 PrevMouseDeltaY {0};
};

check_size(eqEventReplayChannelClass, 0x638);

// 0x908C58 | ?eqEventReplayChannel@@3VeqEventReplayChannelClass@@A
ARTS_IMPORT extern class eqEventReplayChannelClass eqEventReplayChannel;
