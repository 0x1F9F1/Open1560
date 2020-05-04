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
