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

define_dummy_symbol(agisw_swtexdef);

#include "swtexdef.h"

#include "agi/error.h"

i32 agiSWTexDef::BeginGfx()
{
    if (Surface == nullptr)
    {
        Errorf("Missing SurfaceDesc for '%s' in BeginGfx - trouble is brewing!", Tex.Name);
        return AGI_ERROR_FILE_NOT_FOUND;
    }

    if (Tex.Name[0] != '*' && page_state_ == 0 && cache_handle_ == 0)
    {
        Surface->Reload(Tex.Name, TexSearchPath, Tex.LOD, PackShift, 0, 0, 0); // TODO: Should this be PackShift & 0xF ?

        // FIXME: Surfaces with a PackShift don't have their pitch updated. This should really be corrected in agiSurfaceDesc::[Load/Reload]
        Surface->Pitch = Surface->Width * Surface->GetPixelSize();
    }

    height_mips_ = 0;
    width_mips_ = 0;

    for (u32 i = Surface->Width; i >>= 1; ++width_mips_) {}
    for (u32 i = Surface->Height; i >>= 1; ++height_mips_) {}

    void* surface = Surface->Surface;
    u32 size = 1 << (width_mips_ + height_mips_);

    for (u32 i = 0; i + 2 < Surface->MipMapCount; ++i)
    {
        surfaces_[i] = MakeUniqueUninit<u8[]>(size);
        std::memcpy(surfaces_[i].get(), surface, size);
        surface = static_cast<u8*>(surface) + size;
        size >>= 2;
    }

    state_ = 1;

    return AGI_ERROR_SUCCESS;
}

void agiSWTexDef::EndGfx()
{
    for (i32 i = 0; i < 7; ++i)
        surfaces_[i] = nullptr;

    state_ = 0;
}

void agiSWTexDef::Unlock(struct agiTexLock& /*arg1*/)
{}

void agiSWTexLut::EndGfx()
{}