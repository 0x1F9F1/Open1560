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

define_dummy_symbol(data7_ipc);

#include "ipc.h"

void ipcCloseHandle(u32 arg1)
{
    return stub<cdecl_t<void, u32>>(0x578740, arg1);
}

void ipcCloseSpinLock(u32* arg1)
{
    return stub<cdecl_t<void, u32*>>(0x578B00, arg1);
}

u32 ipcCreateEvent(i32 arg1)
{
    return stub<cdecl_t<u32, i32>>(0x578650, arg1);
}

u32 ipcCreateMutex(i32 arg1)
{
    return stub<cdecl_t<u32, i32>>(0x578670, arg1);
}

void ipcCreateSpinLock(u32* arg1)
{
    return stub<cdecl_t<void, u32*>>(0x578AF0, arg1);
}

u32 ipcCreateThread(u32(__stdcall* arg1)(void*), void* arg2, u32* arg3)
{
    return stub<cdecl_t<u32, u32(__stdcall*)(void*), void*, u32*>>(0x578690, arg1, arg2, arg3);
}

void ipcReleaseMutex(u32 arg1)
{
    return stub<cdecl_t<void, u32>>(0x5786D0, arg1);
}

void ipcSleep(u32 arg1)
{
    return stub<cdecl_t<void, u32>>(0x578770, arg1);
}

void ipcSpinLock(u32* arg1)
{
    return stub<cdecl_t<void, u32*>>(0x578A70, arg1);
}

void ipcSpunUnlock(u32* arg1)
{
    return stub<cdecl_t<void, u32*>>(0x578AC0, arg1);
}

void ipcTriggerEvent(u32 arg1)
{
    return stub<cdecl_t<void, u32>>(0x5786B0, arg1);
}

i32 ipcWaitMultiple(i32 arg1, u32* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, i32, u32*, i32>>(0x578720, arg1, arg2, arg3);
}

void ipcWaitSingle(u32 arg1)
{
    return stub<cdecl_t<void, u32>>(0x5786F0, arg1);
}

void ipcYield()
{
    return stub<cdecl_t<void>>(0x578760);
}

static i32 __fastcall compareExchange(u32* arg1, i32 arg2)
{
    return stub<fastcall_t<i32, u32*, i32>>(0x578AB0, arg1, arg2);
}

void ipcMessageQueue::Init(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, ipcMessageQueue*, i32, i32>>(0x578870, this, arg1, arg2);
}

void ipcMessageQueue::Send(void (*arg1)(void*), void* arg2)
{
    return stub<thiscall_t<void, ipcMessageQueue*, void (*)(void*), void*>>(0x578980, this, arg1, arg2);
}

void ipcMessageQueue::Shutdown()
{
    return stub<thiscall_t<void, ipcMessageQueue*>>(0x578920, this);
}

i32 ipcMessageQueue::MessageLoop()
{
    return stub<thiscall_t<i32, ipcMessageQueue*>>(0x578790, this);
}

u32 __stdcall ipcMessageQueue::Proc(void* arg1)
{
    return stub<stdcall_t<u32, void*>>(0x578780, arg1);
}
