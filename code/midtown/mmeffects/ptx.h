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

/*
    mmeffects:ptx

    0x5000B0 | public: __thiscall asParticles::asParticles(void) | ??0asParticles@@QAE@XZ
    0x500120 | public: virtual __thiscall asParticles::~asParticles(void) | ??1asParticles@@UAE@XZ
    0x5001A0 | public: void __thiscall asParticles::Init(int,int,int,int,struct agiMeshCardVertex *) | ?Init@asParticles@@QAEXHHHHPAUagiMeshCardVertex@@@Z
    0x500210 | public: virtual void __thiscall asParticles::Reset(void) | ?Reset@asParticles@@UAEXXZ
    0x500220 | public: void __thiscall asParticles::SetTexture(class agiTexDef *) | ?SetTexture@asParticles@@QAEXPAVagiTexDef@@@Z
    0x500250 | public: void __thiscall asParticles::SetTexture(char *) | ?SetTexture@asParticles@@QAEXPAD@Z
    0x5002A0 | public: virtual void __thiscall asParticles::Update(void) | ?Update@asParticles@@UAEXXZ
    0x5005F0 | public: void __thiscall asParticles::Blast(int,class asBirthRule *) | ?Blast@asParticles@@QAEXHPAVasBirthRule@@@Z
    0x500690 | int __cdecl cmpPtx(void const *,void const *) | ?cmpPtx@@YAHPBX0@Z
    0x5006B0 | public: virtual void __thiscall asParticles::Cull(void) | ?Cull@asParticles@@UAEXXZ
    0x500750 | public: virtual void __thiscall asParticles::AddWidgets(class Bank *) | ?AddWidgets@asParticles@@UAEXPAVBank@@@Z
    0x500830 | public: static void __cdecl asParticles::DeclareFields(void) | ?DeclareFields@asParticles@@SAXXZ
    0x500990 | public: virtual class MetaClass * __thiscall asParticles::GetClass(void) | ?GetClass@asParticles@@UAEPAVMetaClass@@XZ
    0x5009A0 | public: virtual void * __thiscall asParticles::`vector deleting destructor'(unsigned int) | ??_EasParticles@@UAEPAXI@Z
    0x6206F0 | const asParticles::`vftable' | ??_7asParticles@@6B@
    0x7195A8 | class MetaClass asParticlesMetaClass | ?asParticlesMetaClass@@3VMetaClass@@A
    0x7195D0 | int EnablePtxSorting | ?EnablePtxSorting@@3HA
*/

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

// ?cmpPtx@@YAHPBX0@Z | unused
ARTS_IMPORT i32 cmpPtx(const void* arg1, const void* arg2);

// ?EnablePtxSorting@@3HA
ARTS_IMPORT extern i32 EnablePtxSorting;
