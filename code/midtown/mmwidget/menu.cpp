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

define_dummy_symbol(mmwidget_menu);

#include "menu.h"

#include "arts7/midgets.h"
#include "eventq7/keys.h"
#include "manager.h"
#include "widget.h"

void UIMenu::PostSetup()
{}

void UIMenu::CheckInput()
{
    // Ignore any events while midgets are open
    if (MIDGETSPTR->IsOpen())
    {
        MenuMgr()->GetEventQ()->Clear();
        return;
    }

    eqEvent event;

    while (MenuMgr()->GetEventQ()->Pop(&event))
    {
        if (event.Type != eqEventType::Keyboard)
            continue;

        // Returns 1 if the menu is active, and the event is for a key press
        i32 is_key_press = ScanInput(&event);

        if (event.Key.Key == EQ_VK_ESCAPE)
        {
            if (is_key_press != 1)
            {
                ClearAction();
                continue;
            }
        }
        else if ((event.Key.Key < 8 || is_key_press != 1) &&
            (event.Key.Char < 8 || is_key_press != 1)) // Ignore mouse buttons?
        {
            continue;
        }

        KeyboardAction(event);
    }
}

i32 UIMenu::IsAnOptionMenu()
{
    return 0;
}

void UIMenu::ClearAction()
{
    state_ = 2;
}

b32 UIMenu::ScanInput(eqEvent* event)
{
    if (!IsNodeActive() || (event->Type != eqEventType::Keyboard) || !(event->Key.Modifiers & EQ_KMOD_DOWN))
        return false;

    // TODO: return result of ScanGlobalKeys?
    MenuMgr()->ScanGlobalKeys(event->Key.Key);

    return true;
}

uiWidget* UIMenu::FindWidget(i32 id)
{
    for (i32 i = 0; i < widget_count_; ++i)
    {
        uiWidget* widget = widgets_[i];

        if (widget->WidgetID == id)
            return widget;
    }

    return nullptr;
}
