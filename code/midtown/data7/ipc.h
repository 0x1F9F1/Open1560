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
