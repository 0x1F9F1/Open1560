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
#include "arts7/sim.h"
#include "birth.h"
#include "data7/metadefine.h"

struct asSparkInfo
{
    f32 Life;
    Vector3 Velocity;
    f32 Mass;
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
    i8 Frame;
    i8 Rotation;
    f32 Radius;
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

static mem::cmd_param PARAM_max_particles {"maxptx"};

void asParticles::Init(i32 max_particles, i32 arg2, i32 arg3, i32 vert_count, agiMeshCardVertex* vertices)
{
    max_particles = static_cast<i32>(max_particles * PARAM_max_particles.get_or<f32>(4.0f));

    SparkCapacity = max_particles;
    Sparks = MakeUnique<asSparkInfo[]>(max_particles);
    SparkPositions = MakeUnique<asSparkPos[]>(max_particles);
    MeshCard.Init(vert_count, vertices, 32, arg2, arg3);
}

#ifdef ARTS_DEV_BUILD
void asParticles::AddWidgets(Bank* bank)
{
    asNode::AddWidgets(bank);

    bank->AddSlider("Spew Rate", &SpewRate, 0.0f, 10000.0f, 1.0f);
    bank->AddVector("Wind", &Wind, -10000.0f, 10000.0f, 0.1f);
    bank->AddSlider("Wind Density", &WindDensity, 0.0f, 10000.0f, 0.1f);
    bank->AddSlider("Gravity", &Gravity, -100000.0f, 10000.0f, 0.1f);
}
#endif

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
        // TODO: Store the relevant asBirthRule info in asSparkInfo
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
        Viewport()->SetWorld(xconst(IDENTITY));
        agiCurState.SetTexture(Texture.get());
        agiMeshSet::InitCards(MeshCard);

        for (i32 i = 0; i < SparkCount; ++i)
        {
            asSparkPos& pos = SparkPositions[i];
            agiMeshSet::DrawCard(pos.Position, pos.Radius, pos.Rotation >> 2, pos.Color, pos.Frame);
        }
    }
}

static const f32 PtxFrameRate = 60.0f;

void asParticles::Update()
{
    f32 delta = Sim()->GetUpdateDelta();
    f32 frames_delta = delta * PtxFrameRate;

    i32 old_frames = static_cast<i32>(Elapsed * PtxFrameRate);
    Elapsed += delta;

    i32 frames = static_cast<i32>(Elapsed * PtxFrameRate) - old_frames;

    if (BirthRule && (Elapsed < BirthRule->SpewRateLimit || (BirthRule->SpewRateLimit == 0.0f)))
    {
        SpewFraction += BirthRule->SpewRate * delta;
        i32 spew_delta = static_cast<i32>(SpewFraction);
        SpewFraction -= static_cast<f32>(spew_delta);

        if (spew_delta)
            Blast(spew_delta, 0);
    }

    for (i32 i = 0; i < SparkCount;)
    {
        asSparkInfo& info = Sparks[i];
        asSparkPos& pos = SparkPositions[i];

        info.Life -= delta;

        if (info.Life < 0.0f || (pos.Position.y < -50.0f) || !(pos.Color & 0xFF000000))
        {
            --SparkCount;
            Sparks[i] = Sparks[SparkCount];
            SparkPositions[i] = SparkPositions[SparkCount];
            continue;
        }

        Vector3 velocity = Wind - info.Velocity;
        velocity *= velocity.Mag() * WindDensity * info.Drag * info.Mass;
        velocity.y += info.Gravity;
        info.Velocity += velocity * delta;

        // Apply a rough approximation of damping (per-frame exponential calculations are silly)
        // Was: info.Velocity *= info.Damp
        info.Velocity *= ((info.Damp - 1.0f) * frames_delta) + 1.0f;
        // info.Velocity *= std::powf(info.Damp, delta * ParticleFrameRate);

        pos.Position += info.Velocity * delta;
        pos.Radius += info.DRadius * frames_delta;

        if ((pos.Position.y < 0.0f) && BirthRule && (BirthRule->BirthFlags & asBirthRule::kSplashes))
        {
            pos.Position.y = 0.0f;
            pos.Frame += 4;
            info.Gravity = 0.0f;
            info.Mass = 0.0f;
            info.Velocity.x = 0.0f;
            info.Velocity.y = 0.0f;
            info.Velocity.z = 0.0f;
            info.Life = 0.1f;
        }

        if (frames)
        {
            if (info.DAlpha && pos.Color)
            {
                i32 d_alpha = info.DAlpha * frames;

                if (i32 alpha = pos.Color >> 24; alpha + d_alpha >= 0)
                    pos.Color += (d_alpha << 24);
                else
                    pos.Color -= (alpha << 24);
            }

            pos.Rotation += static_cast<i8>(info.DRotation * frames);

            if (BirthRule && (BirthRule->BirthFlags & asBirthRule::kCycleFrames))
            {
                i32 start = BirthRule->TexFrameStart;
                i32 end = BirthRule->TexFrameEnd;

                if (start < end)
                    pos.Frame = static_cast<i8>(start + (pos.Frame - start + frames) % (end - start));
            }
        }

        ++i;
    }
}

META_DEFINE_CHILD("asParticles", asParticles, asNode)
{}
