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

// #include "midtown.h"

#include "loader.h"

#include <charconv>

#include <DbgHelp.h>
#include <dinput.h>

#include <mem/module.h>

static decltype(&DirectInputCreateA) DirectInputCreateA_Orig = nullptr;

#pragma comment(linker, "/EXPORT:DirectInputCreateA=_DirectInputCreateA_Impl@16")

extern "C" HRESULT WINAPI DirectInputCreateA_Impl(
    HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTA* ppDI, LPUNKNOWN punkOuter)
{
    if (DirectInputCreateA_Orig == nullptr)
    {
        wchar_t system_directory[MAX_PATH];
        GetSystemDirectoryW(system_directory, std::size(system_directory));
        wcscat_s(system_directory, L"\\dinput.dll");

        if (HMODULE dinput_dll = LoadLibraryW(system_directory))
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
                MessageBoxA(NULL, "Fatal Error", "Failed to find DirectInputCreateA", MB_OK);
                exit(1);
            }
        }
        else
        {
            MessageBoxA(NULL, "Fatal Error", "Failed to load dinput.dll", MB_OK);
            exit(1);
        }
    }

    return DirectInputCreateA_Orig(hinst, dwVersion, ppDI, punkOuter);
}

static std::size_t InitExportHooks(HMODULE instance)
{
    // TODO: Validate symbol is a function (in an executable section)

    std::vector<HGLOBAL> resources;
    std::unordered_map<std::string_view, std::uintptr_t> symbols;

    for (int idr : {IDR_RESOURCES_BASE_SYMBOLS, IDR_RESOURCES_NEW_SYMBOLS})
    {
        HRSRC hResInfo = FindResource(instance, MAKEINTRESOURCE(idr), TEXT("TXT"));
        HGLOBAL hResData = LoadResource(instance, hResInfo);

        resources.emplace_back(hResData);

        DWORD nResSize = SizeofResource(instance, hResInfo);
        LPVOID lpResLock = LockResource(hResData);

        std::string_view symbols_txt(static_cast<const char*>(lpResLock), nResSize);

        for (usize idx = 0; idx < symbols_txt.size();)
        {
            usize line_end = symbols_txt.find_first_of("\r\n", idx);

            if (line_end == SIZE_MAX)
                line_end = symbols_txt.size();

            std::string_view line = symbols_txt.substr(idx, line_end - idx);
            idx = symbols_txt.find_first_not_of("\r\n", line_end);

            usize split = line.find('=');

            if (split == SIZE_MAX)
            {
                Errorf("Invalid Symbol Mapping: '%.*s'", line.size(), line.data());

                continue;
            }

            std::string_view symbol = line.substr(0, split);
            std::string_view value = line.substr(split + 1);

            std::uintptr_t address = 0;

            if (value.compare(0, 2, "0x") == 0)
            {
                value = value.substr(2);

                if (std::from_chars(value.data(), value.data() + value.size(), address, 16).ec != std::errc())
                {
                    Errorf("Invalid Symbol Address: '%.*s' = '%.*s'", symbol.size(), symbol.data(), value.size(),
                        value.data());

                    continue;
                }
            }
            else
            {
                auto find = symbols.find(value);

                if (find == symbols.end())
                {
                    Errorf("Invalid Symbol Alias: '%.*s' -> '%.*s'", symbol.size(), symbol.data(), value.size(),
                        value.data());

                    continue;
                }

                address = find->second;
            }

            if (!symbols.try_emplace(symbol, address).second)
            {
                Errorf("Duplicate Symbol: '%.*s'", symbol.size(), symbol.data());
            }
        }
    }

    std::size_t total = 0;

    LogHooks = false;

    mem::module::nt(instance).enum_exports(
        [&total, &symbols](const char* name, std::uint32_t /*ordinal*/, mem::pointer address) {
            if (name != nullptr)
            {
                std::uint32_t target = 0;
                char hook_name[256];

                if (arts_sscanf(name, "%[^:]:Hook_%x", hook_name, 256, &target) == 2)
                {
                    hook_name[255] = '\0';
                }
                else if (auto find = symbols.find(name); find != symbols.end())
                {
                    arts_strcpy(hook_name, name);
                    target = find->second;
                }
                else
                {
                    char replaced[256];
                    arts_strcpy(replaced, name);

                    // Hacky replacement of mangled const char* -> char*
                    while (char* s = std::strstr(replaced, "PBD"))
                        std::memcpy(s, "PAD", 3);

                    // Hacky replacement of mangled const void* -> void*
                    while (char* s = std::strstr(replaced, "PBX"))
                        std::memcpy(s, "PAX", 3);

                    if (find = symbols.find(replaced); find != symbols.end())
                    {
                        arts_strcpy(hook_name, replaced);
                        target = find->second;
                    }
                    else
                    {
                        Errorf("Unrecogized Symbol '%s'", name);
                    }
                }

                if (target != 0)
                {
                    char undName[256];

                    const char* function_name =
                        UnDecorateSymbolName(hook_name, undName, std::size(undName), UNDNAME_NAME_ONLY) ? undName
                                                                                                        : hook_name;

                    create_hook(function_name, "", target, address);

                    ++total;
                }
            }

            return false;
        });

    LogHooks = true;

    for (HGLOBAL hResData : resources)
    {
        FreeResource(hResData);
    }

    return total;
}

BOOL APIENTRY DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID /*lpvReserved*/)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        if (std::strcmp(mem::pointer(0x6346BC).as<const char*>(), "Angel: 1560 / Apr  2 1999 19:10:27") != 0)
        {
            MessageBoxA(NULL, "Invalid MM1 Version Detected", "Fatal Error",
                MB_OK | MB_ICONERROR | MB_SETFOREGROUND | MB_TOPMOST);

            std::exit(1);
        }

        SetProcessDEPPolicy(PROCESS_DEP_ENABLE);

        if (GetConsoleWindow() == NULL)
        {
            AllocConsole();
            SetConsoleTitleA("Open1560");

            std::FILE* f = nullptr;
            freopen_s(&f, "CONOUT$", "w", stdout);
            freopen_s(&f, "CONOUT$", "w", stderr);
        }

        // Must run first
        create_hook("DefaultPrinter", "Use a custom printer", 0x5769C0, &DefaultPrinter);

        patch_jmp("LogToFile Patch", "Disables second LogToFile call", 0x401B68, jump_type::always);

        LogToFile("Open1560.log");

#if defined(CI_BUILD_STRING)
        Displayf("Build: %s", CI_BUILD_STRING " / " __DATE__ " " __TIME__);
#endif

        patch_jmp("HW Menu", "Enable HW Menu Rendering", 0x401DB4, jump_type::always);

        create_patch("Heap Size", "Increase Heap Size", 0x401E11, "\xb8\x00\x00\x00\x08", 5); // mov eax, 0x8000000

        patch_jmp("mmLoader::Update", "Enable Task String", 0x48BA2D, jump_type::never);
        patch_jmp("mmLoader::Update", "Enable Task String", 0x48BA4B, jump_type::never);

        create_patch("mmLoader::Init", "Enable Text Transparency", 0x48B766 + 1, "\x01", 1);

        for (mem::pointer address : {0x4EE463, 0x4EE697, 0x4EE9A3})
        {
            // The code writes to the first 2 channels, even when there are less.
            // operator new(4 * pmxl.cChannels) -> operator new(4 * (pmxl.cChannels + 2))
            create_patch("MixerCT", "Fix paDetails allocation", address + 3, "\x08", 1);
        }

        patch_jmp("agiDDPipeline::CopyBitmap", "Disable Manual Blit", 0x5330AE, jump_type::always);

        patch_jmp("mmCullCity::InitTimeOfDayAndWeather", "Additive Blending Check", 0x48DDD2, jump_type::always);
        patch_jmp("AutoDetect", "Additive Blending Check", 0x49994B, jump_type::always);
        patch_jmp("SetTexQualString", "Additive Blending Check", 0x49A29F, jump_type::never);

        // Checked in GetPackedTexture, only necessary if agiRQ.TextureQuality <= 2
        // create_patch("aiVehicleOpponent::Init", "agiRQ.TextureQuality", 0x44DC2A, "\xEB\x06", 2);

        create_patch("agiD3DTexDef::BeginGfx", "Clear DDSD_PITCH", 0x531B33, "\x24\xD7", 2);

        create_patch("CACHE", "Capacity", 0x4029DA + 1, "\x00\x10\x00\x00", 4);
        create_patch("CACHE", "HeapSize", 0x4029DF + 1, "\x00\x00\x40\x00", 4);

        create_patch("TEXCACHE", "Capacity", 0x4029F3 + 1, "\x00\x02\x00\x00", 4);
        create_patch("TEXCACHE", "HeapSize", 0x4029F8 + 1, "\x00\x00\x00\x02", 4);

        if (false) // Hack, replaces 16-bit handler with 32-bit handler
        {
            create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D419, "\x83\x79\x04\x04", 4);
            create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D439, "\x8D\x04\xBA", 3);
            create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D47E, "\x8B\x00\x89\x04\x93\x90\x90", 7);
        }

        // Allocates 2 extra agiTexDef slots instead of 1, in case TextureCount == 0 (Assumes new memory is zeroed out)
        // Won't avoid some crashes, but should help avoid any out of bounds reads or writes
        // This also needs to be patched in agiMeshSet::DoPageIn
        create_patch("agiMeshSet::BinaryLoad", "Avoid empty texdefs", 0x502D43, "\x8D\x14\x8D\x08\x00\x00\x00", 7);

        // Hack, avoids attempting to access freed memory (https://github.com/0x1F9F1/Open1560/issues/15)
        // Luckily the aiVehicleSpline destructor doesn't do actually do anything anyway (apart from set mmInstanceHeap.HeapHead, which we want to avoid anyway)
        patch_jmp("aiVehicleSpline::~aiVehicleSpline", "Avoid freeing aiVehicleInstance", 0x459F84, jump_type::always);

        create_patch("sfPointer::ResChange", "Use Old Cursor", 0x641F2C, "pointer", 8);

        create_patch("dxiScreenShot", "Disable second CloseHandle call", 0x57488F, "\x90\x90\x90\x90\x90\x90\x90", 7);

        // create_patch("DoScan", "Stop Touching Memory", 0x4046D0, "\xC3", 1);

        // create_patch("MultiTexture", "Enable D3D MultiTexture", 0x530788 + 6, "\x02", 1);

        patch_jmp("sfPointer::Update", "Enable cursor in windowed mode", 0x4BDAA4, jump_type::never);

        patch_jmp("PolarCamCS", "No Collision", 0x4FAFF4, jump_type::always);

        create_patch("PolarCamCS", "Increase Max XCAM Distance", 0x620340, "\x00\x00\x7A\x43", 4);

        create_patch("aiVehicleOpponent::Reset", "Fix List::Clear memory leak", 0x44DE4D, "\x89\xF9\xE8\x3C\xE4\x12\x00\x90\x8B\xD3\x42", 11);
        create_patch("aiVehiclePolice::Reset", "Fix List::Clear memory leak", 0x44511C, "\x89\xF9\xE8\x6D\x71\x13\x00\x90", 8);

        Displayf("Begin Init Functions");

        std::size_t init_count = mem::init_function::init();

        Displayf("Processed %zu Init Functions", init_count);

        asMemoryAllocator init_alloc;
        usize init_heap_size = 0x80000;
        void* init_heap = std::malloc(init_heap_size);
        init_alloc.Init(init_heap, init_heap_size, true);

        CURHEAP = &init_alloc;
        std::size_t export_hook_count = InitExportHooks(hinstDLL);
        CURHEAP = nullptr;

        init_alloc.Kill();
        std::free(init_heap);

        Displayf("Processed %zu Export Hooks", export_hook_count);
    }

    return TRUE;
}

include_dummy_symbol(midtown);

include_dummy_symbol(agi_bitmap);
include_dummy_symbol(agi_cmodel);
// include_dummy_symbol(agi_cmodel8);
// include_dummy_symbol(agi_cmodelx);
// include_dummy_symbol(agi_dlp);
// include_dummy_symbol(agi_dlptmpl);
// include_dummy_symbol(agi_dyndlp);
include_dummy_symbol(agi_error);
// include_dummy_symbol(agi_getdlp);
// include_dummy_symbol(agi_light);
// include_dummy_symbol(agi_lmodel);
// include_dummy_symbol(agi_mtldef);
include_dummy_symbol(agi_mtllib);
// include_dummy_symbol(agi_palette);
// include_dummy_symbol(agi_physdef);
include_dummy_symbol(agi_physlib);
include_dummy_symbol(agi_pipeline);
include_dummy_symbol(agi_print);
include_dummy_symbol(agi_refresh);
// include_dummy_symbol(agi_render);
include_dummy_symbol(agi_rsys);
// include_dummy_symbol(agi_smap);
include_dummy_symbol(agi_surface);
include_dummy_symbol(agi_texdef);
include_dummy_symbol(agi_texlib);
// include_dummy_symbol(agi_viewport);

// include_dummy_symbol(agid3d_d3dlight);
// include_dummy_symbol(agid3d_d3dmtldef);
// include_dummy_symbol(agid3d_d3dpipe);
// include_dummy_symbol(agid3d_d3drpipe);
// include_dummy_symbol(agid3d_d3drsys);
// include_dummy_symbol(agid3d_d3dtexdef);
// include_dummy_symbol(agid3d_d3dview);
// include_dummy_symbol(agid3d_ddbitmap);
// include_dummy_symbol(agid3d_dderror);
// include_dummy_symbol(agid3d_ddpipe);
// include_dummy_symbol(agid3d_pcpipe);

// include_dummy_symbol(agirend_bilight);
// include_dummy_symbol(agirend_bilmodel);
// include_dummy_symbol(agirend_lighter);
// include_dummy_symbol(agirend_projvtx);
// include_dummy_symbol(agirend_rdlp);
// include_dummy_symbol(agirend_surfrender);
// include_dummy_symbol(agirend_zbrender);

// include_dummy_symbol(agisw_swddraw);
// include_dummy_symbol(agisw_swemitrunall);
// include_dummy_symbol(agisw_swpipe);
// include_dummy_symbol(agisw_swrend);
// include_dummy_symbol(agisw_swrsys);
// include_dummy_symbol(agisw_swtexdef);

// include_dummy_symbol(agiworld_bone);
// include_dummy_symbol(agiworld_getmesh);
// include_dummy_symbol(agiworld_getmodel);
include_dummy_symbol(agiworld_meshlight);
// include_dummy_symbol(agiworld_meshload);
// include_dummy_symbol(agiworld_meshmodel);
// include_dummy_symbol(agiworld_meshrend);
// include_dummy_symbol(agiworld_meshsave);
// include_dummy_symbol(agiworld_meshset);
// include_dummy_symbol(agiworld_mrkni);
// include_dummy_symbol(agiworld_packnorm);
// include_dummy_symbol(agiworld_quality);
// include_dummy_symbol(agiworld_skeleton);
// include_dummy_symbol(agiworld_texsheet);
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

// include_dummy_symbol(localize_localize);

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
// include_dummy_symbol(mmai_aiPoliceForce);
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
// include_dummy_symbol(mmaudio_cd);
// include_dummy_symbol(mmaudio_crevbuf);
// include_dummy_symbol(mmaudio_creverb);
// include_dummy_symbol(mmaudio_dsglobal);
// include_dummy_symbol(mmaudio_dupbufcreator);
// include_dummy_symbol(mmaudio_eaxguid);
// include_dummy_symbol(mmaudio_head);
// include_dummy_symbol(mmaudio_manager);
// include_dummy_symbol(mmaudio_mixer);
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
// include_dummy_symbol(mmcar_shard);
// include_dummy_symbol(mmcar_shock);
// include_dummy_symbol(mmcar_skid);
// include_dummy_symbol(mmcar_splash);
// include_dummy_symbol(mmcar_stuck);
// include_dummy_symbol(mmcar_surfaceaudio);
// include_dummy_symbol(mmcar_surfaceaudioinfo);
// include_dummy_symbol(mmcar_trailer);
// include_dummy_symbol(mmcar_transmission);
// include_dummy_symbol(mmcar_wheel);

// include_dummy_symbol(mmcity_anim);
// include_dummy_symbol(mmcity_cellrend);
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

// include_dummy_symbol(mmcityinfo_cityinfo);
// include_dummy_symbol(mmcityinfo_citylist);
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
// include_dummy_symbol(mmcityinfo_vehinfo);
// include_dummy_symbol(mmcityinfo_vehlist);

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
// include_dummy_symbol(mmeffects_linespark);
// include_dummy_symbol(mmeffects_meshform);
// include_dummy_symbol(mmeffects_mmnumber);
include_dummy_symbol(mmeffects_mmtext);
// include_dummy_symbol(mmeffects_mousesteerbar);
// include_dummy_symbol(mmeffects_ptx);
include_dummy_symbol(mmeffects_vehform);

// include_dummy_symbol(mmgame_cd);
// include_dummy_symbol(mmgame_dash);
// include_dummy_symbol(mmgame_game);
// include_dummy_symbol(mmgame_gameedit);
// include_dummy_symbol(mmgame_gameman);
// include_dummy_symbol(mmgame_gamemulti);
// include_dummy_symbol(mmgame_gamesingle);
// include_dummy_symbol(mmgame_gauge);
// include_dummy_symbol(mmgame_hud);
// include_dummy_symbol(mmgame_hudmap);
// include_dummy_symbol(mmgame_icons);
// include_dummy_symbol(mmgame_interface);
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
// include_dummy_symbol(mminput_input);
// include_dummy_symbol(mminput_io);
// include_dummy_symbol(mminput_iodev);
// include_dummy_symbol(mminput_joyman);
// include_dummy_symbol(mminput_joystick);
// include_dummy_symbol(mminput_localize);
// include_dummy_symbol(mminput_road);
// include_dummy_symbol(mminput_spring);

// include_dummy_symbol(mmnetwork_netobject);
// include_dummy_symbol(mmnetwork_network);
// include_dummy_symbol(mmphysics_aero);
// include_dummy_symbol(mmphysics_bound);
// include_dummy_symbol(mmphysics_entity);
// include_dummy_symbol(mmphysics_inertia);
// include_dummy_symbol(mmphysics_joint3dof);
// include_dummy_symbol(mmphysics_osample);
// include_dummy_symbol(mmphysics_phys);

// include_dummy_symbol(mmui_about);
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
// include_dummy_symbol(mmui_graphics);
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
// include_dummy_symbol(mmui_pu_key);
// include_dummy_symbol(mmui_pu_main);
// include_dummy_symbol(mmui_pu_menu);
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
// include_dummy_symbol(mmwidget_cwarray);
// include_dummy_symbol(mmwidget_dropdown);
// include_dummy_symbol(mmwidget_icon);
// include_dummy_symbol(mmwidget_iconwidget);
// include_dummy_symbol(mmwidget_label);
// include_dummy_symbol(mmwidget_manager);
// include_dummy_symbol(mmwidget_menu);
// include_dummy_symbol(mmwidget_mexbutton);
// include_dummy_symbol(mmwidget_mstore);
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
// include_dummy_symbol(mmwidget_wstore);

include_dummy_symbol(pcwindis_dxinit);
include_dummy_symbol(pcwindis_dxmovie);
include_dummy_symbol(pcwindis_dxsetup);
include_dummy_symbol(pcwindis_pcwindis);
include_dummy_symbol(pcwindis_setupdata);

include_dummy_symbol(stream_filestream);
include_dummy_symbol(stream_fsystem);
include_dummy_symbol(stream_hfsystem);
// include_dummy_symbol(stream_problems);
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
