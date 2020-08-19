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

define_dummy_symbol(arts7_pgraph);

#include "pgraph.h"

#include "agi/cmodel.h"
#include "agi/pipeline.h"
#include "agi/print.h"
#include "agi/rsys.h"
#include "agi/vertex.h"
#include "data7/timer.h"
#include "eventq7/key_codes.h"
#include "sim.h"
#include "vector7/vector3.h"

static f32 PerfGraphOverhead = 0.0f;
static Timer PerfGraphOverheadTimer {};

asPerfGraph::asPerfGraph()
{
    if (PGRAPH)
        Quitf("Already have a PGRAPH");

    PGRAPH = this;

    num_samples_ = std::min<i32>((Pipe()->GetWidth() * 3) / 4, 960);

    AddComponent("Overhead", &PerfGraphOverhead, {0.5f, 0.5f, 0.5f});
}

asPerfGraph::~asPerfGraph()
{
    while (num_components_)
    {
        delete[] component_history_[--num_components_];
    }

    PGRAPH = nullptr;
}

void asPerfGraph::AddComponent(const char* name, f32* value, const Vector3& color)
{
    ArAssert(num_components_ < MaxComponents, "Too many components");

    component_history_[num_components_] = new f32[num_samples_] {};
    component_name_[num_components_] = name;
    component_value_[num_components_] = value;
    component_color_[num_components_] = agiRgba {static_cast<u8>(color.x * 255.0f), static_cast<u8>(color.y * 255.0f),
        static_cast<u8>(color.z * 255.0f), static_cast<u8>(Pipe()->IsHardware() ? 0xBB : 0xFF)};

    ++num_components_;
}

void asPerfGraph::Cull()
{
    RAST->BeginGroup();

    auto tex = agiCurState.SetTexture(nullptr);
    auto draw_mode = agiCurState.SetDrawMode(0xF);
    auto depth = agiCurState.SetZEnable(false);
    auto zwrite = agiCurState.SetZWrite(false);
    auto alpha = agiCurState.SetAlphaEnable(false);
    auto filter = agiCurState.SetTexFilter(agiTexFilter::Point);
    auto fog_mode = agiCurState.SetFogMode(agiFogMode::None);
    auto fog_color = agiCurState.SetFogColor(0x00000000);

    const u16 buf_size = 64;

    agiScreenVtx vert_buf[buf_size * 4];
    u16 index_buf[buf_size * 6];

    u16 count = 0;

    i32 pipe_width = Pipe()->GetWidth();
    i32 pipe_height = Pipe()->GetHeight();

    i32 x_offset = pipe_width - num_samples_;

    f32 max_height = 0.0f;
    f32 total_height = 0.0f;
    i32 total = 0;

    f32 scale = graph_scale_ * auto_scale_;

    for (i32 i = read_index_; i != write_index_;)
    {
        if (++i == num_samples_)
            i = 0;

        f32 height = 0.0f;

        for (i32 j = 0, k = maim_component_; j < num_components_; ++j)
        {
            i32 line_bottom = pipe_height - static_cast<i32>(height * scale);
            height += component_history_[k][i];
            i32 line_top = pipe_height - static_cast<i32>(height * scale);

            if (line_bottom >= 0)
            {
                if (line_top < 0)
                    line_top = 0;

                if (count == buf_size)
                {
                    RAST->Mesh(
                        agiVtxType::Screen, reinterpret_cast<agiVtx*>(vert_buf), count * 4, index_buf, count * 6);

                    count = 0;
                }

                agiScreenVtx* verts = &vert_buf[count * 4];
                u16* indices = &index_buf[count * 6];

                agiScreenVtx blank;

                blank.x = 0.0f;
                blank.y = 0.0f;
                blank.z = 0.0f;
                blank.w = 1.0f;
                blank.specular = component_color_[k].ToARGB();
                blank.diffuse = 0xFFFFFFFF;
                blank.tu = 0.0f;
                blank.tv = 0.0f;

                verts[0] = blank;
                verts[1] = blank;
                verts[2] = blank;
                verts[3] = blank;

                i32 offset = x_offset + (scroll_ ? total : i);

                verts[3].x = verts[0].x = static_cast<f32>(offset);
                verts[1].x = verts[2].x = static_cast<f32>(offset + 1);
                verts[1].y = verts[0].y = static_cast<f32>(line_top);
                verts[3].y = verts[2].y = static_cast<f32>(line_bottom);

                u16 base = count * 4;

                indices[0] = base + 0;
                indices[1] = base + 1;
                indices[2] = base + 2;
                indices[3] = base + 0;
                indices[4] = base + 2;
                indices[5] = base + 3;

                ++count;
            }

            if (++k == num_components_)
                k = 0;
        }

        if (height > max_height)
            max_height = height;

        total_height += height;
        ++total;
    }

    if (count)
    {
        RAST->Mesh(agiVtxType::Screen, (agiVtx*) vert_buf, count * 4, index_buf, count * 6);
    }

    RAST->EndGroup();

    agiCurState.SetTexture(tex);
    agiCurState.SetDrawMode(draw_mode);
    agiCurState.SetZEnable(depth);
    agiCurState.SetZWrite(zwrite);
    agiCurState.SetAlphaEnable(alpha);
    agiCurState.SetTexFilter(filter);
    agiCurState.SetFogMode(fog_mode);
    agiCurState.SetFogColor(fog_color);

    for (i32 height = 0, step = std::clamp<i32>(static_cast<i32>(std::round(max_height * 0.05f)), 1, 5),
             prev = pipe_height;
         height <= max_height;)
    {
        height += step;

        i32 line_top = pipe_height - static_cast<i32>(height * scale) - 1;

        if (line_top < 0)
            break;

        Pipe()->ClearRect(x_offset, line_top, pipe_width - x_offset, 1, 0);

        if (line_top + agiFontHeight <= prev)
        {
            agiPrintf(x_offset, line_top, 0xFFFFFFFF, "%2i", height);
            prev = line_top;
        }
    }

    i32 text_y = 0;

    for (i32 i = 0; i < num_components_; ++i)
    {
        agiPrintf(0, text_y, 0xFFFFFFFF, "   %5.2f %s", component_history_[i][write_index_], component_name_[i]);

        Pipe()->ClearRect(
            0, text_y, agiFontWidth * 2, agiFontHeight, Pipe()->GetHiColorModel()->GetColor(component_color_[i]));

        text_y += agiFontHeight;
    }

    if (total)
    {
        f32 avg_height = total_height / total;

        agiPrintf(0, text_y, 0xFFFFFFFF, "   %5.2f Avg", avg_height);
        text_y += agiFontHeight;

        agiPrintf(0, text_y, 0xFFFFFFFF, "   %5.2f Max", max_height);
        text_y += agiFontHeight;

        auto_scale_ = (auto_scale_ * 0.99f) +
            ((std::min<f32>(240.0f, pipe_width * 0.25f) / (avg_height > 1.0f ? std::round(avg_height) : 1.0f)) * 0.01f);
    }
}

void asPerfGraph::Key(i32 vkey)
{
    switch (vkey)
    {
        case EQ_VK_F2: graph_scale_ *= 0.5f; break;
        case EQ_VK_F3: graph_scale_ *= 2.0f; break;
        case EQ_VK_F4: maim_component_ = (maim_component_ + 1) % num_components_; break;
        case EQ_VK_F5: scroll_ ^= true; break;

        // TODO: Move somewhere else?
        case EQ_VK_F6: asNode::TimingCount = 100; break;
        case EQ_VK_F7:
            ARTSPTR->ResetTime();
            asNode::TimingCount = 0;
            break;
    }
}

void asPerfGraph::Update()
{
    if (++write_index_ == num_samples_)
        write_index_ = 0;

    if (read_index_ == write_index_)
    {
        if (++read_index_ == num_samples_)
            read_index_ = 0;
    }

    PerfGraphOverhead = PerfGraphOverheadTimer.Time() * 1000.0f;
    PerfGraphOverheadTimer.Reset();

    f32 total = 0;

    for (i32 i = 1; i < num_components_; ++i)
    {
        f32 value = *component_value_[i] * 1000.0f;
        component_history_[i][write_index_] = value;
        total += value;
    }

    PerfGraphOverhead = std::max(PerfGraphOverhead - total, 0.0f);

    component_history_[0][write_index_] = PerfGraphOverhead;
}
