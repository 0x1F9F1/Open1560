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

// #define ARTS_STANDALONE

#define DIRECT3D_VERSION 0x0600
#define DIRECTDRAW_VERSION 0x0600
#define DIRECTINPUT_VERSION 0x0500
#define DIRECTSOUND_VERSION 0x0600

#define INITGUID

#include <algorithm>

#include "core/defines.h"

#include "core/hooking.h"
#include "core/primitives.h"

#include "core/pointer.h"

#include "core/refcount.h"

#include "core/assert.h"

#include "core/string.h"

#include "core/noncopyable.h"

#include "core/container.h"

#include "data7/global.h"

#include "data7/printer.h"
#include "data7/quitf.h"

#include "data7/metadeclare.h"

#include "arts7/node.h"

// #include <sol/sol.hpp>
