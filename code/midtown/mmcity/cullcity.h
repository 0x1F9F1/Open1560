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
    mmcity:cullcity

    0x48BB90 | public: __thiscall mmCullCity::mmCullCity(void) | ??0mmCullCity@@QAE@XZ
    0x48BD70 | public: virtual __thiscall mmCullCity::~mmCullCity(void) | ??1mmCullCity@@UAE@XZ
    0x48BF10 | public: short __thiscall mmCullCity::GetHitId(class Vector3 &) | ?GetHitId@mmCullCity@@QAEFAAVVector3@@@Z
    0x48BF40 | private: virtual void __fastcall mmUpperInstance::Draw(int) | ?Draw@mmUpperInstance@@EAIXH@Z
    0x48BFA0 | public: __thiscall mmRunwayLight::mmRunwayLight(char *,class Vector3 &,class Vector3 &) | ??0mmRunwayLight@@QAE@PADAAVVector3@@1@Z
    0x48C160 | public: virtual class Vector3 & __fastcall mmRunwayLight::GetPos(void) | ?GetPos@mmRunwayLight@@UAIAAVVector3@@XZ
    0x48C170 | public: virtual void __fastcall mmRunwayLight::FromMatrix(class Matrix34 const &) | ?FromMatrix@mmRunwayLight@@UAIXABVMatrix34@@@Z
    0x48C180 | public: virtual class Matrix34 & __fastcall mmRunwayLight::ToMatrix(class Matrix34 &) | ?ToMatrix@mmRunwayLight@@UAIAAVMatrix34@@AAV2@@Z
    0x48C1B0 | public: virtual void __fastcall mmRunwayLight::Draw(int) | ?Draw@mmRunwayLight@@UAIXH@Z
    0x48C2B0 | public: virtual float __fastcall mmRunwayLight::GetScale(void) | ?GetScale@mmRunwayLight@@UAIMXZ
    0x48C2C0 | private: void __thiscall mmCullCity::AddInstance(int,char *,char *,int,class Vector3 *,class Vector3 *,class Vector3 *,float) | ?AddInstance@mmCullCity@@AAEXHPAD0HPAVVector3@@11M@Z
    0x48C640 | public: void __thiscall mmCullCity::ReparentObject(class mmInstance *) | ?ReparentObject@mmCullCity@@QAEXPAVmmInstance@@@Z
    0x48C6D0 | public: void __thiscall mmCullCity::Init(char *,class asCamera *) | ?Init@mmCullCity@@QAEXPADPAVasCamera@@@Z
    0x48CDD0 | public: virtual void __thiscall mmCullCity::Reset(void) | ?Reset@mmCullCity@@UAEXXZ
    0x48CEA0 | public: void __thiscall mmCullCity::InitObjectDetail(void) | ?InitObjectDetail@mmCullCity@@QAEXXZ
    0x48CED0 | public: void __thiscall mmCullCity::LoadBangers(char *) | ?LoadBangers@mmCullCity@@QAEXPAD@Z
    0x48CFF0 | public: void __thiscall mmCullCity::LoadFacades(char *) | ?LoadFacades@mmCullCity@@QAEXPAD@Z
    0x48D100 | private: void __thiscall mmCullCity::InitSnowTextures(void) | ?InitSnowTextures@mmCullCity@@AAEXXZ
    0x48D2F0 | private: void __thiscall mmCullCity::UpdateSnowTextures(void) | ?UpdateSnowTextures@mmCullCity@@AAEXXZ
    0x48D590 | public: int __thiscall mmCullCity::IsPolyWater(class mmPolygon *) | ?IsPolyWater@mmCullCity@@QAEHPAVmmPolygon@@@Z
    0x48D5D0 | public: virtual void __thiscall mmCullCity::Update(void) | ?Update@mmCullCity@@UAEXXZ
    0x48D820 | public: virtual void __thiscall mmCullCity::Cull(void) | ?Cull@mmCullCity@@UAEXXZ
    0x48D950 | public: void __thiscall mmCullCity::ToggleSky(void) | ?ToggleSky@mmCullCity@@QAEXXZ
    0x48D960 | public: short __thiscall mmCullCity::GetRoomFlags(short) | ?GetRoomFlags@mmCullCity@@QAEFF@Z
    0x48D9A0 | public: void __thiscall mmCullCity::RelightEverything(void) | ?RelightEverything@mmCullCity@@QAEXXZ
    0x48DA00 | void __cdecl fix_clip(void) | ?fix_clip@@YAXXZ
    0x48DA70 | void __cdecl fix_lighting(void) | ?fix_lighting@@YAXXZ
    0x48DB10 | private: void __thiscall mmCullCity::InitTimeOfDayAndWeather(void) | ?InitTimeOfDayAndWeather@mmCullCity@@AAEXXZ
    0x48E450 | void __cdecl fix_fog(void) | ?fix_fog@@YAXXZ
    0x48E480 | void __cdecl fix_shadow(void) | ?fix_shadow@@YAXXZ
    0x48E4B0 | public: virtual void __thiscall mmCullCity::AddWidgets(class Bank *) | ?AddWidgets@mmCullCity@@UAEXPAVBank@@@Z
    0x48F8C0 | public: static void __cdecl mmCullCity::DeclareFields(void) | ?DeclareFields@mmCullCity@@SAXXZ
    0x48FA30 | public: virtual class MetaClass * __thiscall mmCullCity::GetClass(void) | ?GetClass@mmCullCity@@UAEPAVMetaClass@@XZ
    0x48FA40 | public: virtual void __thiscall mmRunwayLight::AddWidgets(class Bank *) | ?AddWidgets@mmRunwayLight@@UAEXPAVBank@@@Z
    0x48FA50 | public: virtual void * __thiscall mmRunwayLight::`scalar deleting destructor'(unsigned int) | ??_GmmRunwayLight@@UAEPAXI@Z
    0x48FA50 | public: virtual void * __thiscall mmRunwayLight::`vector deleting destructor'(unsigned int) | ??_EmmRunwayLight@@UAEPAXI@Z
    0x48FA70 | public: virtual __thiscall mmRunwayLight::~mmRunwayLight(void) | ??1mmRunwayLight@@UAE@XZ
    0x48FA80 | public: virtual void * __thiscall mmUpperInstance::`vector deleting destructor'(unsigned int) | ??_EmmUpperInstance@@UAEPAXI@Z
    0x48FA80 | public: virtual void * __thiscall mmUpperInstance::`scalar deleting destructor'(unsigned int) | ??_GmmUpperInstance@@UAEPAXI@Z
    0x48FAA0 | public: virtual __thiscall mmUpperInstance::~mmUpperInstance(void) | ??1mmUpperInstance@@UAE@XZ
    0x48FAB0 | public: virtual void * __thiscall mmCullCity::`vector deleting destructor'(unsigned int) | ??_EmmCullCity@@UAEPAXI@Z
    0x48FB10 | public: int __thiscall agiLib<class agiTexParameters,class agiTexDef>::Add(class agiTexParameters &) | ?Add@?$agiLib@VagiTexParameters@@VagiTexDef@@@@QAEHAAVagiTexParameters@@@Z
    0x48FBF0 | public: virtual void * __thiscall mmShearInstance::`scalar deleting destructor'(unsigned int) | ??_GmmShearInstance@@UAEPAXI@Z
    0x48FC10 | public: virtual __thiscall mmShearInstance::~mmShearInstance(void) | ??1mmShearInstance@@UAE@XZ
    0x48FC20 | public: virtual void * __thiscall mmBuildingInstance::`scalar deleting destructor'(unsigned int) | ??_GmmBuildingInstance@@UAEPAXI@Z
    0x48FC40 | public: virtual __thiscall mmBuildingInstance::~mmBuildingInstance(void) | ??1mmBuildingInstance@@UAE@XZ
    0x48FC50 | public: virtual void * __thiscall mmUnhitBangerInstance::`vector deleting destructor'(unsigned int) | ??_EmmUnhitBangerInstance@@UAEPAXI@Z
    0x48FC50 | public: virtual void * __thiscall mmUnhitBangerInstance::`scalar deleting destructor'(unsigned int) | ??_GmmUnhitBangerInstance@@UAEPAXI@Z
    0x48FC70 | public: virtual __thiscall mmUnhitBangerInstance::~mmUnhitBangerInstance(void) | ??1mmUnhitBangerInstance@@UAE@XZ
    0x48FC80 | public: virtual void * __thiscall mmBangerManager::`vector deleting destructor'(unsigned int) | ??_EmmBangerManager@@UAEPAXI@Z
    0x48FC80 | public: virtual void * __thiscall mmBangerManager::`scalar deleting destructor'(unsigned int) | ??_GmmBangerManager@@UAEPAXI@Z
    0x48FCB0 | public: virtual __thiscall mmBangerManager::~mmBangerManager(void) | ??1mmBangerManager@@UAE@XZ
    0x61CCD8 | const mmCullCity::`vftable' | ??_7mmCullCity@@6B@
    0x61CD18 | const mmBangerManager::`vftable' | ??_7mmBangerManager@@6B@
    0x61CD58 | const mmRunwayLight::`vftable' | ??_7mmRunwayLight@@6B@
    0x61CDB8 | const mmUpperInstance::`vftable' | ??_7mmUpperInstance@@6B@
    0x61CE18 | const mmBuildingInstance::`vftable' | ??_7mmBuildingInstance@@6B@
    0x61CE78 | const mmShearInstance::`vftable' | ??_7mmShearInstance@@6B@
    0x61CED8 | const mmUnhitBangerInstance::`vftable' | ??_7mmUnhitBangerInstance@@6B@
    0x63E260 | struct t_mmEnvSetup (* mmEnvSetup)[4] | ?mmEnvSetup@@3PAY03Ut_mmEnvSetup@@A
    0x63E4E4 | float BoneScale | ?BoneScale@@3MA
    0x6A8DCC | int facadeTriCount | ?facadeTriCount@@3HA
    0x6A8DD0 | float EnvVel | ?EnvVel@@3MA
    0x6A8DDC | int ambTriCount | ?ambTriCount@@3HA
    0x6A8DE0 | int carTriCount | ?carTriCount@@3HA
    0x6A8DE4 | int bangerTriCount | ?bangerTriCount@@3HA
    0x6A8E20 | int UsePixelFog | ?UsePixelFog@@3HA
    0x6A8E24 | int pedTriCount | ?pedTriCount@@3HA
    0x6A8E28 | private: static class mmCullCity * mmCullCity::Instance | ?Instance@mmCullCity@@0PAV1@A
    0x6A8E30 | class Vector3 PlaneFudge | ?PlaneFudge@@3VVector3@@A
    0x6A8E40 | class MetaClass mmCullCityMetaClass | ?mmCullCityMetaClass@@3VMetaClass@@A
    0x6A8E68 | float FadeConstant | ?FadeConstant@@3MA
    0x6A8E70 | class Stream * StaticLog | ?StaticLog@@3PAVStream@@A
    0x6A8E74 | public: static float mmRunwayLight::Phase | ?Phase@mmRunwayLight@@2MA
    0x6A8E78 | float FadeScale | ?FadeScale@@3MA
    0x6A8E7C | int DisableUpper | ?DisableUpper@@3HA
    0x48E1B0 | void __cdecl fix_sun(void) | ?fix_sun@@YAXXZ
    0x48E220 | void __cdecl fix_fill1(void) | ?fix_fill1@@YAXXZ
    0x48E290 | void __cdecl fix_fill2(void) | ?fix_fill2@@YAXXZ
    0x48E300 | void __cdecl parseFloat(float &) | ?parseFloat@@YAXAAM@Z
    0x48E330 | void __cdecl parseVector3(class Vector3 &) | ?parseVector3@@YAXAAVVector3@@@Z
    0x48E360 | void __cdecl parseRGB(unsigned int &) | ?parseRGB@@YAXAAI@Z
    0x48E3D0 | void __cdecl parseARGB(unsigned int &) | ?parseARGB@@YAXAAI@Z
*/

#include "arts7/node.h"
#include "inst.h"

class mmCullCity : public asNode
{
    // const mmCullCity::`vftable' @ 0x61CCD8

public:
    // 0x48BB90 | ??0mmCullCity@@QAE@XZ
    mmCullCity();

    // 0x48FAB0 | ??_EmmCullCity@@UAEPAXI@Z
    // 0x48BD70 | ??1mmCullCity@@UAE@XZ
    ~mmCullCity() override;

    // 0x48E4B0 | ?AddWidgets@mmCullCity@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x48D820 | ?Cull@mmCullCity@@UAEXXZ
    void Cull() override;

    // 0x48FA30 | ?GetClass@mmCullCity@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x48BF10 | ?GetHitId@mmCullCity@@QAEFAAVVector3@@@Z
    i16 GetHitId(class Vector3& arg1);

    // 0x48D960 | ?GetRoomFlags@mmCullCity@@QAEFF@Z
    i16 GetRoomFlags(i16 arg1);

    // 0x48C6D0 | ?Init@mmCullCity@@QAEXPADPAVasCamera@@@Z
    void Init(char* arg1, class asCamera* arg2);

    // 0x48CEA0 | ?InitObjectDetail@mmCullCity@@QAEXXZ
    void InitObjectDetail();

    // 0x48D590 | ?IsPolyWater@mmCullCity@@QAEHPAVmmPolygon@@@Z
    i32 IsPolyWater(class mmPolygon* arg1);

    // 0x48CED0 | ?LoadBangers@mmCullCity@@QAEXPAD@Z
    void LoadBangers(char* arg1);

    // 0x48CFF0 | ?LoadFacades@mmCullCity@@QAEXPAD@Z
    void LoadFacades(char* arg1);

    // 0x48D9A0 | ?RelightEverything@mmCullCity@@QAEXXZ
    void RelightEverything();

    // 0x48C640 | ?ReparentObject@mmCullCity@@QAEXPAVmmInstance@@@Z
    void ReparentObject(class mmInstance* arg1);

    // 0x48CDD0 | ?Reset@mmCullCity@@UAEXXZ
    void Reset() override;

    // 0x48D950 | ?ToggleSky@mmCullCity@@QAEXXZ
    void ToggleSky();

    // 0x48D5D0 | ?Update@mmCullCity@@UAEXXZ
    void Update() override;

    // 0x48F8C0 | ?DeclareFields@mmCullCity@@SAXXZ
    static void DeclareFields();

    // 0x4A9F40 | ?GetInstance@mmCullCity@@SAPAV1@XZ | inline
    static class mmCullCity* GetInstance();

private:
    // 0x48C2C0 | ?AddInstance@mmCullCity@@AAEXHPAD0HPAVVector3@@11M@Z
    void AddInstance(i32 arg1, char* arg2, char* arg3, i32 arg4, class Vector3* arg5, class Vector3* arg6,
        class Vector3* arg7, f32 arg8);

    // 0x48D100 | ?InitSnowTextures@mmCullCity@@AAEXXZ
    void InitSnowTextures();

    // 0x48DB10 | ?InitTimeOfDayAndWeather@mmCullCity@@AAEXXZ
    void InitTimeOfDayAndWeather();

    // 0x48D2F0 | ?UpdateSnowTextures@mmCullCity@@AAEXXZ
    void UpdateSnowTextures();

    // 0x6A8E28 | ?Instance@mmCullCity@@0PAV1@A
    static inline extern_var(0x6A8E28, class mmCullCity*, Instance);
};

check_size(mmCullCity, 0x34D6C);

class mmUpperInstance : public mmMatrixInstance
{
    // const mmUpperInstance::`vftable' @ 0x61CDB8

public:
    // 0x48FA80 | ??_GmmUpperInstance@@UAEPAXI@Z
    // 0x48FAA0 | ??1mmUpperInstance@@UAE@XZ
    ~mmUpperInstance() override;

private:
    // 0x48BF40 | ?Draw@mmUpperInstance@@EAIXH@Z
    void __fastcall Draw(i32 arg1) override;
};

check_size(mmUpperInstance, 0x0);

class mmRunwayLight : public mmInstance
{
    // const mmRunwayLight::`vftable' @ 0x61CD58

public:
    // 0x48BFA0 | ??0mmRunwayLight@@QAE@PADAAVVector3@@1@Z
    mmRunwayLight(char* arg1, class Vector3& arg2, class Vector3& arg3);

    // 0x48FA50 | ??_EmmRunwayLight@@UAEPAXI@Z
    // 0x48FA70 | ??1mmRunwayLight@@UAE@XZ
    ~mmRunwayLight() override;

    // 0x48FA40 | ?AddWidgets@mmRunwayLight@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x48C1B0 | ?Draw@mmRunwayLight@@UAIXH@Z
    void __fastcall Draw(i32 arg1) override;

    // 0x48C170 | ?FromMatrix@mmRunwayLight@@UAIXABVMatrix34@@@Z
    void __fastcall FromMatrix(class Matrix34 const& arg1) override;

    // 0x48C160 | ?GetPos@mmRunwayLight@@UAIAAVVector3@@XZ
    class Vector3& __fastcall GetPos() override;

    // 0x48C2B0 | ?GetScale@mmRunwayLight@@UAIMXZ
    f32 __fastcall GetScale() override;

    // 0x48C180 | ?ToMatrix@mmRunwayLight@@UAIAAVMatrix34@@AAV2@@Z
    class Matrix34& __fastcall ToMatrix(class Matrix34& arg1) override;

    // 0x6A8E74 | ?Phase@mmRunwayLight@@2MA
    static inline extern_var(0x6A8E74, f32, Phase);
};

check_size(mmRunwayLight, 0x0);

// 0x48DA00 | ?fix_clip@@YAXXZ
void fix_clip();

// 0x48E450 | ?fix_fog@@YAXXZ
void fix_fog();

// 0x48DA70 | ?fix_lighting@@YAXXZ
void fix_lighting();

// 0x48E480 | ?fix_shadow@@YAXXZ
void fix_shadow();

// 0x63E4E4 | ?BoneScale@@3MA
inline extern_var(0x63E4E4, f32, BoneScale);

// 0x6A8E7C | ?DisableUpper@@3HA
inline extern_var(0x6A8E7C, i32, DisableUpper);

// 0x6A8DD0 | ?EnvVel@@3MA
inline extern_var(0x6A8DD0, f32, EnvVel);

// 0x6A8E68 | ?FadeConstant@@3MA
inline extern_var(0x6A8E68, f32, FadeConstant);

// 0x6A8E78 | ?FadeScale@@3MA
inline extern_var(0x6A8E78, f32, FadeScale);

// 0x6A8E30 | ?PlaneFudge@@3VVector3@@A
inline extern_var(0x6A8E30, class Vector3, PlaneFudge);

// 0x6A8E70 | ?StaticLog@@3PAVStream@@A
inline extern_var(0x6A8E70, class Stream*, StaticLog);

// 0x6A8E20 | ?UsePixelFog@@3HA
inline extern_var(0x6A8E20, i32, UsePixelFog);

// 0x6A8DDC | ?ambTriCount@@3HA
inline extern_var(0x6A8DDC, i32, ambTriCount);

// 0x6A8DE4 | ?bangerTriCount@@3HA
inline extern_var(0x6A8DE4, i32, bangerTriCount);

// 0x6A8DE0 | ?carTriCount@@3HA
inline extern_var(0x6A8DE0, i32, carTriCount);

// 0x6A8DCC | ?facadeTriCount@@3HA
inline extern_var(0x6A8DCC, i32, facadeTriCount);

// 0x6A8E40 | ?mmCullCityMetaClass@@3VMetaClass@@A
inline extern_var(0x6A8E40, class MetaClass, mmCullCityMetaClass);

// 0x63E260 | ?mmEnvSetup@@3PAY03Ut_mmEnvSetup@@A
inline extern_var(0x63E260, struct t_mmEnvSetup (*)[4], mmEnvSetup);

// 0x6A8E24 | ?pedTriCount@@3HA
inline extern_var(0x6A8E24, i32, pedTriCount);

class mmBangerManager : public asNode
{
    // const mmBangerManager::`vftable' @ 0x61CD18

public:
    // 0x48FC80 | ??_GmmBangerManager@@UAEPAXI@Z
    // 0x48FCB0 | ??1mmBangerManager@@UAE@XZ
    ~mmBangerManager() override;

    // 0x4CAC70 | ?GetBanger@mmBangerManager@@QAEPAVmmHitBangerInstance@@XZ | inline
    class mmHitBangerInstance* GetBanger();

    // 0x4CACD0 | ?Init@mmBangerManager@@QAEXH@Z | inline
    void Init(i32 arg1);

    // 0x4CAD90 | ?Reset@mmBangerManager@@UAEXXZ | inline
    void Reset() override;

protected:
    // 0x706048 | ?Instance@mmBangerManager@@1PAV1@A | inline
    static inline extern_var(0x706048, class mmBangerManager*, Instance);
};

check_size(mmBangerManager, 0x0);
