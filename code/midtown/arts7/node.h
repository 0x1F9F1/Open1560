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

#include "cullable.h"

class bkWindow;

#define NODE_FLAG_ACTIVE 0x1
#define NODE_FLAG_2 0x2
#define NODE_FLAG_LOAD_ERROR 0x4
#define NODE_FLAG_UPDATE_PAUSED 0x400
#define NODE_FLAG_OWNED 0x800

class asNode : public asCullable
{
public:
    // ??0asNode@@QAE@XZ
    ARTS_EXPORT asNode() = default;

    // ??_EasNode@@UAEPAXI@Z
    // ??1asNode@@UAE@XZ
    ARTS_EXPORT ~asNode() override;

    ARTS_NON_COPYABLE(asNode);

    // ?Update@asNode@@UAEXXZ
    ARTS_EXPORT virtual void Update();

    // ?Reset@asNode@@UAEXXZ
    ARTS_EXPORT virtual void Reset();

    // ?ResChange@asNode@@UAEXHH@Z
    ARTS_EXPORT virtual void ResChange(i32 width, i32 height);

    // ?UpdatePaused@asNode@@UAEXXZ | inline
    ARTS_EXPORT virtual void UpdatePaused();

    // ?Load@asNode@@UAEXXZ
    ARTS_EXPORT virtual void Load();

    // ?Save@asNode@@UAEXXZ
    ARTS_EXPORT virtual void Save();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asNode@@UAEXPAVBank@@@Z
    ARTS_EXPORT virtual void AddWidgets(Bank* bank);

    // ?OpenWidgets@asNode@@UAEXPADPAVbkWindow@@@Z
    ARTS_EXPORT virtual void OpenWidgets(char* arg1, bkWindow* arg2);

    // ?CloseWidgets@asNode@@UAEXXZ
    ARTS_EXPORT virtual void CloseWidgets();

    // ?AddButton@asNode@@QAEXPAVBank@@AAH@Z | unused
    ARTS_EXPORT void AddButton(Bank* arg1, i32& arg2);
#endif

    // ?AddChild@asNode@@QAEHPAV1@@Z
    ARTS_EXPORT b32 AddChild(asNode* child);

    void AdoptChild(Ptr<asNode> child);

    // ?GetChild@asNode@@QAEPAV1@H@Z
    [[deprecated]] ARTS_EXPORT asNode* GetChild(i32 index);

    // ?GetLastChild@asNode@@QAEPAV1@XZ | unused
    [[deprecated]] ARTS_EXPORT asNode* GetLastChild();

    // ?GetNext@asNode@@QAEPAV1@XZ | unused
    [[deprecated]] ARTS_EXPORT asNode* GetNext()
    {
        return next_node_;
    }

    // ?GetNodeType@asNode@@QAEPADXZ | unused
    ARTS_EXPORT const char* GetNodeType();

    // ?GetParent@asNode@@QAEPAV1@PAVMetaClass@@@Z | unused
    ARTS_EXPORT asNode* GetParent(MetaClass* cls);

    // ?InsertChild@asNode@@QAEHHPAV1@@Z
    ARTS_EXPORT b32 InsertChild(i32 index, asNode* child);

    // ?Load@asNode@@QAEHPAD@Z
    ARTS_EXPORT b32 Load(const char* path);

    // ?NumChildren@asNode@@QAEHXZ
    ARTS_EXPORT i32 NumChildren();

#ifdef ARTS_DEV_BUILD
    // ?PerfReport@asNode@@QAEXPAVStream@@H@Z
    ARTS_EXPORT void PerfReport(Stream* output, i32 indent);
#endif

    // ?RemoveAllChildren@asNode@@QAEXXZ
    ARTS_EXPORT void RemoveAllChildren();

    // ?RemoveChild@asNode@@QAEHPAV1@@Z
    ARTS_EXPORT b32 RemoveChild(asNode* child);

    // ?RemoveChild@asNode@@QAEHH@Z
    [[deprecated]] ARTS_EXPORT b32 RemoveChild(i32 index);

#ifdef ARTS_DEV_BUILD
    // ?ResetTime@asNode@@QAEXXZ
    ARTS_EXPORT void ResetTime();
#endif

    // ?Save@asNode@@QAEHPAD@Z
    ARTS_EXPORT b32 Save(const char* path);

    // ?SetName@asNode@@QAEXPAD@Z
    ARTS_EXPORT void SetName(const char* name);

    // ?SwitchTo@asNode@@QAEXH@Z | unused
    ARTS_EXPORT void SwitchTo(i32 index);

    // ?VerifyTree@asNode@@QAEPADXZ | arts7:sim
    ARTS_EXPORT const char* VerifyTree();

    bool IsNodeActive() const
    {
        return node_flags_ & NODE_FLAG_ACTIVE;
    }

    void ActivateNode()
    {
        node_flags_ |= NODE_FLAG_ACTIVE;
    }

    void DeactivateNode()
    {
        node_flags_ &= ~NODE_FLAG_ACTIVE;
    }

    void SetNodeFlag(i32 flag)
    {
        node_flags_ |= flag;
    }

    void ClearNodeFlag(i32 flag)
    {
        node_flags_ &= ~flag;
    }

    void ToggleNodeFlag(i32 flag)
    {
        node_flags_ ^= flag;
    }

    i32 TestNodeFlag(i32 flag) const
    {
        return node_flags_ & flag;
    }

    asNode* GetNextNode() const
    {
        return next_node_;
    }

    asNode* GetChildNode() const
    {
        return child_node_;
    }

    asNode* GetParentNode() const
    {
        return parent_node_;
    }

    const char* GetNodeName() const
    {
        return node_name_.get();
    }

    VIRTUAL_META_DECLARE;

#ifdef ARTS_DEV_BUILD
    // ?TimingCount@asNode@@2HA
    ARTS_IMPORT static i32 TimingCount;
#endif

private:
#ifdef ARTS_DEV_BUILD
    f32 update_time_ {};
#endif

    asNode* next_node_ {};
    asNode* child_node_ {};
    asNode* parent_node_ {};

    ConstString node_name_;

    // NODE_FLAG_*
    i32 node_flags_ {NODE_FLAG_ACTIVE | NODE_FLAG_2};

#ifdef ARTS_DEV_BUILD
    Bank* current_bank_ {};
#endif
};

check_size(asNode, 0x20);

#define ARTS_DEBUG_SIM 0x1       // asSimulation::Simulate : _CrtCheckMemory, VerifyTree | -simdbg
#define ARTS_DEBUG_UPDATEMEM 0x2 // asNode::Update         : SanityCheck                 | -updatememdbg
#define ARTS_DEBUG_UPDATE 0x4    // asNode::Update         : VerifyTree                  | -updatedbg

// ?DebugMemory@@3HA
ARTS_IMPORT extern i32 DebugMemory;
