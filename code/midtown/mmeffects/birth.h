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
    mmeffects:birth

    0x500A00 | public: __thiscall asBirthRule::asBirthRule(void) | ??0asBirthRule@@QAE@XZ
    0x500AB0 | public: void __thiscall asBirthRule::InitSpark(struct asSparkInfo *,struct asSparkPos *) | ?InitSpark@asBirthRule@@QAEXPAUasSparkInfo@@PAUasSparkPos@@@Z
    0x500D30 | public: virtual void __thiscall asBirthRule::AddWidgets(class Bank *) | ?AddWidgets@asBirthRule@@UAEXPAVBank@@@Z
    0x5012A0 | public: static void __cdecl asBirthRule::DeclareFields(void) | ?DeclareFields@asBirthRule@@SAXXZ
    0x501620 | public: virtual class MetaClass * __thiscall asBirthRule::GetClass(void) | ?GetClass@asBirthRule@@UAEPAVMetaClass@@XZ
    0x501630 | public: virtual void * __thiscall asBirthRule::`vector deleting destructor'(unsigned int) | ??_EasBirthRule@@UAEPAXI@Z
    0x620740 | const asBirthRule::`vftable' | ??_7asBirthRule@@6B@
    0x7195D8 | class MetaClass asBirthRuleMetaClass | ?asBirthRuleMetaClass@@3VMetaClass@@A
*/

class asBirthRule : public asNode
{
    // const asBirthRule::`vftable' @ 0x620740

public:
    // 0x500A00 | ??0asBirthRule@@QAE@XZ
    asBirthRule();

    // 0x501630 | ??_EasBirthRule@@UAEPAXI@Z
    // 0x453BC0 | ??1asBirthRule@@UAE@XZ
    ~asBirthRule() override;

    // 0x500D30 | ?AddWidgets@asBirthRule@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x501620 | ?GetClass@asBirthRule@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x500AB0 | ?InitSpark@asBirthRule@@QAEXPAUasSparkInfo@@PAUasSparkPos@@@Z
    void InitSpark(struct asSparkInfo* arg1, struct asSparkPos* arg2);

    // 0x5012A0 | ?DeclareFields@asBirthRule@@SAXXZ
    static void DeclareFields();
};

check_size(asBirthRule, 0xB0);

// 0x7195D8 | ?asBirthRuleMetaClass@@3VMetaClass@@A
inline extern_var(0x3195D8_Offset, class MetaClass, asBirthRuleMetaClass);
