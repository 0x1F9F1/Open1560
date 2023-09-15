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

define_dummy_symbol(mmcar_car);

#include "car.h"

#include "agi/dlptmpl.h"
#include "agi/getdlp.h"
#include "data7/timer.h"
#include "mmcity/cullcity.h"
#include "mmcityinfo/vehlist.h"
#include "mmphysics/joint3dof.h"
#include "patches.cpp"

#include "playercaraudio.h"
#include "trailer.h"

mmCar::mmCar()
{
    // FIXME: mmCar is already oversampled by mmPhysicsMGR
    AddChild(&OverSample);
    OverSample.AddChild(&Sim);
    OverSample.RealTime(35.0f);

    AddChild(&FLSkid);
    AddChild(&FRSkid);
    AddChild(&BLSkid);
    AddChild(&BRSkid);
}

void mmCar::TranslateFlags(i32 info_flags)
{
    u32 flags = CAR_FLAG_ACTIVE;

    flags |= (info_flags & VEH_INFO_FLAG_6_WHEELS) ? CAR_FLAG_6_WHEELS : 0;
    flags |= (info_flags & VEH_INFO_FLAG_TRAILER) ? CAR_FLAG_TRAILER : 0;
    flags |= (info_flags & VEH_INFO_FLAG_FENDERS) ? CAR_FLAG_FENDERS : 0;
    flags |= (info_flags & VEH_INFO_FLAG_SIREN) ? CAR_FLAG_SIREN : 0;
    flags |= (info_flags & VEH_INFO_FLAG_LARGE) ? CAR_FLAG_LARGE : 0;
    flags |= (info_flags & VEH_INFO_FLAG_AXLES) ? CAR_FLAG_AXLES : 0;

    Model.CarFlags = flags;
}

void mmCar::Update()
{
#ifdef ARTS_DEV_BUILD
    Timer t;
#endif

    OverSample.Update();

    if (PARAM_opp_jump)
    {
        if (!Sim.FrontLeft.OnGround && !Sim.FrontRight.OnGround && !Sim.BackLeft.OnGround && !Sim.BackRight.OnGround)
        {
            Sim.ICS.AngularMomentum *= 0.1f;
        }
    }

#ifdef ARTS_DEV_BUILD
    f32 elapsed = t.Time();
    mmCar::UpdateTime += elapsed;
    mmCar::TotalUpdateTime += elapsed;
#endif
}

b32 mmCar::IsDrivingDisabled()
{
    return (Sim.ICS.Constraints & (ICS_CONSTRAIN_TX | ICS_CONSTRAIN_TZ | ICS_CONSTRAIN_RY)) != 0;
}

void mmCar::PostUpdate()
{
#ifdef ARTS_DEV_BUILD
    Timer t;
#endif

    if (Model.HasTrailer())
    {
        Trailer->PostUpdate();

        // FIXME: If the trailer isn't active, the car won't move either
        if (TrailerJoint->IsNodeActive())
            TrailerJoint->MoveICS();
    }
    else
    {
        Sim.ICS.MoveICS();
    }

    FLSkid.Update();
    FRSkid.Update();
    BLSkid.Update();
    BRSkid.Update();

    Shards.Update();

    Sim.ExhaustPtx.Update();
    Sim.GrassPtx.Update();
    Sim.ExplosionPtx.Update();

#ifdef ARTS_DEV_BUILD
    f32 elapsed = t.Time();
    mmCar::PostUpdateTime += elapsed;
    mmCar::TotalUpdateTime += elapsed;
#endif

    CullCity()->ReparentObject(&Model);
}

void mmCar::ReInit(char* name, i32 variant)
{
    mmVehInfo* veh_info = VehList()->GetVehicleInfo(name);

    if (!veh_info)
    {
        Errorf("This vehicle doens't exist");
        return;
    }

    TranslateFlags(veh_info->Flags);

    Sim.ReInit(name);
    Model.Init(name, this, variant);

    FLSkid.ReInit(&Sim.FrontLeft);
    FRSkid.ReInit(&Sim.FrontRight);
    BLSkid.ReInit(&Sim.BackLeft);
    BRSkid.ReInit(&Sim.BackRight);

    CullCity()->ReparentObject(&Model);

    if (Model.HasTrailer())
    {
        Vector3 trailer_pos {};
        Vector3 joint_pos {0.0f, 0.7f, 3.0f};

        DLPTemplate* dlp = GetDLPTemplate(arts_formatf<128>("%s_trailer", name));

        dlp->GetCentroid(trailer_pos, "TRAILER_H"_xconst);

        Trailer->Init(name, &Sim, trailer_pos);

        trailer_pos.y += Sim.LCS.Matrix.m3.y;
        TrailerJoint->InitJoint3Dof(&Sim.ICS, joint_pos, &Trailer->ICS, joint_pos - trailer_pos);

        Trailer->Activate();
        CullCity()->ReparentObject(&Trailer->Inst);
        TrailerJoint->UnbreakJoint();

        Sim.EnableExhaust = true;

        dlp->Release();
    }
    else
    {
        Trailer->Deactivate();

        if (Trailer->Inst.IsParented())
            CullCity()->ObjectsChain.Unparent(&Trailer->Inst);

        TrailerJoint->BreakJoint();

        Sim.EnableExhaust = false;
    }

    Reset();
}

void mmCar::ReleaseTrailer()
{
    if (Model.HasTrailer())
    {
        TrailerJoint->BreakJoint();
        Trailer->SetHackedImpactParams();
    }
}

void mmCar::RemoveVehicleAudio()
{
    Sim.RemoveNetVehicleAudio();
}

void mmCar::Reset()
{
    if (Model.HasSiren())
        Model.CarFlags &= ~CAR_FLAG_SIREN_ON;

    Sim.Reset();
    Model.Reset();
    ClearDamage();

    if (Model.HasTrailer())
    {
        TrailerJoint->UnbreakJoint();

        Sim.Reset();
        Trailer->Reset();
        TrailerJoint->Reset();
    }

    FLSkid.Reset();
    FRSkid.Reset();
    BLSkid.Reset();
    BRSkid.Reset();
}

void mmCar::StartSiren()
{
    Model.CarFlags |= CAR_FLAG_SIREN_ON;
    Sim.PlayerCarAudio->StartSiren();
}

void mmCar::StopSiren()
{
    Model.CarFlags &= ~CAR_FLAG_SIREN_ON;
    Sim.PlayerCarAudio->StopSiren();
}

void mmCar::ToggleSiren()
{
    if (Model.CarFlags & CAR_FLAG_SIREN_ON)
        StopSiren();
    else
        StartSiren();
}

void mmCar::ClearDamage()
{
    Sim.CurrentDamage = 0.0f;
    Model.ClearDamage(false);

    Sim.Splash.Reset();
    Sim.SetGlobalTuning(1.0f, 1.0f);
}

void mmCar::EnableDriving(b32 enabled)
{
    if (enabled)
    {
        Sim.ICS.Constraints &= ~ICS_CONSTRAIN_ALL;

        if (Model.HasTrailer())
            Trailer->ICS.Constraints &= ~ICS_CONSTRAIN_ALL;
    }
    else
    {
        Sim.ICS.Constraints |= ICS_CONSTRAIN_TX | ICS_CONSTRAIN_TZ | ICS_CONSTRAIN_RY;

        // TODO: Should this be TX|TZ|RY as well?
        if (Model.HasTrailer())
            Trailer->ICS.Constraints |= ICS_CONSTRAIN_ALL;
    }
}

static const char* EggPlayerNames[14] {
    "vasedans",
    "vasedanl",
    "vavan",
    "vadiesels",
    "vacompact",
    "vapickup",
    "vabus",
    "vadelivery",
    "valimo",
    "valimoblack",
    "vataxi",
    "vataxicheck",
    "valimoangel",
    "vaboeing_small",
};

static const char* EggPlayerVehicles[14] {
    "vpcaddie",
    "vpbullet",
    "vpford",
    "vpbus",
    "vpbug",
    "vpford",
    "vpbus",
    "vpford",
    "vpmustang99",
    "vpmustang99",
    "vpcaddie",
    "vpcaddie",
    "vpmustang99",
    "vpbus",
};

i32 EggNameIndex(char* name)
{
    for (i32 i = 0; i < ARTS_SSIZE32(EggPlayerNames); ++i)
    {
        if (!std::strcmp(name, EggPlayerNames[i]))
            return i;
    }

    return -1;
}

hook_func(INIT_main, [] {
    static const f32 spark_multiplier = 16.0f / 30.0f;
    create_patch("mmCar::Impact", "Spark Count", 0x47422C, "\xD9\xE8\x90\x90\x90\x90", 6);
    create_packed_patch<const void*>("mmCar::Impact", "Spark Count", 0x474235 + 2, &spark_multiplier);
});
