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
#include "agiworld/texsort.h"
#include "arts7/sim.h"
#include "data7/metadefine.h"
#include "heap.h"
#include "mmcity/cullcity.h"
#include "mmcity/renderweb.h"
#include "stream/problems.h"

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

i32 mmInstance::LodTableIndex = 0;

mmInstance::MeshSetTableEntry mmInstance::MeshSetTable[MaxMeshSetSets] {};
char* mmInstance::MeshSetNames[MaxMeshSetSets] {};
i32 mmInstance::MeshSetSetCount = 0;

b32 mmInstance::ShowLights = false;
void (*mmInstance::StaticLighter)(u8*, u32*, u32*, agiMeshSet*) = nullptr;

mmHeap<i32> mmInstanceHeap {};

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

usize mmInstance::SizeOf()
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

mmFacadeQuad::mmFacadeQuad(agiMeshSet* mesh, f32 min_y, f32 min_z)
    : MinY(min_y)
    , MinZ(min_z)
{
    u16* idx = mesh->VertexIndices;
    Vector3* verts = mesh->Vertices;
    Vector2* uvs = mesh->TexCoords;

    Vector3* v0 = &verts[idx[0]];
    Vector3* v1 = &verts[idx[1]];
    Vector3* v2 = &verts[idx[2]];

    // UV Jacobian: partial derivatives of U,V with respect to vertex Y and Z
    f32 dy10 = v1->y - v0->y;
    f32 dz10 = v1->z - v0->z;
    f32 dy20 = v2->y - v0->y;
    f32 dz20 = v2->z - v0->z;
    f32 inv_det = 1.0f / (dy20 * dz10 - dz20 * dy10);

    f32 du10 = uvs[1].x - uvs[0].x, dv10 = uvs[1].y - uvs[0].y;
    f32 du20 = uvs[2].x - uvs[0].x, dv20 = uvs[2].y - uvs[0].y;

    f32 dU_dY = (du10 * dy20 - du20 * dy10) * inv_det;
    f32 dU_dZ = (du20 * dz10 - du10 * dz20) * inv_det;
    f32 dV_dY = (dv10 * dy20 - dv20 * dy10) * inv_det;
    f32 dV_dZ = (dv20 * dz10 - dv10 * dz20) * inv_det;

    for (i32 i = 0; i < 4; ++i)
    {
        Vector3* vt = &verts[idx[i]];
        f32 u = uvs[i].x;
        f32 v = uvs[i].y;

        if (min_y != 0.0f && vt->y < min_y)
        {
            f32 dy = min_y - vt->y;
            u += dy * dU_dY;
            v += dy * dV_dY;
        }

        if (min_z != 0.0f && vt->z < min_z)
        {
            f32 dz = min_z - vt->z;
            u += dz * dU_dZ;
            v += dz * dV_dZ;
        }

        Tex[i][0] = static_cast<i16>(static_cast<i32>(u * 256.0f));
        Tex[i][1] = static_cast<i16>(static_cast<i32>(v * 256.0f));
    }
}

void mmFacadeQuad::DrawLit(agiMeshLighter lighter, agiMeshSet* mesh)
{
    if (!mesh->LockIfResident())
    {
        mesh->PageIn();
        return;
    }

    Vector3 verts[4];
    Vector2 tex_coords[4];
    u32 colors[4];

    for (i32 i = 0; i < 4; ++i)
    {
        u16 vi = mesh->VertexIndices[i];
        verts[i] = mesh->Vertices[vi];

        if (MinY != 0.0f && verts[i].y < MinY)
            verts[i].y = MinY;
        if (MinZ != 0.0f && verts[i].z < MinZ)
            verts[i].z = MinZ;

        tex_coords[i].x = static_cast<f32>(Tex[i][0]) * 0.00390625f;
        tex_coords[i].y = static_cast<f32>(Tex[i][1]) * 0.00390625f;
    }

    if (mesh->Geometry(MESH_DRAW_CLIP, verts, mesh->Planes) <= 255)
    {
        if (lighter)
        {
            lighter(nullptr, colors, mesh->Colors, mesh);
            mesh->FirstPass(colors, tex_coords, 0);
        }
        else
        {
            mesh->FirstPass(mesh->Colors, tex_coords, 0xFFFFFFFF);
        }
    }

    mesh->Unlock();
}

f32 mmFacadeQuad::DoubleArea(agiMeshSet* mesh)
{
    u16* idx = mesh->VertexIndices;
    Vector3* v0 = &mesh->Vertices[idx[0]];
    Vector3* v1 = &mesh->Vertices[idx[1]];
    Vector3* v2 = &mesh->Vertices[idx[2]];

    // X component of (v2-v0) x (v1-v0) = area in the YZ plane
    return ((*v2 - *v0) % (*v1 - *v0)).x;
}

i32 mmFacadeQuad::Valid(agiMeshSet* mesh)
{
    return std::fabs(DoubleArea(mesh)) > 1.0f;
}

mmFacadeInstance::mmFacadeInstance() = default;

mmFacadeInstance::~mmFacadeInstance()
{
    delete LeftSideQuad;
    delete RightSideQuad;
}

void mmFacadeInstance::Draw(i32 lod)
{
    enum
    {
        MESH_FACADE = 0,
        MESH_LEFT = 1,
        MESH_RIGHT = 2,
        MESH_GRND = 3,
        MESH_TOP = 4,
        MESH_BACK = 5,
    };

    if (Sim()->IsDebugDrawEnabled())
        return;

    Matrix34 world;
    Viewport()->SetWorld(ToMatrix(world));

#ifdef ARTS_DEV_BUILD
    i32 tri_before = agiPolySet::TriCount;
#endif

    if (asRenderWeb::PassMask & RENDER_PASS_TERRAIN)
    {
        if (agiMeshSet* grnd = GetMeshSet(INST_LOD_HIGH, MESH_GRND))
            grnd->DrawLitEnv(StaticLighter, CullCity()->ShadowMap, CullCity()->EnvMatrix, MESH_DRAW_CLIP);

        if (SubType & INST_INIT_FLAG_FCD_TOP)
        {
            if (agiMeshSet* top = GetMeshSet(INST_LOD_HIGH, MESH_TOP))
                top->DrawLitEnv(StaticLighter, CullCity()->ShadowMap, CullCity()->EnvMatrix, MESH_DRAW_CLIP);
        }
    }

    if (asRenderWeb::PassMask & RENDER_PASS_BUILDINGS)
    {
        if (agiMeshSet* facade = GetResidentMeshSet(lod, MESH_FACADE))
            facade->DrawLit(StaticLighter, MESH_DRAW_CLIP, nullptr);

        if (SubType & INST_INIT_FLAG_FCD_LEFT)
        {
            if (agiMeshSet* left = GetMeshSet(INST_LOD_HIGH, MESH_LEFT))
            {
#ifdef ARTS_DEV_BUILD
                if (LeftSideQuad && EnableFacadeSideClipping)
                    LeftSideQuad->DrawLit(StaticLighter, left);
                else
#endif
                    left->DrawLit(StaticLighter, MESH_DRAW_CLIP, nullptr);
            }
        }

        if (SubType & INST_INIT_FLAG_FCD_RIGHT)
        {
            if (agiMeshSet* right = GetMeshSet(INST_LOD_HIGH, MESH_RIGHT))
            {
#ifdef ARTS_DEV_BUILD
                if (RightSideQuad && EnableFacadeSideClipping)
                    RightSideQuad->DrawLit(StaticLighter, right);
                else
#endif
                    right->DrawLit(StaticLighter, MESH_DRAW_CLIP, nullptr);
            }
        }

        // Owner & 4 checks INST_INIT_FLAG_FCD_BACK (0x400) stored in the high byte of flags
        if (Owner & (INST_INIT_FLAG_FCD_BACK >> 8))
        {
            if (agiMeshSet* back = GetMeshSet(INST_LOD_HIGH, MESH_BACK))
                back->DrawLit(StaticLighter, MESH_DRAW_CLIP, nullptr);
        }
    }

#ifdef ARTS_DEV_BUILD
    facadeTriCount += agiPolySet::TriCount - tri_before;
#endif
}

f32 mmFacadeInstance::GetScale()
{
    return Scale;
}

b32 mmFacadeInstance::InitFacade(
    char* name, Vector3& start, Vector3& end, f32 scale_param, i32 flags, const Vector3& sides)
{
    InitMeshes(name, MESH_SET_UV | MESH_SET_NORMAL | MESH_SET_CPV | MESH_SET_NO_BOUND, "FACADE"_xconst, nullptr);
    if (!MeshIndex)
    {
        InitMeshes(name, MESH_SET_UV | MESH_SET_NORMAL | MESH_SET_CPV | MESH_SET_NO_BOUND, "BLDG"_xconst, nullptr);
        if (!MeshIndex)
        {
            RegisterProblem("No FACADE or BLDG group in facade", name, nullptr);
            return 0;
        }
    }

    Matrix34 mat;
    MatrixFromPoints(mat, start, end, scale_param);
    FromMatrix(mat);

    Scale = std::max({mat.m0.Mag(), mat.m1.Mag(), mat.m2.Mag()});

    AddMeshes(name, MESH_SET_UV | MESH_SET_NORMAL | MESH_SET_CPV | MESH_SET_NO_BOUND, "LEFT"_xconst, nullptr);
    AddMeshes(name, MESH_SET_UV | MESH_SET_NORMAL | MESH_SET_CPV | MESH_SET_NO_BOUND, "RIGHT"_xconst, nullptr);
    AddMeshes(name, MESH_SET_UV | MESH_SET_NORMAL | MESH_SET_CPV | MESH_SET_NO_BOUND, "GRND"_xconst, nullptr);
    AddMeshes(name, MESH_SET_UV | MESH_SET_NORMAL | MESH_SET_CPV | MESH_SET_NO_BOUND, "TOP"_xconst, nullptr);
    AddMeshes(name, MESH_SET_UV | MESH_SET_NORMAL | MESH_SET_CPV | MESH_SET_NO_BOUND, "BACK"_xconst, nullptr);

    SubType = static_cast<u8>(flags);
    Owner = static_cast<u8>(flags >> 8);

    // Left side quad (LEFT mesh at slot MeshIndex+0, LOD_HIGH)
    LeftSideQuad = nullptr;
    if (sides.x != 0.0f || sides.z != 0.0f)
    {
        if (agiMeshSet* left = MeshIndex ? MeshSetTable[MeshIndex].Meshes[INST_LOD_HIGH] : nullptr)
        {
            left->MakeResident();
            if (left->VertexCount == 4 && left->SurfaceCount == 1 && mmFacadeQuad::Valid(left))
                LeftSideQuad = new mmFacadeQuad(left, sides.x, sides.z);
            else
                RegisterProblem("Bad left-side quad", name, nullptr);
            left->Unlock();
        }
        else
        {
            RegisterProblem("Missing left-side quad", name, nullptr);
        }
    }

    // Right side quad (RIGHT mesh at slot MeshIndex+1, LOD_HIGH)
    RightSideQuad = nullptr;
    if (sides.y != 0.0f || sides.z != 0.0f)
    {
        if (agiMeshSet* right = MeshIndex ? MeshSetTable[MeshIndex + 1].Meshes[INST_LOD_HIGH] : nullptr)
        {
            right->MakeResident();
            if (right->VertexCount == 4 && right->SurfaceCount == 1 && mmFacadeQuad::Valid(right))
                RightSideQuad = new mmFacadeQuad(right, sides.y, sides.z);
            else
                RegisterProblem("Bad right-side quad", name, nullptr);
            right->Unlock();
        }
        else
        {
            RegisterProblem("Missing right-side quad", name, nullptr);
        }
    }

    return 1;
}

usize mmFacadeInstance::SizeOf()
{
    return sizeof(*this);
}

void mmFacadeInstance::DeclareFields()
{
    mmStaticInstance::DeclareFields();
}
