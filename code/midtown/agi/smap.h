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
    agi:smap

    0x6573E0 | private: static double agiShadowMap::Converter | ?Converter@agiShadowMap@@0NA
*/

class agiShadowMap
{
private:
    // 0x6573E0 | ?Converter@agiShadowMap@@0NA
    static inline extern_var(0x2573E0_Offset, f64, Converter);
};
