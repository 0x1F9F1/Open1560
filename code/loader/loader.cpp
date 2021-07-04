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

#include "core/hooking.h"
#include "core/minwin.h"

#include "data7/printer.h"

#include "memory/allocator.h"
#include "memory/valloc.h"

#include "midtown.h"

#include "symbols.h"

#include <dinput.h>

#include <mem/module.h>
#include <mem/pattern.h>

#pragma comment(linker, "/EXPORT:DirectInputCreateA=_DirectInputCreateA_Impl@16")

extern "C" HRESULT WINAPI DirectInputCreateA_Impl(
    HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTA* ppDI, LPUNKNOWN punkOuter)
{
    static decltype(&DirectInputCreateA_Impl) DirectInputCreateA_Orig = nullptr;

    if (DirectInputCreateA_Orig == nullptr)
    {
        wchar_t dinput_path[MAX_PATH];
        GetSystemDirectoryW(dinput_path, ARTS_SIZE32(dinput_path));
        wcscat_s(dinput_path, L"\\dinput.dll");

        if (HMODULE dinput_dll = LoadLibraryW(dinput_path))
        {
            Displayf("Loaded real dinput.dll at 0x%zX", reinterpret_cast<std::uintptr_t>(dinput_dll));

            DirectInputCreateA_Orig =
                reinterpret_cast<decltype(DirectInputCreateA_Orig)>(GetProcAddress(dinput_dll, "DirectInputCreateA"));

            if (DirectInputCreateA_Orig)
            {
                Displayf(
                    "Found DirectInputCreateA at 0x%zX", reinterpret_cast<std::uintptr_t>(DirectInputCreateA_Orig));
            }
            else
            {
                Abortf("Failed to find DirectInputCreateA");
            }
        }
        else
        {
            Abortf("Failed to load dinput.dll\n"
                   "If you are using Wine, ensure you are using \"dinput=n,b\"");
        }
    }

    return DirectInputCreateA_Orig(hinst, dwVersion, ppDI, punkOuter);
}

static std::size_t InitExportHooks(HMODULE instance)
{
    std::unordered_map<std::string_view, std::string_view> remaps;

    for (const char* const* lines = NewSymbols; *lines; ++lines)
    {
        std::string_view line = *lines;

        usize split = line.find('=');

        if (split == SIZE_MAX)
        {
            Quitf("Invalid Symbol Mapping: '%.*s'", line.size(), line.data());

            continue;
        }

        std::string_view symbol = line.substr(0, split);
        std::string_view value = line.substr(split + 1);

        remaps.emplace(symbol, value);
    }

    Displayf("Processing exports");

    LogHooks = false;

    std::vector<std::pair<const SymbolInfo*, mem::pointer>> symbols;

    mem::module::nt(instance).enum_exports(
        [&remaps, &symbols](const char* namez, std::uint32_t /*ordinal*/, mem::pointer address) {
            std::string_view name = namez ? namez : "";

            if (auto find = remaps.find(name); find != remaps.end())
                name = find->second;

            if (!name.empty())
            {
                auto symbol = LookupBaseSymbol(name);

                if (symbol == nullptr)
                {
                    char replaced[256];
                    arts_strncpy(replaced, name.data(), name.size());

                    char* here = replaced;

                    if (*here == '?')
                    {
                        // Skip qualified name
                        while (*here != '@' && *here != '\0')
                            here += std::strcspn(here, "@") + 1;

                        // Hacky replacement of mangled const char* -> char*
                        while (char* s = std::strstr(here, "PBD"))
                            std::memcpy(s, "PAD", 3);

                        // Hacky replacement of mangled const void* -> void*
                        while (char* s = std::strstr(here, "PBX"))
                            std::memcpy(s, "PAX", 3);

                        // Hacky replacement of mangled T* __restrict -> T*
                        while (char* s = std::strstr(here, "PI"))
                            std::memmove(s + 1, s + 2, std::strlen(s + 1));
                    }

                    symbol = LookupBaseSymbol(replaced);
                }

                if (symbol == nullptr)
                {
                    Quitf("Unrecogized Symbol '%.*s'", name.size(), name.data());
                }

                symbols.emplace_back(symbol, address);
            }

            return false;
        });

    // Hook functions after data variables, to avoid clobbering a jump hook
    std::sort(symbols.begin(), symbols.end(),
        [](const auto& lhs, const auto& rhs) { return lhs.first->IsFunction() < rhs.first->IsFunction(); });

    for (const auto& [symbol, address] : symbols)
        symbol->Hook(address);

    LogHooks = true;

    return symbols.size();
}

#ifndef CI_BUILD_STRING
#    define CI_BUILD_STRING "Dev"
#endif

BOOL APIENTRY DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID /*lpvReserved*/)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        if (mem::pointer ver_string = mem::scan(mem::pattern("Angel: ", nullptr), mem::module::main());
            ver_string != 0x6346BC)
        {
            MessageBoxA(NULL,
                arts_formatf<256>("Invalid Game Version '%s'\n"
                                  "Use the Open1560.exe provided in the download",
                    ver_string ? ver_string.as<const char*>() : "<INVALID>"),
                "Invalid Version", MB_OK | MB_ICONERROR | MB_SETFOREGROUND | MB_TOPMOST);

            std::exit(1);
        }

        if (auto _SetProcessDEPPolicy = reinterpret_cast<BOOL(WINAPI*)(DWORD)>(
                GetProcAddress(GetModuleHandleA("KERNEL32.DLL"), "SetProcessDEPPolicy")))
        {
            _SetProcessDEPPolicy(0x00000001 /*PROCESS_DEP_ENABLE*/);
        };

        // Fixes mouse drift when display scale is not 100%
        if (auto _SetProcessDPIAware =
                reinterpret_cast<BOOL(WINAPI*)()>(GetProcAddress(GetModuleHandleA("USER32.DLL"), "SetProcessDPIAware")))
        {
            _SetProcessDPIAware();
        };

#ifdef ARTS_FINAL
        if (IsDebuggerPresent())
#endif
        {
            LogToConsole();
        }

        InitBaseSymbols();

        LogToFile("Open1560.log");

        VERSION_STRING = const_cast<char*>("Open1560: " CI_BUILD_STRING " / " __DATE__ " " __TIME__);

        Displayf("Build: %s", VERSION_STRING);
        Displayf("Download updates at https://0x1f9f1.github.io/Open1560");

        // Run export hooks first to avoid corrupting any patches
        Displayf("Processed %zu Export Hooks", InitExportHooks(hinstDLL));

        // Run init functions which need to be happen before WinMain
        Displayf("Processed %zu Early Init Functions", mem::init_function::init(INIT_early));
    }

    return TRUE;
}

include_dummy_symbol(midtown);

include_dummy_symbol(agi_bitmap);
include_dummy_symbol(agi_cmodel);
include_dummy_symbol(agi_cmodel8);
include_dummy_symbol(agi_cmodelx);
// include_dummy_symbol(agi_dlp);
include_dummy_symbol(agi_dlptmpl);
// include_dummy_symbol(agi_dyndlp);
include_dummy_symbol(agi_error);
include_dummy_symbol(agi_getdlp);
include_dummy_symbol(agi_light);
// include_dummy_symbol(agi_lmodel);
include_dummy_symbol(agi_mtldef);
include_dummy_symbol(agi_mtllib);
include_dummy_symbol(agi_palette);
include_dummy_symbol(agi_physdef);
include_dummy_symbol(agi_physlib);
include_dummy_symbol(agi_pipeline);
include_dummy_symbol(agi_print);
include_dummy_symbol(agi_refresh);
include_dummy_symbol(agi_render);
include_dummy_symbol(agi_rsys);
// include_dummy_symbol(agi_smap);
include_dummy_symbol(agi_surface);
include_dummy_symbol(agi_texdef);
include_dummy_symbol(agi_texlib);
include_dummy_symbol(agi_viewport);

include_dummy_symbol(agid3d_d3dlight);
// include_dummy_symbol(agid3d_d3dmtldef);
include_dummy_symbol(agid3d_d3dpipe);
include_dummy_symbol(agid3d_d3drpipe);
include_dummy_symbol(agid3d_d3drsys);
include_dummy_symbol(agid3d_d3dtexdef);
include_dummy_symbol(agid3d_d3dview);
include_dummy_symbol(agid3d_ddbitmap);
// include_dummy_symbol(agid3d_dderror);
include_dummy_symbol(agid3d_ddpipe);
include_dummy_symbol(agid3d_pcpipe);

// include_dummy_symbol(agirend_bilight);
// include_dummy_symbol(agirend_bilmodel);
// include_dummy_symbol(agirend_lighter);
// include_dummy_symbol(agirend_projvtx);
// include_dummy_symbol(agirend_rdlp);
include_dummy_symbol(agirend_surfrender);
// include_dummy_symbol(agirend_zbrender);

include_dummy_symbol(agisw_swddraw);
// include_dummy_symbol(agisw_swemitrunall);
include_dummy_symbol(agisw_swpipe);
include_dummy_symbol(agisw_swrend);
// include_dummy_symbol(agisw_swrsys);
// include_dummy_symbol(agisw_swtexdef);

// include_dummy_symbol(agiworld_bone);
include_dummy_symbol(agiworld_getmesh);
// include_dummy_symbol(agiworld_getmodel);
include_dummy_symbol(agiworld_meshlight);
include_dummy_symbol(agiworld_meshload);
// include_dummy_symbol(agiworld_meshmodel);
include_dummy_symbol(agiworld_meshrend);
include_dummy_symbol(agiworld_meshsave);
include_dummy_symbol(agiworld_meshset);

#ifdef ARTS_ENABLE_KNI
include_dummy_symbol(agiworld_mrkni);
#endif

include_dummy_symbol(agiworld_packnorm);
include_dummy_symbol(agiworld_quality);
// include_dummy_symbol(agiworld_skeleton);
include_dummy_symbol(agiworld_texsheet);
include_dummy_symbol(agiworld_texsort);

include_dummy_symbol(arts7_bank);
include_dummy_symbol(arts7_benchstats);
include_dummy_symbol(arts7_camera);
include_dummy_symbol(arts7_cullable);
include_dummy_symbol(arts7_cullmgr);
// include_dummy_symbol(arts7_dof);
// include_dummy_symbol(arts7_form);
// include_dummy_symbol(arts7_lamp);
include_dummy_symbol(arts7_linear);
include_dummy_symbol(arts7_midgets);
include_dummy_symbol(arts7_node);
include_dummy_symbol(arts7_pgraph);
include_dummy_symbol(arts7_sim);
// include_dummy_symbol(arts7_view);

include_dummy_symbol(data7_args);
include_dummy_symbol(data7_b2f);
include_dummy_symbol(data7_base);
include_dummy_symbol(data7_cache);
include_dummy_symbol(data7_callback);
include_dummy_symbol(data7_global);
include_dummy_symbol(data7_hash);
include_dummy_symbol(data7_ipc);
include_dummy_symbol(data7_list);
include_dummy_symbol(data7_machname);
include_dummy_symbol(data7_memstat);
include_dummy_symbol(data7_metaclass);
include_dummy_symbol(data7_metatype);
include_dummy_symbol(data7_miniparser);
include_dummy_symbol(data7_mmx);
include_dummy_symbol(data7_pager);
// include_dummy_symbol(data7_perfstat);
include_dummy_symbol(data7_printer);
include_dummy_symbol(data7_quitf);
include_dummy_symbol(data7_speed);
include_dummy_symbol(data7_str);
include_dummy_symbol(data7_timer);
// include_dummy_symbol(data7_utimer);

// include_dummy_symbol(dyna7_dyna);
// include_dummy_symbol(dyna7_gfx);

include_dummy_symbol(eventq7_dispatchable);
include_dummy_symbol(eventq7_event);
include_dummy_symbol(eventq7_eventq);
include_dummy_symbol(eventq7_geinputLib);
include_dummy_symbol(eventq7_replay);
include_dummy_symbol(eventq7_winevent);

include_dummy_symbol(localize_localize);

include_dummy_symbol(memory_allocator);
include_dummy_symbol(memory_stack);
include_dummy_symbol(memory_stub);
include_dummy_symbol(memory_valloc);

// include_dummy_symbol(mmai_addoncaraudio);
// include_dummy_symbol(mmai_aiData);
// include_dummy_symbol(mmai_aiGoal);
// include_dummy_symbol(mmai_aiGoalAvoidPlayer);
// include_dummy_symbol(mmai_aiGoalBackup);
// include_dummy_symbol(mmai_aiGoalChase);
// include_dummy_symbol(mmai_aiGoalCollision);
// include_dummy_symbol(mmai_aiGoalFollowWayPts);
// include_dummy_symbol(mmai_aiGoalRandomDrive);
// include_dummy_symbol(mmai_aiGoalRegainRail);
// include_dummy_symbol(mmai_aiGoalStop);
// include_dummy_symbol(mmai_aiIntersection);
// include_dummy_symbol(mmai_aiMap);
// include_dummy_symbol(mmai_aiPath);
// include_dummy_symbol(mmai_aiPedestrian);
include_dummy_symbol(mmai_aiPoliceForce);
// include_dummy_symbol(mmai_aiRailSet);
// include_dummy_symbol(mmai_aiStuck);
// include_dummy_symbol(mmai_aiTrafficLight);
// include_dummy_symbol(mmai_aiVehicle);
// include_dummy_symbol(mmai_aiVehicleAmbient);
// include_dummy_symbol(mmai_aiVehicleMGR);
// include_dummy_symbol(mmai_aiVehicleOpponent);
// include_dummy_symbol(mmai_aiVehiclePolice);
// include_dummy_symbol(mmai_aiVehicleSpline);
// include_dummy_symbol(mmai_aiaudiomanager);
// include_dummy_symbol(mmai_aipedaudiomanager);
// include_dummy_symbol(mmai_arraylist);

// include_dummy_symbol(mmanim_AnimDOF);
// include_dummy_symbol(mmanim_AnimMgr);
// include_dummy_symbol(mmanim_AnimSpline);
// include_dummy_symbol(mmanim_AnimTrigger);
// include_dummy_symbol(mmanim_Excel);
// include_dummy_symbol(mmanim_boat);
// include_dummy_symbol(mmanim_bridge);
// include_dummy_symbol(mmanim_mmbridgeaudmgr);
// include_dummy_symbol(mmanim_plane);
// include_dummy_symbol(mmanim_train);
// include_dummy_symbol(mmanim_traincar);

// include_dummy_symbol(mmaudio_audstream);
include_dummy_symbol(mmaudio_cd);
// include_dummy_symbol(mmaudio_crevbuf);
// include_dummy_symbol(mmaudio_creverb);
include_dummy_symbol(mmaudio_dsglobal);
// include_dummy_symbol(mmaudio_dupbufcreator);
// include_dummy_symbol(mmaudio_eaxguid);
// include_dummy_symbol(mmaudio_head);
// include_dummy_symbol(mmaudio_manager);
include_dummy_symbol(mmaudio_mixer);
// include_dummy_symbol(mmaudio_mmvoicecommentary);
// include_dummy_symbol(mmaudio_sound);
// include_dummy_symbol(mmaudio_soundobj);
// include_dummy_symbol(mmaudio_streamobj);

// include_dummy_symbol(mmbangers_active);
// include_dummy_symbol(mmbangers_banger);
// include_dummy_symbol(mmbangers_data);
// include_dummy_symbol(mmbangers_dof);

// include_dummy_symbol(mmcamcs_aicamcs);
// include_dummy_symbol(mmcamcs_appcamcs);
// include_dummy_symbol(mmcamcs_basecamcs);
// include_dummy_symbol(mmcamcs_carcamcs);
// include_dummy_symbol(mmcamcs_pointcamcs);
// include_dummy_symbol(mmcamcs_polarcamcs);
// include_dummy_symbol(mmcamcs_postcamcs);
// include_dummy_symbol(mmcamcs_povcamcs);
// include_dummy_symbol(mmcamcs_precamcs);
// include_dummy_symbol(mmcamcs_spline);
// include_dummy_symbol(mmcamcs_trackcamcs);
// include_dummy_symbol(mmcamcs_transitioncs);
// include_dummy_symbol(mmcamcs_viewcs);

// include_dummy_symbol(mmcamtour_gamerecord);

// include_dummy_symbol(mmcar_axle);
// include_dummy_symbol(mmcar_car);
// include_dummy_symbol(mmcar_carmodel);
// include_dummy_symbol(mmcar_carsim);
// include_dummy_symbol(mmcar_carsimcheap);
// include_dummy_symbol(mmcar_drivetrain);
// include_dummy_symbol(mmcar_engine);
// include_dummy_symbol(mmcar_engineaudio);
// include_dummy_symbol(mmcar_engineaudioopponent);
// include_dummy_symbol(mmcar_force);
// include_dummy_symbol(mmcar_gyro);
// include_dummy_symbol(mmcar_impactaudio);
// include_dummy_symbol(mmcar_netaddoncaraudio);
// include_dummy_symbol(mmcar_netaudiomanager);
// include_dummy_symbol(mmcar_networkcaraudio);
// include_dummy_symbol(mmcar_opponentcaraudio);
// include_dummy_symbol(mmcar_opponentimpactaudio);
// include_dummy_symbol(mmcar_opponentsurfaceaudio);
// include_dummy_symbol(mmcar_playercaraudio);
// include_dummy_symbol(mmcar_policecaraudio);
// include_dummy_symbol(mmcar_roadff);
include_dummy_symbol(mmcar_shard);
// include_dummy_symbol(mmcar_shock);
// include_dummy_symbol(mmcar_skid);
// include_dummy_symbol(mmcar_splash);
// include_dummy_symbol(mmcar_stuck);
// include_dummy_symbol(mmcar_surfaceaudio);
// include_dummy_symbol(mmcar_surfaceaudioinfo);
// include_dummy_symbol(mmcar_trailer);
// include_dummy_symbol(mmcar_transmission);
include_dummy_symbol(mmcar_wheel);

// include_dummy_symbol(mmcity_anim);
include_dummy_symbol(mmcity_cellrend);
include_dummy_symbol(mmcity_cullcity);
include_dummy_symbol(mmcity_heap);
include_dummy_symbol(mmcity_inst);
// include_dummy_symbol(mmcity_instchn);
include_dummy_symbol(mmcity_loader);
// include_dummy_symbol(mmcity_ped);
// include_dummy_symbol(mmcity_portal);
// include_dummy_symbol(mmcity_position);
// include_dummy_symbol(mmcity_positions);
// include_dummy_symbol(mmcity_renderweb);
// include_dummy_symbol(mmcity_sky);

include_dummy_symbol(mmcityinfo_cityinfo);
include_dummy_symbol(mmcityinfo_citylist);
// include_dummy_symbol(mmcityinfo_crc);
// include_dummy_symbol(mmcityinfo_infobase);
// include_dummy_symbol(mmcityinfo_mapdata);
// include_dummy_symbol(mmcityinfo_miscdata);
// include_dummy_symbol(mmcityinfo_playercfg);
// include_dummy_symbol(mmcityinfo_playerdata);
// include_dummy_symbol(mmcityinfo_playerdir);
// include_dummy_symbol(mmcityinfo_racedata);
// include_dummy_symbol(mmcityinfo_racerecord);
// include_dummy_symbol(mmcityinfo_roadsect);
include_dummy_symbol(mmcityinfo_state);
include_dummy_symbol(mmcityinfo_vehinfo);
include_dummy_symbol(mmcityinfo_vehlist);

// include_dummy_symbol(mmdjpeg_jcomapi);
// include_dummy_symbol(mmdjpeg_jdapimin);
// include_dummy_symbol(mmdjpeg_jdapistd);
// include_dummy_symbol(mmdjpeg_jdatasrc);
// include_dummy_symbol(mmdjpeg_jdcoefct);
// include_dummy_symbol(mmdjpeg_jdcolor);
// include_dummy_symbol(mmdjpeg_jddctmgr);
// include_dummy_symbol(mmdjpeg_jdhuff);
// include_dummy_symbol(mmdjpeg_jdinput);
// include_dummy_symbol(mmdjpeg_jdmainct);
// include_dummy_symbol(mmdjpeg_jdmarker);
// include_dummy_symbol(mmdjpeg_jdmaster);
// include_dummy_symbol(mmdjpeg_jdpostct);
// include_dummy_symbol(mmdjpeg_jdsample);
// include_dummy_symbol(mmdjpeg_jerror);
// include_dummy_symbol(mmdjpeg_jidctflt);
// include_dummy_symbol(mmdjpeg_jidctfst);
// include_dummy_symbol(mmdjpeg_jidctint);
// include_dummy_symbol(mmdjpeg_jmemmgr);
// include_dummy_symbol(mmdjpeg_jmemnobs);
// include_dummy_symbol(mmdjpeg_jutils);

// include_dummy_symbol(mmdyna_bndtmpl);
// include_dummy_symbol(mmdyna_bndtmpl2);
// include_dummy_symbol(mmdyna_isect);
// include_dummy_symbol(mmdyna_poly);

// include_dummy_symbol(mmeffects_birth);
// include_dummy_symbol(mmeffects_card2d);
include_dummy_symbol(mmeffects_damage);
include_dummy_symbol(mmeffects_linespark);
// include_dummy_symbol(mmeffects_meshform);
include_dummy_symbol(mmeffects_mmnumber);
include_dummy_symbol(mmeffects_mmtext);
// include_dummy_symbol(mmeffects_mousesteerbar);
include_dummy_symbol(mmeffects_ptx);
include_dummy_symbol(mmeffects_vehform);

// include_dummy_symbol(mmgame_cd);
// include_dummy_symbol(mmgame_dash);
include_dummy_symbol(mmgame_game);
// include_dummy_symbol(mmgame_gameedit);
include_dummy_symbol(mmgame_gameman);
include_dummy_symbol(mmgame_gamemulti);
// include_dummy_symbol(mmgame_gamesingle);
// include_dummy_symbol(mmgame_gauge);
// include_dummy_symbol(mmgame_hud);
include_dummy_symbol(mmgame_hudmap);
// include_dummy_symbol(mmgame_icons);
include_dummy_symbol(mmgame_interface);
// include_dummy_symbol(mmgame_mmambientaudio);
// include_dummy_symbol(mmgame_multiblitz);
// include_dummy_symbol(mmgame_multicircuit);
// include_dummy_symbol(mmgame_multicr);
// include_dummy_symbol(mmgame_multirace);
// include_dummy_symbol(mmgame_netobject);
// include_dummy_symbol(mmgame_player);
// include_dummy_symbol(mmgame_popup);
// include_dummy_symbol(mmgame_rainaudio);
// include_dummy_symbol(mmgame_singleblitz);
// include_dummy_symbol(mmgame_singlecircuit);
// include_dummy_symbol(mmgame_waypoints);
// include_dummy_symbol(mmgame_wphud);
// include_dummy_symbol(mmgame_wpinst);
// include_dummy_symbol(mmgame_wpobject);

// include_dummy_symbol(mminput_collide);
// include_dummy_symbol(mminput_effect);
// include_dummy_symbol(mminput_friction);
include_dummy_symbol(mminput_input);
// include_dummy_symbol(mminput_io);
include_dummy_symbol(mminput_iodev);
// include_dummy_symbol(mminput_joyman);
include_dummy_symbol(mminput_joystick);
include_dummy_symbol(mminput_localize);
// include_dummy_symbol(mminput_road);
// include_dummy_symbol(mminput_spring);

// include_dummy_symbol(mmnetwork_netobject);
include_dummy_symbol(mmnetwork_network);

// include_dummy_symbol(mmphysics_aero);
// include_dummy_symbol(mmphysics_bound);
// include_dummy_symbol(mmphysics_entity);
// include_dummy_symbol(mmphysics_inertia);
// include_dummy_symbol(mmphysics_joint3dof);
// include_dummy_symbol(mmphysics_osample);
// include_dummy_symbol(mmphysics_phys);

include_dummy_symbol(mmui_about);
// include_dummy_symbol(mmui_audio);
// include_dummy_symbol(mmui_control);
// include_dummy_symbol(mmui_controlbase);
// include_dummy_symbol(mmui_cr_settings);
// include_dummy_symbol(mmui_dlg_city);
// include_dummy_symbol(mmui_dlg_ctrl);
// include_dummy_symbol(mmui_dlg_drec);
// include_dummy_symbol(mmui_dlg_hoff);
// include_dummy_symbol(mmui_dlg_msg);
// include_dummy_symbol(mmui_dlg_newp);
// include_dummy_symbol(mmui_dlg_password);
// include_dummy_symbol(mmui_dlg_renv);
// include_dummy_symbol(mmui_dlg_serial);
// include_dummy_symbol(mmui_dlg_tcpip);
// include_dummy_symbol(mmui_driver);
include_dummy_symbol(mmui_graphics);
// include_dummy_symbol(mmui_main);
// include_dummy_symbol(mmui_netarena);
// include_dummy_symbol(mmui_netselect);
// include_dummy_symbol(mmui_options);
// include_dummy_symbol(mmui_optionsbase);
// include_dummy_symbol(mmui_pu_audio);
// include_dummy_symbol(mmui_pu_chat);
// include_dummy_symbol(mmui_pu_control);
// include_dummy_symbol(mmui_pu_debug);
// include_dummy_symbol(mmui_pu_exit);
// include_dummy_symbol(mmui_pu_graphics);
include_dummy_symbol(mmui_pu_key);
// include_dummy_symbol(mmui_pu_main);
include_dummy_symbol(mmui_pu_menu);
// include_dummy_symbol(mmui_pu_options);
// include_dummy_symbol(mmui_pu_quit);
// include_dummy_symbol(mmui_pu_results);
// include_dummy_symbol(mmui_pu_roster);
// include_dummy_symbol(mmui_race);
// include_dummy_symbol(mmui_racebase);
// include_dummy_symbol(mmui_racehost);
// include_dummy_symbol(mmui_vehicle);
// include_dummy_symbol(mmui_vselect);
// include_dummy_symbol(mmui_vshow);

// include_dummy_symbol(mmwidget_bm_button);
// include_dummy_symbol(mmwidget_bm_label);
// include_dummy_symbol(mmwidget_button);
// include_dummy_symbol(mmwidget_compbase);
// include_dummy_symbol(mmwidget_compcr);
// include_dummy_symbol(mmwidget_compdrec);
// include_dummy_symbol(mmwidget_comproster);
// include_dummy_symbol(mmwidget_comprrec);
// include_dummy_symbol(mmwidget_compscroll);
// include_dummy_symbol(mmwidget_controlwidget);
include_dummy_symbol(mmwidget_cwarray);
include_dummy_symbol(mmwidget_dropdown);
// include_dummy_symbol(mmwidget_icon);
// include_dummy_symbol(mmwidget_iconwidget);
// include_dummy_symbol(mmwidget_label);
include_dummy_symbol(mmwidget_manager);
include_dummy_symbol(mmwidget_menu);
// include_dummy_symbol(mmwidget_mexbutton);
include_dummy_symbol(mmwidget_mstore);
// include_dummy_symbol(mmwidget_navbar);
// include_dummy_symbol(mmwidget_pointer);
// include_dummy_symbol(mmwidget_slider);
// include_dummy_symbol(mmwidget_sliderbar);
// include_dummy_symbol(mmwidget_tdwidget);
// include_dummy_symbol(mmwidget_textdrop);
// include_dummy_symbol(mmwidget_textfield);
// include_dummy_symbol(mmwidget_textroller);
// include_dummy_symbol(mmwidget_textroller2);
// include_dummy_symbol(mmwidget_toggle);
// include_dummy_symbol(mmwidget_toggle2);
// include_dummy_symbol(mmwidget_togglebutton);
// include_dummy_symbol(mmwidget_togglebutton2);
// include_dummy_symbol(mmwidget_tscroll);
// include_dummy_symbol(mmwidget_ttip);
// include_dummy_symbol(mmwidget_vscrollbar);
// include_dummy_symbol(mmwidget_vswidget);
// include_dummy_symbol(mmwidget_widget);
include_dummy_symbol(mmwidget_wstore);

include_dummy_symbol(pcwindis_dxinit);
include_dummy_symbol(pcwindis_dxmovie);
include_dummy_symbol(pcwindis_dxsetup);
include_dummy_symbol(pcwindis_pcwindis);
include_dummy_symbol(pcwindis_setupdata);

include_dummy_symbol(stream_filestream);
include_dummy_symbol(stream_fsystem);
include_dummy_symbol(stream_hfsystem);
include_dummy_symbol(stream_problems);
include_dummy_symbol(stream_sparser);
include_dummy_symbol(stream_stream);
include_dummy_symbol(stream_token);
include_dummy_symbol(stream_vfsystem);
include_dummy_symbol(stream_vstream);

// include_dummy_symbol(vector7_algmath);
// include_dummy_symbol(vector7_const);
// include_dummy_symbol(vector7_geomath);
include_dummy_symbol(vector7_matrix34);
// include_dummy_symbol(vector7_matrix44);
// include_dummy_symbol(vector7_quat);
// include_dummy_symbol(vector7_randmath);
// include_dummy_symbol(vector7_random);
// include_dummy_symbol(vector7_trigmath);
include_dummy_symbol(vector7_vector2);
include_dummy_symbol(vector7_vector3);
include_dummy_symbol(vector7_vector4);
