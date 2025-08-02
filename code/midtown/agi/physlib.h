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

#include "agilib.h"

#include "physdef.h"

// ?agiPhysLib@@3V?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@A
ARTS_EXPORT extern agiLib<agiPhysParameters, agiPhysDef> agiPhysLib;

check_size(agiPhysLib, 0x4014);

#define PHYS_DB_BENCH 1
#define PHYS_DB_BF010_C 2
#define PHYS_DB_BF011_C 3
#define PHYS_DB_BF012_C 4
#define PHYS_DB_BF013_C 5
#define PHYS_DB_BF014_C 6
#define PHYS_DB_BF015_C 7
#define PHYS_DB_BF016_C 8
#define PHYS_DB_BF01_D 9
#define PHYS_DB_BF01_DS 10
#define PHYS_DB_BF01_I 11
#define PHYS_DB_BF01_O 12
#define PHYS_DB_BF02_D 13
#define PHYS_DB_BF02_DS 14
#define PHYS_DB_BF02_I 15
#define PHYS_DB_BF02_O 16
#define PHYS_DB_BF03_C 17
#define PHYS_DB_BF03_D 18
#define PHYS_DB_BF03_DS 19
#define PHYS_DB_BF03_I 20
#define PHYS_DB_BF03_O 21
#define PHYS_DB_BF03_W 22
#define PHYS_DB_BF04_C 23
#define PHYS_DB_BF04_D 24
#define PHYS_DB_BF04_I 25
#define PHYS_DB_BF04_O 26
#define PHYS_DB_BF04_W 27
#define PHYS_DB_BF05_C 28
#define PHYS_DB_BF05_D 29
#define PHYS_DB_BF05_I 30
#define PHYS_DB_BF06 31
#define PHYS_DB_BF06_C 32
#define PHYS_DB_BF06_D 33
#define PHYS_DB_BF07_C 34
#define PHYS_DB_BF07_D 35
#define PHYS_DB_BUSH 36
#define PHYS_DB_DIRT 37
#define PHYS_DB_FACADE_SF2 38
#define PHYS_DB_FIREHY 39
#define PHYS_DB_FLAGSTONE 40
#define PHYS_DB_GRASS1 41
#define PHYS_DB_LANDMARK 42
#define PHYS_DB_LIGHT01 43
#define PHYS_DB_LIGHT02 44
#define PHYS_DB_LIGHTTP 45
#define PHYS_DB_LIGHTTS 46
#define PHYS_DB_LMOSQR_GRND 47
#define PHYS_DB_LMPARK_GRASS 48
#define PHYS_DB_MBOX 49
#define PHYS_DB_NEW2 50
#define PHYS_DB_P_BMAN 51
#define PHYS_DB_P_DINE 52
#define PHYS_DB_P_TCOP 53
#define PHYS_DB_P_TWAIT 54
#define PHYS_DB_P_WWMN 55
#define PHYS_DB_PMETER 56
#define PHYS_DB_R1 57
#define PHYS_DB_R2 58
#define PHYS_DB_R2C 59
#define PHYS_DB_R2I 60
#define PHYS_DB_R4 61
#define PHYS_DB_R6 62
#define PHYS_DB_R8 63
#define PHYS_DB_RD1RR_TRACK 64
#define PHYS_DB_RD2LANE_COB 65
#define PHYS_DB_RD2LANE_IND 66
#define PHYS_DB_RD2LANEP 67
#define PHYS_DB_RD4LANEP 68
#define PHYS_DB_RD4LANEPI 69
#define PHYS_DB_RF08 70
#define PHYS_DB_RF10 71
#define PHYS_DB_RFWY 72
#define PHYS_DB_RINTER 73
#define PHYS_DB_RWALK 74
#define PHYS_DB_SDWLK 75
#define PHYS_DB_SGN_OW 76
#define PHYS_DB_SGN_SL 77
#define PHYS_DB_SGN_ST 78
#define PHYS_DB_SGN_STP 79
#define PHYS_DB_SGN_XW 80
#define PHYS_DB_SHRSE 81
#define PHYS_DB_SHRUB 82
#define PHYS_DB_SIGN_CONST 83
#define PHYS_DB_SIGN_DEADEND 84
#define PHYS_DB_SIGN_STOP 85
#define PHYS_DB_SIGN_STOPLIGHT 86
#define PHYS_DB_T_GRASS 87
#define PHYS_DB_T_STEP_SIDE 88
#define PHYS_DB_T_STEP_TOP 89
#define PHYS_DB_T_WALK_ALLEY 90
#define PHYS_DB_T_WATER 91
#define PHYS_DB_TBPARK03GRASS 92
#define PHYS_DB_TCANM 93
#define PHYS_DB_TEST1 94
#define PHYS_DB_TEST2 95
#define PHYS_DB_TEST3 96
#define PHYS_DB_TEST4 97
#define PHYS_DB_WPOBJ 98
