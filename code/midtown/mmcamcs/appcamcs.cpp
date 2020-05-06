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

define_dummy_symbol(mmcamcs_appcamcs);

#include "appcamcs.h"

AppCamCS::AppCamCS()
{
    unimplemented();
}

AppCamCS::~AppCamCS()
{
    unimplemented(arg1);
}

void AppCamCS::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, AppCamCS*, class Bank*>>(0x4FCDB0, this, arg1);
}

class MetaClass* AppCamCS::GetClass()
{
    return stub<thiscall_t<class MetaClass*, AppCamCS*>>(0x4FD380, this);
}

void AppCamCS::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4FD0D0);
}

void AppCamCS::ApproachIt()
{
    return stub<thiscall_t<void, AppCamCS*>>(0x4FC430, this);
}

i32 AppCamCS::DApproach(f32& arg1, f32 arg2, f32 arg3, f32 arg4, f32& arg5, f32 arg6)
{
    return stub<thiscall_t<i32, AppCamCS*, f32&, f32, f32, f32, f32&, f32>>(
        0x4FCC60, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void AppCamCS::UpdateApproach()
{
    return stub<thiscall_t<void, AppCamCS*>>(0x4FC460, this);
}

void AppCamCS::UpdateMaxDist()
{
    return stub<thiscall_t<void, AppCamCS*>>(0x4FC9D0, this);
}
