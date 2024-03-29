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

#include <hedley.h>

#define ARTS_FORCEINLINE HEDLEY_ALWAYS_INLINE
#define ARTS_NOINLINE HEDLEY_NEVER_INLINE

#define ARTS_LIKELY HEDLEY_LIKELY
#define ARTS_UNLIKELY HEDLEY_UNLIKELY

#define ARTS_ASSUME HEDLEY_ASSUME

#define ARTS_CONCAT HEDLEY_CONCAT
#define ARTS_STRINGIFY HEDLEY_STRINGIFY

#define ARTS_RESTRICT HEDLEY_RESTRICT

#ifdef ARTS_STANDALONE
#    define ARTS_IMPORT
#    define ARTS_EXPORT
#else
#    define ARTS_IMPORT HEDLEY_IMPORT
#    define ARTS_EXPORT HEDLEY_PUBLIC
#endif

#ifndef ARTS_FUNCTION
#    if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#        define ARTS_FUNCTION __func__
#    elif ((__GNUC__ >= 2) || defined(_MSC_VER) || defined(__WATCOMC__))
#        define ARTS_FUNCTION __FUNCTION__
#    else
#        define ARTS_FUNCTION "???"
#    endif
#endif

#ifndef ARTS_FILE
#    define ARTS_FILE __FILE__
#endif

#ifndef ARTS_LINE
#    define ARTS_LINE ARTS_CONCAT(__LINE__, L) // Workaround Edit and Continue
#endif

#define ARTS_CDECL __cdecl
#define ARTS_STDCALL __stdcall
#define ARTS_FASTCALL __fastcall

#if _MSC_VER > 1400
#    include <sal.h>
#    define ARTS_FORMAT_STRING _In_z_ _Printf_format_string_
#else
#    define ARTS_FORMAT_STRING
#endif /* _MSC_VER */

#define ARTS_DIAGNOSTIC_PUSH HEDLEY_DIAGNOSTIC_PUSH
#define ARTS_DIAGNOSTIC_POP HEDLEY_DIAGNOSTIC_POP
#define ARTS_PRAGMA HEDLEY_PRAGMA

#if defined(_MSC_VER)
#    define ARTS_MSVC_DIAGNOSTIC_IGNORED(INDEX) ARTS_PRAGMA(warning(disable : INDEX))
#else
#    define ARTS_MSVC_DIAGNOSTIC_IGNORED(NAME)
#endif

#if defined(__clang__)
#    define ARTS_CLANG_DIAGNOSTIC_IGNORED(NAME) ARTS_PRAGMA(clang diagnostic ignored NAME)
#else
#    define ARTS_CLANG_DIAGNOSTIC_IGNORED(NAME)
#endif

#define ARTS_HAS_BUILTIN HEDLEY_HAS_BUILTIN
