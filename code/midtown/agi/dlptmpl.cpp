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

define_dummy_symbol(agi_dlptmpl);

#include "dlptmpl.h"

#include "data7/hash.h"
#include "stream/stream.h"

#include "mtllib.h"
#include "physlib.h"
#include "texlib.h"

DLPTemplate::DLPTemplate(char* name)
    : Name(name)
{
    DLPTemplateHash.Insert(Name.get(), this);
}

DLPTemplate::~DLPTemplate()
{
    DLPTemplateHash.Delete(Name.get());
}

i32 DLPTemplate::Load(char* path)
{
    Ptr<Stream> input {arts_fopen(path, "r")};

    if (input == nullptr)
        return -1;

    Load(input.get());

    return 0;
}

void DLPTemplate::Load(Stream* file)
{
    if (u32 magic = file->Get<u32>(); magic != 'DLP7')
        Quitf("Not a valid .dlp file, or old version.");

    NumGroups = file->Get<u32>();
    NumPatches = file->Get<u32>();
    NumVertices = file->Get<u32>();

    Init(NumGroups, NumPatches, NumVertices);

    for (i32 i = 0; i < NumGroups; ++i)
        Groups[i].Load(file);

    for (i32 i = 0; i < NumPatches; ++i)
        Patches[i].Load(file);

    file->GetN<Vector3>(Vertices.get(), NumVertices);

    agiLib<agiMtlParameters, agiMtlDef> mlib("MLib");
    mlib.Load(file);

    agiLib<agiTexParameters, agiTexDef> tlib("TLib");
    tlib.Load(file);

    agiLib<agiPhysParameters, agiPhysDef> plib("PLib");
    plib.Load(file);

    InitRemap(mlib, tlib, plib);
}

void DLPPatch::Load(Stream* file)
{
    SRes = file->Get<u16>();
    TRes = file->Get<u16>();
    VertexCount = SRes * TRes;
    Flags = file->Get<u16>() & ~0x1;
    ROpts = file->Get<u16>();
    MtlIdx = file->Get<u16>();
    TexIdx = file->Get<u16>();
    PhysIdx = file->Get<u16>();

    Vertices = MakeUnique<DLPVertex[]>(VertexCount);

    for (i32 i = 0; i < VertexCount; ++i)
        Vertices[i].Load(file);

    Name = file->GetString();
}

void DLPVertex::Load(Stream* file)
{
    Id = file->Get<u16>();
    Position = file->Get<Vector3>();
    UV = file->Get<Vector2>();

    u32 color = file->Get<u32>();

    Color = Vector4(((color >> 16) & 0xFF) / 255.0f, ((color >> 8) & 0xFF) / 255.0f, (color & 0xFF) / 255.0f,
        (color >> 24) / 255.0f);
}
