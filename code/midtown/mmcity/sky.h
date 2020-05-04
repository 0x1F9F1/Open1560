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
    mmSky();

    // 0x495610 | ??1mmSky@@QAE@XZ
    ~mmSky();

    // 0x4956A0 | ?Draw@mmSky@@QAEXAAVMatrix34@@@Z
    void Draw(class Matrix34& arg1);

    // 0x495650 | ?Init@mmSky@@QAEXPAD@Z
    void Init(char* arg1);

    // 0x495680 | ?SetTexture@mmSky@@QAEXPAVagiTexDef@@@Z
    void SetTexture(class agiTexDef* arg1);

    // 0x63FC50 | ?Color@mmSky@@2IA
    static inline extern_var(0x23FC50_Offset, u32, Color);

private:
    // 0x7056FC | ?DoFlash@mmSky@@0HA
    static inline extern_var(0x3056FC_Offset, i32, DoFlash);

    // 0x705704 | ?Instance@mmSky@@0PAV1@A
    static inline extern_var(0x305704_Offset, class mmSky*, Instance);
};

check_size(mmSky, 0x0);

// 0x705700 | ?FlashTex@@3PAVagiTexDef@@A
inline extern_var(0x305700_Offset, class agiTexDef*, FlashTex);

// 0x63FC54 | ?SkyScale@@3MA
inline extern_var(0x23FC54_Offset, f32, SkyScale);
