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

#include "active.h"

mmBangerActive::mmBangerActive()
{
    unimplemented();
}

mmBangerActive::~mmBangerActive()
{
    unimplemented();
}

void mmBangerActive::PostUpdate()
{
    return stub<thiscall_t<void, mmBangerActive*>>(0xCB350_Offset, this);
}

class asBound* mmBangerActive::GetBound()
{
    return stub<thiscall_t<class asBound*, mmBangerActive*>>(0xCB7B0_Offset, this);
}

class asInertialCS* mmBangerActive::GetICS()
{
    return stub<thiscall_t<class asInertialCS*, mmBangerActive*>>(0xCB7C0_Offset, this);
}

void mmBangerActive::DetachMe()
{
    return stub<thiscall_t<void, mmBangerActive*>>(0xCB280_Offset, this);
}

void mmBangerActive::Attach(class mmBangerInstance* arg1)
{
    return stub<thiscall_t<void, mmBangerActive*, class mmBangerInstance*>>(0xCB030_Offset, this, arg1);
}

void mmBangerActive::Detach()
{
    return stub<thiscall_t<void, mmBangerActive*>>(0xCB220_Offset, this);
}

void mmBangerActive::Update()
{
    return stub<thiscall_t<void, mmBangerActive*>>(0xCB2A0_Offset, this);
}

mmBangerActiveManager::mmBangerActiveManager()
{
    unimplemented();
}

mmBangerActiveManager::~mmBangerActiveManager()
{
    unimplemented();
}

class mmBangerActive* mmBangerActiveManager::Attach(class mmBangerInstance* arg1)
{
    return stub<thiscall_t<class mmBangerActive*, mmBangerActiveManager*, class mmBangerInstance*>>(
        0xCB520_Offset, this, arg1);
}

void mmBangerActiveManager::Detach(class mmBangerActive* arg1)
{
    return stub<thiscall_t<void, mmBangerActiveManager*, class mmBangerActive*>>(0xCB5F0_Offset, this, arg1);
}

class mmBangerActive* mmBangerActiveManager::GetActive(class mmBangerInstance* arg1)
{
    return stub<thiscall_t<class mmBangerActive*, mmBangerActiveManager*, class mmBangerInstance*>>(
        0xCB4F0_Offset, this, arg1);
}

void mmBangerActiveManager::Reset()
{
    return stub<thiscall_t<void, mmBangerActiveManager*>>(0xCB720_Offset, this);
}

void mmBangerActiveManager::Update()
{
    return stub<thiscall_t<void, mmBangerActiveManager*>>(0xCB640_Offset, this);
}

define_dummy_symbol(mmbangers_active);
