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
    mmgame:cd

    0x422FF0 | public: __thiscall mmCDPlayer::mmCDPlayer(void) | ??0mmCDPlayer@@QAE@XZ
    0x423080 | public: void __thiscall mmCDPlayer::Init(class mmHUD *) | ?Init@mmCDPlayer@@QAEXPAVmmHUD@@@Z
    0x423190 | public: virtual void __thiscall mmCDPlayer::Reset(void) | ?Reset@mmCDPlayer@@UAEXXZ
    0x4231A0 | public: virtual void __thiscall mmCDPlayer::Update(void) | ?Update@mmCDPlayer@@UAEXXZ
    0x423210 | public: virtual void __thiscall mmCDPlayer::Cull(void) | ?Cull@mmCDPlayer@@UAEXXZ
    0x423400 | public: void __thiscall mmCDPlayer::PlayStop(void) | ?PlayStop@mmCDPlayer@@QAEXXZ
    0x423450 | public: void __thiscall mmCDPlayer::NextTrack(void) | ?NextTrack@mmCDPlayer@@QAEXXZ
    0x4234C0 | public: virtual void __thiscall mmCDPlayer::AddWidgets(class Bank *) | ?AddWidgets@mmCDPlayer@@UAEXPAVBank@@@Z
    0x423750 | public: void __thiscall mmCDPlayer::PrevTrack(void) | ?PrevTrack@mmCDPlayer@@QAEXXZ
    0x4237C0 | public: void __thiscall mmCDPlayer::Toggle(void) | ?Toggle@mmCDPlayer@@QAEXXZ
    0x423810 | public: virtual void * __thiscall mmCDPlayer::`vector deleting destructor'(unsigned int) | ??_EmmCDPlayer@@UAEPAXI@Z
    0x423810 | public: virtual void * __thiscall mmCDPlayer::`scalar deleting destructor'(unsigned int) | ??_GmmCDPlayer@@UAEPAXI@Z
    0x61AB40 | const mmCDPlayer::`vftable' | ??_7mmCDPlayer@@6B@
*/

#include "arts7/node.h"

class mmCDPlayer final : public asNode
{
    // const mmCDPlayer::`vftable' @ 0x61AB40

public:
    // 0x422FF0 | ??0mmCDPlayer@@QAE@XZ
    ARTS_IMPORT mmCDPlayer();

    // 0x423810 | ??_GmmCDPlayer@@UAEPAXI@Z
    // 0x423810 | ??_EmmCDPlayer@@UAEPAXI@Z
    // 0x406960 | ??1mmCDPlayer@@UAE@XZ | inline
    ARTS_IMPORT ~mmCDPlayer() override;

#ifdef ARTS_DEV_BUILD
    // 0x4234C0 | ?AddWidgets@mmCDPlayer@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // 0x423210 | ?Cull@mmCDPlayer@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x423080 | ?Init@mmCDPlayer@@QAEXPAVmmHUD@@@Z
    ARTS_IMPORT void Init(class mmHUD* arg1);

    // 0x423450 | ?NextTrack@mmCDPlayer@@QAEXXZ
    ARTS_IMPORT void NextTrack();

    // 0x423400 | ?PlayStop@mmCDPlayer@@QAEXXZ
    ARTS_IMPORT void PlayStop();

    // 0x423750 | ?PrevTrack@mmCDPlayer@@QAEXXZ
    ARTS_IMPORT void PrevTrack();

    // 0x423190 | ?Reset@mmCDPlayer@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4237C0 | ?Toggle@mmCDPlayer@@QAEXXZ
    ARTS_IMPORT void Toggle();

    // 0x4231A0 | ?Update@mmCDPlayer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x12C];
};

check_size(mmCDPlayer, 0x14C);
