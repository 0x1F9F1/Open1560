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

#pragma once

#include "agiworld/meshrend.h"
#include "arts7/node.h"
#include "vector7/vector3.h"

struct agiMeshCardVertex;
class agiTexDef;
class asBirthRule;
struct asSparkInfo;
struct asSparkPos;

class asParticles final : public asNode
{
public:
    // ??0asParticles@@QAE@XZ
    ARTS_EXPORT asParticles();

    // ??_EasParticles@@UAEPAXI@Z
    // ??1asParticles@@UAE@XZ
    ARTS_EXPORT ~asParticles() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asParticles@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* bank) override;
#endif

    // ?Blast@asParticles@@QAEXHPAVasBirthRule@@@Z
    ARTS_EXPORT void Blast(i32 num_sparks, asBirthRule* birth_rule);

    // ?Cull@asParticles@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?Init@asParticles@@QAEXHHHHPAUagiMeshCardVertex@@@Z
    ARTS_EXPORT void Init(i32 max_particles, i32 arg2, i32 arg3, i32 vert_count, agiMeshCardVertex* vertices);

    // ?Reset@asParticles@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?SetTexture@asParticles@@QAEXPAD@Z
    ARTS_EXPORT void SetTexture(char* name);

    // ?SetTexture@asParticles@@QAEXPAVagiTexDef@@@Z
    ARTS_EXPORT void SetTexture(agiTexDef* texture);

    // ?Update@asParticles@@UAEXXZ
    ARTS_EXPORT void Update() override;

    VIRTUAL_META_DECLARE;

    i32 GetNumActive() const
    {
        return SparkCount;
    }

    asBirthRule* GetBirthRule() const
    {
        return BirthRule;
    }

    void SetBirthRule(asBirthRule* rule)
    {
        BirthRule = rule;
    }

    void SetMatrix(Matrix34* matrix)
    {
        Matrix = matrix;
    }

private:
    i32 SparkCapacity {};
    i32 SparkCount {};
    Ptr<asSparkInfo[]> Sparks;
    Ptr<asSparkPos[]> SparkPositions;
    Rc<agiTexDef> Texture;
    agiMeshCardInfo MeshCard {};
    Matrix34* Matrix {};
    f32 Elapsed {};
    f32 SpewRate {};
    f32 SpewFraction {};
    asBirthRule* BirthRule {};
    Vector3 Wind {0.0f, 0.0f, 0.0f};
    f32 WindDensity {};
    f32 Gravity {-9.8f};
};

check_size(asParticles, 0x6C);

// ?EnablePtxSorting@@3HA
ARTS_IMPORT extern i32 EnablePtxSorting;
