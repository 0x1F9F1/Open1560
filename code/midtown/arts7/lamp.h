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

#include "node.h"

class MiniParser;

class agiLight;
class agiLightParameters;

class asLamp final : public asNode
{
public:
    // ??0asLamp@@QAE@XZ
    ARTS_IMPORT asLamp();

    // ??_EasLamp@@UAEPAXI@Z
    // ??1asLamp@@UAE@XZ
    ARTS_EXPORT ~asLamp() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asLamp@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@asLamp@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?FileIO@asLamp@@QAEXPAVMiniParser@@@Z | unused
    ARTS_EXPORT void FileIO(MiniParser* arg1);

    // ?GetClass@asLamp@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?SetColor@asLamp@@QAEXABVVector3@@M@Z
    ARTS_IMPORT void SetColor(const Vector3& arg1, f32 arg2);

    // ?SetDistant@asLamp@@QAEXXZ
    ARTS_IMPORT void SetDistant();

    // ?Update@asLamp@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@asLamp@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?Regen@asLamp@@AAEXXZ
    ARTS_IMPORT void Regen();

    Rc<agiLight> Light;
    Ptr<agiLightParameters> Params;
    b32 Global {true};
    i32 CullCount {};
};

check_size(asLamp, 0x30);
