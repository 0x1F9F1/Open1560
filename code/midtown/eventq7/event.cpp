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

define_dummy_symbol(eventq7_event);

#include "event.h"

eqEventHandler::eqEventHandler()
{
    unimplemented();
}

eqEventHandler::~eqEventHandler()
{
    unimplemented();
}

void eqEventHandler::AddClient(class eqEventMonitor* arg1)
{
    return stub<thiscall_t<void, eqEventHandler*, class eqEventMonitor*>>(0x563200, this, arg1);
}

void eqEventHandler::RemoveClient(class eqEventMonitor* arg1)
{
    return stub<thiscall_t<void, eqEventHandler*, class eqEventMonitor*>>(0x563260, this, arg1);
}

char* eqEventHandler::EKeyName(i32 arg1)
{
    return stub<cdecl_t<char*, i32>>(0x562F30, arg1);
}

eqEventMonitor::eqEventMonitor(i32 arg1)
{
    unimplemented(arg1);
}

eqEventMonitor::~eqEventMonitor()
{
    unimplemented();
}

void eqEventMonitor::Redraw(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*, i32, i32, i32, i32>>(
        0x5632E0, this, arg1, arg2, arg3, arg4, arg5);
}

void eqEventMonitor::Refocus(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*, i32>>(0x563320, this, arg1, arg2);
}

void eqEventMonitor::Mouse(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*, i32, i32, i32, i32, i32, i32, i32>>(
        0x563360, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void eqEventMonitor::Keyboard(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*, i32, i32, i32, i32>>(
        0x5633E0, this, arg1, arg2, arg3, arg4, arg5);
}

void eqEventMonitor::Destroy(void* arg1)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*>>(0x563470, this, arg1);
}

void eqEventMonitor::Activate(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*, i32>>(0x5634A0, this, arg1, arg2);
}

void eqEventMonitor::SetWantMotion(i32 arg1)
{
    return stub<thiscall_t<void, eqEventMonitor*, i32>>(0x5634E0, this, arg1);
}

eqEventReplayChannelClass::eqEventReplayChannelClass()
{
    unimplemented();
}

eqEventReplayChannelClass::~eqEventReplayChannelClass()
{
    unimplemented();
}

void eqEventReplayChannelClass::DoPlayback(class Stream* arg1)
{
    return stub<thiscall_t<void, eqEventReplayChannelClass*, class Stream*>>(0x563790, this, arg1);
}

void eqEventReplayChannelClass::DoRecord(class Stream* arg1)
{
    return stub<thiscall_t<void, eqEventReplayChannelClass*, class Stream*>>(0x563580, this, arg1);
}

void eqEventReplayChannelClass::QueueKeyboard(i32 arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, eqEventReplayChannelClass*, i32, i32, i32, i32>>(
        0x563910, this, arg1, arg2, arg3, arg4);
}

void eqEventReplayChannelClass::QueueMouse(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, eqEventReplayChannelClass*, i32, i32, i32, i32, i32, i32, i32>>(
        0x563880, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
