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

#include "agisdl/sdlpipe.h"
#include "data7/hash.h"

class agiGLContext;
class agiGLRasterizer;

class agiGLPipeline final : public agiSDLPipeline
{
public:
    agiGLPipeline();
    ~agiGLPipeline();

    i32 BeginGfx() override;
    void EndGfx() override;

    void BeginFrame() override;
    void BeginScene() override;
    void EndScene() override;
    void EndFrame() override;

    RcOwner<agiTexDef> CreateTexDef() override;
    RcOwner<agiTexLut> CreateTexLut() override;
    RcOwner<DLP> CreateDLP() override;
    RcOwner<agiLight> CreateLight() override;
    RcOwner<agiLightModel> CreateLightModel() override;
    RcOwner<agiViewport> CreateViewport() override;
    RcOwner<agiBitmap> CreateBitmap() override;

    void CopyBitmap(i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height) override;

    void ClearAll(i32 arg1) override;
    void ClearRect(i32 x, i32 y, i32 width, i32 height, u32 color) override;

    void Init();

    u32 GetRenderX() const
    {
        return render_x_;
    }

    u32 GetRenderY() const
    {
        return render_y_;
    }

    u32 GetRenderWidth() const
    {
        return render_width_;
    }

    u32 GetRenderHeight() const
    {
        return render_height_;
    }

    i32 GetAnisotropyLevel() const
    {
        return afilter_level_;
    }

    agiGLRasterizer* Rast()
    {
        return rasterizer_.get();
    }

private:
    Ptr<agiSurfaceDesc> CaptureScreen();

    Ptr<agiGLContext> gl_context_;
    Rc<agiGLRasterizer> rasterizer_;

    u32 fbo_ {};
    u32 rbo_[2] {};

    i32 render_x_ {};
    i32 render_y_ {};
    i32 render_width_ {};
    i32 render_height_ {};

    u32 blit_filter_ {};
    i32 afilter_level_ {};
};

Owner<agiPipeline> glCreatePipeline(i32 argc, char** argv);
