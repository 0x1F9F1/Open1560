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
#include "mmcityinfo/state.h"

#if ARTS_TARGET_BUILD < 1588
agiBitmap* mmHudMap::Icon_Pink = nullptr;
#endif

mmHudMap::~mmHudMap()
{
#if ARTS_TARGET_BUILD < 1588
    if (Icon_Pink)
    {
        Icon_Pink->Release();
        Icon_Pink = nullptr;
    }
#endif
}

void mmHudMap::Cull()
{
    Pipe()->CopyBitmap(MapDstX, MapDstY, Current, MapSrcX, MapSrcY, MapWidth, MapHeight);

    DrawMisc();
    DrawCops();
    DrawOpponents();
    DrawWaypoints();
    DrawOrientedBitmap(Transform, Icon_Player);

    if (MMSTATE.GameMode == mmGameMode::CnR)
        DrawCopsnRobbers();

    if (Mode == 3)
        Pipe()->ClearBorder(MapDstX, MapDstY, MapWidth, MapHeight, 0);
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
#if ARTS_TARGET_BUILD < 1588
                if (Icon_Pink == nullptr)
                {
                    // TODO: Move to mmHudMap::Init
                    // icon_grey is actually pink
                    Icon_Pink = AsRaw(Pipe()->GetBitmap("icon_grey", 0.0, 0.0, BITMAP_TRANSPARENT | BITMAP_OFFSCREEN));
                }
#endif

                bitmap = Icon_Pink;
                break;
        }

        if (bitmap)
            DrawOrientedBitmap(icon.Position, bitmap);
    }
}

hook_func(INIT_main, [] {
    create_hook(
        "mmPlayer::~mmPlayer", "Call mmHudMap Destructor", 0x42D453, &class_proxy<mmHudMap>::dtor, hook_type::call);

    // OppIconInfo.Place
    create_packed_patch<u32>("mmMultiCR::OppStealGold", "Icon Number", 0x41D93C + 6, OPP_ICON_GOLD);
    create_packed_patch<u8>("mmIcons::Cull", "Icon Number", 0x426646 + 2, OPP_ICON_GOLD);
    create_packed_patch<u8>("mmIcons::Cull", "Icon Number", 0x426731 + 4, OPP_ICON_BLANK);
    create_packed_patch<u32>("mmMultiCR::GameMessage", "Icon Number", 0x41EC44 + 2, OPP_ICON_BLANK);
    create_packed_patch<u32>("mmMultiCR::GameMessage", "Icon Number", 0x41EB00 + 3, OPP_ICON_BLANK);
    create_packed_patch<u32>("mmGameMulti::RegisterMapNetObjects", "Icon Number", 0x431F6E + 3, OPP_ICON_BLANK);
    create_packed_patch<u32>("mmGameMulti::DeactivateMapNetObject", "Icon Number", 0x43201A + 6, OPP_ICON_BLANK);
});
