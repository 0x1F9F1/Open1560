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

class agiSWRasterizer final : public agiRasterizer
{
public:
    // ??0agiSWRasterizer@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiSWRasterizer(agiPipeline* arg1);

    // ??1agiSWRasterizer@@UAE@XZ
    ARTS_EXPORT ~agiSWRasterizer() override = default;

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
    ARTS_EXPORT void Mesh(agiVtxType type, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count) override;

    // ?Points@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    ARTS_EXPORT void Points(agiVtxType arg1, agiVtx* arg2, i32 arg3) override;

    // ?Quad@agiSWRasterizer@@UAEXHHHH@Z
    ARTS_IMPORT void Quad(i32 arg1, i32 arg2, i32 arg3, i32 arg4) override;

    // ?SetVertCount@agiSWRasterizer@@UAEXH@Z
    ARTS_EXPORT void SetVertCount(i32 arg1) override;

    // ?Triangle@agiSWRasterizer@@UAEXHHH@Z
    ARTS_IMPORT void Triangle(i32 arg1, i32 arg2, i32 arg3) override;

    // ?Verts@agiSWRasterizer@@UAEXW4agiVtxType@@PATagiVtx@@H@Z
    ARTS_IMPORT void Verts(agiVtxType arg1, agiVtx* arg2, i32 arg3) override;
};

check_size(agiSWRasterizer, 0x18);
