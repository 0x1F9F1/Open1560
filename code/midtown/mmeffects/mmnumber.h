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

// Rewritten using 1588+ logic

class agiBitmap;
class mmNumberFont;

class mmNumber final : public asNode
{
public:
    // ??0mmNumber@@QAE@XZ
    ARTS_EXPORT mmNumber();

    // ??1mmNumber@@UAE@XZ
    ARTS_EXPORT ~mmNumber() override;

    // ?Cull@mmNumber@@UAEXXZ
    void Cull() override;

    // ?Init@mmNumber@@QAEXPAVmmNumberFont@@MM@Z
    ARTS_EXPORT void Init(mmNumberFont* font, f32 x, f32 y);

    // ?Printf@mmNumber@@QAAXPBDZZ
    ARTS_EXPORT void Printf(const char* format, ...);

    // ?SetString@mmNumber@@QAEXPAD@Z
    ARTS_EXPORT void SetString(char* text);

    // ?Update@mmNumber@@UAEXXZ
    void Update() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmNumber@@UAEXPAVBank@@@Z
    void AddWidgets(Bank* arg1) override;
#endif

    VIRTUAL_META_DECLARE;

private:
    f32 x_ {};
    f32 y_ {};
    mmNumberFont* font_;

#if ARTS_TARGET_BUILD < 1588
    char gap2C[0x4]; // TODO: Remove this
#endif

    char text_[80];
};

check_size(mmNumber, 0x80);

class mmNumberFont
{
public:
    // ??0mmNumberFont@@QAE@XZ
    ARTS_EXPORT mmNumberFont();

    mmNumberFont(const char* chars);

    // ??1mmNumberFont@@QAE@XZ
    ARTS_EXPORT ~mmNumberFont();

    // ?LoadFont@mmNumberFont@@QAEXPADHI@Z
    ARTS_EXPORT void LoadFont(char* font, i32 height, u32 color);

    // ?LoadLocFont@mmNumberFont@@QAEXPADPAULocString@@HI@Z
    ARTS_EXPORT void LoadLocFont(char* font, LocString* params, i32 screen_width, u32 color);

private:
    friend class mmNumber;

    void* Font {};
    const char* Chars {};
    usize Count {};
    agiBitmap** Bitmaps {};

#if ARTS_TARGET_BUILD < 1588
    char gap10[0x14]; // TODO: Remove this
#endif

    void Init(u32 color);
};

check_size(mmNumberFont, 0x24);

// ?NUMBERSTRING@@3PADA
extern aconst char* NUMBERSTRING;
