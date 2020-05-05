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
    agi:bitmap

    0x55A3B0 | public: __thiscall agiBitmap::agiBitmap(class agiPipeline *) | ??0agiBitmap@@QAE@PAVagiPipeline@@@Z
    0x55A3F0 | public: int __thiscall agiBitmap::Init(char *,float,float,int) | ?Init@agiBitmap@@QAEHPADMMH@Z
    0x55A600 | public: void __thiscall agiBitmap::SetTransparency(int) | ?SetTransparency@agiBitmap@@QAEXH@Z
    0x55A630 | public: virtual void __thiscall agiBitmap::UpdateFlags(void) | ?UpdateFlags@agiBitmap@@UAEXXZ
    0x55A640 | protected: virtual __thiscall agiBitmap::~agiBitmap(void) | ??1agiBitmap@@MAE@XZ
    0x55A6D0 | public: virtual char * __thiscall agiBitmap::GetName(void) | ?GetName@agiBitmap@@UAEPADXZ
    0x55A6F0 | protected: virtual void * __thiscall agiBitmap::`vector deleting destructor'(unsigned int) | ??_EagiBitmap@@MAEPAXI@Z
    0x55A6F0 | protected: virtual void * __thiscall agiBitmap::`scalar deleting destructor'(unsigned int) | ??_GagiBitmap@@MAEPAXI@Z
    0x6216F0 | const agiBitmap::`vftable' | ??_7agiBitmap@@6B@
    0x6570F0 | char * BitmapSearchPath | ?BitmapSearchPath@@3PADA
    0x903140 | class HashTable BitmapHash | ?BitmapHash@@3VHashTable@@A
*/

#include "refresh.h"

class agiBitmap : public agiRefreshable
{
    // const agiBitmap::`vftable' @ 0x6216F0

public:
    // 0x55A3B0 | ??0agiBitmap@@QAE@PAVagiPipeline@@@Z
    agiBitmap(class agiPipeline* arg1);

    // 0x55A630 | ?UpdateFlags@agiBitmap@@UAEXXZ
    virtual void UpdateFlags();

    // 0x55A6D0 | ?GetName@agiBitmap@@UAEPADXZ
    char* GetName() override;

    // 0x55A3F0 | ?Init@agiBitmap@@QAEHPADMMH@Z
    i32 Init(char* arg1, f32 arg2, f32 arg3, i32 arg4);

    // 0x55A600 | ?SetTransparency@agiBitmap@@QAEXH@Z
    void SetTransparency(i32 arg1);

protected:
    // 0x55A6F0 | ??_GagiBitmap@@MAEPAXI@Z
    // 0x55A640 | ??1agiBitmap@@MAE@XZ
    ~agiBitmap() override;
};

check_size(agiBitmap, 0x40);

// 0x903140 | ?BitmapHash@@3VHashTable@@A
inline extern_var(0x503140_Offset, class HashTable, BitmapHash);

// 0x6570F0 | ?BitmapSearchPath@@3PADA
inline extern_var(0x2570F0_Offset, char*, BitmapSearchPath);
