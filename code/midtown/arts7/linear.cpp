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

#include "cullmgr.h"
#include "data7/metadefine.h"
#include "dyna7/dyna.h"
#include "dyna7/gfx.h"
#include "sim.h"

asLinearCS::asLinearCS()
    : Matrix(IDENTITY)
    , World(IDENTITY)
{
    ClearNodeFlag(NODE_FLAG_2);
}

#ifdef ARTS_DEV_BUILD
void asLinearCS::AddWidgets(Bank* bank)
{
    bank->SetLabel("LinearCS");

    bank->AddTitle("Matrix");

    bank->PushSection("Rotation", false);
    bank->AddVector("A Axis:", &Matrix.m0, -5000.0f, 5000.0f, 0.1f);
    bank->AddVector("B Axis:", &Matrix.m1, -5000.0f, 5000.0f, 0.1f);
    bank->AddVector("C Axis:", &Matrix.m2, -5000.0f, 5000.0f, 0.1f);
    bank->PopSection();

    bank->PushSection("Translation", true);
    bank->AddVector("Position:", &Matrix.m3, -5000.0f, 5000.0f, 0.1f);
    bank->PopSection();

    bank->AddToggle("Global", &Global, 0);

    asNode::AddWidgets(bank);
}
#endif

void asLinearCS::Cull()
{
#ifdef ARTS_DEV_BUILD
    DrawBegin(World);
    DrawColor(ColRed);
    DrawLine(ORIGIN, XAXIS);
    DrawColor(ColGreen);
    DrawLine(ORIGIN, YAXIS);
    DrawColor(ColBlue);
    DrawLine(ORIGIN, ZAXIS);
    DrawEnd();
    DrawLabelf(XAXIS, "x"_xconst);
    DrawLabelf(YAXIS, "y"_xconst);
    DrawLabelf(ZAXIS, "z"_xconst);
#endif
}

void asLinearCS::FileIO(MiniParser* /*arg1*/)
{}

void asLinearCS::Update()
{
    if (Global)
    {
        World = Inherit ? Inherit->World : Matrix;
    }
    else
    {
        World.Dot(Matrix, Inherit ? Inherit->World : *Sim()->GetCurrentMatrix());
    }

    Sim()->GetStats().LCSUpdates++;

    Sim()->PushFrame(this);

    asNode::Update();

#ifdef ARTS_DEV_BUILD
    if (Sim()->IsDebugDrawEnabled() && (DynaDrawMode & DYNA_DRAW_MATRIX))
        CullMgr()->DeclareCullable(this);
#endif

    Sim()->PopFrame();
}

META_DEFINE_CHILD("asLinearCS", asLinearCS, asNode)
{
    META_FIELD("Matrix", Matrix);
    META_FIELD("Global", Global);
    META_FIELD("Inherit", Inherit);
}
