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

#include "refresh.h"

#include "data7/pager.h"
#include "surface.h"

#include <atomic>

class agiColorModel;
class agiPolySet;
class DataCache;
struct lutQentry;

class agiTexParameters
{
public:
    // ??0agiTexParameters@@QAE@XZ
    ARTS_EXPORT agiTexParameters() = default;

    // ?Load@agiTexParameters@@QAEXPAVStream@@@Z
    ARTS_EXPORT void Load(Stream* file);

    // ?Save@agiTexParameters@@QAEXPAVStream@@@Z
    ARTS_EXPORT void Save(Stream* file);

    char Name[32] {};

    enum : u8
    {
        Alpha = 0x1,
        WrapU = 0x2,
        WrapV = 0x4,
        KeepLoaded = 0x8,
        NoMipMaps = 0x10,
        Chromakey = 0x40,
        Second = 0x80,
    };

    u8 Flags {};

    // Probably not actually LOD, seems to always be 0
    u8 LOD {};
    u8 MaxLOD {};

    // Mirrors agiTexProp::Flags
    u32 Props {};

    f32 field_28 {}; // Snowable ? 4.0f : 2.0f
    u32 Color {};

    bool HasAlpha() const
    {
        return Flags & agiTexParameters::Alpha;
    }

    bool ShouldWrapU() const
    {
        return Flags & agiTexParameters::WrapU;
    }

    bool ShouldWrapV() const
    {
        return Flags & agiTexParameters::WrapV;
    }

    bool DisableMipMaps() const
    {
        return Flags & agiTexParameters::NoMipMaps;
    }

    bool UseChromakey() const
    {
        return Flags & agiTexParameters::Chromakey;
    }
};

check_size(agiTexParameters, 0x30);

struct agiTexLock
{
    agiColorModel* ColorModel {};
    u32 Width {};
    u32 Height {};
    i32 Pitch {};
    void* Surface {};
};

check_size(agiTexLock, 0x14);

class agiTexDef : public agiRefreshable
{
public:
    // ?IsAvailable@agiTexDef@@UAEHXZ
    ARTS_EXPORT virtual b32 IsAvailable();

    virtual void Set(Vector2& arg1, Vector2& arg2) = 0;

    // ?Lock@agiTexDef@@UAEHAAUagiTexLock@@@Z
    ARTS_EXPORT virtual b32 Lock(agiTexLock& lock);

    // ?Unlock@agiTexDef@@UAEXAAUagiTexLock@@@Z
    ARTS_EXPORT virtual void Unlock(agiTexLock& lock);

    // ?Request@agiTexDef@@UAEXXZ
    ARTS_EXPORT virtual void Request();

    // ?CheckSurface@agiTexDef@@QAEXXZ
    ARTS_EXPORT void CheckSurface();

    // ?DoPageIn@agiTexDef@@QAEXXZ
    ARTS_EXPORT void DoPageIn();

    // ?GetName@agiTexDef@@UAEPADXZ
    ARTS_EXPORT aconst char* GetName() override;

    // ?Init@agiTexDef@@QAEHABVagiTexParameters@@@Z
    ARTS_EXPORT i32 Init(const agiTexParameters& params);

    i32 Init(const agiTexParameters& params, Ptr<agiSurfaceDesc> surface);

    // ?IsTexture@agiTexDef@@UAEHXZ
    ARTS_EXPORT b32 IsTexture() override;

    // ?LockSurfaceIfResident@agiTexDef@@QAEHXZ
    ARTS_EXPORT b32 LockSurfaceIfResident();

    // ?PageInSurface@agiTexDef@@QAEXXZ
    ARTS_EXPORT void PageInSurface();

    // ?Reload@agiTexDef@@QAEHXZ
    ARTS_EXPORT i32 Reload();

    // ?UnlockAndFreeSurface@agiTexDef@@QAEXXZ
    ARTS_EXPORT void UnlockAndFreeSurface();

    // ?UnlockSurface@agiTexDef@@QAEXXZ
    ARTS_EXPORT void UnlockSurface();

    // ?PageInCallback@agiTexDef@@SAXPAX@Z
    [[deprecated]] ARTS_EXPORT static void PageInCallback(void* param);

    // ?PageOutCallback@agiTexDef@@SAXPAXH@Z
    ARTS_EXPORT static void PageOutCallback(void* param, isize delta);

    i32 GetWidth() const
    {
        return Surface->Width;
    }

    i32 GetHeight() const
    {
        return Surface->Height;
    }

    Ptr<agiSurfaceDesc> Surface;
    agiTexParameters Tex {};
    agiPolySet* PolySet {};
    i32 SceneIndex {};
    u32 SurfaceSize {};
    i32 PackShift {};

protected:
    // ??0agiTexDef@@IAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiTexDef(agiPipeline* pipe);

    // ??_EagiTexDef@@MAEPAXI@Z
    // ??_GagiTexDef@@MAEPAXI@Z
    // ??1agiTexDef@@MAE@XZ
    ARTS_EXPORT ~agiTexDef() override;

    // CacheHandle must be stored directly after Pager
    PagerInfo_t pager_ {};
    i32 cache_handle_ {};

    // 0 | Paged Out
    // 1 | Paging In
    // 2 | Paged In
    std::atomic<i32> page_state_ {};
};

check_size(agiTexDef, 0x74);

// ?ShutdownLutQueue@@YAXXZ
ARTS_EXPORT void ShutdownLutQueue();

// ?UpdateLutQueue@@YAXXZ
ARTS_EXPORT void UpdateLutQueue();

// ?MaxTexSize@@3HA
ARTS_IMPORT extern i32 MaxTexSize;

// ?PackShift@@3HA
ARTS_IMPORT extern i32 PackShift;

// ?TEXCACHE@@3VDataCache@@A
ARTS_EXPORT extern DataCache TEXCACHE;

// ?TexBytesPaged@@3HA
ARTS_IMPORT extern i32 TexBytesPaged;

// ?TexLutHash@@3VHashTable@@A
ARTS_IMPORT extern HashTable TexLutHash;

// ?TexSearchPath@@3PADA
ARTS_IMPORT extern aconst char* TexSearchPath; // Null Separated

// ?TexsPaged@@3HA
ARTS_IMPORT extern i32 TexsPaged;

// ?lutQ@@3PAUlutQentry@@A
ARTS_IMPORT extern lutQentry lutQ[64];

class agiTexLut : public agiRefreshable
{
public:
    // ?GetName@agiTexLut@@UAEPADXZ
    ARTS_EXPORT aconst char* GetName() override;

    // ?Init@agiTexLut@@QAEHPAD@Z
    ARTS_EXPORT i32 Init(const char* name);

protected:
    // ??0agiTexLut@@IAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiTexLut(agiPipeline* pipe);

    // ??_GagiTexLut@@MAEPAXI@Z
    // ??_EagiTexLut@@MAEPAXI@Z
    // ??1agiTexLut@@MAE@XZ
    ARTS_EXPORT ~agiTexLut() override = default;

    u32 palette_[256] {};
    ConstString name_;
};

check_size(agiTexLut, 0x41C);
