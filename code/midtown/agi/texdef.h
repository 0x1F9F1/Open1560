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

class agiTexParameters
{
public:
    // 0x556100 | ??0agiTexParameters@@QAE@XZ
    agiTexParameters();

    // 0x556120 | ?Load@agiTexParameters@@QAEXPAVStream@@@Z
    void Load(class Stream* arg1);

    // 0x556170 | ?Save@agiTexParameters@@QAEXPAVStream@@@Z
    void Save(class Stream* arg1);
};

check_size(agiTexParameters, 0x30);

class agiTexDef : public agiRefreshable
{
    // const agiTexDef::`vftable' @ 0x6215B8

public:
    // 0x5567F0 | ?IsAvailable@agiTexDef@@UAEHXZ
    virtual i32 IsAvailable();

    virtual void Set(class Vector2& arg1, class Vector2& arg2) = 0;

    // 0x556440 | ?Lock@agiTexDef@@UAEHAAUagiTexLock@@@Z
    virtual i32 Lock(struct agiTexLock& arg1);

    // 0x556450 | ?Unlock@agiTexDef@@UAEXAAUagiTexLock@@@Z
    virtual void Unlock(struct agiTexLock& arg1);

    // 0x5567E0 | ?Request@agiTexDef@@UAEXXZ
    virtual void Request();

    // 0x5562F0 | ?CheckSurface@agiTexDef@@QAEXXZ
    void CheckSurface();

    // 0x556550 | ?DoPageIn@agiTexDef@@QAEXXZ
    void DoPageIn();

    // 0x556400 | ?GetName@agiTexDef@@UAEPADXZ
    char* GetName() override;

    // 0x556380 | ?Init@agiTexDef@@QAEHABVagiTexParameters@@@Z
    i32 Init(class agiTexParameters const& arg1);

    // 0x556430 | ?IsTexture@agiTexDef@@UAEHXZ
    i32 IsTexture() override;

    // 0x556770 | ?LockSurfaceIfResident@agiTexDef@@QAEHXZ
    i32 LockSurfaceIfResident();

    // 0x5566B0 | ?PageInSurface@agiTexDef@@QAEXXZ
    void PageInSurface();

    // 0x556310 | ?Reload@agiTexDef@@QAEHXZ
    i32 Reload();

    // 0x5567C0 | ?UnlockAndFreeSurface@agiTexDef@@QAEXXZ
    void UnlockAndFreeSurface();

    // 0x5567A0 | ?UnlockSurface@agiTexDef@@QAEXXZ
    void UnlockSurface();

    // 0x5566A0 | ?PageInCallback@agiTexDef@@SAXPAX@Z
    static void PageInCallback(void* arg1);

    // 0x556460 | ?PageOutCallback@agiTexDef@@SAXPAXH@Z
    static void PageOutCallback(void* arg1, i32 arg2);

protected:
    // 0x5561C0 | ??0agiTexDef@@IAE@PAVagiPipeline@@@Z
    agiTexDef(class agiPipeline* arg1);

    // 0x556970 | ??_EagiTexDef@@MAEPAXI@Z
    // 0x556230 | ??1agiTexDef@@MAE@XZ
    ~agiTexDef() override;
};

check_size(agiTexDef, 0x0);

// 0x556530 | ?ShutdownLutQueue@@YAXXZ
void ShutdownLutQueue();

// 0x5564A0 | ?UpdateLutQueue@@YAXXZ
void UpdateLutQueue();

// 0x656834 | ?MaxTexSize@@3HA
inline extern_var(0x656834, i32, MaxTexSize);

// 0x8FAD28 | ?PackShift@@3HA
inline extern_var(0x8FAD28, i32, PackShift);

// 0x8FAF88 | ?TEXCACHE@@3VDataCache@@A
inline extern_var(0x8FAF88, class DataCache, TEXCACHE);

// 0x8FAD2C | ?TexBytesPaged@@3HA
inline extern_var(0x8FAD2C, i32, TexBytesPaged);

// 0x8FAF70 | ?TexLutHash@@3VHashTable@@A
inline extern_var(0x8FAF70, class HashTable, TexLutHash);

// 0x656838 | ?TexSearchPath@@3PADA
inline extern_var(0x656838, char*, TexSearchPath);

// 0x8FAFC8 | ?TexsPaged@@3HA
inline extern_var(0x8FAFC8, i32, TexsPaged);

// 0x8FAD70 | ?lutQ@@3PAUlutQentry@@A
inline extern_var(0x8FAD70, struct lutQentry[64], lutQ);

class agiTexLut : public agiRefreshable
{
    // const agiTexLut::`vftable' @ 0x6215E8

public:
    // 0x5568D0 | ?GetName@agiTexLut@@UAEPADXZ
    char* GetName() override;

    // 0x556800 | ?Init@agiTexLut@@QAEHPAD@Z
    i32 Init(char* arg1);

protected:
    // 0x5568F0 | ??0agiTexLut@@IAE@PAVagiPipeline@@@Z
    agiTexLut(class agiPipeline* arg1);

    // 0x5569A0 | ??_GagiTexLut@@MAEPAXI@Z
    // 0x556920 | ??1agiTexLut@@MAE@XZ
    ~agiTexLut() override;
};

check_size(agiTexLut, 0x420);
