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

define_dummy_symbol(agirend_lighter);

#include "lighter.h"

#include "vector7/vector3.h"

agiLight* agiLighter::ACTIVELIGHTS[MAX_LIGHTS] {};
char agiLighter::Attenuate[MAX_LIGHTS] {};
f32 agiLighter::CosSpread[MAX_LIGHTS] {};
i32 agiLighter::Current {};
Vector3 agiLighter::Dir[MAX_LIGHTS] {};
Vector3 agiLighter::Eye {};
agiLight* agiLighter::LIGHTS[MAX_LIGHTS] {};
agiLightModel* agiLighter::LMODEL {};
i32 agiLighter::LocalViewer {};
Vector3 agiLighter::Pos[MAX_LIGHTS] {};
char agiLighter::Positional[MAX_LIGHTS] {};
i32 agiLighter::SceneActive {};
Vector3 agiLighter::SceneAmbient {};
i32 agiLighter::SceneCurrent {};
agiShadowMap* agiLighter::ShadowMap {};

agiMonoLighter MONOLIGHTER {};
agiRGBLighter RGBLIGHTER {};

void agiLighter::DeclareLight(agiLight* light)
{
    if (Current < MAX_LIGHTS)
    {
        LIGHTS[Current++] = light;
    }
}