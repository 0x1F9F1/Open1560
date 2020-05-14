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

define_dummy_symbol(mmcamcs_aicamcs);

#include "aicamcs.h"

AICamCS::AICamCS()
{
    unimplemented();
}

AICamCS::~AICamCS()
{
    unimplemented();
}

class MetaClass* AICamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, AICamCS*>>(0x4FAAC0, this);
}

void AICamCS::Init(class mmCar* arg1)
{
    return stub<thiscall_t<void, AICamCS*, class mmCar*>>(0x4FA4C0, this, arg1);
}

void AICamCS::MakeActive()
{
    return stub<thiscall_t<void, AICamCS*>>(0x4FA4E0, this);
}

void AICamCS::Reset()
{
    return stub<thiscall_t<void, AICamCS*>>(0x4FA4D0, this);
}

void AICamCS::Update()
{
    return stub<thiscall_t<void, AICamCS*>>(0x4FA5F0, this);
}

void AICamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4FA950);
}
