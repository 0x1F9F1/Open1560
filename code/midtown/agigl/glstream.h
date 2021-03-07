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
    u32 Target {0};
    u32 Buffer {0};
    usize Capacity {0};

    agiGLStreamBuffer(u32 target, usize capacity);
    virtual ~agiGLStreamBuffer();

    void Bind();
    void Unbind();

    virtual usize Upload(const void* data, usize length) = 0;
    virtual void SetFences() = 0;
};

class agiGLBasicStreamBuffer final : public agiGLStreamBuffer
{
public:
    bool Orphan {false};

    agiGLBasicStreamBuffer(u32 target, usize capacity, bool orphan);

    usize Upload(const void* data, u32 length) override;
    void SetFences() override;
};

class agiGLFencedStreamBuffer : public agiGLStreamBuffer
{
public:
    // More fences could reduce the chance of waiting, at the cost of checking them more often.
    static constexpr usize NumFences = 4;

    void* Fences[NumFences] {};
    usize Offset {0};

    using agiGLStreamBuffer::agiGLStreamBuffer;
    ~agiGLFencedStreamBuffer() override;

    void LockSection(usize index);
    void UnlockSection(usize index);

    usize GetSectionSize() const;
    void UnlockRange(u32 offset, usize length, bool exclusive);

    void WaitForAll();
    void CheckFence(usize length);

    void SetFences() override;
};

class agiGLAsyncStreamBuffer final : public agiGLFencedStreamBuffer
{
public:
    agiGLAsyncStreamBuffer(u32 target, usize capacity);

    usize Upload(const void* data, usize length) override;
};

class agiGLPinnedStreamBuffer final : public agiGLFencedStreamBuffer
{
public:
    void* Memory {nullptr};

    agiGLPinnedStreamBuffer(u32 target, usize capacity);
    ~agiGLPinnedStreamBuffer() override;

    usize Upload(const void* data, usize length) override;
};

class agiGLPersistentStreamBuffer final : public agiGLFencedStreamBuffer
{
public:
    void* Mapping {nullptr};
    bool Coherent {false};

    agiGLPersistentStreamBuffer(u32 target, usize capacity, bool coherent);
    ~agiGLPersistentStreamBuffer() override;

    usize Upload(const void* data, usize length) override;
};

class agiGLRiskyAsyncStreamBuffer final : public agiGLFencedStreamBuffer
{
public:
    void* Mapping {nullptr};

    agiGLRiskyAsyncStreamBuffer(u32 target, u32 capacity);

    usize Upload(const void* data, usize length) override;
};
