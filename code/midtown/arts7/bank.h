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

class bkButton;
class bkSlider;
class bkWindow;

class Bank
{
public:
    virtual void SetLabel(const char* title) = 0;
    virtual bkWindow* AddTitle(const char* title) = 0;
    virtual bkButton* AddButton(const char* title, Callback cb) = 0;
    virtual bkButton* AddToggle(const char* title, i32* value, i32 arg3, Callback cb) = 0;
    virtual bkButton* AddMex(const char* title, i32* value, i32 arg3, Callback cb) = 0;
    virtual bkButton* AddText(Callback cb) = 0;
    virtual bkButton* AddText(const char* title, Callback cb) = 0;
    virtual bkSlider* AddSlider(const char* title, i8* value, i8 min, i8 max, f32 step, Callback cb) = 0;
    virtual bkSlider* AddSlider(const char* title, u8* value, u8 min, u8 max, f32 step, Callback cb) = 0;
    virtual bkSlider* AddSlider(const char* title, i16* value, i16 min, i16 max, f32 step, Callback cb) = 0;
    virtual bkSlider* AddSlider(const char* title, u16* value, u16 min, u16 max, f32 step, Callback cb) = 0;
    virtual bkSlider* AddSlider(const char* title, i32* value, i32 min, i32 max, f32 step, Callback cb) = 0;
    virtual bkSlider* AddSlider(const char* title, u32* value, u32 min, u32 max, f32 step, Callback cb) = 0;
    virtual bkSlider* AddSlider(const char* title, f32* value, f32 min, f32 max, f32 step, Callback cb) = 0;
    virtual bkSlider* AddTextSlider(const char* title, const char* arg2, i32* value, f32 arg4, Callback cb) = 0;
    virtual void AddVector(const char* title, Vector2* arg2, f32 arg3, f32 arg4, f32 arg5, Callback cb) = 0;
    virtual void AddVector(const char* title, Vector3* arg2, f32 arg3, f32 arg4, f32 arg5, Callback cb) = 0;
    virtual void AddVector(const char* title, Vector4* arg2, f32 arg3, f32 arg4, f32 arg5, Callback cb) = 0;
    virtual void AddColor(const char* title, Vector3* arg2, Callback cb) = 0;
    virtual void AddColor(const char* title, Vector4* arg2, Callback cb) = 0;
    virtual void AddFileButton(const char* title, Callback cb) = 0;
    virtual void PushSection(const char* title, i32 arg2) = 0;
    virtual void PopSection() = 0;
    virtual void PushColumn(i32 arg1) = 0;
    virtual void PopColumn() = 0;
    virtual void Off() = 0;
};

check_size(Bank, 0x4);
