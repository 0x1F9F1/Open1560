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
    localize:localize

    0x520010 | char * __cdecl GetLocTime(float) | ?GetLocTime@@YAPADM@Z
    0x5200D0 | struct LocString * __cdecl AngelReadString(unsigned int) | ?AngelReadString@@YAPAULocString@@I@Z
*/

#include "string_ids.h"

// 0 | Use builtin strings
// 1 | Use AngelReadString with builtin strings
// 2 | Use AngelReadString with MMLANG
#define ARTS_LOCALIZE_MODE 0
#define ARTS_LANG_HEADER "lang_english.h"

struct LocString
{
    char Text[1];
};

#define LOC_TEXT(TEXT) ((struct LocString*) (TEXT))

// ?AngelReadString@@YAPAULocString@@I@Z
ARTS_EXPORT struct LocString* AngelReadString(u32 index);

// ?GetLocTime@@YAPADM@Z
ARTS_EXPORT char* GetLocTime(f32 time);

#if ARTS_LOCALIZE_MODE != 0
#    define LOC_STRING(ID) (AngelReadString(ID))
#else
#    define LOC_STR_VAR(ID) (ARTS_CONCAT(MM_LANG_STR_, ID))
#    define X(ID, VALUE) extern const char LOC_STR_VAR(ID)[];
#    include ARTS_LANG_HEADER
#    undef X
#    define LOC_STRING(ID) LOC_TEXT(LOC_STR_VAR(ID))
#endif

#define LOC_STR(ID) (LOC_STRING(ID)->Text)
