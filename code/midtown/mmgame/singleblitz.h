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
    mmgame:singleblitz

    0x412EF0 | public: __thiscall mmSingleBlitz::mmSingleBlitz(void) | ??0mmSingleBlitz@@QAE@XZ
    0x412F90 | public: virtual __thiscall mmSingleBlitz::~mmSingleBlitz(void) | ??1mmSingleBlitz@@UAE@XZ
    0x413060 | public: int __thiscall mmSingleBlitz::Init(void) | ?Init@mmSingleBlitz@@QAEHXZ
    0x4131E0 | public: virtual void __thiscall mmSingleBlitz::InitMyPlayer(void) | ?InitMyPlayer@mmSingleBlitz@@UAEXXZ
    0x413250 | public: virtual void __thiscall mmSingleBlitz::InitHUD(void) | ?InitHUD@mmSingleBlitz@@UAEXXZ
    0x4132D0 | public: virtual void __thiscall mmSingleBlitz::InitGameObjects(void) | ?InitGameObjects@mmSingleBlitz@@UAEXXZ
    0x413540 | public: virtual void __thiscall mmSingleBlitz::InitOtherPlayers(void) | ?InitOtherPlayers@mmSingleBlitz@@UAEXXZ
    0x413550 | public: virtual void __thiscall mmSingleBlitz::Reset(void) | ?Reset@mmSingleBlitz@@UAEXXZ
    0x413660 | private: void __thiscall mmSingleBlitz::EnableRacers(void) | ?EnableRacers@mmSingleBlitz@@AAEXXZ
    0x4136F0 | private: void __thiscall mmSingleBlitz::DisableRacers(void) | ?DisableRacers@mmSingleBlitz@@AAEXXZ
    0x413760 | public: virtual void __thiscall mmSingleBlitz::HitWaterHandler(void) | ?HitWaterHandler@mmSingleBlitz@@UAEXXZ
    0x413800 | public: virtual void __thiscall mmSingleBlitz::Update(void) | ?Update@mmSingleBlitz@@UAEXXZ
    0x413820 | public: virtual void __thiscall mmSingleBlitz::UpdateGameInput(int) | ?UpdateGameInput@mmSingleBlitz@@UAEXH@Z
    0x413860 | public: virtual void __thiscall mmSingleBlitz::UpdateGame(void) | ?UpdateGame@mmSingleBlitz@@UAEXXZ
    0x4140C0 | private: int __thiscall mmSingleBlitz::RegisterFinish(void) | ?RegisterFinish@mmSingleBlitz@@AAEHXZ
    0x4143F0 | private: void __thiscall mmSingleBlitz::FinishMessage(int) | ?FinishMessage@mmSingleBlitz@@AAEXH@Z
    0x414420 | private: int __thiscall mmSingleBlitz::ProgressCheck(int,int) | ?ProgressCheck@mmSingleBlitz@@AAEHHH@Z
    0x4144F0 | public: virtual void __thiscall mmSingleBlitz::NextRace(void) | ?NextRace@mmSingleBlitz@@UAEXXZ
    0x414660 | public: void __thiscall mmSingleBlitz::PlayTimerWarning(float) | ?PlayTimerWarning@mmSingleBlitz@@QAEXM@Z
    0x414740 | public: static void __cdecl mmSingleBlitz::DeclareFields(void) | ?DeclareFields@mmSingleBlitz@@SAXXZ
    0x4148B0 | public: virtual class MetaClass * __thiscall mmSingleBlitz::GetClass(void) | ?GetClass@mmSingleBlitz@@UAEPAVMetaClass@@XZ
    0x414A10 | public: virtual __thiscall foobar::~foobar(void) | ??1foobar@@UAE@XZ
    0x414A20 | public: virtual void * __thiscall foobar::`vector deleting destructor'(unsigned int) | ??_Efoobar@@UAEPAXI@Z
    0x414A20 | public: virtual void * __thiscall foobar::`scalar deleting destructor'(unsigned int) | ??_Gfoobar@@UAEPAXI@Z
    0x414A50 | public: __thiscall mmPlayerRecord::mmPlayerRecord(class mmPlayerRecord const &) | ??0mmPlayerRecord@@QAE@ABV0@@Z
    0x414AD0 | public: virtual void * __thiscall Base::`vector deleting destructor'(unsigned int) | ??_EBase@@UAEPAXI@Z
    0x414AD0 | public: virtual void * __thiscall Base::`scalar deleting destructor'(unsigned int) | ??_GBase@@UAEPAXI@Z
    0x414B00 | public: virtual void * __thiscall mmPlayerRecord::`scalar deleting destructor'(unsigned int) | ??_GmmPlayerRecord@@UAEPAXI@Z
    0x414B30 | public: virtual void * __thiscall mmSingleBlitz::`vector deleting destructor'(unsigned int) | ??_EmmSingleBlitz@@UAEPAXI@Z
    0x414B90 | public: virtual void * __thiscall mmInfoBase::`scalar deleting destructor'(unsigned int) | ??_GmmInfoBase@@UAEPAXI@Z
    0x414BC0 | public: virtual __thiscall mmInfoBase::~mmInfoBase(void) | ??1mmInfoBase@@UAE@XZ
    0x414BD0 | public: virtual void __thiscall mmSingleBlitz::UpdateDebugKeyInput(int) | ?UpdateDebugKeyInput@mmSingleBlitz@@UAEXH@Z
    0x414BE0 | public: virtual class mmWaypoints * __thiscall mmSingleBlitz::GetWaypoints(void) | ?GetWaypoints@mmSingleBlitz@@UAEPAVmmWaypoints@@XZ
    0x61A550 | const mmSingleBlitz::`vftable' | ??_7mmSingleBlitz@@6B@
    0x61A5C8 | const foobar::`vftable' | ??_7foobar@@6B@
    0x61A608 | const mmPlayerRecord::`vftable' | ??_7mmPlayerRecord@@6B@
    0x61A620 | const mmInfoBase::`vftable' | ??_7mmInfoBase@@6B@
    0x61A638 | const Base::`vftable' | ??_7Base@@6B@
    0x6A7040 | class MetaClass mmSingleBlitzMetaClass | ?mmSingleBlitzMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"
#include "game.h"

class foobar : public asNode
{
    // const foobar::`vftable' @ 0x61A5C8

public:
    // 0x414A20 | ??_Gfoobar@@UAEPAXI@Z
    // 0x414A10 | ??1foobar@@UAE@XZ
    ~foobar() override;

private:
    // 0x411EE0 | ?Update@foobar@@EAEXXZ
    void Update() override;

    // 0x411F10 | ?UpdatePaused@foobar@@EAEXXZ
    void UpdatePaused() override;
};

check_size(foobar, 0x0);

class mmSingleBlitz : public mmGame
{
    // const mmSingleBlitz::`vftable' @ 0x61A550

public:
    // 0x412EF0 | ??0mmSingleBlitz@@QAE@XZ
    mmSingleBlitz();

    // 0x414B30 | ??_EmmSingleBlitz@@UAEPAXI@Z
    // 0x412F90 | ??1mmSingleBlitz@@UAE@XZ
    ~mmSingleBlitz() override;

    // 0x4148B0 | ?GetClass@mmSingleBlitz@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x414BE0 | ?GetWaypoints@mmSingleBlitz@@UAEPAVmmWaypoints@@XZ
    class mmWaypoints* GetWaypoints() override;

    // 0x413760 | ?HitWaterHandler@mmSingleBlitz@@UAEXXZ
    void HitWaterHandler() override;

    // 0x413060 | ?Init@mmSingleBlitz@@QAEHXZ
    i32 Init();

    // 0x4132D0 | ?InitGameObjects@mmSingleBlitz@@UAEXXZ
    void InitGameObjects() override;

    // 0x413250 | ?InitHUD@mmSingleBlitz@@UAEXXZ
    void InitHUD() override;

    // 0x4131E0 | ?InitMyPlayer@mmSingleBlitz@@UAEXXZ
    void InitMyPlayer() override;

    // 0x413540 | ?InitOtherPlayers@mmSingleBlitz@@UAEXXZ
    void InitOtherPlayers() override;

    // 0x4144F0 | ?NextRace@mmSingleBlitz@@UAEXXZ
    void NextRace() override;

    // 0x414660 | ?PlayTimerWarning@mmSingleBlitz@@QAEXM@Z
    void PlayTimerWarning(f32 arg1);

    // 0x413550 | ?Reset@mmSingleBlitz@@UAEXXZ
    void Reset() override;

    // 0x413800 | ?Update@mmSingleBlitz@@UAEXXZ
    void Update() override;

    // 0x414BD0 | ?UpdateDebugKeyInput@mmSingleBlitz@@UAEXH@Z
    void UpdateDebugKeyInput(i32 arg1) override;

    // 0x413860 | ?UpdateGame@mmSingleBlitz@@UAEXXZ
    void UpdateGame() override;

    // 0x413820 | ?UpdateGameInput@mmSingleBlitz@@UAEXH@Z
    void UpdateGameInput(i32 arg1) override;

    // 0x414740 | ?DeclareFields@mmSingleBlitz@@SAXXZ
    static void DeclareFields();

private:
    // 0x4136F0 | ?DisableRacers@mmSingleBlitz@@AAEXXZ
    void DisableRacers();

    // 0x413660 | ?EnableRacers@mmSingleBlitz@@AAEXXZ
    void EnableRacers();

    // 0x4143F0 | ?FinishMessage@mmSingleBlitz@@AAEXH@Z
    void FinishMessage(i32 arg1);

    // 0x414420 | ?ProgressCheck@mmSingleBlitz@@AAEHHH@Z
    i32 ProgressCheck(i32 arg1, i32 arg2);

    // 0x4140C0 | ?RegisterFinish@mmSingleBlitz@@AAEHXZ
    i32 RegisterFinish();
};

check_size(mmSingleBlitz, 0x1E5B8);

// 0x6A7040 | ?mmSingleBlitzMetaClass@@3VMetaClass@@A
inline extern_var(0x2A7040_Offset, class MetaClass, mmSingleBlitzMetaClass);
