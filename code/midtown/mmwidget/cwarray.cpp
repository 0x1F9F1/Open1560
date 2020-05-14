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

define_dummy_symbol(mmwidget_cwarray);

#include "cwarray.h"

UICWArray::UICWArray()
{
    unimplemented();
}

UICWArray::~UICWArray()
{
    unimplemented();
}

void UICWArray::AcceptCapture()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B8560, this);
}

void UICWArray::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UICWArray*, union eqEvent>>(0x4B82A0, this, arg1);
}

void UICWArray::CaptureAction(union eqEvent arg1)
{
    return stub<thiscall_t<void, UICWArray*, union eqEvent>>(0x4B83D0, this, arg1);
}

void UICWArray::CheckCapture()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B85E0, this);
}

void UICWArray::DebugForceSetting()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B8740, this);
}

void UICWArray::DefaultCFG()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B8720, this);
}

void UICWArray::EnterCapture(i32 arg1)
{
    return stub<thiscall_t<void, UICWArray*, i32>>(0x4B84C0, this, arg1);
}

void UICWArray::ForceCapture()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B8530, this);
}

void UICWArray::Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5, class Callback arg6)
{
    return stub<thiscall_t<void, UICWArray*, f32, f32, f32, f32, i32, class Callback>>(
        0x4B7D50, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void UICWArray::LoadCFG()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B86D0, this);
}

void UICWArray::Redraw()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B8100, this);
}

void UICWArray::Reset()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B7D40, this);
}

void UICWArray::ResetCapture()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B85B0, this);
}

void UICWArray::SaveCFG()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B8690, this);
}

void UICWArray::SetStartOffset(i32 arg1)
{
    return stub<thiscall_t<void, UICWArray*, i32>>(0x4B80C0, this, arg1);
}

void UICWArray::SetVScrollPos()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B8090, this);
}

void UICWArray::SetVScrollVals()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B8020, this);
}

void UICWArray::Switch(i32 arg1)
{
    return stub<thiscall_t<void, UICWArray*, i32>>(0x4B8260, this, arg1);
}

void UICWArray::Update()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B8440, this);
}

void UICWArray::VScrollCB()
{
    return stub<thiscall_t<void, UICWArray*>>(0x4B7FB0, this);
}
