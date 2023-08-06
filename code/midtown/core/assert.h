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

struct ArSourceLocation
{
    const char* filename;
    const char* function;
    unsigned int linenum;
};

struct ArAssertData
{
    const char* condition;
    const char* message;
    ArSourceLocation location;
};

[[noreturn]] ARTS_NOINLINE void ARTS_FASTCALL ArReportAssertion(const ArAssertData& data);

#define AR_SOURCE_LOCATION                                             \
    ::ArSourceLocation                                                 \
    {                                                                  \
        ARTS_FILE, ARTS_FUNCTION, static_cast<unsigned int>(ARTS_LINE) \
    }

#define ArEnabledAssert(CONDITION, MESSAGE)                                                           \
    do                                                                                                \
    {                                                                                                 \
        if (ARTS_UNLIKELY(!(CONDITION)))                                                              \
        {                                                                                             \
            static constexpr ::ArAssertData ar_assert_data {#CONDITION, MESSAGE, AR_SOURCE_LOCATION}; \
            ArReportAssertion(ar_assert_data);                                                        \
        }                                                                                             \
    } while (false)

#define ArDisabledAssert(CONDITION, MESSAGE) static_cast<void>(sizeof(!(CONDITION)))

#ifdef ARTS_DEBUG
#    define ArDebugAssert ArEnabledAssert
#else
#    define ArDebugAssert ArDisabledAssert
#endif

#define ArAssert ArEnabledAssert
