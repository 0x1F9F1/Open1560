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
    agi:palette

    0x55C090 | public: __thiscall agiPalette::agiPalette(void) | ??0agiPalette@@QAE@XZ
    0x55C0B0 | public: void __thiscall agiPalette::Kill(void) | ?Kill@agiPalette@@QAEXXZ
    0x55C0F0 | public: void __thiscall agiPalette::Cube(void) | ?Cube@agiPalette@@QAEXXZ
    0x55C180 | public: void __thiscall agiPalette::Load(char *) | ?Load@agiPalette@@QAEXPAD@Z
    0x55C310 | public: unsigned int __thiscall agiPalette::GetColor(struct agiRgba) | ?GetColor@agiPalette@@QAEIUagiRgba@@@Z
    0x55C3A0 | public: unsigned int __thiscall agiPalette::FindColor(struct agiRgba) | ?FindColor@agiPalette@@QAEIUagiRgba@@@Z
    0x907238 | class agiPalette agiPal | ?agiPal@@3VagiPalette@@A
*/

class agiPalette
{
public:
    // 0x55C090 | ??0agiPalette@@QAE@XZ
    agiPalette();

    // 0x55C0F0 | ?Cube@agiPalette@@QAEXXZ
    void Cube();

    // 0x55C3A0 | ?FindColor@agiPalette@@QAEIUagiRgba@@@Z
    u32 FindColor(struct agiRgba arg1);

    // 0x55C310 | ?GetColor@agiPalette@@QAEIUagiRgba@@@Z
    u32 GetColor(struct agiRgba arg1);

    // 0x55C0B0 | ?Kill@agiPalette@@QAEXXZ
    void Kill();

    // 0x55C180 | ?Load@agiPalette@@QAEXPAD@Z
    void Load(char* arg1);
};

check_size(agiPalette, 0x0);

// 0x907238 | ?agiPal@@3VagiPalette@@A
inline extern_var(0x907238, class agiPalette, agiPal);
