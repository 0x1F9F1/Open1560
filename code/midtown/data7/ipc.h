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
    data7:ipc

    0x578650 | unsigned int __cdecl ipcCreateEvent(int) | ?ipcCreateEvent@@YAIH@Z
    0x578670 | unsigned int __cdecl ipcCreateMutex(int) | ?ipcCreateMutex@@YAIH@Z
    0x578690 | unsigned int __cdecl ipcCreateThread(unsigned long (__stdcall*)(void *),void *,unsigned long *) | ?ipcCreateThread@@YAIP6GKPAX@Z0PAK@Z
    0x5786B0 | void __cdecl ipcTriggerEvent(unsigned int) | ?ipcTriggerEvent@@YAXI@Z
    0x5786D0 | void __cdecl ipcReleaseMutex(unsigned int) | ?ipcReleaseMutex@@YAXI@Z
    0x5786F0 | void __cdecl ipcWaitSingle(unsigned int) | ?ipcWaitSingle@@YAXI@Z
    0x578720 | int __cdecl ipcWaitMultiple(int,unsigned int *,int) | ?ipcWaitMultiple@@YAHHPAIH@Z
    0x578740 | void __cdecl ipcCloseHandle(unsigned int) | ?ipcCloseHandle@@YAXI@Z
    0x578760 | void __cdecl ipcYield(void) | ?ipcYield@@YAXXZ
    0x578770 | void __cdecl ipcSleep(unsigned int) | ?ipcSleep@@YAXI@Z
    0x578780 | private: static unsigned long __stdcall ipcMessageQueue::Proc(void *) | ?Proc@ipcMessageQueue@@CGKPAX@Z
    0x578790 | private: int __thiscall ipcMessageQueue::MessageLoop(void) | ?MessageLoop@ipcMessageQueue@@AAEHXZ
    0x578870 | public: void __thiscall ipcMessageQueue::Init(int,int) | ?Init@ipcMessageQueue@@QAEXHH@Z
    0x578920 | public: void __thiscall ipcMessageQueue::Shutdown(void) | ?Shutdown@ipcMessageQueue@@QAEXXZ
    0x578980 | public: void __thiscall ipcMessageQueue::Send(void (__cdecl*)(void *),void *) | ?Send@ipcMessageQueue@@QAEXP6AXPAX@Z0@Z
    0x578A70 | void __cdecl ipcSpinLock(unsigned int *) | ?ipcSpinLock@@YAXPAI@Z
    0x578AC0 | void __cdecl ipcSpunUnlock(unsigned int *) | ?ipcSpunUnlock@@YAXPAI@Z
    0x578AF0 | void __cdecl ipcCreateSpinLock(unsigned int *) | ?ipcCreateSpinLock@@YAXPAI@Z
    0x578B00 | void __cdecl ipcCloseSpinLock(unsigned int *) | ?ipcCloseSpinLock@@YAXPAI@Z
    0x90AE60 | int SynchronousMessageQueues | ?SynchronousMessageQueues@@3HA
    0x578AB0 | int __fastcall compareExchange(unsigned int *,int) | ?compareExchange@@YIHPAIH@Z
*/

// 0x578740 | ?ipcCloseHandle@@YAXI@Z
void ipcCloseHandle(u32 arg1);

// 0x578B00 | ?ipcCloseSpinLock@@YAXPAI@Z
void ipcCloseSpinLock(u32* arg1);

// 0x578650 | ?ipcCreateEvent@@YAIH@Z
u32 ipcCreateEvent(i32 arg1);

// 0x578670 | ?ipcCreateMutex@@YAIH@Z
u32 ipcCreateMutex(i32 arg1);

// 0x578AF0 | ?ipcCreateSpinLock@@YAXPAI@Z
void ipcCreateSpinLock(u32* arg1);

// 0x578690 | ?ipcCreateThread@@YAIP6GKPAX@Z0PAK@Z
u32 ipcCreateThread(u32(__stdcall* arg1)(void*), void* arg2, u32* arg3);

// 0x5786D0 | ?ipcReleaseMutex@@YAXI@Z
void ipcReleaseMutex(u32 arg1);

// 0x578770 | ?ipcSleep@@YAXI@Z
void ipcSleep(u32 arg1);

// 0x578A70 | ?ipcSpinLock@@YAXPAI@Z
void ipcSpinLock(u32* arg1);

// 0x578AC0 | ?ipcSpunUnlock@@YAXPAI@Z
void ipcSpunUnlock(u32* arg1);

// 0x5786B0 | ?ipcTriggerEvent@@YAXI@Z
void ipcTriggerEvent(u32 arg1);

// 0x578720 | ?ipcWaitMultiple@@YAHHPAIH@Z
i32 ipcWaitMultiple(i32 arg1, u32* arg2, i32 arg3);

// 0x5786F0 | ?ipcWaitSingle@@YAXI@Z
void ipcWaitSingle(u32 arg1);

// 0x578760 | ?ipcYield@@YAXXZ
void ipcYield();

// 0x90AE60 | ?SynchronousMessageQueues@@3HA
inline extern_var(0x90AE60, i32, SynchronousMessageQueues);

class ipcMessageQueue
{
public:
    // 0x578870 | ?Init@ipcMessageQueue@@QAEXHH@Z
    void Init(i32 arg1, i32 arg2);

    // 0x578980 | ?Send@ipcMessageQueue@@QAEXP6AXPAX@Z0@Z
    void Send(void (*arg1)(void*), void* arg2);

    // 0x578920 | ?Shutdown@ipcMessageQueue@@QAEXXZ
    void Shutdown();

private:
    // 0x578790 | ?MessageLoop@ipcMessageQueue@@AAEHXZ
    i32 MessageLoop();

    // 0x578780 | ?Proc@ipcMessageQueue@@CGKPAX@Z
    static u32 __stdcall Proc(void* arg1);

    char gap0[0x28];
};

check_size(ipcMessageQueue, 0x28);
