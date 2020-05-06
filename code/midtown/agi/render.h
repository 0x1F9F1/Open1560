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
    agi:render

    0x55DD80 | public: __thiscall agiRenderer::agiRenderer(void) | ??0agiRenderer@@QAE@XZ
    0x907868 | struct agiCardStateStruct agiLastCardState | ?agiLastCardState@@3UagiCardStateStruct@@A
    0x907898 | class agiCardState agiCurCardState | ?agiCurCardState@@3VagiCardState@@A
*/

// 0x907898 | ?agiCurCardState@@3VagiCardState@@A
inline extern_var(0x907898, class agiCardState, agiCurCardState);

// 0x907868 | ?agiLastCardState@@3UagiCardStateStruct@@A
inline extern_var(0x907868, struct agiCardStateStruct, agiLastCardState);
