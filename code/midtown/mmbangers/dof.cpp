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

#include "dof.h"

class Vector3& __fastcall mmFacadeBangerInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmFacadeBangerInstance*>>(0xCB940_Offset, this);
}

class Matrix34& __fastcall mmFacadeBangerInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmFacadeBangerInstance*, class Matrix34&>>(0xCB890_Offset, this, arg1);
}

void __fastcall mmGlassBangerInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmGlassBangerInstance*, i32>>(0xCB9C0_Offset, this, arg1);
}

define_dummy_symbol(mmbangers_dof);
