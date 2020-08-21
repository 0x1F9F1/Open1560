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

#include "agi/pipeline.h"
#include "agi/rsys.h"

#include "core/minwin.h"

// #define ARTS_GL_MSAA 8

class agiGLPipeline final : public agiPipeline
{
public:
    i32 BeginGfx() override;
    void EndGfx() override;

    void BeginFrame() override;
    void BeginScene() override;
    void EndScene() override;
    void EndFrame() override;

    RcOwner<class agiTexDef> CreateTexDef() override;
    RcOwner<class agiTexLut> CreateTexLut() override;
    RcOwner<class DLP> CreateDLP() override;
    RcOwner<class agiLight> CreateLight() override;
    RcOwner<class agiLightModel> CreateLightModel() override;
    RcOwner<class agiViewport> CreateViewport() override;
    RcOwner<class agiBitmap> CreateBitmap() override;

    void CopyBitmap(i32 dst_x, i32 dst_y, class agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height) override;

    void ClearAll(i32 arg1) override;
    void ClearRect(i32 x, i32 y, i32 width, i32 height, u32 color) override;

    void Init();

private:
    HDC window_dc_ {nullptr};
    HGLRC gl_context_ {nullptr};
    Rc<agiRasterizer> rasterizer_ {};

#ifdef ARTS_GL_MSAA
    u32 fbo_ {0};
    u32 rbo_ {0};
    u32 msaa_tex_ {0};
#endif
};
