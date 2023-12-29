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
    char city_path[64];
    char lm_path[64];

    IsSnowing = (MMSTATE.Weather == mmWeather::Snow);
    CityName = arts_strdup(name);

    arts_strcpy(city_path, name);
    arts_strcat(city_path, "city");

    arts_strcpy(lm_path, name);
    arts_strcat(lm_path, "lm");

    TEXSHEET.allow_remapping_ = (MMSTATE.TimeOfDay == mmTimeOfDay::Sunset || MMSTATE.TimeOfDay == mmTimeOfDay::Night);

    switch (MMSTATE.Weather)
    {
        case mmWeather::Rain: TextureSuffix = "_fall"_xconst; break;
        case mmWeather::Snow: TextureSuffix = "_win"_xconst; break;
        default: TextureSuffix = nullptr; break;
    }

    StaticLog = arts_fopen(arts_formatf<64>("%s_static.csv", name), "w");

    Loader()->BeginTask(LOC_STRING(MM_IDS_LOADING_CITY_LAYOUT), 0.0f);

    DLPTemplate* city_dlp = nullptr;
    DLPTemplate* lm_dlp = nullptr;

    if (DevelopmentMode)
    {
        city_dlp = GetDLPTemplate(city_path);
        // if (!city_dlp)
        //     Quitf("Unable to load city '%s'", name);

        lm_dlp = GetDLPTemplate(lm_path);
    }

    BeginMemStat("mmCullCity::Init");
    InitProblems();

    Camera = camera;
    AddChild(&BangerDataManager);
    AddChild(&BangerActiveManager);
    AddChild(&BangerManager);
    AddChild(&asnode34AF0);
    AddChild(&PHYS);
    AddChild(&RenderWeb);
    AddChild(&Particles);

    agiMeshCardVertex* vertex = NULL;

    if (MMSTATE.Weather == mmWeather::Rain)
        vertex = RainMeshCard;
    else
        vertex = agiMeshSet::DefaultQuad;

    Particles.Init(100, 4, 4, 4, vertex);

    SnowBirthRule.SetName("SnowRule");
    AddChild(&SnowBirthRule);
    SnowBirthRule.Load();

    RainBirthRule.SetName("RainRule");
    AddChild(&RainBirthRule);
    RainBirthRule.Load();

    BirthRule = 0;

    Sky.Init("mmsky"_xconst);
    Loader()->EndTask(0.0f);

    BeginMemStat("mmCullCity.WEB");
    RenderWeb.Load(name, 1);
    EndMemStat();

    HitIdBound = RenderWeb.HitIdBound;
    HitIdBound->AddRef();

    BuildingChain.Init(RenderWeb.MaxCells);
    ObjectsChain.Init(RenderWeb.MaxCells);
    ShadowChain.Init(RenderWeb.MaxCells);

    InitObjectDetail();

    LastInstance = (mmInstance*) mmInstanceHeap.HeapHead;
    ResetInst = new mmYInstance();

    EnableSphereCull = CHICAGO;

    LoadBangers(name);

    switch (MMSTATE.GameMode)
    {
        case mmGameMode::Cruise: LoadBangers(arts_formatf<64>("%s_roam", name)); break;
        case mmGameMode::Checkpoint: LoadBangers(arts_formatf<64>("%s_r%d", name, MMSTATE.EventId)); break;
        case mmGameMode::CnR: LoadBangers(arts_formatf<64>("%s_cops", name)); break;
        case mmGameMode::Circuit: LoadBangers(arts_formatf<64>("%s_c%d", name, MMSTATE.EventId)); break;
        case mmGameMode::Blitz: LoadBangers(arts_formatf<64>("%s_b%d", name, MMSTATE.EventId)); break;
    }

    ResetInst = new mmYInstance();

    LoadFacades(name);

    if (CHICAGO)
    {
        Vector3 pos_1 = {995.782, 0.173, 1188.804};
        Vector3 pos_2 = {995.782, 0.173, 742.411};
        Vector3 pos_3 = {1015.383, 0.173, 1188.805};
        Vector3 pos_4 = {1015.383, 0.173, 742.411};

        mmRunwayLight* light_1 = new mmRunwayLight("fxltglow"_xconst, pos_1, pos_2);
        mmRunwayLight* light_2 = new mmRunwayLight("fxltglow"_xconst, pos_3, pos_4);

        BuildingChain.Parent(light_1, 35);
        BuildingChain.Parent(light_2, 35);
    }

    InitTimeOfDayAndWeather();

    if (IsSnowing)
        InitSnowTextures();

    BangerMgr()->Init(40);

    if (city_dlp && city_dlp->Release())
        Errorf("Someone is still holding a ref on the city's template");

    if (lm_dlp)
        lm_dlp->Release();

    EndMemStat();

    CULLMGR->AddPage(ShowRenderStats);

    if (StaticLog)
    {
        delete StaticLog;
    }
}
