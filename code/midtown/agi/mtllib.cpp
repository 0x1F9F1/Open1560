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

define_dummy_symbol(agi_mtllib);

#include "mtllib.h"

agiLib<class agiMtlParameters, class agiMtlDef>::agiLib<class agiMtlParameters, class agiMtlDef>()
{
    unimplemented();
}

agiLib<class agiMtlParameters, class agiMtlDef>::~agiLib<class agiMtlParameters, class agiMtlDef>()
{
    unimplemented();
}

i32 agiLib<class agiMtlParameters, class agiMtlDef>::Add(class agiMtlParameters& arg1)
{
    return stub<thiscall_t<i32, agiLib<class agiMtlParameters, class agiMtlDef>*, class agiMtlParameters&>>(
        0x559D90, this, arg1);
}

void agiLib<class agiMtlParameters, class agiMtlDef>::Init(i32 arg1)
{
    return stub<thiscall_t<void, agiLib<class agiMtlParameters, class agiMtlDef>*, i32>>(0x55A080, this, arg1);
}

void agiLib<class agiMtlParameters, class agiMtlDef>::Kill()
{
    return stub<thiscall_t<void, agiLib<class agiMtlParameters, class agiMtlDef>*>>(0x55A030, this);
}
