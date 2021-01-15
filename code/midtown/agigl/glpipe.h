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
#include "data7/hash.h"

#include "core/minwin.h"

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

    u32 AllocTexture();
    void DeleteTexture(u32 texture);

    bool HasExtension(const char* name);
    bool HasVersion(i32 major, i32 minor);

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

private:
    HDC window_dc_ {nullptr};
    HGLRC gl_context_ {nullptr};

    HashTable extensions_ {128, "Extensions"};

    Rc<agiRasterizer> rasterizer_ {};

    i32 gl_major_version_ {0};
    i32 gl_minor_version_ {0};

    u32 fbo_ {0};
    u32 rbo_ {0};
    u32 color_fbo_ {0};

    u32 render_x_ {0};
    u32 render_y_ {0};
    u32 render_width_ {0};
    u32 render_height_ {0};

    u32 blit_x_ {0};
    u32 blit_y_ {0};
    u32 blit_width_ {0};
    u32 blit_height_ {0};

    u32 texture_cache_[64];
    u32 cached_textures_ {0};

    void InitExtensions();
};

Ptr<u8[]> glScreenShot(i32& width, i32& height);
