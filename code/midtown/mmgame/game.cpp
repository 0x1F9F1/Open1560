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
#include "agiworld/texsort.h"
#include "arts7/cullmgr.h"
#include "arts7/lamp.h"
#include "arts7/sim.h"
#include "data7/memstat.h"
#include "eventq7/eventq.h"
#include "eventq7/keys.h"
#include "localize//localize.h"
#include "mmai/aiIntersection.h"
#include "mmai/aiMap.h"
#include "mmai/aiPath.h"
#include "mmai/aiTrafficLight.h"
#include "mmai/aiVehicleMGR.h"
#include "mmai/aiVehicleOpponent.h"
#include "mmai/aiVehiclePolice.h"
#include "mmai/aiaudiomanager.h"
#include "mmanim/AnimMgr.h"
#include "mmaudio/head.h"
#include "mmaudio/manager.h"
#include "mmaudio/mmvoicecommentary.h"
#include "mmaudio/sound.h"
#include "mmbangers/data.h"
#include "mmcamcs/viewcs.h"
#include "mmcar/carsimcheap.h"
#include "mmcar/surfaceaudioinfo.h"
#include "mmcity/cullcity.h"
#include "mmcity/loader.h"
#include "mmcity/position.h"
#include "mmcity/positions.h"
#include "mmcityinfo/citylist.h"
#include "mmcityinfo/playerdata.h"
#include "mmcityinfo/racedata.h"
#include "mmcityinfo/state.h"
#include "mminput/input.h"
#include "mmnetwork/network.h"
#include "mmphysics/phys.h"
#include "mmui/pu_results.h"
#include "stream/hfsystem.h"

#include "gameman.h"
#include "mmambientaudio.h"
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

    // TODO: Move to mmInput constructor
    GameInput()->SetNodeFlag(NODE_FLAG_UPDATE_PAUSED);

    BangerProjectile = nullptr;
}

mmGame::~mmGame()
{
    if (MMCURRPLAYER.Loaded && EnableSave)
    {
        Config.SetIOPath("players"_xconst);
        Config.GetControls();
        Config.GetAudio();
        Config.GetGraphics();

        if (NextHudMode != -1)
            Player->HudMap.SetMode(NextHudMode);

        Config.GetViewSettings();

        Config.Save(MMCURRPLAYER.GetFileName(), true);
    }

    if (!LogOpenOn)
    {
        DontClearPositions = true;
        DumpPositions("positions.csv"_xconst);

        i32 max_posi = 0;
        WIN32_FIND_DATAA find_data;

        if (HANDLE find_handle = FindFirstFileA("posi*.csv", &find_data); find_handle != INVALID_HANDLE_VALUE)
        {
            do
            {
                max_posi = (std::max)(max_posi, std::atoi(&find_data.cFileName[4]));
            } while (FindNextFileA(find_handle, &find_data));

            FindClose(find_handle);
        }

        DontClearPositions = false;
        DumpPositions(arts_formatf<64>("posi%04d.csv", max_posi + 1));
    }

    {
        ARTS_MEM_STAT("mmGame Destructor");

        if (HasAIMap)
            AIMAP.Clean();

        pCullCity = nullptr;
        Player = nullptr;
        Lamp = nullptr;
        LampCS = nullptr;
        EventQueue = nullptr;
        Popup = nullptr;
        AnimMgr = nullptr;

        PHYS.Shutdown();

        AmbientAudio = nullptr;

        // FIXME: Freed by some child classes, but not zeroed
        StartSounds.release();
    }
}

void mmGame::UpdateDebugInput()
{
    while (EventQueue->Pop(&CurrentEvent))
    {
        if ((CurrentEvent.Type != eqEventType::Keyboard) || (CurrentEvent.Key.Key == 0))
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

void mmGame::UpdateGameInput()
{
    if (bool horn = GameInput()->IsInputPressed(IOID_HORN); static_cast<b16>(horn) != HornPressed)
    {
        HornPressed = horn;

        if (horn)
        {
            if (BangerProjectile)
                BangerProjectile->LaunchInstance(ProjectileY, &ProjectileV);

            if (Player->Car.Model.HasSiren())
                Player->Car.ToggleSiren();
            else
                Player->Car.Sim.PlayHorn();
        }
        else
        {
            if (!Player->Car.Model.HasSiren())
                Player->Car.Sim.StopHorn();
        }
    }

    for (i32 event = -1; GameInput()->PopEvent(&event);)
    {
        switch (event)
        {
            case IOID_MAP: {
                Player->HudMap.Cycle();

                if (!Player->HudMap.IsNodeActive() && Player->IsPOV() && Player->WideFov)
                    Player->SetWideFOV(true);

                break;
            }
            case IOID_FMAP: Player->HudMap.ToggleFullScreen(); break;
            case IOID_MAPRES: Player->HudMap.ToggleMapRes(); break;
            case IOID_HUD: Player->Hud.ToggleExternalView(); break;
            case IOID_CAM: Player->ToggleCam(); break;
            case IOID_XVIEW: Player->ToggleExternalView(); break;

            case IOID_WFOV: {
                if (Player->HudMap.GetMode() < HUD_MAP_MODE_2)
                {
                    Player->ToggleWideFOV();

                    if (Player->Hud.IsDashActive() && Player->WideFov)
                    {
                        Player->Hud.DeactivateDash();

                        // FIXME: Find a better way to track if the dash was active
                        Player->Hud.DashView.Active = true;
                        Player->Car.Model.Deactivate();
                    }
                }

                if (!Player->WideFov && Player->Hud.DashView.Active && Player->CameraMode == 0)
                    Player->Hud.ActivateDash();

                break;
            }

            case IOID_DASH: Player->ToggleDash(); break;

            case IOID_TRANS: {
                if (mmTransmission& trans = Player->Car.Sim.Trans; trans.IsAutomatic)
                {
                    GameInput()->SwapThrottle = false;
                    trans.Automatic(false);
                }
                else
                {
                    trans.Automatic(true);
                }

                break;
            }

            case IOID_UPSH: {
                if (mmTransmission& trans = Player->Car.Sim.Trans; trans.IsAutomatic)
                    trans.SetDrive();
                else
                    trans.Upshift();

                break;
            }

            case IOID_DWNS: {
                if (mmTransmission& trans = Player->Car.Sim.Trans; trans.IsAutomatic)
                    trans.SetReverse();
                else
                    trans.Downshift();

                break;
            }

            case IOID_REV: {
                GameInput()->SwapThrottle = false;

                if (mmTransmission& trans = Player->Car.Sim.Trans; trans.IsReverse())
                    trans.SetDrive();
                else
                    trans.SetReverse();

                break;
            }

            case IOID_CDSHOW: Player->Hud.CDPlayer.Toggle(); break;
            case IOID_CDPLAY: Player->Hud.CDPlayer.PlayStop(); break;
            case IOID_CDPRIOR: Player->Hud.CDPlayer.PrevTrack(); break;
            case IOID_CDNEXT: Player->Hud.CDPlayer.NextTrack(); break;

            case IOID_MIRROR: Player->Hud.ToggleMirror(); break;

            case IOID_OPPPOS: {
                MMSTATE.ShowPositions ^= true;
                SetIconsState();
                break;
            }

            case IOID_CHAT: {
                if (NETMGR.InSession())
                    Popup->ProcessChat();
                break;
            }

            default: UpdateGameInput(event); break;
        }
    }

    Player->CamPan = GameInput()->GetCamPan();

    if (Player->IsPOV())
    {
        if (Player->CamPan == 0.0f)
            Player->Hud.ActivateNode();
        else
            Player->Hud.DeactivateNode();
    }
}

void mmGame::UpdatePaused()
{
    for (i32 event = -1; GameInput()->PopEvent(&event);)
    {
        switch (event)
        {
            case IOID_CAM: Player->ToggleCam(); break;
            case IOID_XVIEW: Player->ToggleExternalView(); break;
        }
    }

    while (EventQueue->Pop(&CurrentEvent))
    {
        if ((CurrentEvent.Type != eqEventType::Keyboard) || (CurrentEvent.Key.Key == 0))
            continue;

        eqKeyboardEvent& event = CurrentEvent.Key;

        if (event.Modifiers & EQ_KMOD_DOWN)
            continue;

        if (event.Modifiers & EQ_KMOD_SHIFT)
            continue;

        switch (event.Key)
        {
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

b32 mmGame::Init()
{
    ResetPositions = arnew mmPositions();
    ResetPositions->Init(100);

    Displayf("DIFFICULTY: %s", (MMSTATE.Difficulty == mmSkillLevel::Professional) ? "Professional" : "Amateur");
    Displayf("%splayer game", MMSTATE.NetworkStatus ? "Multi" : "Single");

    switch (MMSTATE.GameMode)
    {
        case mmGameMode::Cruise: Displayf("GAMETYPE: Roam mode."); break;
        case mmGameMode::Checkpoint: Displayf("GAMETYPE: Checkpoint %d", MMSTATE.EventId); break;
        case mmGameMode::CnR: Displayf("GAMETYPE: C&R"); break;
        case mmGameMode::Circuit: Displayf("GAMETYPE: Circuit %d", MMSTATE.EventId); break;
        case mmGameMode::Blitz: Displayf("GAMETYPE: Blitz %d", MMSTATE.EventId); break;
    }

    InitGameStrings();
    HornPressed = false;

    if (!LogOpenOn)
    {
        LoadPositions("positions.csv"_xconst);
        ResetPositions->Load("resetpositions.csv"_xconst);
    }

    if (ResetPositions->GetCount() == 0)
    {
        // FIXME: Pass position as const reference
        Vector4 pos;

        ResetPositions->Register(pos = {-458.0f, 4.0f, -1429.0f, 67.0f});
        ResetPositions->Register(pos = {973.0f, 4.0f, -1003.0f, -121.0f});
        ResetPositions->Register(pos = {-137.0f, 7.0f, -954.0f, 175.0f});
        ResetPositions->Register(pos = {-714.0f, 2.0f, -620.0f, 49.0f});
        ResetPositions->Register(pos = {-135.0f, 2.0f, -221.0f, 89.0f});
        ResetPositions->Register(pos = {421.0f, 2.0f, 220.0f, -158.0f});
        ResetPositions->Register(pos = {-901.0f, 6.0f, 360.0f, -90.0f});
        ResetPositions->Register(pos = {-177.0f, 2.0f, 409.0f, -1.0f});
        ResetPositions->Register(pos = {2.0f, 12.0f, 1359.0f, 109.0f});
        ResetPositions->Register(pos = {949.0f, 2.0f, 1210.0f, -5.0f});
        ResetPositions->Register(pos = {0.0f, 0.0f, 0.0f, 0.0f});
    }

    MemStat game_init {"mmGame"};

    PlayerSetState();

    switch (MMSTATE.Weather)
    {
        case mmWeather::Rain: TextureSuffix = "_fall"_xconst; break;
        case mmWeather::Snow: TextureSuffix = "_win"_xconst; break;
        default: TextureSuffix = nullptr; break;
    }

    {
        Loader()->BeginTask(LOC_STRING(MM_IDS_LOADING_AUDIO));

        AudMgr()->SetBitDepthAndSampleRate(MMSTATE.AudFlags & AudManager::GetHiSampleSizeMask(),
            (MMSTATE.AudFlags & AudManager::GetHiResMask()) ? 22050 : 11025);

        switch (MMSTATE.Weather)
        {
            case mmWeather::Rain: SetRainSurfaceAudioInfos(); break;
            case mmWeather::Snow: SetSnowSurfaceAudioInfos(); break;
            default: SetClearSurfaceAudioInfos(); break;
        }

        Loader()->EndTask();
    }

    {
        ARTS_MEM_STAT("mmRace constructors");
        Loader()->SetIntroText(LOC_TEXT(MMSTATE.IntroText));
        Loader()->BeginTask(LOC_STRING(MM_IDS_LOADING_CITY));

        pCullCity = arnew mmCullCity();

        Lamp = arnew asLamp();
        LampCS = arnew asLinearCS();

        mmCityInfo* city_info = CityList()->GetCurrentCity();
        arts_strcpy(MapName, city_info->MapName);
        arts_strcpy(RaceDir, city_info->RaceDir);

        // FIXME: Some custom chicago locales happen to start with c but not chicago, i.e customrace.
        CHICAGO = MapName[0] == 'c' || MapName[0] == 'C'; // !arts_strnicmp(MapName, "chicago", 7);

        Displayf("%s maps to %s (CHICAGO=%d)", MapName, RaceDir, CHICAGO);

        if (MMSTATE.AudFlags & AudManager::GetCommentaryOnMask())
        {
            VoiceCommentary = arnew mmVoiceCommentary();
            VoiceCommentary->ValidateCity(RaceDir);
        }
        else
        {
            VoiceCommentary = nullptr;
        }

        AudMgr()->SetVoiceCommentaryPtr(VoiceCommentary.get());

        Loader()->EndTask();
    }

    {
        Loader()->BeginTask(LOC_STRING(MM_IDS_LOADING_PLAYER));

        InitMyPlayer();
        Player->Car.Sim.Trans.Automatic(MMSTATE.AutoTransmission);

        Loader()->EndTask();
    }

    {
        ARTS_MEM_STAT("City and PHYS init");

        pCullCity->Init(MapName, &Player->Camera);
        PHYS.Init(&Player->Car.Sim.ICS, Player->ViewCS);
        Player->Init(MMSTATE.CarName, MapName, this);
        Icons.Init(&Player->ViewCS->World, 2500.0f, 90000.0f);

        if (MMSTATE.AudFlags & AudManager::GetDSound3DMask())
        {
            Ptr<AudHead> aud_head = arnew AudHead(CullCity()->Camera->GetCameraMatrix());

            aud_head->Init();
            aud_head->SetRolloff(0.0f);
            aud_head->SetDoppler(0.0f);

            AddChild(aud_head.get());

            // FIXME: Memory leak
            aud_head.release();
        }
    }

    InitGameObjects();

    {
        ARTS_MEM_STAT("AI");
        Loader()->BeginTask(LOC_STRING(MM_IDS_LOADING_AI));

        char city_folder[128];
        arts_sprintf(city_folder, "city/%s", MapName);

        char aimap_file[128];
        HasAIMap = false;

        if (EnableAI && !MMSTATE.DisableAI &&
            (FindFile(MapName, city_folder, ".map", 0, aimap_file, ARTS_SIZE(aimap_file)) ||
                FindFile(MapName, city_folder, ".bai", 0, aimap_file, ARTS_SIZE(aimap_file))))
        {
            // aiTrafficLightSet::ObjCount = 0;

            AIMAP.Init(RaceDir, aimap_file, city_folder, &Player->Car);
            HasAIMap = true;

            // TODO: Handle more than 8 opponents
            ArAssert(AIMAP.NumOpponents <= ARTS_SSIZE32(OppIcons), "Too Many AI");

            for (i32 i = 0; i < AIMAP.NumOpponents; ++i)
            {
                OppIconInfo& icon = OppIcons[i];
                icon.Position = &AIMAP.Opponent(i)->Car.GetICS()->Matrix;
                icon.Enabled = true;
                icon.Place = OPP_ICON_BLANK;
                arts_sprintf(icon.Name, LOC_STR(MM_IDS_OPP_NAME), i + 1);
            }

            Player->HudMap.RegisterOpponents(OppIcons, AIMAP.NumOpponents);
            Icons.RegisterOpponents(OppIcons, AIMAP.NumOpponents, nullptr);
            // Player->HudMap.AiMap = &AIMAP;

            if (!MMSTATE.NetworkStatus && AiAudMgr())
                AiAudMgr()->PlayerSpeed = &Player->Car.Sim.Speed;
        }

        Loader()->EndTask();
    }

    InitOtherPlayers();
    InitHUD();

    // TODO: Fix crash in mmBridgeSet::Init when the AI map is missing
    if (!MMSTATE.DisableAI)
    {
        AnimMgr = arnew mmAnimMgr();
        AnimMgr->Init(MapName, Player->Car.Sim.Model, nullptr, 0);
        AddChild(AnimMgr.get());
    }

    for (bool changed = true; changed;)
    {
        changed = false;

        for (i32 i = 0; i < AIMAP.NumIntersections; ++i)
        {
            aiIntersection* isect = AIMAP.Intersection(i);
            i32 num_sinks = 0;

            for (i32 j = 0; j < isect->NumSinkPaths; ++j)
            {
                // FIXME: aiMap::ChooseNextLaneLink does not support roads with the same sink and source intersection
                if (aiPath* sink = isect->SinkPath(j); !sink->IsBlocked && !sink->HasBridge && (sink->Sink != isect))
                    ++num_sinks;
            }

            if (num_sinks == 1)
            {
                Warningf("Blocked dead-end intersection %i", isect->Id);

                for (i32 j = 0; j < isect->NumSinkPaths; ++j)
                    isect->SinkPath(j)->Blocked(true);

                for (i32 j = 0; j < isect->NumSourcePaths; ++j)
                    isect->SourcePath(j)->Blocked(true);

                changed = true;
            }
        }
    }

    {
        Loader()->BeginTask(LOC_STRING(MM_IDS_LOADING_MORE_AUDIO));

        if (MMSTATE.Weather == mmWeather::Sun && !MMSTATE.NetworkStatus && AIMAP.NumAmbients > 0)
            AmbientAudio = arnew mmAmbientAudio(Player.get());
        else
            AmbientAudio = nullptr;

        Loader()->EndTask();
    }

    LampCS->Matrix.m3 = {10.0f, 1000.0f, 10.0f};
    LampCS->SetName("Lamp");
    Lamp->SetDistant();

    EventQueue = arnew eqEventQ(1, -1, 32);
    Popup = arnew mmPopup(this, 0.2f, 0.1f, 0.6f, 0.8f);
    Popup->Reset();

    game_init.End();

    switch (MMSTATE.GameMode)
    {
        case mmGameMode::Checkpoint: {
            string event_names = CityList()->GetCurrentCity()->CheckpointNames.get();
            string event_name = event_names.SubString(MMSTATE.EventId + 1);
            Popup->Results->AddTitle(LOC_STRING(MM_IDS_CHECKPOINT_RACE), event_name.get_loc());
            break;
        }

        case mmGameMode::CnR: {
            LocString* event_name = nullptr;

            switch (MMSTATE.CRGameClass)
            {
                case mmCRGameClass::FreeForAll: event_name = LOC_STRING(MM_IDS_CNR_FREE_FOR_ALL); break;
                case mmCRGameClass::CopsRobbers: event_name = LOC_STRING(MM_IDS_CNR_COPS_N_ROBBERS); break;
                case mmCRGameClass::RobberTeams: event_name = LOC_STRING(MM_IDS_CNR_ROBBERS_TEAMS); break;
                default: event_name = LOC_TEXT(""); break;
            }

            Popup->Results->AddTitle(LOC_STRING(MM_IDS_COPS_N_ROBBERS), event_name);
            break;
        }

        case mmGameMode::Circuit: {
            string event_names = CityList()->GetCurrentCity()->CircuitNames.get();
            string event_name = event_names.SubString(MMSTATE.EventId + 1);
            Popup->Results->AddTitle(LOC_STRING(MM_IDS_CIRCUIT_RACE), event_name.get_loc());
            break;
        }

        case mmGameMode::Blitz: {
            string event_names = CityList()->GetCurrentCity()->BlitzNames.get();
            string event_name = event_names.SubString(MMSTATE.EventId + 1);
            Popup->Results->AddTitle(LOC_STRING(MM_IDS_BLITZ_RACE), event_name.get_loc());
            break;
        }
        default: break;
    }

    return true;
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

        BangerProjectile = BangerDataMgr()->GetBangerData("tpmail"_xconst, nullptr);
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
    else if (X("cop2opp"))
    {
        CHEATING = true;

        MMSTATE.ChaseOpponents = true;
    }

#undef X
}
