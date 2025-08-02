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
    0x578AB0 | int __fastcall compareExchange(unsigned int *,int) | ?compareExchange@@YIHPAIH@Z
    0x578AC0 | void __cdecl ipcSpunUnlock(unsigned int *) | ?ipcSpunUnlock@@YAXPAI@Z
    0x578AF0 | void __cdecl ipcCreateSpinLock(unsigned int *) | ?ipcCreateSpinLock@@YAXPAI@Z
    0x578B00 | void __cdecl ipcCloseSpinLock(unsigned int *) | ?ipcCloseSpinLock@@YAXPAI@Z
    0x90AE60 | int SynchronousMessageQueues | ?SynchronousMessageQueues@@3HA
*/

#include "callback.h"
#include "mutex.h"

#include <atomic>

// ?ipcCloseHandle@@YAXI@Z
[[deprecated]] ARTS_EXPORT void ipcCloseHandle(usize handle);

// ?ipcCloseSpinLock@@YAXPAI@Z | unused
ARTS_EXPORT void ipcCloseSpinLock(u32* value);

// ?ipcCreateEvent@@YAIH@Z
[[deprecated]] ARTS_EXPORT usize ipcCreateEvent(b32 initial_state);

// ?ipcCreateMutex@@YAIH@Z
[[deprecated]] ARTS_EXPORT usize ipcCreateMutex(b32 initial_owner);

// ?ipcCreateSpinLock@@YAXPAI@Z | unused
ARTS_EXPORT void ipcCreateSpinLock(u32* value);

// ?ipcCreateThread@@YAIP6GKPAX@Z0PAK@Z
ARTS_EXPORT usize ipcCreateThread(ulong(ARTS_STDCALL* start)(void*), void* param, ulong* thread_id);

void ipcWaitThreadExit(usize thread);

void ipcDeleteThread(usize thread);

// ?ipcReleaseMutex@@YAXI@Z
[[deprecated]] ARTS_EXPORT void ipcReleaseMutex(usize mutex);

// ?ipcSleep@@YAXI@Z | unused
ARTS_EXPORT void ipcSleep(u32 milli_seconds);

// ?ipcSpinLock@@YAXPAI@Z
ARTS_EXPORT void ipcSpinLock(u32* value);

// ?ipcSpunUnlock@@YAXPAI@Z | unused
ARTS_EXPORT void ipcSpinUnlock(u32* value);

// ?ipcTriggerEvent@@YAXI@Z
[[deprecated]] ARTS_EXPORT void ipcTriggerEvent(usize event);

// ?ipcWaitMultiple@@YAHHPAIH@Z | unused
[[deprecated]] ARTS_EXPORT i32 ipcWaitMultiple(i32 count, usize* handles, b32 wait_all);

// ?ipcWaitSingle@@YAXI@Z
[[deprecated]] ARTS_EXPORT void ipcWaitSingle(usize handle);

// ?ipcYield@@YAXXZ
ARTS_EXPORT void ipcYield();

// ?SynchronousMessageQueues@@3HA
ARTS_IMPORT extern b32 SynchronousMessageQueues;

#define IPC_QUEUE_MODE_ASYNC 0
#define IPC_QUEUE_MODE_BLOCKING 1
#define IPC_QUEUE_MODE_SYNC 2

// A bounded, multi-producer, single-consumer FIFO worker queue
class ipcMessageQueue
{
public:
    ipcMessageQueue();
    ~ipcMessageQueue();

    ARTS_NON_COPYABLE(ipcMessageQueue);

    // ?Init@ipcMessageQueue@@QAEXHH@Z
    ARTS_EXPORT void Init(i32 max_messages, i32 mode);

    // ?Send@ipcMessageQueue@@QAEXP6AXPAX@Z0@Z
    [[deprecated]] ARTS_EXPORT void Send(void (*func)(void*), void* param);

    void Send(Callback cb);

    // ?Shutdown@ipcMessageQueue@@QAEXXZ
    ARTS_EXPORT void Shutdown();

private:
    // ?MessageLoop@ipcMessageQueue@@AAEHXZ
    ARTS_EXPORT i32 MessageLoop();

    // ?Proc@ipcMessageQueue@@CGKPAX@Z
    ARTS_EXPORT static ulong ARTS_STDCALL Proc(void* param);

    std::atomic<b32> initialized_ {};
    u32 send_index_ {};
    u32 read_index_ {};
    u32 max_messages_ {};
    b32 blocking_ {};
    Ptr<Callback[]> messages_;
    Condvar send_event_ {};
    Condvar done_event_ {};
    Mutex mutex_ {};
    usize proc_thread_ {};
};

check_size(ipcMessageQueue, 0x28);
