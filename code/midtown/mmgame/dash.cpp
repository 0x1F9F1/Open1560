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

define_dummy_symbol(mmgame_dash);

#include "dash.h"

mmExternalView::mmExternalView()
{
    unimplemented();
}

mmExternalView::~mmExternalView()
{
    unimplemented();
}

void mmExternalView::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmExternalView*, class Bank*>>(0x4224E0, this, arg1);
}

void mmExternalView::Cull()
{
    return stub<thiscall_t<void, mmExternalView*>>(0x422340, this);
}

void mmExternalView::Init(class mmPlayer* arg1)
{
    return stub<thiscall_t<void, mmExternalView*, class mmPlayer*>>(0x422170, this, arg1);
}

void mmExternalView::ResChange(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmExternalView*, i32, i32>>(0x4221B0, this, arg1, arg2);
}

void mmExternalView::Reset()
{
    return stub<thiscall_t<void, mmExternalView*>>(0x422300, this);
}

void mmExternalView::Update()
{
    return stub<thiscall_t<void, mmExternalView*>>(0x422310, this);
}

void mmExternalView::WideFOV(i32 arg1)
{
    return stub<thiscall_t<void, mmExternalView*, i32>>(0x422330, this, arg1);
}

mmDashView::mmDashView()
{
    unimplemented();
}

mmDashView::~mmDashView()
{
    unimplemented();
}

void mmDashView::Activate()
{
    return stub<thiscall_t<void, mmDashView*>>(0x421D80, this);
}

void mmDashView::ActivateUntilTransitionIsOver()
{
    return stub<thiscall_t<void, mmDashView*>>(0x421D60, this);
}

void mmDashView::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmDashView*, class Bank*>>(0x4227D0, this, arg1);
}

void mmDashView::AfterLoad()
{
    return stub<thiscall_t<void, mmDashView*>>(0x421CC0, this);
}

void mmDashView::BeforeSave()
{
    return stub<thiscall_t<void, mmDashView*>>(0x421C20, this);
}

void mmDashView::Cull()
{
    return stub<thiscall_t<void, mmDashView*>>(0x421F00, this);
}

void mmDashView::Deactivate()
{
    return stub<thiscall_t<void, mmDashView*>>(0x421DA0, this);
}

class MetaClass* mmDashView::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmDashView*>>(0x422EC0, this);
}

void mmDashView::Init(char* arg1, class mmPlayer* arg2)
{
    return stub<thiscall_t<void, mmDashView*, char*, class mmPlayer*>>(0x421880, this, arg1, arg2);
}

void mmDashView::Reset()
{
    return stub<thiscall_t<void, mmDashView*>>(0x421C10, this);
}

void mmDashView::TempDeactivate()
{
    return stub<thiscall_t<void, mmDashView*>>(0x421DC0, this);
}

void mmDashView::Update()
{
    return stub<thiscall_t<void, mmDashView*>>(0x421DD0, this);
}

void mmDashView::DeclareFields()
{
    return stub<cdecl_t<void>>(0x422BD0);
}
