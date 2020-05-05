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
    arts7:sim

    0x521800 | public: __thiscall asSimulation::asSimulation(void) | ??0asSimulation@@QAE@XZ
    0x521A60 | public: virtual __thiscall asSimulation::~asSimulation(void) | ??1asSimulation@@UAE@XZ
    0x521C10 | public: void __thiscall asSimulation::Quiet(void) | ?Quiet@asSimulation@@QAEXXZ
    0x521C40 | public: void __thiscall asSimulation::Init(char *,int,char * *) | ?Init@asSimulation@@QAEXPADHPAPAD@Z
    0x522290 | public: virtual void __thiscall asSimulation::Reset(void) | ?Reset@asSimulation@@UAEXXZ
    0x5222A0 | public: void __thiscall asSimulation::FirstUpdate(void) | ?FirstUpdate@asSimulation@@QAEXXZ
    0x5222C0 | public: virtual void __thiscall asSimulation::Update(void) | ?Update@asSimulation@@UAEXXZ
    0x5225F0 | double __cdecl invert(double) | ?invert@@YANN@Z
    0x522600 | public: void __thiscall asSimulation::Device(void) | ?Device@asSimulation@@QAEXXZ
    0x5229C0 | public: void __thiscall asSimulation::Widgets(void) | ?Widgets@asSimulation@@QAEXXZ
    0x522A60 | public: void __thiscall asSimulation::Simulate(void) | ?Simulate@asSimulation@@QAEXXZ
    0x522B10 | public: void __thiscall asSimulation::UpdatePaused(class asNode *) | ?UpdatePaused@asSimulation@@QAEXPAVasNode@@@Z
    0x522B80 | public: void __thiscall asSimulation::DeclareVector(class Vector3 const *,class Vector3 const *,class Vector3 const *) | ?DeclareVector@asSimulation@@QAEXPBVVector3@@00@Z
    0x522C20 | public: virtual void __thiscall asSimulation::Cull(void) | ?Cull@asSimulation@@UAEXXZ
    0x522CA0 | public: void __thiscall asSimulation::ResetClock(void) | ?ResetClock@asSimulation@@QAEXXZ
    0x522CF0 | public: void __thiscall asSimulation::BeginOverSample(int) | ?BeginOverSample@asSimulation@@QAEXH@Z
    0x522D30 | public: void __thiscall asSimulation::EndOverSample(void) | ?EndOverSample@asSimulation@@QAEXXZ
    0x522D60 | public: void __thiscall asSimulation::EndOverSample(int) | ?EndOverSample@asSimulation@@QAEXH@Z
    0x522D90 | public: void __thiscall asSimulation::RealTime(float) | ?RealTime@asSimulation@@QAEXM@Z
    0x522DF0 | public: void __thiscall asSimulation::FixedFrame(float,int) | ?FixedFrame@asSimulation@@QAEXMH@Z
    0x522E30 | public: void __thiscall asSimulation::FrameLock(int,int) | ?FrameLock@asSimulation@@QAEXHH@Z
    0x522E40 | public: void __thiscall asSimulation::Benchmark(void) | ?Benchmark@asSimulation@@QAEXXZ
    0x522EC0 | public: void __thiscall asSimulation::Pause(void) | ?Pause@asSimulation@@QAEXXZ
    0x522FA0 | public: void __thiscall asSimulation::OpenPhysicsBank(void) | ?OpenPhysicsBank@asSimulation@@QAEXXZ
    0x522FC0 | void __cdecl InitBank(int,char * *) | ?InitBank@@YAXHPAPAD@Z
    0x522FD0 | public: virtual void __thiscall asSimulation::AddWidgets(class Bank *) | ?AddWidgets@asSimulation@@UAEXPAVBank@@@Z
    0x523210 | int __cdecl InitPipeline(char *,int,char * *) | ?InitPipeline@@YAHPADHPAPAD@Z
    0x5232D0 | void __cdecl ShutdownPipeline(void) | ?ShutdownPipeline@@YAXXZ
    0x523340 | int __cdecl RestartPipeline(int,int,int,int,int) | ?RestartPipeline@@YAHHHHHH@Z
    0x523440 | public: char * __thiscall asNode::VerifyTree(void) | ?VerifyTree@asNode@@QAEPADXZ
    0x523530 | public: static void __cdecl asSimulation::DeclareFields(void) | ?DeclareFields@asSimulation@@SAXXZ
    0x5236A0 | public: virtual class MetaClass * __thiscall asSimulation::GetClass(void) | ?GetClass@asSimulation@@UAEPAVMetaClass@@XZ
    0x5236B0 | public: __thiscall artsReplayChannel::artsReplayChannel(void) | ??0artsReplayChannel@@QAE@XZ
    0x5236D0 | public: virtual void __thiscall artsReplayChannel::DoRecord(class Stream *) | ?DoRecord@artsReplayChannel@@UAEXPAVStream@@@Z
    0x523710 | public: virtual void __thiscall artsReplayChannel::DoPlayback(class Stream *) | ?DoPlayback@artsReplayChannel@@UAEXPAVStream@@@Z
    0x523740 | public: __thiscall artsReplayChannel::~artsReplayChannel(void) | ??1artsReplayChannel@@QAE@XZ
    0x523750 | public: virtual void * __thiscall asSimulation::`vector deleting destructor'(unsigned int) | ??_EasSimulation@@UAEPAXI@Z
    0x5237B0 | [thunk]: __thiscall `vcall'{28,{flat}}' }' | ??_9@$BBM@AE
    0x620A00 | const asSimulation::`vftable' | ??_7asSimulation@@6B@
    0x620A60 | const artsReplayChannel::`vftable' | ??_7artsReplayChannel@@6B@
    0x790750 | class MetaClass asSimulationMetaClass | ?asSimulationMetaClass@@3VMetaClass@@A
    0x79077C | class asSimulation * ARTSPTR | ?ARTSPTR@@3PAVasSimulation@@A
    0x790800 | int Argc | ?Argc@@3HA
    0x790804 | char * * Argv | ?Argv@@3PAPADA
    0x790808 | class VirtualFileSystem * VFS | ?VFS@@3PAVVirtualFileSystem@@A
    0x790820 | int StereoBuffer | ?StereoBuffer@@3HA
*/

#include "eventq7/replay.h"
#include "node.h"

class asSimulation : public asNode
{
    // const asSimulation::`vftable' @ 0x620A00

public:
    // 0x521800 | ??0asSimulation@@QAE@XZ
    asSimulation();

    // 0x523750 | ??_EasSimulation@@UAEPAXI@Z
    // 0x521A60 | ??1asSimulation@@UAE@XZ
    ~asSimulation() override;

    // 0x522FD0 | ?AddWidgets@asSimulation@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x522CF0 | ?BeginOverSample@asSimulation@@QAEXH@Z
    void BeginOverSample(i32 arg1);

    // 0x522E40 | ?Benchmark@asSimulation@@QAEXXZ
    void Benchmark();

    // 0x522C20 | ?Cull@asSimulation@@UAEXXZ
    void Cull() override;

    // 0x522B80 | ?DeclareVector@asSimulation@@QAEXPBVVector3@@00@Z
    void DeclareVector(class Vector3 const* arg1, class Vector3 const* arg2, class Vector3 const* arg3);

    // 0x522600 | ?Device@asSimulation@@QAEXXZ
    void Device();

    // 0x522D30 | ?EndOverSample@asSimulation@@QAEXXZ
    void EndOverSample();

    // 0x522D60 | ?EndOverSample@asSimulation@@QAEXH@Z
    void EndOverSample(i32 arg1);

    // 0x5222A0 | ?FirstUpdate@asSimulation@@QAEXXZ
    void FirstUpdate();

    // 0x522DF0 | ?FixedFrame@asSimulation@@QAEXMH@Z
    void FixedFrame(f32 arg1, i32 arg2);

    // 0x522E30 | ?FrameLock@asSimulation@@QAEXHH@Z
    void FrameLock(i32 arg1, i32 arg2);

    // 0x5236A0 | ?GetClass@asSimulation@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x521C40 | ?Init@asSimulation@@QAEXPADHPAPAD@Z
    void Init(char* arg1, i32 arg2, char** arg3);

    // 0x522FA0 | ?OpenPhysicsBank@asSimulation@@QAEXXZ
    void OpenPhysicsBank();

    // 0x522EC0 | ?Pause@asSimulation@@QAEXXZ
    void Pause();

    // 0x521C10 | ?Quiet@asSimulation@@QAEXXZ
    void Quiet();

    // 0x522D90 | ?RealTime@asSimulation@@QAEXM@Z
    void RealTime(f32 arg1);

    // 0x522290 | ?Reset@asSimulation@@UAEXXZ
    void Reset() override;

    // 0x522CA0 | ?ResetClock@asSimulation@@QAEXXZ
    void ResetClock();

    // 0x522A60 | ?Simulate@asSimulation@@QAEXXZ
    void Simulate();

    // 0x5222C0 | ?Update@asSimulation@@UAEXXZ
    void Update() override;

    // 0x522B10 | ?UpdatePaused@asSimulation@@QAEXPAVasNode@@@Z
    void UpdatePaused(class asNode* arg1);

    // 0x5229C0 | ?Widgets@asSimulation@@QAEXXZ
    void Widgets();

    // 0x523530 | ?DeclareFields@asSimulation@@SAXXZ
    static void DeclareFields();
};

check_size(asSimulation, 0x2B0);

// 0x522FC0 | ?InitBank@@YAXHPAPAD@Z
void InitBank(i32 arg1, char** arg2);

// 0x523210 | ?InitPipeline@@YAHPADHPAPAD@Z
i32 InitPipeline(char* arg1, i32 arg2, char** arg3);

// 0x523340 | ?RestartPipeline@@YAHHHHHH@Z
i32 RestartPipeline(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

// 0x5232D0 | ?ShutdownPipeline@@YAXXZ
void ShutdownPipeline();

// 0x5225F0 | ?invert@@YANN@Z
f64 invert(f64 arg1);

// 0x5237B0 | ??_9@$BBM@AE (Skipped: void)

// 0x79077C | ?ARTSPTR@@3PAVasSimulation@@A
inline extern_var(0x39077C_Offset, class asSimulation*, ARTSPTR);

// 0x790800 | ?Argc@@3HA
inline extern_var(0x390800_Offset, i32, Argc);

// 0x790804 | ?Argv@@3PAPADA
inline extern_var(0x390804_Offset, char**, Argv);

// 0x790820 | ?StereoBuffer@@3HA
inline extern_var(0x390820_Offset, i32, StereoBuffer);

// 0x790808 | ?VFS@@3PAVVirtualFileSystem@@A
inline extern_var(0x390808_Offset, class VirtualFileSystem*, VFS);

// 0x790750 | ?asSimulationMetaClass@@3VMetaClass@@A
inline extern_var(0x390750_Offset, class MetaClass, asSimulationMetaClass);

class artsReplayChannel : public eqReplayChannel
{
    // const artsReplayChannel::`vftable' @ 0x620A60

public:
    // 0x5236B0 | ??0artsReplayChannel@@QAE@XZ
    artsReplayChannel();

    // 0x523740 | ??1artsReplayChannel@@QAE@XZ
    ~artsReplayChannel();

    // 0x523710 | ?DoPlayback@artsReplayChannel@@UAEXPAVStream@@@Z
    void DoPlayback(class Stream* arg1) override;

    // 0x5236D0 | ?DoRecord@artsReplayChannel@@UAEXPAVStream@@@Z
    void DoRecord(class Stream* arg1) override;
};

check_size(artsReplayChannel, 0x0);
