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

#include "linear.h"

class asDofCS final : public asLinearCS
{
public:
    // ??0asDofCS@@QAE@XZ
    ARTS_IMPORT asDofCS();

    // ??1asDofCS@@UAE@XZ | inline
    ARTS_EXPORT ~asDofCS() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asDofCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?FileIO@asDofCS@@QAEXPAVMiniParser@@@Z | unused
    void FileIO(MiniParser* arg1);

    // ?GetClass@asDofCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Reset@asDofCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@asDofCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@asDofCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

protected:
#ifdef ARTS_DEV_BUILD
    // ?ModeCB@asDofCS@@IAEXXZ
    ARTS_IMPORT void ModeCB();
#endif

    u8 gap88[0x70];
};

check_size(asDofCS, 0xF8);
