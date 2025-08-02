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

class agiTexDef;

class mmSky
{
public:
    // ??0mmSky@@QAE@XZ
    ARTS_IMPORT mmSky();

    // ??1mmSky@@QAE@XZ
    ARTS_IMPORT ~mmSky();

    // ?Draw@mmSky@@QAEXAAVMatrix34@@@Z
    ARTS_IMPORT void Draw(Matrix34& arg1);

    // ?Init@mmSky@@QAEXPAD@Z
    ARTS_IMPORT void Init(char* arg1);

    // ?SetTexture@mmSky@@QAEXPAVagiTexDef@@@Z
    ARTS_IMPORT void SetTexture(agiTexDef* arg1);

    // ?Color@mmSky@@2IA
    ARTS_IMPORT static u32 Color;

private:
    // ?DoFlash@mmSky@@0HA
    ARTS_IMPORT static i32 DoFlash;

    // ?Instance@mmSky@@0PAV1@A
    ARTS_IMPORT static mmSky* Instance;

public:
    f32 RotationSpeed;
    f32 Mesh;
};

check_size(mmSky, 0x8);

// ?FlashTex@@3PAVagiTexDef@@A
ARTS_IMPORT extern agiTexDef* FlashTex;

// ?SkyScale@@3MA
ARTS_IMPORT extern f32 SkyScale;
