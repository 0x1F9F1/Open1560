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

define_dummy_symbol(mmcar_skid);

#include "skid.h"

#include "arts7/sim.h"
#include "mmcity/cullcity.h"
#include "mmdyna/poly.h"

#include "carsim.h"
#include "wheel.h"

#ifdef ARTS_DEV_BUILD
void mmSkid::AddWidgets(Bank* /*arg1*/)
{}
#endif

void ARTS_FASTCALL mmSkid::DrawShadow()
{}

void ARTS_FASTCALL mmSkid::FromMatrix(const Matrix34& /*arg1*/)
{}

void mmSkid::Update()
{}

static const f32 SkidSpeedThresh = 3.0f;
static const f32 SkidTrackTimeThresh = 0.1f;

void mmSkidManager::Update()
{
    mmCarSim* car = Wheel->CarSim;
    f32 slip_thresh = car->SlipPercentThresh;

    f32 car_speed = car->Speed;
    f32 wheel_speed = std::abs(Wheel->RotationSpeed * Wheel->Radius);

    if ((car_speed > SkidSpeedThresh || wheel_speed > SkidSpeedThresh) &&
        (std::abs(Wheel->LatSlipPercent) > slip_thresh || std::abs(Wheel->LongSlipPercent) > slip_thresh) &&
        Wheel->OnGround && car->ShouldSkid() && Wheel->Intersection.Normal.y > 0.1f)
    {
        TimeSinceLastTrack += Sim()->GetUpdateDelta();

        if (TimeSinceLastTrack > SkidTrackTimeThresh)
        {
            if (mmPolygon* surface = Wheel->Intersection.HitPoly;
                !surface || !(CullCity()->GetRoomFlags(surface->RoomId) & ROOM_FLAG_40))
            {
                LayTrack();
            }

            TimeSinceLastTrack = 0.0f;
        }

        Wheel->GenerateSkidParticles();
    }
    else
    {
        NotSkidding = true;
    }

    asNode::Update();
}
