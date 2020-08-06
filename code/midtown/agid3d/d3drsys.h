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
    agid3d:d3drsys

    0x52E550 | public: __thiscall agiD3DRasterizer::agiD3DRasterizer(class agiPipeline *) | ??0agiD3DRasterizer@@QAE@PAVagiPipeline@@@Z
    0x52E570 | public: virtual int __thiscall agiD3DRasterizer::BeginGfx(void) | ?BeginGfx@agiD3DRasterizer@@UAEHXZ
    0x52E580 | public: virtual void __thiscall agiD3DRasterizer::EndGfx(void) | ?EndGfx@agiD3DRasterizer@@UAEXXZ
    0x52E590 | public: virtual __thiscall agiD3DRasterizer::~agiD3DRasterizer(void) | ??1agiD3DRasterizer@@UAE@XZ
    0x52E5A0 | public: virtual void __thiscall agiD3DRasterizer::BeginGroup(void) | ?BeginGroup@agiD3DRasterizer@@UAEXXZ
    0x52E5B0 | public: virtual void __thiscall agiD3DRasterizer::EndGroup(void) | ?EndGroup@agiD3DRasterizer@@UAEXXZ
    0x52E5C0 | void __cdecl d3d_state_init(void) | ?d3d_state_init@@YAXXZ
    0x52E630 | protected: void __thiscall agiD3DRasterizer::FlushState(void) | ?FlushState@agiD3DRasterizer@@IAEXXZ
    0x52F770 | public: virtual void __thiscall agiD3DRasterizer::Verts(enum agiVtxType,union agiVtx *,int) | ?Verts@agiD3DRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    0x52F7C0 | public: virtual void __thiscall agiD3DRasterizer::SetVertCount(int) | ?SetVertCount@agiD3DRasterizer@@UAEXH@Z
    0x52F7D0 | public: virtual void __thiscall agiD3DRasterizer::Triangle(int,int,int) | ?Triangle@agiD3DRasterizer@@UAEXHHH@Z
    0x52F860 | public: virtual void __thiscall agiD3DRasterizer::Line(int,int) | ?Line@agiD3DRasterizer@@UAEXHH@Z
    0x52F8E0 | public: virtual void __thiscall agiD3DRasterizer::Card(int,int) | ?Card@agiD3DRasterizer@@UAEXHH@Z
    0x52F8F0 | public: virtual void __thiscall agiD3DRasterizer::Points(enum agiVtxType,union agiVtx *,int) | ?Points@agiD3DRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    0x52F950 | public: virtual void __thiscall agiD3DRasterizer::Mesh(enum agiVtxType,union agiVtx *,int,unsigned short *,int) | ?Mesh@agiD3DRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@HPAGH@Z
    0x52F9C0 | public: virtual void __thiscall agiD3DRasterizer::Mesh2(struct agiScreenVtx2 *,int,unsigned short *,int) | ?Mesh2@agiD3DRasterizer@@UAEXPAUagiScreenVtx2@@HPAGH@Z
    0x52FA60 | public: virtual void * __thiscall agiD3DRasterizer::`scalar deleting destructor'(unsigned int) | ??_GagiD3DRasterizer@@UAEPAXI@Z
    0x52FA60 | public: virtual void * __thiscall agiD3DRasterizer::`vector deleting destructor'(unsigned int) | ??_EagiD3DRasterizer@@UAEPAXI@Z
    0x620F10 | const agiD3DRasterizer::`vftable' | ??_7agiD3DRasterizer@@6B@
    0x790DF0 | int NoOutput | ?NoOutput@@3HA
    0x794DFC | struct IDirect3DDevice3 * d3ddev | ?d3ddev@@3PAUIDirect3DDevice3@@A
    0x794E10 | void * VtxBase | ?VtxBase@@3PAXA
    0x794F18 | int OneTexture | ?OneTexture@@3HA
    0x794F1C | int OrthoFix | ?OrthoFix@@3HA
*/

#include "agi/rsys.h"

#include "d3drpipe.h"

class agiD3DRasterizer final : public agiRasterizer
{
    // const agiD3DRasterizer::`vftable' @ 0x620F10

public:
    // 0x52E550 | ??0agiD3DRasterizer@@QAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiD3DRasterizer(class agiPipeline* pipe)
        : agiRasterizer(pipe)
    {}

    // 0x52FA60 | ??_EagiD3DRasterizer@@UAEPAXI@Z
    // 0x52FA60 | ??_GagiD3DRasterizer@@UAEPAXI@Z
    // 0x52E590 | ??1agiD3DRasterizer@@UAE@XZ
    ARTS_EXPORT ~agiD3DRasterizer() override = default;

    // 0x52E570 | ?BeginGfx@agiD3DRasterizer@@UAEHXZ
    ARTS_EXPORT i32 BeginGfx() override;

    // 0x52E5A0 | ?BeginGroup@agiD3DRasterizer@@UAEXXZ
    ARTS_EXPORT void BeginGroup() override;

    // 0x52F8E0 | ?Card@agiD3DRasterizer@@UAEXHH@Z
    ARTS_EXPORT void Card(i32 arg1, i32 arg2) override;

    // 0x52E580 | ?EndGfx@agiD3DRasterizer@@UAEXXZ
    ARTS_EXPORT void EndGfx() override;

    // 0x52E5B0 | ?EndGroup@agiD3DRasterizer@@UAEXXZ
    ARTS_EXPORT void EndGroup() override;

    // 0x52F860 | ?Line@agiD3DRasterizer@@UAEXHH@Z
    ARTS_EXPORT void Line(i32 i1, i32 i2) override;

    // 0x52F950 | ?Mesh@agiD3DRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@HPAGH@Z
    ARTS_EXPORT void Mesh(
        enum agiVtxType type, union agiVtx* verts, i32 vert_count, u16* indices, i32 index_count) override;

    // 0x52F9C0 | ?Mesh2@agiD3DRasterizer@@UAEXPAUagiScreenVtx2@@HPAGH@Z
    ARTS_EXPORT void Mesh2(struct agiScreenVtx2* verts, i32 vert_count, u16* indices, i32 index_count) override;

    // 0x52F8F0 | ?Points@agiD3DRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    ARTS_EXPORT void Points(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3) override;

    // 0x52F7C0 | ?SetVertCount@agiD3DRasterizer@@UAEXH@Z
    ARTS_EXPORT void SetVertCount(i32 vert_count) override;

    // 0x52F7D0 | ?Triangle@agiD3DRasterizer@@UAEXHHH@Z
    ARTS_EXPORT void Triangle(i32 i1, i32 i2, i32 i3) override;

    // 0x52F770 | ?Verts@agiD3DRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    ARTS_EXPORT void Verts(enum agiVtxType type, union agiVtx* verts, i32 vert_count) override;

    agiD3DPipeline* Pipe() const
    {
        return static_cast<agiD3DPipeline*>(agiRefreshable::Pipe());
    }

protected:
    // 0x52E630 | ?FlushState@agiD3DRasterizer@@IAEXXZ
    ARTS_EXPORT void FlushState();
};

check_size(agiD3DRasterizer, 0x18);

// 0x52E5C0 | ?d3d_state_init@@YAXXZ
ARTS_EXPORT void d3d_state_init();

// 0x790DF0 | ?NoOutput@@3HA
ARTS_IMPORT extern i32 NoOutput;

// 0x794F18 | ?OneTexture@@3HA
ARTS_IMPORT extern i32 OneTexture;

// 0x794F1C | ?OrthoFix@@3HA
ARTS_IMPORT extern i32 OrthoFix;

// 0x794E10 | ?VtxBase@@3PAXA
ARTS_IMPORT extern void* VtxBase;

// 0x794DFC | ?d3ddev@@3PAUIDirect3DDevice3@@A
ARTS_IMPORT extern struct IDirect3DDevice3* d3ddev;
