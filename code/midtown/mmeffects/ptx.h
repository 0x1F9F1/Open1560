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

#include "arts7/node.h"

class asParticles final : public asNode
{
    // const asParticles::`vftable' @ 0x6206F0

public:
    // 0x5000B0 | ??0asParticles@@QAE@XZ
    ARTS_IMPORT asParticles();

    // 0x5009A0 | ??_EasParticles@@UAEPAXI@Z
    // 0x500120 | ??1asParticles@@UAE@XZ
    ARTS_IMPORT ~asParticles() override;

    // 0x500750 | ?AddWidgets@asParticles@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x5005F0 | ?Blast@asParticles@@QAEXHPAVasBirthRule@@@Z
    ARTS_IMPORT void Blast(i32 arg1, class asBirthRule* arg2);

    // 0x5006B0 | ?Cull@asParticles@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x500990 | ?GetClass@asParticles@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x5001A0 | ?Init@asParticles@@QAEXHHHHPAUagiMeshCardVertex@@@Z
    ARTS_IMPORT void Init(i32 arg1, i32 arg2, i32 arg3, i32 arg4, struct agiMeshCardVertex* arg5);

    // 0x500210 | ?Reset@asParticles@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x500250 | ?SetTexture@asParticles@@QAEXPAD@Z
    ARTS_IMPORT void SetTexture(char* arg1);

    // 0x500220 | ?SetTexture@asParticles@@QAEXPAVagiTexDef@@@Z
    ARTS_IMPORT void SetTexture(class agiTexDef* arg1);

    // 0x5002A0 | ?Update@asParticles@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x500830 | ?DeclareFields@asParticles@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x4C];
};

check_size(asParticles, 0x6C);

// 0x500690 | ?cmpPtx@@YAHPBX0@Z | unused
ARTS_IMPORT i32 cmpPtx(void const* arg1, void const* arg2);

// 0x7195D0 | ?EnablePtxSorting@@3HA
ARTS_IMPORT extern i32 EnablePtxSorting;

// 0x7195A8 | ?asParticlesMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass asParticlesMetaClass;
