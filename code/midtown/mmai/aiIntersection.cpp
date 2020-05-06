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

define_dummy_symbol(mmai_aiIntersection);

#include "aiIntersection.h"

aiIntersection::aiIntersection(i32 arg1)
{
    unimplemented(arg1);
}

aiIntersection::~aiIntersection()
{
    unimplemented();
}

void aiIntersection::AddSinkPath(class aiPath* arg1)
{
    return stub<thiscall_t<void, aiIntersection*, class aiPath*>>(0x447530, this, arg1);
}

void aiIntersection::AddSourcePath(class aiPath* arg1)
{
    return stub<thiscall_t<void, aiIntersection*, class aiPath*>>(0x4475A0, this, arg1);
}

void aiIntersection::CreateRoadMap()
{
    return stub<thiscall_t<void, aiIntersection*>>(0x447920, this);
}

void aiIntersection::DrawId()
{
    return stub<thiscall_t<void, aiIntersection*>>(0x4478B0, this);
}

void aiIntersection::DrawPaths()
{
    return stub<thiscall_t<void, aiIntersection*>>(0x447880, this);
}

void aiIntersection::Dump()
{
    return stub<thiscall_t<void, aiIntersection*>>(0x4478F0, this);
}

void aiIntersection::Init()
{
    return stub<thiscall_t<void, aiIntersection*>>(0x447370, this);
}

class aiPath* aiIntersection::Path(i32 arg1)
{
    return stub<thiscall_t<class aiPath*, aiIntersection*, i32>>(0x447C50, this, arg1);
}

void aiIntersection::ReadBinary(class Stream* arg1)
{
    return stub<thiscall_t<void, aiIntersection*, class Stream*>>(0x4476E0, this, arg1);
}

void aiIntersection::Reset()
{
    return stub<thiscall_t<void, aiIntersection*>>(0x447520, this);
}

void aiIntersection::SaveBinary(class Stream* arg1)
{
    return stub<thiscall_t<void, aiIntersection*, class Stream*>>(0x447610, this, arg1);
}
