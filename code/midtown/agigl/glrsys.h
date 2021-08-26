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
#include "glpipe.h"
#include "vector7/vector2.h"
#include "vector7/vector3.h"
#include "vector7/vector4.h"

class agiGLStreamBuffer;

class agiGLRasterizer final : public agiRasterizer
{
public:
    agiGLRasterizer(agiPipeline* pipe);
    ~agiGLRasterizer();

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

    agiGLPipeline* Pipe() const
    {
        return static_cast<agiGLPipeline*>(agiRefreshable::Pipe());
    }

private:
    void InitModern();

    void FlushState();

    u16* ImmAddIndices(u32 draw_mode, u16 count);
    void ImmDraw();

    void DrawMesh(u32 draw_mode, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count);

    u32 current_texture_ {};

    bool flip_winding_ {};
    bool reversed_z_ {};

    Ptr<agiGLStreamBuffer> vbo_;

    u32 vao_ {};
    u32 shader_ {};

    i32 uniform_alpha_ref_ {-1};
    f32 alpha_ref_ {};

    i32 uniform_tex_env_ {-1};
    agiTexEnv tex_env_ {};

    i32 uniform_fog_mode_ {-1};
    Vector4 fog_mode_ {};

    i32 uniform_fog_color_ {-1};
    Vector3 fog_color_ {};

    bool draw_base_vertex_ {};
    const void* last_vtx_offset_ {};
};
