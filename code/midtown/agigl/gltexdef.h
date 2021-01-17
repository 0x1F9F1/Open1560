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

#include "agi/texdef.h"

#include "glpipe.h"

class agiGLTexDef final : public agiTexDef
{
public:
    agiGLTexDef(class agiPipeline* pipe)
        : agiTexDef(pipe)
    {}

    i32 BeginGfx() override;
    void EndGfx() override;
    void Set(Vector2& arg1, Vector2& arg2) override;

    b32 Lock(struct agiTexLock& lock) override;
    void Unlock(struct agiTexLock& lock) override;

    b32 IsAvailable() override;
    void Request() override;

    u32 GetHandle();

    agiGLPipeline* Pipe() const
    {
        return static_cast<agiGLPipeline*>(agiRefreshable::Pipe());
    }

private:
    bool CheckFence();

    u32 texture_ {0};
    void* fence_ {0};

    Ptr<agiSurfaceDesc> temp_surface_ {};
};
