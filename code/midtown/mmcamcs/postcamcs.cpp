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
    return stub<thiscall_t<void, PostCamCS*, class Bank*>>(0x4F97A0, this, arg1);
}

class MetaClass* PostCamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, PostCamCS*>>(0x4F9930, this);
}

void PostCamCS::Init(class mmCar* arg1)
{
    return stub<thiscall_t<void, PostCamCS*, class mmCar*>>(0x4F95C0, this, arg1);
}

void PostCamCS::MakeActive()
{
    return stub<thiscall_t<void, PostCamCS*>>(0x4F95F0, this);
}

void PostCamCS::Reset()
{
    return stub<thiscall_t<void, PostCamCS*>>(0x4F95E0, this);
}

void PostCamCS::Update()
{
    return stub<thiscall_t<void, PostCamCS*>>(0x4F9670, this);
}

void PostCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4F97C0);
}
