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

#include "benchstats.h"
#include "data7/timer.h"
#include "eventq7/eventq.h"
#include "eventq7/replay.h"
#include "linear.h"
#include "node.h"

class VirtualFileSystem;

class asSimulation final : public asNode
{
public:
    // ??0asSimulation@@QAE@XZ
    ARTS_EXPORT asSimulation();

    // ??1asSimulation@@UAE@XZ
    ARTS_EXPORT ~asSimulation() override;

    // ?Init@asSimulation@@QAEXPADHPAPAD@Z
    void Init(aconst char* proj_path, i32 argc, char** argv);

#ifdef ARTS_DEV_BUILD
    // ?OpenPhysicsBank@asSimulation@@QAEXXZ | unused
    void OpenPhysicsBank();

    // ?AddWidgets@asSimulation@@UAEXPAVBank@@@Z
    void AddWidgets(Bank* bank) override;
#endif

    // ?Benchmark@asSimulation@@QAEXXZ
    ARTS_IMPORT void Benchmark();

#ifdef ARTS_DEV_BUILD
    // ?Cull@asSimulation@@UAEXXZ
    void Cull() override;

    // ?DeclareVector@asSimulation@@QAEXPBVVector3@@00@Z
    ARTS_EXPORT void DeclareVector(const Vector3* start, const Vector3* end, const Vector3* color);
#endif

    // ?Device@asSimulation@@QAEXXZ
    void Device();

    // ?BeginOverSample@asSimulation@@QAEXH@Z
    void BeginOverSample(i32 samples);

    // ?EndOverSample@asSimulation@@QAEXH@Z
    void EndOverSample(i32 samples);

    // ?FirstUpdate@asSimulation@@QAEXXZ
    void FirstUpdate();

    // ?FixedFrame@asSimulation@@QAEXMH@Z | unused
    void FixedFrame(f32 frame_rate, i32 frame_samples);

    // ?FrameLock@asSimulation@@QAEXHH@Z | unused
    void FrameLock(i32 lock, i32 arg2);

    // ?Pause@asSimulation@@QAEXXZ
    void Pause();

    // ?Quiet@asSimulation@@QAEXXZ
    void Quiet();

    // ?RealTime@asSimulation@@QAEXM@Z
    void RealTime(f32 fps);

    // ?Reset@asSimulation@@UAEXXZ
    void Reset() override;

    // ?ResetClock@asSimulation@@QAEXXZ
    void ResetClock();

    // ?Simulate@asSimulation@@QAEXXZ
    ARTS_EXPORT void Simulate();

    // ?Update@asSimulation@@UAEXXZ
    void Update() override;

    // TODO: Mode code to asNode::UpdatePaused(), matching AGE
    // ?UpdatePaused@asSimulation@@QAEXPAVasNode@@@Z
    void UpdatePaused(asNode* node);

    // ?Widgets@asSimulation@@QAEXXZ
    void Widgets();

    asBenchStats& GetStats()
    {
        return curr_stats_;
    }

    Matrix34* GetCurrentMatrix()
    {
        return current_matrix_;
    }

    void SetCurrentMatrix(Matrix34* view)
    {
        current_matrix_ = view;
    }

    void PushFrame(asLinearCS* lcs)
    {
        ArAssert(++frame_depth_ < ARTS_SSIZE(frame_stack_), "Frame overflow");
        frame_stack_[frame_depth_] = lcs;
        current_matrix_ = &lcs->World;
    }

    void PopFrame()
    {
        ArAssert(--frame_depth_ >= 0, "Frame underflow");
        current_matrix_ = &frame_stack_[frame_depth_]->World;
    }

    bool IsDebug() const
    {
        return !no_debug_;
    }

    void SetDebug(bool debug)
    {
        no_debug_ = !debug;
    }

    bool IsDebugDrawEnabled() const
    {
#ifdef ARTS_DEV_BUILD
        return physics_bank_open_;
#else
        return false;
#endif
    }

    bool IsPaused() const
    {
        return paused_;
    }

    void SetPause(bool pause)
    {
        toggle_pause_ = static_cast<bool>(paused_) ^ pause;
    }

    void TogglePause()
    {
        toggle_pause_ = true;
    }

    i32 GetDrawMode() const
    {
        return draw_mode_;
    }

    f32 GetUpdateDelta() const
    {
        return seconds_;
    }

    void SetUpdateDelta(f32 delta)
    {
        seconds_ = delta;
        inv_seconds_ = 1.0f / delta;
    }

    bool IsFullUpdate() const
    {
        return full_update_;
    }

    void SetIsFullUpdate(bool full_update)
    {
        full_update_ = full_update;
    }

    f32 GetElapsed() const
    {
        return elapsed_;
    }

    void SetElapsed(f32 elapsed)
    {
        elapsed_ = elapsed;
    }

    VIRTUAL_META_DECLARE;

private:
    void SmoothDelta(f32& delta);

    b32 in_escape_ {};
    i32 frame_depth_ {};
    asLinearCS* frame_stack_[32] {};
    asLinearCS root_frame_ {};
    Matrix34* current_matrix_ {};
    Timer frame_timer_ {};
    i32 frame_lock_ {};
    f32 seconds_ {};
    f32 inv_seconds_ {};
    f32 elapsed_ {};
    f32 actual_elapsed_ {};
    i32 updates_ {};
    i32 full_updates_ {};
    b32 first_frame_ {};
    b32 full_update_ {true};
    i32 sample_mode_ {};
    f32 fixed_fps_ {};
    f32 sample_step_ {};
    f32 min_frame_delta_ {0.0001f};
    f32 max_frame_delta_ {0.25f};
    i32 max_samples_ {4};
    i32 frame_samples_ {};
    b32 frame_step_ {};
    i32 frame_count_ {};
    b32 print_bench_stats_ {};
    i32 field_184 {};
    f32 bench_elapsed_ {};
    asBenchStats curr_stats_ {};
    asBenchStats prev_stats_ {};

#ifdef ARTS_DEV_BUILD
    i32 vector_count_ {};
    Ptr<Vector3[]> vector_starts_;
    Ptr<Vector3[]> vector_ends_;
    Ptr<Vector3[]> vector_colors_;
#endif

    eqEventQ keys_queue_;
    eqEventQ widgets_queue_;

#ifdef ARTS_DEV_BUILD
    i32 field_294 {};
    i32 field_298 {};
#endif

    i32 draw_mode_ {};

#ifdef ARTS_DEV_BUILD
    b32 physics_bank_open_ {};
#endif

    b32 no_debug_ {};
    b32 show_ui_ {};
    b32 paused_ {};

    // New Fields
    bool smooth_ {};
    f32 delta_drift_ {};
    f32 target_delta_ {};
    ulong prev_utimer_ {};
    f32 max_fps_delta_ {};
    bool toggle_pause_ {};
    bool should_reset_ {};
    i32 vector_capacity_ {};
    f32 time_warp_ {};
};

// check_size(asSimulation, 0x2B0);

#ifdef ARTS_DEV_BUILD
// ?InitBank@@YAXHPAPAD@Z | unused
void InitBank(i32 argc, char** argv);
#endif

// ?InitPipeline@@YAHPADHPAPAD@Z
i32 InitPipeline(const char* title, i32 argc, char** argv);

// ?ShutdownPipeline@@YAXXZ
void ShutdownPipeline();

// ?ARTSPTR@@3PAVasSimulation@@A
ARTS_EXPORT extern asSimulation* ARTSPTR;

inline asSimulation* Sim()
{
    return ARTSPTR;
}

// ?VFS@@3PAVVirtualFileSystem@@A
extern VirtualFileSystem* VFS;
