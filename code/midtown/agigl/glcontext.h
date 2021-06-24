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

class agiGLRasterizer;

class agiGLContext final
{
public:
    agiGLContext(void* window_dc, void* gl_context, i32 debug_level);
    ~agiGLContext();

    ARTS_NON_COPYABLE(agiGLContext);

    void MakeCurrent();
    void* GetProc(const char* name);

    void Init();
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
    void InitExtensions();

    void* gl_module_ {nullptr};
    void* window_dc_ {nullptr};
    void* gl_context_ {nullptr};

    HashTable extensions_ {128, "Extensions"};

    i32 gl_version_ {0};
    i32 context_flags_ {0};
    i32 profile_mask_ {0};

    i32 shader_version_ {0};
    i32 debug_level_ {0};
    i32 error_count_ {0};

    bool direct_state_access_ {false};
    i32 max_anisotropy_ {0};

    u32 active_texture_unit_ {0};
    bool capabilities_[6] {};
    bool depth_mask_ {};
    u32 polygon_mode_ {0};
    u32 depth_func_ {0};
    u32 front_face_ {0};
    u32 blend_func_s_ {0};
    u32 blend_func_d_ {0};
};

inline thread_local agiGLContext* agiGL {nullptr};
