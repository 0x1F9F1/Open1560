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

#include <atomic>

#ifdef _WIN32
#    include <intrin.h>
using ThreadId = u32;
#    ifdef _WIN64
#        define ThisThreadId() __readgsdword(0x48)
#    else
#        define ThisThreadId() __readfsdword(0x24)
#    endif
#else
#    include <thread>
using ThreadId = std::thread::id;
#    define ThisThreadId() std::this_thread::get_id()
#endif

#define InvalidThreadId() ThreadId()

class TicketLock
{
public:
    void lock();

    void unlock()
    {
        now_serving_.fetch_add(1, std::memory_order_release);
    }

private:
    std::atomic<usize> next_ticket_ {};
    std::atomic<usize> now_serving_ {};
};

template <typename T>
class RecursiveLock
{
public:
    void lock()
    {
        if (ThreadId tid = ThisThreadId(); tid != lock_owner_.load(std::memory_order_acquire))
        {
            lock_.lock();
            lock_owner_.store(tid, std::memory_order_relaxed);
        }

        ++lock_count_;
    }

    void unlock()
    {
        if (--lock_count_ == 0)
        {
            lock_.unlock();
            lock_owner_.store(InvalidThreadId(), std::memory_order_relaxed);
        }
    }

private:
    T lock_ {};
    std::atomic<ThreadId> lock_owner_ {InvalidThreadId()};
    usize lock_count_ {};
};

using RecursiveTicketLock = RecursiveLock<TicketLock>;
