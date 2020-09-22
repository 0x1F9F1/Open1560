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
#include <thread>

class TicketLock
{
public:
    void lock();

    void unlock()
    {
        now_serving_.fetch_add(1, std::memory_order_release);
    }

private:
    std::atomic<usize> next_ticket_ {0};
    std::atomic<usize> now_serving_ {0};
};

template <typename T>
class RecursiveLock
{
public:
    void lock()
    {
        if (std::thread::id tid = std::this_thread::get_id(); tid != lock_owner_.load(std::memory_order_acquire))
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
            lock_owner_.store(std::thread::id(), std::memory_order_relaxed);
        }
    }

private:
    T lock_ {};
    std::atomic<std::thread::id> lock_owner_ {};
    usize lock_count_ {0};
};

using RecursiveTicketLock = RecursiveLock<TicketLock>;
