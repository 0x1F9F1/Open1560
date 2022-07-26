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

define_dummy_symbol(mmai_aiPoliceForce);

#include "aiPoliceForce.h"

#include "mmcar/car.h"
#include "mmphysics/inertia.h"

static mem::cmd_param PARAM_maxcops {"maxcops"};

aiPoliceForce::aiPoliceForce()
{
    // TODO: Add a field to AIMAP
    max_cops_ = std::min<i16>(PARAM_maxcops.get_or<i16>(3), MaxCops);

    Reset();
}

i32 aiPoliceForce::Find(mmCar* cop, mmCar* perp)
{
    if (i32 index = FindPerp(perp); index >= 0)
    {
        if (FindCop(index, cop) >= 0)
            return 0;
    }

    return -1;
}

b32 aiPoliceForce::RegisterPerp(mmCar* cop, mmCar* perp)
{
    if (i32 index = FindPerp(perp); index >= 0)
    {
        // TODO: Check if already registered?
        if (num_cops_[index] >= max_cops_)
            return false;

        cops_[index][num_cops_[index]++] = cop;
        return true;
    }

    if (num_perps_ >= MaxPerps)
        return false;

    i32 index = num_perps_++;
    perps_[index] = perp;
    cops_[index][0] = cop;
    num_cops_[index] = 1;

    last_register_.Reset();

    return true;
}

void aiPoliceForce::Reset()
{
    num_perps_ = 0;

    for (usize i = 0; i < MaxPerps; ++i)
    {
        perps_[i] = nullptr;
        num_cops_[i] = 0;

        for (i32 j = 0; j < max_cops_; ++j)
            cops_[i][j] = nullptr;
    }
}

i32 aiPoliceForce::State(mmCar* cop, mmCar* perp, f32 cop_dist)
{
    i32 i = FindPerp(perp);

    if (i < 0)
    {
        Displayf("ERROR: Can't find perp.");
        return 9;
    }

    i32 best = 0;
    f32 best_dist = 1e9f;

    for (i32 j = 0; j < num_cops_[i]; ++j)
    {
        if (f32 dist = perp->GetICS()->GetPosition().Dist2(cops_[i][j]->GetICS()->GetPosition()); dist < best_dist)
        {
            best_dist = dist;
            best = j;
        }
    }

    if ((cops_[i][best] == cop) && (cop_dist <= 25.0f))
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

b32 aiPoliceForce::UnRegisterCop(mmCar* cop, mmCar* perp)
{
    i32 i = FindPerp(perp);

    if (i < 0)
        return false;

    i32 j = FindCop(i, cop);

    if (j < 0)
        return false;

    cops_[i][j] = cops_[i][--num_cops_[i]];

    if (num_cops_[i] == 0)
        perps_[i] = perps_[--num_perps_];

    return true;
}

void aiPoliceForce::Update()
{}

i32 aiPoliceForce::FindPerp(mmCar* perp)
{
    for (i32 i = 0; i < num_perps_; ++i)
    {
        if (perps_[i] == perp)
            return i;
    }

    return -1;
}

i32 aiPoliceForce::FindCop(i32 index, mmCar* cop)
{
    for (i32 i = 0; i < num_cops_[index]; ++i)
    {
        if (cops_[index][i] == cop)
            return i;
    }

    return -1;
}

hook_func(INIT_main, [] {
    create_hook("aiPoliceForce", "Size of aiPoliceForce", 0x43506A, alloc_proxy<aiPoliceForce>, hook_type::call);
});