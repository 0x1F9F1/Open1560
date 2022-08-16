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

#pragma once

/*
    mmbangers:dof

    0x4CB7D0 | public: virtual unsigned int __thiscall mmDofBangerInstance::SizeOf(void) | ?SizeOf@mmDofBangerInstance@@UAEIXZ
    0x4CB7E0 | public: int __thiscall mmDofBangerInstance::Init(char *,char *,int,class Matrix34 *,class Vector3 *) | ?Init@mmDofBangerInstance@@QAEHPAD0HPAVMatrix34@@PAVVector3@@@Z
    0x4CB890 | public: virtual class Matrix34 & __fastcall mmFacadeBangerInstance::ToMatrix(class Matrix34 &) | ?ToMatrix@mmFacadeBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    0x4CB940 | public: virtual class Vector3 & __fastcall mmFacadeBangerInstance::GetPos(void) | ?GetPos@mmFacadeBangerInstance@@UAIAAVVector3@@XZ
    0x4CB9C0 | private: virtual void __fastcall mmGlassBangerInstance::Draw(int) | ?Draw@mmGlassBangerInstance@@EAIXH@Z
*/

#include "banger.h"

class mmDofBangerInstance : public mmUnhitBangerInstance
{
public:
    // ??_GmmDofBangerInstance@@UAEPAXI@Z
    // ??_EmmDofBangerInstance@@UAEPAXI@Z
    // ??1mmDofBangerInstance@@UAE@XZ | inline
    ARTS_IMPORT ~mmDofBangerInstance() override = default;

    // ?FromMatrix@mmDofBangerInstance@@UAIXABVMatrix34@@@Z | inline
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(const Matrix34& arg1) override;

    // ?GetPos@mmDofBangerInstance@@UAIAAVVector3@@XZ | inline
    ARTS_IMPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?Init@mmDofBangerInstance@@QAEHPAD0HPAVMatrix34@@PAVVector3@@@Z
    ARTS_IMPORT i32 Init(char* name, char* part, i32 flags, Matrix34* matrix, Vector3* offset);

    // ?SizeOf@mmDofBangerInstance@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;

    // ?ToMatrix@mmDofBangerInstance@@UAIAAVMatrix34@@AAV2@@Z | inline
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) override;

    u8 gap30[0x4];
};

check_size(mmDofBangerInstance, 0x34);

#if 0
class mmFacadeBangerInstance final : public mmBangerInstance
{
public:
    // ?GetPos@mmFacadeBangerInstance@@UAIAAVVector3@@XZ | unused
    ARTS_IMPORT Vector3& ARTS_FASTCALL GetPos();

    // ?ToMatrix@mmFacadeBangerInstance@@UAIAAVMatrix34@@AAV2@@Z | unused
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1);

    u8 gap1C[0x14];
};

check_size(mmFacadeBangerInstance, 0x30);

class mmGlassBangerInstance final : public mmBangerInstance
{
private:
    // ?Draw@mmGlassBangerInstance@@EAIXH@Z | unused
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1);
};

check_size(mmGlassBangerInstance, 0x1C);
#endif