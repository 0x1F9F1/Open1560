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

define_dummy_symbol(mmgame_dash);

#include "dash.h"

#include "agi/dlptmpl.h"
#include "agi/getdlp.h"
#include "agi/rsys.h"
#include "agi/viewport.h"
#include "agiworld/getmesh.h"
#include "agiworld/meshset.h"
#include "agiworld/texsort.h"
#include "mmcity/cullcity.h"
#include "mmgame/player.h"

void mmExternalView::Reset()
{}

void mmExternalView::WideFOV(i32 /*arg1*/)
{}

// ?DashAlphaRef@@3HA
ARTS_IMPORT extern i32 DashAlphaRef;

// ?DashColorScale@@3MA
ARTS_IMPORT extern f32 DashColorScale;

// Gear variation (implement using tex-sheet siblings): N,1,2,3,4,5,6,7,8,R,P,D
#define DASH_GEAR_NEUTRAL 0
#define DASH_GEAR_1 1
#define DASH_GEAR_2 2
#define DASH_GEAR_3 3
#define DASH_GEAR_4 4
#define DASH_GEAR_5 5
#define DASH_GEAR_6 6
#define DASH_GEAR_7 7
#define DASH_GEAR_8 8
#define DASH_GEAR_REVERSE 9
#define DASH_GEAR_PARK 10
#define DASH_GEAR_DRIVE 11

void mmDashView::Init(char* name, mmPlayer* player)
{
    auto file = arts_formatf<128>("%s_dash", name);

    SetName(name);
    Load();
    Player = player;

    RPMGuage.Init(file, "TACH"_xconst, &player->Car.Sim.Engine.RPM, &MaxRPM, 800.0f);
    SpeedGuage.Init(file, "SPEED"_xconst, &Player->Speed, &MaxSpeed, MinSpeed);
    DamageGuage.Init(file, "DAMAGE"_xconst, &Player->Car.Sim.CurrentDamage, &Player->Car.Sim.MaxDamageScaled, 0.0f);

    Vector3 center {};

    if (auto dlp = GetDLPTemplate(file))
    {
        dlp->GetCentroid(center, "WHEEL"_xconst);
        dlp->Release();
    }

    WheelMesh = GetMeshSet(file, "WHEEL"_xconst, &center);
    DashMesh = GetMeshSet(file, "DASH"_xconst);
    RoofMesh = GetMeshSet(file, "ROOF"_xconst);
    GearMesh = GetMeshSet(file, "GEAR_INDICATOR"_xconst);

    DashCamOffset = Player->PovCam.Offset;
}

void mmDashView::Cull()
{
    auto alpha_ref = agiCurState.SetAlphaRef(static_cast<u8>(DashAlphaRef));
    auto zwrite = agiCurState.SetZWrite(false);
    auto zenable = agiCurState.SetZEnable(false);
    auto fog_mode = agiCurState.SetFogMode(agiFogMode::None);

    u32 color = 0xFFFFFFFF;

    if (CullCity()->GetRoomFlags(Player->Car.Model.ChainId) & (ROOM_FLAG_2 | ROOM_FLAG_8))
    {
        Vector3& pos = DashLCS.GetPosition();
        i32 scale = static_cast<i32>((pos.x + pos.z) * DashColorScale) & 31;
        color = 0xFF808080 + ((scale > 15) ? (31 - scale) : scale) * 0x080808;
    }

    agiViewport* vp = Viewport();

    vp->SetWorld(DashLCS.World);
    DashMesh->DrawColor(color, 1u);

    mmTransmission& trans = Player->Car.Sim.Trans;

    i32 gear = trans.GetCurrentGear();

    if (trans.InPark)
        gear = DASH_GEAR_PARK;
    else if (gear == -1)
        gear = DASH_GEAR_REVERSE;
    else if (trans.IsAutomatic && (gear != DASH_GEAR_NEUTRAL))
        gear = DASH_GEAR_DRIVE;

    GearMesh->Draw(MESH_DRAW_CLIP | MESH_DRAW_VARIANT(gear));

    if (RoofMesh)
    {
        vp->SetWorld(RoofLCS.World);
        RoofMesh->DrawColor(color, MESH_DRAW_CLIP);
    }

    SpeedGuage.Cull();
    RPMGuage.Cull();
    DamageGuage.Cull();

    vp->SetWorld(WheelLCS.World);
    WheelMesh->DrawColor(color, MESH_DRAW_CLIP);

    TexSorter()->Cull(true);

    agiCurState.SetAlphaRef(alpha_ref);
    agiCurState.SetZWrite(zwrite);
    agiCurState.SetZEnable(zenable);
    agiCurState.SetFogMode(fog_mode);
}
