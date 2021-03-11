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

#include "glstream.h"

#include "core/minwin.h"
#include <glad/glad.h>

agiGLStreamBuffer::agiGLStreamBuffer(u32 target, usize capacity)
    : Target(target)
    , Capacity(capacity)
{
    glGenBuffers(1, &Buffer);
}

agiGLStreamBuffer::~agiGLStreamBuffer()
{
    glDeleteBuffers(1, &Buffer);
}

void agiGLStreamBuffer::Bind()
{
    glBindBuffer(Target, Buffer);
}

void agiGLStreamBuffer::Unbind()
{
    glBindBuffer(Target, 0);
}

agiGLBasicStreamBuffer::agiGLBasicStreamBuffer(u32 target, usize capacity, bool orphan)
    : agiGLStreamBuffer(target, capacity)
    , Orphan(orphan)
{
    glBindBuffer(Target, Buffer);
    glBufferData(Target, Capacity, NULL, GL_STREAM_DRAW);
}

usize agiGLBasicStreamBuffer::Upload(const void* data, usize length)
{
    glBufferData(Target, length, Orphan ? NULL : data, GL_STREAM_DRAW);

    if (Orphan)
        glBufferSubData(Target, 0, length, data);

    return 0;
}

void agiGLBasicStreamBuffer::SetFences()
{}

agiGLFencedStreamBuffer::~agiGLFencedStreamBuffer()
{
    for (usize i = 0; i < NumFences; ++i)
    {
        if (Fences[i])
        {
            glClientWaitSync(static_cast<GLsync>(Fences[i]), GL_SYNC_FLUSH_COMMANDS_BIT, UINT64_MAX);
            glDeleteSync(static_cast<GLsync>(Fences[i]));
        }
    }
}

void agiGLFencedStreamBuffer::LockSection(usize index)
{
    if (Fences[index] != NULL)
        return;

    Fences[index] = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
}

void agiGLFencedStreamBuffer::UnlockSection(usize index)
{
    if (Fences[index] == NULL)
        return;

    if (u32 state = glClientWaitSync(static_cast<GLsync>(Fences[index]), 0, 0);
        state != GL_ALREADY_SIGNALED && state != GL_CONDITION_SATISFIED)
    {
        // We should have picked a larger capacity.
        Errorf("Fenced %u", index);
        glClientWaitSync(static_cast<GLsync>(Fences[index]), GL_SYNC_FLUSH_COMMANDS_BIT, UINT64_MAX);
    }

    glDeleteSync(static_cast<GLsync>(Fences[index]));
    Fences[index] = nullptr;
}

usize agiGLFencedStreamBuffer::GetSectionSize() const
{
    return (Capacity + NumFences - 1) / NumFences;
}

void agiGLFencedStreamBuffer::UnlockRange(u32 offset, usize length, bool exclusive)
{
    const usize slice = GetSectionSize();

    for (usize i = 0; i < NumFences; ++i)
    {
        usize start = i * slice;

        if ((offset < (start + slice)) && ((offset + length) > start))
            UnlockSection(i);
        else if (exclusive)
            LockSection(i);
    }
}

void agiGLFencedStreamBuffer::WaitForAll()
{
    for (usize i = 0; i < NumFences; ++i)
        UnlockSection(i);
}

void agiGLFencedStreamBuffer::CheckFence(usize length)
{
    if (length > Capacity)
        Abortf("Data is too large (%u > %u)", length, Capacity);

    if (Offset + length > Capacity)
    {
        Offset = 0;

        if (Fences[(Offset + length) / GetSectionSize()] == NULL)
            Abortf("Data wrapped onto unlocked data (%u, %u)", Offset + length, Capacity);
    }

    UnlockRange(Offset, length, false);
}

void agiGLFencedStreamBuffer::SetFences()
{
    UnlockRange(Offset, 0, true);
}

agiGLAsyncStreamBuffer::agiGLAsyncStreamBuffer(u32 target, usize capacity)
    : agiGLFencedStreamBuffer(target, capacity)
{
    glBindBuffer(Target, Buffer);
    glBufferData(Target, Capacity, NULL, GL_DYNAMIC_DRAW);
}

usize agiGLAsyncStreamBuffer::Upload(const void* data, usize length)
{
    CheckFence(length);

    usize offset = Offset;
    void* dst = glMapBufferRange(
        Target, offset, length, GL_MAP_WRITE_BIT | GL_MAP_UNSYNCHRONIZED_BIT | GL_MAP_INVALIDATE_RANGE_BIT);
    std::memcpy(dst, data, length);
    glUnmapBuffer(Target);

    Offset = (offset + length + 0xF) & ~usize(0xF);

    return offset;
}

agiGLPinnedStreamBuffer::agiGLPinnedStreamBuffer(u32 target, usize capacity)
    : agiGLFencedStreamBuffer(target, capacity)
{
    Memory = VirtualAlloc(NULL, capacity, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

    glBindBuffer(GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD, Buffer);
    glBufferData(GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD, capacity, Memory, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD, 0);

    glBindBuffer(Target, Buffer);
}

agiGLPinnedStreamBuffer::~agiGLPinnedStreamBuffer()
{
    WaitForAll();

    VirtualFree(Memory, 0, MEM_RELEASE);
}

usize agiGLPinnedStreamBuffer::Upload(const void* data, usize length)
{
    CheckFence(length);

    usize offset = Offset;
    void* dst = static_cast<u8*>(Memory) + offset;
    std::memcpy(dst, data, length);

    Offset = (offset + length + 0xF) & ~usize(0xF);

    return offset;
}

agiGLPersistentStreamBuffer::agiGLPersistentStreamBuffer(u32 target, usize capacity, bool coherent)
    : agiGLFencedStreamBuffer(target, capacity)
    , Coherent(coherent)
{
    glBindBuffer(Target, Buffer);

    glBufferStorage(
        Target, Capacity, NULL, GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | (coherent ? GL_MAP_COHERENT_BIT : 0));

    Mapping = glMapBufferRange(Target, 0, Capacity,
        GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_UNSYNCHRONIZED_BIT | GL_MAP_INVALIDATE_BUFFER_BIT |
            (coherent ? GL_MAP_COHERENT_BIT : GL_MAP_FLUSH_EXPLICIT_BIT));
}

agiGLPersistentStreamBuffer::~agiGLPersistentStreamBuffer()
{
    if (Mapping)
    {
        glBindBuffer(Target, Buffer);
        glUnmapBuffer(Target);
    }
}

usize agiGLPersistentStreamBuffer::Upload(const void* data, usize length)
{
    CheckFence(length);

    usize offset = Offset;
    void* dst = static_cast<u8*>(Mapping) + offset;
    std::memcpy(dst, data, length);

    if (!Coherent)
        glFlushMappedBufferRange(Target, offset, length);

    Offset = (offset + length + 0xF) & ~usize(0xF);

    return offset;
}

agiGLRiskyAsyncStreamBuffer::agiGLRiskyAsyncStreamBuffer(u32 target, usize capacity)
    : agiGLFencedStreamBuffer(target, capacity)
{
    glBindBuffer(Target, Buffer);
    glBufferData(Target, Capacity, NULL, GL_DYNAMIC_DRAW);

    // This is very unsafe. The mapping is no longer "valid" after unmapping the buffer.
    // However, if this is a mapping directly to the GPU memory, it is unlikely to move while the buffer exists.
    Mapping = glMapBuffer(Target, GL_WRITE_ONLY);
    glUnmapBuffer(Target);

    if (MEMORY_BASIC_INFORMATION info; VirtualQuery(Mapping, &info, sizeof(info)))
    {
        // info.State == MEM_COMMIT; // 0x1000
        // info.Protect == PAGE_READWRITE | PAGE_WRITECOMBINE; // 0x404
        // info.Type == MEM_PRIVATE; // 0x20000
        Displayf("OpenGL Buffer Mapping State: %X, %X, %X", info.State, info.Protect, info.Type);

        if (info.State != MEM_COMMIT || info.Protect != (PAGE_READWRITE | PAGE_WRITECOMBINE) ||
            info.Type != MEM_PRIVATE)
        {
            Warningf("Unexpected mapping state, this may crash");
        }
    }
}

usize agiGLRiskyAsyncStreamBuffer::Upload(const void* data, usize length)
{
    CheckFence(length);

    usize offset = Offset;
    void* dst = static_cast<u8*>(Mapping) + offset;
    std::memcpy(dst, data, length);

    Offset = (offset + length + 0xF) & ~usize(0xF);

    return offset;
}
