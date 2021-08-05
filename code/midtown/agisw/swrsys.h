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

#include "agi/rsys.h"

class agiSWRasterizer final : public agiRasterizer
{
    // const agiSWRasterizer::`vftable'

public:
    // ??0agiSWRasterizer@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiSWRasterizer(class agiPipeline* arg1);

    // ??_GagiSWRasterizer@@UAEPAXI@Z
    // ??_EagiSWRasterizer@@UAEPAXI@Z
    // ??1agiSWRasterizer@@UAE@XZ
    ARTS_IMPORT ~agiSWRasterizer() override = default;

    // ?BeginGfx@agiSWRasterizer@@UAEHXZ
    ARTS_EXPORT i32 BeginGfx() override;

    // ?BeginGroup@agiSWRasterizer@@UAEXXZ
    ARTS_EXPORT void BeginGroup() override;

    // ?Card@agiSWRasterizer@@UAEXHH@Z
    ARTS_IMPORT void Card(i32 arg1, i32 arg2) override;

    // ?EndGfx@agiSWRasterizer@@UAEXXZ
    ARTS_EXPORT void EndGfx() override;

    // ?EndGroup@agiSWRasterizer@@UAEXXZ
    ARTS_EXPORT void EndGroup() override;

    // ?Line@agiSWRasterizer@@UAEXHH@Z
    ARTS_EXPORT void Line(i32 i1, i32 i2) override;

    // ?Mesh@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@HPAGH@Z
    ARTS_EXPORT void Mesh(
        enum agiVtxType type, union agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count) override;

    // ?Points@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    ARTS_EXPORT void Points(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3) override;

    // ?Quad@agiSWRasterizer@@UAEXHHHH@Z
    ARTS_IMPORT void Quad(i32 arg1, i32 arg2, i32 arg3, i32 arg4) override;

    // ?SetVertCount@agiSWRasterizer@@UAEXH@Z
    ARTS_EXPORT void SetVertCount(i32 arg1) override;

    // ?Triangle@agiSWRasterizer@@UAEXHHH@Z
    ARTS_IMPORT void Triangle(i32 arg1, i32 arg2, i32 arg3) override;

    // ?Verts@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    ARTS_IMPORT void Verts(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3) override;
};

check_size(agiSWRasterizer, 0x18);
