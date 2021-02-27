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

define_dummy_symbol(mmeffects_ptx);

#include "ptx.h"

#include "agi/rsys.h"
#include "agi/texdef.h"
#include "agi/viewport.h"
#include "agiworld/texsort.h"
#include "arts7/bank.h"
#include "birth.h"
#include "data7/metadefine.h"

struct asSparkInfo
{
    f32 Life;
    Vector3 Velocity;
    f32 VelocityScale;
    f32 Drag;
    f32 Damp;
    f32 Gravity;
    f32 DRadius;
    i8 DAlpha;
    i8 DRotation;
};

check_size(asSparkInfo, 0x28);

struct asSparkPos
{
    i8 CurrentFrame;
    i8 Rotation;
    f32 Scale;
    u32 Color;
    Vector3 Position;
};

check_size(asSparkPos, 0x18);

asParticles::asParticles()
{
    Reset();
}

asParticles::~asParticles() = default;

void asParticles::Reset()
{
    SparkCount = 0;
    Matrix = nullptr;
    Elapsed = 0.0f;
}

void asParticles::Init(i32 max_particles, i32 arg2, i32 arg3, i32 vert_count, agiMeshCardVertex* vertices)
{
    SparkCapacity = max_particles;
    Sparks = MakeUnique<asSparkInfo[]>(max_particles);
    SparkPositions = MakeUnique<asSparkPos[]>(max_particles);
    MeshCard.Init(vert_count, vertices, 32, arg2, arg3);
}

void asParticles::AddWidgets(Bank* bank)
{
    asNode::AddWidgets(bank);

    bank->AddSlider("Spew Rate", &SpewRate, 0.0f, 10000.0f, 1.0f, NullCallback);
    bank->AddVector("Wind", &Wind, -10000.0f, 10000.0f, 0.1f, NullCallback);
    bank->AddSlider("Wind Density", &WindDensity, 0.0f, 10000.0f, 0.1f, NullCallback);
    bank->AddSlider("Gravity", &Gravity, -100000.0f, 10000.0f, 0.1f, NullCallback);
}

void asParticles::SetTexture(char* name)
{
    Rc<agiTexDef> texture = AsRc(GetPackedTexture(name, 0));

    if (!texture)
        Errorf("asParticles::SetTexture: '%s' not found", name);

    SetTexture(texture.get()); // FIXME: This ref counting is a bit silly
    SparkCount = 0;            // TODO: Why does this reset SparkCount?
}

void asParticles::SetTexture(agiTexDef* texture)
{
    Texture = AddRc(texture);
}

void asParticles::Blast(i32 num_sparks, asBirthRule* birth_rule)
{
    if (!birth_rule)
    {
        if (!BirthRule)
        {
            Errorf("asParticles::Blast()- No BirthRule");
            return;
        }

        birth_rule = BirthRule;
    }

    num_sparks = std::min(num_sparks, SparkCapacity - SparkCount);

    for (i32 i = 0; i < num_sparks; ++i, ++SparkCount)
    {
        birth_rule->InitSpark(&Sparks[SparkCount], &SparkPositions[SparkCount]);

        if (Matrix)
        {
            Vector3& pos = SparkPositions[SparkCount].Position;
            pos.Dot(pos, *Matrix);
        }
    }
}

void asParticles::Cull()
{
    if (!Texture)
    {
        Errorf("asParticles::Cull: Null texture");
        return;
    }

    if (SparkCount)
    {
        GetActiveViewport()->SetWorld(const_cast<Matrix34&>(IDENTITY));
        agiCurState.SetTexture(Texture.get());
        agiMeshSet::InitCards(MeshCard);

        for (i32 i = 0; i < SparkCount; ++i)
        {
            asSparkPos& pos = SparkPositions[i];
            agiMeshSet::DrawCard(pos.Position, pos.Scale, pos.Rotation >> 2, pos.Color, pos.CurrentFrame);
        }
    }
}

META_DEFINE_CHILD("asParticles", asParticles, asNode)
{}