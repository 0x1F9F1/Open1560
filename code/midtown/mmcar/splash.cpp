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

define_dummy_symbol(mmcar_splash);

#include "splash.h"

mmSplash::mmSplash()
{
    unimplemented();
}

mmSplash::~mmSplash()
{
    unimplemented();
}

void mmSplash::Activate(f32 arg1)
{
    return stub<thiscall_t<void, mmSplash*, f32>>(0x4811C0, this, arg1);
}

void mmSplash::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmSplash*, class Bank*>>(0x481420, this, arg1);
}

void mmSplash::Init(class asInertialCS* arg1, class Vector3 arg2, class Vector3 arg3)
{
    return stub<thiscall_t<void, mmSplash*, class asInertialCS*, class Vector3, class Vector3>>(
        0x481070, this, arg1, arg2, arg3);
}

void mmSplash::Reset()
{
    return stub<thiscall_t<void, mmSplash*>>(0x481060, this);
}

void mmSplash::Update()
{
    return stub<thiscall_t<void, mmSplash*>>(0x4811E0, this);
}

static void SplashCB(class mmSplash* arg1)
{
    return stub<cdecl_t<void, class mmSplash*>>(0x481050, arg1);
}
