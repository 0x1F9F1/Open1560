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
    unimplemented(arg1);
}

i32 eqEventHandler::BeginGfx(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<i32, eqEventHandler*, i32, i32, i32>>(0x - 400000_Offset, this, arg1, arg2, arg3);
}

void eqEventHandler::EndGfx()
{
    return stub<thiscall_t<void, eqEventHandler*>>(0x - 400000_Offset, this);
}

void eqEventHandler::Update(i32 arg1)
{
    return stub<thiscall_t<void, eqEventHandler*, i32>>(0x - 400000_Offset, this, arg1);
}

void eqEventHandler::BeginTracking()
{
    return stub<thiscall_t<void, eqEventHandler*>>(0x - 400000_Offset, this);
}

void eqEventHandler::EndTracking()
{
    return stub<thiscall_t<void, eqEventHandler*>>(0x - 400000_Offset, this);
}

char* eqEventHandler::GKeyName(i32 arg1)
{
    return stub<thiscall_t<char*, eqEventHandler*, i32>>(0x - 400000_Offset, this, arg1);
}

void eqEventHandler::AddClient(class eqEventMonitor* arg1)
{
    return stub<thiscall_t<void, eqEventHandler*, class eqEventMonitor*>>(0x163200_Offset, this, arg1);
}

void eqEventHandler::RemoveClient(class eqEventMonitor* arg1)
{
    return stub<thiscall_t<void, eqEventHandler*, class eqEventMonitor*>>(0x163260_Offset, this, arg1);
}

char* eqEventHandler::EKeyName(i32 arg1)
{
    return stub<cdecl_t<char*, i32>>(0x162F30_Offset, arg1);
}

eqEventMonitor::eqEventMonitor(i32 arg1)
{
    unimplemented(arg1);
}

eqEventMonitor::~eqEventMonitor()
{
    unimplemented(arg1);
}

void eqEventMonitor::Redraw(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*, i32, i32, i32, i32>>(
        0x1632E0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void eqEventMonitor::Refocus(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*, i32>>(0x163320_Offset, this, arg1, arg2);
}

void eqEventMonitor::Mouse(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*, i32, i32, i32, i32, i32, i32, i32>>(
        0x163360_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void eqEventMonitor::Keyboard(void* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*, i32, i32, i32, i32>>(
        0x1633E0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void eqEventMonitor::Destroy(void* arg1)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*>>(0x163470_Offset, this, arg1);
}

void eqEventMonitor::Activate(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, eqEventMonitor*, void*, i32>>(0x1634A0_Offset, this, arg1, arg2);
}

void eqEventMonitor::SetWantMotion(i32 arg1)
{
    return stub<thiscall_t<void, eqEventMonitor*, i32>>(0x1634E0_Offset, this, arg1);
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
    return stub<thiscall_t<void, eqEventReplayChannelClass*, class Stream*>>(0x163790_Offset, this, arg1);
}

void eqEventReplayChannelClass::DoRecord(class Stream* arg1)
{
    return stub<thiscall_t<void, eqEventReplayChannelClass*, class Stream*>>(0x163580_Offset, this, arg1);
}

void eqEventReplayChannelClass::QueueKeyboard(i32 arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, eqEventReplayChannelClass*, i32, i32, i32, i32>>(
        0x163910_Offset, this, arg1, arg2, arg3, arg4);
}

void eqEventReplayChannelClass::QueueMouse(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, eqEventReplayChannelClass*, i32, i32, i32, i32, i32, i32, i32>>(
        0x163880_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
