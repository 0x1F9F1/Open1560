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

#include "arts7/node.h"

/*
    mmeffects:card2d

    0x4FE150 | public: __thiscall Card2D::Card2D(void) | ??0Card2D@@QAE@XZ
    0x4FE170 | public: void __thiscall Card2D::Init(class asCamera *,float,float,float,float,float) | ?Init@Card2D@@QAEXPAVasCamera@@MMMMM@Z
    0x4FE1B0 | public: void __thiscall Card2D::SetDimensions(float,float,float,float) | ?SetDimensions@Card2D@@QAEXMMMM@Z
    0x4FE2A0 | public: void __thiscall Card2D::SetPosition(float,float) | ?SetPosition@Card2D@@QAEXMM@Z
    0x4FE2C0 | public: void __thiscall Card2D::SetAlpha(float) | ?SetAlpha@Card2D@@QAEXM@Z
    0x4FE320 | public: virtual void __thiscall Card2D::Update(void) | ?Update@Card2D@@UAEXXZ
    0x4FE330 | private: virtual void __thiscall Card2D::Cull(void) | ?Cull@Card2D@@EAEXXZ
    0x4FE540 | private: virtual void __thiscall Card2D::AddWidgets(class Bank *) | ?AddWidgets@Card2D@@EAEXPAVBank@@@Z
    0x4FE620 | public: virtual void * __thiscall Card2D::`scalar deleting destructor'(unsigned int) | ??_GCard2D@@UAEPAXI@Z
    0x4FE620 | public: virtual void * __thiscall Card2D::`vector deleting destructor'(unsigned int) | ??_ECard2D@@UAEPAXI@Z
    0x4FE650 | public: virtual __thiscall Card2D::~Card2D(void) | ??1Card2D@@UAE@XZ
    0x6205B8 | const Card2D::`vftable' | ??_7Card2D@@6B@
*/

class Card2D : public asNode
{
    // const Card2D::`vftable' @ 0x6205B8

public:
    // 0x4FE150 | ??0Card2D@@QAE@XZ
    Card2D();

    // 0x4FE620 | ??_ECard2D@@UAEPAXI@Z
    // 0x4FE650 | ??1Card2D@@UAE@XZ
    ~Card2D() override;

    // 0x4FE170 | ?Init@Card2D@@QAEXPAVasCamera@@MMMMM@Z
    void Init(class asCamera* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

    // 0x4FE2C0 | ?SetAlpha@Card2D@@QAEXM@Z
    void SetAlpha(f32 arg1);

    // 0x49C530 | ?SetColor@Card2D@@QAEXVVector4@@@Z
    void SetColor(class Vector4 arg1);

    // 0x4FE1B0 | ?SetDimensions@Card2D@@QAEXMMMM@Z
    void SetDimensions(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x4FE2A0 | ?SetPosition@Card2D@@QAEXMM@Z
    void SetPosition(f32 arg1, f32 arg2);

    // 0x4FE320 | ?Update@Card2D@@UAEXXZ
    void Update() override;

private:
    // 0x4FE540 | ?AddWidgets@Card2D@@EAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x4FE330 | ?Cull@Card2D@@EAEXXZ
    void Cull() override;
};

check_size(Card2D, 0x38);
