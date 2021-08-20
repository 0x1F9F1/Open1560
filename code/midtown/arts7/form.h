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
    arts7:form

    0x528390 | public: __thiscall asForm::asForm(void) | ??0asForm@@QAE@XZ
    0x5283C0 | public: virtual __thiscall asForm::~asForm(void) | ??1asForm@@UAE@XZ
    0x528420 | public: void __thiscall asForm::SetDLP(class DLP *) | ?SetDLP@asForm@@QAEXPAVDLP@@@Z
    0x528450 | public: void __thiscall asForm::SetShape(char *,char *,class Vector3 *,int,int) | ?SetShape@asForm@@QAEXPAD0PAVVector3@@HH@Z
    0x5284D0 | public: void __thiscall asForm::SetCull(int,float) | ?SetCull@asForm@@QAEXHM@Z
    0x5284F0 | public: virtual void __thiscall asForm::Update(void) | ?Update@asForm@@UAEXXZ
    0x528520 | public: virtual void __thiscall asForm::Cull(void) | ?Cull@asForm@@UAEXXZ
    0x528600 | public: int __thiscall asForm::Visible(class asCamera *,class Matrix34 const &) const | ?Visible@asForm@@QBEHPAVasCamera@@ABVMatrix34@@@Z
    0x5287D0 | public: class Vector3 __thiscall asForm::GetBoundMin(void) | ?GetBoundMin@asForm@@QAE?AVVector3@@XZ
    0x528820 | public: class Vector3 __thiscall asForm::GetBoundMax(void) | ?GetBoundMax@asForm@@QAE?AVVector3@@XZ
    0x528870 | public: class Vector4 __thiscall asForm::GetBoundSphere(void) | ?GetBoundSphere@asForm@@QAE?AVVector4@@XZ
    0x5288D0 | public: void __thiscall asForm::FileIO(class MiniParser *) | ?FileIO@asForm@@QAEXPAVMiniParser@@@Z
    0x5288E0 | public: virtual void __thiscall asForm::AddWidgets(class Bank *) | ?AddWidgets@asForm@@UAEXPAVBank@@@Z
    0x5289D0 | public: static void __cdecl asForm::DeclareFields(void) | ?DeclareFields@asForm@@SAXXZ
    0x528B40 | public: virtual class MetaClass * __thiscall asForm::GetClass(void) | ?GetClass@asForm@@UAEPAVMetaClass@@XZ
    0x528B50 | public: virtual void * __thiscall asForm::`vector deleting destructor'(unsigned int) | ??_EasForm@@UAEPAXI@Z
    0x620D10 | const asForm::`vftable' | ??_7asForm@@6B@
    0x790930 | class MetaClass asFormMetaClass | ?asFormMetaClass@@3VMetaClass@@A
*/

#include "node.h"

class asCamera;
class DLP;
class MiniParser;

class asForm final : public asNode
{
public:
    // ??0asForm@@QAE@XZ
    ARTS_IMPORT asForm();

    // ??_EasForm@@UAEPAXI@Z
    // ??1asForm@@UAE@XZ
    ARTS_IMPORT ~asForm() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asForm@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@asForm@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?FileIO@asForm@@QAEXPAVMiniParser@@@Z | unused
    ARTS_EXPORT void FileIO(MiniParser* arg1);

    // ?GetBoundMax@asForm@@QAE?AVVector3@@XZ | unused
    ARTS_IMPORT Vector3 GetBoundMax();

    // ?GetBoundMin@asForm@@QAE?AVVector3@@XZ | unused
    ARTS_IMPORT Vector3 GetBoundMin();

    // ?GetBoundSphere@asForm@@QAE?AVVector4@@XZ | unused
    ARTS_IMPORT Vector4 GetBoundSphere();

    // ?GetClass@asForm@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?SetCull@asForm@@QAEXHM@Z
    ARTS_IMPORT void SetCull(i32 arg1, f32 arg2);

    // ?SetDLP@asForm@@QAEXPAVDLP@@@Z | unused
    ARTS_IMPORT void SetDLP(DLP* arg1);

    // ?SetShape@asForm@@QAEXPAD0PAVVector3@@HH@Z
    ARTS_IMPORT void SetShape(char* arg1, char* arg2, Vector3* arg3, i32 arg4, i32 arg5);

    // ?Update@asForm@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?Visible@asForm@@QBEHPAVasCamera@@ABVMatrix34@@@Z
    ARTS_IMPORT i32 Visible(asCamera* arg1, Matrix34 const& arg2) const;

    // ?DeclareFields@asForm@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0xA8];
};

check_size(asForm, 0xC8);
