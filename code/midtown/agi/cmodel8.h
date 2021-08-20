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
    agi:cmodel8

    0x55BEB0 | public: __thiscall agiColorModel8::agiColorModel8(class agiPalette *) | ??0agiColorModel8@@QAE@PAVagiPalette@@@Z
    0x55BF00 | public: virtual __thiscall agiColorModel8::~agiColorModel8(void) | ??1agiColorModel8@@UAE@XZ
    0x55BF10 | public: virtual unsigned int __thiscall agiColorModel8::GetColor(struct agiRgba) | ?GetColor@agiColorModel8@@UAEIUagiRgba@@@Z
    0x55BF30 | public: virtual unsigned int __thiscall agiColorModel8::FindColor(struct agiRgba) | ?FindColor@agiColorModel8@@UAEIUagiRgba@@@Z
    0x55BF50 | public: virtual unsigned int __thiscall agiColorModel8::Filter(unsigned int,unsigned int,unsigned int,unsigned int) | ?Filter@agiColorModel8@@UAEIIIII@Z
    0x55C000 | public: virtual unsigned int __thiscall agiColorModel8::GetPixel(class agiSurfaceDesc *,int,int) | ?GetPixel@agiColorModel8@@UAEIPAVagiSurfaceDesc@@HH@Z
    0x55C020 | public: virtual void __thiscall agiColorModel8::SetPixel(class agiSurfaceDesc *,int,int,unsigned int) | ?SetPixel@agiColorModel8@@UAEXPAVagiSurfaceDesc@@HHI@Z
    0x55C040 | public: virtual void * __thiscall agiColorModel8::`scalar deleting destructor'(unsigned int) | ??_GagiColorModel8@@UAEPAXI@Z
    0x55C040 | public: virtual void * __thiscall agiColorModel8::`vector deleting destructor'(unsigned int) | ??_EagiColorModel8@@UAEPAXI@Z
    0x621780 | const agiColorModel8::`vftable' | ??_7agiColorModel8@@6B@
*/

#include "cmodel.h"

class agiPalette;

class agiColorModel8 final : public agiColorModel
{
public:
    // ??0agiColorModel8@@QAE@PAVagiPalette@@@Z
    ARTS_IMPORT agiColorModel8(agiPalette* arg1);

    // ??_EagiColorModel8@@UAEPAXI@Z
    // ??_GagiColorModel8@@UAEPAXI@Z
    // ??1agiColorModel8@@UAE@XZ
    ARTS_IMPORT ~agiColorModel8() override = default;

    // ?Filter@agiColorModel8@@UAEIIIII@Z
    ARTS_IMPORT u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // ?FindColor@agiColorModel8@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1) override;

    // ?GetColor@agiColorModel8@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1) override;

    // ?GetPixel@agiColorModel8@@UAEIPAVagiSurfaceDesc@@HH@Z
    ARTS_EXPORT u32 GetPixel(agiSurfaceDesc* surface, i32 x, i32 y) override;

    // ?SetPixel@agiColorModel8@@UAEXPAVagiSurfaceDesc@@HHI@Z
    ARTS_EXPORT void SetPixel(agiSurfaceDesc* surface, i32 x, i32 y, u32 color) override;

    agiPalette* Palette {nullptr};
};

check_size(agiColorModel8, 0x30);
