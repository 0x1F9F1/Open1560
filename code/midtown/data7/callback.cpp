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

void Callback::Call(void* param)
{
    if (type_ == CB_TYPE_NONE)
        return;

    if (this_ptr_)
    {
        switch (type_)
        {
            case CB_TYPE_MFA: return (this_ptr_->*func_.member0)();
            case CB_TYPE_MFA1: return (this_ptr_->*func_.member1)(param_1_);
            case CB_TYPE_MFA2: return (this_ptr_->*func_.member2)(param_1_, param);
            case CB_TYPE_MFA3: return (this_ptr_->*func_.member2)(param_1_, param_2_);

            default: Quitf("Invalid Callback");
        }
    }
    else
    {
        switch (type_)
        {
            case CB_TYPE_CFA: return func_.static0();
            case CB_TYPE_CFA1: return func_.static1(param_1_);
            case CB_TYPE_CFA2: return func_.static2(param_1_, param);

            default: Quitf("Invalid Callback");
        }
    }
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
