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

define_dummy_symbol(mmcity_inst);

#include "inst.h"

class mmPhysEntity* mmInstance::GetEntity()
{
    return nullptr;
}

class mmPhysEntity* mmInstance::AttachEntity()
{
    return nullptr;
}

void mmInstance::Impact(class mmInstance* /*arg1*/, class Vector3* /*arg2*/)
{}

void mmInstance::Detach()
{}

void ARTS_FASTCALL mmInstance::DrawShadow()
{}

void ARTS_FASTCALL mmInstance::DrawGlow()
{}

void ARTS_FASTCALL mmInstance::Relight()
{}

void mmInstance::Reset()
{}

i32 mmInstance::Init(char* /*arg1*/, class Vector3& /*arg2*/, class Vector3& /*arg3*/, i32 /*arg4*/, char* /*arg5*/)
{
    return 0;
}

// 0x493670 | ?MatrixFromPoints@@YAXAAVMatrix34@@AAVVector3@@1M@Z
ARTS_IMPORT /*static*/ void MatrixFromPoints(class Matrix34& arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4);

void mmMatrixInstance::Hit(class mmInstance* /*arg1*/)
{}

void mmMatrixInstance::AddWidgets(class Bank* /*arg1*/)
{}

void ARTS_FASTCALL mmStaticInstance::Relight()
{}
