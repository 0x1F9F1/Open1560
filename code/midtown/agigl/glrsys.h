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
#include "vector7/vector4.h"

class agiGLStreamBuffer;

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

    agiGLPipeline* Pipe() const
    {
        return static_cast<agiGLPipeline*>(agiRefreshable::Pipe());
    }

private:
    void FlushState();
    void FlushAgiState();
    void FlushGlState();

    u16* ImmAddIndices(u32 draw_mode, u16 count);
    void ImmDraw();

    void DrawMesh(u32 draw_mode, agiVtx* vertices, i32 vertex_count, u16* indices, i32 index_count);

    agiGLStreamBuffer* vbo_ {nullptr};
    agiGLStreamBuffer* ibo_ {nullptr};

    u32 vao_ {0};
    u32 shader_ {0};
    u32 white_texture_ {0};

    u32 uniform_alpha_ref_ {0};
    u32 uniform_fog_ {0};

    struct State
    {
        enum Touched_ : u32
        {
            // Touched_Texture = 1 << 0,

            Touched_DepthMask = 1 << 1,
            Touched_DepthTest = 1 << 2,
            Touched_DepthFunc = 1 << 3,

            Touched_PolygonMode = 1 << 4,

            Touched_Blend = 1 << 5,
            Touched_AlphaRef = 1 << 6,

            Touched_BlendFunc = 1 << 7,

            Touched_CullFace = 1 << 8,
            Touched_FrontFace = 1 << 9,

            Touched_Fog = 1 << 10,
        };

        u32 Touched {0};

        u32 Texture {0};
        u32 MinFilter {0};
        u32 MagFilter {0};

        bool DepthMask {false};
        bool DepthTest {false};
        u32 DepthFunc {0};

        u32 PolygonMode {0};

        bool Blend {false};
        f32 AlphaRef {0.0f};

        u32 BlendFuncS {0};
        u32 BlendFuncD {0};

        bool CullFace {false};
        u32 FrontFace {0};

        Vector4 Fog {};

        template <typename T>
        inline void Set(T& state, T value, u32 touched)
        {
            Touched |= (state != value) ? touched : 0;
            state = value;
        }
    };

    State state_ {};
};
