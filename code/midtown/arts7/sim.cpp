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

define_dummy_symbol(arts7_sim);

#include "sim.h"

#include "agi/light.h"
#include "agi/mtllib.h"
#include "agi/physlib.h"
#include "agi/texlib.h"
#include "cullmgr.h"
#include "data7/metadefine.h"
#include "data7/utimer.h"
#include "eventq7/keys.h"
#include "midgets.h"
#include "stream/vfsystem.h"

void InitBank(i32 /*arg1*/, char** /*arg2*/)
{}

// 0x523510 | ?IsValidPointer@@YAHPAXIH@Z
ARTS_IMPORT /*static*/ i32 IsValidPointer(void* arg1, u32 arg2, i32 arg3);

// 0x521C20 | ?QuietPrinter@@YAXHPBDPAD@Z
ARTS_IMPORT /*static*/ void QuietPrinter(i32 arg1, char const* arg2, char* arg3);

static extern_var(0x790780, agiLight*, g_Light);
static extern_var(0x790788, agiLightParameters, SunParams);

static mem::cmd_param PARAM_smoothstep {"smoothstep"};

asSimulation::~asSimulation()
{
    ARTSPTR = nullptr;

    if (MIDGETSPTR)
    {
        delete MIDGETSPTR;
        MIDGETSPTR = nullptr;
    }

    if (CULLMGR)
    {
        delete CULLMGR;
        CULLMGR = nullptr;
    }

    agiMtlLib.Kill();
    agiTexLib.Kill();
    agiPhysLib.Kill();

    if (VFS)
    {
        delete VFS;
        VFS = nullptr;
    }
}

void asSimulation::FirstUpdate()
{
    ResetClock();
    frame_timer_.Reset();
    first_frame_ = true;
    seconds_ = 0.0f;
}

void asSimulation::ResetClock()
{
    inv_seconds_ = 1.0f;
    elapsed_ = 0.0f;
    full_updates_ = 0;
    updates_ = 0;
    frame_count_ = 0;
    bench_elapsed_ = 0.0f;

    curr_stats_.Reset();
    prev_stats_.Reset();

    smooth_ = PARAM_smoothstep.get_or(true);
    target_delta_ = 1.0f / 30.0f;
    delta_drift_ = 0.0f;
    prev_utimer_ = 0;
}

void asSimulation::Update()
{
    if (seconds_ == 4321.0f)
        FirstUpdate();
    else if (seconds_ == 1234.0f)
        Quitf("ARTS.Init() not called");

    if (!frame_step_ || paused_)
        vector_count_ = 0;

    Timer timer;

    f32 delta = frame_timer_.Time();
    frame_timer_.Reset();

    prev_utimer_ = adjust_utimer(delta, prev_utimer_);

    actual_elapsed_ += delta;
    bench_elapsed_ += delta;

    if (bench_elapsed_ > 1.0f)
        Benchmark();

    i32 num_samples = 1;
    ++frame_count_;

    delta = std::clamp(delta, min_frame_delta_, max_frame_delta_);

    if (smooth_)
        SmoothDelta(delta);

    if (!eqReplay::Playback)
    {
        if (paused_)
        {
            seconds_ = sample_step_ ? sample_step_ : 0.05f;
        }
        else if (sample_mode_)
        {
            num_samples = frame_samples_;
            seconds_ = sample_step_;
        }
        else
        {
            if (sample_step_ && delta >= sample_step_)
            {
                delta = std::min(delta, max_samples_ * sample_step_);
                num_samples = static_cast<i32>(delta / sample_step_) + 1;
                seconds_ = delta / num_samples;
            }
            else
            {
                seconds_ = delta;
            }
        }
    }

    full_update_ = false;
    ++full_updates_;
    inv_seconds_ = 1.0f / seconds_;

    for (i32 sample = 1; sample <= num_samples; ++sample)
    {
        ++updates_;

        if (sample == num_samples)
            full_update_ = true;

        elapsed_ += seconds_;

        if (!frame_step_ || paused_)
            asNode::Update();
        else
            UpdatePaused(this);

        prev_stats_.Current(&curr_stats_);

        first_frame_ = 0;
    }

    if (physics_bank_open_)
    {
        if (g_Light)
        {
            g_Light->Init(SunParams);
            g_Light->Update();
        }

        CULLMGR->DeclareCullable(this);
    }

    curr_stats_.UpdateTime += timer.Time();

    if (TimingCount && !--TimingCount)
    {
        Ptr<Stream> report {arts_fopen("perf.rpt", "w")};

        PerfReport(report.get(), 0);
    }
}

void asSimulation::Widgets()
{
    Timer timer;

    for (eqEvent event; widgets_queue_.Pop(&event);)
    {
        if ((event.Common.Type == eqEventType::Keyboard) && (event.Key.Modifiers == (EQ_KMOD_DOWN | EQ_KMOD_CTRL)) &&
            (event.Key.VirtualKey == EQ_VK_M) && !no_debug_)
        {
            if (MIDGETSPTR->IsOpen() && MIDGETSPTR->GetVisibleLines() == 5)
            {
                MIDGETSPTR->SetVisibleLines(21);
            }
            else
            {
                MIDGETSPTR->SetVisibleLines(5);
                MIDGETSPTR->Toggle();
            }
        }
    }

    curr_stats_.Widgets += timer.Time();
}

void asSimulation::SmoothDelta(f32& delta)
{
    f32 raw_delta = delta;

    delta += delta_drift_ * 0.2f;
    delta += (target_delta_ - delta) * 0.8f;

    target_delta_ += (raw_delta - target_delta_) * 0.1f;

    delta_drift_ += raw_delta - delta;
    delta_drift_ = std::clamp(delta_drift_, -0.05f, 0.05f);
}

const char* asNode::VerifyTree()
{
    if (!IsValidPointer(this, sizeof(*this), true))
        return "Bad 'this'";

    if (!IsValidPointer(*reinterpret_cast<void**>(this), 8 * sizeof(void*), false))
        return "Bad virtual table";

    if (!IsValidPointer(parent_node_, sizeof(*this), 1) && (this != parent_node_))
        return "Bad parent";

    const char* msg = nullptr;

    i32 i = 1;
    for (asNode* n = child_node_; n; n = n->next_node_, ++i)
    {
        msg = n->VerifyTree();

        if (msg)
        {
            Errorf("Kid %d(%p) of type %s name %s: %s", i, n, GetNodeType(), node_name_.get(), msg);
            break;
        }
    }

    return msg;
}

META_DEFINE_CHILD("asSimulation", asSimulation, asNode)
{}