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

define_dummy_symbol(agi_refresh);

#include "refresh.h"

agiRefreshable::agiRefreshable(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

void agiRefreshable::Restore()
{
    return stub<thiscall_t<void, agiRefreshable*>>(0x557AD0, this);
}

char* agiRefreshable::GetName()
{
    return stub<thiscall_t<char*, agiRefreshable*>>(0x557B90, this);
}

agiRefreshable::~agiRefreshable()
{
    unimplemented();
}

void agiRefreshable::AddRef()
{
    return stub<thiscall_t<void, agiRefreshable*>>(0x557AE0, this);
}

i32 agiRefreshable::Release()
{
    return stub<thiscall_t<i32, agiRefreshable*>>(0x557B00, this);
}

i32 agiRefreshable::SafeBeginGfx()
{
    return stub<thiscall_t<i32, agiRefreshable*>>(0x557AA0, this);
}

i32 agiRefreshable::IsTexture()
{
    return stub<thiscall_t<i32, agiRefreshable*>>(0x557BA0, this);
}

void agiRefreshable::ValidatePtr(char* arg1)
{
    return stub<thiscall_t<void, agiRefreshable*, char*>>(0x557B30, this, arg1);
}
