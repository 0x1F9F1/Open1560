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

define_dummy_symbol(agi_texdef);

#include "texdef.h"

#include "data7/cache.h"
#include "data7/ipc.h"
#include "error.h"
#include "pipeline.h"
#include "rsys.h"
#include "stream/fsystem.h"
#include "stream/stream.h"
#include "texlib.h"

ARTS_EXPORT DataCache TEXCACHE;

struct lutQentry
{
    agiTexLut** Lut;
    char Name[4];
};

static i32 lutQhead = 0;
static i32 lutQtail = 0;

void agiTexParameters::Load(Stream* file)
{
    file->Read(Name, sizeof(Name));
    file->Get(&Flags, 1);
    file->Get(&LOD, 1);
    file->Get(&MaxLOD, 1);

    u8 align = 0;
    file->Get(&align, 1);
}

void agiTexParameters::Save(Stream* file)
{
    file->Write(Name, sizeof(Name));
    file->Put(Flags);
    file->Put(LOD);
    file->Put(MaxLOD);
    file->Put(0_u8);
}

b32 agiTexDef::IsAvailable()
{
    return page_state_ == 2;
}

b32 agiTexDef::Lock(agiTexLock& /*arg1*/)
{
    return false;
}

void agiTexDef::Unlock(agiTexLock& /*arg1*/)
{}

void agiTexDef::Request()
{}

void agiTexDef::CheckSurface()
{
    if (Surface->Flags & AGISD_CKSRCBLT)
        Tex.Flags |= agiTexParameters::Chromakey;
    else
        Tex.Flags &= ~agiTexParameters::Chromakey;
}

// Same as DataCache alignment
static inline constexpr u32 AlignSize(u32 value) noexcept
{
    return (value + 7) & ~u32(7); // FIXME: 64-bit requires 16-byte alignment
}

void agiTexDef::DoPageIn()
{
    // NOTE: 64-bit incompatible
    static_assert(sizeof(*Surface) == 0x7C);
    pager_.Read(Surface.get(), 0x4, sizeof(*Surface));

    // FIXME: Some RV3 textures (SKY_*) have incorrect pitch.
    Surface->FixPitch();

    // Ensure the surface pointer is null in case it can't be paged in
    Surface->Surface = 0;

    i32 mip_pack = PackShift & 0xF;

    Surface->MipMapCount -= mip_pack;
    Surface->Width >>= mip_pack;
    Surface->Height >>= mip_pack;
    Surface->Pitch >>= mip_pack;

    if (agiCurState.GetSoftwareRendering())
    {
        i32 index = (lutQtail + 1) % ARTS_SIZE(lutQ);

        if (index == lutQhead)
        {
            page_state_ = 0;

            return;
        }

        lutQ[index].Lut = &Surface->lpLut;
        std::memcpy(lutQ[index].Name, Surface->szLut, 4);
        Surface->lpLut = nullptr;
        lutQtail = index;
    }

    u32 surface_offset = 0x80;
    u32 surface_size = pager_.Size - 0x80;

    // Go through the mip levels in reverse, adding the correct offset (sd->Width and sd->Height are already scaled by down MipReduction).
    for (u32 current_surface_size = Surface->Height * Surface->Pitch; mip_pack; --mip_pack)
    {
        current_surface_size *= 4;
        surface_offset += current_surface_size;
        surface_size -= current_surface_size;
    }

    if (!TEXCACHE.BeginObject(&cache_handle_, PageOutCallback, this, AlignSize(surface_size)))
    {
        page_state_ = 0;

        return;
    }

    Surface->Surface = TEXCACHE.Allocate(cache_handle_, surface_size);
    pager_.Read(Surface->Surface, surface_offset, surface_size);

    TexBytesPaged += surface_size;
    ++TexsPaged;

    page_state_ = 2;

    TEXCACHE.EndObject(cache_handle_);
}

aconst char* agiTexDef::GetName()
{
    static char buffer[64]; // FIXME: Static buffer
    arts_sprintf(buffer, "Texture '%s' %d/%d", Tex.Name, Tex.LOD, Tex.MaxLOD);
    return buffer;
}

i32 agiTexDef::Init(const agiTexParameters& params)
{
    if (DevelopmentMode || !(EnablePaging & ARTS_PAGE_TEXTURES) || (params.Flags & agiTexParameters::KeepLoaded))
    {
        EndGfx();
        Tex = params;
        Reload();

        return SafeBeginGfx();
    }
    else
    {
        Tex = params;

        return 0;
    }
}

i32 agiTexDef::Init(const agiTexParameters& params, Ptr<agiSurfaceDesc> surface)
{
    EndGfx();

    Tex = params;
    Tex.Flags |= agiTexParameters::KeepLoaded;

    Surface = std::move(surface);

    CheckSurface();

    return BeginGfx();
}

b32 agiTexDef::IsTexture()
{
    return true;
}

b32 agiTexDef::LockSurfaceIfResident()
{
    return (page_state_ > 1) && (cache_handle_ == 0 || TEXCACHE.Lock(&cache_handle_));
}

void agiTexDef::PageInSurface()
{
    if (pager_.Handle == 0)
    {
        const char* path = TexSearchPath;

        do
        {
            char buffer[64];

            if (Tex.LOD)
                arts_sprintf(buffer, "%s/%s.%04d.dds", path, Tex.Name, Tex.LOD);
            else
                arts_sprintf(buffer, "%s/%s.dds", path, Tex.Name);

            if (FileSystem::PagerInfoAny(buffer, pager_))
                break;

            path += std::strlen(path) + 1;
        } while (*path);

        if (pager_.Handle)
            Surface = arnew agiSurfaceDesc();
    }

    if (page_state_ == 0 && pager_.Handle != 0)
    {
        ++page_state_;

        PAGER.Send([this] { DoPageIn(); });
    }
}

#ifdef ARTS_DEBUG
static Ptr<agiSurfaceDesc> CreateMissingTexture()
{
    // FIXME: Support pallete textures
    if (!Pipe()->IsHardware())
        return nullptr;

    Ptr<agiSurfaceDesc> surface = as_ptr agiSurfaceDesc::Init(16, 16, Pipe()->GetAlphaFormat());
    Rc<agiColorModel> cmodel = surface->GetColorModel();
    u32 pink = cmodel->GetColor(0xFF, 0x00, 0xFF, 0xFF);
    u32 black = cmodel->GetColor(0x00, 0x00, 0x00, 0xFF);

    for (u32 y = 0; y < surface->Height; ++y)
        for (u32 x = 0; x < surface->Width; ++x)
            cmodel->SetPixel(surface.get(), x, y, ((x ^ y) & 1) ? black : pink);

    return surface;
}
#endif

i32 agiTexDef::Reload()
{
    Surface = as_ptr agiSurfaceDesc::Load(Tex.Name, TexSearchPath, Tex.LOD, PackShift & 0xF, 0, 0);

#ifdef ARTS_DEBUG
    if (!Surface)
        Surface = CreateMissingTexture();
#endif

    if (!Surface)
        return AGI_ERROR_FILE_NOT_FOUND;

    CheckSurface();

    agiDisplayf("'%s' is %s texture", Tex.Name,
        (Tex.Flags & agiTexParameters::Chromakey)   ? "chromakey"
            : (Tex.Flags & agiTexParameters::Alpha) ? "alpha"
                                                    : "opaque");

    return AGI_ERROR_SUCCESS;
}

void agiTexDef::UnlockAndFreeSurface()
{
    if (cache_handle_ != 0)
        TEXCACHE.UnlockAndFree(cache_handle_);

    cache_handle_ = 0;
}

void agiTexDef::UnlockSurface()
{
    if (cache_handle_ != 0)
        TEXCACHE.Unlock(cache_handle_);
}

void agiTexDef::PageInCallback(void* param)
{
    static_cast<agiTexDef*>(param)->DoPageIn();
}

void agiTexDef::PageOutCallback(void* param, isize delta)
{
    agiTexDef* self = static_cast<agiTexDef*>(param);

    PointerFixup(self->Surface->Surface, delta);

    if (delta == 0)
        self->page_state_ = 0;
}

agiTexDef::agiTexDef(agiPipeline* pipe)
    : agiRefreshable(pipe)
{}

agiTexDef::~agiTexDef()
{
    if (cache_handle_ != 0)
        TEXCACHE.Free(cache_handle_);

    if (Surface)
        Surface->Unload();

    if (i32 index = agiTexLib.Lookup(Tex.Name))
    {
        if (Tex.LOD)
            index += Tex.LOD - 1;

        if (agiTexDef** def = agiTexLib.GetDef(index); *def)
        {
            ArAssert(*def == this, "TexLib def mismatch");
            Displayf("%s still in TexLib", GetName());
            *def = nullptr;
        }
    }
}

void ShutdownLutQueue()
{
    lutQhead = 0;
    lutQtail = 0;
}

void UpdateLutQueue()
{
    while (lutQhead != lutQtail)
    {
        i32 index = (lutQhead + 1) % ARTS_SIZE(lutQ);

        auto path = arts_formatf<32>("texp/nbr%s.lut", lutQ[index].Name);

        *lutQ[index].Lut = as_raw Pipe()->GetTexLut(path);

        if (*lutQ[index].Lut == nullptr)
            Errorf("Lut '%s' didn't load.", path.get());

        lutQhead = index;
    }
}

aconst char* agiTexLut::GetName()
{
    static char buffer[64]; // FIXME: Static buffer
    arts_sprintf(buffer, "texlut '%s'", name_.get());
    return buffer;
}

i32 agiTexLut::Init(const char* name)
{
    EndGfx();
    name_ = name;

    if (!arts_stricmp(name, "*grey") || !arts_stricmp(name, "*gray"))
    {
        for (u32 i = 0; i < ARTS_SIZE(palette_); ++i)
            palette_[i] = i * 0x010101;
    }
    else
    {
        Ptr<Stream> file {arts_fopen(name, "r")};

        if (file == nullptr)
            return -1;

        file->Read(palette_, sizeof(palette_));
    }

    return SafeBeginGfx();
}

agiTexLut::agiTexLut(agiPipeline* pipe)
    : agiRefreshable(pipe)
{}
