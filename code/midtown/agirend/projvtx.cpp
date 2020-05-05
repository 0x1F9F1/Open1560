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

define_dummy_symbol(agirend_projvtx);

#include "projvtx.h"

void agiProjVtx::Init(i32 arg1, class agiLighter* arg2, u32 arg3)
{
    return stub<cdecl_t<void, i32, class agiLighter*, u32>>(0x152BA0_Offset, arg1, arg2, arg3);
}

void agiProjVtx::InitMtx(class Matrix34& arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<cdecl_t<void, class Matrix34&, f32, f32, f32, f32>>(0x1524F0_Offset, arg1, arg2, arg3, arg4, arg5);
}

i32 agiProjVtx::Project(i32 arg1, struct agiLitVtx* arg2)
{
    return stub<cdecl_t<i32, i32, struct agiLitVtx*>>(0x152710_Offset, arg1, arg2);
}

void agiProjVtx::SetOutcode(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x152630_Offset, arg1);
}

void agiProjVtx::ToScreen(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x152A20_Offset, arg1);
}
