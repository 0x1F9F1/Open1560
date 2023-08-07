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

// headers will be improved later
#include "multicr.h"
#include "arts7/sim.h"
#include "mmnetwork/network.h"
#include "player.h"
#include "wphud.h"

#include "mmaudio/head.h"
#include "mmaudio/manager.h"
#include "mmaudio/mmvoicecommentary.h"
#include "mmaudio/sound.h"

#include "popup.h"

#include "mmcar/car.h"
#include "mmcar/carsim.h"

#include "mmcityinfo/state.h"

#include "localize/localize.h"

#include "mmgame/game.h"

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


// ...
// ...
// Note: set sim.h member variables to public
// Double spacing is added for Review readability
void mmMultiCR::UpdateGame()
{
    switch (GameState)
    {
        case 0: // OK
            if (NETMGR.IsHost())
                GameState = 1;
            break; 


        case 1: // OK
            GameState = 2;
            if (MMSTATE.HasMidtownCD)
                AudMgr()->PlayCDTrack(GetCDTrack(10), true);
            Player->Hud.StopTimers();
            break;


        case 2: // ----------------------
            if (MMSTATE.CRLimitMode == mmCRLimitMode::Time && NETMGR.IsHost())
            {
                field_1EEFC.Start();
                Player->Hud.BlitzTimer.Start();
            }


            // StartSounds->ActiveSound = 0;            struct AudSound is not yet complete
            // StartSounds->PlayOnce(-1.0, -1.0);       struct AudSound is not yet complete


            Player->Hud.SetMessage(AngelReadString(0x83u), 2.0f, true);

            if (VoiceCommentary)
                VoiceCommentary->PlayCRPreRace();

            EnableRacers();
            GameState = 4; // extend enum class?
            break;


        case 4: // ----------------------
            if (!MMSTATE.DisableDamage && Player->IsMaxDamaged())
            {
                Player->Hud.SetMessage(AngelReadString(0x84u), 5.0f, false);

                if (VoiceCommentary)
                    VoiceCommentary->PlayTimePenalty();

                GameStateWait = 5.0f;
                GameState = 6;

                if (GoldCarrier == &Player->Car)
                {
                    DropGold(Player->Car.GetICS()->Matrix.m3, 0);


                    // goldMassDelta = (float) -MMSTATE.CRGoldMass;         // pseudo
                    // FondleCarMass(&Player->Car, goldMassDelta);          // pseudo

                    i32 GoldmassDelta = 500;
                    i32 GoldMass = GoldmassDelta - MMSTATE.CRGoldMass;

                    FondleCarMass(&Player->Car, GoldMass);                  // needs review
                                                                            // goal is to (also) pass other parameters, such as Horsepower or invoke damage


                    if (VoiceCommentary)
                       VoiceCommentary->PlayCR(1, MMSTATE.CRIsRobber = 1);  // 1 for true?


                    // Player->Hud.Arrow.SetInterest(&field_1EEB0->Position);           // write gap in "mmWaypointObject struc"
                    Player->Hud.Arrow.SetInterest(&Player->Car.GetICS()->Matrix.m3);    // temporary filler


                    Player->EnableRegen(1);
                }
            }
            break;


        case 5: // ----------------------


            // GameStateWait -= ARTSPTR->seconds_;      // any preference? I went with Sim() for now
            GameStateWait -= Sim()->seconds_;

            // some if statement
            // some if statement
            //  MMSTATE.GameState = 0;


            if (MMSTATE.HasMidtownCD)
                AudMgr()->PlayCDTrack(GetCDTrack(10), true);
            break;


        case 6: // ----------------------
            GameStateWait -= Sim()->seconds_;


            // some if statement
            // some if statement


            // indent
            Player->ResetDamage();
            Player->Car.EnableDriving(true);
            GameState = 4;
            SendMsg(509);
            break;


        case 7: // ----------------------
            GameStateWait -= Sim()->seconds_;


            // some if statement
            // some if statement

            
            // indent
            GameState = 4;
            break;


        case 9: // OK
            if (GameStateWait > 0.0f)
            {
                GameStateWait -= Sim()->seconds_;
            }
            else
            {
                FillResults();
                Player->ForceStop = 1;
                GameState = 10;
            }
            break;


        case 10: // OK (?)
            if (!Popup->IsEnabled())
                Popup->ShowResults();
            break;
        default: break;
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
    UpdateGame();
}