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

define_dummy_symbol(mmcar_force);

#include "force.h"

#include "carsim.h"

#include "arts7/sim.h"
#include "mmcityinfo/state.h"

static mem::cmd_param PARAM_disabledownforce {"disabledownforce"};

mmForce::mmForce()
{}

void mmForce::Update()
{
    if (CarSim == nullptr)
    {
        asNode::Update();
        return;
    }

    Vector3 total_force {0.0f, 0.0f, 0.0f};
    f32 speed = CarSim->Speed;
    f32 speed_sqr = speed * speed;

    if (speed > 0.0f)
    {
        f32 inv_speed = 1.0f / speed;
        Vector3 vel_dir = CarSim->ICS.LinearVelocity * inv_speed;
        f32 drag_mag = -Drag * speed_sqr;
        total_force = vel_dir * drag_mag;
    }

    f32 downforce_mag = speed_sqr * Downforce;
    Vector3 downforce_vec = CarSim->ICS.Matrix.m1 * downforce_mag;
    total_force = total_force - downforce_vec;

    CarSim->ICS.ApplyForce(total_force);
    CarSim->ICS.AngularMomentum.y *= (1.0f - ARTSPTR->GetUpdateDelta());

    if (CHICAGO)
    {
        f32 car_height = CarSim->ICS.Matrix.m3.y;

        if (car_height > YDownForceMinHeight)
        {
            if (PARAM_disabledownforce)
            {
                CHEATING = true;
            }
            else
            {
                f32 height_factor = (car_height - YDownForceMinHeight) / (YDownForceMaxHeight - YDownForceMinHeight);
                f32 downforce_scale = height_factor * (YDownForceMax - YDownForceMin) + YDownForceMin;
                f32 force_mag = downforce_scale * CarSim->ICS.Mass;
                Vector3 force_vec = YAXIS * (-force_mag);

                CarSim->ICS.ApplyForce(force_vec);
            }
        }
    }

    asNode::Update();
}