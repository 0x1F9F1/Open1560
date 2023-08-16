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

define_dummy_symbol(mmgame_multicr);

#include "multicr.h"

#include "arts7/sim.h"
#include "localize/localize.h"
#include "mmaudio/manager.h"
#include "mmaudio/mmvoicecommentary.h"
#include "mmaudio/sound.h"
#include "mmcityinfo/state.h"
#include "mmnetwork/network.h"

#include "player.h"
#include "popup.h"
#include "wphud.h"
#include "wpobject.h"

mmWaypoints* mmMultiCR::GetWaypoints()
{
    return nullptr;
}

void mmMultiCR::UpdateDebugKeyInput(i32 /*arg1*/)
{}

void mmMultiCR::OppStealGold(i32 player)
{
    StealGold(Cars[player]);
    Player->Hud.CrHud->ActivateRosterGold(NetObjects[player].PlayerID);

    OppIconInfo& icon = OppIcons[player];
    icon.Place = OPP_ICON_GOLD;
    icon.Enabled = true;

    if (NETMGR.IsHost())
        ++TimesGoldStolen;
}

i32 mmMultiCR::SelectTeams()
{
    return 0;
}

void mmMultiCR::SendSetup(ulong /*arg1*/)
{}

void mmMultiCR::StealGold(mmCar* car)
{
    GoldCarrier = car;

    mmMultiCR::FondleCarMass(GoldCarrier, static_cast<float>(MMSTATE.CRGoldMass));
    field_1EEB0->Initialized = true;
}

void mmMultiCR::UpdateGame()
{
    switch (GameState)
    {
        case 0: {
            if (NETMGR.IsHost())
                GameState = 1;
            break;
        }

        case 1: {
            GameState = 2;
            if (MMSTATE.HasMidtownCD)
                AudMgr()->PlayCDTrack(GetCDTrack(10), true);
            Player->Hud.StopTimers();
            break;
        }

        case 2: {
            if (MMSTATE.CRLimitMode == mmCRLimitMode::Time && NETMGR.IsHost())
            {
                field_1EEFC.Start();
                Player->Hud.BlitzTimer.Start();
            }

            StartSounds->ActiveSound = 0;
            StartSounds->PlayOnce(-1.0, -1.0);

            Player->Hud.SetMessage(LOC_STRING(MM_IDS_RACE_GO), 2.0f, true);

            if (VoiceCommentary)
                VoiceCommentary->PlayCRPreRace();

            EnableRacers();
            GameState = 4;
            break;
        }

        case 4: {
            if (!MMSTATE.DisableDamage && Player->IsMaxDamaged())
            {
                Player->Hud.SetMessage(LOC_STRING(MM_IDS_DAMAGE_PENALTY), 5.0f, false);
                ;
                if (VoiceCommentary)
                    VoiceCommentary->PlayTimePenalty();

                GameStateWait = 5.0f;
                GameState = 6;

                if (GoldCarrier == &Player->Car)
                {
                    DropGold(Player->Car.GetICS()->Matrix.m3, 0);
                    FondleCarMass(&Player->Car, -static_cast<float>(MMSTATE.CRGoldMass));

                    if (VoiceCommentary)
                        VoiceCommentary->PlayCR(1, static_cast<b16>(MMSTATE.CRIsRobber));

                    Player->Hud.Arrow.SetInterest(&field_1EEB0->Position);
                    Player->EnableRegen(1);
                }
            }
            break;
        }

        case 5: {
            GameStateWait -= Sim()->GetUpdateDelta();

            if (GameStateWait <= 0.0f)
                MMSTATE.GameState = mmGameState::Menus;

            if (MMSTATE.HasMidtownCD)
                AudMgr()->PlayCDTrack(GetCDTrack(10), true);
            break;
        }

        case 6: {
            GameStateWait -= Sim()->GetUpdateDelta();

            if (GameStateWait <= 0.0f)
            {
                Player->ResetDamage();
                Player->Car.EnableDriving(true);
                GameState = 4;
                SendMsg(509);
            }
            break;
        }

        case 7: {
            GameStateWait -= Sim()->GetUpdateDelta();
            if (GameStateWait <= 0.0f)
                GameState = 4;
            break;
        }

        case 9: {
            if (GameStateWait > 0.0f)
            {
                GameStateWait -= Sim()->GetUpdateDelta();
            }
            else
            {
                FillResults();
                Player->ForceStop = 1;
                GameState = 10;
            }
            break;
        }

        case 10: {
            if (!Popup->IsEnabled())
                Popup->ShowResults();
            break;
            default: break;
        }
    }

    if (GameState != 9 && GameState != 10)
    {
        UpdateHUD();
        UpdateLimit();
        UpdateTimeWarning();
        UpdateGold();
        UpdateHUD();
        if (MMSTATE.CRIsRobber)
            UpdateHideout();
        else
            UpdateBank();
    }

    PlayerObject.Flags |= field_1EEA4 & 0xFFFF0000;
    mmGameMulti::UpdateGame();
}