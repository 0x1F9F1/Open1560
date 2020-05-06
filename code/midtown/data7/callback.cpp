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

Callback::Callback()
{
    unimplemented();
}

Callback::Callback(void (*arg1)(void))
{
    unimplemented(arg1);
}

Callback::Callback(void (*arg1)(void*), void* arg2)
{
    unimplemented(arg1, arg2);
}

Callback::Callback(void (*arg1)(void*, void*), void* arg2)
{
    unimplemented(arg1, arg2);
}

void Callback::Call(void* arg1)
{
    return stub<thiscall_t<void, Callback*, void*>>(0x579450, this, arg1);
}
