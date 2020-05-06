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

define_dummy_symbol(mmbangers_active);

#include "active.h"

mmBangerActive::mmBangerActive()
{
    unimplemented();
}

mmBangerActive::~mmBangerActive()
{
    unimplemented(arg1);
}

void mmBangerActive::PostUpdate()
{
    return stub<thiscall_t<void, mmBangerActive*>>(0x4CB350, this);
}

class asBound* mmBangerActive::GetBound()
{
    return stub<thiscall_t<class asBound*, mmBangerActive*>>(0x4CB7B0, this);
}

class asInertialCS* mmBangerActive::GetICS()
{
    return stub<thiscall_t<class asInertialCS*, mmBangerActive*>>(0x4CB7C0, this);
}

void mmBangerActive::DetachMe()
{
    return stub<thiscall_t<void, mmBangerActive*>>(0x4CB280, this);
}

void mmBangerActive::Attach(class mmBangerInstance* arg1)
{
    return stub<thiscall_t<void, mmBangerActive*, class mmBangerInstance*>>(0x4CB030, this, arg1);
}

void mmBangerActive::Detach()
{
    return stub<thiscall_t<void, mmBangerActive*>>(0x4CB220, this);
}

void mmBangerActive::Update()
{
    return stub<thiscall_t<void, mmBangerActive*>>(0x4CB2A0, this);
}

mmBangerActiveManager::mmBangerActiveManager()
{
    unimplemented();
}

mmBangerActiveManager::~mmBangerActiveManager()
{
    unimplemented(arg1);
}

class mmBangerActive* mmBangerActiveManager::Attach(class mmBangerInstance* arg1)
{
    return stub<thiscall_t<class mmBangerActive*, mmBangerActiveManager*, class mmBangerInstance*>>(
        0x4CB520, this, arg1);
}

void mmBangerActiveManager::Detach(class mmBangerActive* arg1)
{
    return stub<thiscall_t<void, mmBangerActiveManager*, class mmBangerActive*>>(0x4CB5F0, this, arg1);
}

class mmBangerActive* mmBangerActiveManager::GetActive(class mmBangerInstance* arg1)
{
    return stub<thiscall_t<class mmBangerActive*, mmBangerActiveManager*, class mmBangerInstance*>>(
        0x4CB4F0, this, arg1);
}

void mmBangerActiveManager::Reset()
{
    return stub<thiscall_t<void, mmBangerActiveManager*>>(0x4CB720, this);
}

void mmBangerActiveManager::Update()
{
    return stub<thiscall_t<void, mmBangerActiveManager*>>(0x4CB640, this);
}
