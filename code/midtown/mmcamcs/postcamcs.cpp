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

define_dummy_symbol(mmcamcs_postcamcs);

#include "postcamcs.h"

PostCamCS::PostCamCS()
{
    unimplemented();
}

PostCamCS::~PostCamCS()
{
    unimplemented(arg1);
}

void PostCamCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, PostCamCS*, class Bank*>>(0xF97A0_Offset, this, arg1);
}

class MetaClass* PostCamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, PostCamCS*>>(0xF9930_Offset, this);
}

void PostCamCS::Init(class mmCar* arg1)
{
    return stub<thiscall_t<void, PostCamCS*, class mmCar*>>(0xF95C0_Offset, this, arg1);
}

void PostCamCS::MakeActive()
{
    return stub<thiscall_t<void, PostCamCS*>>(0xF95F0_Offset, this);
}

void PostCamCS::Reset()
{
    return stub<thiscall_t<void, PostCamCS*>>(0xF95E0_Offset, this);
}

void PostCamCS::Update()
{
    return stub<thiscall_t<void, PostCamCS*>>(0xF9670_Offset, this);
}

void PostCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0xF97C0_Offset);
}
