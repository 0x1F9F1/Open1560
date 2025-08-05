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

define_dummy_symbol(mmcity_cullcity);

#include "cullcity.h"

#include "agi/dlptmpl.h"
#include "agi/getdlp.h"
#include "agi/rsys.h"
#include "agisw/swrend.h"
#include "agiworld/getmesh.h"
#include "agiworld/meshlight.h"
#include "agiworld/meshset.h"
#include "agiworld/quality.h"
#include "agiworld/texsheet.h"
#include "arts7/cullmgr.h"
#include "data7/memstat.h"
#include "localize/localize.h"
#include "mmcityinfo/state.h"
#include "mmdyna/bndtmpl.h"
#include "mmphysics/phys.h"
#include "stream/problems.h"
#include "stream/stream.h"

#include "loader.h"

static constexpr i32 MAX_BANGERS = 40;
static constexpr i32 MAX_PARTICLES = 100;
static constexpr i32 CHICAGO_CELLID_RUNWAY = 35;

#ifdef ARTS_DEV_BUILD
void mmRunwayLight::AddWidgets(Bank* /*arg1*/)
{}
#endif

void ARTS_FASTCALL mmRunwayLight::FromMatrix(const Matrix34& /*arg1*/)
{}

// ?fix_fill1@@YAXXZ
ARTS_IMPORT /*static*/ void fix_fill1();

// ?fix_fill2@@YAXXZ
ARTS_IMPORT /*static*/ void fix_fill2();

// ?fix_sun@@YAXXZ
ARTS_IMPORT /*static*/ void fix_sun();

// ?parseARGB@@YAXAAI@Z
ARTS_IMPORT /*static*/ void parseARGB(u32& arg1);

// ?parseFloat@@YAXAAM@Z
ARTS_IMPORT /*static*/ void parseFloat(f32& arg1);

// ?parseRGB@@YAXAAI@Z
ARTS_IMPORT /*static*/ void parseRGB(u32& arg1);

// ?parseVector3@@YAXAAVVector3@@@Z
ARTS_IMPORT /*static*/ void parseVector3(Vector3& arg1);

// ?ShowRenderStats@@YAXXZ
ARTS_IMPORT /*static*/ void ShowRenderStats();

void mmCullCity::Cull()
{
    if (FogEnd == 0.0f || agiCurState.GetDrawMode() == agiDrawDepth)
    {
        agiCurState.SetFogMode(agiFogMode::None);
        agiMeshSet::SetFog(0.0, 0);
    }
    else
    {
        agiCurState.SetFogMode(UsePixelFog ? agiFogMode::Pixel : agiFogMode::Vertex);
        agiCurState.SetFogColor(SkyColor | swIsInterlaced);

        if (!agiCurState.GetSoftwareRendering())
            FogEnd = std::min(FogEnd, agiRQ.FarClip);

        if (UsePixelFog)
        {
            agiMeshSet::SetFog(0.0f, 0);
            agiCurState.SetFogStart(1.0f);
            agiCurState.SetFogEnd(FogEnd);
        }
        else if (UseFogEnd2)
        {
            agiMeshSet::SetFog(FogEnd2, UseFogEnd2);
        }
        else
        {
            agiMeshSet::SetFog(FogEnd, 0);
        }
    }
}

static agiMeshCardVertex RainMeshCard[4] {
    {-0.1f, 2.0f, 0.4f, 1.0f},
    {-0.1f, -2.0f, 0.4f, 0.0f},
    {0.1f, -2.0f, 0.6f, 0.0f},
    {0.1f, 2.0f, 0.6f, 1.0f},
};

void mmCullCity::Init(char* name, asCamera* camera)
{
    IsSnowing = MMSTATE.Weather == mmWeather::Snow;
    CityName = name;

    TEXSHEET.SetUseAlternate((MMSTATE.TimeOfDay == mmTimeOfDay::Sunset) || (MMSTATE.TimeOfDay == mmTimeOfDay::Night));

    switch (MMSTATE.Weather)
    {
        case mmWeather::Rain: TextureSuffix = "_fall"_xconst; break;
        case mmWeather::Snow: TextureSuffix = "_win"_xconst; break;
        default: TextureSuffix = nullptr; break;
    }

    StaticLog = arts_fopen(arts_formatf<64>("%s_static.csv", name), "w");

    Loader()->BeginTask(LOC_STRING(MM_IDS_LOADING_CITY_LAYOUT));

    DLPTemplate* city_dlp = nullptr;
    DLPTemplate* lm_dlp = nullptr;

    if (DevelopmentMode)
    {
        city_dlp = GetDLPTemplate(arts_formatf<128>("%scity", name));
        lm_dlp = GetDLPTemplate(arts_formatf<128>("%slm", name));
    }

    ARTS_MEM_STAT("mmCullCity::Init");

    InitProblems();

    Camera = camera;
    AddChild(&BangerDataManager);
    AddChild(&BangerActiveManager);
    AddChild(&BangerManager);
    AddChild(&field_34AF0);
    AddChild(&PHYS);
    AddChild(&RenderWeb);
    AddChild(&Particles);

    Particles.Init(
        MAX_PARTICLES, 4, 4, 4, (MMSTATE.Weather == mmWeather::Rain) ? RainMeshCard : agiMeshSet::DefaultQuad);

    SnowBirthRule.SetName("SnowRule");
    AddChild(&SnowBirthRule);
    SnowBirthRule.Load();

    RainBirthRule.SetName("RainRule");
    AddChild(&RainBirthRule);
    RainBirthRule.Load();

    BirthRule = nullptr;

    Sky.Init("mmsky"_xconst);
    Loader()->EndTask();

    {
        ARTS_MEM_STAT("mmCullCity.WEB");
        RenderWeb.Load(name, 1);
    }

    HitIdBound = RenderWeb.HitIdBound;
    HitIdBound->AddRef();

    BuildingChain.Init(RenderWeb.MaxCells);
    ObjectsChain.Init(RenderWeb.MaxCells);
    ShadowChain.Init(RenderWeb.MaxCells);

    InitObjectDetail();

    StartOfBangers = static_cast<mmInstance*>(mmInstanceHeap.GetHead());

    LoadBangers(name);

    switch (MMSTATE.GameMode)
    {
        case mmGameMode::Cruise: LoadBangers(arts_formatf<64>("%s_roam", name)); break;
        case mmGameMode::Checkpoint: LoadBangers(arts_formatf<64>("%s_r%d", name, MMSTATE.EventId)); break;
        case mmGameMode::CnR: LoadBangers(arts_formatf<64>("%s_cops", name)); break;
        case mmGameMode::Circuit: LoadBangers(arts_formatf<64>("%s_c%d", name, MMSTATE.EventId)); break;
        case mmGameMode::Blitz: LoadBangers(arts_formatf<64>("%s_b%d", name, MMSTATE.EventId)); break;
    }

    EndOfBangers = new mmYInstance();

    LoadFacades(name);

    EnableSphereCull = CHICAGO;

    if (CHICAGO)
    {
        Vector3 pos_1 = {995.782, 0.173, 1188.804};
        Vector3 pos_2 = {995.782, 0.173, 742.411};
        Vector3 pos_3 = {1015.383, 0.173, 1188.805};
        Vector3 pos_4 = {1015.383, 0.173, 742.411};

        BuildingChain.Parent(new mmRunwayLight("fxltglow"_xconst, pos_1, pos_2), CHICAGO_CELLID_RUNWAY);
        BuildingChain.Parent(new mmRunwayLight("fxltglow"_xconst, pos_3, pos_4), CHICAGO_CELLID_RUNWAY);
    }

    InitTimeOfDayAndWeather();

    if (IsSnowing)
        InitSnowTextures();

    BangerMgr()->Init(MAX_BANGERS);

    if (city_dlp && city_dlp->Release())
        Errorf("Someone is still holding a ref on the city's template");

    if (lm_dlp)
        lm_dlp->Release();

    CullMgr()->AddPage(ShowRenderStats);

    if (StaticLog)
    {
        delete StaticLog;
    }
}

static mem::cmd_param PARAM_conelighter {"conelighter", "Use agiConeLighter"};

void fix_lighting()
{
    if (PARAM_conelighter)
    {
        mmInstance::DynamicLighter = agiConeLighter;
        mmInstance::StaticLighter = agiConeLighter;
        return;
    }

    switch (agiRQ.LightQuality)
    {
        case AGI_QUALITY_LOW:
            mmInstance::StaticLighter = nullptr;
            mmInstance::DynamicLighter = nullptr;
            break;
        case AGI_QUALITY_MEDIUM:
            mmInstance::DynamicLighter = agiMeshLighterQuarter;
            mmInstance::StaticLighter = agiMeshLighterQuarter;
            break;
        case AGI_QUALITY_HIGH:
            mmInstance::DynamicLighter = agiMeshLighterQuarter;
            mmInstance::StaticLighter = agiMeshLighterTriple;
            break;
        case AGI_QUALITY_VERY_HIGH:
            mmInstance::DynamicLighter = agiMeshLighterTriple;
            mmInstance::StaticLighter = agiMeshLighterTriple;
            break;

        default: Quitf("agiRQ.LightQuality = %d", agiRQ.LightQuality);
    }

    if (agiCurState.GetSoftwareRendering())
        mmInstance::StaticLighter = nullptr;
}