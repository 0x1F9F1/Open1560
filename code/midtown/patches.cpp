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

define_dummy_symbol(midtown_patches);

#include "patches.h"

static mem::cmd_param PARAM_rv3 {"rv3"};
static mem::cmd_param PARAM_opp_jump {"opp_jump"};
static mem::cmd_param PARAM_traffic_colors {"traffic_colors"};

[[maybe_unused]] static void InitPatches()
{
    // TODO: Move these patches elsewhere

    // Checked in GetPackedTexture, only necessary if agiRQ.TextureQuality <= 2
    // create_patch("aiVehicleOpponent::Init", "agiRQ.TextureQuality", 0x44DC2A, "\xEB\x06", 2);

    if (false) // Hack, replaces 16-bit handler with 32-bit handler
    {
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D419, "\x83\x79\x04\x04", 4);
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D439, "\x8D\x04\xBA", 3);
        create_patch("mmCullCity::UpdateSnowTextures", "32-bit snow", 0x48D47E, "\x8B\x00\x89\x04\x93\x90\x90", 7);
    }

    // create_patch("sfPointer::ResChange", "Use Old Cursor", 0x641F2C, "pointer", 8);

    // create_patch("DoScan", "Stop Touching Memory", 0x4046D0, "\xC3", 1);

    // create_patch("MultiTexture", "Enable D3D MultiTexture", 0x530788 + 6, "\x02", 1);

    patch_jmp("sfPointer::Update", "Enable cursor in windowed mode", 0x4BDAA4, jump_type::never);

    patch_jmp("PolarCamCS", "No Collision", 0x4FAFF4, jump_type::always);

    create_packed_patch<f32>("PolarCamCS", "Increase Max XCAM Distance", 0x620340, 250.0f);

    patch_jmp("mmMultiBlitz::Reset", "Always allow resetting", 0x41982D, jump_type::never);
    patch_jmp("mmMultiCircuit::Reset", "Always allow resetting", 0x41B19D, jump_type::never);
    patch_jmp("mmMultiRace::Reset", "Always allow resetting", 0x4203EF, jump_type::never);

    create_patch("aiVehicleOpponent::Reset", "Fix List::Clear memory leak", 0x44DE4D,
        "\x89\xF9\xE8\x3C\xE4\x12\x00\x90\x8B\xD3\x42", 11);

    create_patch(
        "aiVehiclePolice::Reset", "Fix List::Clear memory leak", 0x44511C, "\x89\xF9\xE8\x6D\x71\x13\x00\x90", 8);

    create_patch("agiSWTexLut::BeginGfx", "Fixed Fog Calculation", 0x5379F2,
        "\xB8\x00\x01\x00\x00\x89\x45\xE4\x46\xC1\xE6\x05\x29\xF0\x90\x90\x90", 0x11);

    create_patch("swComputeIntensity", "Fixed Fog Calculation", 0x536857, "\xB8\x00\x07\x00\x00\x5D\xC3", 7);

    patch_jmp("VehShowcase::PreSetup", "Fix showcase with addon cars", 0x4A5146, jump_type::never);

    patch_jmp("mmInterface::PlayerFillStats", "Always Show Score", 0x40C414, jump_type::never);

    create_patch("DriverMenu::DisplayDriverInfo", "Fix score alignment", 0x6410E0, "%d", 3);

    patch_jmp("mmCullCity::Init", "DevelopmentMode", 0x48C851, jump_type::always);
    patch_jmp("mmCullCity::Init", "DevelopmentMode", 0x4908DC, jump_type::always);

    patch_jmp("GetMeshSet", "Pager address check", 0x512AD5, jump_type::always);
    patch_jmp("mmBoundTemplate::LockIfResident", "Pager address check", 0x519329, jump_type::always);

    // create_patch("AudManager::Disable", "Actually disable sfx/music", 0x4E9098 + 1, "\x00\x00\x00\x00", 4);

    create_patch("mmWheel::Update", "Wheel Speed", 0x47F179, "\xDD\xD8\x90\x90\x90\x90", 6);

    create_packed_patch<f32>("SkidRotationThresh", "Fix skids", 0x63C014, 0.5f);

    for (usize addr : {
             0x4F5B6E, // ?SetupNotifications@StreamObj@@QAEHXZ
             0x4F5C15, // ?HandleNotifications@@YAKPAX@Z
             0x4F5E2C, // ?HandleNotifications@@YAKPAX@Z
             0x4F4CD6, // ??1StreamObj@@QAE@XZ
             0x4F52E2, // ?Play@StreamObj@@QAEHXZ
             0x4F533C, // ?SetPlayOneShotEvent@StreamObj@@QAEXPAD@Z
             0x4F5397, // ?SetStopEvent@StreamObj@@QAEXXZ
             0x4F53BA, // ?SetVolumeEvent@StreamObj@@QAEXM@Z
             0x4F53EA, // ?SetFrequencyEvent@StreamObj@@QAEXM@Z
             0x4F541A, // ?SetPanEvent@StreamObj@@QAEXM@Z
             0x4F54D3, // ?Play@StreamObj@@QAEHPAD@Z
         })
    {
        create_patch("StreamObj", "Disable Thread Suspend", addr, "\x58\x31\xC0\x90\x90\x90", 6);
    }

    constexpr u32 pxt_checks[][2] {
        {0x444609, 0x444642}, // ?Draw@aiTrafficLightInstance@@UAIXH@Z
        {0x451DA5, 0x451DDE}, // ?Draw@aiVehicleInstance@@UAIXH@Z
        {0x471BDA, 0x471C0D}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x471C2D, 0x471C60}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x471C80, 0x471CB3}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x471F92, 0x471FC5}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x471FE5, 0x472018}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x472035, 0x472068}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x4728D5, 0x472908}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x472925, 0x472958}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x472978, 0x4729AB}, // ?Draw@mmCarModel@@UAIXH@Z
        {0x48D7B9, 0x48D7F2}, // ?Update@mmCullCity@@UAEXXZ
        {0x4C9DF8, 0x4C9E31}, // ?Draw@mmBangerInstance@@UAIXH@Z
        {0x4CA0B7, 0x4CA0F0}, // ?Draw@mmHitBangerInstance@@UAIXH@Z
        {0x4CBA9F, 0x4CBAD8}, // ?Draw@mmGlassBangerInstance@@EAIXH@Z
    };

    for (const auto [from, to] : pxt_checks)
    {
        create_hook("PtxCount", "Avoid particle limit crash", from, to, hook_type::jmp);
    }

    create_packed_patch<u8>(
        "MenuManager::ScanGlobalKeys", "Debug Text Alignment", 0x4B11DA + 1, 0x7); // CENTER | VCENTER | BORDER

    for (usize addr : {0x413BC0, 0x415D72, 0x417A90})
    {
        create_patch("LocPlayerName", "lea don't mov", addr, "\x8D", 1);
    }

    patch_jmp("mmPlayer::Init", "Enable FreeCam when not in DevelopmentMode", 0x42A8E8, jump_type::never);

    create_packed_patch<u8, f32, u8, u8, u8>(
        "mmGameEdit::InitGameObjects", "Use a valid waypoint object", 0x412495, 0x68, 7.5f, 0x6A, 0x03, 0x90);

    create_packed_patch<const char*>(
        "mmGameEdit::InitGameObjects", "Use a valid waypoint object", 0x4124A7 + 1, "pt_check");

    create_packed_patch<f32>("Vehicle::Vehicle", "Camera Viewport X", 0x4A522E + 1, 34.0f / 640.0f);
    create_packed_patch<f32>("Vehicle::Vehicle", "Camera Viewport Y", 0x4A5229 + 1, 175.0f / 480.0f);
    create_packed_patch<f32>("Vehicle::Vehicle", "Camera Viewport W", 0x4A5224 + 1, 290.0f / 640.0f);
    create_packed_patch<f32>("Vehicle::Vehicle", "Camera Viewport H", 0x4A521F + 1, 216.0f / 480.0f);
    create_packed_patch<f32>("VehicleSelectBase::InitCarSelection", "Camera Viewport Offset", 0x49B043 + 3, 2.3f);

    {
        // sw[Tri/Quad/Poly] uses Q12.10 for casting vertices to integers

        // This currently does not change anything apart from the mask, which can actually fit 1 more bit (increasing the res limit to 4096x4096)
        const u32 whole_bits = 12; // TODO: Why not just use 22?

        for (usize addr : {
                 0x53697B, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     esi, 0Ah
                 0x536999, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     eax, 0Ah
                 0x5369BC, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     eax, 0Ah
                 0x5369DA, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     ecx, 0Ah
                 0x536A00, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     edx, 0Ah
                 0x536A20, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    shr     edi, 0Ah

                 0x536B75, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536B93, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536BB9, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536BD7, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536C00, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536C21, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536C4D, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah
                 0x536C6E, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  shr     esi, 0Ah

                 0x536F98, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    shr     ecx, 0Ah
                 0x536FB6, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    shr     ecx, 0Ah
                 0x537005, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    shr     eax, 0Ah
                 0x537022, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    shr     ecx, 0Ah
             })
        {
            create_packed_patch<u8>("Software Renderer", "Max Software Resolution", addr + 2,
                static_cast<u8>(22 - whole_bits)); // shr x, 10
        }

        for (usize addr : {
                 0x53697E, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     esi, 7FFh
                 0x53699C, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     eax, 7FFh
                 0x5369BF, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     eax, 7FFh
                 0x5369DD, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     ecx, 7FFh
                 0x536A03, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     edx, 7FFh
                 0x536A23, // ?swTri@@YAXPAUagiScreenVtx@@00@Z    and     edi, 7FFh

                 0x536B78, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536B96, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536BBC, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536BDA, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536C03, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536C24, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536C50, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh
                 0x536C71, // ?swQuad@@YAXPAUagiScreenVtx@@000@Z  and     esi, 7FFh

                 0x536F9B, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    and     ecx, 7FFh
                 0x536FB9, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    and     ecx, 7FFh
                 0x537008, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    and     eax, 7FFh
                 0x537025, // ?swPoly@@YAXPAUagiScreenVtx@@H@Z    and     ecx, 7FFh
             })
        {
            switch (*(const u8*) (addr))
            {
                case 0x25: addr += 1; break;
                case 0x81: addr += 2; break;
            }

            create_packed_patch<u32>(
                "Software Renderer", "Max Software Resolution", addr, (1 << whole_bits) - 1); // and x, 7FF
        }

        create_packed_patch<f32>(
            "Software Renderer", "Max Software Resolution", 0x6212D4, -static_cast<f32>(3 << whole_bits)); // -12288.0
        create_packed_patch<f32>(
            "Software Renderer", "Max Software Resolution", 0x652258, static_cast<f32>(3 << whole_bits)); // 12288.0
        create_packed_patch<u8>("Software Renderer", "Max Software Resolution", 0x537450 + 2,
            static_cast<u8>(whole_bits)); // lea     ecx, [eax+0Ch]

        create_packed_patch<u16>(
            "TestResolution", "Max Software Resolution", 0x575E6C + 3, static_cast<u16>(1 << whole_bits));
        create_packed_patch<u16>(
            "TestResolution", "Max Software Resolution", 0x575E73 + 2, static_cast<u16>(1 << whole_bits));
    }

    // Declare car mover before trailer mover
    // TODO: Also patch mmNetObject::Update?
    create_patch("mmPlayer::Update", "DeclareMover Order", 0x42C096,
        "\x8D\xB3\x34\x20\x00\x00\x6A\x0B\x6A\x01\x56\xB9\x98\x86\x71\x00\xE8\x95\x84\x0A\x00\xF6\x83\x50\x20\x00\x00"
        "\x80\x74\x18\x8B\x8B\x40\x23\x00\x00\x6A\x0A\x83\xC1\x24\x6A\x01\x51\xB9\x98\x86\x71\x00\xE8\x74\x84\x0A\x00",
        0x36);

    if (PARAM_rv3)
    {
        create_patch("mmCullCity::InitTimeOfDayAndWeather", "Don't change mmSky::Color", 0x48DE0B,
            "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90", 10);

        create_patch("mmSky::Draw", "Disable Sky Rotation", 0x4956E4, "\xD9\xEE\x90\x90\x90\x90", 6);

        create_packed_patch<f32>("mmSky::Draw", "Sky Offset", 0x61D1D4, 0.005f);
        create_packed_patch<f32>("SkyScale", "Sky Scale", 0x63FC54, 0.0045f);

        struct EnvSetup // t_mmEnvSetup
        {
            const char* Sky;
            const char* SphereMap;
            const char* ShadowMap;
            f32 EnvVel;
            f32 SkyHeight;
            f32 FogEnd;
            u32 SkyColor;
            f32 field_1C;
            f32 field_20;
            f32 field_24;
        };

        auto& env_setup = mem::pointer(0x63E260).as<EnvSetup[4][4]>();

        env_setup[0][1].ShadowMap = "shadmap_cld";
        env_setup[0][3].SphereMap = "refl_ms";

        env_setup[1][1].ShadowMap = "shadmap_cld";
        env_setup[1][3].SphereMap = "refl_ns";

        env_setup[2][1].ShadowMap = "shadmap_cld";
        env_setup[2][3].SphereMap = "refl_ss";

        env_setup[2][3].SphereMap = "refl_ds";
    }

    // create_patch("mmPopup::Update", "Don't Reset GameManager on F4", 0x427741, "\x90\x90\x90", 3);

#ifdef __clang__
    // Hacky workaround for clang's lack of vector deleting destructor support
    // https://bugs.llvm.org/show_bug.cgi?id=19398

    struct VecDelDtor
    {
        virtual ~VecDelDtor() = 0;

        void Destruct()
        {
            // Assumes the class:
            // * Is 4-byte aligned
            // * Has the virtual destructor at the start of the vtable
            // * msize returns the exact size

            void* base = reinterpret_cast<usize*>(this) - 1;
            usize i = *static_cast<usize*>(base);
            usize stride = (arts_msize(base) - sizeof(usize)) / i;

            while (i--)
            {
                reinterpret_cast<VecDelDtor*>(reinterpret_cast<u8*>(this) + (i * stride))->~VecDelDtor();
            }

            operator delete(base);
        }
    };

    // Addresses of known vecdeldtor calls, ignoring MetaClass delete_* functions.
    for (usize addr : {
             0x4248F3,
             0x424903,
             0x425316,
             0x425326,
             0x425399,
             0x477BA3,
             0x478893,
             0x49B806,
             0x49B816,
             0x4B0C9D,
             0x4B0CAD,
             0x4B8933,
             0x4C08A3,
             0x4C0A67,
             0x4E09B5,
             0x4FE75D,
         })
    {
        create_patch("", "", addr, "\x90\x90\x90\x90\x90\x90", 6);
        create_hook("", "", addr, &VecDelDtor::Destruct, hook_type::call);
    }
#endif

    if (PARAM_traffic_colors)
    {
        for (usize addr : {
                 0x4743C9,
                 0x47441D,
                 0x474471,
                 0x4744DD,
             })
        {
            patch_jmp("mmCar::VehNameRemap", "Egg Check", addr, jump_type::never);
        }

        // Ambient Vehicle Colors
        static const u32 AmbientVehiclePalette[] {
            0xFFB58900, // Yellow
            0xFFCB4B16, // Orange
            0xFFDC322F, // Red
            0xFFD33682, // Magenta
            0xFF6C71C4, // Violet
            0xFF268BD2, // Blue
            0xFF2AA198, // Cyan
            0xFF859900, // Green
        };

        create_hook("aiVehicleAmbient::Init", "Custom Ambient Colors", 0x44EFF1,
            alloc_proxy<ARTS_SIZE(AmbientVehiclePalette) * sizeof(u32**)>, hook_type::call);

        create_packed_patch<const void*>(
            "aiVehicleAmbient::Init", "Custom Ambient Colors", 0x44EFF6 + 1, &AmbientVehiclePalette);

        create_packed_patch<u32>(
            "aiVehicleAmbient::Init", "Custom Ambient Colors", 0x44F008 + 3, ARTS_SIZE32(AmbientVehiclePalette));

        create_packed_patch<u32>(
            "aiVehicleAmbient::Init", "Custom Ambient Colors", 0x44F100 + 1, ARTS_SIZE32(AmbientVehiclePalette));
    }

    patch_jmp("mmCar::VehNameRemap", "Work in all game modes", 0x474371, jump_type::never);
}

hook_func(INIT_main, [] { InitPatches(); });