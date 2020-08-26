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
    agi:cmodel

    0x55BB70 | protected: virtual __thiscall agiColorModel::~agiColorModel(void) | ??1agiColorModel@@MAE@XZ
    0x55BB80 | public: unsigned int __thiscall agiColorModel::GetColor(int,int,int,int) | ?GetColor@agiColorModel@@QAEIHHHH@Z
    0x55BBB0 | public: unsigned int __thiscall agiColorModel::FindColor(int,int,int,int) | ?FindColor@agiColorModel@@QAEIHHHH@Z
    0x55BBE0 | public: unsigned int __thiscall agiColorModel::GetColor(class Vector3 const &) | ?GetColor@agiColorModel@@QAEIABVVector3@@@Z
    0x55BC40 | public: unsigned int __thiscall agiColorModel::GetColor(class Vector4 const &) | ?GetColor@agiColorModel@@QAEIABVVector4@@@Z
    0x621740 | const agiColorModel::`vftable' | ??_7agiColorModel@@6B@
*/

class agiColorModel
{
    // const agiColorModel::`vftable' @ 0x621740

public:
    // 0x55BB70 | ??1agiColorModel@@MAE@XZ
    virtual ~agiColorModel() = default;

    virtual u32 GetColor(struct agiRgba color) = 0;

    virtual u32 FindColor(struct agiRgba color) = 0;

    virtual u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) = 0;

    virtual void SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) = 0;

    virtual u32 GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3) = 0;

    // 0x55BBB0 | ?FindColor@agiColorModel@@QAEIHHHH@Z | unused
    ARTS_EXPORT u32 FindColor(i32 r, i32 g, i32 b, i32 a);

    // 0x55BBE0 | ?GetColor@agiColorModel@@QAEIABVVector3@@@Z
    ARTS_EXPORT u32 GetColor(class Vector3 const& color);

    // 0x55BC40 | ?GetColor@agiColorModel@@QAEIABVVector4@@@Z | unused
    ARTS_EXPORT u32 GetColor(class Vector4 const& color);

    // 0x55BB80 | ?GetColor@agiColorModel@@QAEIHHHH@Z
    ARTS_EXPORT u32 GetColor(i32 r, i32 g, i32 b, i32 a);

    // 0x55D810 | ?FindMatch@agiColorModel@@SAPAV1@PAVagiSurfaceDesc@@@Z | agi:cmodelx
    ARTS_IMPORT static RcOwner<class agiColorModel> FindMatch(class agiSurfaceDesc* arg1);

    // 0x55D760 | ?FindMatch@agiColorModel@@SAPAV1@HHHH@Z | agi:cmodelx
    ARTS_IMPORT static RcOwner<class agiColorModel> FindMatch(i32 mask_r, i32 mask_g, i32 mask_b, i32 mask_a);

    void AddRef()
    {
        ++RefCount;
    }

    i32 Release()
    {
        u32 const refs = --RefCount;

        if (refs == 0)
        {
            delete this;
        }

        return refs;
    }

    u32 PixelSize {0};

    u32 BitCountR {0};
    u32 BitCountG {0};
    u32 BitCountB {0};
    u32 BitCountA {0};

    u32 ShiftR {0};
    u32 ShiftG {0};
    u32 ShiftB {0};
    u32 ShiftA {0};

    u32 GetMaskR() const
    {
        return ((1 << BitCountR) - 1) << ShiftR;
    }

    u32 GetMaskG() const
    {
        return ((1 << BitCountR) - 1) << ShiftR;
    }

    u32 GetMaskB() const
    {
        return ((1 << BitCountR) - 1) << ShiftR;
    }

    u32 GetMaskA() const
    {
        return ((1 << BitCountR) - 1) << ShiftR;
    }

private:
    u32 RefCount {1};
};

check_size(agiColorModel, 0x2C);
