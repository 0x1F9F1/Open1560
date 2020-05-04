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

#include "agi/rsys.h"

/*
    agisw:swrsys

    0x537BB0 | public: __thiscall agiSWRasterizer::agiSWRasterizer(class agiPipeline *) | ??0agiSWRasterizer@@QAE@PAVagiPipeline@@@Z
    0x537BD0 | public: virtual __thiscall agiSWRasterizer::~agiSWRasterizer(void) | ??1agiSWRasterizer@@UAE@XZ
    0x537BE0 | public: virtual int __thiscall agiSWRasterizer::BeginGfx(void) | ?BeginGfx@agiSWRasterizer@@UAEHXZ
    0x537BF0 | public: virtual void __thiscall agiSWRasterizer::EndGfx(void) | ?EndGfx@agiSWRasterizer@@UAEXXZ
    0x537C00 | public: virtual void __thiscall agiSWRasterizer::BeginGroup(void) | ?BeginGroup@agiSWRasterizer@@UAEXXZ
    0x537C10 | public: virtual void __thiscall agiSWRasterizer::EndGroup(void) | ?EndGroup@agiSWRasterizer@@UAEXXZ
    0x537C20 | public: virtual void __thiscall agiSWRasterizer::Verts(enum agiVtxType,union agiVtx *,int) | ?Verts@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    0x537C30 | public: virtual void __thiscall agiSWRasterizer::SetVertCount(int) | ?SetVertCount@agiSWRasterizer@@UAEXH@Z
    0x537C40 | public: virtual void __thiscall agiSWRasterizer::Triangle(int,int,int) | ?Triangle@agiSWRasterizer@@UAEXHHH@Z
    0x537C70 | public: virtual void __thiscall agiSWRasterizer::Quad(int,int,int,int) | ?Quad@agiSWRasterizer@@UAEXHHHH@Z
    0x537CB0 | public: virtual void __thiscall agiSWRasterizer::Line(int,int) | ?Line@agiSWRasterizer@@UAEXHH@Z
    0x537CF0 | public: virtual void __thiscall agiSWRasterizer::Card(int,int) | ?Card@agiSWRasterizer@@UAEXHH@Z
    0x537D00 | public: virtual void __thiscall agiSWRasterizer::Points(enum agiVtxType,union agiVtx *,int) | ?Points@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    0x537D10 | public: virtual void __thiscall agiSWRasterizer::Mesh(enum agiVtxType,union agiVtx *,int,unsigned short *,int) | ?Mesh@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@HPAGH@Z
    0x537DC0 | public: virtual void * __thiscall agiSWRasterizer::`vector deleting destructor'(unsigned int) | ??_EagiSWRasterizer@@UAEPAXI@Z
    0x537DC0 | public: virtual void * __thiscall agiSWRasterizer::`scalar deleting destructor'(unsigned int) | ??_GagiSWRasterizer@@UAEPAXI@Z
    0x621338 | const agiSWRasterizer::`vftable' | ??_7agiSWRasterizer@@6B@
*/

class agiSWRasterizer : public agiRasterizer
{
    // const agiSWRasterizer::`vftable' @ 0x621338

public:
    // 0x537BB0 | ??0agiSWRasterizer@@QAE@PAVagiPipeline@@@Z
    agiSWRasterizer(class agiPipeline* arg1);

    // 0x537DC0 | ??_GagiSWRasterizer@@UAEPAXI@Z
    // 0x537BD0 | ??1agiSWRasterizer@@UAE@XZ
    ~agiSWRasterizer() override;

    // 0x537BE0 | ?BeginGfx@agiSWRasterizer@@UAEHXZ
    i32 BeginGfx() override;

    // 0x537C00 | ?BeginGroup@agiSWRasterizer@@UAEXXZ
    void BeginGroup() override;

    // 0x537CF0 | ?Card@agiSWRasterizer@@UAEXHH@Z
    void Card(i32 arg1, i32 arg2) override;

    // 0x537BF0 | ?EndGfx@agiSWRasterizer@@UAEXXZ
    void EndGfx() override;

    // 0x537C10 | ?EndGroup@agiSWRasterizer@@UAEXXZ
    void EndGroup() override;

    // 0x537CB0 | ?Line@agiSWRasterizer@@UAEXHH@Z
    void Line(i32 arg1, i32 arg2) override;

    // 0x537D10 | ?Mesh@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@HPAGH@Z
    void Mesh(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3, u16* arg4, i32 arg5) override;

    // 0x537D00 | ?Points@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    void Points(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3) override;

    // 0x537C70 | ?Quad@agiSWRasterizer@@UAEXHHHH@Z
    void Quad(i32 arg1, i32 arg2, i32 arg3, i32 arg4) override;

    // 0x537C30 | ?SetVertCount@agiSWRasterizer@@UAEXH@Z
    void SetVertCount(i32 arg1) override;

    // 0x537C40 | ?Triangle@agiSWRasterizer@@UAEXHHH@Z
    void Triangle(i32 arg1, i32 arg2, i32 arg3) override;

    // 0x537C20 | ?Verts@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    void Verts(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3) override;
};

check_size(agiSWRasterizer, 0x18);
