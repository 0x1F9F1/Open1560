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

#include "head.h"

AudHead::AudHead(class Matrix34* arg1)
{
    unimplemented();
}

AudHead::~AudHead()
{
    unimplemented();
}

void AudHead::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, AudHead*, class Bank*>>(0xEBEF0_Offset, this, arg1);
}

class Matrix34* AudHead::GetHeadPtr()
{
    return stub<thiscall_t<class Matrix34*, AudHead*>>(0xEC030_Offset, this);
}

class Vector3* AudHead::GetPositionPtr()
{
    return stub<thiscall_t<class Vector3*, AudHead*>>(0xEC010_Offset, this);
}

i32 AudHead::Init()
{
    return stub<thiscall_t<i32, AudHead*>>(0xEBD10_Offset, this);
}

void AudHead::SetDoppler(f32 arg1)
{
    return stub<thiscall_t<void, AudHead*, f32>>(0xEBFB0_Offset, this, arg1);
}

void AudHead::SetHeadPtr(class Matrix34* arg1)
{
    return stub<thiscall_t<void, AudHead*, class Matrix34*>>(0xEC020_Offset, this, arg1);
}

void AudHead::SetRolloff(f32 arg1)
{
    return stub<thiscall_t<void, AudHead*, f32>>(0xEBF50_Offset, this, arg1);
}

void AudHead::WidgetSetRolloff()
{
    return stub<thiscall_t<void, AudHead*>>(0xEBEE0_Offset, this);
}

void AudHead::Update()
{
    return stub<thiscall_t<void, AudHead*>>(0xEBD60_Offset, this);
}

define_dummy_symbol(mmaudio_head);
