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

define_dummy_symbol(mmwidget_textfield);

#include "textfield.h"

#include "manager.h"

#include "menu.h"
#include "mmeffects/card2d.h"
#include "mmeffects/mmtext.h"
#include "pcwindis/dxinit.h"
#include "vector7/vector4.h"

#include <SDL3/SDL_keyboard.h>

void UITextField::ToggleField(i32 state)
{
    if (MenuMgr()->HasActiveWidget() && (state == 0) && (LocString513 == 1))
        MenuMgr()->RegisterWidgetFocus(0, X, Y, Width, Height, this);

    if (state == -1)
        Enabled = Enabled == 0;
    else
        Enabled = state != 0;

    if (Enabled)
    {
        Text->SetFGColor(MenuMgr()->GetFGColor(3));
        Card->SetColor(Vector4 {0.0f, 0.0f, 0.0f, 1.0f});
    }
    else
    {
        Text->SetFGColor(MenuMgr()->GetFGColor(0));
        Card->SetColor(Vector4 {0.0f, 0.0f, 0.0f, 0.0f});
    }

    if (!(Flags & 0x80) && !(Flags & 0x100))
    {
        if (Enabled)
        {
            MenuMgr()->SetActiveImeField(this);

            SetCompositionWindow();
        }
        else
        {
            if (SDL_TextInputActive(g_MainWindow))
            {
                Displayf("Disabled Text Input");
                SDL_StopTextInput(g_MainWindow);
            }
        }
    }
}

void UITextField::SetCompositionWindow()
{
    // TODO: Call SDL_SetTextInputArea

    if (Enabled)
    {
        if (!SDL_TextInputActive(g_MainWindow))
        {
            Displayf("Enabled Text Input");
            SDL_StartTextInput(g_MainWindow);
        }
    }
}
