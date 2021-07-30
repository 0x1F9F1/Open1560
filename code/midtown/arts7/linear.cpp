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

define_dummy_symbol(arts7_linear);

#include "linear.h"

#include "bank.h"
#include "cullmgr.h"
#include "data7/metadefine.h"
#include "dyna7/dyna.h"
#include "dyna7/gfx.h"
#include "sim.h"

asLinearCS::asLinearCS()
    : matrix_(IDENTITY)
    , camera_(IDENTITY)
{
    SetNodeFlag2(false);
}

#ifdef ARTS_DEV_BUILD
void asLinearCS::AddWidgets(Bank* bank)
{
    bank->SetLabel("LinearCS");

    bank->AddTitle("Matrix");

    bank->PushSection("Rotation", 0);
    bank->AddVector("A Axis:", &matrix_.m0, -5000.0f, 5000.0f, 0.1f, NullCallback);
    bank->AddVector("B Axis:", &matrix_.m1, -5000.0f, 5000.0f, 0.1f, NullCallback);
    bank->AddVector("C Axis:", &matrix_.m2, -5000.0f, 5000.0f, 0.1f, NullCallback);
    bank->PopSection();

    bank->PushSection("Translation", 1);
    bank->AddVector("Position:", &matrix_.m3, -5000.0f, 5000.0f, 0.1f, NullCallback);
    bank->PopSection();

    bank->AddToggle("Global", &global_, 0, NullCallback);

    asNode::AddWidgets(bank);
}
#endif

void asLinearCS::Cull()
{
#ifdef ARTS_DEV_BUILD
    DrawBegin(camera_);
    DrawColor(ColRed);
    DrawLine(ORIGIN, XAXIS);
    DrawColor(ColGreen);
    DrawLine(ORIGIN, YAXIS);
    DrawColor(ColBlue);
    DrawLine(ORIGIN, ZAXIS);
    DrawEnd();
    DrawLabelf(XAXIS, const_cast<char*>("x"));
    DrawLabelf(YAXIS, const_cast<char*>("y"));
    DrawLabelf(ZAXIS, const_cast<char*>("z"));
#endif
}

void asLinearCS::FileIO(class MiniParser* /*arg1*/)
{}

void asLinearCS::Update()
{
    if (global_)
    {
        camera_ = inherit_ ? inherit_->camera_ : matrix_;
    }
    else
    {
        camera_.Dot(matrix_, inherit_ ? inherit_->camera_ : *ARTSPTR->GetCurrentCamera());
    }

    ARTSPTR->GetStats().LCSUpdates++;

    ARTSPTR->PushCamera(this);

    asNode::Update();

#ifdef ARTS_DEV_BUILD
    if (ARTSPTR->IsDebugDrawEnabled() && (DynaDrawMode & 0x200))
    {
        CULLMGR->DeclareCullable(this);
    }
#endif

    ARTSPTR->PopCamera();
}

META_DEFINE_CHILD("asLinearCS", asLinearCS, asNode)
{
    META_FIELD("Matrix", matrix_);
    META_FIELD("Global", global_);
    META_FIELD("Inherit", inherit_);
}
