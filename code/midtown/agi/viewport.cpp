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

define_dummy_symbol(agi_viewport);

#include "viewport.h"

#include "pipeline.h"
#include "vector7/matrix34.h"

void agiViewParameters::SetWorld(Matrix34& world)
{
    World = world;
    ModelView.Dot(World, View);
    ++MtxSerial;
}

agiViewport::agiViewport(class agiPipeline* pipe)
    : agiRefreshable(pipe)
    , field_144_(pipe_->GetDword38())
{}

agiViewport::~agiViewport()
{
    if (this == Active)
        Active = nullptr;
}

void agiViewport::SetWorld(class Matrix34& world)
{
    params_.SetWorld(world);
}

f32 agiViewport::Aspect()
{
    if (state_)
    {
        agiPipeline* pipe = Pipe();

        return (pipe->GetWidth() * params_.Width) / (pipe->GetHeight() * params_.Height);
    }

    return params_.Width / params_.Height;
}

char* agiViewport::GetName()
{
    static char buffer[128]; // FIXME: Static buffer
    arts_sprintf(buffer, "Viewport '%p'", this);
    return buffer;
}
