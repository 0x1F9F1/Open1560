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

define_dummy_symbol(mmwidget_compbase);

#include "compbase.h"

mmCompBase::~mmCompBase()
{
    unimplemented();
}

void mmCompBase::DisableBlt()
{
    return stub<thiscall_t<void, mmCompBase*>>(0x4B4E00, this);
}

void mmCompBase::SetBltXY(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmCompBase*, f32, f32>>(0x4B4E10, this, arg1, arg2);
}

void mmCompBase::Action(union eqEvent arg1, f32 arg2, f32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmCompBase*, union eqEvent, f32, f32, i32>>(0x4B4E70, this, arg1, arg2, arg3, arg4);
}

void mmCompBase::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, mmCompBase*, union eqEvent>>(0x4B4E40, this, arg1);
}

void mmCompBase::CaptureAction(union eqEvent arg1)
{
    return stub<thiscall_t<void, mmCompBase*, union eqEvent>>(0x4B4E50, this, arg1);
}

void mmCompBase::Switch(i32 arg1)
{
    return stub<thiscall_t<void, mmCompBase*, i32>>(0x4B4E60, this, arg1);
}

void mmCompBase::EvalMouseXY(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmCompBase*, f32, f32>>(0x4B4E80, this, arg1, arg2);
}

void mmCompBase::Highlight(class mmTextNode* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCompBase*, class mmTextNode*, i32>>(0x4B4E90, this, arg1, arg2);
}

void mmCompBase::SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmCompBase*, f32, f32, f32, f32>>(0x4B4EA0, this, arg1, arg2, arg3, arg4);
}

void mmCompBase::Reset()
{
    return stub<thiscall_t<void, mmCompBase*>>(0x4BF2D0, this);
}

void mmCompBase::Update()
{
    return stub<thiscall_t<void, mmCompBase*>>(0x4BF2E0, this);
}
