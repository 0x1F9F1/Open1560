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

#include "agiworld/texsort.h"
#include "arts7/node.h"
#include "mmbangers/active.h"
#include "mmbangers/banger.h"
#include "mmbangers/data.h"
#include "vector7/matrix34.h"

#include "inst.h"
#include "instchn.h"
#include "renderweb.h"
#include "sky.h"

class agiTexDef;
class asCamera;
class mmPolygon;

// TODO: Move to portal.h?
#define ROOM_FLAG_1 0x1     // No Env/Sph Mapping
#define ROOM_FLAG_2 0x2     // ?
#define ROOM_FLAG_4 0x4     // Water/Slide, Implies 0x20
#define ROOM_FLAG_8 0x8     // ?
#define ROOM_FLAG_10 0x10   // Implies 0x40
#define ROOM_FLAG_20 0x20   // Force ZEnable
#define ROOM_FLAG_40 0x40   // No Skidding ?
#define ROOM_FLAG_80 0x80   // FogValue = 0.25
#define ROOM_FLAG_100 0x100 // ?

class mmCullCity final : public asNode
{
public:
    // ??0mmCullCity@@QAE@XZ
    ARTS_IMPORT mmCullCity();

    // ??_EmmCullCity@@UAEPAXI@Z
    // ??1mmCullCity@@UAE@XZ
    ARTS_IMPORT ~mmCullCity() override;

    ARTS_ZEROED;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmCullCity@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@mmCullCity@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?GetClass@mmCullCity@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetHitId@mmCullCity@@QAEFAAVVector3@@@Z
    ARTS_IMPORT i16 GetHitId(Vector3& arg1);

    // ?GetRoomFlags@mmCullCity@@QAEFF@Z
    ARTS_IMPORT i16 GetRoomFlags(i16 arg1);

    // ?Init@mmCullCity@@QAEXPADPAVasCamera@@@Z
    ARTS_EXPORT void Init(char* name, asCamera* camera);

    // ?InitObjectDetail@mmCullCity@@QAEXXZ
    ARTS_IMPORT void InitObjectDetail();

    // ?IsPolyWater@mmCullCity@@QAEHPAVmmPolygon@@@Z
    ARTS_IMPORT i32 IsPolyWater(mmPolygon* arg1);

    // ?LoadBangers@mmCullCity@@QAEXPAD@Z
    ARTS_IMPORT void LoadBangers(char* arg1);

    // ?LoadFacades@mmCullCity@@QAEXPAD@Z
    ARTS_IMPORT void LoadFacades(char* arg1);

    // ?RelightEverything@mmCullCity@@QAEXXZ
    ARTS_IMPORT void RelightEverything();

    // ?ReparentObject@mmCullCity@@QAEXPAVmmInstance@@@Z
    ARTS_IMPORT void ReparentObject(mmInstance* inst);

    // ?Reset@mmCullCity@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?ToggleSky@mmCullCity@@QAEXXZ
    ARTS_IMPORT void ToggleSky();

    // ?Update@mmCullCity@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmCullCity@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?GetInstance@mmCullCity@@SAPAV1@XZ | inline
    ARTS_IMPORT static mmCullCity* GetInstance();

private:
    // ?AddInstance@mmCullCity@@AAEXHPAD0HPAVVector3@@11M@Z
    ARTS_IMPORT void AddInstance(
        i32 arg1, char* arg2, char* arg3, i32 arg4, Vector3* arg5, Vector3* arg6, Vector3* arg7, f32 arg8);

    // ?InitSnowTextures@mmCullCity@@AAEXXZ
    ARTS_IMPORT void InitSnowTextures();

    // ?InitTimeOfDayAndWeather@mmCullCity@@AAEXXZ
    ARTS_IMPORT void InitTimeOfDayAndWeather();

    // ?UpdateSnowTextures@mmCullCity@@AAEXXZ
    ARTS_IMPORT void UpdateSnowTextures();

    friend mmCullCity* CullCity();

    // ?Instance@mmCullCity@@0PAV1@A
    ARTS_IMPORT static mmCullCity* Instance;

public:
    asCamera* Camera;
    mmBoundTemplate* HitIdBound;
    mmBangerDataManager BangerDataManager;
    mmBangerActiveManager BangerActiveManager;
    mmBangerManager BangerManager;
    mmSky Sky;
    asRenderWeb RenderWeb;
    agiTexSorter TexSorter;
    mmInstChain BuildingChain;
    mmInstChain ObjectsChain;
    mmInstChain ShadowChain;
    asNode field_34AF0;
    i32 field_34B10;
    ConstString CityName;
    i32 SnowTextureCount;
    i32 CurrentSnowTexture;
    agiTexDef** SnowTexturesDst;
    agiTexDef** SnowTexturesSrc;
    i8* ShowTextureWidthRatios;
    i8* SnowTextureHeightRatios;
    f32 WeatherFriction;
    f32 RainFriction;
    f32 SnowFrictionStart;
    f32 SnowFrictionMin;
    f32 SnowFrictionTime;
    f32 SnowTotalElapsed;
    agiTexDef* ShadowMap;
    agiTexDef* SphereMap;
    Matrix34 EnvMatrix;
    asParticles Particles;
    asBirthRule* BirthRule;
    asBirthRule SnowBirthRule;
    asBirthRule RainBirthRule;
    i32 field_34D50;
    u32 SkyColor;
    b32 UseFogEnd2;
    f32 FogEnd;
    f32 FogEnd2;
    mmInstance* StartOfBangers;
    mmInstance* EndOfBangers;
};

check_size(mmCullCity, 0x34D6C);

inline mmCullCity* CullCity()
{
    return mmCullCity::Instance;
}

class mmUpperInstance final : public mmMatrixInstance
{
public:
    // ??_GmmUpperInstance@@UAEPAXI@Z
    // ??_EmmUpperInstance@@UAEPAXI@Z
    // ??1mmUpperInstance@@UAE@XZ | inline
    ARTS_EXPORT ~mmUpperInstance() override = default;

private:
    // ?Draw@mmUpperInstance@@EAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;
};

check_size(mmUpperInstance, 0x44);

class mmRunwayLight final : public mmInstance
{
public:
    // ??0mmRunwayLight@@QAE@PADAAVVector3@@1@Z
    ARTS_IMPORT mmRunwayLight(char* arg1, Vector3& arg2, Vector3& arg3);

    // ??_EmmRunwayLight@@UAEPAXI@Z
    // ??_GmmRunwayLight@@UAEPAXI@Z
    // ??1mmRunwayLight@@UAE@XZ | inline
    ARTS_EXPORT ~mmRunwayLight() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmRunwayLight@@UAEXPAVBank@@@Z | inline
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Draw@mmRunwayLight@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?FromMatrix@mmRunwayLight@@UAIXABVMatrix34@@@Z
    ARTS_EXPORT void ARTS_FASTCALL FromMatrix(const Matrix34& arg1) override;

    // ?GetPos@mmRunwayLight@@UAIAAVVector3@@XZ
    ARTS_IMPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?GetScale@mmRunwayLight@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // ?ToMatrix@mmRunwayLight@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) override;

    // ?Phase@mmRunwayLight@@2MA
    ARTS_IMPORT static f32 Phase;

    Vector3 Start;
    Vector3 End;
    Vector3 Step;
    Vector3 Center;
    f32 Scale;
    i32 NumLights;
    i32 Texture;
    agiMeshCardInfo MeshCard;
};

check_size(mmRunwayLight, 0x60);

// ?fix_clip@@YAXXZ
ARTS_IMPORT void fix_clip();

#ifdef ARTS_DEV_BUILD
// ?fix_fog@@YAXXZ
ARTS_IMPORT void fix_fog();
#endif

// ?fix_lighting@@YAXXZ
ARTS_IMPORT void fix_lighting();

#ifdef ARTS_DEV_BUILD
// ?fix_shadow@@YAXXZ
ARTS_IMPORT void fix_shadow();
#endif

// ?BoneScale@@3MA
ARTS_IMPORT extern f32 BoneScale;

// ?DisableUpper@@3HA
ARTS_IMPORT extern i32 DisableUpper;

// ?EnvVel@@3MA
ARTS_IMPORT extern f32 EnvVel;

// ?FadeConstant@@3MA
ARTS_IMPORT extern f32 FadeConstant;

// ?FadeScale@@3MA
ARTS_IMPORT extern f32 FadeScale;

// ?PlaneFudge@@3VVector3@@A
ARTS_IMPORT extern Vector3 PlaneFudge;

#ifdef ARTS_DEV_BUILD
// ?StaticLog@@3PAVStream@@A
ARTS_IMPORT extern Stream* StaticLog;
#endif

// ?UsePixelFog@@3HA
ARTS_IMPORT extern i32 UsePixelFog;

#ifdef ARTS_DEV_BUILD
// ?ambTriCount@@3HA
ARTS_IMPORT extern i32 ambTriCount;

// ?bangerTriCount@@3HA
ARTS_IMPORT extern i32 bangerTriCount;

// ?carTriCount@@3HA
ARTS_IMPORT extern i32 carTriCount;

// ?facadeTriCount@@3HA
ARTS_IMPORT extern i32 facadeTriCount;
#endif

struct t_mmEnvSetup
{
    const char* Sky;
    const char* SphereMap;
    const char* ShadowMap;
    f32 EnvVel;
    f32 SkyHeight;
    f32 FogEnd;
    u32 SkyColor;
    f32 field_1C;
    f32 field_20;
    f32 field_24;
};

check_size(t_mmEnvSetup, 0x28);

// ?mmEnvSetup@@3PAY03Ut_mmEnvSetup@@A
ARTS_IMPORT extern t_mmEnvSetup mmEnvSetup[4][4];

#ifdef ARTS_DEV_BUILD
// ?pedTriCount@@3HA
ARTS_IMPORT extern i32 pedTriCount;
#endif
