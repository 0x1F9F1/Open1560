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
#include "mmcity/inst.h"

class agiTexDef;
class mmCarSim;

class mmShard final : public mmMatrixInstance
{
public:
    // ??0mmShard@@QAE@XZ
    ARTS_IMPORT mmShard();

    // ??1mmShard@@UAE@XZ
    ARTS_EXPORT ~mmShard() override = default;

    // ?AddShard@mmShard@@QAEXVVector3@@00M@Z
    ARTS_IMPORT void AddShard(Vector3 arg1, Vector3 arg2, Vector3 arg3, f32 arg4);

    // ?Draw@mmShard@@UAIXH@Z
    ARTS_EXPORT void ARTS_FASTCALL Draw(i32 lod) override;

    // ?GetClass@mmShard@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmShard@@QAEXPADH@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2);

    // ?Update@mmShard@@QAEXXZ
    ARTS_IMPORT void Update();

    // ?DeclareFields@mmShard@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    Vector3 Velocity;
    Vector3 RotationAxis;
    f32 Age;
    f32 RotationSpeed;
};

check_size(mmShard, 0x64);

class mmShardManager final : public asNode
{
public:
    // ??0mmShardManager@@QAE@XZ
    ARTS_EXPORT mmShardManager();

    // ??1mmShardManager@@UAE@XZ
    ARTS_EXPORT ~mmShardManager() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmShardManager@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?EmitAllShards@mmShardManager@@QAEXVVector3@@M@Z
    ARTS_IMPORT void EmitAllShards(Vector3 arg1, f32 arg2);

    // ?EmitShard@mmShardManager@@QAEXVVector3@@M@Z
    ARTS_IMPORT void EmitShard(Vector3 arg1, f32 arg2);

    // ?EmitShards@mmShardManager@@QAEXVVector3@@MM@Z
    ARTS_IMPORT void EmitShards(Vector3 arg1, f32 arg2, f32 arg3);

    // ?GetClass@mmShardManager@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmShardManager@@QAEXPADHPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2, mmCarSim* arg3);

    // ?Update@mmShardManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmShardManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?GetInstance@mmShardManager@@SAPAV1@H@Z
    static mmShardManager* GetInstance(i32 index);

    friend class mmShard;

protected:
    static const usize MaxShardManagers = 128;

    // ?Instances@mmShardManager@@1PAPAV1@A
    static mmShardManager* Instances[MaxShardManagers];

    // ?NumInstances@mmShardManager@@1HA
    ARTS_IMPORT static i32 NumInstances;

private:
    mmCarSim* CarSim {};
    Ptr<mmShard[]> Shards;
    i32 ShardCount {};
    i32 ShardHead {};
    f32 ImpThresh {3500.0f};
    f32 ImpPerShard {};
    f32 VelXCoeff {0.3f};
    f32 VelYCoeff {0.3f};
    f32 VelZCoeff {0.2f};
    f32 AngVelCoeff {1.8f};
    f32 SpeedThresh {5.0f};
    i32 Index {};
    agiTexDef* TexDef {};
};

check_size(mmShardManager, 0x54);
