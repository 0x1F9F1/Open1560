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

/*
    agi:texdef

    0x556100 | public: __thiscall agiTexParameters::agiTexParameters(void) | ??0agiTexParameters@@QAE@XZ
    0x556120 | public: void __thiscall agiTexParameters::Load(class Stream *) | ?Load@agiTexParameters@@QAEXPAVStream@@@Z
    0x556170 | public: void __thiscall agiTexParameters::Save(class Stream *) | ?Save@agiTexParameters@@QAEXPAVStream@@@Z
    0x5561C0 | protected: __thiscall agiTexDef::agiTexDef(class agiPipeline *) | ??0agiTexDef@@IAE@PAVagiPipeline@@@Z
    0x556230 | protected: virtual __thiscall agiTexDef::~agiTexDef(void) | ??1agiTexDef@@MAE@XZ
    0x5562F0 | public: void __thiscall agiTexDef::CheckSurface(void) | ?CheckSurface@agiTexDef@@QAEXXZ
    0x556310 | public: int __thiscall agiTexDef::Reload(void) | ?Reload@agiTexDef@@QAEHXZ
    0x556380 | public: int __thiscall agiTexDef::Init(class agiTexParameters const &) | ?Init@agiTexDef@@QAEHABVagiTexParameters@@@Z
    0x556400 | public: virtual char * __thiscall agiTexDef::GetName(void) | ?GetName@agiTexDef@@UAEPADXZ
    0x556430 | public: virtual int __thiscall agiTexDef::IsTexture(void) | ?IsTexture@agiTexDef@@UAEHXZ
    0x556440 | public: virtual int __thiscall agiTexDef::Lock(struct agiTexLock &) | ?Lock@agiTexDef@@UAEHAAUagiTexLock@@@Z
    0x556450 | public: virtual void __thiscall agiTexDef::Unlock(struct agiTexLock &) | ?Unlock@agiTexDef@@UAEXAAUagiTexLock@@@Z
    0x556460 | public: static void __cdecl agiTexDef::PageOutCallback(void *,int) | ?PageOutCallback@agiTexDef@@SAXPAXH@Z
    0x5564A0 | void __cdecl UpdateLutQueue(void) | ?UpdateLutQueue@@YAXXZ
    0x556530 | void __cdecl ShutdownLutQueue(void) | ?ShutdownLutQueue@@YAXXZ
    0x556550 | public: void __thiscall agiTexDef::DoPageIn(void) | ?DoPageIn@agiTexDef@@QAEXXZ
    0x5566A0 | public: static void __cdecl agiTexDef::PageInCallback(void *) | ?PageInCallback@agiTexDef@@SAXPAX@Z
    0x5566B0 | public: void __thiscall agiTexDef::PageInSurface(void) | ?PageInSurface@agiTexDef@@QAEXXZ
    0x556770 | public: int __thiscall agiTexDef::LockSurfaceIfResident(void) | ?LockSurfaceIfResident@agiTexDef@@QAEHXZ
    0x5567A0 | public: void __thiscall agiTexDef::UnlockSurface(void) | ?UnlockSurface@agiTexDef@@QAEXXZ
    0x5567C0 | public: void __thiscall agiTexDef::UnlockAndFreeSurface(void) | ?UnlockAndFreeSurface@agiTexDef@@QAEXXZ
    0x5567E0 | public: virtual void __thiscall agiTexDef::Request(void) | ?Request@agiTexDef@@UAEXXZ
    0x5567F0 | public: virtual int __thiscall agiTexDef::IsAvailable(void) | ?IsAvailable@agiTexDef@@UAEHXZ
    0x556800 | public: int __thiscall agiTexLut::Init(char *) | ?Init@agiTexLut@@QAEHPAD@Z
    0x5568D0 | public: virtual char * __thiscall agiTexLut::GetName(void) | ?GetName@agiTexLut@@UAEPADXZ
    0x5568F0 | protected: __thiscall agiTexLut::agiTexLut(class agiPipeline *) | ??0agiTexLut@@IAE@PAVagiPipeline@@@Z
    0x556920 | protected: virtual __thiscall agiTexLut::~agiTexLut(void) | ??1agiTexLut@@MAE@XZ
    0x556970 | protected: virtual void * __thiscall agiTexDef::`scalar deleting destructor'(unsigned int) | ??_GagiTexDef@@MAEPAXI@Z
    0x556970 | protected: virtual void * __thiscall agiTexDef::`vector deleting destructor'(unsigned int) | ??_EagiTexDef@@MAEPAXI@Z
    0x5569A0 | protected: virtual void * __thiscall agiTexLut::`vector deleting destructor'(unsigned int) | ??_EagiTexLut@@MAEPAXI@Z
    0x5569A0 | protected: virtual void * __thiscall agiTexLut::`scalar deleting destructor'(unsigned int) | ??_GagiTexLut@@MAEPAXI@Z
    0x6215B8 | const agiTexDef::`vftable' | ??_7agiTexDef@@6B@
    0x6215E8 | const agiTexLut::`vftable' | ??_7agiTexLut@@6B@
    0x656834 | int MaxTexSize | ?MaxTexSize@@3HA
    0x656838 | char * TexSearchPath | ?TexSearchPath@@3PADA
    0x8FAD28 | int PackShift | ?PackShift@@3HA
    0x8FAD2C | int TexBytesPaged | ?TexBytesPaged@@3HA
    0x8FAD70 | struct lutQentry * lutQ | ?lutQ@@3PAUlutQentry@@A
    0x8FAF70 | class HashTable TexLutHash | ?TexLutHash@@3VHashTable@@A
    0x8FAF88 | class DataCache TEXCACHE | ?TEXCACHE@@3VDataCache@@A
    0x8FAFC8 | int TexsPaged | ?TexsPaged@@3HA
*/

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

    u8 Flags {0};

    // Probably not actually LOD, seems to always be 0
    u8 LOD {0};
    u8 MaxLOD {0};

    // Mirrors agiTexProp::Flags
    u32 Props {0};

    f32 field_28 {0.0f}; // Snowable ? 4.0f : 2.0f
    u32 Color {0};

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
    agiColorModel* ColorModel {nullptr};
    u32 Width {0};
    u32 Height {0};
    i32 Pitch {0};
    void* Surface {nullptr};
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
    ARTS_EXPORT char* GetName() override;

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
    ARTS_EXPORT static void PageInCallback(void* param);

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
    agiPolySet* PolySet {nullptr};
    i32 SceneIndex {0};
    u32 SurfaceSize {0};
    i32 PackShift {0};

protected:
    // ??0agiTexDef@@IAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiTexDef(agiPipeline* pipe);

    // ??_EagiTexDef@@MAEPAXI@Z
    // ??_GagiTexDef@@MAEPAXI@Z
    // ??1agiTexDef@@MAE@XZ
    ARTS_EXPORT ~agiTexDef() override;

    // CacheHandle must be stored directly after Pager
    PagerInfo_t pager_ {};
    i32 cache_handle_ {0};

    // 0 | Paged Out
    // 1 | Paging In
    // 2 | Paged In
    std::atomic<i32> page_state_ {0};
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
ARTS_IMPORT extern char* TexSearchPath; // Null Separated

// ?TexsPaged@@3HA
ARTS_IMPORT extern i32 TexsPaged;

// ?lutQ@@3PAUlutQentry@@A
ARTS_IMPORT extern lutQentry lutQ[64];

class agiTexLut : public agiRefreshable
{
public:
    // ?GetName@agiTexLut@@UAEPADXZ
    ARTS_EXPORT char* GetName() override;

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
