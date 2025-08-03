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

#include "memory/stack.h"

#include "core/minwin.h"

b32 SynchronousMessageQueues = false;

usize ipcCreateThread(ulong(ARTS_STDCALL* start)(void*), void* param, ulong* thread_id)
{
    return reinterpret_cast<usize>(CreateThread(nullptr, 0, start, param, 0, thread_id));
}

void ipcWaitThreadExit(usize thread)
{
    if (thread)
        WaitForSingleObject(reinterpret_cast<HANDLE>(thread), INFINITE);
}

void ipcDeleteThread(usize thread)
{
    if (thread)
        CloseHandle(reinterpret_cast<HANDLE>(thread));
}

void ipcYield()
{
    Sleep(0);
}

ipcMessageQueue::ipcMessageQueue() = default;

ipcMessageQueue::~ipcMessageQueue()
{
    Shutdown();
}

void ipcMessageQueue::Init(i32 max_messages, i32 mode)
{
    if (mode == IPC_QUEUE_MODE_SYNC)
        return;

    if (initialized_)
        Quitf("ipcMessageQueue::Init - didn't Shutdown first?");

    read_index_ = 0;
    send_index_ = 0;

    bool blocking = mode == IPC_QUEUE_MODE_BLOCKING;

    if (blocking)
        max_messages = 2;

    ArAssert(max_messages >= 2, "Queue must have at least 2 message slots");

    blocking_ = blocking;
    max_messages_ = max_messages;
    messages_ = arnewa Callback[max_messages] {};

    send_event_.init();
    done_event_.init();
    mutex_.init();

    initialized_ = true;

    ulong thread_id = 0;
    proc_thread_ = ipcCreateThread(ipcMessageQueue::Proc, this, &thread_id);
}

void ipcMessageQueue::Send(Callback cb)
{
    if (!initialized_)
    {
        cb.Call();

        return;
    }

    UniqueLock lock(mutex_);
    u32 send_index = 0;

    while (true)
    {
        // Get the next send index
        send_index = send_index_ + 1;

        if (send_index == max_messages_)
            send_index = 0;

        // Check if the queue is full
        if (send_index != read_index_)
            break;

        // The queue is full, wait for some messages to be processed
        done_event_.wait(lock);
    }

    // The queue is empty, will need to wake up the worker thread
    bool trigger_send = read_index_ == send_index_;

    send_index_ = send_index;
    messages_[send_index_] = cb;

    // If necessary, wake up the worker thread
    if (trigger_send)
        send_event_.notify_one();

    // If blocking, wait for the event to be processed
    if (blocking_)
        done_event_.wait(lock);
}

void ipcMessageQueue::Shutdown()
{
    if (!initialized_)
        return;

    initialized_ = false;
    send_event_.notify_one();

    ipcWaitThreadExit(proc_thread_);
    ipcDeleteThread(proc_thread_);

    send_event_.close();
    done_event_.close();
    mutex_.close();
    messages_ = nullptr;
}

i32 ipcMessageQueue::MessageLoop()
{
    ARTS_EXCEPTION_BEGIN
    {
        UniqueLock lock(mutex_);

        while (initialized_)
        {
            // Check if the queue is empty
            while (read_index_ != send_index_)
            {
                // Get the next read index
                if (++read_index_ == max_messages_)
                    read_index_ = 0;

                // Copy the message
                Callback msg = messages_[read_index_];

                // Process the message, temporarily unlocking the mutex
                lock.unlock();
                msg.Call();
                lock.lock();

                // Notify that a message has been processed
                done_event_.notify_one();
            }

            // The queue is empty, wait for something to be sent
            send_event_.wait(lock);
        }
    }
    ARTS_EXCEPTION_END
    {
        Abortf("Exception caught in MessageLoop");
    }

    return 0;
}

ulong ipcMessageQueue::Proc(void* param)
{
    return static_cast<ipcMessageQueue*>(param)->MessageLoop();
}
