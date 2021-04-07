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
    mmcar:shard

    0x478560 | public: __thiscall mmShard::mmShard(void) | ??0mmShard@@QAE@XZ
    0x4785A0 | public: void __thiscall mmShard::Init(char *,int) | ?Init@mmShard@@QAEXPADH@Z
    0x4785D0 | public: virtual __thiscall mmShard::~mmShard(void) | ??1mmShard@@UAE@XZ
    0x4785E0 | public: void __thiscall mmShard::AddShard(class Vector3,class Vector3,class Vector3,float) | ?AddShard@mmShard@@QAEXVVector3@@00M@Z
    0x478640 | public: void __thiscall mmShard::Update(void) | ?Update@mmShard@@QAEXXZ
    0x478730 | public: virtual void __fastcall mmShard::Draw(int) | ?Draw@mmShard@@UAIXH@Z
    0x4787F0 | public: __thiscall mmShardManager::mmShardManager(void) | ??0mmShardManager@@QAE@XZ
    0x478860 | public: virtual __thiscall mmShardManager::~mmShardManager(void) | ??1mmShardManager@@UAE@XZ
    0x4788D0 | public: static class mmShardManager * __cdecl mmShardManager::GetInstance(int) | ?GetInstance@mmShardManager@@SAPAV1@H@Z
    0x4788F0 | public: void __thiscall mmShardManager::Init(char *,int,class mmCarSim *) | ?Init@mmShardManager@@QAEXPADHPAVmmCarSim@@@Z
    0x4789E0 | public: void __thiscall mmShardManager::ReInit(class mmCarSim *) | ?ReInit@mmShardManager@@QAEXPAVmmCarSim@@@Z
    0x4789F0 | public: void __thiscall mmShardManager::EmitShards(class Vector3,float,float) | ?EmitShards@mmShardManager@@QAEXVVector3@@MM@Z
    0x478A60 | public: void __thiscall mmShardManager::EmitAllShards(class Vector3,float) | ?EmitAllShards@mmShardManager@@QAEXVVector3@@M@Z
    0x478AB0 | public: void __thiscall mmShardManager::EmitShard(class Vector3,float) | ?EmitShard@mmShardManager@@QAEXVVector3@@M@Z
    0x478C60 | public: virtual void __thiscall mmShardManager::Update(void) | ?Update@mmShardManager@@UAEXXZ
    0x478C90 | public: virtual void __thiscall mmShardManager::AddWidgets(class Bank *) | ?AddWidgets@mmShardManager@@UAEXPAVBank@@@Z
    0x478E00 | public: static void __cdecl mmShard::DeclareFields(void) | ?DeclareFields@mmShard@@SAXXZ
    0x478F80 | public: virtual class MetaClass * __thiscall mmShard::GetClass(void) | ?GetClass@mmShard@@UAEPAVMetaClass@@XZ
    0x478F90 | public: static void __cdecl mmShardManager::DeclareFields(void) | ?DeclareFields@mmShardManager@@SAXXZ
    0x479160 | public: virtual class MetaClass * __thiscall mmShardManager::GetClass(void) | ?GetClass@mmShardManager@@UAEPAVMetaClass@@XZ
    0x479170 | public: virtual void * __thiscall mmShard::`vector deleting destructor'(unsigned int) | ??_EmmShard@@UAEPAXI@Z
    0x4791D0 | public: virtual void * __thiscall mmShardManager::`vector deleting destructor'(unsigned int) | ??_EmmShardManager@@UAEPAXI@Z
    0x61C2C0 | const mmShard::`vftable' | ??_7mmShard@@6B@
    0x61C350 | const mmShardManager::`vftable' | ??_7mmShardManager@@6B@
    0x6A7EF0 | class MetaClass mmShardManagerMetaClass | ?mmShardManagerMetaClass@@3VMetaClass@@A
    0x6A7F18 | protected: static class mmShardManager * * mmShardManager::Instances | ?Instances@mmShardManager@@1PAPAV1@A
    0x6A7F68 | class MetaClass mmShardMetaClass | ?mmShardMetaClass@@3VMetaClass@@A
    0x6A7F90 | protected: static int mmShardManager::NumInstances | ?NumInstances@mmShardManager@@1HA
*/

#include "arts7/node.h"
#include "mmcity/inst.h"

class agiTexDef;
class mmCarSim;

class mmShard final : public mmMatrixInstance
{
    // const mmShard::`vftable' @ 0x61C2C0

public:
    // 0x478560 | ??0mmShard@@QAE@XZ
    ARTS_IMPORT mmShard();

    // 0x479170 | ??_EmmShard@@UAEPAXI@Z
    // 0x4785D0 | ??1mmShard@@UAE@XZ
    ARTS_IMPORT ~mmShard() override = default;

    // 0x4785E0 | ?AddShard@mmShard@@QAEXVVector3@@00M@Z
    ARTS_IMPORT void AddShard(class Vector3 arg1, class Vector3 arg2, class Vector3 arg3, f32 arg4);

    // 0x478730 | ?Draw@mmShard@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x478F80 | ?GetClass@mmShard@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4785A0 | ?Init@mmShard@@QAEXPADH@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2);

    // 0x478640 | ?Update@mmShard@@QAEXXZ
    ARTS_IMPORT void Update();

    // 0x478E00 | ?DeclareFields@mmShard@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap44[0x20];
};

check_size(mmShard, 0x64);

class mmShardManager final : public asNode
{
    // const mmShardManager::`vftable' @ 0x61C350

public:
    // 0x4787F0 | ??0mmShardManager@@QAE@XZ
    ARTS_EXPORT mmShardManager();

    // 0x4791D0 | ??_EmmShardManager@@UAEPAXI@Z
    // 0x478860 | ??1mmShardManager@@UAE@XZ
    ARTS_EXPORT ~mmShardManager() override;

    // 0x478C90 | ?AddWidgets@mmShardManager@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x478A60 | ?EmitAllShards@mmShardManager@@QAEXVVector3@@M@Z
    ARTS_IMPORT void EmitAllShards(class Vector3 arg1, f32 arg2);

    // 0x478AB0 | ?EmitShard@mmShardManager@@QAEXVVector3@@M@Z
    ARTS_IMPORT void EmitShard(class Vector3 arg1, f32 arg2);

    // 0x4789F0 | ?EmitShards@mmShardManager@@QAEXVVector3@@MM@Z
    ARTS_IMPORT void EmitShards(class Vector3 arg1, f32 arg2, f32 arg3);

    // 0x479160 | ?GetClass@mmShardManager@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4788F0 | ?Init@mmShardManager@@QAEXPADHPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2, class mmCarSim* arg3);

    // 0x4789E0 | ?ReInit@mmShardManager@@QAEXPAVmmCarSim@@@Z | unused
    ARTS_IMPORT void ReInit(class mmCarSim* arg1);

    // 0x478C60 | ?Update@mmShardManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x478F90 | ?DeclareFields@mmShardManager@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // 0x4788D0 | ?GetInstance@mmShardManager@@SAPAV1@H@Z
    ARTS_EXPORT static class mmShardManager* GetInstance(i32 index);

protected:
    // 0x6A7F18 | ?Instances@mmShardManager@@1PAPAV1@A
    ARTS_EXPORT static class mmShardManager* Instances[64];

    // 0x6A7F90 | ?NumInstances@mmShardManager@@1HA
    ARTS_IMPORT static i32 NumInstances;

private:
    mmCarSim* CarSim {nullptr};
    Ptr<mmShard[]> Shards;
    i32 ShardCount {0};
    i32 ShardHead {0};
    f32 ImpThresh {3500.0f};
    f32 ImpPerShard {0.0f};
    f32 VelXCoeff {0.3f};
    f32 VelYCoeff {0.3f};
    f32 VelZCoeff {0.2f};
    f32 AngVelCoeff {1.8f};
    f32 SpeedThresh {5.0f};
    i32 Index {0};
    agiTexDef* TexDef {nullptr};
};

check_size(mmShardManager, 0x54);

// 0x6A7EF0 | ?mmShardManagerMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmShardManagerMetaClass;

// 0x6A7F68 | ?mmShardMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmShardMetaClass;
