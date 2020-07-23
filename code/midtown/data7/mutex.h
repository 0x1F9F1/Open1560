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

// TODO: Use critical section instead of mutex

class Mutex
{
public:
    constexpr Mutex() = default;

    ~Mutex()
    {
        close();
    }

    Mutex(const Mutex&) = delete;
    Mutex& operator=(const Mutex&) = delete;

    // Must call init and close, to match ipc.h semantics
    void init();
    void close();

    void lock();
    void unlock();

private:
    void* handle_ {nullptr};
};

class MutexGuard
{
public:
    ARTS_FORCEINLINE MutexGuard(Mutex& mutex)
        : mutex_(&mutex)
    {
        mutex_->lock();
    }

    ARTS_FORCEINLINE ~MutexGuard()
    {
        mutex_->unlock();
    }

    MutexGuard(const MutexGuard&) = delete;
    MutexGuard& operator=(const MutexGuard&) = delete;

private:
    Mutex* const mutex_ {nullptr};
};
