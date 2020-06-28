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
    mmwidget:cwarray

    0x4B7C70 | public: __thiscall UICWArray::UICWArray(void) | ??0UICWArray@@QAE@XZ
    0x4B7D30 | public: virtual __thiscall UICWArray::~UICWArray(void) | ??1UICWArray@@UAE@XZ
    0x4B7D40 | public: virtual void __thiscall UICWArray::Reset(void) | ?Reset@UICWArray@@UAEXXZ
    0x4B7D50 | public: void __thiscall UICWArray::Init(float,float,float,float,int,class Callback) | ?Init@UICWArray@@QAEXMMMMHVCallback@@@Z
    0x4B7FB0 | public: void __thiscall UICWArray::VScrollCB(void) | ?VScrollCB@UICWArray@@QAEXXZ
    0x4B8020 | public: void __thiscall UICWArray::SetVScrollVals(void) | ?SetVScrollVals@UICWArray@@QAEXXZ
    0x4B8090 | public: void __thiscall UICWArray::SetVScrollPos(void) | ?SetVScrollPos@UICWArray@@QAEXXZ
    0x4B80C0 | public: void __thiscall UICWArray::SetStartOffset(int) | ?SetStartOffset@UICWArray@@QAEXH@Z
    0x4B8100 | public: void __thiscall UICWArray::Redraw(void) | ?Redraw@UICWArray@@QAEXXZ
    0x4B8260 | public: virtual void __thiscall UICWArray::Switch(int) | ?Switch@UICWArray@@UAEXH@Z
    0x4B82A0 | public: virtual void __thiscall UICWArray::Action(union eqEvent) | ?Action@UICWArray@@UAEXTeqEvent@@@Z
    0x4B83D0 | public: virtual void __thiscall UICWArray::CaptureAction(union eqEvent) | ?CaptureAction@UICWArray@@UAEXTeqEvent@@@Z
    0x4B8440 | public: virtual void __thiscall UICWArray::Update(void) | ?Update@UICWArray@@UAEXXZ
    0x4B84C0 | public: void __thiscall UICWArray::EnterCapture(int) | ?EnterCapture@UICWArray@@QAEXH@Z
    0x4B8530 | public: void __thiscall UICWArray::ForceCapture(void) | ?ForceCapture@UICWArray@@QAEXXZ
    0x4B8560 | public: void __thiscall UICWArray::AcceptCapture(void) | ?AcceptCapture@UICWArray@@QAEXXZ
    0x4B85B0 | public: void __thiscall UICWArray::ResetCapture(void) | ?ResetCapture@UICWArray@@QAEXXZ
    0x4B85E0 | public: void __thiscall UICWArray::CheckCapture(void) | ?CheckCapture@UICWArray@@QAEXXZ
    0x4B8690 | public: void __thiscall UICWArray::SaveCFG(void) | ?SaveCFG@UICWArray@@QAEXXZ
    0x4B86D0 | public: void __thiscall UICWArray::LoadCFG(void) | ?LoadCFG@UICWArray@@QAEXXZ
    0x4B8720 | public: void __thiscall UICWArray::DefaultCFG(void) | ?DefaultCFG@UICWArray@@QAEXXZ
    0x4B8740 | public: void __thiscall UICWArray::DebugForceSetting(void) | ?DebugForceSetting@UICWArray@@QAEXXZ
    0x4B8760 | public: virtual void * __thiscall UICWArray::`vector deleting destructor'(unsigned int) | ??_EUICWArray@@UAEPAXI@Z
    0x4B8760 | public: virtual void * __thiscall UICWArray::`scalar deleting destructor'(unsigned int) | ??_GUICWArray@@UAEPAXI@Z
    0x4B8790 | public: virtual void * __thiscall UIControlWidget::`vector deleting destructor'(unsigned int) | ??_EUIControlWidget@@UAEPAXI@Z
    0x61E9F0 | const UICWArray::`vftable' | ??_7UICWArray@@6B@
*/

#include "widget.h"

class UICWArray : public uiWidget
{
    // const UICWArray::`vftable' @ 0x61E9F0

public:
    // 0x4B7C70 | ??0UICWArray@@QAE@XZ
    ARTS_IMPORT UICWArray();

    // 0x4B8760 | ??_GUICWArray@@UAEPAXI@Z
    // 0x4B8760 | ??_EUICWArray@@UAEPAXI@Z
    // 0x4B7D30 | ??1UICWArray@@UAE@XZ
    ARTS_IMPORT ~UICWArray() override = default;

    // 0x4B8560 | ?AcceptCapture@UICWArray@@QAEXXZ
    ARTS_IMPORT void AcceptCapture();

    // 0x4B82A0 | ?Action@UICWArray@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(union eqEvent arg1) override;

    // 0x4B83D0 | ?CaptureAction@UICWArray@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void CaptureAction(union eqEvent arg1) override;

    // 0x4B85E0 | ?CheckCapture@UICWArray@@QAEXXZ
    ARTS_IMPORT void CheckCapture();

    // 0x4B8740 | ?DebugForceSetting@UICWArray@@QAEXXZ | unused
    ARTS_IMPORT void DebugForceSetting();

    // 0x4B8720 | ?DefaultCFG@UICWArray@@QAEXXZ
    ARTS_IMPORT void DefaultCFG();

    // 0x4B84C0 | ?EnterCapture@UICWArray@@QAEXH@Z
    ARTS_IMPORT void EnterCapture(i32 arg1);

    // 0x4B8530 | ?ForceCapture@UICWArray@@QAEXXZ
    ARTS_IMPORT void ForceCapture();

    // 0x4B7D50 | ?Init@UICWArray@@QAEXMMMMHVCallback@@@Z
    ARTS_IMPORT void Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5, class Callback arg6);

    // 0x4B86D0 | ?LoadCFG@UICWArray@@QAEXXZ | unused
    ARTS_IMPORT void LoadCFG();

    // 0x4B8100 | ?Redraw@UICWArray@@QAEXXZ
    ARTS_IMPORT void Redraw();

    // 0x4B7D40 | ?Reset@UICWArray@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4B85B0 | ?ResetCapture@UICWArray@@QAEXXZ
    ARTS_IMPORT void ResetCapture();

    // 0x4B8690 | ?SaveCFG@UICWArray@@QAEXXZ | unused
    ARTS_IMPORT void SaveCFG();

    // 0x4B80C0 | ?SetStartOffset@UICWArray@@QAEXH@Z | unused
    ARTS_IMPORT void SetStartOffset(i32 arg1);

    // 0x4B8090 | ?SetVScrollPos@UICWArray@@QAEXXZ
    ARTS_IMPORT void SetVScrollPos();

    // 0x4B8020 | ?SetVScrollVals@UICWArray@@QAEXXZ
    ARTS_IMPORT void SetVScrollVals();

    // 0x4B8260 | ?Switch@UICWArray@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // 0x4B8440 | ?Update@UICWArray@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4B7FB0 | ?VScrollCB@UICWArray@@QAEXXZ
    ARTS_IMPORT void VScrollCB();

    u8 gap74[0x68];
};

check_size(UICWArray, 0xDC);
