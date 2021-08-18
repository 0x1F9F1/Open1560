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

define_dummy_symbol(mmgame_game);

#include "game.h"

#include "agi/pipeline.h"
#include "arts7/cullmgr.h"
#include "arts7/sim.h"
#include "eventq7/eventq.h"
#include "eventq7/keys.h"
#include "localize//localize.h"
#include "mmai/aiMap.h"
#include "mmai/aiVehicleOpponent.h"
#include "mmai/aiVehiclePolice.h"
#include "mmanim/AnimMgr.h"
#include "mmaudio/manager.h"
#include "mmaudio/mmvoicecommentary.h"
#include "mmcity/cullcity.h"
#include "mmcity/position.h"
#include "mmcityinfo/state.h"
#include "mminput/input.h"
#include "mmnetwork/network.h"

#include "gameman.h"
#include "player.h"
#include "popup.h"
#include "waypoints.h"

u32 IconColor[8] {
    0xFF0000EF, // Blue
    0xFF00EF00, // Green
    0xFFEF0000, // Red
    0xFFFFFF00, // Yellow
    0xFFFF5A00, // Orange
    0xFFB400FF, // Purple
    0xFF00FFFF, // Cyan
    0xFFFF0390, // Pink
};

void mmGame::UpdateDebugInput()
{
    while (EventQueue->Pop(&CurrentEvent))
    {
        if ((CurrentEvent.Common.Type != eqEventType::Keyboard) || (CurrentEvent.Key.Key == 0))
            continue;

        eqKeyboardEvent& event = CurrentEvent.Key;

        if (event.Modifiers & EQ_KMOD_DOWN)
        {
            if (event.Key == VK_F7 &&
                (event.Modifiers & (EQ_KMOD_DOWN | EQ_KMOD_SHIFT | EQ_KMOD_CTRL | EQ_KMOD_ALT)) ==
                    (EQ_KMOD_DOWN | EQ_KMOD_SHIFT | EQ_KMOD_CTRL | EQ_KMOD_ALT) &&
                !NETMGR.InSession())
            {
                Popup->ProcessChat();
            }

            continue;
        }

#ifdef ARTS_DEV_BUILD
        if ((event.Modifiers & EQ_KMOD_SHIFT) && ARTSPTR->IsDebug())
        {
            switch (event.Key)
            {
                case EQ_VK_1: {
                    Player->Hud.SetMessage(GameInputPtr->ToggleFFEnabled(0) ? LOC_TEXT("ffFriction Enabled")
                                                                            : LOC_TEXT("ffFriction Disabled"),
                        3.0f);
                    break;
                }
                case EQ_VK_2: {
                    Player->Hud.SetMessage(GameInputPtr->ToggleFFEnabled(1) ? LOC_TEXT("ffCollide Enabled")
                                                                            : LOC_TEXT("ffCollide Disabled"),
                        3.0f);
                    break;
                }
                case EQ_VK_3: {
                    Player->Hud.SetMessage(
                        GameInputPtr->ToggleFFEnabled(2) ? LOC_TEXT("ffShake Enabled") : LOC_TEXT("ffShake Disabled"),
                        3.0f);
                    break;
                }
                case EQ_VK_4: {
                    Player->Hud.SetMessage(
                        GameInputPtr->ToggleFFEnabled(3) ? LOC_TEXT("ffSpring Enabled") : LOC_TEXT("ffSpring Disabled"),
                        3.0f);
                    break;
                }
                case EQ_VK_6: {
                    if (GetWaypoints() && MMSTATE.GameMode == mmGameMode::Checkpoint)
                        GetWaypoints()->GetClosestWaypoint();
                    break;
                }
                case EQ_VK_7: {
                    NextRace();
                    break;
                }
                case EQ_VK_8: {
                    if (!NETMGR.InSession())
                    {
                        Warningf("Reloading current race...");
                        --MMSTATE.EventId;
                        NextRace();
                    }
                    break;
                }
                case EQ_VK_9: {
                    Player->Car.Sim.Explode();
                    break;
                }
                case EQ_VK_A: {
                    bool want_sfx = MMSTATE.AudFlags & AudManager::GetSoundFXOnMask();
                    bool want_cd = MMSTATE.AudFlags & AudManager::GetCDMusicOnMask();

                    bool sfx_on = want_sfx && AUDMGRPTR->SfxOn;
                    bool cd_on = want_cd && AUDMGRPTR->CdMusicOn;

                    if (sfx_on || cd_on)
                        AUDMGRPTR->Disable(sfx_on ? 1 : 0, cd_on ? 1 : 0);
                    else
                        AUDMGRPTR->Enable(MMSTATE.AudDeviceName, want_sfx, want_cd);

                    break;
                }
                case EQ_VK_B: {
                    if (ARTSPTR->IsDebug())
                        AIMAP.DrawAppRoads();
                    break;
                }
                case EQ_VK_C: {
                    if (ARTSPTR->IsDebug())
                    {
                        static i32 target_cop = 0;

                        if (target_cop >= AIMAP.NumPolice)
                            target_cop = 0;

                        if (aiVehiclePolice* cop = AIMAP.Police(target_cop))
                            Player->SetCamInterest(&cop->Car.Sim.ICS);

                        MMSTATE.ChaseOpponents = true;
                        ++target_cop;
                    }
                    break;
                }
                case EQ_VK_D: {
                    if (ARTSPTR->IsDebug())
                        AIMAP.DrawBBoxes = !AIMAP.DrawBBoxes;
                    break;
                }
                case EQ_VK_E: {
                    GameManager()->StartReplay();
                    break;
                }
                case EQ_VK_F: {
                    GameInputPtr->UseForceFeedback = !GameInputPtr->UseForceFeedback;

                    Player->Hud.SetMessage(
                        GameInputPtr->UseForceFeedback ? LOC_TEXT("FF Enabled") : LOC_TEXT("FF Disabled"), 3.0f);
                    break;
                }
                case EQ_VK_G: {
                    AnimMgr->BridgeMgr.ToggleDrawLabels();
                    break;
                }
                case EQ_VK_I: {
                    if (ARTSPTR->IsDebug())
                        AIMAP.DrawIntersectionIds = !AIMAP.DrawIntersectionIds;
                    break;
                }
                case EQ_VK_L: {
                    if (ARTSPTR->IsDebug())
                        AIMAP.DrawPathIds = !AIMAP.DrawPathIds;
                    break;
                }
                case EQ_VK_M: {
                    if (ARTSPTR->IsDebug())
                        AIMAP.DrawIntersections = !AIMAP.DrawIntersections;
                    break;
                }
                case EQ_VK_N: {
                    if (ARTSPTR->IsDebug())
                        AIMAP.DrawNextVisibleAmbient();
                    break;
                }
                case EQ_VK_O: {
                    if (ARTSPTR->IsDebug())
                    {
                        static i32 target_opp = 0;

                        if (target_opp >= AIMAP.NumOpponents)
                            target_opp = 0;

                        if (aiVehicleOpponent* opp = AIMAP.Opponent(target_opp))
                            Player->SetCamInterest(&opp->Car.Sim.ICS);

                        Player->Hud.SetMessage(LOC_TEXT(arts_formatf<64>("Opponent #%d", target_opp)), 5.0f);

                        MMSTATE.ChaseOpponents = false;
                        ++target_opp;
                    }
                    break;
                }
                case EQ_VK_P: {
                    Player->Hud.RecordPosition(Popup->GetComment());
                    Popup->SetComment(const_cast<char*>(""));
                    break;
                }
                case EQ_VK_Q: {
                    masscycle = (masscycle + 1) % 3;
                    Player->Car.Sim.ICS.Mass = defmass - masscycle * -500.0f;
                    Player->Hud.SetMessage(LOC_TEXT(arts_formatf<64>("Mass=%f", Player->Car.Sim.ICS.Mass)), 3.0f);
                    break;
                }
                case EQ_VK_R: {
                    static i32 next_pos = 0;
                    Matrix34 matrix;

                    if (next_pos >= ResetPositions->GetCount())
                        next_pos = 0;

                    if (ResetPositions->Recall(next_pos, &matrix, 0, 0))
                    {
                        Player->Car.Sim.SetResetPos(matrix.m3);

                        Player->Car.Sim.ResetRotation =
                            ResetPositions->Positions[next_pos]->Position.w * -ARTS_DEG_TO_RADF;
                        Reset();
                    }

                    ++next_pos;
                    break;
                }
                case EQ_VK_S: {
                    CullCity()->ToggleSky();
                    break;
                }
                case EQ_VK_T: {
                    if (ARTSPTR->IsDebug())
                        AIMAP.DrawAmbientPts = !AIMAP.DrawAmbientPts;
                    break;
                }
                case EQ_VK_U: {
                    Player->SetCamInterest(nullptr);
                    MMSTATE.ChaseOpponents = false;
                    break;
                }
                case EQ_VK_W: {
                    if (ARTSPTR->IsDebug())
                        AIMAP.DrawAmbientIds = !AIMAP.DrawAmbientIds;
                    break;
                }
                default: break;
            }
        }
        else
#endif
        {
            switch (event.Key)
            {
                case EQ_VK_ESCAPE: {
                    if (VoiceCommentary)
                        VoiceCommentary->StopNow();

                    Popup->ProcessEscape(!NETMGR.InSession());
                    break;
                }
#ifdef ARTS_DEV_BUILD
                case EQ_VK_P: {
                    Player->Hud.TogglePositionDisplay(-1);
                    break;
                }
#endif
                case EQ_VK_F1: {
                    Popup->ProcessKeymap(!NETMGR.InSession());
                    break;
                }
                case EQ_VK_F2: {
                    if (!NETMGR.InSession() && !IsPopupEnabled())
                        ARTSPTR->TogglePause();
                    break;
                }
                case EQ_VK_F4: {
                    GameManager()->Reset();
                    break;
                }
                case EQ_VK_F5: {
                    if (MMSTATE.NetworkStatus == 0)
                        Player->Car.ReleaseTrailer();
                    break;
                }
                case EQ_VK_F6: {
                    if (NETMGR.InSession())
                        Popup->ShowRoster();
                    break;
                }
                case EQ_VK_F9: {
                    Pipe()->Defragment();
                    break;
                }
                default: {
                    UpdateDebugKeyInput(event.Key);
                    break;
                }
            }
        }
    }
}

void mmGame::UpdatePaused()
{
    while (EventQueue->Pop(&CurrentEvent))
    {
        if ((CurrentEvent.Common.Type != eqEventType::Keyboard) || (CurrentEvent.Key.Key == 0))
            continue;

        eqKeyboardEvent& event = CurrentEvent.Key;

        if (event.Modifiers & EQ_KMOD_DOWN)
            continue;

        switch (event.Key)
        {
            case EQ_VK_C: {
                Player->ToggleCam();
                break;
            }
            case EQ_VK_V: {
                Player->ToggleExternalView();
                break;
            }
            case EQ_VK_F1: {
                Popup->ProcessKeymap(!NETMGR.InSession());
                break;
            }
            case EQ_VK_F2: {
                if (!NETMGR.InSession() && !IsPopupEnabled())
                    ARTSPTR->TogglePause();
                break;
            }
        }
    }
}

b32 mmGame::IsPopupEnabled()
{
    return Popup->IsEnabled();
}

run_once([] {
    create_hook("IconColor", "Add Player 8 Icon", 0x40E9AC, IconColor + ARTS_SIZE(IconColor), hook_type::pointer);
});
