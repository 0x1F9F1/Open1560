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
#include "mmai/aiVehicleMGR.h"
#include "mmai/aiVehicleOpponent.h"
#include "mmai/aiVehiclePolice.h"
#include "mmanim/AnimMgr.h"
#include "mmaudio/manager.h"
#include "mmaudio/mmvoicecommentary.h"
#include "mmbangers/data.h"
#include "mmcar/carsimcheap.h"
#include "mmcity/cullcity.h"
#include "mmcity/position.h"
#include "mmcityinfo/state.h"
#include "mminput/input.h"
#include "mmnetwork/network.h"
#include "mmphysics/phys.h"

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

mmGame::mmGame()
{
    for (i32 i = 0; i < 8; ++i)
    {
        OppIconInfo* icon = &OppIcons[i];
        icon->Color = IconColor[i];
        icon->Enabled = false;
        icon->Position = nullptr;
    }

    arts_strcpy(LocPlayerName, LOC_STR(MM_IDS_PLAYER_NAME));

    BangerProjectile = nullptr;
}

void mmGame::UpdateDebugInput()
{
    while (EventQueue->Pop(&CurrentEvent))
    {
        if ((CurrentEvent.Common.Type != eqEventType::Keyboard) || (CurrentEvent.Key.Key == 0))
            continue;

        eqKeyboardEvent& event = CurrentEvent.Key;

        if (event.Modifiers & EQ_KMOD_DOWN)
        {
            if (event.Key == EQ_VK_F7 &&
                (event.Modifiers & (EQ_KMOD_DOWN | EQ_KMOD_SHIFT | EQ_KMOD_CTRL | EQ_KMOD_ALT)) ==
                    (EQ_KMOD_DOWN | EQ_KMOD_SHIFT | EQ_KMOD_CTRL | EQ_KMOD_ALT) &&
                !NETMGR.InSession())
            {
                Popup->ProcessChat();
            }

            continue;
        }

#ifdef ARTS_DEV_BUILD
        if ((event.Modifiers & EQ_KMOD_SHIFT) && Sim()->IsDebug())
        {
            switch (event.Key)
            {
                case EQ_VK_1: {
                    Player->Hud.SetMessage(GameInput()->ToggleFFEnabled(0) ? LOC_TEXT("ffFriction Enabled")
                                                                           : LOC_TEXT("ffFriction Disabled"),
                        3.0f);
                    break;
                }
                case EQ_VK_2: {
                    Player->Hud.SetMessage(GameInput()->ToggleFFEnabled(1) ? LOC_TEXT("ffCollide Enabled")
                                                                           : LOC_TEXT("ffCollide Disabled"),
                        3.0f);
                    break;
                }
                case EQ_VK_3: {
                    Player->Hud.SetMessage(
                        GameInput()->ToggleFFEnabled(2) ? LOC_TEXT("ffShake Enabled") : LOC_TEXT("ffShake Disabled"),
                        3.0f);
                    break;
                }
                case EQ_VK_4: {
                    Player->Hud.SetMessage(
                        GameInput()->ToggleFFEnabled(3) ? LOC_TEXT("ffSpring Enabled") : LOC_TEXT("ffSpring Disabled"),
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

                    bool sfx_on = want_sfx && AudMgr()->SfxOn;
                    bool cd_on = want_cd && AudMgr()->CdMusicOn;

                    if (sfx_on || cd_on)
                        AudMgr()->Disable(sfx_on ? 1 : 0, cd_on ? 1 : 0);
                    else
                        AudMgr()->Enable(MMSTATE.AudDeviceName, want_sfx, want_cd);

                    break;
                }
                case EQ_VK_B: {
                    if (Sim()->IsDebug())
                        AIMAP.DrawAppRoads();
                    break;
                }
                case EQ_VK_C: {
                    if (Sim()->IsDebug())
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
                    if (Sim()->IsDebug())
                        AIMAP.DrawBBoxes = !AIMAP.DrawBBoxes;
                    break;
                }
                case EQ_VK_E: {
                    GameMgr()->StartReplay();
                    break;
                }
                case EQ_VK_F: {
                    GameInput()->UseForceFeedback = !GameInput()->UseForceFeedback;

                    Player->Hud.SetMessage(
                        GameInput()->UseForceFeedback ? LOC_TEXT("FF Enabled") : LOC_TEXT("FF Disabled"), 3.0f);
                    break;
                }
                case EQ_VK_G: {
                    AnimMgr->BridgeMgr.ToggleDrawLabels();
                    break;
                }
                case EQ_VK_I: {
                    if (Sim()->IsDebug())
                        AIMAP.DrawIntersectionIds = !AIMAP.DrawIntersectionIds;
                    break;
                }
                case EQ_VK_L: {
                    if (Sim()->IsDebug())
                        AIMAP.DrawPathIds = !AIMAP.DrawPathIds;
                    break;
                }
                case EQ_VK_M: {
                    if (Sim()->IsDebug())
                        AIMAP.DrawAllPaths = !AIMAP.DrawAllPaths;
                    break;
                }
                case EQ_VK_N: {
                    if (Sim()->IsDebug())
                        AIMAP.DrawNextVisibleAmbient();
                    break;
                }
                case EQ_VK_O: {
                    if (Sim()->IsDebug())
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
                    Popup->RecordPosition();
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
                            ResetPositions->Positions[next_pos]->Position.w * -ARTS_DEG_TO_RAD;
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
                    if (Sim()->IsDebug())
                        AIMAP.DrawTargetPoints = !AIMAP.DrawTargetPoints;
                    break;
                }
                case EQ_VK_U: {
                    Player->SetCamInterest(nullptr);
                    MMSTATE.ChaseOpponents = false;
                    break;
                }
                case EQ_VK_W: {
                    if (Sim()->IsDebug())
                        AIMAP.DrawAmbientIds = !AIMAP.DrawAmbientIds;
                    break;
                }
                default: break;
            }
        }
        else
#endif
            if (!(event.Modifiers & EQ_KMOD_SHIFT))
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
                        Sim()->TogglePause();
                    break;
                }
                case EQ_VK_F4: {
                    GameMgr()->Reset();
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

        if (event.Modifiers & EQ_KMOD_SHIFT)
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
                    Sim()->TogglePause();
                break;
            }
        }
    }
}

b32 mmGame::IsPopupEnabled()
{
    return Popup->IsEnabled();
}

void mmGame::SendChatMessage(char* msg)
{
    if (*msg != '/')
        return;

#define X(NAME) !std::strncmp(msg + 1, NAME, std::strlen(NAME))

    if (X("big"))
    {
        BoneScale = 5.0f;
    }
    else if (X("tiny"))
    {
        BoneScale = 0.2f;
    }
    else if (X("swap"))
    {
        AnimMgr->AirlinerSwap();
    }
    else if (X("ufo"))
    {
        AnimMgr->UFOSwap();
    }
    else if (X("posta" /*l*/))
    {
        CHEATING = true;

        BangerProjectile = BangerDataMgr()->GetBangerData(xconst("tpmail"), nullptr);
        ProjectileV = Vector3(0.0f, 5.0f, -30.0f);
    }
    else if (X("banger "))
    {
        CHEATING = true;

        const char* banger_name = msg + 8;

        BangerProjectile = BangerDataMgr()->GetBangerData(xconst(banger_name), nullptr);
        ProjectileV = Vector3(0.0f, 5.0f, -30.0f);

        if (BangerProjectile && !BangerProjectile->MeshIndex)
            BangerProjectile = nullptr;

        if (BangerProjectile == nullptr)
            Player->Hud.PostChatMessage(arts_formatf<128>("Invalid/Missing banger '%s'", banger_name));
    }
    else if (X("slid" /*"e"*/))
    {
        CHEATING = true;

        EggFriction = (EggFriction == 0.0f) ? 1.0f : 0.0f;
    }
    else if (X("grav" /*ity*/))
    {
        CHEATING = true;

        PHYS.SetGravity((PHYS.GetGravity() == -19.8f) ? -9.8f : -19.8f);
    }
    else if (X("bridg" /*e*/))
    {
        CHEATING = true;

        if (mmBridgeMgr* manager = BridgeMgr())
        {
            manager->BridgeDelta = 2.0f;
            manager->BridgeOnGoal = ARTS_PI / 4;

            for (i32 i = 0; i < manager->NumBridges; ++i)
                manager->Bridges[i].TriggerTimeout = 20.0f;
        }
    }
    else if (X("puck"))
    {
        CHEATING = true;

        CullCity()->WeatherFriction = 0.0f;
    }
    else if (X("noda" /*mage*/))
    {
        CHEATING = true;

        Player->Car.Sim.EnableDamage = false;
    }
    else if (X("dama" /*ge*/))
    {
        Player->Car.Sim.EnableDamage = true;
    }
    else if (X("ver" /*sion*/))
    {
        Player->Hud.PostChatMessage(xconst(VERSION_STRING));
    }
    else if (X("talkfast"))
    {
        if (mmVoiceCommentary* commentary = AudMgr()->GetVoiceCommentaryPtr())
            commentary->SetFrequency(1.5f);
    }
    else if (X("talkslow"))
    {
        if (mmVoiceCommentary* commentary = AudMgr()->GetVoiceCommentaryPtr())
            commentary->SetFrequency(0.75f);
    }
    else if (X("fuzz"))
    {
        CHEATING = true;

        Player->HudMap.ToggleShowAllCops();
    }
    else if (X("smok" /*e*/))
    {
        ForceSmoke = true;
        EnableSmoke = true;
    }
    else if (X("nosm" /*oke*/))
    {
        ForceSmoke = false;
        EnableSmoke = false;
    }
    else if (X("gridlock"))
    {
        CHEATING = true;

        MMSTATE.AmbientCount = 2000;
        MMSTATE.AmbientDensity = 3.0f;
        MMSTATE.PedDensity = 2.0f;
        MMSTATE.GameState = mmGameState::Drive;
    }
    else if (X("feather"))
    {
        CHEATING = true;

        EggMass = (EggMass == 1.0f) ? 0.01f : 1.0f;
    }

#undef X
}

run_once([] {
    create_hook("IconColor", "Add Player 8 Icon", 0x40E9AC, IconColor + ARTS_SIZE(IconColor), hook_type::pointer);
});
