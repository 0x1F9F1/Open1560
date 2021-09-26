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

#include "agi/bitmap.h"
#include "agi/texdef.h"

class agiTexDef;

class agiGLBitmap final : public agiBitmap
{
public:
    agiGLBitmap(agiPipeline* pipe)
        : agiBitmap(pipe)
    {
        // is_3D_ = true;
    }

    void EndGfx() override;
    i32 BeginGfx() override;
    void UpdateFlags() override;

    agiTexDef* GetHandle() const
    {
        return tex_def_.get();
    }

private:
    Rc<agiTexDef> tex_def_;
};
