import struct
import math

def read_unpack(file, fmt):
    return struct.unpack(fmt, file.read(struct.calcsize(fmt)))

def write_pack(file, fmt, *args):
    file.write(struct.pack(fmt, *args))

class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def read(file):
        return Vector2(*read_unpack(file, '<2f'))

    def readn(file, count):
        return [ Vector2.read(file) for _ in range(count) ]

    def write(self, file):
        write_pack(file, '<2f', self.x, self.y)

    def __repr__(self):
        return '{{{:f},{:f}}}'.format(self.x, self.y)

    def __add__(self, other):
        return Vector2(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector2(self.x - other.x, self.y - other.y)

    def __mul__(self, other):
        return Vector2(self.x * other, self.y * other)

    def __truediv__(self, other):
        return Vector2(self.x / other, self.y / other)

    def __eq__(self, other):
        return (self.x, self.y) == (other.x, other.y)

    def __hash__(self):
        return hash((self.x, self.y))

    def tuple(self):
        return (self.x, self.y)

    def Cross(self, rhs=None):
        if rhs is None:
            return Vector2(self.y, -self.x)

        return (self.x*rhs.y) - (self.y*rhs.x)

    def Dot(self, rhs):
        return (self.x * rhs.x) + (self.y * rhs.y)

    def Mag2(self):
        return (self.x * self.x) + (self.y * self.y)

    def Normalize(self):
        return self * (self.Mag2() ** -0.5)

    def Dist2(self, other):
        return (other - self).Mag2()

    def Dist(self, other):
        return self.Dist2(other) ** 0.5

class Vector3:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def read(file):
        return Vector3(*read_unpack(file, '<3f'))

    def readn(file, count):
        return [ Vector3.read(file) for _ in range(count) ]

    def write(self, file):
        write_pack(file, '<3f', self.x, self.y, self.z)

    def __repr__(self):
        return '{{{:f},{:f},{:f}}}'.format(self.x, self.y, self.z)

    def __add__(self, other):
        return Vector3(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Vector3(self.x - other.x, self.y - other.y, self.z - other.z)

    def __mul__(self, other):
        return Vector3(self.x * other, self.y * other, self.z * other)

    def __truediv__(self, other):
        return Vector3(self.x / other, self.y / other, self.z / other)

    def __eq__(self, other):
        return (self.x, self.y, self.z) == (other.x, other.y, other.z)

    def __hash__(self):
        return hash((self.x, self.y, self.z))

    def tuple(self):
        return (self.x, self.y, self.z)

    def Cross(self, rhs):
        return Vector3(self.y * rhs.z - self.z * rhs.y, self.z * rhs.x - self.x * rhs.z, self.x * rhs.y - self.y * rhs.x)

    def Dot(self, rhs):
        return (self.x * rhs.x) + (self.y * rhs.y) + (self.z * rhs.z)

    def Mag2(self):
        return (self.x * self.x) + (self.y * self.y) + (self.z * self.z)

    def Normalize(self):
        return self * (self.Mag2() ** -0.5)

    def Dist2(self, other):
        return (other - self).Mag2()

    def Dist(self, other):
        return self.Dist2(other) ** 0.5

class mmPolygon:
    def __init__(self, cell_id, mtl_id, flags, vert_indices, plane_edges, plane_n, plane_d):
        self.cell_id = cell_id
        self.mtl_id = mtl_id
        self.flags = flags
        self.vert_indices = vert_indices
        self.plane_edges = plane_edges
        self.plane_n = plane_n
        self.plane_d = plane_d

    @property
    def is_quad(self):
        return bool(self.flags & 4)

    @property
    def num_verts(self):
        return 4 if self.is_quad else 3

    def read(file):
        cell_id, mtl_id, flags = read_unpack(file, '<HBB')
        vert_indices = read_unpack(file, '<4H')
        plane_edges = Vector3.readn(file, 4)
        plane_n = Vector3.read(file)
        plane_d, = read_unpack(file, '<f')
        return mmPolygon(cell_id, mtl_id, flags, vert_indices, plane_edges, plane_n, plane_d)

    def readn(file, count):
        return [ mmPolygon.read(file) for _ in range(count) ]

CITY_NAME = 'RACETRACK14'
MERGE_COLINEAR = True
RADIUS_FUDGE = 1
TANGENT_ANGLE_FUDGE = 0.999
TANGENT_DIST_FUDGE = 0.1
CORNER_FUDGE = 0.1
LENGTH_FUDGE = 1
STRICT_EDGES = False

if MERGE_COLINEAR:
    assert not STRICT_EDGES

game_dir = open('../../GameDirectory.txt', 'r').read().strip()
dev_dir = f'{game_dir}dev'

with open(f'{dev_dir}/BND/{CITY_NAME}_HITID.BND', 'rb') as f:
    magic, = read_unpack(f, '<I')
    assert magic == 0x424E4432

    offset = Vector3.read(f)
    assert offset == Vector3(0, 0, 0)

    width, row_count, height = read_unpack(f, '<III')
    print(width, row_count, height)

    center = Vector3.read(f)
    print(center)

    radius, radius_sqr = read_unpack(f, '<ff')
    print(radius)

    bb_min, bb_max = Vector3.readn(f, 2)
    print(bb_min)
    print(bb_max)

    num_verts, num_polys = read_unpack(f, '<II')

    print('Verts', num_verts, 'Polys', num_polys)

    num_hot_verts_1, num_hot_verts_2 = read_unpack(f, '<II')
    num_edges, = read_unpack(f, '<I')

    print('Edges', num_edges)

    x_scale, z_scale, num_indices, y_scale = read_unpack(f, '<ffIf')

    # print(x_scale, z_scale, num_indices, y_scale)

    cache_size = read_unpack(f, '<I')

    vertices = Vector3.readn(f, num_verts)
    polys = mmPolygon.readn(f, num_polys + 1)

    print('Vertices', len(vertices), len(set(vertices)))

    hot_verts = Vector3.readn(f, num_hot_verts_2)
    edges_0 = read_unpack(f, '<{}I'.format(num_edges))
    edges_1 = read_unpack(f, '<{}I'.format(num_edges))
    edge_normals = Vector3.readn(f, num_edges)
    edge_floats = read_unpack(f, '<{}f'.format(num_edges))

    if width and row_count:
        row_offsets = read_unpack(f, '<{}I'.format(height))
        row_shorts = read_unpack(f, '<{}H'.format(width * height))
        row_indices = read_unpack(f, '<{}H'.format(num_indices))
        row_heights = read_unpack(f, '<{}B'.format(width * height))

class Edge:
    def __init__(self, v1, v2):
        A = Vector2(v1.y - v2.y, v2.x - v1.x)
        assert A == (v1 - v2).Cross()

        c = A.Dot(v1)
        d = A.Mag2()

        if d > 0.00001:
            line = Vector3(A.x, A.y, -c) * (d ** -0.5)
        else:
            line = Vector3(0, 0, 1000000)

        self.v1 = v1
        self.v2 = v2

        self.line = line

        self.v1p = self.line_pos(self.v1, 0)
        self.v2p = self.line_pos(self.v2, 0)

        assert self.v1p < self.v2p

        self.length = d ** 0.5

        assert abs(self.length - self.v1.Dist(self.v2)) < 0.0001
        delta = self.v1p + self.length - self.v2p
        assert abs(delta) < 0.0001, delta

    # Distance tangential to the line
    def tangent_dist(self, point):
        return (point.x * self.line.x) + (point.y * self.line.y) + self.line.z

    # Distance along the line
    def line_pos(self, point, dist):
        x = point.x + self.line.x * dist
        y = point.y + self.line.y * dist
        return (x * self.line.y) - (y * self.line.x)

    def pos_to_point(self, pos):
        return Vector2(
             (self.line.y * pos) - (self.line.x * self.line.z),
            -(self.line.x * pos) - (self.line.y * self.line.z)
        )


COLINEAR_FUDGE = 0.00001

class Cell:
    def __init__(self, id):
        self.id = id
        self.edges = []

    def add_edge(self, v1, v2):
        # Discard the Y (height) coordinate
        v1 = Vector2(v1.x, v1.z)
        v2 = Vector2(v2.x, v2.z)

        if v1.Dist2(v2) < 0.00001:
            return

        self.edges.append(Edge(v1, v2))

    def merge_colinear(self):
        i = 0

        while i < len(self.edges):
            edge1 = self.edges[i]

            j = i + 1

            while j < len(self.edges):
                edge2 = self.edges[j]
                j += 1

                angle = (edge1.line.x * edge2.line.x) + (edge1.line.y * edge2.line.y)

                if abs(angle) < 0.999:
                    continue

                v1p = edge1.tangent_dist(edge2.v1)
                if abs(v1p) > COLINEAR_FUDGE:
                    continue

                v2p = edge1.tangent_dist(edge2.v2)
                if abs(v2p) > COLINEAR_FUDGE:
                    continue

                v1p = edge1.line_pos(edge2.v1, v1p)
                v2p = edge1.line_pos(edge2.v2, v2p)

                v1p, v2p = min(v1p, v2p), max(v1p, v2p)

                if (v2p < edge1.v1p + CORNER_FUDGE) or (v1p > edge1.v2p - CORNER_FUDGE):
                    continue

                edge1.v1p = min(edge1.v1p, v1p)
                edge1.v2p = max(edge1.v2p, v2p)

                edge1.v1 = edge1.pos_to_point(edge1.v1p)
                edge1.v2 = edge1.pos_to_point(edge1.v2p)

                del self.edges[j - 1]
                j = i + 1

            i += 1

    def process(self):
        if MERGE_COLINEAR:
            self.merge_colinear()

        bb_min = Vector2( 10000000,  10000000)
        bb_max = Vector2(-10000000, -10000000)

        for edge in self.edges:
            for vert in (edge.v1,edge.v2):
                bb_min.x = min(bb_min.x, vert.x)
                bb_min.y = min(bb_min.y, vert.y)

                bb_max.x = max(bb_max.x, vert.x)
                bb_max.y = max(bb_max.y, vert.y)

        self.bb_min = bb_min
        self.bb_max = bb_max
        self.center = (self.bb_min + self.bb_max) * 0.5
        self.radius = (self.bb_min.Dist(self.bb_max) * 0.5)

    def check_radius(self, other, fudge):
        return self.center.Dist2(other.center) < (self.radius + other.radius + fudge) ** 2

cells = {}

for poly in polys:
    if poly.cell_id in cells:
        cell = cells[poly.cell_id]
    else:
        cell = Cell(poly.cell_id)
        cells[poly.cell_id] = cell

    for i in range(poly.num_verts):
        j = (i + 1) % poly.num_verts

        cell.add_edge(vertices[poly.vert_indices[i]], vertices[poly.vert_indices[j]])

for cell in cells.values():
    cell.process()

print('Cells', len(cells))

portals = set()

cell_vs_cell = 0
edge_vs_edge = 0

for cell1 in cells.values():
    for cell2 in cells.values():
        if cell1.id >= cell2.id:
            continue

        if not cell1.check_radius(cell2, RADIUS_FUDGE):
            continue

        cell_vs_cell += 1

        for edge1 in cell1.edges:
            for edge2 in cell2.edges:
                edge_vs_edge += 1

                # angle = (edge1.line.x * edge2.line.x) + (edge1.line.y * edge2.line.y)

                # if abs(angle) < TANGENT_ANGLE_FUDGE:
                #     continue

                v1p = edge1.tangent_dist(edge2.v1)
                if abs(v1p) > TANGENT_DIST_FUDGE:
                    continue

                v2p = edge1.tangent_dist(edge2.v2)
                if abs(v2p) > TANGENT_DIST_FUDGE:
                    continue

                v1p = edge1.line_pos(edge2.v1, v1p)
                v2p = edge1.line_pos(edge2.v2, v2p)

                v1p, v2p = min(v1p, v2p), max(v1p, v2p)

                # Check whether any parts of the two edges are touching
                if (v2p < edge1.v1p + CORNER_FUDGE) or (v1p > edge1.v2p - CORNER_FUDGE):
                    continue

                if STRICT_EDGES:
                    # Check whether these two edges match
                    if (abs((v1p - edge1.v1p)) > CORNER_FUDGE) or (abs(v2p - edge1.v2p) > CORNER_FUDGE):
                        continue
                else:
                    if (v2p - v1p) < LENGTH_FUDGE:
                        continue
                    pass

                v1p = max(edge1.v1p, v1p)
                v2p = min(edge1.v2p, v2p)

                assert v1p < v2p

                # TODO: Preserve y-height
                p1 = edge1.pos_to_point(v1p)
                p2 = edge1.pos_to_point(v2p)

                portals.add((cell1.id, cell2.id, p1, p2))

print('Cell vs Cell', cell_vs_cell)
print('Edge vs Edge', edge_vs_edge)
print('Portals', len(portals))

MIN_Y = -20
MAX_Y = 50

with open(f'{dev_dir}/CITY/{CITY_NAME}.PTL', 'wb') as f:
    write_pack(f, '<I', 0)
    write_pack(f, '<I', len(portals))

    for cell_1, cell_2, v1, v2 in portals:
        # 0x1: Active (Implicit)

        # Flags 0x2 and 0x4 disable groups
        # 0x2: Reset Clip MinX, MaxX, MinY, MaxY | Open Area?
        # 0x4: Reset MinX or MaxX depending on direction | Half-Open Area?
        # 0x8: Must be infront (or behind?) portal plane
        flags = 0x2
        edge_count = 2
        write_pack(f, '<BB', flags, edge_count)
        write_pack(f, '<H', 101)
        write_pack(f, '<HH', cell_2, cell_1)

        # TODO: Change height
        height = MAX_Y - MIN_Y
        write_pack(f, '<f', height)

        Vector3(v1.x, 0, v1.y).write(f)
        Vector3(v2.x, 0, v2.y).write(f)
