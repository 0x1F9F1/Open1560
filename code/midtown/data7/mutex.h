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

typedef struct SDL_Mutex SDL_Mutex;
typedef struct SDL_Condition SDL_Condition;

class Mutex
{
public:
    constexpr Mutex() = default;

    ~Mutex();

    ARTS_NON_COPYABLE(Mutex);

    void init();
    void close();

    void lock();
    void unlock();

    SDL_Mutex* native_handle() const
    {
        return handle_;
    }

private:
    SDL_Mutex* handle_ {};
};

template <typename T>
class LockGuard
{
public:
    LockGuard(T& mutex)
        : mutex_(&mutex)
    {
        mutex_->lock();
    }

    ~LockGuard()
    {
        mutex_->unlock();
    }

    ARTS_NON_COPYABLE(LockGuard);

private:
    T* const mutex_ {};
};

template <typename T>
LockGuard(T&) -> LockGuard<T>;

template <typename T>
class UniqueLock
{
public:
    UniqueLock(T& mutex)
        : mutex_(&mutex)
    {
        lock();
    }

    ~UniqueLock()
    {
        if (locked_)
            unlock();
    }

    ARTS_NON_COPYABLE(UniqueLock);

    void lock()
    {
        ArAssert(!locked_, "Mutex already locked");
        mutex_->lock();
        locked_ = true;
    }

    void unlock()
    {
        ArAssert(locked_, "Mutex not locked");
        mutex_->unlock();
        locked_ = false;
    }

    T* mutex() const
    {
        return mutex_;
    }

    bool owns_lock() const
    {
        return locked_;
    }

private:
    T* const mutex_ {};
    bool locked_ {};
};

template <typename T>
UniqueLock(T&) -> UniqueLock<T>;

class Condvar
{
public:
    constexpr Condvar() = default;

    ~Condvar();

    ARTS_NON_COPYABLE(Condvar);

    void init();
    void close();

    void notify_one();
    void notify_all();

    void wait(UniqueLock<Mutex>& mutex);

private:
    SDL_Condition* handle_ {};
};
