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

define_dummy_symbol(agi_getdlp);

#include "getdlp.h"

#include "stream/hfsystem.h"

// ?LibOutOfDate@@YAHPAD0@Z
ARTS_IMPORT /*static*/ i32 LibOutOfDate(char* arg1, char* arg2);

b32 OutOfDate(char* lhs, char* rhs)
{
    struct stat lhs_stat;
    struct stat rhs_stat;

    if (stat(FQN(rhs), &rhs_stat))
        return false;

    if (stat(FQN(lhs), &lhs_stat))
        return true;

    return lhs_stat.st_mtime < rhs_stat.st_mtime;
}
