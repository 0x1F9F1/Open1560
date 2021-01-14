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

#include <algorithm>

struct LangString
{
    u32 Index;
    const char* Value;
};

#define X(ID, VALUE) const char LOC_STR_VAR(ID)[] {VALUE};
#include "lang_english.h"
#undef X

static constexpr LangString LangStrings[] {
#define X(ID, VALUE) {ID, LOC_STR_VAR(ID)},
#include "lang_english.h"
#undef X
};

LocString* AngelReadString(u32 index)
{
    auto find = std::lower_bound(std::begin(LangStrings), std::end(LangStrings), index,
        [](const LangString& lhs, u32 index) { return lhs.Index < index; });

    const char* result = (find != std::end(LangStrings) && find->Index == index) ? find->Value : "INVALID_LANG_STRING";

    return LOC_TEXT(result);
}
