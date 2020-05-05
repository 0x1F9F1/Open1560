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

void agiRefreshable::EndGfx()
{
    return stub<thiscall_t<void, agiRefreshable*>>(0x - 400000_Offset, this);
}

void agiRefreshable::Restore()
{
    return stub<thiscall_t<void, agiRefreshable*>>(0x157AD0_Offset, this);
}

char* agiRefreshable::GetName()
{
    return stub<thiscall_t<char*, agiRefreshable*>>(0x157B90_Offset, this);
}

agiRefreshable::~agiRefreshable()
{
    unimplemented(arg1);
}

i32 agiRefreshable::BeginGfx()
{
    return stub<thiscall_t<i32, agiRefreshable*>>(0x - 400000_Offset, this);
}

i32 agiRefreshable::IsTexture()
{
    return stub<thiscall_t<i32, agiRefreshable*>>(0x157BA0_Offset, this);
}

void agiRefreshable::AddRef()
{
    return stub<thiscall_t<void, agiRefreshable*>>(0x157AE0_Offset, this);
}

i32 agiRefreshable::Release()
{
    return stub<thiscall_t<i32, agiRefreshable*>>(0x157B00_Offset, this);
}

i32 agiRefreshable::SafeBeginGfx()
{
    return stub<thiscall_t<i32, agiRefreshable*>>(0x157AA0_Offset, this);
}

void agiRefreshable::ValidatePtr(char* arg1)
{
    return stub<thiscall_t<void, agiRefreshable*, char*>>(0x157B30_Offset, this, arg1);
}
