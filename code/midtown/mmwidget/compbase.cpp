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

define_dummy_symbol(mmwidget_compbase);

#include "compbase.h"

#include "eventq7/eventq.h"

void mmCompBase::Action(union eqEvent /*arg1*/, f32 /*arg2*/, f32 /*arg3*/, i32 /*arg4*/)
{}

void mmCompBase::Action(union eqEvent /*arg1*/)
{}

void mmCompBase::CaptureAction(union eqEvent /*arg1*/)
{}

void mmCompBase::EvalMouseXY(f32 /*arg1*/, f32 /*arg2*/)
{}

void mmCompBase::Highlight(class mmTextNode* /*arg1*/, i32 /*arg2*/)
{}

void mmCompBase::Reset()
{}
