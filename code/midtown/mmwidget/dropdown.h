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

#include "arts7/node.h"
#include "data7/str.h"

class asCamera;
class mmTextNode;

class mmDropDown final : public asNode
{
public:
    // ??0mmDropDown@@QAE@XZ
    ARTS_EXPORT mmDropDown();

    // ??1mmDropDown@@UAE@XZ
    ARTS_EXPORT ~mmDropDown() override;

    // ?FindFirstEnabled@mmDropDown@@QAEHXZ
    ARTS_IMPORT i32 FindFirstEnabled();

    // ?GetCurrentString@mmDropDown@@QAEXPADH@Z
    ARTS_IMPORT void GetCurrentString(char* arg1, i32 arg2);

    // ?GetHit@mmDropDown@@QAEHMM@Z
    ARTS_IMPORT i32 GetHit(f32 arg1, f32 arg2);

    // ?Init@mmDropDown@@QAEXPAVasCamera@@PAXMMMMVstring@@H@Z
    ARTS_IMPORT void Init(asCamera* arg1, void* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, string arg7, i32 arg8);

    // ?InitString@mmDropDown@@QAEXVstring@@@Z
    ARTS_EXPORT void InitString(string values);

    // ?SetDisabledColors@mmDropDown@@QAEXXZ
    ARTS_IMPORT void SetDisabledColors();

    // ?SetHighlight@mmDropDown@@QAEXH@Z
    ARTS_EXPORT void SetHighlight(i32 index);

    // ?Update@mmDropDown@@UAEXXZ
    ARTS_IMPORT void Update() override;

    VIRTUAL_META_DECLARE;

private:
    // ?SetString@mmDropDown@@AAEXVstring@@@Z
    ARTS_IMPORT void SetString(string arg1);

    Ptr<mmTextNode[]> ValueNodes;
    Ptr<u32[]> DropIndex;
    i32 Highlighted {-1};
    i32 field_2C {};
    i32 Enabled {};
    i32 DisabledMask {};
    asCamera* Camera {};
    void* Font {};
    f32 Y {};
    f32 Height {};
    f32 X {};
    f32 Width {};
    f32 DropHeight {};
    f32 Bottom {};
    i32 NumValues {};
    string ValuesString {};
    char field_64[100];
};

check_size(mmDropDown, 0xC8);
