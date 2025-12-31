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

define_dummy_symbol(mmgame_hud);

#include "hud.h"

#include "arts7/sim.h"
#include "mmcity/cullcity.h"
#include "mmcityinfo/state.h"
#include "mmeffects/meshform.h"

#include "gameman.h"

f32 mmTimer::GetTime()
{
    return Time;
}

void mmTimer::Init(b32 count_down, f32 start_time)
{
    CountDown = count_down;
    StartTime = start_time;
    Time = start_time;
}

void mmTimer::Reset()
{
    Time = StartTime;
}

void mmTimer::Start()
{
    Running = true;
}

void mmTimer::StartStop()
{
    Running ^= true;
}

void mmTimer::Stop()
{
    Running = false;
}

void mmTimer::Update()
{
    if (!Running)
        return;

    if (CountDown)
    {
        Time -= Sim()->GetUpdateDelta();

        if (Time <= 0.0f)
        {
            Time = 0.0f;
            Running = false;
        }
    }
    else
    {
        Time += Sim()->GetUpdateDelta();
    }
}

void mmHUD::ToggleMirror()
{
    ScreenClearCount = 3;
    CullCity()->RenderWeb.EnableMirror ^= true;
    MMSTATE.EnableMirror = CullCity()->RenderWeb.EnableMirror;
}

void mmHUD::TogglePositionDisplay(i32 mode)
{
    // FIXME: Move to constructor
    if (DashView.GetParentNode() == &HudElements)
    {
        // DashView is not a HUD element, and should not be hidden when a menu is shown.
        // To avoid drawing over the HUD, it should also come before HudElements
        HudElements.RemoveChild(&DashView);
        InsertChild(1, &DashView);

        // Show position text while paused
        PositionText.SetNodeFlag(NODE_FLAG_UPDATE_PAUSED);
    }

    ShowPosition = (mode != -1) ? (mode != 0) : !ShowPosition;

    if (ShowPosition)
        PositionText.ActivateNode();
    else
        PositionText.DeactivateNode();
}

void mmHUD::UpdatePaused()
{}

mmArrow::mmArrow()
    : asNode()
{
    LinearCS = new asLinearCS();

    GreenArrow = new asMeshSetForm();
    GreenArrow->SetShape("hudarrow1"_xconst, "BOTTOM"_xconst, nullptr);

    asMeshSetForm::Lighter = nullptr;
    asMeshSetForm::SphMapTex = nullptr;

    GreenArrow->SetZRead(false);
    GreenArrow->SetZWrite(false);

    GreenArrow->Color = 0x8000FF00;

    YellowArrow = new asMeshSetForm();
    YellowArrow->SetShape("hudarrow2"_xconst, "BOTTOM"_xconst, nullptr);

    asMeshSetForm::Lighter = nullptr;
    asMeshSetForm::SphMapTex = nullptr;

    YellowArrow->SetZRead(false);
    YellowArrow->SetZWrite(false);

    YellowArrow->Color = 0x80FFFF00;

    LinearCS->Matrix.m3 = {0.0f, 2.0f, -6.1f};

    Interest = 0;
    Transform = 0;

    LinearCS->AddChild(GreenArrow);
    LinearCS->AddChild(YellowArrow);
    AddChild(LinearCS);

    Color = 2;
}