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

define_dummy_symbol(data7_callback);

#include "callback.h"

Callback NullCallback {};

Callback::Callback(Static0 func) noexcept
    : Callback([func] { func(); })
{}

Callback::Callback(Static1 func, void* param) noexcept
    : Callback([func, param] { func(param); })
{}

Callback::Callback(Static2 func, void* param) noexcept
    : Callback([func, param](void* arg) { func(param, arg); })
{}

Callback::Callback(Member0 func, Base* this_ptr) noexcept
    : Callback([func, this_ptr] { (this_ptr->*func)(); })
{
    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

Callback::Callback(Member1 func, Base* this_ptr, void* param) noexcept
    : Callback([func, this_ptr, param] { (this_ptr->*func)(param); })
{
    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

Callback::Callback(Member2 func, Base* this_ptr, void* param) noexcept
    : Callback([func, this_ptr, param](void* arg) { (this_ptr->*func)(param, arg); })
{
    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

Callback::Callback(Member2 func, Base* this_ptr, void* param1, void* param2) noexcept
    : Callback([func, this_ptr, param1, param2] { (this_ptr->*func)(param1, param2); })
{
    if (!this_ptr)
        Quitf("Can't have callback to member function with nil 'this'");
}

CallbackArray::CallbackArray(Callback* callbacks, usize capacity)
    : callbacks_(callbacks)
    , capacity_(static_cast<u16>(capacity))
{}

void CallbackArray::Append(Callback callback)
{
    for (u16 i = 0; i < size_; ++i)
    {
        if (callbacks_[i] == callback)
            return;
    }

    if (size_ == capacity_)
        return;

    callbacks_[size_++] = callback;
}

void CallbackArray::Clear()
{
    size_ = 0;
}

void CallbackArray::Invoke(bool clear_after, void* param)
{
    for (u16 i = 0; i < size_; ++i)
        callbacks_[i].Call(param);

    if (clear_after)
        Clear();
}
