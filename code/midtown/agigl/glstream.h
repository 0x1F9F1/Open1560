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

class agiGLStreamBuffer
{
public:
    u32 Buffer {0};

    agiGLStreamBuffer();
    virtual ~agiGLStreamBuffer();

    ARTS_NON_COPYABLE(agiGLStreamBuffer);

    virtual void Upload(const void** values, const usize* lengths, const usize* aligns, usize count) = 0;
    virtual void Discard();
};

class agiGLBasicStreamBuffer final : public agiGLStreamBuffer
{
public:
    agiGLBasicStreamBuffer();

    void Upload(const void** values, const usize* lengths, const usize* aligns, usize count) override;
};

class agiGLMappedStreamBuffer : public agiGLStreamBuffer
{
public:
    usize Capacity {0};
    usize Offset {0};

    agiGLMappedStreamBuffer(usize capacity);

    void Upload(const void** values, const usize* lengths, const usize* aligns, usize count) override;

    virtual void* Map(usize offset, usize length) = 0;
    virtual void Unmap(usize offset, usize length) = 0;
};

class agiGLMapRangeStreamBuffer final : public agiGLMappedStreamBuffer
{
public:
    agiGLMapRangeStreamBuffer(usize capacity);

    void* Map(usize offset, usize length) override;
    void Unmap(usize offset, usize length) override;
};

class agiGLMappedRingStreamBuffer : public agiGLMappedStreamBuffer
{
public:
    // More fences could reduce the chance of waiting, at the cost of checking them more often.
    static constexpr usize NumFences = 4;

    void* Mapping {nullptr};
    void* Fences[NumFences] {};

    agiGLMappedRingStreamBuffer(usize capacity);
    ~agiGLMappedRingStreamBuffer() override;

    void LockSection(usize index);
    void UnlockSection(usize index);

    void UnlockRange(usize offset, usize length, bool exclusive);
    void WaitForAll();

    void* Map(usize offset, usize length) override;
    void Unmap(usize offset, usize length) override;

    void Discard() override;

    usize GetSectionSize() const
    {
        return (Capacity + NumFences - 1) / NumFences;
    }
};

class agiGLPersistentStreamBuffer final : public agiGLMappedRingStreamBuffer
{
public:
    bool Coherent {false};

    agiGLPersistentStreamBuffer(usize capacity, bool coherent);
    ~agiGLPersistentStreamBuffer() override;

    void Unmap(usize offset, usize length) override;
};

class agiGLAMDPinnedStreamBuffer final : public agiGLMappedRingStreamBuffer
{
public:
    agiGLAMDPinnedStreamBuffer(usize capacity);
    ~agiGLAMDPinnedStreamBuffer() override;
};

class agiGLMapUnsafeStreamBuffer final : public agiGLMappedRingStreamBuffer
{
public:
    agiGLMapUnsafeStreamBuffer(usize capacity);
};
