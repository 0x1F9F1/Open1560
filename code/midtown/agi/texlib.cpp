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

define_dummy_symbol(agi_texlib);

#include "texlib.h"

agiLib<class agiTexParameters, class agiTexDef>::agiLib<class agiTexParameters, class agiTexDef>()
{
    unimplemented();
}

agiLib<class agiTexParameters, class agiTexDef>::~agiLib<class agiTexParameters, class agiTexDef>()
{
    unimplemented();
}

i32 agiLib<class agiTexParameters, class agiTexDef>::Add(class agiTexParameters& arg1)
{
    return stub<thiscall_t<i32, agiLib<class agiTexParameters, class agiTexDef>*, class agiTexParameters&>>(
        0x8FB10_Offset, this, arg1);
}

void agiLib<class agiTexParameters, class agiTexDef>::Init(i32 arg1)
{
    return stub<thiscall_t<void, agiLib<class agiTexParameters, class agiTexDef>*, i32>>(0x15A190_Offset, this, arg1);
}

void agiLib<class agiTexParameters, class agiTexDef>::Kill()
{
    return stub<thiscall_t<void, agiLib<class agiTexParameters, class agiTexDef>*>>(0x15A140_Offset, this);
}
