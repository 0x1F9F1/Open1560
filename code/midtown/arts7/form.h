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

class asCamera;
class DLP;
class MiniParser;

class asForm final : public asNode
{
public:
    // ??0asForm@@QAE@XZ
    ARTS_IMPORT asForm();

    // ??_EasForm@@UAEPAXI@Z
    // ??1asForm@@UAE@XZ
    ARTS_IMPORT ~asForm() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asForm@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@asForm@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?FileIO@asForm@@QAEXPAVMiniParser@@@Z | unused
    ARTS_EXPORT void FileIO(MiniParser* arg1);

    // ?GetClass@asForm@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?SetCull@asForm@@QAEXHM@Z
    ARTS_IMPORT void SetCull(i32 arg1, f32 arg2);

    // ?SetShape@asForm@@QAEXPAD0PAVVector3@@HH@Z
    ARTS_IMPORT void SetShape(char* arg1, char* arg2, Vector3* arg3, i32 arg4, i32 arg5);

    // ?Update@asForm@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?Visible@asForm@@QBEHPAVasCamera@@ABVMatrix34@@@Z
    ARTS_IMPORT i32 Visible(asCamera* arg1, const Matrix34& arg2) const;

    // ?DeclareFields@asForm@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0xA8];
};

check_size(asForm, 0xC8);
