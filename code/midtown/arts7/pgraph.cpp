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
#include "vector7/vector3.h"

static extern_var(0x79098C, f32, PerfGraphOverhead);
static extern_var(0x790988, Timer, PerfGraphOverheadTimer);

asPerfGraph::asPerfGraph()
{
    if (PGRAPH)
        Quitf("Already have a PGRAPH");

    PGRAPH = this;

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

    component_history_[num_components_] = new f32[Pipe()->GetWidth()] {};
    component_name_[num_components_] = name;
    component_value_[num_components_] = value;
    component_color_[num_components_] = agiRgba {
        static_cast<u8>(color.x * 255.0f), static_cast<u8>(color.y * 255.0f), static_cast<u8>(color.z * 255.0f), 0xFF};

    ++num_components_;
}

void asPerfGraph::Cull()
{
    RAST->BeginGroup();

    auto tex = agiCurState.SetTexture(nullptr);
    auto draw_mode = agiCurState.SetDrawMode(15);
    auto depth = agiCurState.SetDepthTest(0);
    auto zwrite = agiCurState.SetZWrite(0);
    auto alpha = agiCurState.SetAlphaEnable(1);
    auto filter = agiCurState.SetTexFilter(0);

    const u16 buf_size = 128;

    agiScreenVtx vert_buf[buf_size * 4];
    u16 index_buf[buf_size * 6];

    u16 count = 0;

    for (i32 i = read_index_; i != write_index_;)
    {
        if (++i == Pipe()->GetWidth())
            i = 0;

        f32 height = 0.0f;

        for (i32 j = 0, k = maim_component_; j < num_components_; ++j)
        {
            i32 line_bottom = Pipe()->GetHeight() - static_cast<i32>(height * graph_scale_) - 1;
            height += component_history_[k][i];
            i32 line_top = Pipe()->GetHeight() - static_cast<i32>(height * graph_scale_) - 1;

            if (line_bottom >= 0)
            {
                if (line_top < 0)
                    line_top = 0;

                // Pipe()->ClearRect(i, line_top, 1, line_bottom - line_top, component_color_[k]);

                if (count == buf_size)
                {
                    RAST->Mesh(agiVtxType::VtxType3, (agiVtx*) vert_buf, count * 4, index_buf, count * 6);

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

                // FIXME: This half pixel offset shouldn't be required.
                verts[3].x = verts[0].x = static_cast<f32>(i) - 0.5f;
                verts[1].x = verts[2].x = static_cast<f32>(i + 1) - 0.5f;
                verts[1].y = verts[0].y = static_cast<f32>(line_top) - 0.5f;
                verts[3].y = verts[2].y = static_cast<f32>(line_bottom) - 0.5f;

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
    }

    if (count)
    {
        RAST->Mesh(agiVtxType::VtxType3, (agiVtx*) vert_buf, count * 4, index_buf, count * 6);
    }

    RAST->EndGroup();

    agiCurState.SetTexture(tex);
    agiCurState.SetDrawMode(draw_mode);
    agiCurState.SetDepthTest(depth);
    agiCurState.SetZWrite(zwrite);
    agiCurState.SetAlphaEnable(alpha);
    agiCurState.SetTexFilter(filter);

    for (i32 i = 0; i < num_components_; ++i)
    {
        agiPrintf(
            0, agiFontHeight * i, 0xFFFFFFFF, "   %5.2f %s", component_history_[i][write_index_], component_name_[i]);

        Pipe()->ClearRect(0, agiFontHeight * i, agiFontWidth * 2, agiFontHeight,
            Pipe()->GetHiColorModel()->GetColor(component_color_[i]));
    }

    for (f32 height = 0.0f; height <= 100.0f; height += 10.0f)
    {
        i32 line_top = Pipe()->GetHeight() - static_cast<i32>(height * graph_scale_) - 1;

        Pipe()->ClearRect(0, line_top, Pipe()->GetWidth(), 1, 0);
    }
}

void asPerfGraph::Key(i32 vkey)
{
    switch (vkey)
    {
        case EQ_VK_F2: graph_scale_ *= 0.5f; break;
        case EQ_VK_F3: graph_scale_ *= 2.0f; break;
        case EQ_VK_F4: maim_component_ = (maim_component_ + 1) % num_components_; break;
    }
}

void asPerfGraph::Update()
{
    if (++write_index_ == Pipe()->GetWidth())
        write_index_ = 0;

    if (read_index_ == write_index_)
    {
        if (++read_index_ == Pipe()->GetWidth())
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
