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
    mmcity:sky

    0x4955D0 | public: __thiscall mmSky::mmSky(void) | ??0mmSky@@QAE@XZ
    0x495610 | public: __thiscall mmSky::~mmSky(void) | ??1mmSky@@QAE@XZ
    0x495650 | public: void __thiscall mmSky::Init(char *) | ?Init@mmSky@@QAEXPAD@Z
    0x495680 | public: void __thiscall mmSky::SetTexture(class agiTexDef *) | ?SetTexture@mmSky@@QAEXPAVagiTexDef@@@Z
    0x4956A0 | public: void __thiscall mmSky::Draw(class Matrix34 &) | ?Draw@mmSky@@QAEXAAVMatrix34@@@Z
    0x63FC50 | public: static unsigned int mmSky::Color | ?Color@mmSky@@2IA
    0x63FC54 | float SkyScale | ?SkyScale@@3MA
    0x7056FC | private: static int mmSky::DoFlash | ?DoFlash@mmSky@@0HA
    0x705700 | class agiTexDef * FlashTex | ?FlashTex@@3PAVagiTexDef@@A
    0x705704 | private: static class mmSky * mmSky::Instance | ?Instance@mmSky@@0PAV1@A
*/

class mmSky
{
public:
    // 0x4955D0 | ??0mmSky@@QAE@XZ
    ARTS_IMPORT mmSky();

    // 0x495610 | ??1mmSky@@QAE@XZ
    ARTS_IMPORT ~mmSky();

    // 0x4956A0 | ?Draw@mmSky@@QAEXAAVMatrix34@@@Z
    ARTS_IMPORT void Draw(class Matrix34& arg1);

    // 0x495650 | ?Init@mmSky@@QAEXPAD@Z
    ARTS_IMPORT void Init(char* arg1);

    // 0x495680 | ?SetTexture@mmSky@@QAEXPAVagiTexDef@@@Z
    ARTS_IMPORT void SetTexture(class agiTexDef* arg1);

    // 0x63FC50 | ?Color@mmSky@@2IA
    ARTS_IMPORT static u32 Color;

private:
    // 0x7056FC | ?DoFlash@mmSky@@0HA
    ARTS_IMPORT static i32 DoFlash;

    // 0x705704 | ?Instance@mmSky@@0PAV1@A
    ARTS_IMPORT static class mmSky* Instance;

    u8 gap0[0x8];
};

check_size(mmSky, 0x8);

// 0x705700 | ?FlashTex@@3PAVagiTexDef@@A
ARTS_IMPORT extern class agiTexDef* FlashTex;

// 0x63FC54 | ?SkyScale@@3MA
ARTS_IMPORT extern f32 SkyScale;
