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
    arts7:node

    0x5237C0 | public: __thiscall asNode::asNode(void) | ??0asNode@@QAE@XZ
    0x5237F0 | public: virtual __thiscall asNode::~asNode(void) | ??1asNode@@UAE@XZ
    0x523860 | public: void __thiscall asNode::SetName(char *) | ?SetName@asNode@@QAEXPAD@Z
    0x523890 | public: virtual void __thiscall asNode::Update(void) | ?Update@asNode@@UAEXXZ
    0x523960 | public: virtual void __thiscall asNode::Reset(void) | ?Reset@asNode@@UAEXXZ
    0x523980 | public: virtual void __thiscall asNode::ResChange(int,int) | ?ResChange@asNode@@UAEXHH@Z
    0x5239B0 | public: void __thiscall asNode::ResetTime(void) | ?ResetTime@asNode@@QAEXXZ
    0x5239D0 | public: void __thiscall asNode::PerfReport(class Stream *,int) | ?PerfReport@asNode@@QAEXPAVStream@@H@Z
    0x523A70 | public: int __thiscall asNode::AddChild(class asNode *) | ?AddChild@asNode@@QAEHPAV1@@Z
    0x523AF0 | public: int __thiscall asNode::InsertChild(int,class asNode *) | ?InsertChild@asNode@@QAEHHPAV1@@Z
    0x523B80 | public: int __thiscall asNode::RemoveChild(int) | ?RemoveChild@asNode@@QAEHH@Z
    0x523C20 | public: int __thiscall asNode::RemoveChild(class asNode *) | ?RemoveChild@asNode@@QAEHPAV1@@Z
    0x523C60 | public: void __thiscall asNode::RemoveAllChildren(void) | ?RemoveAllChildren@asNode@@QAEXXZ
    0x523C80 | public: class asNode * __thiscall asNode::GetChild(int) | ?GetChild@asNode@@QAEPAV1@H@Z
    0x523CB0 | public: class asNode * __thiscall asNode::GetNext(void) | ?GetNext@asNode@@QAEPAV1@XZ
    0x523CC0 | public: class asNode * __thiscall asNode::GetLastChild(void) | ?GetLastChild@asNode@@QAEPAV1@XZ
    0x523D00 | public: int __thiscall asNode::NumChildren(void) | ?NumChildren@asNode@@QAEHXZ
    0x523D20 | public: void __thiscall asNode::SwitchTo(int) | ?SwitchTo@asNode@@QAEXH@Z
    0x523D80 | public: class asNode * __thiscall asNode::GetParent(class MetaClass *) | ?GetParent@asNode@@QAEPAV1@PAVMetaClass@@@Z
    0x523DC0 | public: char * __thiscall asNode::GetNodeType(void) | ?GetNodeType@asNode@@QAEPADXZ
    0x523DD0 | public: int __thiscall asNode::Load(char *) | ?Load@asNode@@QAEHPAD@Z
    0x523EC0 | public: int __thiscall asNode::Save(char *) | ?Save@asNode@@QAEHPAD@Z
    0x523F70 | public: virtual void __thiscall asNode::Save(void) | ?Save@asNode@@UAEXXZ
    0x524150 | public: virtual void __thiscall asNode::Load(void) | ?Load@asNode@@UAEXXZ
    0x524330 | public: virtual void __thiscall asNode::AddWidgets(class Bank *) | ?AddWidgets@asNode@@UAEXPAVBank@@@Z
    0x5243E0 | public: virtual void __thiscall asNode::OpenWidgets(char *,class bkWindow *) | ?OpenWidgets@asNode@@UAEXPADPAVbkWindow@@@Z
    0x5243F0 | public: virtual void __thiscall asNode::CloseWidgets(void) | ?CloseWidgets@asNode@@UAEXXZ
    0x524400 | public: void __thiscall asNode::AddButton(class Bank *,int &) | ?AddButton@asNode@@QAEXPAVBank@@AAH@Z
    0x524410 | public: static void __cdecl asNode::DeclareFields(void) | ?DeclareFields@asNode@@SAXXZ
    0x524600 | public: virtual class MetaClass * __thiscall asNode::GetClass(void) | ?GetClass@asNode@@UAEPAVMetaClass@@XZ
    0x524610 | struct MetaType * __cdecl PtrTo(struct MetaType *) | ?PtrTo@@YAPAUMetaType@@PAU1@@Z
    0x524640 | public: virtual void * __thiscall asNode::`vector deleting destructor'(unsigned int) | ??_EasNode@@UAEPAXI@Z
    0x5246A0 | [thunk]: __thiscall `vcall'{40,{flat}}' }' | ??_9@$BCI@AE
    0x5246B0 | [thunk]: __thiscall `vcall'{44,{flat}}' }' | ??_9@$BCM@AE
    0x620A78 | const asNode::`vftable' | ??_7asNode@@6B@
    0x620AB8 | const PtrToType::`vftable' | ??_7PtrToType@@6B@
    0x790830 | int DebugMemory | ?DebugMemory@@3HA
    0x790834 | public: static int asNode::TimingCount | ?TimingCount@asNode@@2HA
    0x790838 | class MetaClass asNodeMetaClass | ?asNodeMetaClass@@3VMetaClass@@A
*/

#include "cullable.h"

class asNode : public asCullable
{
    // const asNode::`vftable' @ 0x620A78

public:
    // 0x5237C0 | ??0asNode@@QAE@XZ

    // 0x524640 | ??_EasNode@@UAEPAXI@Z
    // 0x5237F0 | ??1asNode@@UAE@XZ
    ~asNode() override;

    // 0x523890 | ?Update@asNode@@UAEXXZ
    virtual void Update();

    // 0x523960 | ?Reset@asNode@@UAEXXZ
    virtual void Reset();

    // 0x523980 | ?ResChange@asNode@@UAEXHH@Z
    virtual void ResChange(i32 width, i32 height);

    // 0x404BB0 | ?UpdatePaused@asNode@@UAEXXZ | inline
    virtual void UpdatePaused();

    // 0x524150 | ?Load@asNode@@UAEXXZ
    virtual void Load();

    // 0x523F70 | ?Save@asNode@@UAEXXZ
    virtual void Save();

    // 0x524330 | ?AddWidgets@asNode@@UAEXPAVBank@@@Z
    virtual void AddWidgets(class Bank* bank);

    // 0x5243E0 | ?OpenWidgets@asNode@@UAEXPADPAVbkWindow@@@Z
    virtual void OpenWidgets(char* arg1, class bkWindow* arg2);

    // 0x5243F0 | ?CloseWidgets@asNode@@UAEXXZ
    virtual void CloseWidgets();

    // 0x524400 | ?AddButton@asNode@@QAEXPAVBank@@AAH@Z | unused
    void AddButton(class Bank* arg1, i32& arg2);

    // 0x523A70 | ?AddChild@asNode@@QAEHPAV1@@Z
    b32 AddChild(class asNode* child);

    // 0x523C80 | ?GetChild@asNode@@QAEPAV1@H@Z
    class asNode* GetChild(i32 index);

    // 0x523CC0 | ?GetLastChild@asNode@@QAEPAV1@XZ | unused
    class asNode* GetLastChild();

    // 0x523CB0 | ?GetNext@asNode@@QAEPAV1@XZ | unused
    class asNode* GetNext()
    {
        return next_node_;
    }

    // 0x523DC0 | ?GetNodeType@asNode@@QAEPADXZ | unused
    const char* GetNodeType();

    // 0x523D80 | ?GetParent@asNode@@QAEPAV1@PAVMetaClass@@@Z | unused
    class asNode* GetParent(class MetaClass* cls);

    // 0x523AF0 | ?InsertChild@asNode@@QAEHHPAV1@@Z
    b32 InsertChild(i32 index, class asNode* child);

    // 0x523DD0 | ?Load@asNode@@QAEHPAD@Z
    b32 Load(const char* path);

    // 0x523D00 | ?NumChildren@asNode@@QAEHXZ
    i32 NumChildren();

    // 0x5239D0 | ?PerfReport@asNode@@QAEXPAVStream@@H@Z
    void PerfReport(class Stream* output, i32 indent);

    // 0x523C60 | ?RemoveAllChildren@asNode@@QAEXXZ
    void RemoveAllChildren();

    // 0x523C20 | ?RemoveChild@asNode@@QAEHPAV1@@Z
    b32 RemoveChild(class asNode* child);

    // 0x523B80 | ?RemoveChild@asNode@@QAEHH@Z
    b32 RemoveChild(i32 idx);

    // 0x5239B0 | ?ResetTime@asNode@@QAEXXZ
    void ResetTime();

    // 0x523EC0 | ?Save@asNode@@QAEHPAD@Z
    b32 Save(const char* path);

    // 0x523860 | ?SetName@asNode@@QAEXPAD@Z
    void SetName(const char* name);

    // 0x523D20 | ?SwitchTo@asNode@@QAEXH@Z | unused
    void SwitchTo(i32 idx);

    // 0x523440 | ?VerifyTree@asNode@@QAEPADXZ | arts7:sim
    const char* VerifyTree();

    bool IsActive() const
    {
        return node_flags_ & 1;
    }

    VIRTUAL_META_DECLARE;

    // 0x790834 | ?TimingCount@asNode@@2HA
    static inline extern_var(0x790834, i32, TimingCount);

private:
    float update_time_ {0.0f};

    asNode* next_node_ {nullptr};
    asNode* child_node_ {nullptr};
    asNode* parent_node_ {nullptr};

    CString node_name_ {};

    // 0x1 | Active
    // 0x4 | LoadError
    // 0x400 | Update While Paused
    i32 node_flags_ {0x3};

    class Bank* current_bank_ {nullptr};
};

check_size(asNode, 0x20);

// 0x5246A0 | ??_9@$BCI@AE (Skipped: void)

// 0x5246B0 | ??_9@$BCM@AE (Skipped: void)

// 0x790830 | ?DebugMemory@@3HA

// 0x1 | SanityCheck in asSimulation::Simulate | -simdbg
// 0x2 | SanityCheck in asNode::Update         | -updatememdbg
// 0x4 | VerifyTree  in asNode::Update         | -updatedbg
inline extern_var(0x790830, i32, DebugMemory);

// 0x790838 | ?asNodeMetaClass@@3VMetaClass@@A
inline extern_var(0x790838, class MetaClass, asNodeMetaClass);
