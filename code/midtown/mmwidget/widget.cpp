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

define_dummy_symbol(mmwidget_widget);

#include "widget.h"

#include "eventq7/eventq.h"

void uiWidget::Action(eqEvent /*arg1*/)
{}

void uiWidget::CaptureAction(eqEvent /*arg1*/)
{}

void uiWidget::Switch(i32 /*arg1*/)
{}

void uiWidget::EvalMouseX(f32 /*arg1*/)
{}

char* uiWidget::ReturnDescription()
{
    return nullptr;
}

void uiWidget::SetPosition(f32 /*arg1*/, f32 /*arg2*/)
{}

void uiWidget::AddToolTip(UIMenu* /*arg1*/, LocString* /*arg2*/)
{}

void uiWidget::ResetToolTip()
{}
