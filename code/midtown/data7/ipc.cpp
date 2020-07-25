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

#include "core/minwin.h"

#include "memory/stack.h"

// 0x578AB0 | ?compareExchange@@YIHPAIH@Z
ARTS_EXPORT /*static*/ i32 ARTS_FASTCALL compareExchange(u32* value, i32 new_value)
{
    return _InterlockedCompareExchange(value, new_value, new_value ^ 1);
}

void ipcCloseHandle(usize handle)
{
    if (handle)
        CloseHandle(reinterpret_cast<HANDLE>(handle));
}

void ipcCloseSpinLock(u32* value)
{
    ipcSpinLock(value);

    *value = 99;
}

usize ipcCreateEvent(b32 initial_state)
{
    return reinterpret_cast<usize>(CreateEventA(nullptr, false, initial_state, nullptr));
}

usize ipcCreateMutex(b32 initial_owner)
{
    return reinterpret_cast<usize>(CreateMutexA(nullptr, initial_owner, nullptr));
}

void ipcCreateSpinLock(u32* value)
{
    *value = 0;
}

usize ipcCreateThread(ulong(ARTS_STDCALL* start)(void*), void* param, ulong* thread_id)
{
    return reinterpret_cast<usize>(CreateThread(nullptr, 0, start, param, 0, thread_id));
}

void ipcReleaseMutex(usize handle)
{
    if (handle)
        ReleaseMutex(reinterpret_cast<HANDLE>(handle));
}

void ipcSleep(u32 milli_seconds)
{
    Sleep(milli_seconds);
}

void ipcSpinLock(u32* value)
{
    while (compareExchange(value, 1) == 1)
        Sleep(0);
}

void ipcSpinUnlock(u32* value)
{
    while (compareExchange(value, 0) == 0)
        Sleep(0);
}

void ipcTriggerEvent(usize handle)
{
    if (handle)
        SetEvent(reinterpret_cast<HANDLE>(handle));
}

i32 ipcWaitMultiple(i32 count, usize* handles, b32 wait_all)
{
    // TODO: Should this return b32?
    return WaitForMultipleObjects(count, reinterpret_cast<const HANDLE*>(handles), wait_all, INFINITE);
}

void ipcWaitSingle(usize handle)
{
    // NOTE: Original looped waiting 1000 ms

    if (handle)
        WaitForSingleObject(reinterpret_cast<HANDLE>(handle), INFINITE);
}

void ipcYield()
{
    Sleep(0);
}

struct ipcMessage
{
    void (*Function)(void*) {nullptr};
    void* Param {nullptr};
};

ipcMessageQueue::ipcMessageQueue() = default;

ipcMessageQueue::~ipcMessageQueue()
{
    Shutdown();
}

void ipcMessageQueue::Init(i32 max_messages, b32 blocking)
{
    if (SynchronousMessageQueues)
        return;

    if (initialized_)
        Quitf("ipcMessageQueue::Init - didn't Shutdown first?");

    read_index_ = 0;
    send_index_ = 0;

    if (blocking)
        max_messages = 2;

    blocking_ = blocking;
    max_messages_ = max_messages;
    messages_ = MakeUnique<ipcMessage[]>(max_messages);

    send_event_ = ipcCreateEvent(false);
    read_event_ = ipcCreateEvent(false);
    mutex_ = ipcCreateMutex(false);

    initialized_ = true;

    ulong thread_id = 0;
    proc_thread_ = ipcCreateThread(ipcMessageQueue::Proc, this, &thread_id);
}

void ipcMessageQueue::Send(void (*func)(void*), void* param)
{
    if (SynchronousMessageQueues)
    {
        func(param);

        return;
    }

    ipcWaitSingle(mutex_);

    u32 send_index = 0;

    while (true)
    {
        send_index = send_index_ + 1;

        if (send_index == max_messages_)
            send_index = 0;

        if (read_index_ != send_index)
            break;

        ipcReleaseMutex(mutex_);
        ipcWaitSingle(read_event_);
        ipcWaitSingle(mutex_);
    }

    bool trigger_send = read_index_ == send_index_;
    send_index_ = send_index;
    messages_[send_index_] = {func, param};

    ipcReleaseMutex(mutex_);

    if (trigger_send)
        ipcTriggerEvent(send_event_);

    if (blocking_)
        ipcWaitSingle(read_event_);
}

void ipcMessageQueue::Shutdown()
{
    if (SynchronousMessageQueues || !initialized_)
        return;

    initialized_ = false;

    ipcTriggerEvent(send_event_);
    ipcWaitSingle(proc_thread_);
    ipcCloseHandle(proc_thread_);
    ipcCloseHandle(send_event_);
    ipcCloseHandle(read_event_);
    ipcCloseHandle(mutex_);

    messages_ = nullptr;
}

i32 ipcMessageQueue::MessageLoop()
{
    EXCEPTION_BEGIN
    while (initialized_)
    {
        ipcWaitSingle(send_event_);

        while (true)
        {
            ipcWaitSingle(mutex_);

            if (read_index_ == send_index_)
                break;

            if (++read_index_ == max_messages_)
                read_index_ = 0;

            ipcMessage msg = messages_[read_index_];

            ipcReleaseMutex(mutex_);
            msg.Function(msg.Param);
            ipcTriggerEvent(read_event_);
        }

        ipcReleaseMutex(mutex_);
    }
    EXCEPTION_END
    {
        Abortf("Exception caught in MessageLoop");
    }

    return 0;
}

ulong ipcMessageQueue::Proc(void* param)
{
    return static_cast<ipcMessageQueue*>(param)->MessageLoop();
}
