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

define_dummy_symbol(localize_localize);

#include "localize.h"

#if ARTS_LOCALIZE_MODE == 2
#    include "core/minwin.h"

#    define LANG_STRING_COUNT 16
#    define LANG_STRING_SIZE 512

static char LangStrings[LANG_STRING_COUNT][LANG_STRING_SIZE];
static usize LangStringIndex = 0;
static HMODULE LangStringDLL = NULL;

LocString* AngelReadString(u32 index)
{
    if (index == 376) // Buffer Overflow in Russian
        return LOC_TEXT("%d x %d - Recommended");

    if (LangStringDLL == NULL)
        LangStringDLL = LoadLibraryA("MMLANG.DLL");

    char* buffer = LangStrings[LangStringIndex];

    if (++LangStringIndex == ARTS_SIZE(LangStrings))
        LangStringIndex = 0;

    // FIXME: This won't work with WIN32 -A APIs which expect ANSI text
    wchar_t wbuffer[LANG_STRING_SIZE];
    LoadStringW(LangStringDLL, index, wbuffer, LANG_STRING_SIZE);
    WideCharToMultiByte(CP_UTF8, 0, wbuffer, -1, buffer, LANG_STRING_SIZE, NULL, NULL);

    return LOC_TEXT(buffer);
}
#else
#    include <algorithm>

struct LangString
{
    u32 Index;
    const char* Value;
};

#    define X(ID, VALUE) const char LOC_STR_VAR(ID)[] {u8##VALUE};
#    include ARTS_LANG_HEADER
#    undef X

static constexpr LangString LangStrings[] {
#    define X(ID, VALUE) {ID, LOC_STR_VAR(ID)},
#    include ARTS_LANG_HEADER
#    undef X
};

LocString* AngelReadString(u32 index)
{
    auto find = std::lower_bound(std::begin(LangStrings), std::end(LangStrings), index,
        [](const LangString& lhs, u32 index) { return lhs.Index < index; });

    const char* result = (find != std::end(LangStrings) && find->Index == index) ? find->Value : "INVALID_LANG_STRING";

    return LOC_TEXT(result);
}
#endif

char* GetLocTime(f32 time)
{
    static char buffer[64]; // FIXME: Static buffer

    if (time <= 0.0f)
    {
        arts_sprintf(buffer, "  ---  ");
    }
    else
    {
        double whole = 0.0;

        i32 centis = static_cast<i32>(std::modf(time + 0.005, &whole) * 100.0);
        i32 minutes = static_cast<i32>(whole / 60.0);
        i32 seconds = static_cast<i32>(whole - minutes * 60.0);

        arts_sprintf(buffer, "%d:%02d:%02d", minutes, seconds, centis);
    }

    return buffer;
}