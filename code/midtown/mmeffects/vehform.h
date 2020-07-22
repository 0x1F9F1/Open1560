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
    mmeffects:vehform

    0x5026B0 | public: __thiscall mmVehicleForm::mmVehicleForm(void) | ??0mmVehicleForm@@QAE@XZ
    0x502710 | public: void __thiscall mmVehicleForm::SetShape(char *,char *,char *,class Vector3 *) | ?SetShape@mmVehicleForm@@QAEXPAD00PAVVector3@@@Z
    0x502780 | public: virtual void __thiscall mmVehicleForm::Update(void) | ?Update@mmVehicleForm@@UAEXXZ
    0x5027A0 | public: virtual void __thiscall mmVehicleForm::Cull(void) | ?Cull@mmVehicleForm@@UAEXXZ
    0x502900 | public: virtual void * __thiscall mmVehicleForm::`scalar deleting destructor'(unsigned int) | ??_GmmVehicleForm@@UAEPAXI@Z
    0x6207A0 | const mmVehicleForm::`vftable' | ??_7mmVehicleForm@@6B@
    0x64A348 | public: static void (__cdecl* mmVehicleForm::Lighter)(unsigned char *,unsigned int *,unsigned int *,class agiMeshSet *) | ?Lighter@mmVehicleForm@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    0x719610 | public: static class agiTexDef * mmVehicleForm::SphMapTex | ?SphMapTex@mmVehicleForm@@2PAVagiTexDef@@A
*/

#include "arts7/node.h"

class mmVehicleForm final : public asNode
{
    // const mmVehicleForm::`vftable' @ 0x6207A0

public:
    // 0x5026B0 | ??0mmVehicleForm@@QAE@XZ
    ARTS_IMPORT mmVehicleForm();

    // 0x49C440 | ??_EmmVehicleForm@@UAEPAXI@Z
    // 0x502900 | ??_GmmVehicleForm@@UAEPAXI@Z | unused
    // 0x49C4A0 | ??1mmVehicleForm@@UAE@XZ | inline
    ARTS_IMPORT ~mmVehicleForm() override;

    // 0x5027A0 | ?Cull@mmVehicleForm@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x502710 | ?SetShape@mmVehicleForm@@QAEXPAD00PAVVector3@@@Z
    ARTS_IMPORT void SetShape(char* arg1, char* arg2, char* arg3, class Vector3* arg4);

    // 0x502780 | ?Update@mmVehicleForm@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x64A348 | ?Lighter@mmVehicleForm@@2P6AXPAEPAI1PAVagiMeshSet@@@ZA
    ARTS_IMPORT static void (*Lighter)(u8*, u32*, u32*, class agiMeshSet*);

    // 0x719610 | ?SphMapTex@mmVehicleForm@@2PAVagiTexDef@@A
    ARTS_IMPORT static class agiTexDef* SphMapTex;

    u8 gap20[0x34];
};

check_size(mmVehicleForm, 0x54);
