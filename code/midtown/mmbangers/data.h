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
    mmbangers:data

    0x4C81B0 | public: int __thiscall mmBangerData::LoadEntry(char *) | ?LoadEntry@mmBangerData@@QAEHPAD@Z
    0x4C8370 | public: void __thiscall mmBangerData::LaunchInstance(float,class Vector3 *) | ?LaunchInstance@mmBangerData@@QAEXMPAVVector3@@@Z
    0x4C8550 | public: virtual void __thiscall mmBangerDataManager::AddWidgets(class Bank *) | ?AddWidgets@mmBangerDataManager@@UAEXPAVBank@@@Z
    0x4C85E0 | public: virtual void __thiscall mmBangerData::AddWidgets(class Bank *) | ?AddWidgets@mmBangerData@@UAEXPAVBank@@@Z
    0x4C8A30 | public: __thiscall mmBangerDataManager::mmBangerDataManager(void) | ??0mmBangerDataManager@@QAE@XZ
    0x4C8B50 | public: virtual __thiscall mmBangerDataManager::~mmBangerDataManager(void) | ??1mmBangerDataManager@@UAE@XZ
    0x4C8C10 | public: int __thiscall mmBangerDataManager::AddBangerDataEntry(char *,char *) | ?AddBangerDataEntry@mmBangerDataManager@@QAEHPAD0@Z
    0x4C8E70 | public: int __thiscall mmBangerData::Bootstrap(char *,char *) | ?Bootstrap@mmBangerData@@QAEHPAD0@Z
    0x4C8ED0 | public: void __thiscall mmBangerData::BootstrapBreakablesOnly(char *) | ?BootstrapBreakablesOnly@mmBangerData@@QAEXPAD@Z
    0x4C8F10 | public: void __thiscall mmBangerData::InitBreakables(char *) | ?InitBreakables@mmBangerData@@QAEXPAD@Z
    0x4C9150 | public: int __thiscall mmBangerData::InitPhysics(char *,char *) | ?InitPhysics@mmBangerData@@QAEHPAD0@Z
    0x4C93D0 | public: void __thiscall mmBangerData::ComputeYRadius(char *) | ?ComputeYRadius@mmBangerData@@QAEXPAD@Z
    0x4C9510 | public: virtual void __thiscall mmBangerDataManager::Save(void) | ?Save@mmBangerDataManager@@UAEXXZ
    0x4C9540 | public: static void __cdecl mmBangerData::DeclareFields(void) | ?DeclareFields@mmBangerData@@SAXXZ
    0x4C98C0 | public: virtual class MetaClass * __thiscall mmBangerData::GetClass(void) | ?GetClass@mmBangerData@@UAEPAVMetaClass@@XZ
    0x4C98D0 | public: static void __cdecl mmBangerDataManager::DeclareFields(void) | ?DeclareFields@mmBangerDataManager@@SAXXZ
    0x4C9A40 | public: virtual class MetaClass * __thiscall mmBangerDataManager::GetClass(void) | ?GetClass@mmBangerDataManager@@UAEPAVMetaClass@@XZ
    0x4C9A50 | struct MetaType * __cdecl RefTo(struct MetaType *,int,short *) | ?RefTo@@YAPAUMetaType@@PAU1@HPAF@Z
    0x4C9A90 | public: virtual void * __thiscall mmBangerData::`vector deleting destructor'(unsigned int) | ??_EmmBangerData@@UAEPAXI@Z
    0x4C9AF0 | public: virtual void * __thiscall mmBangerDataManager::`vector deleting destructor'(unsigned int) | ??_EmmBangerDataManager@@UAEPAXI@Z
    0x4C9B50 | public: __thiscall mmBangerData::mmBangerData(void) | ??0mmBangerData@@QAE@XZ
    0x4C9BE0 | public: virtual __thiscall mmBangerData::~mmBangerData(void) | ??1mmBangerData@@UAE@XZ
    0x61F6E0 | const mmBangerDataManager::`vftable' | ??_7mmBangerDataManager@@6B@
    0x61F720 | const RefToType::`vftable' | ??_7RefToType@@6B@
    0x61F738 | const mmBangerData::`vftable' | ??_7mmBangerData@@6B@
    0x705FB0 | class MetaClass mmBangerDataMetaClass | ?mmBangerDataMetaClass@@3VMetaClass@@A
    0x705FD8 | public: static float mmBangerDataManager::FloatClock | ?FloatClock@mmBangerDataManager@@2MA
    0x705FDC | protected: static class mmBangerDataManager * mmBangerDataManager::Instance | ?Instance@mmBangerDataManager@@1PAV1@A
    0x705FF0 | public: static int mmBangerDataManager::SignalClock | ?SignalClock@mmBangerDataManager@@2HA
    0x706008 | class MetaClass mmBangerDataManagerMetaClass | ?mmBangerDataManagerMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

#include "mmeffects/birth.h"
#include "mmeffects/ptx.h"

class mmBangerData final : public asNode
{
public:
    // ??0mmBangerData@@QAE@XZ | inline
    ARTS_IMPORT mmBangerData();

    // ??_EmmBangerData@@UAEPAXI@Z
    // ??1mmBangerData@@UAE@XZ | inline
    ARTS_IMPORT ~mmBangerData() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmBangerData@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Bootstrap@mmBangerData@@QAEHPAD0@Z
    ARTS_IMPORT i32 Bootstrap(char* arg1, char* arg2);

    // ?BootstrapBreakablesOnly@mmBangerData@@QAEXPAD@Z
    ARTS_IMPORT void BootstrapBreakablesOnly(char* arg1);

    // ?ComputeYRadius@mmBangerData@@QAEXPAD@Z
    ARTS_IMPORT void ComputeYRadius(char* arg1);

    // ?GetClass@mmBangerData@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?InitBreakables@mmBangerData@@QAEXPAD@Z
    ARTS_IMPORT void InitBreakables(char* arg1);

    // ?InitPhysics@mmBangerData@@QAEHPAD0@Z
    ARTS_IMPORT i32 InitPhysics(char* arg1, char* arg2);

    // ?LaunchInstance@mmBangerData@@QAEXMPAVVector3@@@Z
    ARTS_IMPORT void LaunchInstance(f32 arg1, Vector3* arg2);

    // ?LoadEntry@mmBangerData@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadEntry(char* arg1);

    // ?DeclareFields@mmBangerData@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    i32 Index;
    Vector3 CG;
    Vector3 Size;
    Vector3 Offset;
    Vector3 GlowOffset;
    f32 Mass;
    f32 Elasticity;
    f32 Friction;
    f32 ImpulseLimit2;
    f32 YRadius;
    asBirthRule BirthRule;
    i32 TexNumber;
    i32 BillFlags;
    i16 SpinAxis;
    i16 Flash;

#define BANGER_COLLISION_TYPE_1 1
#define BANGER_COLLISION_TYPE_2 2 // Glass
#define BANGER_COLLISION_TYPE_4 4 // Props
#define BANGER_COLLISION_TYPE_6 6 // Walls

    i16 CollisionType;
    i16 NumParts;
    char** PartNames;
    u32 AudioId;
    i32 MeshIndex;
};

check_size(mmBangerData, 0x134);

class mmBangerDataManager final : public asNode
{
public:
    // ??0mmBangerDataManager@@QAE@XZ
    ARTS_IMPORT mmBangerDataManager();

    // ??_EmmBangerDataManager@@UAEPAXI@Z
    // ??1mmBangerDataManager@@UAE@XZ
    ARTS_IMPORT ~mmBangerDataManager() override;

    // ?AddBangerDataEntry@mmBangerDataManager@@QAEHPAD0@Z
    ARTS_IMPORT i32 AddBangerDataEntry(char* banger, char* part);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmBangerDataManager@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@mmBangerDataManager@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Save@mmBangerDataManager@@UAEXXZ
    ARTS_IMPORT void Save() override;

    mmBangerData* GetBangerData(i32 index)
    {
        return (index != -1) ? &Bangers[index] : nullptr;
    }

    mmBangerData* GetBangerData(const char* banger, const char* part)
    {
        return GetBangerData(AddBangerDataEntry(const_cast<char*>(banger), const_cast<char*>(part)));
    }

    // ?DeclareFields@mmBangerDataManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?FloatClock@mmBangerDataManager@@2MA
    ARTS_IMPORT static f32 FloatClock;

    // ?SignalClock@mmBangerDataManager@@2HA
    ARTS_IMPORT static i32 SignalClock;

protected:
    friend mmBangerDataManager* BangerDataManager();

    // ?Instance@mmBangerDataManager@@1PAV1@A
    ARTS_IMPORT static mmBangerDataManager* Instance;

    i32 NumEntries;
    mmBangerData Bangers[512];
    asParticles Particles;
    agiTexDef* ParticleTextures[10];
    Vector3 LaunchVelocity;
    Vector3 LaunchAngularVelocity;
};

check_size(mmBangerDataManager, 0x268D0);

inline mmBangerDataManager* BangerDataManager()
{
    return mmBangerDataManager::Instance;
}

// ?RefTo@@YAPAUMetaType@@PAU1@HPAF@Z | inline
// ARTS_IMPORT MetaType* RefTo(MetaType* arg1, i32 arg2, i16* arg3);
