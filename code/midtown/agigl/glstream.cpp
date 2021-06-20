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

#include "glcontext.h"

#include "core/minwin.h"

#include <glad/glad.h>

static constexpr usize AlignUp(usize value, usize align)
{
    value += align - 1;
    return value - (value % align);
}

agiGLStreamBuffer::agiGLStreamBuffer()
{
    glGenBuffers(1, &Buffer);
}

agiGLStreamBuffer::~agiGLStreamBuffer()
{
    glDeleteBuffers(1, &Buffer);
}

void agiGLStreamBuffer::Discard()
{}

agiGLBasicStreamBuffer::agiGLBasicStreamBuffer()
    : agiGLStreamBuffer()
{}

void agiGLBasicStreamBuffer::Upload(const void** values, const usize* lengths, const usize* aligns, usize count)
{
    usize offset = 0;

    for (usize i = 0; i < count; ++i)
        offset = AlignUp(offset, aligns[i]) + lengths[i];

    glBufferData(GL_ARRAY_BUFFER, offset, NULL, GL_STREAM_DRAW);
    offset = 0;

    for (usize i = 0; i < count; ++i)
    {
        offset = AlignUp(offset, aligns[i]);
        glBufferSubData(GL_ARRAY_BUFFER, offset, lengths[i], values[i]);
        values[i] = reinterpret_cast<const void*>(offset);
        offset += lengths[i];
    }
}

agiGLMappedStreamBuffer::agiGLMappedStreamBuffer(usize capacity)
    : agiGLStreamBuffer()
    , Capacity(AlignUp(capacity, 4096))
{}

void agiGLMappedStreamBuffer::Upload(const void** values, const usize* lengths, const usize* aligns, usize count)
{
    usize length = 0;

    for (usize i = 0; i < count; ++i)
        length += lengths[i] + aligns[i] - 1;

    if (length > Capacity)
        Abortf("Data is too large (%u > %u)", length, Capacity);

    usize offset = Offset;

    if (offset + length > Capacity)
        offset = 0;

    void* dest = Map(offset, length);
    usize here = offset;

    for (usize i = 0; i < count; ++i)
    {
        here = AlignUp(here, aligns[i]);
        std::memcpy(static_cast<u8*>(dest) + (here - offset), values[i], lengths[i]);
        values[i] = reinterpret_cast<const void*>(here);
        here += lengths[i];
    }

    Unmap(offset, length);

    Offset = here;
}

agiGLMapRangeStreamBuffer::agiGLMapRangeStreamBuffer(usize capacity)
    : agiGLMappedStreamBuffer(capacity)
{
    glBindBuffer(GL_ARRAY_BUFFER, Buffer);
    glBufferData(GL_ARRAY_BUFFER, Capacity, NULL, GL_STREAM_DRAW);
}

void* agiGLMapRangeStreamBuffer::Map(usize offset, usize length)
{
    return glMapBufferRange(GL_ARRAY_BUFFER, offset, length,
        GL_MAP_WRITE_BIT |
            (offset ? (GL_MAP_UNSYNCHRONIZED_BIT | GL_MAP_INVALIDATE_RANGE_BIT) : GL_MAP_INVALIDATE_BUFFER_BIT));
}

void agiGLMapRangeStreamBuffer::Unmap([[maybe_unused]] usize offset, [[maybe_unused]] usize length)
{
    glUnmapBuffer(GL_ARRAY_BUFFER);
}

agiGLMappedRingStreamBuffer::agiGLMappedRingStreamBuffer(usize capacity)
    : agiGLMappedStreamBuffer(capacity)
{}

agiGLMappedRingStreamBuffer::~agiGLMappedRingStreamBuffer()
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

void agiGLMappedRingStreamBuffer::LockSection(usize index)
{
    if (Fences[index] != NULL)
        return;

    Fences[index] = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
}

void agiGLMappedRingStreamBuffer::UnlockSection(usize index)
{
    if (Fences[index] == NULL)
        return;

    if (u32 state = glClientWaitSync(static_cast<GLsync>(Fences[index]), 0, 0);
        state != GL_ALREADY_SIGNALED && state != GL_CONDITION_SATISFIED)
    {
        // We should have picked a larger capacity.
        // Errorf("Fenced %u", index);
        glClientWaitSync(static_cast<GLsync>(Fences[index]), GL_SYNC_FLUSH_COMMANDS_BIT, UINT64_MAX);
    }

    glDeleteSync(static_cast<GLsync>(Fences[index]));
    Fences[index] = nullptr;
}

void agiGLMappedRingStreamBuffer::UnlockRange(usize offset, usize length, bool exclusive)
{
    const usize slice = (Capacity + NumFences - 1) / NumFences;

    for (usize i = 0; i < NumFences; ++i)
    {
        usize start = i * slice;

        if ((offset < (start + slice)) && ((offset + length) > start))
            UnlockSection(i);
        else if (exclusive)
            LockSection(i);
    }
}

void agiGLMappedRingStreamBuffer::WaitForAll()
{
    for (usize i = 0; i < NumFences; ++i)
        UnlockSection(i);
}

void* agiGLMappedRingStreamBuffer::Map(usize offset, usize length)
{
    if (offset == 0)
    {
        for (usize i = 0; i < NumFences; ++i)
            LockSection(i);
    }

    UnlockRange(offset, length, false);

    return static_cast<u8*>(Mapping) + offset;
}

void agiGLMappedRingStreamBuffer::Unmap([[maybe_unused]] usize offset, [[maybe_unused]] usize length)
{}

void agiGLMappedRingStreamBuffer::Discard()
{
    UnlockRange(Offset, 0, true);
}

agiGLPersistentStreamBuffer::agiGLPersistentStreamBuffer(usize capacity, bool coherent)
    : agiGLMappedRingStreamBuffer(capacity)
    , Coherent(coherent)
{
    glBindBuffer(GL_ARRAY_BUFFER, Buffer);

    glBufferStorage(GL_ARRAY_BUFFER, Capacity, NULL,
        GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | (coherent ? GL_MAP_COHERENT_BIT : 0));

    Mapping = glMapBufferRange(GL_ARRAY_BUFFER, 0, Capacity,
        GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_UNSYNCHRONIZED_BIT | GL_MAP_INVALIDATE_BUFFER_BIT |
            (Coherent ? GL_MAP_COHERENT_BIT : GL_MAP_FLUSH_EXPLICIT_BIT));
}

agiGLPersistentStreamBuffer::~agiGLPersistentStreamBuffer()
{
    if (Mapping)
    {
        glBindBuffer(GL_ARRAY_BUFFER, Buffer);
        glUnmapBuffer(GL_ARRAY_BUFFER);
    }
}

void agiGLPersistentStreamBuffer::Unmap(usize offset, usize length)
{
    if (!Coherent)
        glFlushMappedBufferRange(GL_ARRAY_BUFFER, offset, length);
}

agiGLAMDPinnedStreamBuffer::agiGLAMDPinnedStreamBuffer(usize capacity)
    : agiGLMappedRingStreamBuffer(capacity)
{
    Mapping = VirtualAlloc(NULL, Capacity, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

    glBindBuffer(GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD, Buffer);
    glBufferData(GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD, Capacity, Mapping, GL_STREAM_DRAW);
    glBindBuffer(GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD, 0);

    glBindBuffer(GL_ARRAY_BUFFER, Buffer);
}

agiGLAMDPinnedStreamBuffer::~agiGLAMDPinnedStreamBuffer()
{
    WaitForAll();

    VirtualFree(Mapping, 0, MEM_RELEASE);
}

agiGLMapUnsafeStreamBuffer::agiGLMapUnsafeStreamBuffer(usize capacity)
    : agiGLMappedRingStreamBuffer(capacity)
{
    glBindBuffer(GL_ARRAY_BUFFER, Buffer);
    glBufferData(GL_ARRAY_BUFFER, Capacity, NULL, GL_STREAM_DRAW);

    // This is very unsafe. The mapping is no longer "valid" after unmapping the buffer.
    // However, if this is a mapping directly to the GPU memory, hopefully it won't move while the buffer exists.
    Mapping = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    glUnmapBuffer(GL_ARRAY_BUFFER);

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
