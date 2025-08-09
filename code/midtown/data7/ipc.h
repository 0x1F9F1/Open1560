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

// ?ipcCreateThread@@YAIP6GKPAX@Z0PAK@Z
usize ipcCreateThread(ulong(ARTS_STDCALL* start)(void*), void* param, ulong* thread_id);

void ipcWaitThreadExit(usize thread);

void ipcDeleteThread(usize thread);

// ?ipcYield@@YAXXZ
void ipcYield();

// ?SynchronousMessageQueues@@3HA
extern b32 SynchronousMessageQueues;

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

    void Send(Callback cb);

    // ?Shutdown@ipcMessageQueue@@QAEXXZ
    ARTS_EXPORT void Shutdown();

private:
    // ?MessageLoop@ipcMessageQueue@@AAEHXZ
    i32 MessageLoop();

    // ?Proc@ipcMessageQueue@@CGKPAX@Z
    static ulong ARTS_STDCALL Proc(void* param);

    b32 initialized_ {};
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
