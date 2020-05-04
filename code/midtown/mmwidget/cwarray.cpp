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
    return stub<thiscall_t<void, UICWArray*>>(0xB8560_Offset, this);
}

void UICWArray::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UICWArray*, union eqEvent>>(0xB82A0_Offset, this, arg1);
}

void UICWArray::CaptureAction(union eqEvent arg1)
{
    return stub<thiscall_t<void, UICWArray*, union eqEvent>>(0xB83D0_Offset, this, arg1);
}

void UICWArray::CheckCapture()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB85E0_Offset, this);
}

void UICWArray::DebugForceSetting()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB8740_Offset, this);
}

void UICWArray::DefaultCFG()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB8720_Offset, this);
}

void UICWArray::EnterCapture(i32 arg1)
{
    return stub<thiscall_t<void, UICWArray*, i32>>(0xB84C0_Offset, this, arg1);
}

void UICWArray::ForceCapture()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB8530_Offset, this);
}

void UICWArray::Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5, class Callback arg6)
{
    return stub<thiscall_t<void, UICWArray*, f32, f32, f32, f32, i32, class Callback>>(
        0xB7D50_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void UICWArray::LoadCFG()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB86D0_Offset, this);
}

void UICWArray::Redraw()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB8100_Offset, this);
}

void UICWArray::Reset()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB7D40_Offset, this);
}

void UICWArray::ResetCapture()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB85B0_Offset, this);
}

void UICWArray::SaveCFG()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB8690_Offset, this);
}

void UICWArray::SetStartOffset(i32 arg1)
{
    return stub<thiscall_t<void, UICWArray*, i32>>(0xB80C0_Offset, this, arg1);
}

void UICWArray::SetVScrollPos()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB8090_Offset, this);
}

void UICWArray::SetVScrollVals()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB8020_Offset, this);
}

void UICWArray::Switch(i32 arg1)
{
    return stub<thiscall_t<void, UICWArray*, i32>>(0xB8260_Offset, this, arg1);
}

void UICWArray::Update()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB8440_Offset, this);
}

void UICWArray::VScrollCB()
{
    return stub<thiscall_t<void, UICWArray*>>(0xB7FB0_Offset, this);
}

define_dummy_symbol(mmwidget_cwarray);
