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

#include "arts7/node.h"

#include "mmeffects/birth.h"
#include "mmeffects/ptx.h"

#ifndef NUM_BANGER_TYPES
#    define NUM_BANGER_TYPES 512
#endif

class mmBangerData final : public asNode
{
public:
    // ??0mmBangerData@@QAE@XZ | inline
    ARTS_IMPORT mmBangerData();

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

#define BANGER_BILL_FLAG_10 0x10 // Shadows?
#define BANGER_BILL_FLAG_20 0x20 // Glow?

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

    // ??1mmBangerDataManager@@UAE@XZ
    ARTS_IMPORT ~mmBangerDataManager() override;

    // ?AddBangerDataEntry@mmBangerDataManager@@QAEHPAD0@Z
    ARTS_IMPORT i32 AddBangerDataEntry(aconst char* banger, aconst char* part);

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
        ArAssert(index >= -1 && index < NumEntries, "Invalid Banger Type");

        return (index >= 0 && index < NumEntries) ? &Types[index] : nullptr;
    }

    mmBangerData* GetBangerData(const char* banger, const char* part)
    {
        return GetBangerData(AddBangerDataEntry(xconst(banger), xconst(part)));
    }

    agiTexDef* GetParticleTexture(i32 index)
    {
        return ParticleTextures[std::clamp(index, 0, ARTS_SSIZE32(ParticleTextures) - 1)];
    }

    // ?DeclareFields@mmBangerDataManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?FloatClock@mmBangerDataManager@@2MA
    ARTS_IMPORT static f32 FloatClock;

    // ?SignalClock@mmBangerDataManager@@2HA
    ARTS_IMPORT static i32 SignalClock;

protected:
    friend mmBangerDataManager* BangerDataMgr();

    // ?Instance@mmBangerDataManager@@1PAV1@A
    ARTS_IMPORT static mmBangerDataManager* Instance;

    i32 NumEntries;
    mmBangerData Types[NUM_BANGER_TYPES];

    asParticles Particles;
    agiTexDef* ParticleTextures[10];

    Vector3 LaunchVelocity;
    Vector3 LaunchAngularVelocity;
};

check_size(mmBangerDataManager, 0x268D0);

inline mmBangerDataManager* BangerDataMgr()
{
    return mmBangerDataManager::Instance;
}

// ?RefTo@@YAPAUMetaType@@PAU1@HPAF@Z | inline
// ARTS_IMPORT MetaType* RefTo(MetaType* arg1, i32 arg2, i16* arg3);
