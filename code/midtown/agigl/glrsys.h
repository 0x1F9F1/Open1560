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

class agiGLRasterizer final : public agiRasterizer
{
public:
    agiGLRasterizer(class agiPipeline* pipe)
        : agiRasterizer(pipe)
    {}

    void EndGfx() override;
    i32 BeginGfx() override;

    void BeginGroup() override;
    void EndGroup() override;

    void Verts(agiVtxType type, agiVtx* vertices, i32 vertex_count) override;
    void Points(agiVtxType type, agiVtx* vertices, i32 vertex_count) override;
    void SetVertCount(i32 vertex_count) override;
    void Triangle(i32 i0, i32 i1, i32 i2) override;
    void Line(i32 i0, i32 i1) override;
    void Card(i32 i0, i32 i1) override;
    void Mesh(agiVtxType type, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count) override;

    void FlushState();

private:
    void SetVertices(agiVtx* vertices, i32 vertex_count);
    void Draw(u16* indices, i32 index_count);

    u32 vbo_ {0};
    u32 ibo_ {0};
    u32 vao_ {0};
    u32 shader_ {0};
    u32 white_texture_ {0};

    u32 uniform_alpha_ref_ {0};

    u32 uniform_fog_color_ {0};
    u32 uniform_fog_enable_ {0};
};