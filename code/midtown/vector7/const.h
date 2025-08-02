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
    vector7:const

    0x5734D0 | void __cdecl SetMathSpeedSlow(void) | ?SetMathSpeedSlow@@YAXXZ
    0x5734F0 | void __cdecl SetMathSpeedMed(void) | ?SetMathSpeedMed@@YAXXZ
    0x573510 | void __cdecl SetMathSpeedFast(void) | ?SetMathSpeedFast@@YAXXZ
    0x573530 | void __cdecl ResetMathSpeed(void) | ?ResetMathSpeed@@YAXXZ
    0x573540 | public: void __thiscall IntArray::Init(int) | ?Init@IntArray@@QAEXH@Z
    0x5735B0 | public: void __thiscall IntArray::Delete(void) | ?Delete@IntArray@@QAEXXZ
    0x573600 | private: void __thiscall IntArray::NewTable(int) | ?NewTable@IntArray@@AAEXH@Z
    0x573670 | public: int & __thiscall IntArray::operator[](int) | ??AIntArray@@QAEAAHH@Z
    0x5736D0 | public: void __thiscall IntArray::operator=(class IntArray &) | ??4IntArray@@QAEXAAV0@@Z
    0x573790 | public: void __thiscall IntArray::BlockCopy(class IntArray &) | ?BlockCopy@IntArray@@QAEXAAV1@@Z
    0x573860 | public: void __thiscall FloatArray::Init(int) | ?Init@FloatArray@@QAEXH@Z
    0x5738D0 | public: void __thiscall FloatArray::Delete(void) | ?Delete@FloatArray@@QAEXXZ
    0x573920 | private: void __thiscall FloatArray::NewTable(int) | ?NewTable@FloatArray@@AAEXH@Z
    0x573990 | public: float & __thiscall FloatArray::operator[](int) | ??AFloatArray@@QAEAAMH@Z
    0x5739F0 | public: void __thiscall FloatArray::operator=(class FloatArray &) | ??4FloatArray@@QAEXAAV0@@Z
    0x573AB0 | public: void __thiscall FloatArray::BlockCopy(class FloatArray &) | ?BlockCopy@FloatArray@@QAEXAAV1@@Z
    0x909648 | int MathSpeed | ?MathSpeed@@3HA
    0x90964C | int OldMathSpeed | ?OldMathSpeed@@3HA
*/

// ?MathSpeed@@3HA
ARTS_IMPORT extern i32 MathSpeed;

// ?OldMathSpeed@@3HA
ARTS_IMPORT extern i32 OldMathSpeed;
