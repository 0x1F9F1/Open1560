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
    agi:cmodelx

    0x55C4A0 | public: __thiscall agiColorModelRGB555::agiColorModelRGB555(void) | ??0agiColorModelRGB555@@QAE@XZ
    0x55C4E0 | public: virtual unsigned int __thiscall agiColorModelRGB555::GetColor(struct agiRgba) | ?GetColor@agiColorModelRGB555@@UAEIUagiRgba@@@Z
    0x55C520 | public: virtual unsigned int __thiscall agiColorModelRGB555::FindColor(struct agiRgba) | ?FindColor@agiColorModelRGB555@@UAEIUagiRgba@@@Z
    0x55C560 | public: virtual unsigned int __thiscall agiColorModelRGB555::Filter(unsigned int,unsigned int,unsigned int,unsigned int) | ?Filter@agiColorModelRGB555@@UAEIIIII@Z
    0x55C5F0 | public: virtual unsigned int __thiscall agiColorModelRGB555::GetPixel(class agiSurfaceDesc *,int,int) | ?GetPixel@agiColorModelRGB555@@UAEIPAVagiSurfaceDesc@@HH@Z
    0x55C610 | public: virtual void __thiscall agiColorModelRGB555::SetPixel(class agiSurfaceDesc *,int,int,unsigned int) | ?SetPixel@agiColorModelRGB555@@UAEXPAVagiSurfaceDesc@@HHI@Z
    0x55C680 | public: __thiscall agiColorModelRGB565::agiColorModelRGB565(void) | ??0agiColorModelRGB565@@QAE@XZ
    0x55C6C0 | public: virtual unsigned int __thiscall agiColorModelRGB565::GetColor(struct agiRgba) | ?GetColor@agiColorModelRGB565@@UAEIUagiRgba@@@Z
    0x55C700 | public: virtual unsigned int __thiscall agiColorModelRGB565::FindColor(struct agiRgba) | ?FindColor@agiColorModelRGB565@@UAEIUagiRgba@@@Z
    0x55C740 | public: virtual unsigned int __thiscall agiColorModelRGB565::Filter(unsigned int,unsigned int,unsigned int,unsigned int) | ?Filter@agiColorModelRGB565@@UAEIIIII@Z
    0x55C7D0 | public: virtual unsigned int __thiscall agiColorModelRGB565::GetPixel(class agiSurfaceDesc *,int,int) | ?GetPixel@agiColorModelRGB565@@UAEIPAVagiSurfaceDesc@@HH@Z
    0x55C7F0 | public: virtual void __thiscall agiColorModelRGB565::SetPixel(class agiSurfaceDesc *,int,int,unsigned int) | ?SetPixel@agiColorModelRGB565@@UAEXPAVagiSurfaceDesc@@HHI@Z
    0x55C860 | public: __thiscall agiColorModelRGB555_Rev::agiColorModelRGB555_Rev(void) | ??0agiColorModelRGB555_Rev@@QAE@XZ
    0x55C8A0 | public: virtual unsigned int __thiscall agiColorModelRGB555_Rev::GetColor(struct agiRgba) | ?GetColor@agiColorModelRGB555_Rev@@UAEIUagiRgba@@@Z
    0x55C8E0 | public: virtual unsigned int __thiscall agiColorModelRGB555_Rev::FindColor(struct agiRgba) | ?FindColor@agiColorModelRGB555_Rev@@UAEIUagiRgba@@@Z
    0x55C920 | public: virtual unsigned int __thiscall agiColorModelRGB555_Rev::Filter(unsigned int,unsigned int,unsigned int,unsigned int) | ?Filter@agiColorModelRGB555_Rev@@UAEIIIII@Z
    0x55C9B0 | public: virtual unsigned int __thiscall agiColorModelRGB555_Rev::GetPixel(class agiSurfaceDesc *,int,int) | ?GetPixel@agiColorModelRGB555_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    0x55C9D0 | public: virtual void __thiscall agiColorModelRGB555_Rev::SetPixel(class agiSurfaceDesc *,int,int,unsigned int) | ?SetPixel@agiColorModelRGB555_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    0x55CA40 | public: __thiscall agiColorModelRGB565_Rev::agiColorModelRGB565_Rev(void) | ??0agiColorModelRGB565_Rev@@QAE@XZ
    0x55CA80 | public: virtual unsigned int __thiscall agiColorModelRGB565_Rev::GetColor(struct agiRgba) | ?GetColor@agiColorModelRGB565_Rev@@UAEIUagiRgba@@@Z
    0x55CAC0 | public: virtual unsigned int __thiscall agiColorModelRGB565_Rev::FindColor(struct agiRgba) | ?FindColor@agiColorModelRGB565_Rev@@UAEIUagiRgba@@@Z
    0x55CB00 | public: virtual unsigned int __thiscall agiColorModelRGB565_Rev::Filter(unsigned int,unsigned int,unsigned int,unsigned int) | ?Filter@agiColorModelRGB565_Rev@@UAEIIIII@Z
    0x55CB90 | public: virtual unsigned int __thiscall agiColorModelRGB565_Rev::GetPixel(class agiSurfaceDesc *,int,int) | ?GetPixel@agiColorModelRGB565_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    0x55CBB0 | public: virtual void __thiscall agiColorModelRGB565_Rev::SetPixel(class agiSurfaceDesc *,int,int,unsigned int) | ?SetPixel@agiColorModelRGB565_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    0x55CC20 | public: __thiscall agiColorModelRGB888::agiColorModelRGB888(void) | ??0agiColorModelRGB888@@QAE@XZ
    0x55CC60 | public: virtual unsigned int __thiscall agiColorModelRGB888::GetColor(struct agiRgba) | ?GetColor@agiColorModelRGB888@@UAEIUagiRgba@@@Z
    0x55CC90 | public: virtual unsigned int __thiscall agiColorModelRGB888::FindColor(struct agiRgba) | ?FindColor@agiColorModelRGB888@@UAEIUagiRgba@@@Z
    0x55CCC0 | public: virtual unsigned int __thiscall agiColorModelRGB888::Filter(unsigned int,unsigned int,unsigned int,unsigned int) | ?Filter@agiColorModelRGB888@@UAEIIIII@Z
    0x55CD40 | public: virtual unsigned int __thiscall agiColorModelRGB888::GetPixel(class agiSurfaceDesc *,int,int) | ?GetPixel@agiColorModelRGB888@@UAEIPAVagiSurfaceDesc@@HH@Z
    0x55CD60 | public: virtual void __thiscall agiColorModelRGB888::SetPixel(class agiSurfaceDesc *,int,int,unsigned int) | ?SetPixel@agiColorModelRGB888@@UAEXPAVagiSurfaceDesc@@HHI@Z
    0x55CDC0 | public: __thiscall agiColorModelRGB888_Rev::agiColorModelRGB888_Rev(void) | ??0agiColorModelRGB888_Rev@@QAE@XZ
    0x55CE00 | public: virtual unsigned int __thiscall agiColorModelRGB888_Rev::GetColor(struct agiRgba) | ?GetColor@agiColorModelRGB888_Rev@@UAEIUagiRgba@@@Z
    0x55CE30 | public: virtual unsigned int __thiscall agiColorModelRGB888_Rev::FindColor(struct agiRgba) | ?FindColor@agiColorModelRGB888_Rev@@UAEIUagiRgba@@@Z
    0x55CE60 | public: virtual unsigned int __thiscall agiColorModelRGB888_Rev::Filter(unsigned int,unsigned int,unsigned int,unsigned int) | ?Filter@agiColorModelRGB888_Rev@@UAEIIIII@Z
    0x55CEE0 | public: virtual unsigned int __thiscall agiColorModelRGB888_Rev::GetPixel(class agiSurfaceDesc *,int,int) | ?GetPixel@agiColorModelRGB888_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    0x55CF00 | public: virtual void __thiscall agiColorModelRGB888_Rev::SetPixel(class agiSurfaceDesc *,int,int,unsigned int) | ?SetPixel@agiColorModelRGB888_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    0x55CF60 | public: __thiscall agiColorModelRGBA5551::agiColorModelRGBA5551(void) | ??0agiColorModelRGBA5551@@QAE@XZ
    0x55CFB0 | public: virtual unsigned int __thiscall agiColorModelRGBA5551::GetColor(struct agiRgba) | ?GetColor@agiColorModelRGBA5551@@UAEIUagiRgba@@@Z
    0x55D000 | public: virtual unsigned int __thiscall agiColorModelRGBA5551::FindColor(struct agiRgba) | ?FindColor@agiColorModelRGBA5551@@UAEIUagiRgba@@@Z
    0x55D050 | public: virtual unsigned int __thiscall agiColorModelRGBA5551::Filter(unsigned int,unsigned int,unsigned int,unsigned int) | ?Filter@agiColorModelRGBA5551@@UAEIIIII@Z
    0x55D110 | public: virtual unsigned int __thiscall agiColorModelRGBA5551::GetPixel(class agiSurfaceDesc *,int,int) | ?GetPixel@agiColorModelRGBA5551@@UAEIPAVagiSurfaceDesc@@HH@Z
    0x55D130 | public: virtual void __thiscall agiColorModelRGBA5551::SetPixel(class agiSurfaceDesc *,int,int,unsigned int) | ?SetPixel@agiColorModelRGBA5551@@UAEXPAVagiSurfaceDesc@@HHI@Z
    0x55D1A0 | public: __thiscall agiColorModelRGBA4444::agiColorModelRGBA4444(void) | ??0agiColorModelRGBA4444@@QAE@XZ
    0x55D1E0 | public: virtual unsigned int __thiscall agiColorModelRGBA4444::GetColor(struct agiRgba) | ?GetColor@agiColorModelRGBA4444@@UAEIUagiRgba@@@Z
    0x55D230 | public: virtual unsigned int __thiscall agiColorModelRGBA4444::FindColor(struct agiRgba) | ?FindColor@agiColorModelRGBA4444@@UAEIUagiRgba@@@Z
    0x55D280 | public: virtual unsigned int __thiscall agiColorModelRGBA4444::Filter(unsigned int,unsigned int,unsigned int,unsigned int) | ?Filter@agiColorModelRGBA4444@@UAEIIIII@Z
    0x55D340 | public: virtual unsigned int __thiscall agiColorModelRGBA4444::GetPixel(class agiSurfaceDesc *,int,int) | ?GetPixel@agiColorModelRGBA4444@@UAEIPAVagiSurfaceDesc@@HH@Z
    0x55D360 | public: virtual void __thiscall agiColorModelRGBA4444::SetPixel(class agiSurfaceDesc *,int,int,unsigned int) | ?SetPixel@agiColorModelRGBA4444@@UAEXPAVagiSurfaceDesc@@HHI@Z
    0x55D3D0 | public: __thiscall agiColorModelARGB::agiColorModelARGB(void) | ??0agiColorModelARGB@@QAE@XZ
    0x55D410 | public: virtual unsigned int __thiscall agiColorModelARGB::GetColor(struct agiRgba) | ?GetColor@agiColorModelARGB@@UAEIUagiRgba@@@Z
    0x55D450 | public: virtual unsigned int __thiscall agiColorModelARGB::FindColor(struct agiRgba) | ?FindColor@agiColorModelARGB@@UAEIUagiRgba@@@Z
    0x55D490 | public: virtual unsigned int __thiscall agiColorModelARGB::Filter(unsigned int,unsigned int,unsigned int,unsigned int) | ?Filter@agiColorModelARGB@@UAEIIIII@Z
    0x55D530 | public: virtual unsigned int __thiscall agiColorModelARGB::GetPixel(class agiSurfaceDesc *,int,int) | ?GetPixel@agiColorModelARGB@@UAEIPAVagiSurfaceDesc@@HH@Z
    0x55D550 | public: virtual void __thiscall agiColorModelARGB::SetPixel(class agiSurfaceDesc *,int,int,unsigned int) | ?SetPixel@agiColorModelARGB@@UAEXPAVagiSurfaceDesc@@HHI@Z
    0x55D5B0 | public: __thiscall agiColorModelABGR::agiColorModelABGR(void) | ??0agiColorModelABGR@@QAE@XZ
    0x55D5F0 | public: virtual unsigned int __thiscall agiColorModelABGR::GetColor(struct agiRgba) | ?GetColor@agiColorModelABGR@@UAEIUagiRgba@@@Z
    0x55D630 | public: virtual unsigned int __thiscall agiColorModelABGR::FindColor(struct agiRgba) | ?FindColor@agiColorModelABGR@@UAEIUagiRgba@@@Z
    0x55D670 | public: virtual unsigned int __thiscall agiColorModelABGR::Filter(unsigned int,unsigned int,unsigned int,unsigned int) | ?Filter@agiColorModelABGR@@UAEIIIII@Z
    0x55D720 | public: virtual unsigned int __thiscall agiColorModelABGR::GetPixel(class agiSurfaceDesc *,int,int) | ?GetPixel@agiColorModelABGR@@UAEIPAVagiSurfaceDesc@@HH@Z
    0x55D740 | public: virtual void __thiscall agiColorModelABGR::SetPixel(class agiSurfaceDesc *,int,int,unsigned int) | ?SetPixel@agiColorModelABGR@@UAEXPAVagiSurfaceDesc@@HHI@Z
    0x55D760 | public: static class agiColorModel * __cdecl agiColorModel::FindMatch(int,int,int,int) | ?FindMatch@agiColorModel@@SAPAV1@HHHH@Z
    0x55D810 | public: static class agiColorModel * __cdecl agiColorModel::FindMatch(class agiSurfaceDesc *) | ?FindMatch@agiColorModel@@SAPAV1@PAVagiSurfaceDesc@@@Z
    0x55D830 | public: virtual __thiscall agiColorModelRGB555::~agiColorModelRGB555(void) | ??1agiColorModelRGB555@@UAE@XZ
    0x55D840 | public: virtual void * __thiscall agiColorModelRGB555::`scalar deleting destructor'(unsigned int) | ??_GagiColorModelRGB555@@UAEPAXI@Z
    0x55D840 | public: virtual void * __thiscall agiColorModelRGB555::`vector deleting destructor'(unsigned int) | ??_EagiColorModelRGB555@@UAEPAXI@Z
    0x55D870 | public: virtual __thiscall agiColorModelRGB565::~agiColorModelRGB565(void) | ??1agiColorModelRGB565@@UAE@XZ
    0x55D880 | public: virtual void * __thiscall agiColorModelRGB565::`scalar deleting destructor'(unsigned int) | ??_GagiColorModelRGB565@@UAEPAXI@Z
    0x55D880 | public: virtual void * __thiscall agiColorModelRGB565::`vector deleting destructor'(unsigned int) | ??_EagiColorModelRGB565@@UAEPAXI@Z
    0x55D8B0 | public: virtual __thiscall agiColorModelRGB555_Rev::~agiColorModelRGB555_Rev(void) | ??1agiColorModelRGB555_Rev@@UAE@XZ
    0x55D8C0 | public: virtual void * __thiscall agiColorModelRGB555_Rev::`scalar deleting destructor'(unsigned int) | ??_GagiColorModelRGB555_Rev@@UAEPAXI@Z
    0x55D8C0 | public: virtual void * __thiscall agiColorModelRGB555_Rev::`vector deleting destructor'(unsigned int) | ??_EagiColorModelRGB555_Rev@@UAEPAXI@Z
    0x55D8F0 | public: virtual __thiscall agiColorModelRGB565_Rev::~agiColorModelRGB565_Rev(void) | ??1agiColorModelRGB565_Rev@@UAE@XZ
    0x55D900 | public: virtual void * __thiscall agiColorModelRGB565_Rev::`vector deleting destructor'(unsigned int) | ??_EagiColorModelRGB565_Rev@@UAEPAXI@Z
    0x55D900 | public: virtual void * __thiscall agiColorModelRGB565_Rev::`scalar deleting destructor'(unsigned int) | ??_GagiColorModelRGB565_Rev@@UAEPAXI@Z
    0x55D930 | public: virtual __thiscall agiColorModelRGB888::~agiColorModelRGB888(void) | ??1agiColorModelRGB888@@UAE@XZ
    0x55D940 | public: virtual void * __thiscall agiColorModelRGB888::`vector deleting destructor'(unsigned int) | ??_EagiColorModelRGB888@@UAEPAXI@Z
    0x55D940 | public: virtual void * __thiscall agiColorModelRGB888::`scalar deleting destructor'(unsigned int) | ??_GagiColorModelRGB888@@UAEPAXI@Z
    0x55D970 | public: virtual __thiscall agiColorModelRGB888_Rev::~agiColorModelRGB888_Rev(void) | ??1agiColorModelRGB888_Rev@@UAE@XZ
    0x55D980 | public: virtual void * __thiscall agiColorModelRGB888_Rev::`vector deleting destructor'(unsigned int) | ??_EagiColorModelRGB888_Rev@@UAEPAXI@Z
    0x55D980 | public: virtual void * __thiscall agiColorModelRGB888_Rev::`scalar deleting destructor'(unsigned int) | ??_GagiColorModelRGB888_Rev@@UAEPAXI@Z
    0x55D9B0 | public: virtual __thiscall agiColorModelRGBA5551::~agiColorModelRGBA5551(void) | ??1agiColorModelRGBA5551@@UAE@XZ
    0x55D9C0 | public: virtual void * __thiscall agiColorModelRGBA5551::`scalar deleting destructor'(unsigned int) | ??_GagiColorModelRGBA5551@@UAEPAXI@Z
    0x55D9C0 | public: virtual void * __thiscall agiColorModelRGBA5551::`vector deleting destructor'(unsigned int) | ??_EagiColorModelRGBA5551@@UAEPAXI@Z
    0x55D9F0 | public: virtual __thiscall agiColorModelRGBA4444::~agiColorModelRGBA4444(void) | ??1agiColorModelRGBA4444@@UAE@XZ
    0x55DA00 | public: virtual void * __thiscall agiColorModelRGBA4444::`scalar deleting destructor'(unsigned int) | ??_GagiColorModelRGBA4444@@UAEPAXI@Z
    0x55DA00 | public: virtual void * __thiscall agiColorModelRGBA4444::`vector deleting destructor'(unsigned int) | ??_EagiColorModelRGBA4444@@UAEPAXI@Z
    0x55DA30 | public: virtual __thiscall agiColorModelARGB::~agiColorModelARGB(void) | ??1agiColorModelARGB@@UAE@XZ
    0x55DA40 | public: virtual void * __thiscall agiColorModelARGB::`scalar deleting destructor'(unsigned int) | ??_GagiColorModelARGB@@UAEPAXI@Z
    0x55DA40 | public: virtual void * __thiscall agiColorModelARGB::`vector deleting destructor'(unsigned int) | ??_EagiColorModelARGB@@UAEPAXI@Z
    0x55DA70 | public: virtual __thiscall agiColorModelABGR::~agiColorModelABGR(void) | ??1agiColorModelABGR@@UAE@XZ
    0x55DA80 | public: virtual void * __thiscall agiColorModelABGR::`vector deleting destructor'(unsigned int) | ??_EagiColorModelABGR@@UAEPAXI@Z
    0x55DA80 | public: virtual void * __thiscall agiColorModelABGR::`scalar deleting destructor'(unsigned int) | ??_GagiColorModelABGR@@UAEPAXI@Z
    0x621798 | const agiColorModelRGB555::`vftable' | ??_7agiColorModelRGB555@@6B@
    0x6217B0 | const agiColorModelRGB565::`vftable' | ??_7agiColorModelRGB565@@6B@
    0x6217C8 | const agiColorModelRGB555_Rev::`vftable' | ??_7agiColorModelRGB555_Rev@@6B@
    0x6217E0 | const agiColorModelRGB565_Rev::`vftable' | ??_7agiColorModelRGB565_Rev@@6B@
    0x6217F8 | const agiColorModelRGB888::`vftable' | ??_7agiColorModelRGB888@@6B@
    0x621810 | const agiColorModelRGB888_Rev::`vftable' | ??_7agiColorModelRGB888_Rev@@6B@
    0x621828 | const agiColorModelRGBA5551::`vftable' | ??_7agiColorModelRGBA5551@@6B@
    0x621840 | const agiColorModelRGBA4444::`vftable' | ??_7agiColorModelRGBA4444@@6B@
    0x621858 | const agiColorModelARGB::`vftable' | ??_7agiColorModelARGB@@6B@
    0x621870 | const agiColorModelABGR::`vftable' | ??_7agiColorModelABGR@@6B@
    0x907648 | class agiColorModelARGB ColorModelARGB | ?ColorModelARGB@@3VagiColorModelARGB@@A
    0x907678 | class agiColorModelRGB565_Rev ColorModelRGB565_Rev | ?ColorModelRGB565_Rev@@3VagiColorModelRGB565_Rev@@A
    0x9076A8 | class agiColorModelABGR ColorModelABGR | ?ColorModelABGR@@3VagiColorModelABGR@@A
    0x9076D8 | class agiColorModelRGB555_Rev ColorModelRGB555_Rev | ?ColorModelRGB555_Rev@@3VagiColorModelRGB555_Rev@@A
    0x907708 | class agiColorModelRGB888_Rev ColorModelRGB888_Rev | ?ColorModelRGB888_Rev@@3VagiColorModelRGB888_Rev@@A
    0x907738 | class agiColorModelRGBA5551 ColorModelRGBA5551 | ?ColorModelRGBA5551@@3VagiColorModelRGBA5551@@A
    0x907768 | class agiColorModelRGBA4444 ColorModelRGBA4444 | ?ColorModelRGBA4444@@3VagiColorModelRGBA4444@@A
    0x907798 | class agiColorModelRGB888 ColorModelRGB888 | ?ColorModelRGB888@@3VagiColorModelRGB888@@A
    0x9077C8 | class agiColorModelRGB565 ColorModelRGB565 | ?ColorModelRGB565@@3VagiColorModelRGB565@@A
    0x9077F8 | class agiColorModelRGB555 ColorModelRGB555 | ?ColorModelRGB555@@3VagiColorModelRGB555@@A
*/

#include "cmodel.h"

class agiColorModelRGB555 : public agiColorModel
{
    // const agiColorModelRGB555::`vftable' @ 0x621798

public:
    // 0x55C4A0 | ??0agiColorModelRGB555@@QAE@XZ
    agiColorModelRGB555();

    // 0x55D840 | ??_EagiColorModelRGB555@@UAEPAXI@Z
    // 0x55D830 | ??1agiColorModelRGB555@@UAE@XZ
    ~agiColorModelRGB555() override;

    // 0x55C560 | ?Filter@agiColorModelRGB555@@UAEIIIII@Z
    u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // 0x55C520 | ?FindColor@agiColorModelRGB555@@UAEIUagiRgba@@@Z
    u32 FindColor(struct agiRgba arg1) override;

    // 0x55C4E0 | ?GetColor@agiColorModelRGB555@@UAEIUagiRgba@@@Z
    u32 GetColor(struct agiRgba arg1) override;

    // 0x55C5F0 | ?GetPixel@agiColorModelRGB555@@UAEIPAVagiSurfaceDesc@@HH@Z
    u32 GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3) override;

    // 0x55C610 | ?SetPixel@agiColorModelRGB555@@UAEXPAVagiSurfaceDesc@@HHI@Z
    void SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB555, 0x0);

class agiColorModelRGB565 : public agiColorModel
{
    // const agiColorModelRGB565::`vftable' @ 0x6217B0

public:
    // 0x55C680 | ??0agiColorModelRGB565@@QAE@XZ
    agiColorModelRGB565();

    // 0x55D880 | ??_EagiColorModelRGB565@@UAEPAXI@Z
    // 0x55D870 | ??1agiColorModelRGB565@@UAE@XZ
    ~agiColorModelRGB565() override;

    // 0x55C740 | ?Filter@agiColorModelRGB565@@UAEIIIII@Z
    u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // 0x55C700 | ?FindColor@agiColorModelRGB565@@UAEIUagiRgba@@@Z
    u32 FindColor(struct agiRgba arg1) override;

    // 0x55C6C0 | ?GetColor@agiColorModelRGB565@@UAEIUagiRgba@@@Z
    u32 GetColor(struct agiRgba arg1) override;

    // 0x55C7D0 | ?GetPixel@agiColorModelRGB565@@UAEIPAVagiSurfaceDesc@@HH@Z
    u32 GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3) override;

    // 0x55C7F0 | ?SetPixel@agiColorModelRGB565@@UAEXPAVagiSurfaceDesc@@HHI@Z
    void SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB565, 0x0);

class agiColorModelRGB555_Rev : public agiColorModel
{
    // const agiColorModelRGB555_Rev::`vftable' @ 0x6217C8

public:
    // 0x55C860 | ??0agiColorModelRGB555_Rev@@QAE@XZ
    agiColorModelRGB555_Rev();

    // 0x55D8C0 | ??_EagiColorModelRGB555_Rev@@UAEPAXI@Z
    // 0x55D8B0 | ??1agiColorModelRGB555_Rev@@UAE@XZ
    ~agiColorModelRGB555_Rev() override;

    // 0x55C920 | ?Filter@agiColorModelRGB555_Rev@@UAEIIIII@Z
    u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // 0x55C8E0 | ?FindColor@agiColorModelRGB555_Rev@@UAEIUagiRgba@@@Z
    u32 FindColor(struct agiRgba arg1) override;

    // 0x55C8A0 | ?GetColor@agiColorModelRGB555_Rev@@UAEIUagiRgba@@@Z
    u32 GetColor(struct agiRgba arg1) override;

    // 0x55C9B0 | ?GetPixel@agiColorModelRGB555_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    u32 GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3) override;

    // 0x55C9D0 | ?SetPixel@agiColorModelRGB555_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    void SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB555_Rev, 0x0);

class agiColorModelRGB565_Rev : public agiColorModel
{
    // const agiColorModelRGB565_Rev::`vftable' @ 0x6217E0

public:
    // 0x55CA40 | ??0agiColorModelRGB565_Rev@@QAE@XZ
    agiColorModelRGB565_Rev();

    // 0x55D900 | ??_GagiColorModelRGB565_Rev@@UAEPAXI@Z
    // 0x55D8F0 | ??1agiColorModelRGB565_Rev@@UAE@XZ
    ~agiColorModelRGB565_Rev() override;

    // 0x55CB00 | ?Filter@agiColorModelRGB565_Rev@@UAEIIIII@Z
    u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // 0x55CAC0 | ?FindColor@agiColorModelRGB565_Rev@@UAEIUagiRgba@@@Z
    u32 FindColor(struct agiRgba arg1) override;

    // 0x55CA80 | ?GetColor@agiColorModelRGB565_Rev@@UAEIUagiRgba@@@Z
    u32 GetColor(struct agiRgba arg1) override;

    // 0x55CB90 | ?GetPixel@agiColorModelRGB565_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    u32 GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3) override;

    // 0x55CBB0 | ?SetPixel@agiColorModelRGB565_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    void SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB565_Rev, 0x0);

class agiColorModelRGB888 : public agiColorModel
{
    // const agiColorModelRGB888::`vftable' @ 0x6217F8

public:
    // 0x55CC20 | ??0agiColorModelRGB888@@QAE@XZ
    agiColorModelRGB888();

    // 0x55D940 | ??_GagiColorModelRGB888@@UAEPAXI@Z
    // 0x55D930 | ??1agiColorModelRGB888@@UAE@XZ
    ~agiColorModelRGB888() override;

    // 0x55CCC0 | ?Filter@agiColorModelRGB888@@UAEIIIII@Z
    u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // 0x55CC90 | ?FindColor@agiColorModelRGB888@@UAEIUagiRgba@@@Z
    u32 FindColor(struct agiRgba arg1) override;

    // 0x55CC60 | ?GetColor@agiColorModelRGB888@@UAEIUagiRgba@@@Z
    u32 GetColor(struct agiRgba arg1) override;

    // 0x55CD40 | ?GetPixel@agiColorModelRGB888@@UAEIPAVagiSurfaceDesc@@HH@Z
    u32 GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3) override;

    // 0x55CD60 | ?SetPixel@agiColorModelRGB888@@UAEXPAVagiSurfaceDesc@@HHI@Z
    void SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB888, 0x0);

class agiColorModelRGB888_Rev : public agiColorModel
{
    // const agiColorModelRGB888_Rev::`vftable' @ 0x621810

public:
    // 0x55CDC0 | ??0agiColorModelRGB888_Rev@@QAE@XZ
    agiColorModelRGB888_Rev();

    // 0x55D980 | ??_GagiColorModelRGB888_Rev@@UAEPAXI@Z
    // 0x55D970 | ??1agiColorModelRGB888_Rev@@UAE@XZ
    ~agiColorModelRGB888_Rev() override;

    // 0x55CE60 | ?Filter@agiColorModelRGB888_Rev@@UAEIIIII@Z
    u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // 0x55CE30 | ?FindColor@agiColorModelRGB888_Rev@@UAEIUagiRgba@@@Z
    u32 FindColor(struct agiRgba arg1) override;

    // 0x55CE00 | ?GetColor@agiColorModelRGB888_Rev@@UAEIUagiRgba@@@Z
    u32 GetColor(struct agiRgba arg1) override;

    // 0x55CEE0 | ?GetPixel@agiColorModelRGB888_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    u32 GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3) override;

    // 0x55CF00 | ?SetPixel@agiColorModelRGB888_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    void SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB888_Rev, 0x0);

class agiColorModelRGBA5551 : public agiColorModel
{
    // const agiColorModelRGBA5551::`vftable' @ 0x621828

public:
    // 0x55CF60 | ??0agiColorModelRGBA5551@@QAE@XZ
    agiColorModelRGBA5551();

    // 0x55D9C0 | ??_EagiColorModelRGBA5551@@UAEPAXI@Z
    // 0x55D9B0 | ??1agiColorModelRGBA5551@@UAE@XZ
    ~agiColorModelRGBA5551() override;

    // 0x55D050 | ?Filter@agiColorModelRGBA5551@@UAEIIIII@Z
    u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // 0x55D000 | ?FindColor@agiColorModelRGBA5551@@UAEIUagiRgba@@@Z
    u32 FindColor(struct agiRgba arg1) override;

    // 0x55CFB0 | ?GetColor@agiColorModelRGBA5551@@UAEIUagiRgba@@@Z
    u32 GetColor(struct agiRgba arg1) override;

    // 0x55D110 | ?GetPixel@agiColorModelRGBA5551@@UAEIPAVagiSurfaceDesc@@HH@Z
    u32 GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3) override;

    // 0x55D130 | ?SetPixel@agiColorModelRGBA5551@@UAEXPAVagiSurfaceDesc@@HHI@Z
    void SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGBA5551, 0x0);

class agiColorModelRGBA4444 : public agiColorModel
{
    // const agiColorModelRGBA4444::`vftable' @ 0x621840

public:
    // 0x55D1A0 | ??0agiColorModelRGBA4444@@QAE@XZ
    agiColorModelRGBA4444();

    // 0x55DA00 | ??_EagiColorModelRGBA4444@@UAEPAXI@Z
    // 0x55D9F0 | ??1agiColorModelRGBA4444@@UAE@XZ
    ~agiColorModelRGBA4444() override;

    // 0x55D280 | ?Filter@agiColorModelRGBA4444@@UAEIIIII@Z
    u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // 0x55D230 | ?FindColor@agiColorModelRGBA4444@@UAEIUagiRgba@@@Z
    u32 FindColor(struct agiRgba arg1) override;

    // 0x55D1E0 | ?GetColor@agiColorModelRGBA4444@@UAEIUagiRgba@@@Z
    u32 GetColor(struct agiRgba arg1) override;

    // 0x55D340 | ?GetPixel@agiColorModelRGBA4444@@UAEIPAVagiSurfaceDesc@@HH@Z
    u32 GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3) override;

    // 0x55D360 | ?SetPixel@agiColorModelRGBA4444@@UAEXPAVagiSurfaceDesc@@HHI@Z
    void SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGBA4444, 0x0);

class agiColorModelARGB : public agiColorModel
{
    // const agiColorModelARGB::`vftable' @ 0x621858

public:
    // 0x55D3D0 | ??0agiColorModelARGB@@QAE@XZ
    agiColorModelARGB();

    // 0x55DA40 | ??_EagiColorModelARGB@@UAEPAXI@Z
    // 0x55DA30 | ??1agiColorModelARGB@@UAE@XZ
    ~agiColorModelARGB() override;

    // 0x55D490 | ?Filter@agiColorModelARGB@@UAEIIIII@Z
    u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // 0x55D450 | ?FindColor@agiColorModelARGB@@UAEIUagiRgba@@@Z
    u32 FindColor(struct agiRgba arg1) override;

    // 0x55D410 | ?GetColor@agiColorModelARGB@@UAEIUagiRgba@@@Z
    u32 GetColor(struct agiRgba arg1) override;

    // 0x55D530 | ?GetPixel@agiColorModelARGB@@UAEIPAVagiSurfaceDesc@@HH@Z
    u32 GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3) override;

    // 0x55D550 | ?SetPixel@agiColorModelARGB@@UAEXPAVagiSurfaceDesc@@HHI@Z
    void SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelARGB, 0x0);

class agiColorModelABGR : public agiColorModel
{
    // const agiColorModelABGR::`vftable' @ 0x621870

public:
    // 0x55D5B0 | ??0agiColorModelABGR@@QAE@XZ
    agiColorModelABGR();

    // 0x55DA80 | ??_GagiColorModelABGR@@UAEPAXI@Z
    // 0x55DA70 | ??1agiColorModelABGR@@UAE@XZ
    ~agiColorModelABGR() override;

    // 0x55D670 | ?Filter@agiColorModelABGR@@UAEIIIII@Z
    u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // 0x55D630 | ?FindColor@agiColorModelABGR@@UAEIUagiRgba@@@Z
    u32 FindColor(struct agiRgba arg1) override;

    // 0x55D5F0 | ?GetColor@agiColorModelABGR@@UAEIUagiRgba@@@Z
    u32 GetColor(struct agiRgba arg1) override;

    // 0x55D720 | ?GetPixel@agiColorModelABGR@@UAEIPAVagiSurfaceDesc@@HH@Z
    u32 GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3) override;

    // 0x55D740 | ?SetPixel@agiColorModelABGR@@UAEXPAVagiSurfaceDesc@@HHI@Z
    void SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelABGR, 0x0);

// 0x9076A8 | ?ColorModelABGR@@3VagiColorModelABGR@@A
inline extern_var(0x5076A8_Offset, class agiColorModelABGR, ColorModelABGR);

// 0x907648 | ?ColorModelARGB@@3VagiColorModelARGB@@A
inline extern_var(0x507648_Offset, class agiColorModelARGB, ColorModelARGB);

// 0x9077F8 | ?ColorModelRGB555@@3VagiColorModelRGB555@@A
inline extern_var(0x5077F8_Offset, class agiColorModelRGB555, ColorModelRGB555);

// 0x9076D8 | ?ColorModelRGB555_Rev@@3VagiColorModelRGB555_Rev@@A
inline extern_var(0x5076D8_Offset, class agiColorModelRGB555_Rev, ColorModelRGB555_Rev);

// 0x9077C8 | ?ColorModelRGB565@@3VagiColorModelRGB565@@A
inline extern_var(0x5077C8_Offset, class agiColorModelRGB565, ColorModelRGB565);

// 0x907678 | ?ColorModelRGB565_Rev@@3VagiColorModelRGB565_Rev@@A
inline extern_var(0x507678_Offset, class agiColorModelRGB565_Rev, ColorModelRGB565_Rev);

// 0x907798 | ?ColorModelRGB888@@3VagiColorModelRGB888@@A
inline extern_var(0x507798_Offset, class agiColorModelRGB888, ColorModelRGB888);

// 0x907708 | ?ColorModelRGB888_Rev@@3VagiColorModelRGB888_Rev@@A
inline extern_var(0x507708_Offset, class agiColorModelRGB888_Rev, ColorModelRGB888_Rev);

// 0x907768 | ?ColorModelRGBA4444@@3VagiColorModelRGBA4444@@A
inline extern_var(0x507768_Offset, class agiColorModelRGBA4444, ColorModelRGBA4444);

// 0x907738 | ?ColorModelRGBA5551@@3VagiColorModelRGBA5551@@A
inline extern_var(0x507738_Offset, class agiColorModelRGBA5551, ColorModelRGBA5551);
