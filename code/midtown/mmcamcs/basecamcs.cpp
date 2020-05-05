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

define_dummy_symbol(mmcamcs_basecamcs);

#include "basecamcs.h"

BaseCamCS::BaseCamCS()
{
    unimplemented();
}

BaseCamCS::~BaseCamCS()
{
    unimplemented(arg1);
}

void BaseCamCS::MakeActive()
{
    return stub<thiscall_t<void, BaseCamCS*>>(0xFB4A0_Offset, this);
}

void BaseCamCS::UpdateInput()
{
    return stub<thiscall_t<void, BaseCamCS*>>(0xF99D0_Offset, this);
}

void BaseCamCS::ForceMatrixDelta(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, BaseCamCS*, class Vector3 const&>>(0xFC090_Offset, this, arg1);
}

void BaseCamCS::SetST(f32* arg1)
{
    return stub<thiscall_t<void, BaseCamCS*, f32*>>(0xF6A50_Offset, this, arg1);
}

void BaseCamCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, BaseCamCS*, class Bank*>>(0xFBF40_Offset, this, arg1);
}

void BaseCamCS::AfterLoad()
{
    return stub<thiscall_t<void, BaseCamCS*>>(0xFBEB0_Offset, this);
}

class MetaClass* BaseCamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, BaseCamCS*>>(0xFC2C0_Offset, this);
}

i32 BaseCamCS::IsViewCSInTransition()
{
    return stub<thiscall_t<i32, BaseCamCS*>>(0xFBEC0_Offset, this);
}

void BaseCamCS::UpdateView()
{
    return stub<thiscall_t<void, BaseCamCS*>>(0xFBEF0_Offset, this);
}

void BaseCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0xFC0E0_Offset);
}
