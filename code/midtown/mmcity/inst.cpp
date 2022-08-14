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

define_dummy_symbol(mmcity_inst);

#include "inst.h"

#include "agi/viewport.h"
#include "agiworld/meshset.h"
#include "agiworld/quality.h"
#include "arts7/sim.h"
#include "heap.h"
#include "mmcity/cullcity.h"
#include "mmcity/renderweb.h"

f32 mmInstance::LodTable[3 /*Inst Type*/][4 /*Terrain Quality*/][3 /*Lod Dist*/] {
    {
        // FACADES
        {200.0f, 150.0f, 100.0f},
        {350.0f, 250.0f, 150.0f},
        {700.0f, 500.0f, 300.0f},
        {700.0f, 500.0f, 300.0f},
    },
    {
        // BANGERS
        {100.0f, 50.0f, 20.0f},
        {150.0f, 85.0f, 35.0f},
        {250.0f, 160.0f, 60.0f},
        {250.0f, 200.0f, 150.0f},
    },
    {
        // UPPERS
        {9999.0f, 0.0f, 0.0f},
        {9999.0f, 100.0f, 0.0f},
        {9999.0f, 500.0f, 300.0f},
        {9999.0f, 600.0f, 400.0f},
    },
};

mmPhysEntity* mmInstance::GetEntity()
{
    return nullptr;
}

mmPhysEntity* mmInstance::AttachEntity()
{
    return nullptr;
}

Vector3 mmInstance::GetVelocity()
{
    return Vector3(0.0f, 0.0f, 0.0f);
}

void mmInstance::Impact(mmInstance* /*arg1*/, Vector3* /*arg2*/)
{}

void mmInstance::Detach()
{}

void mmInstance::Draw(i32 lod)
{
    if (Sim()->IsDebugDrawEnabled())
        return;

    if (agiMeshSet* mesh = GetResidentMeshSet(lod, 0))
    {
        Matrix34 matrix;
        Viewport()->SetWorld(ToMatrix(matrix));

        mesh->Draw(MESH_DRAW_CLIP);
    }
}

void mmInstance::DrawShadow()
{}

void mmInstance::DrawGlow()
{}

void mmInstance::Relight()
{}

u32 mmInstance::SizeOf()
{
    return sizeof(*this);
}

void mmInstance::Reset()
{}

b32 mmInstance::Init(
    aconst char* /*name*/, Vector3& /*pos1*/, Vector3& /*pos2*/, i32 /*init_flags*/, aconst char* /*part*/)
{
    return false;
}

f32 mmInstance::GetScale()
{
    return 1.0f;
}

i32 mmInstance::ComputeLod(f32 dist, f32 scale)
{
    f32 scaled = dist * scale;

    f32* lods = LodTable[LodTableIndex][agiRQ.TerrainQuality];

    if (scaled >= lods[0])
        return 0;

    if (scaled >= lods[1])
        return 1;

    if (scaled >= lods[2])
        return 2;

    return 3;
}

void mmInstance::AddMeshes(aconst char* name, i32 mesh_flags, aconst char* part, Vector3* offset)
{
    GetMeshSetSet(name, mesh_flags, part, offset);
}

// ?MatrixFromPoints@@YAXAAVMatrix34@@AAVVector3@@1M@Z
ARTS_IMPORT /*static*/ void MatrixFromPoints(Matrix34& arg1, Vector3& arg2, Vector3& arg3, f32 arg4);

mmMatrixInstance::mmMatrixInstance()
    : Matrix(IDENTITY)
{
    // mmMatrixInstances don't have an underlying entity, and colliding with one (i.e the el_train) will just crash.
    // Flags |= INST_FLAG_COLLIDER;
}

void mmMatrixInstance::Hit(mmInstance* /*arg1*/)
{}

#ifdef ARTS_DEV_BUILD
void mmMatrixInstance::AddWidgets(Bank* /*arg1*/)
{}
#endif

void mmMatrixInstance::FromMatrix(const Matrix34& matrix)
{
    Matrix = matrix;
}

Vector3& mmMatrixInstance::GetPos()
{
    return Matrix.m3;
}

u32 mmMatrixInstance::SizeOf()
{
    return sizeof(*this);
}

Matrix34& mmMatrixInstance::ToMatrix([[maybe_unused]] Matrix34& matrix)
{
    return Matrix;
}

void mmStaticInstance::Relight()
{}

agiMeshSet* mmInstance::GetResidentMeshSet(i32 lod, i32 index, i32 variant)
{
    agiMeshSet* mesh = nullptr;

    if (MeshSetTableEntry* entry = GetMeshBase(index))
    {
        if (mesh = entry->Meshes[lod]; mesh && !mesh->IsFullyResident(variant))
        {
            if (lod)
            {
                if (agiMeshSet* low = entry->Meshes[lod - 1]; low && low->IsFullyResident(variant))
                    return low;
            }
        }
    }

    return mesh;
}

void mmInstance::InitMeshes(aconst char* name, i32 mesh_flags, aconst char* part, Vector3* offset)
{
    if (Flags & (INST_FLAG_COLLIDER | INST_FLAG_MOVER | INST_FLAG_40))
        mesh_flags |= MESH_SET_UV | MESH_SET_NORMAL | MESH_SET_CPV;
    else
        mesh_flags |= MESH_SET_UV | MESH_SET_NO_BOUND;

    MeshIndex = static_cast<u16>(GetMeshSetSet(name, mesh_flags, part, offset));
}

void* mmInstance::operator new(std::size_t size)
{
    return mmInstanceHeap.Allocate(size);
}

void mmInstance::operator delete(void* ptr)
{
    mmInstanceHeap.Free(ptr);
}

void mmBuildingInstance::Draw(i32 lod)
{
    enum
    {
        MESH_FACADE = 0,
        MESH_GRND = 1,
    };

    if (Sim()->IsDebugDrawEnabled())
        return;

    Matrix34 world;
    Viewport()->SetWorld(ToMatrix(world));

    if (asRenderWeb::PassMask & RENDER_PASS_TERRAIN)
    {
        if (agiMeshSet* mesh = GetMeshSet(INST_LOD_HIGH, MESH_GRND))
            mesh->DrawLitEnv(DynamicLighter, CullCity()->ShadowMap, CullCity()->EnvMatrix, MESH_DRAW_CLIP);
    }

    if (asRenderWeb::PassMask & RENDER_PASS_BUILDINGS)
    {
        if (agiMeshSet* mesh = GetResidentMeshSet(std::max(lod, INST_LOD_LOW), MESH_FACADE))
            mesh->DrawLit(StaticLighter, MESH_DRAW_CLIP, nullptr);
    }
}
