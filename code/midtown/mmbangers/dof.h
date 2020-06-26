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
    // const mmDofBangerInstance::`vftable' @ 0x61F478

public:
    // 0x4C4EC0 | ??_GmmDofBangerInstance@@UAEPAXI@Z
    // 0x4C4EE0 | ??1mmDofBangerInstance@@UAE@XZ | inline
    ARTS_IMPORT ~mmDofBangerInstance() override;

    // 0x4C4E50 | ?FromMatrix@mmDofBangerInstance@@UAIXABVMatrix34@@@Z | inline
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(class Matrix34 const& arg1) override;

    // 0x4C4E90 | ?GetPos@mmDofBangerInstance@@UAIAAVVector3@@XZ | inline
    ARTS_IMPORT class Vector3& ARTS_FASTCALL GetPos() override;

    // 0x4CB7E0 | ?Init@mmDofBangerInstance@@QAEHPAD0HPAVMatrix34@@PAVVector3@@@Z
    ARTS_IMPORT i32 Init(char* arg1, char* arg2, i32 arg3, class Matrix34* arg4, class Vector3* arg5);

    // 0x4CB7D0 | ?SizeOf@mmDofBangerInstance@@UAEIXZ
    ARTS_IMPORT u32 SizeOf() override;

    // 0x4C4E60 | ?ToMatrix@mmDofBangerInstance@@UAIAAVMatrix34@@AAV2@@Z | inline
    ARTS_IMPORT class Matrix34& ARTS_FASTCALL ToMatrix(class Matrix34& arg1) override;
};

check_size(mmDofBangerInstance, 0x34);

class mmFacadeBangerInstance : public mmBangerInstance
{
public:
    // 0x4CB940 | ?GetPos@mmFacadeBangerInstance@@UAIAAVVector3@@XZ | unused
    ARTS_IMPORT class Vector3& ARTS_FASTCALL GetPos();

    // 0x4CB890 | ?ToMatrix@mmFacadeBangerInstance@@UAIAAVMatrix34@@AAV2@@Z | unused
    ARTS_IMPORT class Matrix34& ARTS_FASTCALL ToMatrix(class Matrix34& arg1);
};

check_size(mmFacadeBangerInstance, 0x30);

class mmGlassBangerInstance : public mmBangerInstance
{
private:
    // 0x4CB9C0 | ?Draw@mmGlassBangerInstance@@EAIXH@Z | unused
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1);
};

check_size(mmGlassBangerInstance, 0x1C);
