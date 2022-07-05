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

define_dummy_symbol(mmnetwork_network);

#include "network.h"

static GUID MM_GUID {0x6C9983A7, 0xC037, 0x11D2, {0xA8, 0xDA, 0x00, 0xA0, 0xC9, 0x70, 0xAF, 0x5D}};

static HRESULT(WINAPI* arts_DirectPlayCreate)(LPGUID lpGUID, LPDIRECTPLAY* lplpDP, IUnknown* pUnk);

static mem::cmd_param PARAM_dplay {"dplay"};

static bool LoadDirectPlay()
{
    if (!PARAM_dplay.get_or(true))
    {
        Displayf("DirectPlay disabled. Use `-dplay` cmd argument to enable multiplayer");
        return false;
    }

    if (!arts_DirectPlayCreate)
    {
        HMODULE hdplayx = LoadLibraryA("DPLAYX.DLL");

        if (hdplayx)
        {
            arts_DirectPlayCreate = (decltype(arts_DirectPlayCreate)) GetProcAddress(hdplayx, "DirectPlayCreate");
        }
    }

    return arts_DirectPlayCreate;
}

b32 asNetwork::Initialize(i32 max_players, b32 secure, i32 game_version)
{
    Displayf("Initializing network");

    if (!LoadDirectPlay())
    {
        Errorf("Failed to load DirectPlay");
        return false;
    }

    if (dplay_)
        return true;

    app_guid_ = &MM_GUID;
    game_version_ = static_cast<f32>(game_version);
    max_players_ = max_players;
    secure_ = secure;
    CoInitialize(NULL);

    if (CreateInterface() != DP_OK)
    {
        in_session_ = false;
        return false;
    }

    return true;
}

b32 asNetwork::InitializeLobby(i32 max_players, b32 secure)
{
    Displayf("Initializing lobby");

    if (!LoadDirectPlay())
    {
        Errorf("Failed to load DirectPlay");
        return false;
    }

    CoInitialize(NULL);

    if (dp_lobby_ == nullptr)
    {
        if (CoCreateInstance(CLSID_DirectPlayLobby, 0, 1, IID_IDirectPlayLobby3A, (LPVOID*) &dp_lobby_))
        {
            in_lobby_ = false;
            CoUninitialize();
            return false;
        }
    }

    max_players_ = max_players;
    secure_ = secure;

    Debugf("Lobby interface created or already created.");
    return true;
}

b32 asNetwork::JoinLobbySession()
{
    Debugf("asNetwork::JoinLobbySession()");
    in_lobby_ = false;

    if (dp_lobby_ == nullptr)
    {
        Errorf("Couldn't get Lobby interface.");
        return false;
    }

    DWORD conn_size = 0;
    if (HRESULT error = dp_lobby_->GetConnectionSettings(0, NULL, &conn_size); error != DPERR_BUFFERTOOSMALL)
    {
        Debugf("Couldn't get connection settings: %08X", error);
        return false;
    }

    if (dp_connection_)
        arts_free(dp_connection_);
    dp_connection_ = (DPLCONNECTION*) arts_malloc(conn_size);

    if (HRESULT error = dp_lobby_->GetConnectionSettings(0, dp_connection_, &conn_size))
    {
        Debugf("Couldn't get connection settings: %08X", error);
        return false;
    }

    max_players_ = 8;
    secure_ = false;
    dp_connection_->lpSessionDesc->dwFlags = DPSESSION_MIGRATEHOST | DPSESSION_KEEPALIVE;
    dp_connection_->lpSessionDesc->dwMaxPlayers = max_players_;

    if (HRESULT error = dp_lobby_->SetConnectionSettings(0, 0, dp_connection_))
    {
        Errorf("Couldn't set lobby connection: %08X", error);
        return false;
    }

    if (dplay_)
    {
        dplay_->Release();
        dplay_ = nullptr;
    }

    if (HRESULT error = dp_lobby_->ConnectEx(0, IID_IDirectPlay4A, (LPVOID*) &dplay_, NULL))
    {
        Errorf("asNetwork::JoinLobbySession: Couldn't join lobby: %08X", error);
        return false;
    }

    if (dp_connection_->dwFlags & DPLCONNECTION_CREATESESSION)
        is_host_ = true;

    in_lobby_ = true;
    in_session_ = true;
    Debugf("asNetwork::JoinLobbySession successful.");

    return true;
}

void asNetwork::Logout()
{
    if (dp_lobby_)
    {
        dp_lobby_->Release();
        dp_lobby_ = nullptr;
    }

    if (dplay_)
    {
        if (recv_buffer_)
        {
            arts_free(recv_buffer_);
            recv_buffer_ = 0;
        }
        if (dplay_->DestroyPlayer(player_id_) == DP_OK)
            Warningf("DPLAY: DestroyPlayer.");

        if (dplay_->Close() == DP_OK)
            Warningf("DPLAY: Closing session.");

        if (dplay_->Release() == 0)
            Warningf("DPLAY: DirectPlay object pointer released.");

        dplay_ = nullptr;
        CoUninitialize();
    }

    player_id_ = 0;
    in_session_ = false;
    in_lobby_ = false;
    is_host_ = false;
    sys_message_cb_ = nullptr;
    app_message_cb_ = nullptr;
    caps_ = 0;
}

void asNetwork::SetSessionData(NETSESSION_DESC* desc, char* name)
{
    if (!dplay_ || !is_host_)
        return;

    DPSESSIONDESC2 session_desc;
    DPSESSIONDESC2* p_session_desc = &session_desc;
    DWORD session_size = sizeof(session_desc);

    if (HRESULT error = dplay_->GetSessionDesc(p_session_desc, &session_size))
    {
        if (error != DPERR_BUFFERTOOSMALL)
        {
            Errorf("DPLAY: GetSessionDesc %08X", error);
            return;
        }

        p_session_desc = (DPSESSIONDESC2*) arts_malloc(session_size);
        error = dplay_->GetSessionDesc(p_session_desc, &session_size);

        if (error)
        {
            Errorf("DPLAY: GetSessionDesc %08X", error);
            return;
        }
    }

    std::memcpy(&p_session_desc->dwUser1, desc, sizeof(*desc));

    if (name)
        p_session_desc->lpszSessionNameA = name;

    HRESULT error = dplay_->SetSessionDesc(p_session_desc, 0);

    if (p_session_desc != &session_desc)
        arts_free(p_session_desc);

    if (error)
    {
        Errorf("DPLAY: SetSessionDesc %08X", error);
    }
    else
    {
        Debugf("asNetwork::Sealing play session...");
    }
}

void asNetwork::Deallocate()
{
    if (recv_buffer_)
    {
        arts_free(recv_buffer_);
        recv_buffer_ = nullptr;
    }

    if (dp_connection_)
    {
        arts_free(dp_connection_);
        dp_connection_ = nullptr;
    }
}

void asNetwork::DestroyPlayer()
{
    if (dplay_)
    {
        if (dplay_->DestroyPlayer(player_id_) == DP_OK)
            Warningf("DPLAY: DestroyPlayer.");

        player_id_ = 0;
        is_host_ = false;
    }
}

void asNetwork::Disconnect()
{
    if (dplay_)
    {
        if (dp_connection_)
        {
            arts_free(dp_connection_);
            dp_connection_ = nullptr;
        }

        if (!dplay_->Release())
            Warningf("DPLAY: DirectPlay object pointer released.");
    }

    in_session_ = false;
    CreateInterface();
}

run_once([] {
    create_hook(
        "DirectPlayCreate", "Dynamically load DPLAYX", 0x5A429A + 2, &arts_DirectPlayCreate, hook_type::pointer);
});