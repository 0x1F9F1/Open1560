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

define_dummy_symbol(mmcamcs_viewcs);

#include "viewcs.h"

mmViewCS::mmViewCS()
{
    unimplemented();
}

mmViewCS::~mmViewCS()
{
    unimplemented(arg1);
}

void mmViewCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmViewCS*, class Bank*>>(0x4F9560, this, arg1);
}

void mmViewCS::ForceMatrixDelta(class Matrix34 const& arg1)
{
    return stub<thiscall_t<void, mmViewCS*, class Matrix34 const&>>(0x4F9320, this, arg1);
}

void mmViewCS::ForceMatrixDelta(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, mmViewCS*, class Vector3 const&>>(0x4F9340, this, arg1);
}

class MetaClass* mmViewCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmViewCS*>>(0x4F94F0, this);
}

void mmViewCS::Init()
{
    return stub<thiscall_t<void, mmViewCS*>>(0x4F9260, this);
}

i32 mmViewCS::NewCam(class CarCamCS* arg1, i32 arg2, f32 arg3, class Callback arg4)
{
    return stub<thiscall_t<i32, mmViewCS*, class CarCamCS*, i32, f32, class Callback>>(
        0x4F9180, this, arg1, arg2, arg3, arg4);
}

void mmViewCS::OneShot()
{
    return stub<thiscall_t<void, mmViewCS*>>(0x4F9360, this);
}

void mmViewCS::Reset()
{
    return stub<thiscall_t<void, mmViewCS*>>(0x4F92C0, this);
}

void mmViewCS::SetCamera(class asCamera* arg1)
{
    return stub<thiscall_t<void, mmViewCS*, class asCamera*>>(0x4F9270, this, arg1);
}

void mmViewCS::SetCurrentCam(class CarCamCS* arg1)
{
    return stub<thiscall_t<void, mmViewCS*, class CarCamCS*>>(0x4F9110, this, arg1);
}

void mmViewCS::Update()
{
    return stub<thiscall_t<void, mmViewCS*>>(0x4F9230, this);
}

void mmViewCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4F9380);
}

class mmViewCS* mmViewCS::Instance(class asCamera* arg1)
{
    return stub<cdecl_t<class mmViewCS*, class asCamera*>>(0x4F9080, arg1);
}
