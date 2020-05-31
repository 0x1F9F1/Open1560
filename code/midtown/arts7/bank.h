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
    arts7:bank
*/

#include "data7/callback.h"

class Bank
{
    // const Bank::`vftable' @ 0x620C40

public:
    virtual void SetLabel(const char* arg1) = 0;
    virtual class bkWindow* AddTitle(const char* arg1) = 0;
    virtual class bkButton* AddButton(const char* arg1, class Callback arg2) = 0;
    virtual class bkButton* AddToggle(const char* arg1, i32* arg2, i32 arg3, class Callback arg4) = 0;
    virtual class bkButton* AddMex(const char* arg1, i32* arg2, i32 arg3, class Callback arg4) = 0;
    virtual class bkButton* AddText(const char* arg1, class Callback arg2) = 0;
    virtual class bkButton* AddText(class Callback arg1) = 0;
    virtual class bkSlider* AddSlider(
        const char* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6) = 0;
    virtual class bkSlider* AddSlider(
        const char* arg1, u32* arg2, u32 arg3, u32 arg4, f32 arg5, class Callback arg6) = 0;
    virtual class bkSlider* AddSlider(
        const char* arg1, i32* arg2, i32 arg3, i32 arg4, f32 arg5, class Callback arg6) = 0;
    virtual class bkSlider* AddSlider(
        const char* arg1, u16* arg2, u16 arg3, u16 arg4, f32 arg5, class Callback arg6) = 0;
    virtual class bkSlider* AddSlider(
        const char* arg1, i16* arg2, i16 arg3, i16 arg4, f32 arg5, class Callback arg6) = 0;
    virtual class bkSlider* AddSlider(const char* arg1, u8* arg2, u8 arg3, u8 arg4, f32 arg5, class Callback arg6) = 0;
    virtual class bkSlider* AddSlider(
        const char* arg1, const char* arg2, char arg3, char arg4, f32 arg5, class Callback arg6) = 0;
    virtual class bkSlider* AddTextSlider(
        const char* arg1, const char* arg2, i32* arg3, f32 arg4, class Callback arg5) = 0;
    virtual void AddVector(
        const char* arg1, class Vector4* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6) = 0;
    virtual void AddVector(
        const char* arg1, class Vector3* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6) = 0;
    virtual void AddVector(
        const char* arg1, class Vector2* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6) = 0;
    virtual void AddColor(const char* arg1, class Vector4* arg2, class Callback arg3) = 0;
    virtual void AddColor(const char* arg1, class Vector3* arg2, class Callback arg3) = 0;
    virtual void AddFileButton(const char* arg1, class Callback arg2) = 0;
    virtual void PushSection(const char* arg1, i32 arg2) = 0;
    virtual void PopSection() = 0;
    virtual void PushColumn(i32 arg1) = 0;
    virtual void PopColumn() = 0;
    virtual void Off() = 0;
};

check_size(Bank, 0x4);
