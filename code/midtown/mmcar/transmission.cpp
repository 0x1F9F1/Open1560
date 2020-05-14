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

define_dummy_symbol(mmcar_transmission);

#include "transmission.h"

mmTransmission::mmTransmission()
{
    unimplemented();
}

mmTransmission::~mmTransmission()
{
    unimplemented();
}

void mmTransmission::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmTransmission*, class Bank*>>(0x470790, this, arg1);
}

void mmTransmission::Automatic(i32 arg1)
{
    return stub<thiscall_t<void, mmTransmission*, i32>>(0x4706F0, this, arg1);
}

void mmTransmission::CopyTrans()
{
    return stub<thiscall_t<void, mmTransmission*>>(0x4706C0, this);
}

i32 mmTransmission::Downshift()
{
    return stub<thiscall_t<i32, mmTransmission*>>(0x4705A0, this);
}

class MetaClass* mmTransmission::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmTransmission*>>(0x470C80, this);
}

i32 mmTransmission::GetCurrentGear()
{
    return stub<thiscall_t<i32, mmTransmission*>>(0x470740, this);
}

void mmTransmission::Init(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmTransmission*, class mmCarSim*>>(0x470500, this, arg1);
}

void mmTransmission::Reset()
{
    return stub<thiscall_t<void, mmTransmission*>>(0x470540, this);
}

i32 mmTransmission::SetCurrentGear(i32 arg1)
{
    return stub<thiscall_t<i32, mmTransmission*, i32>>(0x470750, this, arg1);
}

void mmTransmission::SetDrive()
{
    return stub<thiscall_t<void, mmTransmission*>>(0x470720, this);
}

void mmTransmission::SetReverse()
{
    return stub<thiscall_t<void, mmTransmission*>>(0x470710, this);
}

void mmTransmission::Update()
{
    return stub<thiscall_t<void, mmTransmission*>>(0x4705C0, this);
}

i32 mmTransmission::Upshift()
{
    return stub<thiscall_t<i32, mmTransmission*>>(0x470570, this);
}

void mmTransmission::DeclareFields()
{
    return stub<cdecl_t<void>>(0x470A30);
}

struct MetaType* ArrayOf(struct MetaType* arg1, i32 arg2)
{
    return stub<cdecl_t<struct MetaType*, struct MetaType*, i32>>(0x470CC0, arg1, arg2);
}
