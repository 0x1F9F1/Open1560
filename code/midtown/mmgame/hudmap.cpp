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

define_dummy_symbol(mmgame_hudmap);

#include "hudmap.h"

#include "agi/bitmap.h"
#include "agi/pipeline.h"

agiBitmap* mmHudMap::Icon_Pink = nullptr;

mmHudMap::~mmHudMap()
{
    if (Icon_Pink)
    {
        Icon_Pink->Release();
        Icon_Pink = nullptr;
    }
}

void mmHudMap::DrawOpponents()
{
    for (i16 i = 0; i < NumOpps; ++i)
    {
        const OppIconInfo& icon = OppIcons[i];

        if (!icon.Enabled || !icon.Position)
            continue;

        agiBitmap* bitmap = nullptr;

        switch (icon.Color)
        {
            case 0xFF0000EF: bitmap = Icon_Blue; break;
            case 0xFF00EF00: bitmap = Icon_Green; break;
            case 0xFFEF0000: bitmap = Icon_Red; break;
            case 0xFFFFFF00: bitmap = Icon_Yellow; break;
            case 0xFFFF5A00: bitmap = Icon_Orange; break;
            case 0xFFB400FF: bitmap = Icon_Purple; break;
            case 0xFF00FFFF: bitmap = Icon_Cyan; break;
            case 0xFFFF0390:
                if (Icon_Pink == nullptr)
                {
                    // TODO: Move to mmHudMap::Init
                    // icon_grey is actually pink
                    Icon_Pink = Pipe()->GetBitmap("icon_grey", 0.0, 0.0, AGI_BITMAP_TRANSPARENT | AGI_BITMAP_OFFSCREEN);
                }

                bitmap = Icon_Pink;
                break;
        }

        if (bitmap)
            DrawOrientedBitmap(icon.Position, bitmap);
    }
}

run_once([] {
    create_hook(
        "mmPlayer::~mmPlayer", "Call mmHudMap Destructor", 0x42D453, &class_proxy<mmHudMap>::dtor, hook_type::call);
});