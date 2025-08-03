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

#include "widget.h"

class agiBitmap;

class UIBMLabel final : public uiWidget
{
public:
    // ??0UIBMLabel@@QAE@XZ
    ARTS_IMPORT UIBMLabel();

    // ??1UIBMLabel@@UAE@XZ
    ARTS_IMPORT ~UIBMLabel() override;

    // ?CreateDummyBitmap@UIBMLabel@@QAEPAVagiBitmap@@XZ
    ARTS_IMPORT agiBitmap* CreateDummyBitmap();

    // ?Cull@UIBMLabel@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetClass@UIBMLabel@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@UIBMLabel@@QAEXPAVstring@@MMPAH@Z
    ARTS_IMPORT void Init(string* arg1, f32 arg2, f32 arg3, i32* arg4);

    // ?SetBitmapName@UIBMLabel@@QAEXPAVstring@@@Z
    ARTS_IMPORT void SetBitmapName(string* arg1);

    // ?Update@UIBMLabel@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@UIBMLabel@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?LoadBitmap@UIBMLabel@@AAEXXZ
    ARTS_IMPORT void LoadBitmap();

    u8 gap74[0x2C];
};

check_size(UIBMLabel, 0xA0);
