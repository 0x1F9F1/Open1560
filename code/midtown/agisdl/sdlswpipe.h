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

#include "sdlpipe.h"

#include <SDL_render.h>

class agiSDLSWPipeline final : public agiSDLPipeline
{
public:
    agiSDLSWPipeline();
    ~agiSDLSWPipeline() override;

    void Init();

    void BeginFrame() override;
    i32 BeginGfx() override;
    void BeginScene() override;

    void ClearAll(i32 color) override;
    void ClearRect(i32 x, i32 y, i32 width, i32 height, u32 color) override;
    void CopyBitmap(i32 dst_x, i32 dst_y, class agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height) override;

    RcOwner<class agiBitmap> CreateBitmap() override;
    RcOwner<class DLP> CreateDLP() override;
    RcOwner<class agiLight> CreateLight() override;
    RcOwner<class agiLightModel> CreateLightModel() override;
    RcOwner<class agiMtlDef> CreateMtlDef() override;
    RcOwner<class agiTexDef> CreateTexDef() override;
    RcOwner<class agiTexLut> CreateTexLut() override;
    RcOwner<class agiViewport> CreateViewport() override;

    void EndFrame() override;
    void EndGfx() override;
    void EndScene() override;
    i32 Validate() override;

    SDL_Surface* GetSurface()
    {
        return render_surface_;
    }

private:
    SDL_Renderer* sdl_renderer_ {nullptr};
    SDL_Texture* render_texture_ {nullptr};
    SDL_Surface* render_surface_ {nullptr};
};

Ptr<u8[]> sdlScreenShot(i32& width, i32& height);

Owner<class agiPipeline> sdlCreatePipeline(i32 argc, char** argv);
