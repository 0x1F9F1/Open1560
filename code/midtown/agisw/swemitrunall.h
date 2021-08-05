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

/*
    agisw:swemitrunall

    0x537DF0 | void __fastcall swEmitRun1_NoZOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun1_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x537E80 | void __fastcall swEmitRun2_NoZOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun2_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x537F10 | void __fastcall swEmitRun3_NoZOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun3_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x537FA0 | void __fastcall swEmitRun4_NoZOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun4_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x538030 | void __fastcall swEmitRun5_NoZOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun5_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x538250 | void __fastcall swEmitRun6_NoZOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun6_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x538470 | void __fastcall swEmitRun7_NoZOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun7_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x538690 | void __fastcall swEmitRun8_NoZOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun8_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x5388A0 | void __fastcall swEmitRun0_ZReadOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun0_ZReadOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x538980 | void __fastcall swEmitRun1_ZReadWriteOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun1_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x538A60 | void __fastcall swEmitRun2_ZReadWriteOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun2_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x538B40 | void __fastcall swEmitRun3_ZReadWriteOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun3_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x538C20 | void __fastcall swEmitRun4_ZReadWriteOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun4_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x538D00 | void __fastcall swEmitRun5_ZReadWriteOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun5_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x539060 | void __fastcall swEmitRun6_ZReadWriteOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun6_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x5393C0 | void __fastcall swEmitRun7_ZReadWriteOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun7_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x539720 | void __fastcall swEmitRun8_ZReadWriteOpaqueDecalLinearSolidWUWV(int) | ?swEmitRun8_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
    0x539A70 | void __fastcall swEmitRun0_NoZOpaqueDecalLinearStippleWUWV(int) | ?swEmitRun0_NoZOpaqueDecalLinearStippleWUWV@@YIXH@Z
    0x539B20 | void __fastcall swEmitRun0_ZReadOpaqueDecalLinearStippleWUWV(int) | ?swEmitRun0_ZReadOpaqueDecalLinearStippleWUWV@@YIXH@Z
    0x539C20 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalLinearStippleWUWV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleWUWV@@YIXH@Z
    0x539D20 | void __fastcall swEmitRun0_NoZChromaDecalLinearSolidWUWV(int) | ?swEmitRun0_NoZChromaDecalLinearSolidWUWV@@YIXH@Z
    0x539DC0 | void __fastcall swEmitRun0_ZReadChromaDecalLinearSolidWUWV(int) | ?swEmitRun0_ZReadChromaDecalLinearSolidWUWV@@YIXH@Z
    0x539EB0 | void __fastcall swEmitRun0_ZReadWriteChromaDecalLinearSolidWUWV(int) | ?swEmitRun0_ZReadWriteChromaDecalLinearSolidWUWV@@YIXH@Z
    0x539FA0 | void __fastcall swEmitRun0_NoZChromaDecalLinearStippleWUWV(int) | ?swEmitRun0_NoZChromaDecalLinearStippleWUWV@@YIXH@Z
    0x53A060 | void __fastcall swEmitRun0_ZReadChromaDecalLinearStippleWUWV(int) | ?swEmitRun0_ZReadChromaDecalLinearStippleWUWV@@YIXH@Z
    0x53A160 | void __fastcall swEmitRun0_ZReadWriteChromaDecalLinearStippleWUWV(int) | ?swEmitRun0_ZReadWriteChromaDecalLinearStippleWUWV@@YIXH@Z
    0x53A270 | void __fastcall swEmitRun0_NoZGlowDecalLinearSolidWUWV(int) | ?swEmitRun0_NoZGlowDecalLinearSolidWUWV@@YIXH@Z
    0x53A340 | void __fastcall swEmitRun0_ZReadGlowDecalLinearSolidWUWV(int) | ?swEmitRun0_ZReadGlowDecalLinearSolidWUWV@@YIXH@Z
    0x53A460 | void __fastcall swEmitRun0_ZReadWriteGlowDecalLinearSolidWUWV(int) | ?swEmitRun0_ZReadWriteGlowDecalLinearSolidWUWV@@YIXH@Z
    0x53A590 | void __fastcall swEmitRun0_NoZGlowDecalLinearStippleWUWV(int) | ?swEmitRun0_NoZGlowDecalLinearStippleWUWV@@YIXH@Z
    0x53A670 | void __fastcall swEmitRun0_ZReadGlowDecalLinearStippleWUWV(int) | ?swEmitRun0_ZReadGlowDecalLinearStippleWUWV@@YIXH@Z
    0x53A7A0 | void __fastcall swEmitRun0_ZReadWriteGlowDecalLinearStippleWUWV(int) | ?swEmitRun0_ZReadWriteGlowDecalLinearStippleWUWV@@YIXH@Z
    0x53A8E0 | void __fastcall swEmitRun0_NoZOpaqueModulateLinearSolidWUWV(int) | ?swEmitRun0_NoZOpaqueModulateLinearSolidWUWV@@YIXH@Z
    0x53A980 | void __fastcall swEmitRun0_ZReadOpaqueModulateLinearSolidWUWV(int) | ?swEmitRun0_ZReadOpaqueModulateLinearSolidWUWV@@YIXH@Z
    0x53AA70 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateLinearSolidWUWV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidWUWV@@YIXH@Z
    0x53AB70 | void __fastcall swEmitRun0_NoZOpaqueModulateLinearStippleWUWV(int) | ?swEmitRun0_NoZOpaqueModulateLinearStippleWUWV@@YIXH@Z
    0x53AC20 | void __fastcall swEmitRun0_ZReadOpaqueModulateLinearStippleWUWV(int) | ?swEmitRun0_ZReadOpaqueModulateLinearStippleWUWV@@YIXH@Z
    0x53AD20 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateLinearStippleWUWV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleWUWV@@YIXH@Z
    0x53AE30 | void __fastcall swEmitRun0_NoZChromaModulateLinearSolidWUWV(int) | ?swEmitRun0_NoZChromaModulateLinearSolidWUWV@@YIXH@Z
    0x53AEE0 | void __fastcall swEmitRun0_ZReadChromaModulateLinearSolidWUWV(int) | ?swEmitRun0_ZReadChromaModulateLinearSolidWUWV@@YIXH@Z
    0x53AFE0 | void __fastcall swEmitRun0_ZReadWriteChromaModulateLinearSolidWUWV(int) | ?swEmitRun0_ZReadWriteChromaModulateLinearSolidWUWV@@YIXH@Z
    0x53B0E0 | void __fastcall swEmitRun0_NoZChromaModulateLinearStippleWUWV(int) | ?swEmitRun0_NoZChromaModulateLinearStippleWUWV@@YIXH@Z
    0x53B1A0 | void __fastcall swEmitRun0_ZReadChromaModulateLinearStippleWUWV(int) | ?swEmitRun0_ZReadChromaModulateLinearStippleWUWV@@YIXH@Z
    0x53B2B0 | void __fastcall swEmitRun0_ZReadWriteChromaModulateLinearStippleWUWV(int) | ?swEmitRun0_ZReadWriteChromaModulateLinearStippleWUWV@@YIXH@Z
    0x53B3C0 | void __fastcall swEmitRun0_NoZGlowModulateLinearSolidWUWV(int) | ?swEmitRun0_NoZGlowModulateLinearSolidWUWV@@YIXH@Z
    0x53B490 | void __fastcall swEmitRun0_ZReadGlowModulateLinearSolidWUWV(int) | ?swEmitRun0_ZReadGlowModulateLinearSolidWUWV@@YIXH@Z
    0x53B5B0 | void __fastcall swEmitRun0_ZReadWriteGlowModulateLinearSolidWUWV(int) | ?swEmitRun0_ZReadWriteGlowModulateLinearSolidWUWV@@YIXH@Z
    0x53B6E0 | void __fastcall swEmitRun0_NoZGlowModulateLinearStippleWUWV(int) | ?swEmitRun0_NoZGlowModulateLinearStippleWUWV@@YIXH@Z
    0x53B7C0 | void __fastcall swEmitRun0_ZReadGlowModulateLinearStippleWUWV(int) | ?swEmitRun0_ZReadGlowModulateLinearStippleWUWV@@YIXH@Z
    0x53B8F0 | void __fastcall swEmitRun0_ZReadWriteGlowModulateLinearStippleWUWV(int) | ?swEmitRun0_ZReadWriteGlowModulateLinearStippleWUWV@@YIXH@Z
    0x53BA30 | void __fastcall swEmitRun0_NoZOpaqueDecalParaSolidWUWV(int) | ?swEmitRun0_NoZOpaqueDecalParaSolidWUWV@@YIXH@Z
    0x53BAF0 | void __fastcall swEmitRun0_ZReadOpaqueDecalParaSolidWUWV(int) | ?swEmitRun0_ZReadOpaqueDecalParaSolidWUWV@@YIXH@Z
    0x53BC00 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalParaSolidWUWV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidWUWV@@YIXH@Z
    0x53BD10 | void __fastcall swEmitRun0_NoZOpaqueDecalParaStippleWUWV(int) | ?swEmitRun0_NoZOpaqueDecalParaStippleWUWV@@YIXH@Z
    0x53BDE0 | void __fastcall swEmitRun0_ZReadOpaqueDecalParaStippleWUWV(int) | ?swEmitRun0_ZReadOpaqueDecalParaStippleWUWV@@YIXH@Z
    0x53BF00 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalParaStippleWUWV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleWUWV@@YIXH@Z
    0x53C020 | void __fastcall swEmitRun0_NoZChromaDecalParaSolidWUWV(int) | ?swEmitRun0_NoZChromaDecalParaSolidWUWV@@YIXH@Z
    0x53C0E0 | void __fastcall swEmitRun0_ZReadChromaDecalParaSolidWUWV(int) | ?swEmitRun0_ZReadChromaDecalParaSolidWUWV@@YIXH@Z
    0x53C200 | void __fastcall swEmitRun0_ZReadWriteChromaDecalParaSolidWUWV(int) | ?swEmitRun0_ZReadWriteChromaDecalParaSolidWUWV@@YIXH@Z
    0x53C320 | void __fastcall swEmitRun0_NoZChromaDecalParaStippleWUWV(int) | ?swEmitRun0_NoZChromaDecalParaStippleWUWV@@YIXH@Z
    0x53C400 | void __fastcall swEmitRun0_ZReadChromaDecalParaStippleWUWV(int) | ?swEmitRun0_ZReadChromaDecalParaStippleWUWV@@YIXH@Z
    0x53C530 | void __fastcall swEmitRun0_ZReadWriteChromaDecalParaStippleWUWV(int) | ?swEmitRun0_ZReadWriteChromaDecalParaStippleWUWV@@YIXH@Z
    0x53C660 | void __fastcall swEmitRun0_NoZGlowDecalParaSolidWUWV(int) | ?swEmitRun0_NoZGlowDecalParaSolidWUWV@@YIXH@Z
    0x53C750 | void __fastcall swEmitRun0_ZReadGlowDecalParaSolidWUWV(int) | ?swEmitRun0_ZReadGlowDecalParaSolidWUWV@@YIXH@Z
    0x53C890 | void __fastcall swEmitRun0_ZReadWriteGlowDecalParaSolidWUWV(int) | ?swEmitRun0_ZReadWriteGlowDecalParaSolidWUWV@@YIXH@Z
    0x53C9E0 | void __fastcall swEmitRun0_NoZGlowDecalParaStippleWUWV(int) | ?swEmitRun0_NoZGlowDecalParaStippleWUWV@@YIXH@Z
    0x53CAF0 | void __fastcall swEmitRun0_ZReadGlowDecalParaStippleWUWV(int) | ?swEmitRun0_ZReadGlowDecalParaStippleWUWV@@YIXH@Z
    0x53CC40 | void __fastcall swEmitRun0_ZReadWriteGlowDecalParaStippleWUWV(int) | ?swEmitRun0_ZReadWriteGlowDecalParaStippleWUWV@@YIXH@Z
    0x53CDA0 | void __fastcall swEmitRun0_NoZOpaqueModulateParaSolidWUWV(int) | ?swEmitRun0_NoZOpaqueModulateParaSolidWUWV@@YIXH@Z
    0x53CE60 | void __fastcall swEmitRun0_ZReadOpaqueModulateParaSolidWUWV(int) | ?swEmitRun0_ZReadOpaqueModulateParaSolidWUWV@@YIXH@Z
    0x53CF70 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateParaSolidWUWV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidWUWV@@YIXH@Z
    0x53D080 | void __fastcall swEmitRun0_NoZOpaqueModulateParaStippleWUWV(int) | ?swEmitRun0_NoZOpaqueModulateParaStippleWUWV@@YIXH@Z
    0x53D160 | void __fastcall swEmitRun0_ZReadOpaqueModulateParaStippleWUWV(int) | ?swEmitRun0_ZReadOpaqueModulateParaStippleWUWV@@YIXH@Z
    0x53D280 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateParaStippleWUWV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleWUWV@@YIXH@Z
    0x53D3B0 | void __fastcall swEmitRun0_NoZChromaModulateParaSolidWUWV(int) | ?swEmitRun0_NoZChromaModulateParaSolidWUWV@@YIXH@Z
    0x53D480 | void __fastcall swEmitRun0_ZReadChromaModulateParaSolidWUWV(int) | ?swEmitRun0_ZReadChromaModulateParaSolidWUWV@@YIXH@Z
    0x53D5A0 | void __fastcall swEmitRun0_ZReadWriteChromaModulateParaSolidWUWV(int) | ?swEmitRun0_ZReadWriteChromaModulateParaSolidWUWV@@YIXH@Z
    0x53D6C0 | void __fastcall swEmitRun0_NoZChromaModulateParaStippleWUWV(int) | ?swEmitRun0_NoZChromaModulateParaStippleWUWV@@YIXH@Z
    0x53D7A0 | void __fastcall swEmitRun0_ZReadChromaModulateParaStippleWUWV(int) | ?swEmitRun0_ZReadChromaModulateParaStippleWUWV@@YIXH@Z
    0x53D8D0 | void __fastcall swEmitRun0_ZReadWriteChromaModulateParaStippleWUWV(int) | ?swEmitRun0_ZReadWriteChromaModulateParaStippleWUWV@@YIXH@Z
    0x53DA10 | void __fastcall swEmitRun0_NoZGlowModulateParaSolidWUWV(int) | ?swEmitRun0_NoZGlowModulateParaSolidWUWV@@YIXH@Z
    0x53DB00 | void __fastcall swEmitRun0_ZReadGlowModulateParaSolidWUWV(int) | ?swEmitRun0_ZReadGlowModulateParaSolidWUWV@@YIXH@Z
    0x53DC40 | void __fastcall swEmitRun0_ZReadWriteGlowModulateParaSolidWUWV(int) | ?swEmitRun0_ZReadWriteGlowModulateParaSolidWUWV@@YIXH@Z
    0x53DD90 | void __fastcall swEmitRun0_NoZGlowModulateParaStippleWUWV(int) | ?swEmitRun0_NoZGlowModulateParaStippleWUWV@@YIXH@Z
    0x53DEA0 | void __fastcall swEmitRun0_ZReadGlowModulateParaStippleWUWV(int) | ?swEmitRun0_ZReadGlowModulateParaStippleWUWV@@YIXH@Z
    0x53DFF0 | void __fastcall swEmitRun0_ZReadWriteGlowModulateParaStippleWUWV(int) | ?swEmitRun0_ZReadWriteGlowModulateParaStippleWUWV@@YIXH@Z
    0x53E150 | void __fastcall swEmitRun0_NoZOpaqueDecalLinearSolidCUWV(int) | ?swEmitRun0_NoZOpaqueDecalLinearSolidCUWV@@YIXH@Z
    0x53E220 | void __fastcall swEmitRun0_ZReadOpaqueDecalLinearSolidCUWV(int) | ?swEmitRun0_ZReadOpaqueDecalLinearSolidCUWV@@YIXH@Z
    0x53E350 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalLinearSolidCUWV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalLinearSolidCUWV@@YIXH@Z
    0x53E470 | void __fastcall swEmitRun0_NoZOpaqueDecalLinearStippleCUWV(int) | ?swEmitRun0_NoZOpaqueDecalLinearStippleCUWV@@YIXH@Z
    0x53E550 | void __fastcall swEmitRun0_ZReadOpaqueDecalLinearStippleCUWV(int) | ?swEmitRun0_ZReadOpaqueDecalLinearStippleCUWV@@YIXH@Z
    0x53E680 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalLinearStippleCUWV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleCUWV@@YIXH@Z
    0x53E7C0 | void __fastcall swEmitRun0_NoZChromaDecalLinearSolidCUWV(int) | ?swEmitRun0_NoZChromaDecalLinearSolidCUWV@@YIXH@Z
    0x53E8B0 | void __fastcall swEmitRun0_ZReadChromaDecalLinearSolidCUWV(int) | ?swEmitRun0_ZReadChromaDecalLinearSolidCUWV@@YIXH@Z
    0x53E9F0 | void __fastcall swEmitRun0_ZReadWriteChromaDecalLinearSolidCUWV(int) | ?swEmitRun0_ZReadWriteChromaDecalLinearSolidCUWV@@YIXH@Z
    0x53EB30 | void __fastcall swEmitRun0_NoZChromaDecalLinearStippleCUWV(int) | ?swEmitRun0_NoZChromaDecalLinearStippleCUWV@@YIXH@Z
    0x53EC30 | void __fastcall swEmitRun0_ZReadChromaDecalLinearStippleCUWV(int) | ?swEmitRun0_ZReadChromaDecalLinearStippleCUWV@@YIXH@Z
    0x53ED80 | void __fastcall swEmitRun0_ZReadWriteChromaDecalLinearStippleCUWV(int) | ?swEmitRun0_ZReadWriteChromaDecalLinearStippleCUWV@@YIXH@Z
    0x53EED0 | void __fastcall swEmitRun0_NoZGlowDecalLinearSolidCUWV(int) | ?swEmitRun0_NoZGlowDecalLinearSolidCUWV@@YIXH@Z
    0x53EFD0 | void __fastcall swEmitRun0_ZReadGlowDecalLinearSolidCUWV(int) | ?swEmitRun0_ZReadGlowDecalLinearSolidCUWV@@YIXH@Z
    0x53F120 | void __fastcall swEmitRun0_ZReadWriteGlowDecalLinearSolidCUWV(int) | ?swEmitRun0_ZReadWriteGlowDecalLinearSolidCUWV@@YIXH@Z
    0x53F260 | void __fastcall swEmitRun0_NoZGlowDecalLinearStippleCUWV(int) | ?swEmitRun0_NoZGlowDecalLinearStippleCUWV@@YIXH@Z
    0x53F370 | void __fastcall swEmitRun0_ZReadGlowDecalLinearStippleCUWV(int) | ?swEmitRun0_ZReadGlowDecalLinearStippleCUWV@@YIXH@Z
    0x53F4D0 | void __fastcall swEmitRun0_ZReadWriteGlowDecalLinearStippleCUWV(int) | ?swEmitRun0_ZReadWriteGlowDecalLinearStippleCUWV@@YIXH@Z
    0x53F630 | void __fastcall swEmitRun0_NoZOpaqueModulateLinearSolidCUWV(int) | ?swEmitRun0_NoZOpaqueModulateLinearSolidCUWV@@YIXH@Z
    0x53F710 | void __fastcall swEmitRun0_ZReadOpaqueModulateLinearSolidCUWV(int) | ?swEmitRun0_ZReadOpaqueModulateLinearSolidCUWV@@YIXH@Z
    0x53F850 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateLinearSolidCUWV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidCUWV@@YIXH@Z
    0x53F980 | void __fastcall swEmitRun0_NoZOpaqueModulateLinearStippleCUWV(int) | ?swEmitRun0_NoZOpaqueModulateLinearStippleCUWV@@YIXH@Z
    0x53FA70 | void __fastcall swEmitRun0_ZReadOpaqueModulateLinearStippleCUWV(int) | ?swEmitRun0_ZReadOpaqueModulateLinearStippleCUWV@@YIXH@Z
    0x53FBB0 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateLinearStippleCUWV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleCUWV@@YIXH@Z
    0x53FD00 | void __fastcall swEmitRun0_NoZChromaModulateLinearSolidCUWV(int) | ?swEmitRun0_NoZChromaModulateLinearSolidCUWV@@YIXH@Z
    0x53FE00 | void __fastcall swEmitRun0_ZReadChromaModulateLinearSolidCUWV(int) | ?swEmitRun0_ZReadChromaModulateLinearSolidCUWV@@YIXH@Z
    0x53FF50 | void __fastcall swEmitRun0_ZReadWriteChromaModulateLinearSolidCUWV(int) | ?swEmitRun0_ZReadWriteChromaModulateLinearSolidCUWV@@YIXH@Z
    0x5400A0 | void __fastcall swEmitRun0_NoZChromaModulateLinearStippleCUWV(int) | ?swEmitRun0_NoZChromaModulateLinearStippleCUWV@@YIXH@Z
    0x5401B0 | void __fastcall swEmitRun0_ZReadChromaModulateLinearStippleCUWV(int) | ?swEmitRun0_ZReadChromaModulateLinearStippleCUWV@@YIXH@Z
    0x540310 | void __fastcall swEmitRun0_ZReadWriteChromaModulateLinearStippleCUWV(int) | ?swEmitRun0_ZReadWriteChromaModulateLinearStippleCUWV@@YIXH@Z
    0x540470 | void __fastcall swEmitRun0_NoZGlowModulateLinearSolidCUWV(int) | ?swEmitRun0_NoZGlowModulateLinearSolidCUWV@@YIXH@Z
    0x540570 | void __fastcall swEmitRun0_ZReadGlowModulateLinearSolidCUWV(int) | ?swEmitRun0_ZReadGlowModulateLinearSolidCUWV@@YIXH@Z
    0x5406C0 | void __fastcall swEmitRun0_ZReadWriteGlowModulateLinearSolidCUWV(int) | ?swEmitRun0_ZReadWriteGlowModulateLinearSolidCUWV@@YIXH@Z
    0x540800 | void __fastcall swEmitRun0_NoZGlowModulateLinearStippleCUWV(int) | ?swEmitRun0_NoZGlowModulateLinearStippleCUWV@@YIXH@Z
    0x540910 | void __fastcall swEmitRun0_ZReadGlowModulateLinearStippleCUWV(int) | ?swEmitRun0_ZReadGlowModulateLinearStippleCUWV@@YIXH@Z
    0x540A70 | void __fastcall swEmitRun0_ZReadWriteGlowModulateLinearStippleCUWV(int) | ?swEmitRun0_ZReadWriteGlowModulateLinearStippleCUWV@@YIXH@Z
    0x540BD0 | void __fastcall swEmitRun0_NoZOpaqueDecalParaSolidCUWV(int) | ?swEmitRun0_NoZOpaqueDecalParaSolidCUWV@@YIXH@Z
    0x540CD0 | void __fastcall swEmitRun0_ZReadOpaqueDecalParaSolidCUWV(int) | ?swEmitRun0_ZReadOpaqueDecalParaSolidCUWV@@YIXH@Z
    0x540E20 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalParaSolidCUWV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidCUWV@@YIXH@Z
    0x540F70 | void __fastcall swEmitRun0_NoZOpaqueDecalParaStippleCUWV(int) | ?swEmitRun0_NoZOpaqueDecalParaStippleCUWV@@YIXH@Z
    0x541080 | void __fastcall swEmitRun0_ZReadOpaqueDecalParaStippleCUWV(int) | ?swEmitRun0_ZReadOpaqueDecalParaStippleCUWV@@YIXH@Z
    0x5411E0 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalParaStippleCUWV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleCUWV@@YIXH@Z
    0x541340 | void __fastcall swEmitRun0_NoZChromaDecalParaSolidCUWV(int) | ?swEmitRun0_NoZChromaDecalParaSolidCUWV@@YIXH@Z
    0x541450 | void __fastcall swEmitRun0_ZReadChromaDecalParaSolidCUWV(int) | ?swEmitRun0_ZReadChromaDecalParaSolidCUWV@@YIXH@Z
    0x5415B0 | void __fastcall swEmitRun0_ZReadWriteChromaDecalParaSolidCUWV(int) | ?swEmitRun0_ZReadWriteChromaDecalParaSolidCUWV@@YIXH@Z
    0x541710 | void __fastcall swEmitRun0_NoZChromaDecalParaStippleCUWV(int) | ?swEmitRun0_NoZChromaDecalParaStippleCUWV@@YIXH@Z
    0x541830 | void __fastcall swEmitRun0_ZReadChromaDecalParaStippleCUWV(int) | ?swEmitRun0_ZReadChromaDecalParaStippleCUWV@@YIXH@Z
    0x5419A0 | void __fastcall swEmitRun0_ZReadWriteChromaDecalParaStippleCUWV(int) | ?swEmitRun0_ZReadWriteChromaDecalParaStippleCUWV@@YIXH@Z
    0x541B10 | void __fastcall swEmitRun0_NoZGlowDecalParaSolidCUWV(int) | ?swEmitRun0_NoZGlowDecalParaSolidCUWV@@YIXH@Z
    0x541C30 | void __fastcall swEmitRun0_ZReadGlowDecalParaSolidCUWV(int) | ?swEmitRun0_ZReadGlowDecalParaSolidCUWV@@YIXH@Z
    0x541DA0 | void __fastcall swEmitRun0_ZReadWriteGlowDecalParaSolidCUWV(int) | ?swEmitRun0_ZReadWriteGlowDecalParaSolidCUWV@@YIXH@Z
    0x541F10 | void __fastcall swEmitRun0_NoZGlowDecalParaStippleCUWV(int) | ?swEmitRun0_NoZGlowDecalParaStippleCUWV@@YIXH@Z
    0x542040 | void __fastcall swEmitRun0_ZReadGlowDecalParaStippleCUWV(int) | ?swEmitRun0_ZReadGlowDecalParaStippleCUWV@@YIXH@Z
    0x5421C0 | void __fastcall swEmitRun0_ZReadWriteGlowDecalParaStippleCUWV(int) | ?swEmitRun0_ZReadWriteGlowDecalParaStippleCUWV@@YIXH@Z
    0x542350 | void __fastcall swEmitRun0_NoZOpaqueModulateParaSolidCUWV(int) | ?swEmitRun0_NoZOpaqueModulateParaSolidCUWV@@YIXH@Z
    0x542460 | void __fastcall swEmitRun0_ZReadOpaqueModulateParaSolidCUWV(int) | ?swEmitRun0_ZReadOpaqueModulateParaSolidCUWV@@YIXH@Z
    0x5425C0 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateParaSolidCUWV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidCUWV@@YIXH@Z
    0x542710 | void __fastcall swEmitRun0_NoZOpaqueModulateParaStippleCUWV(int) | ?swEmitRun0_NoZOpaqueModulateParaStippleCUWV@@YIXH@Z
    0x542830 | void __fastcall swEmitRun0_ZReadOpaqueModulateParaStippleCUWV(int) | ?swEmitRun0_ZReadOpaqueModulateParaStippleCUWV@@YIXH@Z
    0x542990 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateParaStippleCUWV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleCUWV@@YIXH@Z
    0x542B00 | void __fastcall swEmitRun0_NoZChromaModulateParaSolidCUWV(int) | ?swEmitRun0_NoZChromaModulateParaSolidCUWV@@YIXH@Z
    0x542C20 | void __fastcall swEmitRun0_ZReadChromaModulateParaSolidCUWV(int) | ?swEmitRun0_ZReadChromaModulateParaSolidCUWV@@YIXH@Z
    0x542D90 | void __fastcall swEmitRun0_ZReadWriteChromaModulateParaSolidCUWV(int) | ?swEmitRun0_ZReadWriteChromaModulateParaSolidCUWV@@YIXH@Z
    0x542EF0 | void __fastcall swEmitRun0_NoZChromaModulateParaStippleCUWV(int) | ?swEmitRun0_NoZChromaModulateParaStippleCUWV@@YIXH@Z
    0x543020 | void __fastcall swEmitRun0_ZReadChromaModulateParaStippleCUWV(int) | ?swEmitRun0_ZReadChromaModulateParaStippleCUWV@@YIXH@Z
    0x5431A0 | void __fastcall swEmitRun0_ZReadWriteChromaModulateParaStippleCUWV(int) | ?swEmitRun0_ZReadWriteChromaModulateParaStippleCUWV@@YIXH@Z
    0x543320 | void __fastcall swEmitRun0_NoZGlowModulateParaSolidCUWV(int) | ?swEmitRun0_NoZGlowModulateParaSolidCUWV@@YIXH@Z
    0x543440 | void __fastcall swEmitRun0_ZReadGlowModulateParaSolidCUWV(int) | ?swEmitRun0_ZReadGlowModulateParaSolidCUWV@@YIXH@Z
    0x5435B0 | void __fastcall swEmitRun0_ZReadWriteGlowModulateParaSolidCUWV(int) | ?swEmitRun0_ZReadWriteGlowModulateParaSolidCUWV@@YIXH@Z
    0x543720 | void __fastcall swEmitRun0_NoZGlowModulateParaStippleCUWV(int) | ?swEmitRun0_NoZGlowModulateParaStippleCUWV@@YIXH@Z
    0x543850 | void __fastcall swEmitRun0_ZReadGlowModulateParaStippleCUWV(int) | ?swEmitRun0_ZReadGlowModulateParaStippleCUWV@@YIXH@Z
    0x5439D0 | void __fastcall swEmitRun0_ZReadWriteGlowModulateParaStippleCUWV(int) | ?swEmitRun0_ZReadWriteGlowModulateParaStippleCUWV@@YIXH@Z
    0x543B60 | void __fastcall swEmitRun0_NoZOpaqueDecalLinearSolidWUCV(int) | ?swEmitRun0_NoZOpaqueDecalLinearSolidWUCV@@YIXH@Z
    0x543C30 | void __fastcall swEmitRun0_ZReadOpaqueDecalLinearSolidWUCV(int) | ?swEmitRun0_ZReadOpaqueDecalLinearSolidWUCV@@YIXH@Z
    0x543D60 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalLinearSolidWUCV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalLinearSolidWUCV@@YIXH@Z
    0x543E80 | void __fastcall swEmitRun0_NoZOpaqueDecalLinearStippleWUCV(int) | ?swEmitRun0_NoZOpaqueDecalLinearStippleWUCV@@YIXH@Z
    0x543F60 | void __fastcall swEmitRun0_ZReadOpaqueDecalLinearStippleWUCV(int) | ?swEmitRun0_ZReadOpaqueDecalLinearStippleWUCV@@YIXH@Z
    0x544090 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalLinearStippleWUCV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleWUCV@@YIXH@Z
    0x5441D0 | void __fastcall swEmitRun0_NoZChromaDecalLinearSolidWUCV(int) | ?swEmitRun0_NoZChromaDecalLinearSolidWUCV@@YIXH@Z
    0x5442B0 | void __fastcall swEmitRun0_ZReadChromaDecalLinearSolidWUCV(int) | ?swEmitRun0_ZReadChromaDecalLinearSolidWUCV@@YIXH@Z
    0x5443E0 | void __fastcall swEmitRun0_ZReadWriteChromaDecalLinearSolidWUCV(int) | ?swEmitRun0_ZReadWriteChromaDecalLinearSolidWUCV@@YIXH@Z
    0x544520 | void __fastcall swEmitRun0_NoZChromaDecalLinearStippleWUCV(int) | ?swEmitRun0_NoZChromaDecalLinearStippleWUCV@@YIXH@Z
    0x544620 | void __fastcall swEmitRun0_ZReadChromaDecalLinearStippleWUCV(int) | ?swEmitRun0_ZReadChromaDecalLinearStippleWUCV@@YIXH@Z
    0x544770 | void __fastcall swEmitRun0_ZReadWriteChromaDecalLinearStippleWUCV(int) | ?swEmitRun0_ZReadWriteChromaDecalLinearStippleWUCV@@YIXH@Z
    0x5448C0 | void __fastcall swEmitRun0_NoZGlowDecalLinearSolidWUCV(int) | ?swEmitRun0_NoZGlowDecalLinearSolidWUCV@@YIXH@Z
    0x5449C0 | void __fastcall swEmitRun0_ZReadGlowDecalLinearSolidWUCV(int) | ?swEmitRun0_ZReadGlowDecalLinearSolidWUCV@@YIXH@Z
    0x544B00 | void __fastcall swEmitRun0_ZReadWriteGlowDecalLinearSolidWUCV(int) | ?swEmitRun0_ZReadWriteGlowDecalLinearSolidWUCV@@YIXH@Z
    0x544C40 | void __fastcall swEmitRun0_NoZGlowDecalLinearStippleWUCV(int) | ?swEmitRun0_NoZGlowDecalLinearStippleWUCV@@YIXH@Z
    0x544D40 | void __fastcall swEmitRun0_ZReadGlowDecalLinearStippleWUCV(int) | ?swEmitRun0_ZReadGlowDecalLinearStippleWUCV@@YIXH@Z
    0x544EA0 | void __fastcall swEmitRun0_ZReadWriteGlowDecalLinearStippleWUCV(int) | ?swEmitRun0_ZReadWriteGlowDecalLinearStippleWUCV@@YIXH@Z
    0x545000 | void __fastcall swEmitRun0_NoZOpaqueModulateLinearSolidWUCV(int) | ?swEmitRun0_NoZOpaqueModulateLinearSolidWUCV@@YIXH@Z
    0x5450E0 | void __fastcall swEmitRun0_ZReadOpaqueModulateLinearSolidWUCV(int) | ?swEmitRun0_ZReadOpaqueModulateLinearSolidWUCV@@YIXH@Z
    0x545220 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateLinearSolidWUCV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidWUCV@@YIXH@Z
    0x545350 | void __fastcall swEmitRun0_NoZOpaqueModulateLinearStippleWUCV(int) | ?swEmitRun0_NoZOpaqueModulateLinearStippleWUCV@@YIXH@Z
    0x545440 | void __fastcall swEmitRun0_ZReadOpaqueModulateLinearStippleWUCV(int) | ?swEmitRun0_ZReadOpaqueModulateLinearStippleWUCV@@YIXH@Z
    0x545580 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateLinearStippleWUCV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleWUCV@@YIXH@Z
    0x5456D0 | void __fastcall swEmitRun0_NoZChromaModulateLinearSolidWUCV(int) | ?swEmitRun0_NoZChromaModulateLinearSolidWUCV@@YIXH@Z
    0x5457C0 | void __fastcall swEmitRun0_ZReadChromaModulateLinearSolidWUCV(int) | ?swEmitRun0_ZReadChromaModulateLinearSolidWUCV@@YIXH@Z
    0x545900 | void __fastcall swEmitRun0_ZReadWriteChromaModulateLinearSolidWUCV(int) | ?swEmitRun0_ZReadWriteChromaModulateLinearSolidWUCV@@YIXH@Z
    0x545A40 | void __fastcall swEmitRun0_NoZChromaModulateLinearStippleWUCV(int) | ?swEmitRun0_NoZChromaModulateLinearStippleWUCV@@YIXH@Z
    0x545B40 | void __fastcall swEmitRun0_ZReadChromaModulateLinearStippleWUCV(int) | ?swEmitRun0_ZReadChromaModulateLinearStippleWUCV@@YIXH@Z
    0x545CA0 | void __fastcall swEmitRun0_ZReadWriteChromaModulateLinearStippleWUCV(int) | ?swEmitRun0_ZReadWriteChromaModulateLinearStippleWUCV@@YIXH@Z
    0x545E00 | void __fastcall swEmitRun0_NoZGlowModulateLinearSolidWUCV(int) | ?swEmitRun0_NoZGlowModulateLinearSolidWUCV@@YIXH@Z
    0x545F00 | void __fastcall swEmitRun0_ZReadGlowModulateLinearSolidWUCV(int) | ?swEmitRun0_ZReadGlowModulateLinearSolidWUCV@@YIXH@Z
    0x546040 | void __fastcall swEmitRun0_ZReadWriteGlowModulateLinearSolidWUCV(int) | ?swEmitRun0_ZReadWriteGlowModulateLinearSolidWUCV@@YIXH@Z
    0x546180 | void __fastcall swEmitRun0_NoZGlowModulateLinearStippleWUCV(int) | ?swEmitRun0_NoZGlowModulateLinearStippleWUCV@@YIXH@Z
    0x546280 | void __fastcall swEmitRun0_ZReadGlowModulateLinearStippleWUCV(int) | ?swEmitRun0_ZReadGlowModulateLinearStippleWUCV@@YIXH@Z
    0x5463E0 | void __fastcall swEmitRun0_ZReadWriteGlowModulateLinearStippleWUCV(int) | ?swEmitRun0_ZReadWriteGlowModulateLinearStippleWUCV@@YIXH@Z
    0x546540 | void __fastcall swEmitRun0_NoZOpaqueDecalParaSolidWUCV(int) | ?swEmitRun0_NoZOpaqueDecalParaSolidWUCV@@YIXH@Z
    0x546630 | void __fastcall swEmitRun0_ZReadOpaqueDecalParaSolidWUCV(int) | ?swEmitRun0_ZReadOpaqueDecalParaSolidWUCV@@YIXH@Z
    0x546780 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalParaSolidWUCV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidWUCV@@YIXH@Z
    0x5468C0 | void __fastcall swEmitRun0_NoZOpaqueDecalParaStippleWUCV(int) | ?swEmitRun0_NoZOpaqueDecalParaStippleWUCV@@YIXH@Z
    0x5469C0 | void __fastcall swEmitRun0_ZReadOpaqueDecalParaStippleWUCV(int) | ?swEmitRun0_ZReadOpaqueDecalParaStippleWUCV@@YIXH@Z
    0x546B10 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalParaStippleWUCV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleWUCV@@YIXH@Z
    0x546C70 | void __fastcall swEmitRun0_NoZChromaDecalParaSolidWUCV(int) | ?swEmitRun0_NoZChromaDecalParaSolidWUCV@@YIXH@Z
    0x546D80 | void __fastcall swEmitRun0_ZReadChromaDecalParaSolidWUCV(int) | ?swEmitRun0_ZReadChromaDecalParaSolidWUCV@@YIXH@Z
    0x546ED0 | void __fastcall swEmitRun0_ZReadWriteChromaDecalParaSolidWUCV(int) | ?swEmitRun0_ZReadWriteChromaDecalParaSolidWUCV@@YIXH@Z
    0x547020 | void __fastcall swEmitRun0_NoZChromaDecalParaStippleWUCV(int) | ?swEmitRun0_NoZChromaDecalParaStippleWUCV@@YIXH@Z
    0x547140 | void __fastcall swEmitRun0_ZReadChromaDecalParaStippleWUCV(int) | ?swEmitRun0_ZReadChromaDecalParaStippleWUCV@@YIXH@Z
    0x5472A0 | void __fastcall swEmitRun0_ZReadWriteChromaDecalParaStippleWUCV(int) | ?swEmitRun0_ZReadWriteChromaDecalParaStippleWUCV@@YIXH@Z
    0x547410 | void __fastcall swEmitRun0_NoZGlowDecalParaSolidWUCV(int) | ?swEmitRun0_NoZGlowDecalParaSolidWUCV@@YIXH@Z
    0x547530 | void __fastcall swEmitRun0_ZReadGlowDecalParaSolidWUCV(int) | ?swEmitRun0_ZReadGlowDecalParaSolidWUCV@@YIXH@Z
    0x5476A0 | void __fastcall swEmitRun0_ZReadWriteGlowDecalParaSolidWUCV(int) | ?swEmitRun0_ZReadWriteGlowDecalParaSolidWUCV@@YIXH@Z
    0x547810 | void __fastcall swEmitRun0_NoZGlowDecalParaStippleWUCV(int) | ?swEmitRun0_NoZGlowDecalParaStippleWUCV@@YIXH@Z
    0x547930 | void __fastcall swEmitRun0_ZReadGlowDecalParaStippleWUCV(int) | ?swEmitRun0_ZReadGlowDecalParaStippleWUCV@@YIXH@Z
    0x547AB0 | void __fastcall swEmitRun0_ZReadWriteGlowDecalParaStippleWUCV(int) | ?swEmitRun0_ZReadWriteGlowDecalParaStippleWUCV@@YIXH@Z
    0x547C30 | void __fastcall swEmitRun0_NoZOpaqueModulateParaSolidWUCV(int) | ?swEmitRun0_NoZOpaqueModulateParaSolidWUCV@@YIXH@Z
    0x547D30 | void __fastcall swEmitRun0_ZReadOpaqueModulateParaSolidWUCV(int) | ?swEmitRun0_ZReadOpaqueModulateParaSolidWUCV@@YIXH@Z
    0x547E90 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateParaSolidWUCV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidWUCV@@YIXH@Z
    0x547FE0 | void __fastcall swEmitRun0_NoZOpaqueModulateParaStippleWUCV(int) | ?swEmitRun0_NoZOpaqueModulateParaStippleWUCV@@YIXH@Z
    0x5480F0 | void __fastcall swEmitRun0_ZReadOpaqueModulateParaStippleWUCV(int) | ?swEmitRun0_ZReadOpaqueModulateParaStippleWUCV@@YIXH@Z
    0x548250 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateParaStippleWUCV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleWUCV@@YIXH@Z
    0x5483C0 | void __fastcall swEmitRun0_NoZChromaModulateParaSolidWUCV(int) | ?swEmitRun0_NoZChromaModulateParaSolidWUCV@@YIXH@Z
    0x5484E0 | void __fastcall swEmitRun0_ZReadChromaModulateParaSolidWUCV(int) | ?swEmitRun0_ZReadChromaModulateParaSolidWUCV@@YIXH@Z
    0x548640 | void __fastcall swEmitRun0_ZReadWriteChromaModulateParaSolidWUCV(int) | ?swEmitRun0_ZReadWriteChromaModulateParaSolidWUCV@@YIXH@Z
    0x5487A0 | void __fastcall swEmitRun0_NoZChromaModulateParaStippleWUCV(int) | ?swEmitRun0_NoZChromaModulateParaStippleWUCV@@YIXH@Z
    0x5488C0 | void __fastcall swEmitRun0_ZReadChromaModulateParaStippleWUCV(int) | ?swEmitRun0_ZReadChromaModulateParaStippleWUCV@@YIXH@Z
    0x548A30 | void __fastcall swEmitRun0_ZReadWriteChromaModulateParaStippleWUCV(int) | ?swEmitRun0_ZReadWriteChromaModulateParaStippleWUCV@@YIXH@Z
    0x548BA0 | void __fastcall swEmitRun0_NoZGlowModulateParaSolidWUCV(int) | ?swEmitRun0_NoZGlowModulateParaSolidWUCV@@YIXH@Z
    0x548CC0 | void __fastcall swEmitRun0_ZReadGlowModulateParaSolidWUCV(int) | ?swEmitRun0_ZReadGlowModulateParaSolidWUCV@@YIXH@Z
    0x548E30 | void __fastcall swEmitRun0_ZReadWriteGlowModulateParaSolidWUCV(int) | ?swEmitRun0_ZReadWriteGlowModulateParaSolidWUCV@@YIXH@Z
    0x548FA0 | void __fastcall swEmitRun0_NoZGlowModulateParaStippleWUCV(int) | ?swEmitRun0_NoZGlowModulateParaStippleWUCV@@YIXH@Z
    0x5490C0 | void __fastcall swEmitRun0_ZReadGlowModulateParaStippleWUCV(int) | ?swEmitRun0_ZReadGlowModulateParaStippleWUCV@@YIXH@Z
    0x549240 | void __fastcall swEmitRun0_ZReadWriteGlowModulateParaStippleWUCV(int) | ?swEmitRun0_ZReadWriteGlowModulateParaStippleWUCV@@YIXH@Z
    0x5493C0 | void __fastcall swEmitRun0_NoZOpaqueDecalLinearSolidCUCV(int) | ?swEmitRun0_NoZOpaqueDecalLinearSolidCUCV@@YIXH@Z
    0x5494C0 | void __fastcall swEmitRun0_ZReadOpaqueDecalLinearSolidCUCV(int) | ?swEmitRun0_ZReadOpaqueDecalLinearSolidCUCV@@YIXH@Z
    0x549620 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalLinearSolidCUCV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalLinearSolidCUCV@@YIXH@Z
    0x549770 | void __fastcall swEmitRun0_NoZOpaqueDecalLinearStippleCUCV(int) | ?swEmitRun0_NoZOpaqueDecalLinearStippleCUCV@@YIXH@Z
    0x549880 | void __fastcall swEmitRun0_ZReadOpaqueDecalLinearStippleCUCV(int) | ?swEmitRun0_ZReadOpaqueDecalLinearStippleCUCV@@YIXH@Z
    0x5499E0 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalLinearStippleCUCV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleCUCV@@YIXH@Z
    0x549B40 | void __fastcall swEmitRun0_NoZChromaDecalLinearSolidCUCV(int) | ?swEmitRun0_NoZChromaDecalLinearSolidCUCV@@YIXH@Z
    0x549C60 | void __fastcall swEmitRun0_ZReadChromaDecalLinearSolidCUCV(int) | ?swEmitRun0_ZReadChromaDecalLinearSolidCUCV@@YIXH@Z
    0x549DD0 | void __fastcall swEmitRun0_ZReadWriteChromaDecalLinearSolidCUCV(int) | ?swEmitRun0_ZReadWriteChromaDecalLinearSolidCUCV@@YIXH@Z
    0x549F40 | void __fastcall swEmitRun0_NoZChromaDecalLinearStippleCUCV(int) | ?swEmitRun0_NoZChromaDecalLinearStippleCUCV@@YIXH@Z
    0x54A070 | void __fastcall swEmitRun0_ZReadChromaDecalLinearStippleCUCV(int) | ?swEmitRun0_ZReadChromaDecalLinearStippleCUCV@@YIXH@Z
    0x54A1F0 | void __fastcall swEmitRun0_ZReadWriteChromaDecalLinearStippleCUCV(int) | ?swEmitRun0_ZReadWriteChromaDecalLinearStippleCUCV@@YIXH@Z
    0x54A370 | void __fastcall swEmitRun0_NoZGlowDecalLinearSolidCUCV(int) | ?swEmitRun0_NoZGlowDecalLinearSolidCUCV@@YIXH@Z
    0x54A4A0 | void __fastcall swEmitRun0_ZReadGlowDecalLinearSolidCUCV(int) | ?swEmitRun0_ZReadGlowDecalLinearSolidCUCV@@YIXH@Z
    0x54A620 | void __fastcall swEmitRun0_ZReadWriteGlowDecalLinearSolidCUCV(int) | ?swEmitRun0_ZReadWriteGlowDecalLinearSolidCUCV@@YIXH@Z
    0x54A790 | void __fastcall swEmitRun0_NoZGlowDecalLinearStippleCUCV(int) | ?swEmitRun0_NoZGlowDecalLinearStippleCUCV@@YIXH@Z
    0x54A8D0 | void __fastcall swEmitRun0_ZReadGlowDecalLinearStippleCUCV(int) | ?swEmitRun0_ZReadGlowDecalLinearStippleCUCV@@YIXH@Z
    0x54AA60 | void __fastcall swEmitRun0_ZReadWriteGlowDecalLinearStippleCUCV(int) | ?swEmitRun0_ZReadWriteGlowDecalLinearStippleCUCV@@YIXH@Z
    0x54ABE0 | void __fastcall swEmitRun0_NoZOpaqueModulateLinearSolidCUCV(int) | ?swEmitRun0_NoZOpaqueModulateLinearSolidCUCV@@YIXH@Z
    0x54ACF0 | void __fastcall swEmitRun0_ZReadOpaqueModulateLinearSolidCUCV(int) | ?swEmitRun0_ZReadOpaqueModulateLinearSolidCUCV@@YIXH@Z
    0x54AE50 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateLinearSolidCUCV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidCUCV@@YIXH@Z
    0x54AFB0 | void __fastcall swEmitRun0_NoZOpaqueModulateLinearStippleCUCV(int) | ?swEmitRun0_NoZOpaqueModulateLinearStippleCUCV@@YIXH@Z
    0x54B0D0 | void __fastcall swEmitRun0_ZReadOpaqueModulateLinearStippleCUCV(int) | ?swEmitRun0_ZReadOpaqueModulateLinearStippleCUCV@@YIXH@Z
    0x54B240 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateLinearStippleCUCV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleCUCV@@YIXH@Z
    0x54B3B0 | void __fastcall swEmitRun0_NoZChromaModulateLinearSolidCUCV(int) | ?swEmitRun0_NoZChromaModulateLinearSolidCUCV@@YIXH@Z
    0x54B4E0 | void __fastcall swEmitRun0_ZReadChromaModulateLinearSolidCUCV(int) | ?swEmitRun0_ZReadChromaModulateLinearSolidCUCV@@YIXH@Z
    0x54B660 | void __fastcall swEmitRun0_ZReadWriteChromaModulateLinearSolidCUCV(int) | ?swEmitRun0_ZReadWriteChromaModulateLinearSolidCUCV@@YIXH@Z
    0x54B7E0 | void __fastcall swEmitRun0_NoZChromaModulateLinearStippleCUCV(int) | ?swEmitRun0_NoZChromaModulateLinearStippleCUCV@@YIXH@Z
    0x54B920 | void __fastcall swEmitRun0_ZReadChromaModulateLinearStippleCUCV(int) | ?swEmitRun0_ZReadChromaModulateLinearStippleCUCV@@YIXH@Z
    0x54BAB0 | void __fastcall swEmitRun0_ZReadWriteChromaModulateLinearStippleCUCV(int) | ?swEmitRun0_ZReadWriteChromaModulateLinearStippleCUCV@@YIXH@Z
    0x54BC40 | void __fastcall swEmitRun0_NoZGlowModulateLinearSolidCUCV(int) | ?swEmitRun0_NoZGlowModulateLinearSolidCUCV@@YIXH@Z
    0x54BD70 | void __fastcall swEmitRun0_ZReadGlowModulateLinearSolidCUCV(int) | ?swEmitRun0_ZReadGlowModulateLinearSolidCUCV@@YIXH@Z
    0x54BEF0 | void __fastcall swEmitRun0_ZReadWriteGlowModulateLinearSolidCUCV(int) | ?swEmitRun0_ZReadWriteGlowModulateLinearSolidCUCV@@YIXH@Z
    0x54C060 | void __fastcall swEmitRun0_NoZGlowModulateLinearStippleCUCV(int) | ?swEmitRun0_NoZGlowModulateLinearStippleCUCV@@YIXH@Z
    0x54C1A0 | void __fastcall swEmitRun0_ZReadGlowModulateLinearStippleCUCV(int) | ?swEmitRun0_ZReadGlowModulateLinearStippleCUCV@@YIXH@Z
    0x54C330 | void __fastcall swEmitRun0_ZReadWriteGlowModulateLinearStippleCUCV(int) | ?swEmitRun0_ZReadWriteGlowModulateLinearStippleCUCV@@YIXH@Z
    0x54C4B0 | void __fastcall swEmitRun0_NoZOpaqueDecalParaSolidCUCV(int) | ?swEmitRun0_NoZOpaqueDecalParaSolidCUCV@@YIXH@Z
    0x54C5D0 | void __fastcall swEmitRun0_ZReadOpaqueDecalParaSolidCUCV(int) | ?swEmitRun0_ZReadOpaqueDecalParaSolidCUCV@@YIXH@Z
    0x54C750 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalParaSolidCUCV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidCUCV@@YIXH@Z
    0x54C8C0 | void __fastcall swEmitRun0_NoZOpaqueDecalParaStippleCUCV(int) | ?swEmitRun0_NoZOpaqueDecalParaStippleCUCV@@YIXH@Z
    0x54C9F0 | void __fastcall swEmitRun0_ZReadOpaqueDecalParaStippleCUCV(int) | ?swEmitRun0_ZReadOpaqueDecalParaStippleCUCV@@YIXH@Z
    0x54CB70 | void __fastcall swEmitRun0_ZReadWriteOpaqueDecalParaStippleCUCV(int) | ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleCUCV@@YIXH@Z
    0x54CD00 | void __fastcall swEmitRun0_NoZChromaDecalParaSolidCUCV(int) | ?swEmitRun0_NoZChromaDecalParaSolidCUCV@@YIXH@Z
    0x54CE40 | void __fastcall swEmitRun0_ZReadChromaDecalParaSolidCUCV(int) | ?swEmitRun0_ZReadChromaDecalParaSolidCUCV@@YIXH@Z
    0x54CFD0 | void __fastcall swEmitRun0_ZReadWriteChromaDecalParaSolidCUCV(int) | ?swEmitRun0_ZReadWriteChromaDecalParaSolidCUCV@@YIXH@Z
    0x54D160 | void __fastcall swEmitRun0_NoZChromaDecalParaStippleCUCV(int) | ?swEmitRun0_NoZChromaDecalParaStippleCUCV@@YIXH@Z
    0x54D2B0 | void __fastcall swEmitRun0_ZReadChromaDecalParaStippleCUCV(int) | ?swEmitRun0_ZReadChromaDecalParaStippleCUCV@@YIXH@Z
    0x54D450 | void __fastcall swEmitRun0_ZReadWriteChromaDecalParaStippleCUCV(int) | ?swEmitRun0_ZReadWriteChromaDecalParaStippleCUCV@@YIXH@Z
    0x54D5F0 | void __fastcall swEmitRun0_NoZGlowDecalParaSolidCUCV(int) | ?swEmitRun0_NoZGlowDecalParaSolidCUCV@@YIXH@Z
    0x54D740 | void __fastcall swEmitRun0_ZReadGlowDecalParaSolidCUCV(int) | ?swEmitRun0_ZReadGlowDecalParaSolidCUCV@@YIXH@Z
    0x54D8E0 | void __fastcall swEmitRun0_ZReadWriteGlowDecalParaSolidCUCV(int) | ?swEmitRun0_ZReadWriteGlowDecalParaSolidCUCV@@YIXH@Z
    0x54DA70 | void __fastcall swEmitRun0_NoZGlowDecalParaStippleCUCV(int) | ?swEmitRun0_NoZGlowDecalParaStippleCUCV@@YIXH@Z
    0x54DBD0 | void __fastcall swEmitRun0_ZReadGlowDecalParaStippleCUCV(int) | ?swEmitRun0_ZReadGlowDecalParaStippleCUCV@@YIXH@Z
    0x54DD80 | void __fastcall swEmitRun0_ZReadWriteGlowDecalParaStippleCUCV(int) | ?swEmitRun0_ZReadWriteGlowDecalParaStippleCUCV@@YIXH@Z
    0x54DF30 | void __fastcall swEmitRun0_NoZOpaqueModulateParaSolidCUCV(int) | ?swEmitRun0_NoZOpaqueModulateParaSolidCUCV@@YIXH@Z
    0x54E060 | void __fastcall swEmitRun0_ZReadOpaqueModulateParaSolidCUCV(int) | ?swEmitRun0_ZReadOpaqueModulateParaSolidCUCV@@YIXH@Z
    0x54E1F0 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateParaSolidCUCV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidCUCV@@YIXH@Z
    0x54E370 | void __fastcall swEmitRun0_NoZOpaqueModulateParaStippleCUCV(int) | ?swEmitRun0_NoZOpaqueModulateParaStippleCUCV@@YIXH@Z
    0x54E4B0 | void __fastcall swEmitRun0_ZReadOpaqueModulateParaStippleCUCV(int) | ?swEmitRun0_ZReadOpaqueModulateParaStippleCUCV@@YIXH@Z
    0x54E640 | void __fastcall swEmitRun0_ZReadWriteOpaqueModulateParaStippleCUCV(int) | ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleCUCV@@YIXH@Z
    0x54E7E0 | void __fastcall swEmitRun0_NoZChromaModulateParaSolidCUCV(int) | ?swEmitRun0_NoZChromaModulateParaSolidCUCV@@YIXH@Z
    0x54E930 | void __fastcall swEmitRun0_ZReadChromaModulateParaSolidCUCV(int) | ?swEmitRun0_ZReadChromaModulateParaSolidCUCV@@YIXH@Z
    0x54EAD0 | void __fastcall swEmitRun0_ZReadWriteChromaModulateParaSolidCUCV(int) | ?swEmitRun0_ZReadWriteChromaModulateParaSolidCUCV@@YIXH@Z
    0x54EC70 | void __fastcall swEmitRun0_NoZChromaModulateParaStippleCUCV(int) | ?swEmitRun0_NoZChromaModulateParaStippleCUCV@@YIXH@Z
    0x54EDD0 | void __fastcall swEmitRun0_ZReadChromaModulateParaStippleCUCV(int) | ?swEmitRun0_ZReadChromaModulateParaStippleCUCV@@YIXH@Z
    0x54EF80 | void __fastcall swEmitRun0_ZReadWriteChromaModulateParaStippleCUCV(int) | ?swEmitRun0_ZReadWriteChromaModulateParaStippleCUCV@@YIXH@Z
    0x54F130 | void __fastcall swEmitRun0_NoZGlowModulateParaSolidCUCV(int) | ?swEmitRun0_NoZGlowModulateParaSolidCUCV@@YIXH@Z
    0x54F280 | void __fastcall swEmitRun0_ZReadGlowModulateParaSolidCUCV(int) | ?swEmitRun0_ZReadGlowModulateParaSolidCUCV@@YIXH@Z
    0x54F420 | void __fastcall swEmitRun0_ZReadWriteGlowModulateParaSolidCUCV(int) | ?swEmitRun0_ZReadWriteGlowModulateParaSolidCUCV@@YIXH@Z
    0x54F5B0 | void __fastcall swEmitRun0_NoZGlowModulateParaStippleCUCV(int) | ?swEmitRun0_NoZGlowModulateParaStippleCUCV@@YIXH@Z
    0x54F710 | void __fastcall swEmitRun0_ZReadGlowModulateParaStippleCUCV(int) | ?swEmitRun0_ZReadGlowModulateParaStippleCUCV@@YIXH@Z
    0x54F8C0 | void __fastcall swEmitRun0_ZReadWriteGlowModulateParaStippleCUCV(int) | ?swEmitRun0_ZReadWriteGlowModulateParaStippleCUCV@@YIXH@Z
    0x652348 | struct swEmitterSet swCurrentEmitterSet | ?swCurrentEmitterSet@@3UswEmitterSet@@A
*/

// ?swEmitRun0_NoZChromaDecalLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalParaSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalParaSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalParaSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalParaSolidWUWV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalParaStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalParaStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalParaStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZChromaDecalParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaDecalParaStippleWUWV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateParaSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateParaSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateParaSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateParaSolidWUWV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateParaStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateParaStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateParaStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZChromaModulateParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZChromaModulateParaStippleWUWV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalParaSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalParaSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalParaSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalParaSolidWUWV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalParaStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalParaStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalParaStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZGlowDecalParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowDecalParaStippleWUWV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateParaSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateParaSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateParaSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateParaSolidWUWV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateParaStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateParaStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateParaStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZGlowModulateParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZGlowModulateParaStippleWUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalParaSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalParaSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalParaSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalParaSolidWUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalParaStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalParaStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalParaStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueDecalParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueDecalParaStippleWUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateParaSolidCUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateParaSolidCUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateParaSolidWUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateParaSolidWUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateParaStippleCUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateParaStippleCUWV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateParaStippleWUCV(i32 arg1);

// ?swEmitRun0_NoZOpaqueModulateParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_NoZOpaqueModulateParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaDecalParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaDecalParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadChromaModulateParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadChromaModulateParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowDecalParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowDecalParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadGlowModulateParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadGlowModulateParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueDecalParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueDecalParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadOpaqueModulateParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadOpaqueModulateParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaDecalParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaDecalParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteChromaModulateParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteChromaModulateParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowDecalParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowDecalParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteGlowModulateParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteGlowModulateParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueDecalParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueDecalParaStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateLinearSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateLinearSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateLinearSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateLinearSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateLinearStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateLinearStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateLinearStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateLinearStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateLinearStippleWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateParaSolidCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateParaSolidCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateParaSolidWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateParaSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateParaSolidWUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleCUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateParaStippleCUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleCUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateParaStippleCUWV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleWUCV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateParaStippleWUCV(i32 arg1);

// ?swEmitRun0_ZReadWriteOpaqueModulateParaStippleWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun0_ZReadWriteOpaqueModulateParaStippleWUWV(i32 arg1);

// ?swEmitRun1_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun1_NoZOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun1_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun1_ZReadWriteOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun2_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun2_NoZOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun2_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun2_ZReadWriteOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun3_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun3_NoZOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun3_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun3_ZReadWriteOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun4_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun4_NoZOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun4_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun4_ZReadWriteOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun5_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun5_NoZOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun5_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun5_ZReadWriteOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun6_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun6_NoZOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun6_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun6_ZReadWriteOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun7_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun7_NoZOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun7_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun7_ZReadWriteOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun8_NoZOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun8_NoZOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swEmitRun8_ZReadWriteOpaqueDecalLinearSolidWUWV@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL swEmitRun8_ZReadWriteOpaqueDecalLinearSolidWUWV(i32 arg1);

// ?swCurrentEmitterSet@@3UswEmitterSet@@A
ARTS_IMPORT extern struct swEmitterSet swCurrentEmitterSet;
