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
    unimplemented(arg1);
}

void mmExternalView::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmExternalView*, class Bank*>>(0x224E0_Offset, this, arg1);
}

void mmExternalView::Cull()
{
    return stub<thiscall_t<void, mmExternalView*>>(0x22340_Offset, this);
}

void mmExternalView::Init(class mmPlayer* arg1)
{
    return stub<thiscall_t<void, mmExternalView*, class mmPlayer*>>(0x22170_Offset, this, arg1);
}

void mmExternalView::ResChange(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmExternalView*, i32, i32>>(0x221B0_Offset, this, arg1, arg2);
}

void mmExternalView::Reset()
{
    return stub<thiscall_t<void, mmExternalView*>>(0x22300_Offset, this);
}

void mmExternalView::Update()
{
    return stub<thiscall_t<void, mmExternalView*>>(0x22310_Offset, this);
}

void mmExternalView::WideFOV(i32 arg1)
{
    return stub<thiscall_t<void, mmExternalView*, i32>>(0x22330_Offset, this, arg1);
}

mmDashView::mmDashView()
{
    unimplemented();
}

mmDashView::~mmDashView()
{
    unimplemented(arg1);
}

void mmDashView::Activate()
{
    return stub<thiscall_t<void, mmDashView*>>(0x21D80_Offset, this);
}

void mmDashView::ActivateUntilTransitionIsOver()
{
    return stub<thiscall_t<void, mmDashView*>>(0x21D60_Offset, this);
}

void mmDashView::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmDashView*, class Bank*>>(0x227D0_Offset, this, arg1);
}

void mmDashView::AfterLoad()
{
    return stub<thiscall_t<void, mmDashView*>>(0x21CC0_Offset, this);
}

void mmDashView::BeforeSave()
{
    return stub<thiscall_t<void, mmDashView*>>(0x21C20_Offset, this);
}

void mmDashView::Cull()
{
    return stub<thiscall_t<void, mmDashView*>>(0x21F00_Offset, this);
}

void mmDashView::Deactivate()
{
    return stub<thiscall_t<void, mmDashView*>>(0x21DA0_Offset, this);
}

class MetaClass* mmDashView::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmDashView*>>(0x22EC0_Offset, this);
}

void mmDashView::Init(char* arg1, class mmPlayer* arg2)
{
    return stub<thiscall_t<void, mmDashView*, char*, class mmPlayer*>>(0x21880_Offset, this, arg1, arg2);
}

void mmDashView::Reset()
{
    return stub<thiscall_t<void, mmDashView*>>(0x21C10_Offset, this);
}

void mmDashView::TempDeactivate()
{
    return stub<thiscall_t<void, mmDashView*>>(0x21DC0_Offset, this);
}

void mmDashView::Update()
{
    return stub<thiscall_t<void, mmDashView*>>(0x21DD0_Offset, this);
}

void mmDashView::DeclareFields()
{
    return stub<cdecl_t<void>>(0x22BD0_Offset);
}
