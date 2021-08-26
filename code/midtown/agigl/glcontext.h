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

#include "data7/hash.h"

#include <SDL_video.h>

class agiGLRasterizer;

class agiGLContext final
{
public:
    agiGLContext(SDL_Window* window, SDL_GLContext gl_context, i32 debug_level);
    ~agiGLContext();

    ARTS_NON_COPYABLE(agiGLContext);

    void MakeCurrent();
    static void* GetProc(const char* name);

    void CheckErrors(bool lazy = false);

    void ActiveTexture(u32 unit);
    void BindTextureUnit(u32 target, u32 texture, u32 unit);

    void EnableDisable(u32 cap, bool enable);
    void DepthMask(bool enable);
    void PolygonMode(u32 mode);
    void DepthFunc(u32 func);
    void FrontFace(u32 face);
    void BlendFunc(u32 sfactor, u32 dfactor);

    bool HasExtension(const char* name)
    {
        return extensions_.Access(name) != nullptr;
    }

    bool HasExtension(i32 version, const char* name)
    {
        return (gl_version_ >= version) || (extensions_.Access(name) != nullptr);
    }

    i32 GetVersion() const
    {
        return gl_version_;
    }

    bool HasVersion(i32 version) const
    {
        return gl_version_ >= version;
    }

    bool IsCoreProfile() const
    {
        return profile_mask_ & 0x00000001; // GL_CONTEXT_CORE_PROFILE_BIT
    }

    i32 GetShaderVersion() const
    {
        return shader_version_;
    }

    i32 GetMaxAnisotropy() const
    {
        return max_anisotropy_;
    }

private:
    void InitVersioning();
    void InitState();

    SDL_Window* window_ {};
    SDL_GLContext gl_context_ {};

    HashTable extensions_ {128, "Extensions"};

    i32 gl_version_ {};
    i32 context_flags_ {};
    i32 profile_mask_ {};

    i32 shader_version_ {};
    i32 debug_level_ {};
    i32 error_count_ {};

    bool direct_state_access_ {};
    i32 max_anisotropy_ {};

    u32 active_texture_unit_ {};
    bool capabilities_[7] {};
    bool depth_mask_ {};
    u32 polygon_mode_ {};
    u32 depth_func_ {};
    u32 front_face_ {};
    u32 blend_func_s_ {};
    u32 blend_func_d_ {};
};

inline thread_local agiGLContext* agiGL {};
