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

struct mmFacadeBangerInstance
{
public:
    // 0x4CB940 | ?GetPos@mmFacadeBangerInstance@@UAIAAVVector3@@XZ
    class Vector3& __fastcall GetPos();

    // 0x4CB890 | ?ToMatrix@mmFacadeBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    class Matrix34& __fastcall ToMatrix(class Matrix34& arg1);
};

check_size(mmFacadeBangerInstance, 0x0);

struct mmGlassBangerInstance
{
private:
    // 0x4CB9C0 | ?Draw@mmGlassBangerInstance@@EAIXH@Z
    void __fastcall Draw(i32 arg1);
};

check_size(mmGlassBangerInstance, 0x0);
