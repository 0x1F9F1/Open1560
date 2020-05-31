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
    mmeffects:meshform

    0x4FFEA0 | public: __thiscall asMeshSetForm::asMeshSetForm(void) | ??0asMeshSetForm@@QAE@XZ
    0x4FFEC0 | public: void __thiscall asMeshSetForm::SetShape(char *,char *,class Vector3 *) | ?SetShape@asMeshSetForm@@QAEXPAD0PAVVector3@@@Z
    0x4FFF00 | public: void __thiscall asMeshSetForm::SetZRead(int) | ?SetZRead@asMeshSetForm@@QAEXH@Z
    0x4FFF20 | public: void __thiscall asMeshSetForm::SetZWrite(int) | ?SetZWrite@asMeshSetForm@@QAEXH@Z
    0x4FFF40 | public: virtual void __thiscall asMeshSetForm::Update(void) | ?Update@asMeshSetForm@@UAEXXZ
    0x4FFF60 | public: virtual void __thiscall asMeshSetForm::Cull(void) | ?Cull@asMeshSetForm@@UAEXXZ
    0x500070 | public: virtual void * __thiscall asMeshSetForm::`vector deleting destructor'(unsigned int) | ??_EasMeshSetForm@@UAEPAXI@Z
    0x500070 | public: virtual void * __thiscall asMeshSetForm::`scalar deleting destructor'(unsigned int) | ??_GasMeshSetForm@@UAEPAXI@Z
    0x5000A0 | public: virtual __thiscall asMeshSetForm::~asMeshSetForm(void) | ??1asMeshSetForm@@UAE@XZ
    0x6206B0 | const asMeshSetForm::`vftable' | ??_7asMeshSetForm@@6B@
    0x649D8C | public: static void (__cdecl* asMeshSetForm::Lighter)(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *) | ?Lighter@asMeshSetForm@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    0x7195A4 | public: static class agiTexDef * asMeshSetForm::SphMapTex | ?SphMapTex@asMeshSetForm@@2PAVagiTexDef@@A
*/

#include "arts7/node.h"

class asMeshSetForm : public asNode
{
    // const asMeshSetForm::`vftable' @ 0x6206B0

public:
    // 0x4FFEA0 | ??0asMeshSetForm@@QAE@XZ
    asMeshSetForm();

    // 0x500070 | ??_GasMeshSetForm@@UAEPAXI@Z
    // 0x5000A0 | ??1asMeshSetForm@@UAE@XZ | inline
    ~asMeshSetForm() override;

    // 0x4FFF60 | ?Cull@asMeshSetForm@@UAEXXZ
    void Cull() override;

    // 0x4FFEC0 | ?SetShape@asMeshSetForm@@QAEXPAD0PAVVector3@@@Z
    void SetShape(char* arg1, char* arg2, class Vector3* arg3);

    // 0x4FFF00 | ?SetZRead@asMeshSetForm@@QAEXH@Z
    void SetZRead(i32 arg1);

    // 0x4FFF20 | ?SetZWrite@asMeshSetForm@@QAEXH@Z
    void SetZWrite(i32 arg1);

    // 0x4FFF40 | ?Update@asMeshSetForm@@UAEXXZ
    void Update() override;

    // 0x649D8C | ?Lighter@asMeshSetForm@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    static inline extern_var(0x649D8C, void (*)(u8*, u32*, u32*, class agiMeshSet*), Lighter);

    // 0x7195A4 | ?SphMapTex@asMeshSetForm@@2PAVagiTexDef@@A
    static inline extern_var(0x7195A4, class agiTexDef*, SphMapTex);
};

check_size(asMeshSetForm, 0x2C);
